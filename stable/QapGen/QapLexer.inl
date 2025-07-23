#include "QapStrFinder.inl"
struct t_fallback;

struct t_scope_tool{
  t_fallback*scope;
  bool ok;
  void operator+=(bool value);
};

struct i_dev_base{
  virtual void push(t_fallback*ptr){QapDebugMsg("no way.");}
  virtual void pop(t_fallback*ptr){QapDebugMsg("no way.");}
  virtual void setPos(int pos){QapDebugMsg("no way.");}
  virtual void getPos(int&pos){QapDebugMsg("no way.");}
};

static int&get_qap_fallback_counter(){static int counter=0;return counter;}

struct t_fallback{
  struct t_rec{bool E;bool ok;bool D;};
  i_dev_base&dev;
  bool ok;
  size_t pos;
  const char*const ptr;
  const char*const ptr2;
  int err_count;
  #ifdef QAP_LOAD_DEV_WITH_STACK
  struct t_err{
    int M=-1;
    int maxpos=0;
    const char*pmsg=nullptr;
    const char*ptr=nullptr;
    const char*ptr2=nullptr;
  };
  vector<t_err> errs;
  t_err best_err;
  bool keep_errs=false;
  #endif
  //t_scope_tool mandatory;
  //t_scope_tool optional;
  //int mode=0;
  t_fallback(i_dev_base&dev,const char*const ptr,const char*const ptr2=nullptr):dev(dev)/*,ok(mandatory.ok)*/,ptr(ptr),ptr2(ptr2),pos(-1),err_count(0){
    if(ptr)dev.push(this);
  }
 ~t_fallback(){
    if(ptr)dev.pop(this);
    get_qap_fallback_counter()++;
  }
  void add_status(const t_rec&rec){
    if(rec.E)err_count++;
  }
  void log_clear(){err_count=0;}
  int getErr()const{return err_count;}
  //void operator()(int M){mode=M;}
  #ifdef QAP_LOAD_DEV_WITH_STACK
  void operator()(bool ok,const char*perr){
    if(ok){
      //log_clear();
      if(!keep_errs)errs.clear();
      return;
    }
    int cur_pos;dev.getPos(cur_pos);
    t_err curerr{0,cur_pos,perr,ptr,ptr2};
    if(best_err.M<0||cur_pos>best_err.maxpos){
      best_err=curerr;
      errs.clear();
      errs.push_back(curerr);
    }else if(cur_pos==best_err.maxpos){
      errs.push_back(curerr);
    }
  }
  #else
  void operator()(...){}
  #endif
};

struct t_load_dev;
struct t_save_dev;

