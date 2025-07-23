struct t_poly_tool:public t_config_2013{
  //struct t_lex{
  //  std::function<void(t_poly_tool*)> func;
  //  CharMask m;
  //};
  t_doc doc;
  static bool config_api(string&inout/*,string&fn*/,bool save){
    static const string rfn="config.cfg";
    static string fn=g_qap_poly_tool_config_path+rfn;// near grammar file
    if(save){
      return file_put_contents(fn,inout);
    }
    CrutchIO IO;
    bool ok=IO.LoadFile(fn);
    if(ok){inout=IO.mem;return true;}
    fn=rfn;//in working dir
    ok=IO.LoadFile(fn);
    if(ok){inout=IO.mem;return true;}
    fn=g_qap_poly_tool_config_path2+rfn;//near app
    ok=IO.LoadFile(fn);
    if(ok){inout=IO.mem;return true;}
    return false;
  }
  static t_poly_tool&get(/*IEnvRTTI&Env*/){
    static t_poly_tool tool;
    static t_doc&doc=tool.doc;
    static QapClock clock;
    static bool first=true;
    if(first){clock.Start();/*doc.lines.reserve(2048);*/}
    if(clock.MS()<360*1000)if(!first)return tool;
    first=false;
    clock.Stop();clock.Start();
    CrutchIO IO;
    bool ok=config_api(IO.mem,false);
    if(IO.mem.find("\r")!=string::npos){
      if(IO.mem.find("\n")!=string::npos){
        IO.mem=join(split(IO.mem,"\r"),"");
      }else{
        IO.mem=join(split(IO.mem,"\r"),"\n");
      }
    }
    if(ok){t_doc tmp;doc=std::move(tmp);/*doc.lines.reserve(2048);*/}
    if(!ok){
      IO.mem.clear();
      if(doc.lines.size())QapAssert(save_obj(/*Env,*/doc,IO.mem));
      config_api(IO.mem,true);
      return tool;
    }
    clock.Stop();clock.Start();
    if(IO.mem.size()){
      string msg;
      auto r=load_obj_full(/*Env,*/doc,IO.mem,true,&msg);
      if(!r.ok)QapDebugMsg(r.msg);clock.Stop();clock.Start();
    }
    real time=clock.MS();
    clock.Stop();clock.Start();
    //doc.lines.reserve(2048);
    return tool;
  }
  void save_doc(/*IEnvRTTI&Env,const string&fn*/){
    CrutchIO IO;
    QapAssert(save_obj(/*Env,*/this->doc,IO.mem));
    config_api(IO.mem,true);
  }
public:
  t_line&find(const string&type){
    auto&arr=doc.lines;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.head==type)return ex;
    }
    arr.push_back(t_line());
    auto&back=arr.back();
    back.head=type;
    return back;
  }
  template<class TYPE>
  vector<t_item>&get_base_arr(/*IEnvRTTI&Env,*/const string&basetype,vector<TYPE>&inp,const vector<string>&types){
    auto&base=find(basetype);
    auto&arr=base.arr;
    if(arr.size()==inp.size())return arr;
    if(arr.size()){
      if(arr.size()!=types.size())QapNoWay();
      for(auto&ex:arr){
        QapAssert(qap_includes(types,ex.type));
      }
      return arr;
    }
    QapAssert(base.arr.empty());
    arr.resize(inp.size());
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ex.type=inp[i].info;
    }
    save_doc(/*Env,"config.cfg"*/);
    return arr;
  }
  static int get_mass(const vector<t_item>&arr,const string&type){
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.type==type)return i;
    }
    QapAssert(false);
    return -1;
  }
public:
  struct t_point{
    int id;
    string name;
    vector<int> inp;
    vector<int> out;
    bool passed;
    int group;
  };
public:
  template<class TYPE>
  struct t_out_rec{
    const char*info;
    TAutoPtr<TYPE> object;
    int pos;
    int mass;
    t_out_rec(){pos=-1;mass=-1;}
    t_out_rec(t_out_rec&&ref){info=std::move(ref.info);object=std::move(ref.object);pos=ref.pos;mass=ref.mass;}
  };
