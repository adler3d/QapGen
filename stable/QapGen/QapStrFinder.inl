#pragma once
class QapStrFinder{
public:
  struct t_cmd{
    int pos=-1;
    int next_line=-1;
    int arr_id=-1;
    int last_pos=-1;
  };
  struct t_line{
    t_cmd cmds[256];
  };
public:
  vector<vector<int>> vecs;
  vector<string> keywords;
  vector<t_line> lines;
public:
  static QapStrFinder fromArr(const vector<string>&arr)
  {
    QapStrFinder tmp;
    tmp.build(arr);
    return std::move(tmp);
  }
  void build(const vector<string>&arr)
  {
    vecs.reserve(1024*8);
    qap_add_back(lines);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      add_keyword(ex);
    }
  }
  void add_keyword(const string&keyword)
  {
    auto id=keywords.size();
    keywords.push_back(keyword);
    int state=0; int last_pos=-1;
    for(int i=0;i<keyword.size();i++)
    {
      state=add(state,id,i,last_pos);
    }
  }
  int add(int line_id,int keyword_id,int pos,int&last_pos)
  {
    const auto next_pos=pos+1;
    auto&kw=keywords[keyword_id];
    const auto c=kw[pos];
    int next_line=lines[line_id].cmds[c].next_line;
    bool eow=(next_pos==kw.size());
    bool need_new_line=(next_line==-1)&&!eow;
    if(need_new_line)
    {
      next_line=lines.size();
      auto&back=qap_add_back(lines);
    }
    auto&ex=lines[line_id].cmds[c];
    if(ex.arr_id<0){ex.arr_id=vecs.size();qap_add_back(vecs);}
    auto&arr=vecs[ex.arr_id];
    arr.push_back(keyword_id);
    if(ex.pos==-1){ex.pos=pos;}
    QapAssert(ex.pos==pos);
    ex.next_line=next_line;
    if(eow)
    {
      QapAssert(ex.last_pos!=next_pos);
      ex.last_pos=next_pos;
      QapAssert(last_pos!=next_pos);
      last_pos=next_pos;
    }
    if(last_pos!=-1)
    {
      ex.last_pos=last_pos;
    }
    if(ex.last_pos!=-1)last_pos=ex.last_pos;
    return ex.next_line;
  }
};