class i_dev:public i_dev_base{
public:
  //virtual IEnvRTTI&getEnv(){QapDebugMsg("no way.");return *(IEnvRTTI*)nullptr;}
public:
  virtual void setPos(int pos){QapDebugMsg("no way.");}
  virtual void getPos(int&pos){QapDebugMsg("no way.");}
public:
  virtual bool isSave(){QapDebugMsg("no way.");return false;}
  virtual bool isLoad(){QapDebugMsg("no way.");return false;}
public:
  virtual bool go_any(string&body,const string&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any(string&body,const CharMask&any){QapDebugMsg("no way.");return false;}
  virtual bool go_const_raw(const char*const ptr,size_t size){QapDebugMsg("no way.");return false;}
  virtual bool go_const(const string&str){QapDebugMsg("no way.");return false;}
  virtual bool go_end(string&body,const string&end){QapDebugMsg("no way.");return false;}
  virtual bool go_any_char(char&c,const string&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any_char(char&c,const CharMask&any){QapDebugMsg("no way.");return false;}
  virtual bool go_any_str_from_vec(string&ref,const vector<string>&arr){QapDebugMsg("no way.");return false;}
  virtual bool go_any_str_from_vec(string&ref,const QapStrFinder&arr){QapDebugMsg("no way.");return false;}
  struct t_result{bool ok=false;char c=0;};
  virtual t_result get_char_lt(){QapDebugMsg("no way.");return {};}
public:
  bool go_any(string&ref,const QapStrFinder&arr){return go_any_str_from_vec(ref,arr);}
  bool go_any(string&ref,const vector<string>&arr){return go_any_str_from_vec(ref,arr);}
public:
  virtual bool go_blob(string&body,size_t count){QapDebugMsg("no way.");return false;}
public:
  bool go_until(string&body,const string&aft){return go_end(body,aft);}
public:
  template<size_t SIZE>
  bool go_any_arr_char(array<char,SIZE>&body,const string&any){
    bool ok=false;
    for(size_t i=0;i<body.size();i++){
      ok=go_any_char(body[i],any);
      if(!ok)break;
    }
    return ok;
  }
  template<size_t SIZE>
  bool go_any_arr_char(array<char,SIZE>&body,const CharMask&any){
    bool ok=false;
    for(size_t i=0;i<body.size();i++){
      ok=go_any_char(body[i],any);
      if(!ok)break;
    }
    return ok;
  }
public:
  template<class TYPE,size_t SIZE>
  bool go_auto(std::array<TYPE,SIZE>&arr){
    bool ok=false;
    for(size_t i=0;i<arr.size();i++){
      ok=go_auto(arr[i]);
      if(!ok)break;
    }
    return ok;
  }
public:
  template<size_t SIZE>
  bool go_const(const char(&ptr)[SIZE]){
    static const auto one=lenof("");
    return go_const_raw(&ptr[0],SIZE-one);
  }
  bool go_const(const char&ref){
    return go_const_raw(&ref,sizeof(ref));
  }
public:
  template<class TYPE>
  bool go_auto(TYPE&ref){
    return go_for_item(*this,ref);
  }
public:
  template<class TYPE>
  bool go_str_without(string&ref);
  template<class TYPE>
  bool go_exclude(string&ref){return go_str_without<TYPE>(ref);}
  template<class TYPE>
  bool go_without(string&ref){return go_str_without<TYPE>(ref);}
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_diff(TYPE&ref);
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_minor(TYPE&ref);
  template<class TYPE_TEMP,class TYPE>
  bool go_if_not_then(TYPE&ref){return old_go_sep<TYPE_TEMP>(ref);}
public:
  template<class TYPE_TEMP,class TYPE>
  bool old_go_sep(TYPE&ref);
public:
  template<class TYPE>
  bool go_str(string&ref);
public:
  template<class TYPE>
  bool go_vec(vector<TYPE>&arr,const string&sep);
  template<class TYPE>
  bool go_sep_vec(vector<TYPE>&arr,const string&sep){return go_vec(arr,sep);}
  template<class TYPE>
  bool go_vec_sep(vector<TYPE>&arr,const string&sep){return go_vec(arr,sep);}
public:
  template<class TYPE>
  bool go_bin_oper(vector<TYPE>&arr,const string&oper)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    ok=go_vec(arr,oper);
    if(!ok)return ok;
    if(ok)ok=arr.size()>=2;
    return ok;
  }
};

class t_load_dev:public i_dev{
public:
  //IEnvRTTI&Env;
  const string&mem;
  vector<t_fallback*> stack;
  size_t pos;
  size_t maxpos;
  t_fallback main;
  size_t maxpos_pop;
public:
  t_load_dev(/*IEnvRTTI&Env,*/const string&mem,size_t pos=0):/*Env(Env),*/mem(mem),pos(pos),maxpos(pos),maxpos_pop(pos),main(*(i_dev*)nullptr,nullptr){stack.push_back(&main);}
public:
  void push(t_fallback*ptr)override{
    QapAssert(ptr);
    //for(int i=0;i<stack.size();i++)QapAssert(stack[i]!=ptr);
    #ifdef QAP_LOAD_DEV_WITH_STACK
    stack.push_back(ptr);
    #endif
    ptr->pos=this->pos;
    //ptr->mandatory.ok=true;
    //ptr->mandatory.scope=ptr;
    //ptr->optional.ok=false;
    //ptr->optional.scope=ptr;
    maxpos=std::max(maxpos,pos);
  }
  void pop(t_fallback*ptr)override{
    maxpos_pop=std::max(maxpos_pop,pos);
    QapAssert(ptr);
    QapAssert(!stack.empty());
    #ifdef QAP_LOAD_DEV_WITH_STACK
    QapAssert(stack.back()==ptr);
    stack.pop_back();
    #endif
    t_fallback::t_rec status;
    auto&fb=*ptr;
    bool skip=pos==fb.pos;
    bool ok=fb.ok;
    bool dep_err=fb.getErr();
    bool error=(!skip&&!ok)||dep_err;
    status.E=error;
    status.ok=ok;
    status.D=dep_err;
    #ifndef QAP_LOAD_DEV_WITH_STACK
    stack.back()->add_status(status);
    if(ptr->ok)return;
    if(this->pos==ptr->pos)return;
    /*QapAssert(!stack.empty());*/
    //stack.back()->log.err(SToS(ptr->ptr)+" ["+IToS(this->pos)+"=>"+IToS(ptr->pos)+"]");
    this->pos=ptr->pos;
    return;
    #else
    auto&b=*stack.back();
    b.add_status(status);
    if(fb.ok&&!fb.keep_errs)return;
    // parse fail or we need to pass fb.errs to stack.back().errs
    bool all_failed=skip;//pos==fb.pos;
    // but someone before fail eat more compared to other. some times maxpos confirm this
    // but errs know more, because errs adds even after go_any fail.
    // so we need take info from errs.
    if(b.best_err.M<0||b.best_err.maxpos<fb.best_err.maxpos){
      b.best_err=fb.best_err;
      b.errs=std::move(fb.errs);
      if(fb.keep_errs)b.keep_errs=true;
    }else if(b.best_err.maxpos==fb.best_err.maxpos){
      b.errs+=fb.errs;
      if(fb.keep_errs)b.keep_errs=true;
    }
    if(all_failed||ok)return;
    pos=fb.pos;
    #endif
  }
  void setPos(int pos)override{this->pos=pos;}
  void getPos(int&pos)override{pos=this->pos;}
public:
  //IEnvRTTI&getEnv(){return Env;}
public:
  bool isSave(){return false;}
  bool isLoad(){return true;}
public:
  t_result get_char_lt(){return pos<mem.size()?t_result{true,mem[pos]}:t_result{};}
  bool go_any(string&body,const string&any){
    for(auto i=pos;i<mem.size();i++){
      auto e=any.find(CToS(mem[i]));
      if(e!=string::npos)continue;
      body=mem.substr(pos,i-pos);
      pos=i;
      return !body.empty();
    }
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
  bool go_any(string&body,const CharMask&any){
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    auto&mask=any.mask;
    for(;p<e;p++)
    {
      if(mask[uchar(*p)])continue;
      auto body_size=p-&mem[pos];
      body=mem.substr(pos,body_size);
      pos+=body_size;
      return body_size;
    }
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
  bitset<256> get_expected_bitset_go_const_raw(const char*const ptr,size_t size){
    bitset<256> b;b[*(unsigned char*)ptr]=true;
    return b;
  }
  bool go_const_raw(const char*const ptr,size_t size){
    auto end=pos+size;
    if(end>mem.size())return false;
    for(int i=0;i<size;i++){
      if(mem[pos+i]==ptr[i])continue;
      return false;
    }
    pos+=size;
    return true;
  }
  bool go_const(const string&body){
    auto size=body.size();
    auto end=pos+size;
    if(end>mem.size())return false;
    for(int i=0;i<size;i++){
      if(mem[pos+i]==body[i])continue;
      return false;
    }
    pos+=body.size();
    return true;
    //string s=mem.substr(pos,body.size());
    //bool ok=s==body;
    //if(ok){pos+=body.size();}
    //return ok;
  }
  bool go_end(string&body,const string&aft){
    auto e=mem.find(aft,pos);
    if(e==string::npos)return false;
    body=mem.substr(pos,e-pos);
    pos=e;
    bool ok=go_const(aft);
    QapAssert(ok);
    return ok;
  }
  bool go_any_char(char&body,const string&any){
    if(mem.empty())return false;
    if(pos>=mem.size())return false;
    auto e=any.find(CToS(mem[pos]));
    if(e==string::npos)return false;
    body=mem[pos];
    pos++;
    return true;
  }
  bool go_any(char&body,const CharMask&any){
    return go_any_char(body,any);
  }
  bool go_any_char(char&body,const CharMask&any){
    if(mem.empty())return false;
    if(pos>=mem.size())return false;
    auto ok=any[mem[pos]];
    if(!ok)return false;
    body=mem[pos];
    pos++;
    return true;
  }
public:
  bool go_blob(string&body,size_t count){
    bool ok=count<=mem.size()-pos;
    //QapAssert(ok);
    if(!ok)return ok;
    body=mem.substr(pos,count);
    pos+=count;
    return true;
  }
public:
  class t_keywords{
  public:
    struct t_func{
      const t_keywords&keywords;
      bool ok=false;
      bool next=false;
      bool fail=false;
      size_t pos=0;
      size_t ok_pos=0;
      size_t ok_way_id=-1;
      vector<int> items;
      t_func(const t_keywords&keywords):keywords(keywords)
      {
        auto&arr=keywords.arr;
        int n=arr.size();items.resize(n);
        for(int i=0;i<n;i++)
        {
          items[i]=i;
        }
      }
      void operator()(char c)
      {
        auto&arr=keywords.arr;
        bool need_clean=false;
        int cur_pos=pos; pos++;
        for(size_t i=0;i<items.size();i++)
        {
          auto&id=items[i];
          auto&ex=arr[id];
          if(c!=ex[cur_pos])
          {
            id=-1;
            need_clean=true;
            continue;
          }
        }
        if(need_clean)
        {
          QapCleanIf(items,[](int id){return id<0;});
          need_clean=false;
        }
        if(items.empty())
        {
          fail=true;
          return;
        }
        if(items.size()==1)
        {
          next=pos<arr[items[0]].size();
          ok=ok||!next;
          return;
        }
        next=true;
        for(int i=0;i<items.size();i++)
        {
          auto&id=items[i];
          if(pos!=arr[id].size())continue;
          ok=true;
          QapAssert(ok_pos!=pos);
          ok_pos=pos;
          ok_way_id=id;
          id=-1;
          need_clean=true;
        }
        if(need_clean)
        {
          QapCleanIf(items,[](int id){return id<0;});
          QapAssert(!items.empty());
          QapAssert(ok);
        }
        int gg=1;
      }
      bool exec(const string&ref)
      {
        auto&func=*this;
        for(int i=0;i<ref.size();i++)
        {
          func(ref[i]);
          if(fail){return false;}
          if(func.next)continue;
          QapAssert(ok);
          return true;
        }
        return ok;
      }
    };
  public:
    const vector<string>&arr;
  };
  
public:
  bool go_any_str_from_vec(string&ref,const vector<string>&arr)
  {
    return go_any_str_from_vec_old_and_slow(ref,arr);
    // we not use code below because the code is hard for debug.
    QapAssert(!arr.empty());
    t_keywords keywords={arr};
    auto&body=ref;
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    t_keywords::t_func func(keywords);
    for(;p<e;p++)
    {
      func(*p);
      if(func.fail)
      {
        if(!func.ok)return false;
        body=mem.substr(pos,func.ok_pos);
        pos+=body.size();
        return true;
      }
      if(func.next)continue;
      QapAssert(func.ok);
      p++;
      auto body_size=p-&mem[pos];
      body=mem.substr(pos,body_size);
      pos+=body_size;
      return true;
    }
    if(!func.ok)return false;
    body=mem.substr(pos);
    pos+=body.size();
    return !body.empty();
  }
public:
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr)
  {
    auto&body=ref; auto&tool=arr; auto&lines=tool.lines;
    auto n=mem.size();
    if(pos>=n)return false;
    const auto*p=&mem[pos];
    auto e=p+n;
    int state=0;
    int last_pos=-1;
    for(;p<e;p++)
    {
      auto c=*p;
      auto&ex=lines[state].cmds[c];
      state=ex.next_line;
      if(ex.last_pos!=-1)last_pos=ex.last_pos;
      if(state!=-1)continue;
      if(last_pos==-1)return false;
      body=mem.substr(pos,last_pos);
      pos+=body.size();
      return true;
    }
    QapAssert(state>=0);
    if(last_pos==-1)return false;
    body=mem.substr(pos,last_pos);
    pos+=body.size();
    return !body.empty();
  }
public:
  bool go_any_str_from_vec_old_and_slow(string&ref,const vector<string>&arr)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    QapAssert(!arr.empty());
    vector<int> out;out.resize(arr.size());
    int count=0;
    int id=-1;int winpos=-1;
    int def_pos=0;
    getPos(def_pos);
    for(int i=0;i<arr.size();i++)
    {
      t_fallback scope(*this,__FUNCTION__,"::loop");
      auto&ex=arr[i];
      QapAssert(!ex.empty());
      scope.ok=this->go_const(ex);
      int dev_pos=0;
      getPos(dev_pos);
      out[i]=dev_pos;
      if(scope.ok)
      {
        id=i;
        count++;
        winpos=dev_pos;
      }
      scope.ok=false;
    }
    ok=count;
    if(!ok)return ok;
    if(count>1)
    {
      int best=0;
      for(int i=1;i<out.size();i++)
      {
        if(out[i]==def_pos)continue;
        bool error_detected=out[i]==out[best];
        if(error_detected)
        {
          CppString cpp=arr[i];
          string msg="error detected:\n";
          msg+="arr["+IToS(i)+"] == arr["+IToS(best)+"]\n";
          msg+="value = \""+cpp.data+"\"";
          QapDebugMsg(msg)
        }
        if(out[i]>out[best])best=i;
      }
      QapAssert(def_pos!=out[best]);
      ref=arr[best];
      ok=go_const(ref);
      return ok;
    }
    ref=arr[id];
    ok=go_const(ref);
    return ok;
  }
};

class t_save_dev:public i_dev{
public:
  //IEnvRTTI&Env;
  string&mem;
  vector<t_fallback*> stack;
public:
  t_save_dev(/*IEnvRTTI&Env,*/string&mem):/*Env(Env),*/mem(mem){}
public:
  void push(t_fallback*ptr){
    QapAssert(ptr);
    //for(int i=0;i<stack.size();i++)QapAssert(stack[i]!=ptr);
    stack.push_back(ptr);
    ptr->pos=this->mem.size();
    //ptr->mandatory.ok=true;
    //ptr->mandatory.scope=ptr;
    //ptr->optional.ok=false;
    //ptr->optional.scope=ptr;
  }
  void pop(t_fallback*ptr){
    QapAssert(ptr);
    QapAssert(!stack.empty());
    QapAssert(stack.back()==ptr);
    stack.pop_back();
    if(ptr->ok)return;
    this->mem.resize(ptr->pos);
  }
  void getPos(int&pos)override{pos=mem.size();}
  void setPos(int pos)override{QapAssert(mem.size()>=pos);mem.resize(pos);}
public:
  //IEnvRTTI&getEnv(){return Env;}
public:
  bool isSave(){return true;}
  bool isLoad(){return false;}
public:
  bool go_any(string&body,const string&any){
    if(body.empty())return false;
    string tmp=body;
    for(int i=0;i<any.size();i++)tmp=join(split(tmp,CToS(any[i])),"");
    bool ok=tmp.empty();
    QapAssert(ok);
    mem+=body;
    return ok;
  }
  bool go_any(string&body,const CharMask&any)
  {
    if(body.empty())return false;
    bool ok=any.check(body);
    QapAssert(ok);
    mem+=body;
    return ok;
  }
  bool go_const_raw(const char*const ptr,size_t size){
    mem+=string(ptr,size);
    return true;
  }
  bool go_const(const string&body){
    mem+=body;
    return true;
  }
  bool go_end(string&body,const string&aft){
    auto e=body.find(aft);
    bool ok=e==string::npos;
    QapAssert(ok);
    if(!ok)return false;
    mem+=body;
    ok=go_const(aft);
    QapAssert(ok);
    return ok;
  }
  bool go_any_char(char&body,const string&any){
    auto ok=any.find(body)!=string::npos;
    QapAssert(ok)
    mem.push_back(body);
    return ok;
  }
  bool go_any_char(char&body,const CharMask&any){
    auto ok=any[(unsigned char&)body];
    QapAssert(ok)
    mem.push_back(body);
    return ok;
  }
public:
  bool go_blob(string&body,size_t count){
    bool ok=count==body.size();
    QapAssert(ok);
    if(!ok)return ok;
    mem+=body;
    return true;
  }
public:
  bool go_any_str_from_vec(string&ref,const vector<string>&arr)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    QapAssert(!arr.empty());
    int id=-1;
    int count=0;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(!ex.empty());
      if(ex==ref){count++;id=i;}
    }
    QapAssert(count<=1);
    ok=count;
    if(!ok)return ok;
    ok=go_const(arr[id]);
    QapAssert(ok);
    return ok;
  }
  bool go_any_str_from_vec(string&ref,const QapStrFinder&arr)
  {
    return go_any_str_from_vec(ref,arr.keywords);
  }
};