public:
  struct t_points{
    vector<t_point> arr;
    t_point&find(const string&name){
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(name==ex.name)return ex;
      }
      QapAssert(false);
      return *(t_point*)nullptr;
    }
    void set_passed(bool value){
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        ex.passed=value;
      }
    }
    void load_points(const vector<string>&inp){
      arr.resize(inp.size());
      for(int i=0;i<inp.size();i++){
        auto&ex=inp[i];
        auto&p=arr[i];
        p.name=ex;
        p.id=i;
        p.passed=false;
        p.group=-1;
      }
    }
    void load_edges_from_events(const vector<t_event>&events){
      for(int i=0;i<events.size();i++){
        auto&ex=events[i];
        auto&pa=find(ex.A.type);
        auto&pb=find(ex.B.type);
        pa.inp.push_back(pb.id);
        pb.out.push_back(pa.id);
      }
    }
    struct t_wave{
      t_points&points;
      vector<int> prev;
      vector<int> next;
      int first_id;
      int group;
      bool result;
      void update(int id)
      {
        auto&ex=points.arr[id];
        ex.group=group;
        ex.passed=true;
        auto&arr=ex.out;
        for(int i=0;i<arr.size();i++){
          auto&id=arr[i];
          auto&ex=points.arr[id];
          QapAssert(id!=first_id);
          if(first_id==id)result=true;
          next.push_back(ex.id);
        }
      }
      void run()
      {
        points.set_passed(false);
        next.push_back(first_id);
        for(int iter=0;!next.empty();iter++)
        {
          prev=std::move(next);
          for(int i=0;i<prev.size();i++){
            auto&id=prev[i];
            auto&ex=points.arr[id];
            if(ex.passed)continue;
            update(ex.id);
          }
        }
      }
    };
    bool isCyclical(){
      t_wave wave={*this};
      wave.result=false;
      string view;view.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        for(int i=0;i<arr.size();i++){view[i]=arr[i].group<0?'N':'0'+arr[i].group;}
        if(ex.group>=0)continue;
        wave.first_id=ex.id;
        wave.group=ex.id;
        wave.run();
      }
      return wave.result;
    }
    vector<string> toList(){
      vector<string> out;
      set_passed(false);
      vector<int> heads;
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(!ex.out.empty())continue;
        heads.push_back(ex.id);
      }
      vector<int> next;
      for(int iter=0;!heads.empty();iter++)
      {
        vector<int> next_heads;
        for(int i=0;i<heads.size();i++){
          auto&id=heads[i];
          auto&ex=arr[id];
          auto&inp=ex.inp;
          for(int i=0;i<inp.size();i++){
            auto&id=inp[i];
            auto&ex=arr[id];
            if(ex.passed)continue;
            bool found=false;
            for(int i=0;i<next_heads.size();i++)if(next_heads[i]==ex.id)found=true;
            if(found)continue;
            next_heads.push_back(ex.id);
          }
        }
        for(int i=0;i<next_heads.size();i++){
          auto&id=next_heads[i];
          auto&ex=arr[id];
          auto&out=ex.out;
          bool ok=true;
          for(int i=0;i<out.size();i++){
            auto&id=out[i];
            for(int i=0;i<next_heads.size();i++){
              if(next_heads[i]==id)ok=false;
            }
          }
          if(!ok)continue;
          next.push_back(ex.id);
        }
        for(int i=0;i<next.size();i++){
          auto&id=next[i];
          auto&ex=arr[id];
          ex.passed=true;
        }
        std::sort(heads.begin(),heads.end());
        for(int i=0;i<heads.size();i++){
          auto&id=heads[i];
          auto&ex=arr[id];
          out.push_back(ex.name);
        }
        heads=std::move(next);
      }
      return out;
    }
  };
public:
  typedef t_config_2013::t_event t_event;
  typedef t_config_2013::t_item t_item;
  static vector<string> list_apply_events(const vector<string>&arr,vector<t_event>&events){
    t_points points;
    points.load_points(arr);
    points.load_edges_from_events(events);
    bool ok=!points.isCyclical();
    QapAssert(ok);
    auto list=points.toList();
    return list;
  }
  void remake(vector<t_item>&points,vector<t_event>&events){
    vector<string> arr;
    arr.resize(points.size());
    for(int i=0;i<arr.size();i++){
      arr[i]=points[i].type;
    }
    auto out=list_apply_events(arr,events);
    QapAssert(out.size()==points.size());
    for(int i=0;i<arr.size();i++){
      points[i].type=out[i];
    }
  }
