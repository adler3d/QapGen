// 431.969400 ms
struct t_templ_sys_v02{
  //===>>===i_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_data)\
    ADD(t_var)\
  ADDEND()
  class i_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_item_visitor{
  public:
    typedef t_templ_sys_v02::i_item i_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_templ_sys_v02::U U;//typedef t_templ_sys_v02::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_item*p){
      if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_item_visitor{
  //  void Do(t_data&r){}
  //  void Do(t_var&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_item_visitor
  struct i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_item
  public:
    typedef i_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_item()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_data);
        F(t_var);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_seq_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_raw)\
    ADD(t_caret)\
  ADDEND()
  class i_seq;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_seq_visitor{
  public:
    typedef t_templ_sys_v02::i_seq i_seq;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_templ_sys_v02::U U;//typedef t_templ_sys_v02::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_seq*p){
      if(!p)return nullptr;Is<TYPE,i_seq_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_seq*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_seq_visitor{
  //  void Do(t_raw&r){}
  //  void Do(t_caret&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_seq_visitor
  struct i_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_seq
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_seq
  public:
    typedef i_seq_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_seq()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_raw);
        F(t_caret);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_data:public i_item{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_data)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_seq>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,"t_templ_sys_v02::t_data::t_impl");
        auto&ok=$.ok;
        ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_seq>>,gen_dips(\"\\x00\\xFF\")");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_data)PARENT(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_data
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_data
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v02::t_data");
      auto&ok=$.ok;
      ok=dev.go_str<t_impl>(body);$(ok,"t_impl,gen_dips(\"\\x00\\xFF\")");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_var:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)PARENT(i_item)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v02::t_var");
      auto&ok=$.ok;
      ok=dev.go_const("^^^");$(ok,",\"^\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
      ok=dev.go_any(name,g_static_var_1);$(ok,",gen_dips(\"09@Zaz\")+\"$_\"");
      if(!ok)return ok;
      ok=dev.go_const("^^^");$(ok,",\"^\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_raw:public i_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v02::t_raw");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(dip_inv("^"));
      ok=dev.go_any(body,g_static_var_0);$(ok,",gen_dips(\"\\x00]_\\xFF\")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_caret:public i_seq{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_caret)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,"t_templ_sys_v02::t_caret::t_impl");
        auto&ok=$.ok;
        ok=dev.go_const("^");$(ok,",\"^\"");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_caret)PARENT(i_seq)OWNER(t_templ_sys_v02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_caret
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_caret
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v02::t_caret");
      auto&ok=$.ok;
      ok=dev.go_minor<t_var>(body);$(ok,"minor<t_var>!t_impl,\"^\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_data )\
  F(t_var  )\
  F(t_raw  )\
  F(t_caret)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_sys_v02)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_sys_v02
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_templ_sys_v02
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_templ_sys_v02");
    auto&ok=$.ok;
    ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_item>>,gen_dips(\"\\x00\\xFF\")");
    if(!ok)return ok;
    return ok;
  }
public:
};
void t_templ_sys_v02::i_item::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,2> lex={
    F(t_data,gen_dips("\x00\xFF")),
    F(t_var,"^")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void t_templ_sys_v02::i_seq::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,2> lex={
    F(t_raw,gen_dips("\x00]_\xFF")),
    F(t_caret,"^")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
/*
//list of types:
F(t_templ_sys_v02)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5ftempl%5fsys%5fv02%7b%0a%20%20t%5fdata%3d%3ei%5fitem%7b%0a%20%20%20%20t%5fimp
l%7bvector%3cTAutoPtr%3ci%5fseq%3e%3e%20arr%3b%7bgo%5fauto%28arr%29%3b%7d%7d%0a%
20%20%20%20string%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fstr%3ct%5
fimpl%3e%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fvar%3d%3ei%5fite
m%7b%0a%20%20%20%20string%20name%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fc
onst%28%22%5e%5e%5e%22%29%3b%0a%20%20%20%20%20%20go%5fany%28name%2cgen%5fdips%28
%22azAZ09%22%29%2b%22%5f%24%40%22%29%3b%0a%20%20%20%20%20%20go%5fconst%28%22%5e%
5e%5e%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fraw%3d%3ei%5fseq%7b%0a%
20%20%20%20string%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fany%28bod
y%2cdip%5finv%28%22%5e%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fcar
et%3d%3ei%5fseq%7b%0a%20%20%20%20t%5fimpl%7b%7bgo%5fconst%28%22%5e%22%29%3b%7d%7
d%0a%20%20%20%20t%5fimpl%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fmi
nor%3ct%5fvar%3e%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20vector%3cTAu
toPtr%3ci%5fitem%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28arr%29%3b%
0a%20%20%7d%0a%7d
*/