template<class TYPE>
bool i_dev::go_str_without(string&ref)
{
  //Adler: ref without TYPE. check it for each char from ref.
  t_fallback scope(*this,__FUNCTION__);
  auto&ok=scope.ok;
  if(isLoad())
  {
    int ok_count=0;
    {
      t_fallback loadscope(*this,__FUNCTION__,"::load");
      for(int i=0;;i++)
      {
        {
          t_fallback tmp(*this,__FUNCTION__,"::load::for::temp");
          TYPE temp;
          tmp.ok=go_for_item(*this,temp);
          if(tmp.ok){
            tmp.ok=false;
            tmp.pos=scope.pos+i;
            break;
          }
        }
        int next_pos;{getPos(next_pos);next_pos++;}
        {
          t_fallback tmp(*this,__FUNCTION__,"::load::for::one");
          string one;
          tmp.ok=go_blob(one,1);
          if(!tmp.ok){
            tmp.pos=scope.pos+i;
            break;
          }
        }
        ok_count++;
        int cur_pos;getPos(cur_pos);
        QapAssert(next_pos==cur_pos);
      }
      loadscope.ok=false;
      //loadscope.log_clear();
    }
    //scope.log_clear();
    ok=ok_count;
    if(!ok)return ok;
    ok=go_blob(ref,ok_count);
    if(!ok)return ok;
    return ok;
  }
  if(isSave())
  {
    //auto&Env=getEnv();
    QapAssert(!ref.empty());
    {
      t_fallback tmp(*this,__FUNCTION__,"::save");
      string tmp_mem=ref;
      t_load_dev dev(/*Env,*/tmp_mem);
      for(int i=0;i<ref.size();i++)
      {
        dev.pos=i;
        TYPE tmp;
        bool ok=dev.go_auto(tmp);
        QapAssert(!ok);
        if(ok){
          return false;
        }
      }
    }
    //scope.log_clear();
    ok=go_blob(ref,ref.size());
    //QapDebugMsg("no way");
    return ok;
  }
  return ok;
}