public:
  template<class TYPE>
  struct go_poly{
    vector<t_out_rec<TYPE>>&out_arr;
    i_dev&dev;
    TAutoPtr<TYPE>&ref;
    t_fallback&scope;
    int&count;
    int&first_id;
    const string&strbasetype;
    //IEnvRTTI&Env;
    struct t_lex{
      const char*pname=nullptr;
      std::function<void(typename TYPE::t_poly_impl*)> func;
      CharMask m;
    };
    template<class T>
    void go_for(){
      t_fallback scope(dev,__FUNCTION__);
      T tmp;
      scope.ok=tmp.go(dev);
      t_out_rec<TYPE> rec;
      static const string strtype=T::ProxySys$$::GetFullName();
      rec.info=strtype.c_str();
      if(scope.ok)
      {
        rec.object=make_unique<T>(std::move(tmp));
        //auto*p=rec.object.get();
        //*p=std::move(tmp);
        if(!count)first_id=out_arr.size();
        count++;
      }
      dev.getPos(rec.pos);
      out_arr.push_back(std::move(rec));
      scope.ok=false;
    }
    template<size_t N=0>
    void main(array<t_lex,N>*plexs=nullptr)
    {
      typedef t_poly_tool::t_out_rec<TYPE> t_out_rec;
      if(!count){scope.ok=false;return;}
      auto use=[this](t_out_rec&ex){
        QapAssert(ex.object);
        ref=std::move(ex.object);
        dev.setPos(ex.pos);
        scope.ok=true;
      };
      if(count==1)
      {
        auto&ex=out_arr[first_id];
        use(ex);
        return;
      }
      #ifndef QAP_POLY_TOOL_DEBUG
      auto id=QAP_MINVAL_ID_OF_VEC(out_arr,-ex.pos);
      use(out_arr[id]);
      return;
      #endif
      auto&tool=t_poly_tool::get(/*Env*/);
      static vector<string> types;
      if(types.empty()&&plexs){
        for(auto&ex:*plexs)types.push_back(ex.pname);
      }
      auto&arr=tool.get_base_arr(/*Env,*/strbasetype,out_arr,types);
      vector<t_out_rec> out;
      auto update_mass=[&](){
        for(int i=0;i<out.size();i++){
          auto&ex=out[i];
          ex.mass=t_poly_tool::get_mass(arr,ex.info);
        }
      };
      for(int i=0;i<out_arr.size();i++){
        auto&ex=out_arr[i];
        if(!ex.object)continue;
        out.push_back(std::move(ex));
      }
      update_mass();
      vector<int> idarr;idarr.resize(out.size());
      for(int i=0;i<out.size();i++){idarr[i]=i;}
      if(true)
      {
        auto comp_pos=[&out](const int&a,const int&b)->bool{return out[a].pos>out[b].pos;};
        std::sort(std::begin(idarr),std::end(idarr),comp_pos);
        QapAssert(out[idarr[0]].pos>out[idarr[1]].pos);
        int fix_count=0;
        for(int i=1;i<out.size();i++){
          auto&pa=idarr[i-1];
          auto&pb=idarr[i-0];
          auto&a=out[pa];
          auto&b=out[pb];
          //if(a.mass<b.mass)continue;
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          auto find_event=[&events](const string&a,const string&b)->bool{
            for(int i=0;i<events.size();i++){
              if(events[i].A.type!=a)continue;
              if(events[i].B.type!=b)continue;
              return true;
            }
            return false;
          };
          bool flag_ab=find_event(a.info,b.info);
          bool flag_ba=find_event(b.info,a.info);
          QapAssert(!flag_ba);
          if(flag_ab)continue;
          events.push_back(t_config_2013::t_event());
          auto&back=events.back();
          back.time=cur_date_str();
          back.A.pos=IToS(a.pos);
          back.A.type=a.info;
          back.B.pos=IToS(b.pos);
          back.B.type=b.info;
          fix_count++;
        }
        if(fix_count){
          auto&base=tool.find(strbasetype);
          auto&events=base.events;
          tool.remake(base.arr,events);
          tool.save_doc(/*Env,"config.cfg"*/);
          update_mass();
        }
      }
      auto comp_func=[&out](const int&a,const int&b)->bool{return out[a].mass<out[b].mass;};
      std::sort(std::begin(idarr),std::end(idarr),comp_func);
      QapAssert(out[idarr[0]].mass<out[idarr[1]].mass);
      for(int i=1;i<out.size();i++){
        auto&pa=idarr[i-1];
        auto&pb=idarr[i-0];
        auto&a=out[pa];
        auto&b=out[pb];
        if(a.pos>b.pos)continue;
        string msg="wrong mass for:\n";
        msg+="a.info = "+string(a.info)+"\n";
        msg+="a.pos = "+IToS(a.pos)+"\n";
        msg+="b.info = "+string(b.info)+"\n";
        msg+="b.pos = "+IToS(b.pos)+"\n";
        QapDebugMsg(msg);
      }
      use(out[idarr[0]]);
    }
  };
};