class t_templ_sys_v02{
public:
  //===>>===i_item_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_data)\
  ADD(t_var)\
  ADDEND()

  class i_item;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_item_visitor{
  public:
    virtual void Do(t_data*p)=0;
    virtual void Do(t_var*p)=0;
  public:
    #define ADD(U)typedef t_templ_sys_v02::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    template<class TYPE>
    static TYPE*UberCast(i_item*p){
      return dynamic_cast<TYPE*>(p);
    }
  };
  #undef DEF_PRO_BLANK

  #undef LIST
  //===<<===i_item_visitor

  class i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_item
  #include "QapGenStruct.inl"
  //<<<<<+=====i_item
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_data);
        F(t_var);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  public:
    typedef i_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  };

  class i_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_seq
  #include "QapGenStruct.inl"
  //<<<<<+=====i_seq
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_raw);
        F(t_caret);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };

  class t_data:public i_item{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_data)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_seq>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        ok=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_data)PARENT(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_data
  #include "QapGenStruct.inl"
  //<<<<<+=====t_data
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      ok=dev.go_str<t_impl>(body);
      if(!ok)return ok;
      return ok;
    }
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };

  class t_var:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)PARENT(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var
  #include "QapGenStruct.inl"
  //<<<<<+=====t_var
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      ok=dev.go_const("^^^");
      if(!ok)return ok;
      static const string g_static_dip_1=gen_dips("azAZ09")+"_$@";
      ok=dev.go_any(name,g_static_dip_1);
      if(!ok)return ok;
      ok=dev.go_const("^^^");
      if(!ok)return ok;
      return ok;
    }
  public:
    bool isVar()const{return true;}
    bool isData()const{return false;}
    string&get(){return name;}
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  };

  class t_raw:public i_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw
  #include "QapGenStruct.inl"
  //<<<<<+=====t_raw
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      static const string g_static_dip_0=dip_inv("^");
      ok=dev.go_any(body,g_static_dip_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_caret:public i_seq{
  public:
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_caret)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStruct.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        ok=dev.go_const("^");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_caret)PARENT(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_caret
  #include "QapGenStruct.inl"
  //<<<<<+=====t_caret
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      ok=dev.go_minor<t_var>(body);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(t_data)F(t_var)F(t_raw)F(t_caret)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_sys_v02)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_sys_v02
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_sys_v02
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    ok=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
public:
  struct t_inp
  {
    struct t_rec{
      string from;
      string to;
    };
    vector<t_rec> arr;
    void add(const string&from,const string&to){
      t_rec tmp={from,to};
      arr.push_back(std::move(tmp));
    }
    string lookup(const string&var)const{
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.from==var)return ex.to;
      }
      QapAssert(false);
      return "";
    }
  };
  class t_item_visitor:public i_item::i_visitor{
  public:
    class t_dev{
    public:
      string&out;
      const t_inp&inp;
    };
  public:
    t_dev&dev;
    t_item_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_data*p){dev.out+=p->body;}
    void Do(t_var*p){dev.out+=dev.inp.lookup(p->name);}
  };
  string eval(const t_inp&inp)const
  {
    string out;
    t_item_visitor::t_dev dev={out,inp};
    t_item_visitor V(dev);
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(ex);
      auto*p=ex.get();
      p->Use(V);
    }
    return out;
  }
};

/*
//list of types:
F(t_templ_sys_v02)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Ftempl%5Fsys%5Fv02%7B%0A%20%20t%5Fdata%3D%3Ei%5Fitem%7B%0A%20%20%20%20t%5Fimp
l%7Bvector%3CTAutoPtr%3Ci%5Fseq%3E%3E%20arr%3B%7Bgo%5Fauto%28arr%29%3B%7D%7D%0A%
20%20%20%20string%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fstr%3Ct%5
Fimpl%3E%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fvar%3D%3Ei%5Fite
m%7B%0A%20%20%20%20string%20name%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fc
onst%28%22%5E%5E%5E%22%29%3B%0A%20%20%20%20%20%20go%5Fany%28name%2Cgen%5Fdips%28
%22azAZ09%22%29%2B%22%5F%24%40%22%29%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%5E%
5E%5E%22%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fraw%3D%3Ei%5Fseq%7B%0A%
20%20%20%20string%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fany%28bod
y%2Cdip%5Finv%28%22%5E%22%29%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fcar
et%3D%3Ei%5Fseq%7B%0A%20%20%20%20t%5Fimpl%7B%7Bgo%5Fconst%28%22%5E%22%29%3B%7D%7
D%0A%20%20%20%20t%5Fimpl%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20go%5Fmi
nor%3Ct%5Fvar%3E%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20vector%3CTAu
toPtr%3Ci%5Fitem%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28arr%29%3B%
0A%20%20%7D%0A%7D
*/