template<class TYPE_TEMP,class TYPE>
bool i_dev::go_diff(TYPE&ref)
{
  //Adler: lex_a=read<TYPE_TEMP>(); lex_b=read<lex_b>(); return lex_a.size()!=lex_b.size();
  //Adler: compared to old_go_sep this algo allow start from TYPE_TEMP. old_go_sep don't allow.
  TYPE_TEMP temp;
  int def_pos=0;
  getPos(def_pos);
  t_fallback scope(*this,__FUNCTION__);
  auto&ok=scope.ok;
  if(isLoad())
  {
    int tmp_pos=0;
    bool tmp_ok=false;
    {
      t_fallback tmp(*this,__FUNCTION__,"::load");
      tmp.ok=go_for_item(*this,temp);
      tmp_ok=tmp.ok;
      if(tmp.ok){
        getPos(tmp_pos);
        tmp.ok=false;ok=false;
        tmp.pos=def_pos;
      }
    }
    //scope.log_clear();
    ok=go_for_item(*this,ref);
    if(!tmp_ok||!ok)return ok;
    int ref_pos=0;
    getPos(ref_pos);
    if(ref_pos<=tmp_pos){ok=false;scope.pos=def_pos;}
    return ok;
  }
  if(isSave())
  {
    //auto&Env=getEnv();
    string tmp_mem;
    {
      t_save_dev dev(/*Env,*/tmp_mem);
      bool ok=go_for_item(dev,ref);
      QapAssert(ok);
      if(!ok)return ok;
    }
    {
      TYPE obj;
      t_load_dev dev(/*Env,*/tmp_mem);
      bool tmp_ok=dev.go_auto(temp);
      int tmp_pos=dev.pos;
      dev.pos=0;
      bool obj_ok=dev.go_auto(obj);
      int obj_pos=dev.pos;
      QapAssert(obj_ok);
      if(tmp_ok)QapAssert(obj_pos>tmp_pos);      
    }
  }
  ok=go_for_item(*this,ref);
  return ok;
}

