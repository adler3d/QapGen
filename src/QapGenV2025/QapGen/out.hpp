// 3511.841200 ms
struct t_using_test_20250628{
  struct t_foo;  
  struct t_foo{
    struct t_bar{
      struct t_baz{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz)OWNER(t_bar)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_baz
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_baz
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_baz)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar)OWNER(t_foo)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_bar
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_bar
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_bar)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo)OWNER(t_using_test_20250628)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_bar,b,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_bar,c,DEF,$,$)\
  ADDVAR(t_bar,d,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_foo
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_foo
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(b);
      if(!ok)return ok;
      ok=dev.go_auto($sep1);
      if(!ok)return ok;
      dev.go_auto(c);
      dev.go_auto(d);
      dev.go_auto($sep4);
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_foo)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_using_test_20250628)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_foo,foo,DEF,$,$)\
ADDEND()
//=====+>>>>>t_using_test_20250628
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_using_test_20250628
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(foo);
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_cppcore{
  //===>>===i_expr_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_int_expr)\
    ADD(t_char_expr)\
    ADD(t_bool_expr)\
    ADD(t_string_expr)\
    ADD(t_real_expr)\
    ADD(t_varcall_expr)\
    ADD(t_block_expr)\
  ADDEND()
  class i_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_expr_visitor{
  public:
    typedef t_cppcore::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_cppcore::U U;//typedef t_cppcore::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_expr_visitor{
  //  void Do(t_int_expr&r){}
  //  void Do(t_char_expr&r){}
  //  void Do(t_bool_expr&r){}
  //  void Do(t_string_expr&r){}
  //  void Do(t_real_expr&r){}
  //  void Do(t_varcall_expr&r){}
  //  void Do(t_block_expr&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_expr_visitor
  struct i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_int_expr);
        F(t_char_expr);
        F(t_bool_expr);
        F(t_string_expr);
        F(t_real_expr);
        F(t_varcall_expr);
        F(t_block_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev03
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev03
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-,!,~",","));
      dev.go_any_str_from_vec(oper,g_static_var_0);
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_lev05{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev03,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev03,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev05
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev05
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev06{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev05,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev05,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev06
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev06
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev07{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev07)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<<,>>",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev07)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev06,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev06,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev07
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev07
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev08{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev08)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("<,<=,>,>=",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev08)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev07,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev07,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev08
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev08
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev09{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("==,!=",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev08,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev08,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev09
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev09
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev10{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("&");
        if(!ok)return ok;
        return ok;
      }
      inline static const string value="&";
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev09,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev09,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev10
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev10
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev11{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("^");
        if(!ok)return ok;
        return ok;
      }
      inline static const string value="^";
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev10,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev10,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev11
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev11
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev12{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("|");
        if(!ok)return ok;
        return ok;
      }
      inline static const string value="|";
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev11,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev11,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev12
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev12
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev13{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("&&");
        if(!ok)return ok;
        return ok;
      }
      inline static const string value="&&";
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev12,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev12,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev13
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev13
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_lev14{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_oper
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("||");
        if(!ok)return ok;
        return ok;
      }
      inline static const string value="||";
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_lev13,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(oper);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev13,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_lev14
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_lev14
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  /*
  var pad2=num=>(num<10?"0"+num:""+num);
  return(
  `+,-,!,~
  *,/,%
  +,-
  <<,>>
  <,<=,>,>=
  ==,!=
  &
  ^
  |
  &&
  ||`.split("\r").join("").split("\n").map((ops,i)=>{
    var e="t_lev"+pad2(i==1?3:i+3);
    var n="t_lev"+pad2(i+4);
    if(!i){
      return `t_lev03{
    string oper=any_str_from_vec(split(`+JSON.stringify(ops)+`,","))?;
    TAutoPtr<i_expr> expr;
  }`;
    }
    var oa=ops.split(",");
    if(oa.length==1){
      return n+`{
    t_oper{"`+oa[0]+`" inline static const string value="`+oa[0]+`";}
    t_item{t_oper oper; `+e+` expr;}
    `+e+` expr;
    vector<t_item> arr?;
  }`;
    }
    return n+`{
    t_oper{string value=any_str_from_vec(split("`+ops+`",","));}
    t_item{t_oper oper;`+e+` expr;}
    `+e+` expr;
    vector<t_item> arr?;
  }`;
  }).join("\n"));
  */
  struct t_string{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_string
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("\"");
      if(!ok)return ok;
      dev.go_str<vector<TAutoPtr<i_str_item>>>(value);
      ok=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_int_expr:public i_expr{
    //===>>===i_val_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_zero)\
      ADD(t_num)\
    ADDEND()
    class i_val;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_val_visitor{
    public:
      typedef t_int_expr::i_val i_val;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_int_expr::U U;//typedef t_int_expr::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_val*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_val_visitor{
    //  void Do(t_zero&r){}
    //  void Do(t_num&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_val_visitor
    struct i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_val
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_val
    public:
      typedef i_val_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_zero);
          F(t_num);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_zero:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_zero
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_zero
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("0");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_num:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_int_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,first,DEF,$,$)\
    ADDVAR(string,num,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_num
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("19"));
        ok=dev.go_any_char(first,g_static_var_0);
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
        dev.go_any(num,g_static_var_1);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_zero)\
    F(t_num )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_int_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_int_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<TAutoPtr<i_val>>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_type_expr{
    struct t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_int_expr,count,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_params
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_params
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("{");
        if(!ok)return ok;
        ok=dev.go_str<t_type_expr>(type);
        if(!ok)return ok;
        ok=dev.go_const(",");
        if(!ok)return ok;
        ok=dev.go_auto(count);
        if(!ok)return ok;
        ok=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(TAutoPtr<t_params>,params,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(params);
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_type_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_elem,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_const("::");
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_params)\
    F(t_elem  )\
    F(t_item  )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_elem,first,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_expr
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_char_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_char_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_bool_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("true,false",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_string_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_string_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_real_expr:public i_expr{
    //===>>===i_val_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_num)\
      ADD(t_zero)\
    ADDEND()
    class i_val;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_val_visitor{
    public:
      typedef t_real_expr::i_val i_val;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_real_expr::U U;//typedef t_real_expr::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_val*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_val_visitor{
    //  void Do(t_num&r){}
    //  void Do(t_zero&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_val_visitor
    struct i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_val
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_val
    public:
      typedef i_val_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_num);
          F(t_zero);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_frac{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_frac
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_frac
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const(".");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
        ok=dev.go_any(arr,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_sign{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,sign,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_sign
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_sign
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr("-+");
        ok=dev.go_any_char(sign,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_exp{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,e,DEF,$,$)\
    ADDVAR(TAutoPtr<t_sign>,sign,DEF,$,$)\
    ADDVAR(string,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_exp
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_exp
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr("eE");
        ok=dev.go_any_char(e,g_static_var_0);
        if(!ok)return ok;
        dev.go_auto(sign);
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
        ok=dev.go_any(arr,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_num:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,first,DEF,$,$)\
    ADDVAR(string,num,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_num
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_num
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("19"));
        ok=dev.go_any_char(first,g_static_var_0);
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
        dev.go_any(num,g_static_var_1);
        return ok;
      }
    };
    struct t_zero:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_zero
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_zero
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("0");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_val>,val,DEF,$,$)\
    ADDVAR(TAutoPtr<t_frac>,frac,DEF,$,$)\
    ADDVAR(TAutoPtr<t_exp>,exp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(val);
        if(!ok)return ok;
        ok=dev.go_auto(frac);
        if(!ok)return ok;
        dev.go_auto(exp);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_frac)\
    F(t_sign)\
    F(t_exp )\
    F(t_num )\
    F(t_zero)\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_real_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
  };
  struct t_call_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_params)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(sep);
      dev.go_vec(arr,",");
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_varcall_expr:public i_expr{
    //===>>===i_part_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_dd_part)\
      ADD(t_template_part)\
    ADDEND()
    class i_part;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_part_visitor{
    public:
      typedef t_varcall_expr::i_part i_part;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_varcall_expr::U U;//typedef t_varcall_expr::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_part*p){
        if(!p)return nullptr;Is<TYPE,i_part_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_part*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_part_visitor{
    //  void Do(t_dd_part&r){}
    //  void Do(t_template_part&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_part_visitor
    struct i_part{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_part)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_part
    public:
      typedef i_part_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_dd_part);
          F(t_template_part);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_sb_expr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sb_expr)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_lev14,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_sb_expr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_sb_expr
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("[");
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_const("]");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_dd_part:public i_part{
      struct t_elem{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_dd_part)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(t_name,name,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_elem
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_elem
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(sep0);
          ok=dev.go_const("::");
          if(!ok)return ok;
          dev.go_auto(sep1);
          ok=dev.go_auto(name);
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_elem)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dd_part)PARENT(i_part)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_elem>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_dd_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_dd_part
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_template_part:public i_part{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_part)PARENT(i_part)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sepB,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_lev14,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_dd_part>,ddp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_template_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_template_part
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sepB);
        ok=dev.go_const("<");
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_const(">");
        if(!ok)return ok;
        dev.go_auto(ddp);
        return ok;
      }
    };
    struct t_arr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(vector<t_sb_expr>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_arr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_arr
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep);
        ok=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(t_arr,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const(".");
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(arr);
        return ok;
      }
    };
    struct t_var{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)OWNER(t_varcall_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(TAutoPtr<i_part>,tp,DEF,$,$)\
    ADDVAR(TAutoPtr<t_arr>,arr,DEF,$,$)\
    ADDVAR(vector<t_item>,items,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_var
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_var
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(tp);
        dev.go_auto(arr);
        dev.go_auto(items);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_sb_expr      )\
    F(t_dd_part      )\
    F(t_template_part)\
    F(t_arr          )\
    F(t_item         )\
    F(t_var          )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_varcall_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var,var,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_call_params,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_varcall_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_varcall_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(var);
      if(!ok)return ok;
      dev.go_auto(sep);
      dev.go_auto(params);
      return ok;
    }
  public:
  };
  struct t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_block_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03       )\
  F(t_lev05       )\
  F(t_lev06       )\
  F(t_lev07       )\
  F(t_lev08       )\
  F(t_lev09       )\
  F(t_lev10       )\
  F(t_lev11       )\
  F(t_lev12       )\
  F(t_lev13       )\
  F(t_lev14       )\
  F(t_string      )\
  F(t_int_expr    )\
  F(t_type_expr   )\
  F(t_char_expr   )\
  F(t_bool_expr   )\
  F(t_string_expr )\
  F(t_real_expr   )\
  F(t_call_param  )\
  F(t_call_params )\
  F(t_varcall_expr)\
  F(t_block_expr  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cppcore)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_cppcore
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_cppcore
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    return ok;
  }
public:
};
struct t_test20250618_atrr{
  struct t_foo{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo)OWNER(t_test20250618_atrr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_foo
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_foo
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_foo)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_test20250618_atrr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_foo,foo,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_test20250618_atrr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_test20250618_atrr
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(foo);
    if(!ok)return ok;
    ok=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  static const vector<string>&foo_attributes(){static const vector<string> a={"skip"};return a;}
  static const vector<string>&sep_attributes(){static const vector<string> a={"optimize","\"sep\"","(\"sep\")","sep[x]"};return a;}
};
//t_test20250620_dev{
//  t_foo{{}}
//  t_bar{
//    "more tests"
//    "test"
//    t_sep sep;
//    "another test" /* yes ` ";" */ ;
//    t_foo foo?;
//    "nope";
//  }
//  string dev=any(";?'->=<`()/\\+")?;
//  t_foo $dev0;
//  t_bar $dev1;
//  /*{
//    go_any(dev,";?'->=<`()/\\+");
//    go_auto($dev0);
//    go_auto($dev1);
//  }*/
//}
struct t_meta_lexer{
  //===>>===i_code_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_name_code)\
    ADD(t_num_code)\
    ADD(t_str_code)\
    ADD(t_char_code)\
    ADD(t_sign_code)\
    ADD(t_soft_brackets_code)\
    ADD(t_hard_brackets_code)\
    ADD(t_curly_brackets_code)\
  ADDEND()
  class i_code;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_code_visitor{
  public:
    typedef t_meta_lexer::i_code i_code;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
  //struct t_visitor:public i_code_visitor{
  //  void Do(t_name_code&r){}
  //  void Do(t_num_code&r){}
  //  void Do(t_str_code&r){}
  //  void Do(t_char_code&r){}
  //  void Do(t_sign_code&r){}
  //  void Do(t_soft_brackets_code&r){}
  //  void Do(t_hard_brackets_code&r){}
  //  void Do(t_curly_brackets_code&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_code_visitor
  struct i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_code
  public:
    typedef i_code_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_name_code);
        F(t_num_code);
        F(t_str_code);
        F(t_char_code);
        F(t_sign_code);
        F(t_soft_brackets_code);
        F(t_hard_brackets_code);
        F(t_curly_brackets_code);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_code_with_sep_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_name_code_with_sep)\
    ADD(t_num_code_with_sep)\
    ADD(t_str_code_with_sep)\
    ADD(t_char_code_with_sep)\
    ADD(t_sign_code_with_sep)\
    ADD(t_soft_brackets_code_with_sep)\
    ADD(t_hard_brackets_code_with_sep)\
    ADD(t_curly_brackets_code_with_sep)\
  ADDEND()
  class i_code_with_sep;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_code_with_sep_visitor{
  public:
    typedef t_meta_lexer::i_code_with_sep i_code_with_sep;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_code_with_sep*p){
      if(!p)return nullptr;Is<TYPE,i_code_with_sep_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_code_with_sep*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_code_with_sep_visitor{
  //  void Do(t_name_code_with_sep&r){}
  //  void Do(t_num_code_with_sep&r){}
  //  void Do(t_str_code_with_sep&r){}
  //  void Do(t_char_code_with_sep&r){}
  //  void Do(t_sign_code_with_sep&r){}
  //  void Do(t_soft_brackets_code_with_sep&r){}
  //  void Do(t_hard_brackets_code_with_sep&r){}
  //  void Do(t_curly_brackets_code_with_sep&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_code_with_sep_visitor
  struct i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_code_with_sep
  public:
    typedef i_code_with_sep_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_name_code_with_sep);
        F(t_num_code_with_sep);
        F(t_str_code_with_sep);
        F(t_char_code_with_sep);
        F(t_sign_code_with_sep);
        F(t_soft_brackets_code_with_sep);
        F(t_hard_brackets_code_with_sep);
        F(t_curly_brackets_code_with_sep);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_type_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_type_item_string)\
    ADD(t_type_item_char)\
    ADD(t_type_item_number)\
    ADD(t_type_item_type)\
  ADDEND()
  class i_type_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_type_item_visitor{
  public:
    typedef t_meta_lexer::i_type_item i_type_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_type_item*p){
      if(!p)return nullptr;Is<TYPE,i_type_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_type_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_type_item_visitor{
  //  void Do(t_type_item_string&r){}
  //  void Do(t_type_item_char&r){}
  //  void Do(t_type_item_number&r){}
  //  void Do(t_type_item_type&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_type_item_visitor
  struct i_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_type_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_type_item
  public:
    typedef i_type_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_type_item_string);
        F(t_type_item_char);
        F(t_type_item_number);
        F(t_type_item_type);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_type_templ_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_type_templ_angle)\
    ADD(t_type_templ_soft)\
  ADDEND()
  class i_type_templ;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_type_templ_visitor{
  public:
    typedef t_meta_lexer::i_type_templ i_type_templ;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_type_templ*p){
      if(!p)return nullptr;Is<TYPE,i_type_templ_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_type_templ*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_type_templ_visitor{
  //  void Do(t_type_templ_angle&r){}
  //  void Do(t_type_templ_soft&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_type_templ_visitor
  struct i_type_templ{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_templ)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_type_templ
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_type_templ
  public:
    typedef i_type_templ_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_type_templ_angle);
        F(t_type_templ_soft);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_struct_cmd_xxxx_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_struct_cmd_mode)\
    ADD(t_struct_cmd_anno)\
  ADDEND()
  class i_struct_cmd_xxxx;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_struct_cmd_xxxx_visitor{
  public:
    typedef t_meta_lexer::i_struct_cmd_xxxx i_struct_cmd_xxxx;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_xxxx*p){
      if(!p)return nullptr;Is<TYPE,i_struct_cmd_xxxx_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_xxxx*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_cmd_xxxx_visitor{
  //  void Do(t_struct_cmd_mode&r){}
  //  void Do(t_struct_cmd_anno&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_struct_cmd_xxxx_visitor
  struct i_struct_cmd_xxxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_struct_cmd_xxxx)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_struct_cmd_xxxx
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_struct_cmd_xxxx
  public:
    typedef i_struct_cmd_xxxx_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_struct_cmd_mode);
        F(t_struct_cmd_anno);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_struct_field_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_const_field)\
    ADD(t_struct_field)\
  ADDEND()
  class i_struct_field;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_struct_field_visitor{
  public:
    typedef t_meta_lexer::i_struct_field i_struct_field;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_struct_field*p){
      if(!p)return nullptr;Is<TYPE,i_struct_field_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_field*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_field_visitor{
  //  void Do(t_const_field&r){}
  //  void Do(t_struct_field&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_struct_field_visitor
  struct i_struct_field{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_struct_field)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_struct_field
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_struct_field
  public:
    typedef i_struct_field_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_const_field);
        F(t_struct_field);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_struct_cmd_so_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_struct_cmd_suffix)\
    ADD(t_struct_cmd_optional)\
    ADD(t_struct_cmd_opt_v2)\
  ADDEND()
  class i_struct_cmd_so;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_struct_cmd_so_visitor{
  public:
    typedef t_meta_lexer::i_struct_cmd_so i_struct_cmd_so;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_so*p){
      if(!p)return nullptr;Is<TYPE,i_struct_cmd_so_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_so*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_cmd_so_visitor{
  //  void Do(t_struct_cmd_suffix&r){}
  //  void Do(t_struct_cmd_optional&r){}
  //  void Do(t_struct_cmd_opt_v2&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_struct_cmd_so_visitor
  struct i_struct_cmd_so{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_struct_cmd_so)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_struct_cmd_so
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_struct_cmd_so
  public:
    typedef i_struct_cmd_so_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_struct_cmd_suffix);
        F(t_struct_cmd_optional);
        F(t_struct_cmd_opt_v2);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_cpp_code_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_cpp_code_sep)\
    ADD(t_cpp_code_main)\
  ADDEND()
  class i_cpp_code;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_cpp_code_visitor{
  public:
    typedef t_meta_lexer::i_cpp_code i_cpp_code;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_cpp_code*p){
      if(!p)return nullptr;Is<TYPE,i_cpp_code_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_cpp_code*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_cpp_code_visitor{
  //  void Do(t_cpp_code_sep&r){}
  //  void Do(t_cpp_code_main&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_cpp_code_visitor
  struct i_cpp_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cpp_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_cpp_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_cpp_code
  public:
    typedef i_cpp_code_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_cpp_code_sep);
        F(t_cpp_code_main);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
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
    typedef t_meta_lexer::i_def i_def;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
  //struct t_visitor:public i_def_visitor{
  //  void Do(t_class_def&r){}
  //  void Do(t_struct_def&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_def_visitor
  struct i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_def
  public:
    typedef i_def_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
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
  //===>>===i_target_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_target_sep)\
    ADD(t_target_item)\
    ADD(t_target_decl)\
    ADD(t_target_using)\
  ADDEND()
  class i_target_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_target_item_visitor{
  public:
    typedef t_meta_lexer::i_target_item i_target_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_meta_lexer::U U;//typedef t_meta_lexer::U U;
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
    // 10kk bench:     31.81 ns/call               59.41 ns/call
    // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
    // Od   :          1678.17     vs              1610.70
    // Debug:          4948.20     vs              4892.66
    // compilation time:
    // UC 32.21 // 4.61 sec //408%
    // DC 28.73 // 1.13 sec
    // empty 27.60 
    template<class TYPE>
    static TYPE*UberCast(i_target_item*p){
      if(!p)return nullptr;Is<TYPE,i_target_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_target_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_target_item_visitor{
  //  void Do(t_target_sep&r){}
  //  void Do(t_target_item&r){}
  //  void Do(t_target_decl&r){}
  //  void Do(t_target_using&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_target_item_visitor
  struct i_target_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_target_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_target_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_target_item
  public:
    typedef i_target_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_target_sep);
        F(t_target_item);
        F(t_target_decl);
        F(t_target_using);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_name_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_name::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_number,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_str_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_seq)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_seq
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_seq
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("\"");
      if(!ok)return ok;
      dev.go_auto(arr);
      ok=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_str_seq{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_str_seq)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_str_seq,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_str_seq
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_str_seq
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto($sep0);
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_str_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str_seq,first,DEF,$,$)\
  ADDVAR(vector<t_sep_str_seq>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  };
  struct t_char_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_char_item>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("'");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const("'");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sign_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sign,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sign_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sign_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_name_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name_code,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_num_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_num_code,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_str_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str_code,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_char_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_char_code,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_sign_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sign_code,body,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sign_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sign_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_soft_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_soft_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_soft_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto($sep1);
      dev.go_auto(body);
      ok=dev.go_const(")");
      if(!ok)return ok;
      dev.go_auto($sep4);
      return ok;
    }
  };
  struct t_hard_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hard_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hard_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      dev.go_auto($sep1);
      dev.go_auto(body);
      ok=dev.go_const("]");
      if(!ok)return ok;
      dev.go_auto($sep4);
      return ok;
    }
  };
  struct t_curly_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_curly_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_curly_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto($sep1);
      dev.go_auto(body);
      ok=dev.go_const("}");
      if(!ok)return ok;
      dev.go_auto($sep4);
      return ok;
    }
  };
  //real_source_data:
  /*
  t_name_code
  t_num_code
  t_str_code
  t_char_code
  t_sign_code
  t_soft_brackets_code
  t_hard_brackets_code
  t_curly_brackets_code
  @@@
  */
  //real_source_code:
  /*
  var mk=POST['data'].split("@@@")[1];
  var gen=function(lex,mk){
    if(lex.includes("brackets")){
      var json=JSON.stringify;
      var m={soft:["(",")"],hard:["[","]"],curly:["{","}"]}
      for(var k in m)if(lex.includes(k))return [
        lex+"_with_sep=>i_code_with_sep{",
        "  "+json(m[k][0])+' " "? vector<TAutoPtr<i_code_with_sep>> body?; '+json(m[k][1])+' " "?',
        "}"
      ].join("\n");
    }
    return lex+"_with_sep=>i_code_with_sep{"+lex+" body;t_sep sep?;}";
  }
  var out=[];
  var arr=POST['data'].split("\n@@@")[0].split("\r").join("").split("\n");
  for(var i=0;i<arr.length;i++){
    out.push(gen(arr[i],mk));
  }
  return out.join("\n");
  */
  struct t_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_code>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_code
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_soft_brackets_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_soft_brackets_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_soft_brackets_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      dev.go_auto(sep1);
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_hard_brackets_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hard_brackets_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hard_brackets_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      dev.go_auto(sep1);
      ok=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_curly_brackets_code:public i_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code)PARENT(i_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_curly_brackets_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_curly_brackets_code
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      dev.go_auto(sep1);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_semicolon{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_semicolon
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_semicolon
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_value_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_value_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_value_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<TAutoPtr<t_cppcore::i_expr>>(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_value
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_const("=");
      if(!ok)return ok;
      ok=dev.go_str<TAutoPtr<t_cppcore::i_expr>>(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_scope)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_type_scope
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_scope
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_templ{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_type_templ>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_templ
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_templ
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_item_string:public i_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_string)PARENT(i_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_item_string
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_item_string
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_item_char:public i_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_char)PARENT(i_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_char_item,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_item_char
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_item_char
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_item_number:public i_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_number)PARENT(i_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_number,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_item_number
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_item_number
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
    struct t_type_item_type;  
  struct t_scope_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_scope,scope,DEF,$,$)\
  ADDVAR(TAutoPtr<t_type_item_type>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope_type_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_scope_type_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(scope);
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_item_type:public i_type_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_type)PARENT(i_type_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_type_scope>,scope,DEF,$,$)\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(TAutoPtr<t_type_templ>,param,DEF,$,$)\
  ADDVAR(vector<t_scope_type_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_item_type
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_item_type
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(scope);
      ok=dev.go_auto(type);
      if(!ok)return ok;
      dev.go_auto(param);
      dev.go_auto(arr);
      return ok;
    }
  };
  struct t_type_expr2{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr2)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_type_scope>,scope,DEF,$,$)\
  ADDVAR(t_type_item_type,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_expr2
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_expr2
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(scope);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_templ_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_param)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_type_item>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_templ_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_templ_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_type_templ_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_type_templ_param)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_templ_param,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_type_templ_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_type_templ_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(",");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_templ_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_params)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_templ_param,first,DEF,$,$)\
  ADDVAR(vector<t_sep_type_templ_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_templ_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_templ_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  };
  struct t_type_templ_angle:public i_type_templ{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_angle)PARENT(i_type_templ)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_type_templ_params>,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_templ_angle
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_templ_angle
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("<");
      if(!ok)return ok;
      dev.go_auto(params);
      ok=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_templ_soft:public i_type_templ{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_soft)PARENT(i_type_templ)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_type_templ_params>,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_templ_soft
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_templ_soft
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(params);
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmd_mode:public i_struct_cmd_xxxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_mode)PARENT(i_struct_cmd_xxxx)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,body,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd_mode
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd_mode
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr("DMO");
      ok=dev.go_any_char(body,g_static_var_0);
      if(!ok)return ok;
      dev.go_auto($sep1);
      ok=dev.go_const("+=");
      if(!ok)return ok;
      dev.go_auto($sep3);
      return ok;
    }
  };
  struct t_sep_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_value)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_value_item,value,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_value
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_auto(value);
      if(!ok)return ok;
      dev.go_auto($sep2);
      return ok;
    }
  };
  struct t_attr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_attr)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_sep_value>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_attr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_attr
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      dev.go_auto($sep2);
      ok=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_const_field:public i_struct_field{
    //===>>===i_sc_item_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_c_item)\
      ADD(t_s_item)\
    ADDEND()
    class i_sc_item;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_sc_item_visitor{
    public:
      typedef t_const_field::i_sc_item i_sc_item;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_const_field::U U;//typedef t_const_field::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_sc_item*p){
        if(!p)return nullptr;Is<TYPE,i_sc_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_sc_item*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_sc_item_visitor{
    //  void Do(t_c_item&r){}
    //  void Do(t_s_item&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_sc_item_visitor
    struct i_sc_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sc_item)OWNER(t_const_field)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_sc_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_sc_item
    public:
      typedef i_sc_item_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_c_item);
          F(t_s_item);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_qst{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_qst)OWNER(t_const_field)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_qst
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_qst
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("?");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_c_item:public i_sc_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_item)PARENT(i_sc_item)OWNER(t_const_field)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_char_item,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_c_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_c_item
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_s_item:public i_sc_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_s_item)PARENT(i_sc_item)OWNER(t_const_field)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_str_item,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_s_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_s_item
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_qst   )\
    F(t_c_item)\
    F(t_s_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_field)PARENT(i_struct_field)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_qst>,qst,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(TAutoPtr<t_semicolon>,sc,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const_field
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_const_field
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<TAutoPtr<i_sc_item>>(value);
      if(!ok)return ok;
      dev.go_auto($sep1);
      dev.go_auto(qst);
      dev.go_auto($sep3);
      dev.go_auto(sc);
      return ok;
    }
  public:
  };
  struct t_struct_field_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field_value)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cppcore::t_varcall_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_field_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_field_value
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_const("=");
      if(!ok)return ok;
      dev.go_auto($sep2);
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_field:public i_struct_field{
    struct t_qst{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_qst)OWNER(t_struct_field)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,s,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_qst
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_qst
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr("*?");
        ok=dev.go_any(s,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_qst)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field)PARENT(i_struct_field)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_struct_cmd_xxxx>,mode,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cppcore::i_expr>,type,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<t_struct_field_value>,value,DEF,$,$)\
  ADDVAR(t_sep,$sep6,DEF,$,$)\
  ADDVAR(TAutoPtr<t_qst>,qst,DEF,$,$)\
  ADDVAR(t_sep,$sep8,DEF,$,$)\
  ADDVAR(t_sep,$sep10,DEF,$,$)\
  ADDVAR(TAutoPtr<t_attr>,attr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_field
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_field
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(mode);
      dev.go_auto($sep1);
      ok=dev.go_auto(type);
      if(!ok)return ok;
      ok=dev.go_auto($sep3);
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      dev.go_auto(value);
      dev.go_auto($sep6);
      dev.go_auto(qst);
      dev.go_auto($sep8);
      ok=dev.go_const(";");
      if(!ok)return ok;
      dev.go_auto($sep10);
      dev.go_auto(attr);
      return ok;
    }
  };
  struct t_sep_struct_field{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_field)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<i_struct_field>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_struct_field
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_struct_field
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_templ_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_params)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_templ_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_templ_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("<");
      if(!ok)return ok;
      ok=dev.go_str<TAutoPtr<t_type_templ_params>>(body);
      if(!ok)return ok;
      ok=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  };
    struct t_cmd_param;  
  struct t_cmd_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_params)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_cmd_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cmd_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_cmd_param{
    //===>>===i_cmd_param_expr_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_expr_call)\
      ADD(t_expr_str)\
      ADD(t_expr_var)\
    ADDEND()
    class i_cmd_param_expr;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_cmd_param_expr_visitor{
    public:
      typedef t_cmd_param::i_cmd_param_expr i_cmd_param_expr;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_cmd_param::U U;//typedef t_cmd_param::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_cmd_param_expr*p){
        if(!p)return nullptr;Is<TYPE,i_cmd_param_expr_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_cmd_param_expr*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_cmd_param_expr_visitor{
    //  void Do(t_expr_call&r){}
    //  void Do(t_expr_str&r){}
    //  void Do(t_expr_var&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_cmd_param_expr_visitor
    struct i_cmd_param_expr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cmd_param_expr)OWNER(t_cmd_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_cmd_param_expr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_cmd_param_expr
    public:
      typedef i_cmd_param_expr_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_expr_call);
          F(t_expr_str);
          F(t_expr_var);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_cmd_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_cmd_param_expr>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_vec(arr,"+");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_expr_call:public i_cmd_param_expr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_call)PARENT(i_cmd_param_expr)OWNER(t_cmd_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_name,func,DEF,$,$)\
    ADDVAR(TAutoPtr<t_cmd_params>,params,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_expr_call
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_expr_call
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(func);
        if(!ok)return ok;
        ok=dev.go_const("(");
        if(!ok)return ok;
        ok=dev.go_auto(params);
        if(!ok)return ok;
        ok=dev.go_const(")");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_expr_str:public i_cmd_param_expr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_str)PARENT(i_cmd_param_expr)OWNER(t_cmd_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_expr_str
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_expr_str
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_str<t_str_seq>(body);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_expr_var:public i_cmd_param_expr{
      struct t_this{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_this)OWNER(t_expr_var)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_this
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_this
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("this->");
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_impl{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_expr_var)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<t_this>,self,DEF,$,$)\
      ADDVAR(t_name,name,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_impl
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_impl
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(self);
          ok=dev.go_auto(name);
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_this)\
      F(t_impl)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_var)PARENT(i_cmd_param_expr)OWNER(t_cmd_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_expr_var
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_expr_var
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_str<t_impl>(body);
        if(!ok)return ok;
        return ok;
      }
    public:
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl     )\
    F(t_expr_call)\
    F(t_expr_str )\
    F(t_expr_var )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_param)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cmd_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_impl>(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_struct_cmd_anno:public i_struct_cmd_xxxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_anno)PARENT(i_struct_cmd_xxxx)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,mode,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd_anno
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd_anno
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("@mandatory,@optional,@mand,@opti,@man,@opt,@ma,@op,@m,@o,m,o",","));
      ok=dev.go_any_str_from_vec(mode,g_static_var_0);
      if(!ok)return ok;
      ok=dev.go_auto($sep1);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmd_suffix:public i_struct_cmd_so{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_suffix)PARENT(i_struct_cmd_so)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd_suffix
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd_suffix
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr("?!");
      ok=dev.go_any_char(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmd_optional:public i_struct_cmd_so{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_optional)PARENT(i_struct_cmd_so)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd_optional
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd_optional
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      static const auto g_static_var_1=QapStrFinder::fromArr(split("optional,mandatory",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_1);
      if(!ok)return ok;
      ok=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmd_opt_v2:public i_struct_cmd_so{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_opt_v2)PARENT(i_struct_cmd_so)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd_opt_v2
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd_opt_v2
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      dev.go_auto($sep1);
      static const auto g_static_var_2=QapStrFinder::fromArr(split("optional,mandatory",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_2);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_struct_cmd_xxxx>,mode,DEF,$,$)\
  ADDVAR(t_name,func,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(string,templ_params,DEF,$,$)\
  ADDVAR(t_cmd_params,params,DEF,$,$)\
  ADDVAR(t_sep,$sep7,DEF,$,$)\
  ADDVAR(TAutoPtr<i_struct_cmd_so>,cmdso,DEF,$,$)\
  ADDVAR(t_sep,$sep9,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmd
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmd
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(mode);
      ok=dev.go_auto(func);
      if(!ok)return ok;
      dev.go_auto($sep2);
      dev.go_str<TAutoPtr<t_templ_params>>(templ_params);
      ok=dev.go_const("(");
      if(!ok)return ok;
      ok=dev.go_auto(params);
      if(!ok)return ok;
      ok=dev.go_const(")");
      if(!ok)return ok;
      dev.go_auto($sep7);
      dev.go_auto(cmdso);
      dev.go_auto($sep9);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_struct_cmd{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmd)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_struct_cmd,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_struct_cmd
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_struct_cmd
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_cmds{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmds)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_sep_struct_cmd>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_cmds
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_cmds
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(arr);
      dev.go_auto($sep2);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_struct_cmds{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmds)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_struct_cmds,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_struct_cmds
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_struct_cmds
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_cpp_code_sep:public i_cpp_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_sep)PARENT(i_cpp_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cpp_code_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cpp_code_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_cpp_code_main:public i_cpp_code{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_main)PARENT(i_cpp_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_code_with_sep>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cpp_code_main
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cpp_code_main
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_cpp_code{
    //===>>===i_major_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_fields)\
      ADD(t_cmds)\
      ADD(t_atr)\
    ADDEND()
    class i_major;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_major_visitor{
    public:
      typedef t_cpp_code::i_major i_major;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_cpp_code::U U;//typedef t_cpp_code::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_major*p){
        if(!p)return nullptr;Is<TYPE,i_major_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_major*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_major_visitor{
    //  void Do(t_fields&r){}
    //  void Do(t_cmds&r){}
    //  void Do(t_atr&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_major_visitor
    struct i_major{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_major)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_major
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_major
    public:
      typedef i_major_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_fields);
          F(t_cmds);
          F(t_atr);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    //===>>===i_bayan_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_with_bayan)\
      ADD(t_without_bayan)\
    ADDEND()
    class i_bayan;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_bayan_visitor{
    public:
      typedef t_cpp_code::i_bayan i_bayan;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_cpp_code::U U;//typedef t_cpp_code::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_bayan*p){
        if(!p)return nullptr;Is<TYPE,i_bayan_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_bayan*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_bayan_visitor{
    //  void Do(t_with_bayan&r){}
    //  void Do(t_without_bayan&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_bayan_visitor
    struct i_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_bayan
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_bayan
    public:
      typedef i_bayan_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_with_bayan);
          F(t_without_bayan);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    //===>>===i_strong_bayan_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_a)\
      ADD(t_b)\
    ADDEND()
    class i_strong_bayan;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_strong_bayan_visitor{
    public:
      typedef t_cpp_code::i_strong_bayan i_strong_bayan;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_cpp_code::U U;//typedef t_cpp_code::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_strong_bayan*p){
        if(!p)return nullptr;Is<TYPE,i_strong_bayan_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_strong_bayan*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_strong_bayan_visitor{
    //  void Do(t_a&r){}
    //  void Do(t_b&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_strong_bayan_visitor
    struct i_strong_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_strong_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_strong_bayan
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_strong_bayan
    public:
      typedef i_strong_bayan_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_a);
          F(t_b);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_bayan
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_bayan
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("[::]");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_fields:public i_major{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fields)PARENT(i_major)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep_struct_field,f,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_fields
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_fields
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(f);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_cmds:public i_major{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmds)PARENT(i_major)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep_struct_cmds,c,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_cmds
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_cmds
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(c);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_atr:public i_major{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_atr)PARENT(i_major)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_attr>,attr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_atr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_atr
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(attr);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_eater{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_eater)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_cpp_code>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_eater
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_eater
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(arr);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_with_bayan:public i_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_with_bayan)PARENT(i_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_bayan,bayan,DEF,$,$)\
    ADDVAR(t_eater,eater,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_with_bayan
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_with_bayan
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(bayan);
        if(!ok)return ok;
        dev.go_auto(eater);
        return ok;
      }
    };
    struct t_without_bayan:public i_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_without_bayan)PARENT(i_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_eater,eater,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_without_bayan
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_without_bayan
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_minor<TAutoPtr<i_major>>(eater);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_a:public i_strong_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_a)PARENT(i_strong_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_with_bayan,wb,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_a
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_a
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(wb);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_b:public i_strong_bayan{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_b)PARENT(i_strong_bayan)OWNER(t_cpp_code)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_eater,e,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_b
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_b
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_minor<t_with_bayan>(e);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_bayan        )\
    F(t_fields       )\
    F(t_cmds         )\
    F(t_atr          )\
    F(t_eater        )\
    F(t_with_bayan   )\
    F(t_without_bayan)\
    F(t_a            )\
    F(t_b            )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_bayan>,bayan,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cpp_code
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cpp_code
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(bayan);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  // test
  struct t_fields_cmds_cppcode{
    struct t_true_fcc{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_true_fcc)OWNER(t_fields_cmds_cppcode)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_sep_struct_field>,arr,DEF,$,$)\
    ADDVAR(TAutoPtr<t_sep_struct_cmds>,cmds,DEF,$,$)\
    ADDVAR(TAutoPtr<t_cpp_code::i_strong_bayan>,cppcode,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_true_fcc
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_true_fcc
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(arr);
        if(!ok)return ok;
        dev.go_auto(cmds);
        dev.go_auto(cppcode);
        return ok;
      }
    };
    struct t_cmds{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmds)OWNER(t_fields_cmds_cppcode)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_sep_struct_cmds>,cmds,DEF,$,$)\
    ADDVAR(TAutoPtr<t_cpp_code::i_strong_bayan>,cppcode,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_cmds
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_cmds
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(cmds);
        if(!ok)return ok;
        dev.go_auto(cppcode);
        return ok;
      }
    };
    struct t_cppcode{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cppcode)OWNER(t_fields_cmds_cppcode)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_cpp_code>,cppcode,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_cppcode
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_cppcode
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(cppcode);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_true_fcc)\
    F(t_cmds    )\
    F(t_cppcode )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fields_cmds_cppcode)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_true_fcc>,tfcc,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cmds>,cmds,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cppcode>,c,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_fields_cmds_cppcode
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fields_cmds_cppcode
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(tfcc);
      dev.go_auto(cmds);
      dev.go_auto(c);
      return ok;
    }
  public:
  };
  struct t_struct_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_body)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_target_item>>,nested,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_fields_cmds_cppcode>,fcc,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_body
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(nested);
      dev.go_auto(sep0);
      ok=dev.go_auto(fcc);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_class_def:public i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_def)PARENT(i_def)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,arrow_or_colon,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_name,parent,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_def
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      dev.go_auto(sep0);
      static const auto g_static_var_2=QapStrFinder::fromArr(split("=>,:",","));
      ok=dev.go_any_str_from_vec(arrow_or_colon,g_static_var_2);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(parent);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_def:public i_def{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def)PARENT(i_def)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_def
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_def
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_target_sep:public i_target_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_sep)PARENT(i_target_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto($sep0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_target_item:public i_target_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_item)PARENT(i_target_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<i_def>,def,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_struct_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target_item
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(def);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_target_decl:public i_target_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_decl)PARENT(i_target_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target_decl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target_decl
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_str<t_name>(name);
      if(!ok)return ok;
      dev.go_auto($sep2);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_target_using:public i_target_item{
    //===>>===i_qa_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_str_ap)\
      ADD(t_str_qu)\
    ADDEND()
    class i_qa;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_qa_visitor{
    public:
      typedef t_target_using::i_qa i_qa;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_target_using::U U;//typedef t_target_using::U U;
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
      // 10kk bench:     31.81 ns/call               59.41 ns/call
      // O2   : UberCast(318.157 ms) vs dynamic_cast(594.17 ms) //  53.546%
      // Od   :          1678.17     vs              1610.70
      // Debug:          4948.20     vs              4892.66
      // compilation time:
      // UC 32.21 // 4.61 sec //408%
      // DC 28.73 // 1.13 sec
      // empty 27.60 
      template<class TYPE>
      static TYPE*UberCast(i_qa*p){
        if(!p)return nullptr;Is<TYPE,i_qa_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_qa*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_qa_visitor{
    //  void Do(t_str_ap&r){}
    //  void Do(t_str_qu&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_qa_visitor
    struct i_qa{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_qa)OWNER(t_target_using)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_qa
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_qa
    public:
      typedef i_qa_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_str_ap);
          F(t_str_qu);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_str_ap:public i_qa{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_ap)PARENT(i_qa)OWNER(t_target_using)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_str_ap
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_str_ap
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("'");
        if(!ok)return ok;
        ok=dev.go_str<TAutoPtr<i_char_item>>(body);
        if(!ok)return ok;
        ok=dev.go_const("'");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_str_qu:public i_qa{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_qu)PARENT(i_qa)OWNER(t_target_using)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_str_qu
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_str_qu
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("\"");
        if(!ok)return ok;
        ok=dev.go_str<vector<TAutoPtr<i_str_item>>>(body);
        if(!ok)return ok;
        ok=dev.go_const("\"");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_str_ap)\
    F(t_str_qu)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_using)PARENT(i_target_item)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(string,s,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDVAR(t_sep,$sep6,DEF,$,$)\
  ADDVAR(string,lexer,DEF,$,$)\
  ADDVAR(t_sep,$sep8,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target_using
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target_using
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_const("using");
      if(!ok)return ok;
      ok=dev.go_auto($sep2);
      if(!ok)return ok;
      ok=dev.go_str<TAutoPtr<i_qa>>(s);
      if(!ok)return ok;
      ok=dev.go_auto($sep4);
      if(!ok)return ok;
      ok=dev.go_const("as");
      if(!ok)return ok;
      ok=dev.go_auto($sep6);
      if(!ok)return ok;
      ok=dev.go_str<t_name>(lexer);
      if(!ok)return ok;
      dev.go_auto($sep8);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_target{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_target_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_name_code                   )\
  F(t_num_code                    )\
  F(t_str_seq                     )\
  F(t_sep_str_seq                 )\
  F(t_str_code                    )\
  F(t_char_code                   )\
  F(t_sign_code                   )\
  F(t_name_code_with_sep          )\
  F(t_num_code_with_sep           )\
  F(t_str_code_with_sep           )\
  F(t_char_code_with_sep          )\
  F(t_sign_code_with_sep          )\
  F(t_soft_brackets_code_with_sep )\
  F(t_hard_brackets_code_with_sep )\
  F(t_curly_brackets_code_with_sep)\
  F(t_code                        )\
  F(t_soft_brackets_code          )\
  F(t_hard_brackets_code          )\
  F(t_curly_brackets_code         )\
  F(t_semicolon                   )\
  F(t_value_item                  )\
  F(t_value                       )\
  F(t_type_scope                  )\
  F(t_type_templ                  )\
  F(t_type_item_string            )\
  F(t_type_item_char              )\
  F(t_type_item_number            )\
  F(t_scope_type_item             )\
  F(t_type_item_type              )\
  F(t_type_expr2                  )\
  F(t_type_templ_param            )\
  F(t_sep_type_templ_param        )\
  F(t_type_templ_params           )\
  F(t_type_templ_angle            )\
  F(t_type_templ_soft             )\
  F(t_struct_cmd_mode             )\
  F(t_sep_value                   )\
  F(t_attr                        )\
  F(t_const_field                 )\
  F(t_struct_field_value          )\
  F(t_struct_field                )\
  F(t_sep_struct_field            )\
  F(t_templ_params                )\
  F(t_cmd_params                  )\
  F(t_cmd_param                   )\
  F(t_struct_cmd_anno             )\
  F(t_struct_cmd_suffix           )\
  F(t_struct_cmd_optional         )\
  F(t_struct_cmd_opt_v2           )\
  F(t_struct_cmd                  )\
  F(t_sep_struct_cmd              )\
  F(t_struct_cmds                 )\
  F(t_sep_struct_cmds             )\
  F(t_cpp_code_sep                )\
  F(t_cpp_code_main               )\
  F(t_cpp_code                    )\
  F(t_fields_cmds_cppcode         )\
  F(t_struct_body                 )\
  F(t_class_def                   )\
  F(t_struct_def                  )\
  F(t_target_sep                  )\
  F(t_target_item                 )\
  F(t_target_decl                 )\
  F(t_target_using                )\
  F(t_target                      )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_meta_lexer)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_meta_lexer
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_meta_lexer
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    return ok;
  }
public:
};
bool t_cppcore::i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_int_expr);
  F(t_char_expr);
  F(t_bool_expr);
  F(t_string_expr);
  F(t_real_expr);
  F(t_varcall_expr);
  F(t_block_expr);
  #undef F
  main();
  return scope.ok;
}
bool t_cppcore::t_int_expr::i_val::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_zero);
  F(t_num);
  #undef F
  main();
  return scope.ok;
}
bool t_cppcore::t_real_expr::i_val::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_num);
  F(t_zero);
  #undef F
  main();
  return scope.ok;
}
bool t_cppcore::t_varcall_expr::i_part::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_dd_part);
  F(t_template_part);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_code::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_name_code);
  F(t_num_code);
  F(t_str_code);
  F(t_char_code);
  F(t_sign_code);
  F(t_soft_brackets_code);
  F(t_hard_brackets_code);
  F(t_curly_brackets_code);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_code_with_sep::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_name_code_with_sep);
  F(t_num_code_with_sep);
  F(t_str_code_with_sep);
  F(t_char_code_with_sep);
  F(t_sign_code_with_sep);
  F(t_soft_brackets_code_with_sep);
  F(t_hard_brackets_code_with_sep);
  F(t_curly_brackets_code_with_sep);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_type_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_type_item_string);
  F(t_type_item_char);
  F(t_type_item_number);
  F(t_type_item_type);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_type_templ::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_type_templ_angle);
  F(t_type_templ_soft);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_struct_cmd_xxxx::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_struct_cmd_mode);
  F(t_struct_cmd_anno);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_struct_field::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_const_field);
  F(t_struct_field);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_struct_cmd_so::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_struct_cmd_suffix);
  F(t_struct_cmd_optional);
  F(t_struct_cmd_opt_v2);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_cpp_code::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_cpp_code_sep);
  F(t_cpp_code_main);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_def::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_class_def);
  F(t_struct_def);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::i_target_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_target_sep);
  F(t_target_item);
  F(t_target_decl);
  F(t_target_using);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_const_field::i_sc_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_c_item);
  F(t_s_item);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_cmd_param::i_cmd_param_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_expr_call);
  F(t_expr_str);
  F(t_expr_var);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_cpp_code::i_major::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_fields);
  F(t_cmds);
  F(t_atr);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_cpp_code::i_bayan::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_with_bayan);
  F(t_without_bayan);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_cpp_code::i_strong_bayan::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_a);
  F(t_b);
  #undef F
  main();
  return scope.ok;
}
bool t_meta_lexer::t_target_using::i_qa::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_str_ap);
  F(t_str_qu);
  #undef F
  main();
  return scope.ok;
}
/*
//list of types:
F(t_using_test_20250628)F(t_cppcore)F(t_test20250618_atrr)F(t_meta_lexer)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fusing%5ftest%5f20250628%7b%0a%20%20using%20%22%20%22%20as%20t%5fsep%3b%0a%20
%20t%5ffoo%3b%0a%20%20t%5ffoo%7b%0a%20%20%20%20t%5fbar%7bt%5fbaz%7b%7d%7d%0a%20%
20%20%20t%5fbar%20b%3b%0a%20%20%20%20%22%20%22%0a%20%20%20%20t%5fbar%20c%3f%3b%0
a%20%20%20%20t%5fbar%20d%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%20%20t%
5ffoo%20foo%3b%0a%7d%0a%0at%5fcppcore%7b%0a%0at%5flev03%7b%0a%20%20string%20oper
%3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2c%2d%2c%21%2c%7e%22%2c%22%2c%22%29%2
9%3f%3b%0a%20%20TAutoPtr%3ci%5fexpr%3e%20expr%3b%0a%7d%0at%5flev05%7b%0a%20%20t%
5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%2a%2c%2f%2c%25%22
%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7bt%5foper%20oper%3bt%5flev03%20expr%3
b%7d%0a%20%20t%5flev03%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%
0at%5flev06%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28spli
t%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7bt%5foper%20oper%3
bt%5flev05%20expr%3b%7d%0a%20%20t%5flev05%20expr%3b%0a%20%20vector%3ct%5fitem%3e
%20arr%3f%3b%0a%7d%0at%5flev07%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%
5ffrom%5fvec%28split%28%22%3c%3c%2c%3e%3e%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5
fitem%7bt%5foper%20oper%3bt%5flev06%20expr%3b%7d%0a%20%20t%5flev06%20expr%3b%0a%
20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev08%7b%0a%20%20t%5foper%7bst
ring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%3c%2c%3c%3d%2c%3e%2c%3e%3d%2
2%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7bt%5foper%20oper%3bt%5flev07%20expr%
3b%7d%0a%20%20t%5flev07%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d
%0at%5flev09%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28spl
it%28%22%3d%3d%2c%21%3d%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7bt%5foper%2
0oper%3bt%5flev08%20expr%3b%7d%0a%20%20t%5flev08%20expr%3b%0a%20%20vector%3ct%5f
item%3e%20arr%3f%3b%0a%7d%0at%5flev10%7b%0a%20%20t%5foper%7b%22%26%22%20inline%2
0static%20const%20string%20value%3d%22%26%22%3b%7d%0a%20%20t%5fitem%7bt%5foper%2
0oper%3b%20t%5flev09%20expr%3b%7d%0a%20%20t%5flev09%20expr%3b%0a%20%20vector%3ct
%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev11%7b%0a%20%20t%5foper%7b%22%5e%22%20inlin
e%20static%20const%20string%20value%3d%22%5e%22%3b%7d%0a%20%20t%5fitem%7bt%5fope
r%20oper%3b%20t%5flev10%20expr%3b%7d%0a%20%20t%5flev10%20expr%3b%0a%20%20vector%
3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev12%7b%0a%20%20t%5foper%7b%22%7c%22%20in
line%20static%20const%20string%20value%3d%22%7c%22%3b%7d%0a%20%20t%5fitem%7bt%5f
oper%20oper%3b%20t%5flev11%20expr%3b%7d%0a%20%20t%5flev11%20expr%3b%0a%20%20vect
or%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev13%7b%0a%20%20t%5foper%7b%22%26%26%2
2%20inline%20static%20const%20string%20value%3d%22%26%26%22%3b%7d%0a%20%20t%5fit
em%7bt%5foper%20oper%3b%20t%5flev12%20expr%3b%7d%0a%20%20t%5flev12%20expr%3b%0a%
20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev14%7b%0a%20%20t%5foper%7b%2
2%7c%7c%22%20inline%20static%20const%20string%20value%3d%22%7c%7c%22%3b%7d%0a%20
%20t%5fitem%7bt%5foper%20oper%3b%20t%5flev13%20expr%3b%7d%0a%20%20t%5flev13%20ex
pr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0a%2f%2a%0avar%20pad2%3dnum
%3d%3e%28num%3c10%3f%220%22%2bnum%3a%22%22%2bnum%29%3b%0areturn%28%0a%60%2b%2c%2
d%2c%21%2c%7e%0a%2a%2c%2f%2c%25%0a%2b%2c%2d%0a%3c%3c%2c%3e%3e%0a%3c%2c%3c%3d%2c%
3e%2c%3e%3d%0a%3d%3d%2c%21%3d%0a%26%0a%5e%0a%7c%0a%26%26%0a%7c%7c%60%2esplit%28%
22%5cr%22%29%2ejoin%28%22%22%29%2esplit%28%22%5cn%22%29%2emap%28%28ops%2ci%29%3d
%3e%7b%0a%20%20var%20e%3d%22t%5flev%22%2bpad2%28i%3d%3d1%3f3%3ai%2b3%29%3b%0a%20
%20var%20n%3d%22t%5flev%22%2bpad2%28i%2b4%29%3b%0a%20%20if%28%21i%29%7b%0a%20%20
%20%20return%20%60t%5flev03%7b%0a%20%20string%20oper%3dany%5fstr%5ffrom%5fvec%28
split%28%60%2bJSON%2estringify%28ops%29%2b%60%2c%22%2c%22%29%29%3f%3b%0a%20%20TA
utoPtr%3ci%5fexpr%3e%20expr%3b%0a%7d%60%3b%0a%20%20%7d%0a%20%20var%20oa%3dops%2e
split%28%22%2c%22%29%3b%0a%20%20if%28oa%2elength%3d%3d1%29%7b%0a%20%20%20%20retu
rn%20n%2b%60%7b%0a%20%20t%5foper%7b%22%60%2boa%5b0%5d%2b%60%22%20inline%20static
%20const%20string%20value%3d%22%60%2boa%5b0%5d%2b%60%22%3b%7d%0a%20%20t%5fitem%7
bt%5foper%20oper%3b%20%60%2be%2b%60%20expr%3b%7d%0a%20%20%60%2be%2b%60%20expr%3b
%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%60%3b%0a%20%20%7d%0a%20%20return
%20n%2b%60%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split
%28%22%60%2bops%2b%60%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7bt%5foper%20o
per%3b%60%2be%2b%60%20expr%3b%7d%0a%20%20%60%2be%2b%60%20expr%3b%0a%20%20vector%
3ct%5fitem%3e%20arr%3f%3b%0a%7d%60%3b%0a%7d%29%2ejoin%28%22%5cn%22%29%29%3b%0a%2
a%2f%0at%5fstring%7b%0a%20%20%22%5c%22%22%0a%20%20string%20value%3dstr%3cvector%
3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%3e%28%29%3f%3b%0a%20%20%22%5c%22%22%0a%7d%0a%0
at%5fint%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fzero%3ai%5fval%7b%220%22%7d%0a%20%20t%
5fnum%3ai%5fval%7b%0a%20%20%20%20char%20first%3dany%5fchar%28gen%5fdips%28%2219%
22%29%29%3b%0a%20%20%20%20string%20num%3dany%28gen%5fdips%28%2209%22%29%29%3f%3b
%0a%20%20%7d%0a%20%20string%20value%3dstr%3cTAutoPtr%3ci%5fval%3e%3e%28%29%3b%0a
%7d%0a%0at%5ftype%5fexpr%7b%0a%20%20t%5fparams%7b%0a%20%20%20%20%22%7b%22%0a%20%
20%20%20string%20type%3dstr%3ct%5ftype%5fexpr%3e%28%29%3b%0a%20%20%20%20%22%2c%2
2%0a%20%20%20%20t%5fint%5fexpr%20count%3b%0a%20%20%20%20%22%7d%22%0a%20%20%7d%0a
%20%20t%5felem%7b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20TAutoPtr%3ct%5f
params%3e%20params%3f%3b%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5fsep%2
0sep0%3f%3b%0a%20%20%20%20%22%3a%3a%22%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%
20%20%20t%5felem%20body%3b%0a%20%20%7d%0a%20%20t%5felem%20first%3b%0a%20%20vecto
r%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0a%0at%5fchar%5fexpr%3ai%5fexpr%7b%0a%20%20t%5
fchar%5fitem%20body%3b%0a%7d%0a%0at%5fbool%5fexpr%3ai%5fexpr%7b%0a%20%20string%2
0value%3dany%5fstr%5ffrom%5fvec%28split%28%22true%2cfalse%22%2c%22%2c%22%29%29%3
b%0a%7d%0a%0at%5fstring%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fstring%20body%3b%0a%7d%
0a%0at%5freal%5fexpr%3ai%5fexpr%7b%0a%20%20t%5ffrac%7b%0a%20%20%20%20%22%2e%22%0
a%20%20%20%20string%20arr%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%7d%0a%
20%20t%5fsign%7b%0a%20%20%20%20char%20sign%3dany%5fchar%28%22%2d%2b%22%29%3b%0a%
20%20%7d%0a%20%20t%5fexp%7b%0a%20%20%20%20char%20e%3dany%5fchar%28%22eE%22%29%3b
%0a%20%20%20%20TAutoPtr%3ct%5fsign%3e%20sign%3f%3b%0a%20%20%20%20string%20arr%3d
any%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fnum%3ai%5fval%7b%0a
%20%20%20%20char%20first%3dany%5fchar%28gen%5fdips%28%2219%22%29%29%3b%0a%20%20%
20%20string%20num%3dany%28gen%5fdips%28%2209%22%29%29%3f%3b%0a%20%20%7d%0a%20%20
t%5fzero%3ai%5fval%7b%220%22%7d%0a%20%20t%5fimpl%7b%0a%20%20%20%20TAutoPtr%3ci%5
fval%3e%20val%3b%0a%20%20%20%20TAutoPtr%3ct%5ffrac%3e%20frac%3b%0a%20%20%20%20TA
utoPtr%3ct%5fexp%3e%20exp%3f%3b%0a%20%20%7d%0a%20%20string%20value%3dstr%3ct%5fi
mpl%3e%28%29%3b%0a%7d%0a%0at%5fcall%5fparam%7b%0a%20%20t%5fsep%20sep0%3f%3b%0a%2
0%20t%5flev14%20body%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a%7d%0a%0at%5fcall%5fparam
s%7b%0a%20%20%22%28%22%0a%20%20t%5fsep%20sep%3f%3b%0a%20%20vector%3ct%5fcall%5fp
aram%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%22%29%22%0a%7d%0a%0at%5fvarcal
l%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fsb%5fexpr%7b%0a%20%20%20%20%22%5b%22%0a%20%20
%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5flev14%20expr%3b%0a%20%20%20%20t%5fs
ep%20sep1%3f%3b%0a%20%20%20%20%22%5d%22%0a%20%20%7d%0a%20%20t%5fdd%5fpart%3ai%5f
part%7b%0a%20%20%20%20t%5felem%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20
%20%20%20%20%20%22%3a%3a%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20
%20%20%20t%5fname%20name%3b%0a%20%20%20%20%7d%0a%20%20%20%20vector%3ct%5felem%3e
%20arr%3b%0a%20%20%7d%0a%20%20t%5ftemplate%5fpart%3ai%5fpart%7b%0a%20%20%20%20t%
5fsep%20sepB%3f%3b%0a%20%20%20%20%22%3c%22%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a
%20%20%20%20t%5flev14%20expr%3b%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%2
0%22%3e%22%0a%20%20%20%20TAutoPtr%3ct%5fdd%5fpart%3e%20ddp%3f%3b%0a%20%20%7d%0a%
20%20t%5farr%7b%0a%20%20%20%20t%5fsep%20sep%3f%3b%0a%20%20%20%20vector%3ct%5fsb%
5fexpr%3e%20arr%3b%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20%22%2e%22%0a%20
%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20t%5
farr%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fvar%7b%0a%20%20%20%20t%5fname%20name%3b
%0a%20%20%20%20TAutoPtr%3ci%5fpart%3e%20tp%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5far
r%3e%20arr%3f%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20items%3f%3b%0a%20%20%7d%0a
%20%20t%5fvar%20var%3b%0a%20%20t%5fsep%20sep%3f%3b%0a%20%20t%5fcall%5fparams%20p
arams%3f%3b%0a%7d%0a%0at%5fblock%5fexpr%3ai%5fexpr%7b%0a%20%20%22%28%22%0a%20%20
t%5flev14%20body%3b%0a%20%20%22%29%22%0a%7d%0a%0a%2f%2a%0at%5fcall%5fexpr%3ai%5f
expr%7b%0a%20%20t%5fvar%5fexpr%20call%3b%0a%20%20t%5fsep%20sep%3f%3b%0a%20%20t%5
fcall%5fparams%20params%3b%0a%7d%2a%2f%0a%0a%7d%0a%0ausing%20%22%20%22%20as%20t%
5fsep%3b%0a%0at%5ftest20250618%5fatrr%7b%0a%20%20t%5ffoo%7b%7b%7d%5b%3a%3a%5d%7d
%0a%20%20t%5ffoo%20foo%3b%20%5bskip%5d%0a%20%20t%5fsep%20sep%3b%20%5boptimize%2c
%22sep%22%2c%28%22sep%22%29%2csep%5bx%5d%5d%0a%20%20%7b%0a%20%20%20%20go%5fauto%
28foo%29%3b%0a%20%20%20%20go%5fauto%28sep%29%3b%0a%20%20%7d%0a%7d%0a%0a%2f%2ft%5
ftest20250620%5fdev%7b%0a%2f%2f%20%20t%5ffoo%7b%7b%7d%7d%0a%2f%2f%20%20t%5fbar%7
b%0a%2f%2f%20%20%20%20%22more%20tests%22%0a%2f%2f%20%20%20%20%22test%22%0a%2f%2f
%20%20%20%20t%5fsep%20sep%3b%0a%2f%2f%20%20%20%20%22another%20test%22%20%2f%2a%2
0yes%20%60%20%22%3b%22%20%2a%2f%20%3b%0a%2f%2f%20%20%20%20t%5ffoo%20foo%3f%3b%0a
%2f%2f%20%20%20%20%22nope%22%3b%0a%2f%2f%20%20%7d%0a%2f%2f%20%20string%20dev%3da
ny%28%22%3b%3f%27%2d%3e%3d%3c%60%28%29%2f%5c%5c%2b%22%29%3f%3b%0a%2f%2f%20%20t%5
ffoo%20%24dev0%3b%0a%2f%2f%20%20t%5fbar%20%24dev1%3b%0a%2f%2f%20%20%2f%2a%7b%0a%
2f%2f%20%20%20%20go%5fany%28dev%2c%22%3b%3f%27%2d%3e%3d%3c%60%28%29%2f%5c%5c%2b%
22%29%3b%0a%2f%2f%20%20%20%20go%5fauto%28%24dev0%29%3b%0a%2f%2f%20%20%20%20go%5f
auto%28%24dev1%29%3b%0a%2f%2f%20%20%7d%2a%2f%0a%2f%2f%7d%0at%5fmeta%5flexer%7b%0
a%0at%5fname%5fcode%3ai%5fcode%7b%0a%20%20string%20value%3dstr%3ct%5fname%3a%3at
%5fimpl%3e%28%29%3b%0a%7d%0a%0at%5fnum%5fcode%3ai%5fcode%7b%0a%20%20t%5fnumber%2
0body%3b%0a%7d%0a%0at%5fstr%5fseq%7b%0a%20%20%22%5c%22%22%0a%20%20vector%3cTAuto
Ptr%3ci%5fstr%5fitem%3e%3e%20arr%3f%3b%0a%20%20%22%5c%22%22%0a%20%20%7d%0a%0at%5
fsep%5fstr%5fseq%7b%0a%20%20%22%20%22%0a%20%20t%5fstr%5fseq%20body%3b%0a%7d%0a%0
at%5fstr%5fcode%3ai%5fcode%7b%0a%20%20t%5fstr%5fseq%20first%3b%0a%20%20vector%3c
t%5fsep%5fstr%5fseq%3e%20arr%3f%3b%0a%7d%0a%0at%5fchar%5fcode%3ai%5fcode%7b%0a%2
0%20%22%27%22%0a%20%20TAutoPtr%3ci%5fchar%5fitem%3e%20body%3b%0a%20%20%22%27%22%
0a%7d%0a%0at%5fsign%5fcode%3ai%5fcode%7b%0a%20%20t%5fsign%20body%3b%0a%7d%0a%0at
%5fname%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7bt%5fname%5fcode%20body%
3bt%5fsep%20sep%3f%3b%7d%0at%5fnum%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fse
p%7bt%5fnum%5fcode%20body%3bt%5fsep%20sep%3f%3b%7d%0at%5fstr%5fcode%5fwith%5fsep
%3d%3ei%5fcode%5fwith%5fsep%7bt%5fstr%5fcode%20body%3bt%5fsep%20sep%3f%3b%7d%0at
%5fchar%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7bt%5fchar%5fcode%20body%
3bt%5fsep%20sep%3f%3b%7d%0at%5fsign%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fs
ep%7bt%5fsign%5fcode%20body%3bt%5fsep%20sep%3f%3b%7d%0at%5fsoft%5fbrackets%5fcod
e%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20%22%28%22%20%22%20%22%3f%20
vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3f%3b%20%22%29%22%20%22%2
0%22%3f%0a%7d%0at%5fhard%5fbrackets%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fs
ep%7b%0a%20%20%22%5b%22%20%22%20%22%3f%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fs
ep%3e%3e%20body%3f%3b%20%22%5d%22%20%22%20%22%3f%0a%7d%0at%5fcurly%5fbrackets%5f
code%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20%22%7b%22%20%22%20%22%3f
%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3f%3b%20%22%7d%22%20%2
2%20%22%3f%0a%7d%0a%0a%2f%2freal%5fsource%5fdata%3a%0a%2f%2a%0at%5fname%5fcode%0
at%5fnum%5fcode%0at%5fstr%5fcode%0at%5fchar%5fcode%0at%5fsign%5fcode%0at%5fsoft%
5fbrackets%5fcode%0at%5fhard%5fbrackets%5fcode%0at%5fcurly%5fbrackets%5fcode%0a%
40%40%40%0a%2a%2f%0a%0a%2f%2freal%5fsource%5fcode%3a%0a%2f%2a%0avar%20mk%3dPOST%
5b%27data%27%5d%2esplit%28%22%40%40%40%22%29%5b1%5d%3b%0avar%20gen%3dfunction%28
lex%2cmk%29%7b%0a%20%20if%28lex%2eincludes%28%22brackets%22%29%29%7b%0a%20%20%20
%20var%20json%3dJSON%2estringify%3b%0a%20%20%20%20var%20m%3d%7bsoft%3a%5b%22%28%
22%2c%22%29%22%5d%2chard%3a%5b%22%5b%22%2c%22%5d%22%5d%2ccurly%3a%5b%22%7b%22%2c
%22%7d%22%5d%7d%0a%20%20%20%20for%28var%20k%20in%20m%29if%28lex%2eincludes%28k%2
9%29return%20%5b%0a%20%20%20%20%20%20lex%2b%22%5fwith%5fsep%3d%3ei%5fcode%5fwith
%5fsep%7b%22%2c%0a%20%20%20%20%20%20%22%20%20%22%2bjson%28m%5bk%5d%5b0%5d%29%2b%
27%20%22%20%22%3f%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3f%3b
%20%27%2bjson%28m%5bk%5d%5b1%5d%29%2b%27%20%22%20%22%3f%27%2c%0a%20%20%20%20%20%
20%22%7d%22%0a%20%20%20%20%5d%2ejoin%28%22%5cn%22%29%3b%0a%20%20%7d%0a%20%20retu
rn%20lex%2b%22%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%22%2blex%2b%22%20body%
3bt%5fsep%20sep%3f%3b%7d%22%3b%0a%7d%0avar%20out%3d%5b%5d%3b%0avar%20arr%3dPOST%
5b%27data%27%5d%2esplit%28%22%5cn%40%40%40%22%29%5b0%5d%2esplit%28%22%5cr%22%29%
2ejoin%28%22%22%29%2esplit%28%22%5cn%22%29%3b%0afor%28var%20i%3d0%3bi%3carr%2ele
ngth%3bi%2b%2b%29%7b%0a%20%20out%2epush%28gen%28arr%5bi%5d%2cmk%29%29%3b%0a%7d%0
areturn%20out%2ejoin%28%22%5cn%22%29%3b%0a%2a%2f%0a%0at%5fcode%7b%0a%20%20vector
%3cTAutoPtr%3ci%5fcode%3e%3e%20arr%3b%0a%7d%0a%0at%5fsoft%5fbrackets%5fcode%3ai%
5fcode%7b%0a%20%20%22%28%22%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ct%5f
code%3e%20body%3f%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a%20%20%22%29%22%0a%7d%0a%0at
%5fhard%5fbrackets%5fcode%3ai%5fcode%7b%0a%20%20%22%5b%22%0a%20%20t%5fsep%20sep0
%3f%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3f%3b%0a%20%20t%5fsep%20sep1%3f%3b%
0a%20%20%22%5d%22%0a%7d%0a%0at%5fcurly%5fbrackets%5fcode%3ai%5fcode%7b%0a%20%20%
22%7b%22%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3f%3
b%0a%20%20t%5fsep%20sep1%3f%3b%0a%20%20%22%7d%22%0a%7d%0a%0at%5fsemicolon%7b%0a%
20%20%22%3b%22%0a%7d%0a%0at%5fvalue%5fitem%7b%0a%20%20string%20body%3dstr%3cTAut
oPtr%3ct%5fcppcore%3a%3ai%5fexpr%3e%3e%28%29%3b%0a%7d%0a%0at%5fvalue%7b%0a%20%20
%22%20%22%3f%0a%20%20%22%3d%22%0a%20%20string%20body%3dstr%3cTAutoPtr%3ct%5fcppc
ore%3a%3ai%5fexpr%3e%3e%28%29%3b%0a%7d%0a%0at%5ftype%5fscope%7b%0a%20%20%22%3a%3
a%22%0a%7d%0a%0at%5ftype%5ftempl%7b%0a%20%20TAutoPtr%3ci%5ftype%5ftempl%3e%20bod
y%3b%0a%7d%0a%0at%5ftype%5fitem%5fstring%3ai%5ftype%5fitem%7b%0a%20%20t%5fstr%5f
item%20body%3b%0a%7d%0a%0at%5ftype%5fitem%5fchar%3ai%5ftype%5fitem%7b%0a%20%20t%
5fchar%5fitem%20body%3b%0a%7d%0a%0at%5ftype%5fitem%5fnumber%3ai%5ftype%5fitem%7b
%0a%20%20t%5fnumber%20body%3b%0a%7d%0a%0at%5ftype%5fitem%5ftype%3b%0a%0at%5fscop
e%5ftype%5fitem%7b%0a%20%20t%5ftype%5fscope%20scope%3b%0a%20%20TAutoPtr%3ct%5fty
pe%5fitem%5ftype%3e%20body%3b%0a%7d%0a%0at%5ftype%5fitem%5ftype%3ai%5ftype%5fite
m%20%7b%0a%20%20TAutoPtr%3ct%5ftype%5fscope%3e%20scope%3f%3b%0a%20%20t%5fname%20
type%3b%0a%20%20TAutoPtr%3ct%5ftype%5ftempl%3e%20param%3f%3b%0a%20%20vector%3ct%
5fscope%5ftype%5fitem%3e%20arr%3f%3b%0a%7d%0a%0at%5ftype%5fexpr2%7b%0a%20%20TAut
oPtr%3ct%5ftype%5fscope%3e%20scope%3f%3b%0a%20%20t%5ftype%5fitem%5ftype%20body%3
b%0a%7d%0a%0at%5ftype%5ftempl%5fparam%7b%0a%20%20TAutoPtr%3ci%5ftype%5fitem%3e%2
0body%3b%0a%7d%0a%0at%5fsep%5ftype%5ftempl%5fparam%7b%0a%20%20%22%2c%22%0a%20%20
t%5ftype%5ftempl%5fparam%20body%3b%0a%7d%0a%0at%5ftype%5ftempl%5fparams%7b%0a%20
%20t%5ftype%5ftempl%5fparam%20first%3b%0a%20%20vector%3ct%5fsep%5ftype%5ftempl%5
fparam%3e%20arr%3f%3b%0a%7d%0a%0at%5ftype%5ftempl%5fangle%3ai%5ftype%5ftempl%7b%
0a%20%20%22%3c%22%0a%20%20TAutoPtr%3ct%5ftype%5ftempl%5fparams%3e%20params%3f%3b
%0a%20%20%22%3e%22%0a%7d%0a%0at%5ftype%5ftempl%5fsoft%3ai%5ftype%5ftempl%7b%0a%2
0%20%22%28%22%0a%20%20TAutoPtr%3ct%5ftype%5ftempl%5fparams%3e%20params%3f%3b%0a%
20%20%22%29%22%0a%7d%0a%0at%5fstruct%5fcmd%5fmode%3ai%5fstruct%5fcmd%5fxxxx%7b%0
a%20%20char%20body%3dany%5fchar%28%22DMO%22%29%3b%0a%20%20%22%20%22%3f%0a%20%20%
22%2b%3d%22%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fsep%5fvalue%7b%0a%20%20%22%20%22
%3f%0a%20%20t%5fvalue%5fitem%20value%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fattr
%7b%0a%20%20%22%5b%22%0a%20%20vector%3ct%5fsep%5fvalue%3e%20arr%3dvec%28%22%2c%2
2%29%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%5d%22%0a%7d%0at%5fconst%5ffield%3ai%
5fstruct%5ffield%7b%0a%20%20t%5fqst%7b%22%3f%22%7d%0a%20%20t%5fc%5fitem%3ai%5fsc
%5fitem%7bt%5fchar%5fitem%20body%3b%7d%0a%20%20t%5fs%5fitem%3ai%5fsc%5fitem%7bt%
5fstr%5fitem%20body%3b%7d%0a%20%20string%20value%3dstr%3cTAutoPtr%3ci%5fsc%5fite
m%3e%3e%28%29%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fqst%3e%20qst%3f%3b%
0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fsemicolon%3e%20sc%3f%3b%0a%7d%0a%0at
%5fstruct%5ffield%5fvalue%20%7b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%3b%0a%20%
20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fcppcore%3a%3at%5fvarcall%5fexpr%3e%20expr%
3b%0a%7d%0at%5fstruct%5ffield%3ai%5fstruct%5ffield%7b%0a%20%20t%5fqst%7bstring%2
0s%3b%7bgo%5fany%28s%2c%22%2a%3f%22%29%3b%7d%7d%0a%20%20TAutoPtr%3ci%5fstruct%5f
cmd%5fxxxx%3e%20mode%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fcppcore%3
a%3ai%5fexpr%3e%20type%3b%0a%20%20%22%20%22%0a%20%20t%5fname%20name%3b%0a%20%20T
AutoPtr%3ct%5fstruct%5ffield%5fvalue%3e%20value%3f%3b%0a%20%20%22%20%22%3f%0a%20
%20TAutoPtr%3ct%5fqst%3e%20qst%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%2
0%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fattr%3e%20attr%3f%3b%0a%7d%0a%0at%5fsep%
5fstruct%5ffield%7b%0a%20%20%22%20%22%3f%0a%20%20i%5fstruct%5ffield%20body%3b%0a
%7d%0a%0at%5ftempl%5fparams%7b%0a%20%20%22%3c%22%0a%20%20string%20body%3dstr%3cT
AutoPtr%3ct%5ftype%5ftempl%5fparams%3e%3e%28%29%3b%0a%20%20%22%3e%22%0a%7d%0a%0a
t%5fcmd%5fparam%3b%0at%5fcmd%5fparams%7b%0a%20%20vector%3ct%5fcmd%5fparam%3e%20a
rr%3dvec%28%22%2c%22%29%3b%0a%7d%0a%0at%5fcmd%5fparam%7b%0a%20%20t%5fimpl%7b%0a%
20%20%20%20vector%3cTAutoPtr%3ci%5fcmd%5fparam%5fexpr%3e%3e%20arr%3dvec%28%22%2b
%22%29%3b%0a%20%20%7d%0a%20%20t%5fexpr%5fcall%3ai%5fcmd%5fparam%5fexpr%7b%0a%20%
20%20%20t%5fname%20func%3b%0a%20%20%20%20%22%28%22%0a%20%20%20%20TAutoPtr%3ct%5f
cmd%5fparams%3e%20params%3b%0a%20%20%20%20%22%29%22%0a%20%20%7d%0a%20%20t%5fexpr
%5fstr%3ai%5fcmd%5fparam%5fexpr%7b%0a%20%20%20%20string%20body%3dstr%3ct%5fstr%5
fseq%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5fexpr%5fvar%3ai%5fcmd%5fparam%5fexpr%7b%
0a%20%20%20%20t%5fthis%7b%22this%2d%3e%22%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%
20%20%20%20TAutoPtr%3ct%5fthis%3e%20self%3f%3b%0a%20%20%20%20%20%20t%5fname%20na
me%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20body%3dstr%3ct%5fimpl%3e%28%29%3b
%0a%20%20%7d%0a%20%20string%20body%3dstr%3ct%5fimpl%3e%28%29%3b%0a%7d%0at%5fstru
ct%5fcmd%5fanno%3ai%5fstruct%5fcmd%5fxxxx%7b%0a%20%20string%20mode%3dany%5fstr%5
ffrom%5fvec%28split%28%22%40mandatory%2c%40optional%2c%40mand%2c%40opti%2c%40man
%2c%40opt%2c%40ma%2c%40op%2c%40m%2c%40o%2cm%2co%22%2c%22%2c%22%29%29%3b%0a%20%20
%22%20%22%3b%0a%7d%0a%0at%5fstruct%5fcmd%5fsuffix%3ai%5fstruct%5fcmd%5fso%7b%0a%
20%20char%20value%3dany%5fchar%28%22%3f%21%22%29%3b%0a%7d%0a%0at%5fstruct%5fcmd%
5foptional%3ai%5fstruct%5fcmd%5fso%7b%0a%20%20%22%5b%22%0a%20%20string%20value%3
dany%5fstr%5ffrom%5fvec%28split%28%22optional%2cmandatory%22%2c%22%2c%22%29%29%3
b%0a%20%20%22%5d%22%0a%7d%0a%0at%5fstruct%5fcmd%5fopt%5fv2%3ai%5fstruct%5fcmd%5f
so%7b%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%20%20string%20value%3dany%5fstr%
5ffrom%5fvec%28split%28%22optional%2cmandatory%22%2c%22%2c%22%29%29%3b%0a%7d%0at
%5fstruct%5fcmd%7b%0a%20%20TAutoPtr%3ci%5fstruct%5fcmd%5fxxxx%3e%20mode%3f%3b%0a
%20%20t%5fname%20func%3b%0a%20%20%22%20%22%3f%0a%20%20string%20templ%5fparams%3d
str%3cTAutoPtr%3ct%5ftempl%5fparams%3e%3e%28%29%3f%3b%0a%20%20%22%28%22%0a%20%20
t%5fcmd%5fparams%20params%3b%0a%20%20%22%29%22%0a%20%20%22%20%22%3f%0a%20%20TAut
oPtr%3ci%5fstruct%5fcmd%5fso%3e%20cmdso%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3
b%22%0a%7d%0a%0at%5fsep%5fstruct%5fcmd%7b%0a%20%20%22%20%22%3f%0a%20%20t%5fstruc
t%5fcmd%20body%3b%0a%7d%0a%0at%5fstruct%5fcmds%7b%0a%20%20%22%7b%22%0a%20%20vect
or%3ct%5fsep%5fstruct%5fcmd%3e%20arr%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%7d%2
2%0a%7d%0a%0at%5fsep%5fstruct%5fcmds%7b%0a%20%20%22%20%22%3f%0a%20%20t%5fstruct%
5fcmds%20body%3b%0a%7d%0a%0a%0at%5fcpp%5fcode%5fsep%3ai%5fcpp%5fcode%7b%0a%20%20
t%5fsep%20sep%3b%0a%7d%0a%0at%5fcpp%5fcode%5fmain%3ai%5fcpp%5fcode%7b%0a%20%20TA
utoPtr%3ci%5fcode%5fwith%5fsep%3e%20body%3b%0a%7d%0a%0at%5fcpp%5fcode%7b%0a%20%2
0t%5fbayan%7b%22%5b%3a%3a%5d%22%7d%0a%20%20t%5ffields%3ai%5fmajor%7bt%5fsep%5fst
ruct%5ffield%20f%3b%7d%0a%20%20t%5fcmds%3ai%5fmajor%7bt%5fsep%5fstruct%5fcmds%20
c%3b%7d%0a%20%20t%5fatr%3ai%5fmajor%7bTAutoPtr%3ct%5fattr%3e%20attr%3b%7d%0a%20%
20t%5feater%7bvector%3cTAutoPtr%3ci%5fcpp%5fcode%3e%3e%20arr%3b%7d%0a%20%20t%5fw
ith%5fbayan%3ai%5fbayan%7b%0a%20%20%20%20t%5fbayan%20bayan%3b%0a%20%20%20%20t%5f
eater%20eater%3f%3b%0a%20%20%7d%0a%20%20t%5fwithout%5fbayan%3ai%5fbayan%7b%0a%20
%20%20%20t%5feater%20eater%3dminor%3cTAutoPtr%3ci%5fmajor%3e%3e%28%29%3b%0a%20%2
0%7d%0a%20%20t%5fa%3ai%5fstrong%5fbayan%7b%0a%20%20%20%20t%5fwith%5fbayan%20wb%3
b%0a%20%20%7d%0a%20%20t%5fb%3ai%5fstrong%5fbayan%7b%0a%20%20%20%20t%5feater%20e%
3dminor%3ct%5fwith%5fbayan%3e%28%29%3b%0a%20%20%7d%0a%20%20TAutoPtr%3ci%5fbayan%
3e%20bayan%3b%0a%7d%0a%2f%2f%20test%0a%0at%5ffields%5fcmds%5fcppcode%7b%0a%20%20
t%5ftrue%5ffcc%7b%0a%20%20%20%20vector%3ct%5fsep%5fstruct%5ffield%3e%20arr%3b%0a
%20%20%20%20TAutoPtr%3ct%5fsep%5fstruct%5fcmds%3e%20cmds%3f%3b%0a%20%20%20%20TAu
toPtr%3ct%5fcpp%5fcode%3a%3ai%5fstrong%5fbayan%3e%20cppcode%3f%3b%0a%20%20%7d%0a
%20%20t%5fcmds%7b%0a%20%20%20%20TAutoPtr%3ct%5fsep%5fstruct%5fcmds%3e%20cmds%3b%
0a%20%20%20%20TAutoPtr%3ct%5fcpp%5fcode%3a%3ai%5fstrong%5fbayan%3e%20cppcode%3f%
3b%0a%20%20%7d%0a%20%20t%5fcppcode%7b%0a%20%20%20%20TAutoPtr%3ct%5fcpp%5fcode%3e
%20cppcode%3b%0a%20%20%7d%0a%20%20TAutoPtr%3ct%5ftrue%5ffcc%3e%20tfcc%3f%3b%0a%2
0%20TAutoPtr%3ct%5fcmds%3e%20cmds%3f%3b%0a%20%20TAutoPtr%3ct%5fcppcode%3e%20c%3f
%3b%0a%7d%0a%0at%5fstruct%5fbody%7b%0a%20%20%22%7b%22%0a%20%20vector%3cTAutoPtr%
3ci%5ftarget%5fitem%3e%3e%20nested%3f%3b%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TA
utoPtr%3ct%5ffields%5fcmds%5fcppcode%3e%20fcc%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a
%20%20%22%7d%22%0a%7d%0a%0at%5fclass%5fdef%3ai%5fdef%7b%0a%20%20t%5fname%20name%
3b%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20string%20arrow%5for%5fcolon%3dany%5fstr%
5ffrom%5fvec%28split%28%22%3d%3e%2c%3a%22%2c%22%2c%22%29%29%3b%0a%20%20t%5fsep%2
0sep1%3f%3b%0a%20%20t%5fname%20parent%3b%0a%7d%0a%0at%5fstruct%5fdef%3ai%5fdef%7
b%0a%20%20t%5fname%20name%3b%0a%7d%0at%5ftarget%5fsep%3ai%5ftarget%5fitem%7b%22%
20%22%7d%0at%5ftarget%5fitem%3ai%5ftarget%5fitem%7b%0a%20%20t%5fsep%20sep0%3f%3b
%0a%20%20TAutoPtr%3ci%5fdef%3e%20def%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a%20%20t%5
fstruct%5fbody%20body%3b%0a%7d%0a%0at%5ftarget%5fdecl%3ai%5ftarget%5fitem%7b%0a%
20%20%22%20%22%3f%0a%20%20string%20name%3dstr%3ct%5fname%3e%28%29%3b%0a%20%20%22
%20%22%3f%0a%20%20%22%3b%22%0a%7d%0a%0at%5ftarget%5fusing%3ai%5ftarget%5fitem%7b
%0a%20%20t%5fstr%5fap%3ai%5fqa%7b%0a%20%20%20%20%22%27%22%0a%20%20%20%20string%2
0body%3dstr%3cTAutoPtr%3ci%5fchar%5fitem%3e%3e%28%29%3b%0a%20%20%20%20%22%27%22%
0a%20%20%7d%0a%20%20t%5fstr%5fqu%3ai%5fqa%7b%0a%20%20%20%20%22%5c%22%22%0a%20%20
%20%20string%20body%3dstr%3cvector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%3e%28%29%3b
%0a%20%20%20%20%22%5c%22%22%0a%20%20%7d%0a%20%20%22%20%22%3f%0a%20%20%22using%22
%0a%20%20%22%20%22%0a%20%20string%20s%3dstr%3cTAutoPtr%3ci%5fqa%3e%3e%28%29%3b%0
a%20%20%22%20%22%0a%20%20%22as%22%0a%20%20%22%20%22%0a%20%20string%20lexer%3dstr
%3ct%5fname%3e%28%29%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%7d%0a%0at%5fta
rget%7b%0a%20%20vector%3cTAutoPtr%3ci%5ftarget%5fitem%3e%3e%20arr%3b%0a%7d%0a%7d
%0a%2f%2f
*/