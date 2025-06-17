// 13.518700 ms
//===>>===i_b_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_bar)\
  ADD(t_baz)\
ADDEND()

class i_b;

#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_b_visitor{
public:
  typedef ::i_b i_b;
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  // 10kk bench:     31.81 ns/call               59.41 ns/call
  // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
  // Od   :          1678.17     vs              1610.70
  // Debug:          4948.20     vs              4892.66
  // compilation time:
  // UC 32.21 // 4.61 sec //408%
  // DC 28.73 // 1.13 sec
  // empty 27.60 
  template<class TYPE>
  static TYPE*UberCast(i_b*p){
    if(!p)return nullptr;Is<TYPE,i_b_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_b*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_b_visitor
struct i_b{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_b)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_b
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_b
public:
  typedef i_b_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load();/*
    {
      F(t_bar);
      F(t_baz);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
struct t_debug2{
  //===>>===i_code_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_char_code)\
    ADD(t_sign_code)\
  ADDEND()
  
  class i_code;
  
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_code_visitor{
  public:
    typedef t_debug2::i_code i_code;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_debug2::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_code*p){
      if(!p)return nullptr;Is<TYPE,i_code_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_code*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_code_visitor
  struct i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code)OWNER(t_debug2)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_code
  public:
    typedef i_code_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_char_code);
        F(t_sign_code);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_char_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code)PARENT(i_code)OWNER(t_debug2)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(i_char_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_code
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("'");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const("'");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sign_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code)PARENT(i_code)OWNER(t_debug2)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sign,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sign_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sign_code
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code)OWNER(t_debug2)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_code>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_code
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_char_code)\
  F(t_sign_code)\
  F(t_code     )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_debug2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_debug2
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_debug2
public:
};
struct t_debug{
  //===>>===i_def_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_class_def)\
    ADD(t_struct_def)\
  ADDEND()
  
  class i_def;
  
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_def_visitor{
  public:
    typedef t_debug::i_def i_def;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_debug::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_def*p){
      if(!p)return nullptr;Is<TYPE,i_def_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_def*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_def_visitor
  struct i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)OWNER(t_debug)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_def
  public:
    typedef i_def_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_class_def);
        F(t_struct_def);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_class_def:public i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_def)PARENT(i_def)OWNER(t_debug)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_name,parent,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_def
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      M+=dev.go_const("=>");
      if(!ok)return ok;
      M+=dev.go_auto(parent);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_def:public i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def)PARENT(i_def)OWNER(t_debug)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_def
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      M+=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_class_def )\
  F(t_struct_def)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_debug)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_debug
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_debug
};
struct t_bar:public i_b{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar)PARENT(i_b)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_bar
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_bar
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
};
struct t_baz:public i_b{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz)PARENT(i_b)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_baz
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_baz
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
};
struct t_z{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_z)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_b>,b,DEF,$,$)\
ADDEND()
//=====+>>>>>t_z
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_z
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(b);
    if(!ok)return ok;
    return ok;
  }
};
struct t_lol_test{
public:
  struct t_more_levels{
  public:
    struct i_b{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_b)OWNER(t_more_levels)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,nope,DEF,$,$)\
    ADDEND()
    //=====+>>>>>i_b
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_b
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=CharMask::fromStr("nope");
        D+=dev.go_any(nope,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(i_b)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_more_levels)OWNER(t_lol_test)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(i_b,fail_expected,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_more_levels
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_more_levels
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(fail_expected);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_more_levels)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lol_test)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_more_levels,ml,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lol_test
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lol_test
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(ml);
    if(!ok)return ok;
    return ok;
  }
};
struct t_lol_test2{
public:
  struct t_more_levels{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_more_levels)OWNER(t_lol_test2)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_b>,fail_expected,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_more_levels
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_more_levels
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(fail_expected);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_more_levels)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lol_test2)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_more_levels,ml,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lol_test2
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lol_test2
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(ml);
    if(!ok)return ok;
    return ok;
  }
};
struct t_foo{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_foo
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_foo
};
struct t_test20250613{
  //===>>===i_yyy_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_fozy)\
    ADD(t_bazz)\
  ADDEND()
  
  class i_yyy;
  
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_yyy_visitor{
  public:
    typedef t_test20250613::i_yyy i_yyy;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_test20250613::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_yyy*p){
      if(!p)return nullptr;Is<TYPE,i_yyy_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_yyy*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_yyy_visitor
  struct i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_yyy
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_yyy
  public:
    typedef i_yyy_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_fozy);
        F(t_bazz);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_xxx_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_fooa)\
    ADD(t_barb)\
    ADD(t_baz)\
  ADDEND()
  
  class i_xxx;
  
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_xxx_visitor{
  public:
    typedef t_test20250613::i_xxx i_xxx;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_test20250613::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_xxx*p){
      if(!p)return nullptr;Is<TYPE,i_xxx_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_xxx*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_xxx_visitor
  struct i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_xxx
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_xxx
  public:
    typedef i_xxx_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_fooa);
        F(t_barb);
        F(t_baz);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_fozy:public i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fozy)PARENT(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_fozy
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fozy
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("Y");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_bazz:public i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bazz)PARENT(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_bazz
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_bazz
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("Z");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_fooa:public i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fooa)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_fooa
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fooa
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("A");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_barb:public i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_barb)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_barb
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_barb
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("B");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_baz:public i_xxx{
    //===>>===i_xxx1_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_foo1)\
      ADD(t_bar1)\
      ADD(t_baz1)\
    ADDEND()
    
    class i_xxx1;
    
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_xxx1_visitor{
    public:
      typedef t_baz::i_xxx1 i_xxx1;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_baz::U U;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #ifdef QAP_FAST_UBERCAST
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr{};
      public:
        #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      };
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_xxx1*p){
        if(!p)return nullptr;Is<TYPE,i_xxx1_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_xxx1*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_xxx1_visitor
    struct i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_xxx1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_xxx1
    public:
      typedef i_xxx1_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_foo1);
          F(t_bar1);
          F(t_baz1);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_foo1:public i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_foo1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_foo1
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("foo");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_bar1:public i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_bar1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_bar1
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("bar");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_baz1:public i_xxx1{
      //===>>===i_xxx2_visitor
      #define DEF_PRO_BLANK()
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
        ADD(t_foo2)\
        ADD(t_bar2)\
      ADDEND()
      
      class i_xxx2;
      
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      class i_xxx2_visitor{
      public:
        typedef t_baz1::i_xxx2 i_xxx2;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_baz1::U U;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #ifdef QAP_FAST_UBERCAST
        template<class TYPE,class Visitor>
        struct Is:public Visitor{
          TYPE*ptr{};
        public:
          #define ADD(U)void Do(U*p){ptr=std::is_same<U,TYPE>::value?(TYPE*)p:nullptr;}
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        };
        // 10kk bench:     31.81 ns/call               59.41 ns/call
        // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
        // Od   :          1678.17     vs              1610.70
        // Debug:          4948.20     vs              4892.66
        // compilation time:
        // UC 32.21 // 4.61 sec //408%
        // DC 28.73 // 1.13 sec
        // empty 27.60 
        template<class TYPE>
        static TYPE*UberCast(i_xxx2*p){
          if(!p)return nullptr;Is<TYPE,i_xxx2_visitor> IS;p->Use(IS);return IS.ptr;
        }
        #else
        template<class TYPE>
        static TYPE*UberCast(i_xxx2*p){return dynamic_cast<TYPE*>(p);}
        #endif
      };
      #undef LIST
      #undef DEF_PRO_BLANK
      //===<<===i_xxx2_visitor
      struct i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_xxx2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_xxx2
      public:
        typedef i_xxx2_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load();/*
          {
            F(t_foo2);
            F(t_bar2);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }*/
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      struct t_foo2:public i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo2)PARENT(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_foo2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_foo2
      public:
        void Use(i_visitor&A){A.Do(this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("foo2");
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_bar2:public i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar2)PARENT(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_bar2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_bar2
      public:
        void Use(i_visitor&A){A.Do(this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback scope(dev,__FUNCTION__);
          auto&ok=scope.ok;
          auto&D=scope.mandatory;
          auto&M=scope.mandatory;
          auto&O=scope.optional;
          D+=dev.go_const("bar2");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_foo2)\
      F(t_bar2)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_baz1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_baz1
    public:
      void Use(i_visitor&A){A.Do(this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("baz");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_foo1)\
    F(t_bar1)\
    F(t_baz1)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_xxx1>,x,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_baz
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_baz
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(x);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_fozy)\
  F(t_bazz)\
  F(t_fooa)\
  F(t_barb)\
  F(t_baz )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_test20250613)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_xxx>,x,DEF,$,$)\
ADDVAR(TAutoPtr<i_yyy>,y,DEF,$,$)\
ADDEND()
//=====+>>>>>t_test20250613
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_test20250613
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(x);
    if(!ok)return ok;
    return ok;
  }
public:
};
bool i_b::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_bar);
  F(t_baz);
  #undef F
  return scope.ok;
}