template<class TYPE_TEMP,class TYPE>
bool i_dev::old_go_sep(TYPE&ref)
{
  //Adler: lex_a=read<TYPE_TEMP>(); if(lex_a.ok){return false;}else{lex_b=read<TYPE>();return lex_b.ok;}
  //Adler: compared to go_diff this algo don't allow start from TYPE_TEMP.
  TYPE_TEMP temp;
  t_fallback scope(*this,__FUNCTION__);
  auto&ok=scope.ok;
  if(isLoad())
  {
    {
      t_fallback tmp(*this,__FUNCTION__,"::load");
      tmp.ok=go_for_item(*this,temp);
      if(tmp.ok){
        tmp.ok=false;ok=false;
        tmp.pos=scope.pos;
      }
    }
    //scope.log_clear();
    if(!ok)return ok;
  }
  if(isSave())
  {
    //auto&Env=getEnv();
    bool g_ok=false;
    string tmp_mem;
    {
      t_save_dev dev(/*Env,*/tmp_mem);
      g_ok=go_for_item(dev,ref);
      //QapAssert(ok);
    }
    {
      t_load_dev dev(/*Env,*/tmp_mem);
      bool tmp_ok=false;
      {
        t_fallback tmp(*this,__FUNCTION__,"::save::load_temp");
        tmp_ok=tmp.ok=dev.go_auto(temp);
        if(tmp_ok||g_ok)QapAssert(tmp_ok!=g_ok);
      }
      TYPE obj;
      ok=dev.go_auto(obj);
      QapAssert(ok==g_ok);
      if(ok||tmp_ok)QapAssert(ok!=tmp_ok);
    }
  }
  ok=go_for_item(*this,ref);
  return ok;
}
double t0{},t0f{},t1{},t1f{};
double St0{},St0f{},St1{},St1f{};

struct t_off_detector{~t_off_detector(){
  int gg=1;
}} off_detector;

template<class TYPE_TEMP,class TYPE>
bool i_dev::go_minor(TYPE&ref){
  return old_go_sep<TYPE_TEMP>(ref);
  // Сохраняем текущее состояние парсера
  int pos_before; getPos(pos_before);
  
  // Запускаем go_diff
  QapClock clock;
  bool result_diff = go_diff<TYPE_TEMP>(ref);
  int pos_after_diff; getPos(pos_after_diff);
  auto ms=clock.MS();
  // Восстанавливаем состояние парсера
  setPos(pos_before);
  if(isLoad())ref={};
  // Запускаем old_go_sep
  
  clock.Start();
  bool result_minor = old_go_sep<TYPE_TEMP>(ref);
  int pos_after_minor; getPos(pos_after_minor);
  auto ms2=clock.MS();
  //static double t0=0;static double t1=0;static double t0f=0;static double t1f=0;
  if(isLoad()){if(result_diff){t0+=ms;t1+=ms2;}else{
    t0f+=ms;t1f+=ms2;
  }}else if(result_diff){St0+=ms;St1+=ms2;}else{
    St0f+=ms;St1f+=ms2;
  }
  // Сравниваем результаты
  if (result_diff != result_minor || pos_after_diff != pos_after_minor) {
    // Логируем расхождения для анализа
    string log="Discrepancy detected between go_diff and old_go_sep\n";
    log+="Result go_diff: "+BToS(result_diff)+", pos: "+IToS(pos_after_diff)+"\n";
    log+="Result go_minor: "+BToS(result_minor)+ ", pos: "+IToS(pos_after_minor)+"\n";
    QapDebugMsg(log);
  }
  //QapDebugMsg("ok="+BToS(result_diff)+" +ms(go_diff)="+FToS2(ms)+" ms(go_sep)="+FToS2(ms2));
  
  // Возвращаем результат (можно выбрать любой или комбинировать)
  return result_diff && result_minor;
}