class QapStrFinderFast{
public:
  struct t_cmd{
    int next=-1;
    int end_id=-1;
    void update(int next,bool eow,int kw_id)
    {
      auto&cmd=*this;
      QapAssert(cmd.next==-1||next==cmd.next);
      cmd.next=next;
      if(!eow)return;
      write_eow(kw_id);
    }
    void write_eow(int kw_id)
    {
      if(kw_id==end_id)return;
      QapAssert(-1==end_id);
      end_id=kw_id;
    }
  };
  struct t_node{
    t_cmd cmds[256];
    int read_cmd_next(uchar c)const
    {
      return cmds[c].next;
    }
    int go_next(uchar c,int&end_id)const
    {
      auto&cmd=cmds[c];
      end_id=cmd.end_id;
      return cmd.next;
    }
    t_cmd&read_cmd(uchar c){
      return cmds[c];
    }
  };
  struct t_item{
    uchar c=0;
    t_cmd cmd;
    int read_cmd_next(uchar c)const
    {
      if(this->c!=c)return -1;
      return cmd.next;
    }
    int go_next(uchar c,int&end_id)const
    {
      if(this->c!=c)return -1;
      end_id=cmd.end_id;
      return cmd.next;
    }
    t_cmd&read_cmd(uchar c){
      QapAssert(this->c==c);
      return cmd;
    }
  };
  struct t_lazy{
    int kw_id=-1;
    int pos=-1;
  };
  struct t_proxy{
    char type='E';
    int id=-1;
    void set_node(int id)
    {
      this->id=id;
      this->type='N';
    }
    void set_item(int id)
    {
      this->id=id;
      this->type='I';
    }
    void set_lazy(int id)
    {
      this->id=id;
      this->type='L';
    }
  };
  struct t_find_result{
    bool ok;
    int kw_id;
    friend bool operator==(const t_find_result&a,const t_find_result&b)
    {
      if(a.ok!=b.ok)return false;
      if(a.kw_id!=b.kw_id)return false;
      return true;
    }
  };
public:
  vector<string> keywords;
  vector<t_proxy> proxies;
  vector<t_node> nodes;
  vector<t_item> items;
  vector<t_lazy> lazys;
  vector<int> free_items;
  vector<int> free_lazys;
public:
  static QapStrFinderFast fromArr(const vector<string>&arr)
  {
    QapStrFinderFast tmp;
    tmp.build(arr);
    return std::move(tmp);
  }
  void rebuild()
  {
    proxies.clear();
    nodes.clear();
    items.clear();
    lazys.clear();
    free_items.clear();
    free_lazys.clear();
    proxies.reserve(keywords.size()*3);
    nodes.reserve(keywords.size()/8);
    qap_add_back(nodes);
    qap_add_back(proxies).set_node(0);
    for(int i=0;i<keywords.size();i++)
    {
      auto&ex=keywords[i];
      add_loop(0,0,i);
    }
    int gg=1;
  }
  void build(const vector<string>&arr)
  {
    keywords=arr;
    rebuild();
  }
  int add(int ptr,uchar c,int keyword_id,int pos,bool eow,bool&need_break)
  {
    if(proxies[ptr].type=='L')
    {
      if(lazys[proxies[ptr].id].kw_id==keyword_id)
      {
        need_break=true;
        return -1;
      }
      unpack(ptr,keyword_id);
      QapAssert(proxies[ptr].type!='L');
    }
    int next=read_next(ptr,c); // see: qap_add_back(lines);
    if(-1!=next)
    {
      if(!eow){return next;}
      QapAssert(eow);
      unsafe_read_cmd(ptr,c).write_eow(keyword_id);
      return next;
    }
    bool need_new_line=(next==-1)&&!eow;
    if(need_new_line)
    {
      next=new_proxy();
    }
    write_next(ptr,c,next,eow,keyword_id,pos,need_break);
    return read_next(ptr,c);
  }
  void add_loop(int ptr,int pos,int kid)
  {
    int state=ptr;
    auto&kw=keywords[kid];
    bool nb=false;
    for(int i=pos;i<kw.size();i++)
    {
      uchar c=kw[i];
      auto eow=kw.size()==i+1;
      state=add(state,c,kid,i,eow,nb);
      if(nb)break;
    }
  }
  void unpack(int ptr,int kb)
  {
    QapAssert(proxies[ptr].type=='L');
    qap_add_back(free_lazys)=proxies[ptr].id;
    auto pos=lazys[proxies[ptr].id].pos;
    auto ka=lazys[proxies[ptr].id].kw_id;
    proxies[ptr].set_item(new_item());
    items[proxies[ptr].id].c=keywords[ka][pos];
    items[proxies[ptr].id].cmd.update(new_proxy(),pos+1==keywords[ka].size(),ka);
    add_loop(ptr,pos,ka);
    add_loop(ptr,pos,kb);
  }
  void write_next(int ptr,uchar c,int next,bool eow,int kw_id,int pos,bool&need_break)
  {
    QapAssert(proxies[ptr].type!='L');
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='E')
    {
      QapAssert(-1==id);
      if(eow)
      {
        p.set_item(new_item());
        auto&item=items[id];
        item.c=c;
        item.cmd.update(next,eow,kw_id);
        return;
      }
      p.set_lazy(new_lazy());
      auto&lazy=lazys[id];
      lazy.pos=pos;
      lazy.kw_id=kw_id;
      need_break=true;
      return;
    }
    if(t=='N')
    {
      auto&node=nodes[id];
      auto&cmd=node.cmds[c];
      cmd.update(next,eow,kw_id);
      return;
    }
    if(t=='I')
    {
      auto&item=items[id];
      if(item.c==c)
      {
        auto&cmd=item.cmd;
        cmd.update(next,eow,kw_id);
        return;
      }
      if(item.c!=c)
      {
        qap_add_back(free_items)=id;
        auto nid=new_node();
        nodes[nid].cmds[item.c]=item.cmd;
        p.set_node(nid);
        nodes[nid].cmds[c].update(next,eow,kw_id);
        item=t_item();
      }
      return;
    }
    QapDebugMsg("no way");
    return;
  }
  t_cmd&unsafe_read_cmd(int ptr,uchar c)
  {
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='N')return nodes[id].read_cmd(c);
    if(t=='I')return items[id].read_cmd(c);
    QapDebugMsg("no way");
    return *(t_cmd*)nullptr;
  }
  int read_next(int ptr,uchar c)const
  {
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    if(t=='E')return -1;
    if(t=='N')return nodes[id].read_cmd_next(c);
    if(t=='I')return items[id].read_cmd_next(c);
    if(t=='L')return -1;
    QapDebugMsg("no way");
    return -1;
  }
  int go_next_for_find(int ptr,uchar c,const string&mem,int&state,int&pos,int&next_pos,int&end_id)const
  {
    end_id=-1;
    auto&p=proxies[ptr];
    auto&t=p.type;
    auto&id=p.id;
    QapAssert(t!='E');
    if(t=='N')return nodes[id].go_next(c,end_id);
    if(t=='I')return items[id].go_next(c,end_id);
    if(t=='L')
    {
      int gg=1;
      auto&L=lazys[id];
      QapAssert(L.pos==pos);
      auto&kw=keywords[L.kw_id];
      if(kw==mem){pos=kw.size()-1;end_id=L.kw_id;return -1;}
      return -1;
    }
    QapDebugMsg("no way");
    return -1;
  }
  int new_proxy()
  {
    int id=proxies.size();
    proxies.emplace_back();
    return id;
  }
  int new_node()
  {
    int id=nodes.size();
    nodes.emplace_back();
    return id;
  }
  int new_item()
  {
    if(!free_items.empty()){int id=free_items.back();free_items.pop_back();return id;};
    int id=items.size();
    items.emplace_back();
    return id;
  }
  int new_lazy()
  {
    if(!free_lazys.empty()){int id=free_lazys.back();free_lazys.pop_back();return id;};
    int id=lazys.size();
    lazys.emplace_back();
    return id;
  }
  t_find_result find_impl(const string&mem,int&state,int&pos,int&next_pos,int&end_id)
  {
    t_find_result fail={false,-1};
    auto n=mem.size();
    if(pos>=n)return fail;
    for(;pos<n;pos=next_pos)
    {
      next_pos=pos+1;
      const uchar c=mem[pos];
      state=go_next_for_find(state,c,mem,state,pos,next_pos,end_id);
      if(state!=-1)continue;
      if(end_id==-1)return fail;
      auto len=1+pos;
      if(n!=len)return fail;
      return {true,end_id};
    }
    QapAssert(state>=0);
    if(end_id==-1)return fail;
    return {true,end_id};
  }
  t_find_result find(const string&mem)
  {
    int pos=0;
    int state=0;
    int next_pos=1;
    int end_id=-1;
    return find_impl(mem,state,pos,next_pos,end_id);
  }
};