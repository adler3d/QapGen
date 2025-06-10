#include "QapStrFinder.inl"

struct t_fallback;

struct t_scope_tool{
  bool ok=true;
  void operator+=(bool value){
    ok=value;
  }
};

struct i_dev_base{
  virtual void push(t_fallback*ptr){QapDebugMsg("no way.");}
  virtual void pop(t_fallback*ptr){QapDebugMsg("no way.");}
};

static int&get_qap_fallback_counter(){static int counter=0;return counter;}

struct t_fallback{
  i_dev_base&dev;
  bool&ok;
  size_t pos;
  t_scope_tool mandatory;
  t_scope_tool optional;
  t_fallback(i_dev_base&dev,const char*const ptr,const char*const ptr2=nullptr):dev(dev),ok(mandatory.ok),pos(-1){
    dev.push(this);
  }
 ~t_fallback(){
    dev.pop(this);
    get_qap_fallback_counter()++;
  }
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
public:
  virtual bool go_blob(string&body,size_t count){QapDebugMsg("no way.");return false;}
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
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_diff(TYPE&ref);
public:
  template<class TYPE_TEMP,class TYPE>
  bool go_minor(TYPE&ref){
    //Adler: I think the old name completely wrong. [about go_sep]
    return old_go_sep<TYPE_TEMP>(ref);
  }
public:
  template<class TYPE_TEMP,class TYPE>
  bool old_go_sep(TYPE&ref);
public:
  template<class TYPE>
  bool go_str(string&ref);
public:
  template<class TYPE>
  bool go_vec(vector<TYPE>&arr,const string&sep);
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
  size_t pos;
  size_t maxpos;
public:
  t_load_dev(/*IEnvRTTI&Env,*/const string&mem,size_t pos=0):/*Env(Env),*/mem(mem),pos(pos),maxpos(pos){}
public:
  void push(t_fallback*ptr){
    ptr->pos=pos;
    maxpos=std::max(maxpos,pos);
  }
  void pop(t_fallback*ptr){
    if(ptr->ok)return;
    if(pos==ptr->pos)return;
    pos=ptr->pos;
  }
  void setPos(int pos){this->pos=pos;}
  void getPos(int&pos){pos=this->pos;}
public:
  //IEnvRTTI&getEnv(){return Env;}
public:
  bool isSave(){return false;}
  bool isLoad(){return true;}
public:
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
public:
  t_save_dev(/*IEnvRTTI&Env,*/string&mem):/*Env(Env),*/mem(mem){}
public:
  void push(t_fallback*ptr){
    ptr->pos=mem.size();
  }
  void pop(t_fallback*ptr){
    if(ptr->ok)return;
    mem.resize(ptr->pos);
  }
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
    auto ok=any[body];
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
      t_fallback tmp(*this,__FUNCTION__, "::save");
      string tmp_mem=ref;
      t_load_dev dev(/*Env,*/tmp_mem);
      for(int i=0;i<ref.size();i++)
      {
        dev.pos=i;
        TYPE tmp;
        bool ok=dev.go_auto(tmp);
        QapAssert(!ok);
        if(ok){
          (*(int*)nullptr)=0;
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
    for(;;)
    {
      TYPE obj;
      t_load_dev dev(/*Env,*/tmp_mem);
      bool tmp_ok=dev.go_auto(temp);
      int tmp_pos=dev.pos;
      dev.pos=0;
      bool obj_ok=dev.go_auto(obj);
      int obj_pos=dev.pos;
      QapAssert(obj_ok);
      if(!tmp_ok)break;
      QapAssert(obj_pos>tmp_pos);
      break;
    }
  }
  ok=go_for_item(*this,ref);
  return ok;
}

template<class TYPE_TEMP,class TYPE>
bool i_dev::old_go_sep(TYPE&ref)
{
  //Adler: lex_a=read<TYPE_TEMP>(); if(lex_a.ok){return false;}else{lex_b=read<TYPE>();return lex_b.ok;}
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
    string tmp_mem;
    {
      t_save_dev dev(/*Env,*/tmp_mem);
      bool ok=go_for_item(dev,ref);
      QapAssert(ok);
    }
    {
      t_load_dev dev(/*Env,*/tmp_mem);
      bool ok=dev.go_auto(temp);
      QapAssert(!ok);
      TYPE obj;
      ok=dev.go_auto(obj);
      QapAssert(ok);
    }
  }
  ok=go_for_item(*this,ref);
  return ok;
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
    TYPE value;
    int pos=0;getPos(pos);
    bool ok=go_auto(value);
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
  static_assert(false,"go_for_item<TYPE> is not implemented!");
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
  TYPE tmp;
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
  ok=tmp.go(dev);
  if(!ok)return ok;
  ref=std::make_unique<TYPE>(std::move(tmp));
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
  ok=!arr.empty();
  return ok;
}

template<class TYPE>
static bool internal_go_for_vec_st(i_dev&dev,vector<TYPE>&arr){
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
  }
  if(dev.isSave()){
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
bool load_obj(/*IEnvRTTI&Env,*/TYPE&out,const string&data,int*pmaxpos=nullptr)
{
  TYPE tmp;
  t_load_dev dev(/*Env,*/data);
  bool ok=dev.go_auto(tmp);
  if(ok)
  {
    string out;
    t_save_dev dev(/*Env,*/out);
    bool ret=dev.go_auto(tmp);
    QapAssert(ok==ret);
    if(ok&&ret)if(out!=data)
    {
      QapDebugMsg(two_text_diff(out,data));
    }
  }
  if(!ok&&pmaxpos){
    *pmaxpos=Clamp<int>(dev.maxpos+1,1,data.size())-1;
  }
  out=std::move(tmp);
  return ok;
}

template<class TYPE>
string load_obj_ex(/*IEnvRTTI&Env,*/TYPE&obj,const string&data){
  int pos=0;
  bool ok=load_obj(/*Env,*/obj,data,&pos);
  string main="{\"ok\":"+BToS(ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(ok)return main;
  auto out=t_error_tool::get_codefrag(data,pos);
  out="{\"offset\":"+IToS(pos)+"}\n"+out;
  return main+"@@@"+out;
}

struct t_load_obj_result{
  bool ok;
  int pos;
  string msg;
};

template<class TYPE>
t_load_obj_result load_obj_full(/*IEnvRTTI&Env,*/TYPE&obj,const string&data){
  t_load_obj_result out;
  out.pos=0;
  out.ok=load_obj(/*Env,*/obj,data,&out.pos);
  out.msg="{\"ok\":"+BToS(out.ok)+",\"date\":\""+cur_date_str()+"\"}";
  if(out.ok)return out;
  auto buff=t_error_tool::get_codefrag(data,out.pos);
  buff="{\"offset\":"+IToS(out.pos)+"}\n"+buff;
  out.msg+="@@@"+buff;
  return out;
}

template<class TYPE>
bool save_obj(/*IEnvRTTI&Env,*/TYPE&inp,string&data)
{
  string mem;
  t_save_dev dev(/*Env,*/mem);
  bool ok=dev.go_auto(inp);
  QapAssert(ok);
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