template<class TYPE>
bool i_dev::go_str(string&ref)
{
  //auto&Env=getEnv();
  if(isSave())
  {
    bool ok=false;
    {
      TYPE value;
      t_load_dev dev(/*Env,*/ref);
        ok=dev.go_auto(value);
        //QapAssert(ok);
        int pos=0;dev.getPos(pos);
        bool err=ref.size()!=pos;
        ok=!err;
        if(err)
        {
          string msg="problem detected:\n";
          msg+="  ref.size : "+IToS(ref.size())+"\n";
          msg+="  pos      : "+IToS(pos)+"\n";
          msg+=t_error_tool::get_codefrag(ref,pos);
          QapDebugMsg(msg);
        }
      }
      if(ok)
      {
        return go_blob(ref,ref.size());
      }
      return ok;
    }
    if(isLoad())
    {
      t_fallback scope(*this,__FUNCTION__);
      bool&ok=scope.ok;
      TYPE value;
      int pos=0;getPos(pos);
      ok=go_auto(value);
      if(!ok)return ok;
      int curpos=0;getPos(curpos);
      QapAssert(curpos>pos);
      setPos(pos);
      auto count=curpos-pos;
      ok=go_blob(ref,count);
      QapAssert(ok);
      return ok;
    }
    QapDebugMsg("no way");
    return false;
  }

  template<class TYPE>
  bool i_dev::go_vec(vector<TYPE>&arr,const string&sep)
  {
    t_fallback scope(*this,__FUNCTION__);
    bool&ok=scope.ok;
    if(isLoad())
    {
      for(int i=0;;i++)
      {
        if(i)
        {
          t_fallback subscope(*this,__FUNCTION__);
          subscope.ok=go_const(sep);
          if(!subscope.ok)break;
        }
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        TYPE tmp;
        ok=go_auto(tmp);
        if(!ok)break;
        QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
        arr.push_back(std::move(tmp));
      }
      ok=!arr.empty();
      return ok;
    }
    if(isSave())
    {
      for(int i=0;i<arr.size();i++)
      {
        if(i)
        {
          t_fallback subscope(*this,__FUNCTION__);
          subscope.ok=go_const(sep);
          if(!subscope.ok)break;
        }
        t_fallback subscope(*this,__FUNCTION__);
        bool&ok=subscope.ok;
        auto&ex=arr[i];
        QapAssert(CheckTAutoPtrIsNotEmpty(ex));
        ok=go_auto(ex);
        if(!ok)break;
      }
      return ok;
    }
    return ok;
  }
/*
template<class TYPE,class BASE>
static bool go_for_class(i_dev&dev,TAutoPtr<BASE>&out){
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  ok=tmp.go(dev);
  if(!ok)return ok;
  auto*p=out.build<TYPE>(dev.getEnv());
  *p=std::move(tmp);
  return ok;
}*/
/*
template<class TYPE> static void try_do_weak_go_for_poly(i_dev&dev,void*){}
template<class TYPE>
static void try_do_weak_go_for_poly(i_dev&dev,TYPE*Self,void(*pFunc)(i_dev&,TYPE*)=&TYPE::weak_go_for_poly_lt<i_dev>)
{
  (*pFunc)(dev,Self);
}*/

template<class TYPE>
static bool go_for_poly(i_dev&dev,TAutoPtr<TYPE>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=TYPE::t_poly_impl::go_lt(dev,ref);
  }
  if(dev.isSave()){
    ok=TYPE::t_poly_impl::go_st(dev,ref);
  }
  return ok;
}

template<class TYPE>
static bool go_for_item(i_dev&dev,const TYPE&ref,...){
  static_assert(false,"no way! 2025.06.26 12:07:07.855"); // look like you call save_obj with const lexer
  //static_assert(false,__FILE__":"__FUNCTION__" => so bad :(");
  //QapDebugMsg(Sys$$<TYPE>::GetRTTI(dev.getEnv())->GetFullName()+" => no way!");
  return false;
}

template<class T,T v>struct detail_test_value{static const bool value=true;};

template<typename,typename=std::void_t<>>
struct detail_has_poly_impl:std::false_type{};

template<typename T>
struct detail_has_poly_impl<T,std::void_t<typename T::t_poly_impl>>:std::true_type{};
/*
template<class TYPE>struct detail_has_poly_impl{
  __if_exists(TYPE::t_poly_impl)
  {
    static const bool value = true;
  }
  __if_not_exists(TYPE::t_poly_impl)
  {
    static const bool value = false;
  }
};*/

//template<class TYPE>struct detail_has_poly_impl{
//  struct yes_type{char arr[1];};
//  struct no_type{char arr[8];};
//  template<class U>
//  static yes_type test(
//    U*,
//    //typename std::enable_if<detail_test_value<bool(*)(i_dev&,TAutoPtr<V>&),&U::t_poly_impl::go_lt>::value>(*)=nullptr
//    typename U::t_poly_impl(*)=nullptr
//  );
//  template<class U>
//  static no_type test(U*,...);
//  static const bool value=sizeof(yes_type)==sizeof(test<TYPE>(nullptr));
//};
/*
template<
  class TYPE,
  bool flag=detail_has_poly_impl<TYPE>::value
>struct detail_go_lt_param_is_not_the_same_as_TYPE{
  static const bool value=!std::is_same<typename get_go_lt_param_type<TYPE>::type,TYPE>::value;
};
template<class TYPE>struct detail_go_lt_param_is_not_the_same_as_TYPE<TYPE,false>{static const bool value=false;};
*/
template<class TYPE>struct get_go_lt_param_type{
  template<class U>
  static U func(bool(*)(i_dev&,TAutoPtr<U>&));
  typedef decltype(func(&TYPE::t_poly_impl::go_lt)) type;
};

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
    !std::is_polymorphic<TYPE>::value/*||detail_go_lt_param_is_not_the_same_as_TYPE<TYPE>::value*/
    ,
    void*
  >::type=nullptr
){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isSave()){
    if(!ref){
      ok=false;
      return ok;
    }
    auto*p=ref.get();
    ok=p->go(dev);
    return ok;
  }
  TYPE tmp;
  ok=tmp.go(dev);
  if(!ok)return ok;
  ref=make_unique<TYPE>(std::move(tmp));
  //auto*p=ref.build<TYPE>(dev.getEnv());
  //*p=std::move(tmp);
  return ok;
}

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
    detail_test_value<
      bool(*)(i_dev&,TAutoPtr<TYPE>&),
      &TYPE::t_poly_impl::go_lt
    >::value,
    void*
  >::type=nullptr,
  bool(*pFunc)(i_dev&,TAutoPtr<TYPE>&)=&TYPE::t_poly_impl::go_lt,
  typename std::enable_if<std::is_polymorphic<TYPE>::value,void*>::type=nullptr
){
  return go_for_poly(dev,ref);
}