bool t_debug2::i_code::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_char_code);
  F(t_sign_code);
  #undef F
  return scope.ok;
}

bool t_debug::i_def::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_class_def);
  F(t_struct_def);
  #undef F
  return scope.ok;
}

bool t_test20250613::i_yyy::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_fozy);
  F(t_bazz);
  #undef F
  return scope.ok;
}

bool t_test20250613::i_xxx::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_fooa);
  F(t_barb);
  F(t_baz);
  #undef F
  return scope.ok;
}

bool t_test20250613::t_baz::i_xxx1::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_foo1);
  F(t_bar1);
  F(t_baz1);
  #undef F
  return scope.ok;
}

bool t_test20250613::t_baz::t_baz1::i_xxx2::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_foo2);
  F(t_bar2);
  #undef F
  return scope.ok;
}

/*
//list of types:
F(t_debug2)F(t_debug)F(t_bar)F(t_baz)F(t_z)F(t_lol_test)F(t_lol_test2)F(t_foo)
F(t_test20250613)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fdebug2%7b%0a%20%20t%5fchar%5fcode%3d%3ei%5fcode%7b%0a%20%20%20%20i%5fchar%5f
item%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fconst%28%22%27%22%29%3
b%0a%20%20%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%20%20%20%20go%5fconst%28%2
2%27%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%0a%20%20t%5fsign%5fcode%3d%3ei%5f
code%7b%0a%20%20%20%20t%5fsign%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20g
o%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%0a%20%20t%5fcode%7b%0a%20
%20%20%20vector%3ci%5fcode%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%
5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%7d%0at%5fdebug%7b%0a%20%20t%
5fclass%5fdef%3d%3ei%5fdef%7b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20t%5
fname%20parent%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28name%
29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3d%3e%22%29%3b%0a%20%20%20%20%
20%20M%2b%3dgo%5fauto%28parent%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fs
truct%5fdef%3d%3ei%5fdef%7b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%7b%0
a%20%20%20%20%20%20M%2b%3dgo%5fauto%28name%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0
a%7d%0at%5fbar%3ai%5fb%7b%7d%0at%5fbaz%3ai%5fb%7b%7d%0at%5fz%7bi%5fb%20b%3b%7bgo
%5fauto%28b%29%3b%7d%7d%0at%5flol%5ftest%7b%0a%20%20t%5fmore%5flevels%7b%0a%20%2
0%20%20i%5fb%7bstring%20nope%3b%7bgo%5fany%28nope%2c%22nope%22%29%3b%7d%7d%0a%20
%20%20%20i%5fb%20fail%5fexpected%3b%0a%20%20%20%20%7bgo%5fauto%28fail%5fexpected
%29%3b%7d%0a%20%20%7d%0a%20%20t%5fmore%5flevels%20ml%3b%0a%20%20%7bgo%5fauto%28m
l%29%3b%7d%0a%7d%0at%5flol%5ftest2%7b%0a%20%20t%5fmore%5flevels%7b%0a%20%20%20%2
0i%5fb%20fail%5fexpected%3b%0a%20%20%20%20%7bgo%5fauto%28fail%5fexpected%29%3b%7
d%0a%20%20%7d%0a%20%20t%5fmore%5flevels%20ml%3b%0a%20%20%7bgo%5fauto%28ml%29%3b%
7d%0a%7d%0at%5ffoo%7b%7d%0at%5ftest20250613%7b%0a%20%20t%5ffozy%3d%3ei%5fyyy%7b%
7bgo%5fconst%28%22Y%22%29%3b%7d%7d%0a%20%20t%5fbazz%3d%3ei%5fyyy%7b%7bgo%5fconst
%28%22Z%22%29%3b%7d%7d%0a%20%20t%5ffooa%3d%3ei%5fxxx%7b%7bgo%5fconst%28%22A%22%2
9%3b%7d%7d%0a%20%20t%5fbarb%3d%3ei%5fxxx%7b%7bgo%5fconst%28%22B%22%29%3b%7d%7d%0
a%20%20t%5fbaz%3d%3ei%5fxxx%7b%0a%20%20%20%20t%5ffoo1%3d%3ei%5fxxx1%7b%7bgo%5fco
nst%28%22foo%22%29%3b%7d%7d%0a%20%20%20%20t%5fbar1%3d%3ei%5fxxx1%7b%7bgo%5fconst
%28%22bar%22%29%3b%7d%7d%0a%20%20%20%20t%5fbaz1%3d%3ei%5fxxx1%7b%0a%20%20%20%20%
20%20t%5ffoo2%3d%3ei%5fxxx2%7b%7bgo%5fconst%28%22foo2%22%29%3b%7d%7d%0a%20%20%20
%20%20%20t%5fbar2%3d%3ei%5fxxx2%7b%7bgo%5fconst%28%22bar2%22%29%3b%7d%7d%0a%20%2
0%20%20%20%20%7bgo%5fconst%28%22baz%22%29%3b%7d%0a%20%20%20%20%7d%0a%20%20%20%20
TAutoPtr%3ci%5fxxx1%3e%20x%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28
x%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20TAutoPtr%3ci%5fxxx%3e%20x%3b%0a%20
%20TAutoPtr%3ci%5fyyy%3e%20y%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28x%29%3b%0a
%20%20%7d%0a%7d
*/