// Проверка, что TYPE наследует от Base (интерфейса)
template <typename TYPE, typename Base>
struct is_derived_from {
  static constexpr bool value = std::is_base_of<Base, TYPE>::value && !std::is_same<Base, TYPE>::value;
};

/*
я проверил можно ли убрать хоть какие-то из эти проверок и оказалось что ни одну нельзя.
как "perplexity.ai" догадался что они все нужны не очень понятно. мне вот нифига не очевидно.
можешь рассказать свои мысли по этому поводу.
*/
template<class TYPE>
static typename std::enable_if<
  std::is_polymorphic<TYPE>::value&&
  detail_has_poly_impl<TYPE>::value&&(
    is_derived_from<TYPE,typename TYPE::ParentClass>::value
  ),
  bool
>::type
go_for_item(i_dev&dev,TAutoPtr<TYPE>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isSave()){
    if(!ref){
      ok=false;
      return ok;
    }
    auto*p=ref.get();
    ok=p->go(dev);// все полиморфные ноды имеют метод go(и ещё в добавок поддерживаю go_for_poly базовым классом) иначе зачем они нужны?
    return ok;
  }
  TYPE tmp;// создаём на стэке, т.к при загрузке основной сценарий - это скорее всего фэйл(таки надо это проверить). нам не нужно дополнительные выделения памяти.
  ok=tmp.go(dev);
  if(!ok)return ok;
  ref=make_unique<TYPE>(std::move(tmp)); // редкий сценарий, можно и память выделить.
  return ok;
}


namespace detail{
  template<class TYPE>struct isTAutoPtr{static const bool value=false;};
  template<class TYPE>struct isTAutoPtr<TAutoPtr<TYPE>>{static const bool value=true;};
};

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TYPE&ref,
  bool(TYPE::*pFunc)(i_dev&)=&TYPE::go,
  typename std::enable_if<!detail::isTAutoPtr<TYPE>::value,void*>::type=nullptr
){
  return (ref.*pFunc)(dev);
}

template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TYPE&ref){return true;}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TAutoPtr<TYPE>&ref){return ref.get();}

template<class TYPE>
static bool internal_go_for_vec_lt(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;;i++){
    t_fallback subscope(dev,__FUNCTION__);
    bool&ok=subscope.ok;
    TYPE tmp;
    ok=go_for_item(dev,tmp);
    if(!ok)break;
    QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
    arr.push_back(std::move(tmp));
  }
  #ifdef QAP_LOAD_DEV_WITH_STACK
  scope.keep_errs=arr.size();
  #endif
  ok=!arr.empty();
  return ok;
}

template<class TYPE>
static bool internal_go_for_vec_st(i_dev&dev,vector<TYPE>&arr){
  if(arr.empty())return false;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    ok=go_for_item(dev,ex);
    if(!ok)break;
  }
  return ok;
}

template<class TYPE>
static bool go_for_arr_lt(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_lt(dev,arr);
#if(0)
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  int bef_pos=0;
  dev.getPos(bef_pos);
  ok=internal_go_for_vec_lt(dev,arr);
  if(!ok)return ok;
  int aft_pos=0;
  dev.getPos(aft_pos);
  int size=aft_pos-bef_pos;
  string inp_mem;
  {
    dev.setPos(bef_pos);
    bool ok=dev.go_blob(inp_mem,size);
    dev.setPos(aft_pos);
    QapAssert(ok);
  }
  {
    string tmp_mem;
    t_save_dev tmp_dev(dev.getEnv(),tmp_mem);
    bool ok=internal_go_for_vec_st(tmp_dev,arr);
    QapAssert(ok);
    QapAssert(tmp_mem==inp_mem)
  }
  return ok;
#endif
}

template<class TYPE>
static bool go_for_arr_st(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_st(dev,arr);
#if(0)
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(arr.empty()){ok=false;return ok;}
  string out_mem;
  {
    {
      t_save_dev tmp_dev(dev.getEnv(),out_mem);
      bool ok=internal_go_for_vec_st(tmp_dev,arr);
      QapAssert(ok);
    }
    vector<TYPE> tmp_arr;
    {
      t_load_dev tmp_dev(dev.getEnv(),out_mem);
      bool ok=internal_go_for_vec_lt(tmp_dev,tmp_arr);
      QapAssert(ok);
    }
    string bin_bef;
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(arr),bin_bef);
    string bin_aft;
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(tmp_arr),bin_aft);
    bool err=bin_bef!=bin_aft;
    if(err){
      string txt_bef=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(arr));
      string txt_aft=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(tmp_arr));
      string msg=two_text_diff(txt_aft,txt_bef);
      QapDebugMsg("diff:\n"+msg);
      QapDebugMsg("before:\n"+txt_bef);
      QapDebugMsg("after:\n"+txt_aft);
      return false;
    }
    //QapAssert(bin_bef==bin_aft);
  }
  ok=dev.go_blob(out_mem,out_mem.size());
  return ok;
#endif
}

template<class TYPE>
static bool go_for_item(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=go_for_arr_lt(dev,arr);
  }else if(dev.isSave()){
    ok=go_for_arr_st(dev,arr);
  }
  return ok;
}

static string two_text_diff(const string&out,const string&data)
{
  auto maxval=std::max(out.size(),data.size());
  auto minval=std::min(out.size(),data.size());
  auto ds=maxval-minval;
  int pos=-1;
  for(int i=0;i<minval;i++){
    if(out[i]!=data[i]){pos=i;break;}
  }
  string msg="diff:\n  min_size="+IToS(minval)+"  diff_size="+IToS(ds)+"  pos="+IToS(pos)+"\n";
  if(pos<0){
    QapAssert(minval==out.size());
    auto out=t_error_tool::get_codefrag(data,minval);
    out="{\"offset\":"+IToS(minval)+"}\n"+out;
    msg+=out;
  }
  if(pos>=0){
    int count=10;
    CppString a_cpp=data.substr(std::max<int>(pos-count,0),count*2);
    CppString b_cpp=out.substr(std::max<int>(pos-count,0),count*2);
    msg+="  inp: \""+a_cpp.data+"\"\n";
    msg+="  out: \""+b_cpp.data+"\"\n";
  }
  QapDebugMsg(msg);
  return msg;
};

template<class TYPE>
bool load_obj(/*IEnvRTTI&Env,*/TYPE&out,const string&data,int*pmaxpos=nullptr,string*perrmsg=nullptr)
{
  out=std::move(TYPE{});
  t_load_dev dev(data);auto&ldev=dev;
  bool ok=dev.go_auto(out);if(pmaxpos){*pmaxpos=dev.pos;}
  if(ok)
  {
    #ifdef QAP_LOAD_OBJ_DEBUG
    string output;
    t_save_dev dev(output);
    bool ret=dev.go_auto(out);
    QapAssert(ok==ret);
    if(ok&&ret)if(output!=data)
    {
      ok=false;
      auto d=data;
      QapAssert(output.size()<=data.size());
      d.resize(output.size());
      if(d==output){
        auto out2=t_error_tool::get_codefrag(data,ldev.maxpos);
        QapDebugMsg(out2);
      }else{
        QapDebugMsg(two_text_diff(output,data));
      }
    }
    #endif
  }else out=std::move(TYPE{});
  if(!ok&&pmaxpos){
    *pmaxpos=Clamp<int>(dev.maxpos+1,1,data.size())-1;
  }
  if(!ok&&perrmsg){
    auto&b=*dev.stack.back();
    #ifdef QAP_LOAD_DEV_WITH_STACK
    QapAssert(b.best_err.M>=0);
    if(pmaxpos)*pmaxpos=b.best_err.maxpos;
    set<string> s;map<string,string> m;vector<string> arr;
    for(auto&ex:b.errs){
      auto str="lexer: "+(ex.ptr?string(ex.ptr):"")+"; expected: "+ex.pmsg;
      auto t=split(ex.pmsg,",");QapPopFront(t);string jt=join(t,",");
      auto it=m.find(jt);
      if(it!=m.end()){
        if(it->second.size()>str.size())it->second=str;
        continue;
      }else m[jt]=str;
      if(!s.insert(str).second)continue;
      arr.push_back(str);
      //*perrmsg+="lexer: "+(ex.ptr?string(ex.ptr):"")+"; expected: "+ex.pmsg+"\n";
    }
    vector<string> arr2;for(auto&ex:m)arr2.push_back(ex.second);
    *perrmsg+=join(arr2,"\n");
    #endif
  }
  return ok;
}

template<class TYPE>
string load_obj_ex(/*IEnvRTTI&Env,*/TYPE&obj,const string&data,string*perrmsg=nullptr){
  int pos=0;
  bool ok=load_obj(/*Env,*/obj,data,&pos,perrmsg);
  string main="{\"ok\":"+BToS(ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(ok)return main;
  auto out=t_error_tool::get_codefrag(data,pos);
  out="{\"offset\":"+IToS(pos)+"}\n"+out+(perrmsg?"\n"+*perrmsg:"");
  return main+"@@@"+out;
}

struct t_load_obj_result{
  bool ok;
  int pos;
  string msg;
};

template<class TYPE>
t_load_obj_result load_obj_full(/*IEnvRTTI&Env,*/TYPE&obj,const string&data,bool fast_ok=true,string*perrmsg=nullptr){
  t_load_obj_result out;
  out.pos=0;
  out.ok=load_obj(/*Env,*/obj,data,&out.pos,perrmsg);
  if(!out.ok||!fast_ok)out.msg="{\"ok\":"+BToS(out.ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(out.ok)return out;
  auto buff=t_error_tool::get_codefrag(data,out.pos);
  buff="{\"offset\":"+IToS(out.pos)+"}\n"+buff+(perrmsg?"\n"+*perrmsg:"");;
  out.msg+="@@@"+buff;
  return out;
}

template<class TYPE>
bool save_obj(/*IEnvRTTI&Env,*/TYPE&inp,string&data)
{
  string mem;
  t_save_dev dev(/*Env,*/mem);
  bool ok=dev.go_auto(inp);
  //QapAssert(ok);
  if(ok)
  {
    #if(0)
    TYPE tmp;
    t_load_dev tmp_dev(/*Env,*/mem);
    bool ok=tmp_dev.go_auto(tmp);
    QapAssert(ok);
    string bin_bef;
    string bin_aft;
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(inp),bin_bef);
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(tmp),bin_aft);
    bool err=bin_bef!=bin_aft;
    if(err)
    {
      string txt_bef=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(inp));
      string txt_aft=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(tmp));
      string msg=two_text_diff(txt_aft,txt_bef);
      QapDebugMsg("diff:\n"+msg);
      QapDebugMsg("before:\n"+txt_bef);
      QapDebugMsg("after:\n"+txt_aft);
      return false;
    }
    #endif
  }
  data=std::move(mem);
  return ok;
}

void t_scope_tool::operator+=(bool value){
  if(!ok)return;
  scope->ok=value;
}