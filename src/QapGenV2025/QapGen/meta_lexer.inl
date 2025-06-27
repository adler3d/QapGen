// 5944.778000 ms
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
    ADD(t_var_expr)\
    ADD(t_block_expr)\
    ADD(t_call_expr)\
  ADDEND()
  class i_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_expr_visitor{
  public:
    typedef t_cppcore::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_expr_visitor{
  //  void Do(t_int_expr*p){}
  //  void Do(t_char_expr*p){}
  //  void Do(t_bool_expr*p){}
  //  void Do(t_string_expr*p){}
  //  void Do(t_real_expr*p){}
  //  void Do(t_var_expr*p){}
  //  void Do(t_block_expr*p){}
  //  void Do(t_call_expr*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
        F(t_var_expr);
        F(t_block_expr);
        F(t_call_expr);
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
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
  public:
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev10)
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
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
  public:
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
  public:
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev11)
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("^",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
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
  public:
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
  public:
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev12)
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("|",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
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
  public:
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
  public:
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev13)
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("&&",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
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
  public:
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
  public:
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev14)
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
        static const auto g_static_var_0=QapStrFinder::fromArr(split("||",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
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
  public:
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_val*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_val_visitor{
    //  void Do(t_zero*p){}
    //  void Do(t_num*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
  public:
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
    void Use(i_visitor&A){A.Do(this);}
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
    void Use(i_visitor&A){A.Do(this);}
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_val*p){
        if(!p)return nullptr;Is<TYPE,i_val_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_val*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_val_visitor{
    //  void Do(t_num*p){}
    //  void Do(t_zero*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
  struct t_var_expr:public i_expr{
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
      typedef t_var_expr::i_part i_part;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_var_expr::U U;//typedef t_var_expr::U U;
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
      static TYPE*UberCast(i_part*p){
        if(!p)return nullptr;Is<TYPE,i_part_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_part*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_part_visitor{
    //  void Do(t_dd_part*p){}
    //  void Do(t_template_part*p){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_part_visitor
    struct i_part{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_part)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_part
    public:
      typedef i_part_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sb_expr)OWNER(t_var_expr)
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
    public:
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
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_elem)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dd_part)PARENT(i_part)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_elem>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_dd_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_dd_part
    public:
      void Use(i_visitor&A){A.Do(this);}
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_part)PARENT(i_part)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sepB,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_dd_part>,ddp,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_template_part
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_template_part
    public:
      void Use(i_visitor&A){A.Do(this);}
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr)OWNER(t_var_expr)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_expr)
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
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_sb_expr      )\
    F(t_dd_part      )\
    F(t_template_part)\
    F(t_arr          )\
    F(t_item         )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(TAutoPtr<i_part>,tp,DEF,$,$)\
  ADDVAR(TAutoPtr<t_arr>,arr,DEF,$,$)\
  ADDVAR(vector<t_item>,items,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_expr
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
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
    void Use(i_visitor&A){A.Do(this);}
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
  struct t_call_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_cppcore)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var_expr,call,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_call_params,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_expr
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(call);
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_auto(params);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03      )\
  F(t_lev05      )\
  F(t_lev06      )\
  F(t_lev07      )\
  F(t_lev08      )\
  F(t_lev09      )\
  F(t_lev10      )\
  F(t_lev11      )\
  F(t_lev12      )\
  F(t_lev13      )\
  F(t_lev14      )\
  F(t_string     )\
  F(t_int_expr   )\
  F(t_type_expr  )\
  F(t_char_expr  )\
  F(t_bool_expr  )\
  F(t_string_expr)\
  F(t_real_expr  )\
  F(t_var_expr   )\
  F(t_block_expr )\
  F(t_call_param )\
  F(t_call_params)\
  F(t_call_expr  )\
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
public:
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
public:
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
  //===>>===i_expr_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_expra)\
    ADD(t_exprb)\
  ADDEND()
  class i_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_expr_visitor{
  public:
    typedef t_meta_lexer::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_expr_visitor{
  //  void Do(t_expra*p){}
  //  void Do(t_exprb*p){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_expr_visitor
  struct i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_expra);
        F(t_exprb);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
  //struct t_visitor:public i_code_visitor{
  //  void Do(t_name_code*p){}
  //  void Do(t_num_code*p){}
  //  void Do(t_str_code*p){}
  //  void Do(t_char_code*p){}
  //  void Do(t_sign_code*p){}
  //  void Do(t_soft_brackets_code*p){}
  //  void Do(t_hard_brackets_code*p){}
  //  void Do(t_curly_brackets_code*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code()const{QapDebugMsg("no way.");return "";};
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_code_with_sep*p){
      if(!p)return nullptr;Is<TYPE,i_code_with_sep_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_code_with_sep*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_code_with_sep_visitor{
  //  void Do(t_name_code_with_sep*p){}
  //  void Do(t_num_code_with_sep*p){}
  //  void Do(t_str_code_with_sep*p){}
  //  void Do(t_char_code_with_sep*p){}
  //  void Do(t_sign_code_with_sep*p){}
  //  void Do(t_soft_brackets_code_with_sep*p){}
  //  void Do(t_hard_brackets_code_with_sep*p){}
  //  void Do(t_curly_brackets_code_with_sep*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code()const{QapDebugMsg("no way.");return "";}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_type_item*p){
      if(!p)return nullptr;Is<TYPE,i_type_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_type_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_type_item_visitor{
  //  void Do(t_type_item_string*p){}
  //  void Do(t_type_item_char*p){}
  //  void Do(t_type_item_number*p){}
  //  void Do(t_type_item_type*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code()const{QapDebugMsg("no way.");return "";};
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_type_templ*p){
      if(!p)return nullptr;Is<TYPE,i_type_templ_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_type_templ*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_type_templ_visitor{
  //  void Do(t_type_templ_angle*p){}
  //  void Do(t_type_templ_soft*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code()const{QapDebugMsg("no way."); return "";};
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_struct_cmd_xxxx*p){
      if(!p)return nullptr;Is<TYPE,i_struct_cmd_xxxx_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_xxxx*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_cmd_xxxx_visitor{
  //  void Do(t_struct_cmd_mode*p){}
  //  void Do(t_struct_cmd_anno*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual char get_mode()const{QapDebugMsg("no way.");return 'D';}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_struct_field*p){
      if(!p)return nullptr;Is<TYPE,i_struct_field_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_field*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_field_visitor{
  //  void Do(t_const_field*p){}
  //  void Do(t_struct_field*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code(int id,t_ic_dev&icdev)const{QapNoWay();return {};}
      virtual string make_cmd(t_ic_dev&icdev)const{QapNoWay();return {};}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_struct_cmd_so*p){
      if(!p)return nullptr;Is<TYPE,i_struct_cmd_so_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_struct_cmd_so*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_struct_cmd_so_visitor{
  //  void Do(t_struct_cmd_suffix*p){}
  //  void Do(t_struct_cmd_optional*p){}
  //  void Do(t_struct_cmd_opt_v2*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual char get_mode()const{QapDebugMsg("no way.");return 'D';}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_cpp_code*p){
      if(!p)return nullptr;Is<TYPE,i_cpp_code_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_cpp_code*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_cpp_code_visitor{
  //  void Do(t_cpp_code_sep*p){}
  //  void Do(t_cpp_code_main*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
    virtual string make_code()const{QapDebugMsg("no way.");return "";}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
  //struct t_visitor:public i_def_visitor{
  //  void Do(t_class_def*p){}
  //  void Do(t_struct_def*p){}
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
    struct t_out{
        string name;
        string parent;
      };
      virtual t_out make_code(){QapDebugMsg("no way.");return *(t_out*)nullptr;}
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
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
    static TYPE*UberCast(i_target_item*p){
      if(!p)return nullptr;Is<TYPE,i_target_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_target_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_target_item_visitor{
  //  void Do(t_target_sep*p){}
  //  void Do(t_target_item*p){}
  //  void Do(t_target_decl*p){}
  //  void Do(t_target_using*p){}
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
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
  struct t_expra:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expra)PARENT(i_expr)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_expra
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expra
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("expra");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_exprb:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exprb)PARENT(i_expr)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_exprb
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_exprb
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("exprb");
      if(!ok)return ok;
      return ok;
    }
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_name::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{return value;}
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{return body.body;}
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
    string get_code()const{
        string out;
        for(int i=0;i<arr.size();i++){
          out+=arr[i]->get_code();
        }
        return out;
      }
      string get_value()const{
        string out;
        for(int i=0;i<arr.size();i++){
          out+=arr[i]->get_value();
        }
        return out;
      }
      string make_code()const{return "\""+get_code()+"\"";}
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string out=first.get_code();
        if(!arr.empty())
        {
          for(int i=0;i<arr.size();i++)out+=arr[i].body.get_code();
          int gg=1;
        }
        return "\""+out+"\"";
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
    void Use(i_visitor&A){A.Do(this);}
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
    string get_code()const{return body->get_code();}
      string get_value()const{return body->get_value();}
      string make_code()const{return "'"+get_code()+"'";}
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{return CToS(body.body);}
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
    void Use(i_visitor&A){A.Do(this);}
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
      string make_code()const{
        return body.make_code()+sep.make_code();
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
    void Use(i_visitor&A){A.Do(this);}
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
      string make_code()const{
        return body.make_code()+sep.make_code();
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
    void Use(i_visitor&A){A.Do(this);}
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
      string make_code()const{
        return body.make_code()+sep.make_code();
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
    void Use(i_visitor&A){A.Do(this);}
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
      string make_code()const{
        return body.make_code()+sep.make_code();
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
    void Use(i_visitor&A){A.Do(this);}
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
      string make_code()const{
        return body.make_code()+sep.make_code();
      }
  };
  struct t_soft_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_soft_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_soft_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      ok=dev.go_const(")");
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
      string make_code()const{
        string v[]={
          sep0.make_code(),
          vector_make_code(body),
          sep1.make_code(),
        };
        return "("+v[0]+v[1]+")"+v[2];
      }
  };
  struct t_hard_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hard_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hard_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      ok=dev.go_const("]");
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
      string make_code()const{
        string v[]={
          sep0.make_code(),
          vector_make_code(body),
          sep1.make_code(),
        };
        return "["+v[0]+v[1]+"]"+v[2];
      }
  };
  struct t_curly_brackets_code_with_sep:public i_code_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code_with_sep)PARENT(i_code_with_sep)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_curly_brackets_code_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_curly_brackets_code_with_sep
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_auto(body);
      ok=dev.go_const("}");
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
      string make_code()const{
        string v[]={
          sep0.make_code(),
          vector_make_code(body),
          sep1.make_code(),
        };
        return "{"+v[0]+v[1]+"}"+v[2];
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
@@@public:
  string make_code()const{return body.make_code()+sep.make_code();}
*/
//real_source_code:
/*
var mk=POST['data'].split("@@@")[1];
var gen=function(lex,mk){
  return lex+"_with_sep=>i_code_with_sep{"+lex+" body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}"+mk+"\n}";
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
    string make_code()const{return vector_make_code(arr);};
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string v[3]={
          sep0.make_code(),
          body?body->make_code():"",
          sep1.make_code()
        };
        return "("+v[0]+v[1]+v[2]+")";
      };
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string v[3]={
          sep0.make_code(),
          body?body->make_code():"",
          sep1.make_code()
        };
        return "["+v[0]+v[1]+v[2]+"]";
      };
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string v[3]={
          sep0.make_code(),
          body?body->make_code():"",
          sep1.make_code()
        };
        return "{"+v[0]+v[1]+v[2]+"}";
      };
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
    string make_code()const{
        return body;
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
    string make_code()const{
        string out=body;
        //for(int i=0;i<arr.size();i++)out+=arr[i].make_code();
        return out;
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
    string make_code()const{
        return "::";
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
        return body.get_code();
      };
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
        return body.get_code();
      };
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
        return body.body;
      };
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
    template<class TYPE>
      static string weak_body_make_code(const TAutoPtr<TYPE>&ref){
        return ref->make_code();
      }
      string make_code()const{
        string out;
        out+=scope.make_code();
        out+=weak_body_make_code(body);
        return out;
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
    void Use(i_visitor&A){A.Do(this);}
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
    template<class TYPE>
      static string weak_arr_make_code(const vector<TYPE>&arr){
        string out;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          out+=ex.make_code();
        }
        return out;
      }
      string make_code()const{
        string out;
        if(scope)out+=scope->make_code();
        out+=type.get();
        if(param){
          auto*p=param.get();
          auto*pParam=p->body.get();
          QapAssert(pParam);
          out+=pParam->make_code();
        }
        out+=weak_arr_make_code(this->arr);
        return out;
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
    string make_code()const{
        string out;
        if(scope)out+=scope->make_code();
        out+=body.make_code();
        return out;
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
    string make_code()const{
        return body->make_code();
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
    string make_code()const{
        string out;
        out+=",";
        out+=body.make_code();
        return out;
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
    string make_code()const{
        string out;
        out+=first.make_code();
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          out+=ex.make_code();
        }
        return out;
      };
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string out;
        out+="<";
        if(params){
          auto*p=params.get();
          out+=p->make_code();
        }
        out+=">";
        return out;
      };
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code()const{
        string out;
        out+="(";
        if(params){
          auto*p=params.get();
          out+=p->make_code();
        }
        out+=")";
        return out;
      };
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
    void Use(i_visitor&A){A.Do(this);}
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
    char get_mode()const{return body;}
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_sc_item*p){
        if(!p)return nullptr;Is<TYPE,i_sc_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_sc_item*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_sc_item_visitor{
    //  void Do(t_c_item*p){}
    //  void Do(t_s_item*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code(int id,t_ic_dev&icdev)const{
        const string*plexer=icdev.get_sep_lex(value);
        if(!plexer)return {};
        return "ADDVAR("+*plexer+",$sep"+IToS(id)+",DEF,$,$)\\\n";
      }
      string make_cmd(t_ic_dev&icdev)const{return "M+=go_const("+value+");";}
  };
  struct t_struct_field_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field_value)OWNER(t_meta_lexer)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cppcore::t_call_expr>,expr,DEF,$,$)\
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
  public:
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
    string make_code(int id,t_ic_dev&icdev)const{
        vector<string> out;
        string mode="DEF";//value?"SET":"DEF";
        //out.push_back(IToS(id));
        string type_mem;
        QapAssert(type&&save_obj(*type.get(),type_mem));
        auto t=type_mem;
        if(bool vec_algo=true){
          auto a=split(t,"<");
          if(a.size()==2&&a[0]=="vector"){
            auto b=split(a[1],">");
            QapAssert(b.size()==2);
            QapAssert(b[1]=="");
            if(icdev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>"+b[1];
          }
        }
        if(icdev.need_tautoptr(t))t="TAutoPtr<"+t+">";
        if(bool need_vec=qst&&qst->s.find('*')!=string::npos)t="vector<"+t+">";
        out.push_back(t);
        out.push_back(name.value);
        out.push_back(mode);
        string value_mem="$";
        //if(value)QapAssert(save_obj(*value.get(),value_mem));
        out.push_back(!value?"$":value_mem);
        string s;
        //if(attr){
        //  bool ok=save_obj(*attr.get(),s);
        //  QapAssert(ok);
        //}
        return "ADDVAR("+join(out,",")+","+(s.empty()?"$":s)+")\\\n";
      }
      string make_cmd(t_ic_dev&icdev)const{
        char m=qst?(qst->s.find('?')==string::npos?'M':'O'):'D';
        QapAssert(qst||mode?bool(qst)!=bool(mode):true);
        string out=CToS(!qst?(mode?mode->get_mode():'D'):m)+"+=";
        string call,params;
        if(value){
          auto*pce=value->expr.get();//t_cppcore::t_call_expr::UberCast(value->expr.get());
          QapAssert(pce);
          QapAssert(save_obj(pce->call,call));
          QapAssert(pce->params.arr.empty()||save_obj(pce->params.arr,params));
        }
        string go=value?call+"("+name.value+string(params.size()?","+params:"")+");":"auto("+name.value+");";
        return out+="go_"+go;
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
    string make_code(int id,t_ic_dev&icdev)const{
        return body->make_code(id,icdev);
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_cmd_param_expr*p){
        if(!p)return nullptr;Is<TYPE,i_cmd_param_expr_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_cmd_param_expr*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_cmd_param_expr_visitor{
    //  void Do(t_expr_call*p){}
    //  void Do(t_expr_str*p){}
    //  void Do(t_expr_var*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
    public:
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
    public:
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
      char get_mode()const{return mode.substr(0,2)=="@m"?'M':(mode[0]=='m'?'M':'D');}
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
    void Use(i_visitor&A){A.Do(this);}
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
    char get_mode()const override{return value=='?'?'O':(value=='!'?'M':'D');}
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
    void Use(i_visitor&A){A.Do(this);}
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
    char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
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
    void Use(i_visitor&A){A.Do(this);}
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
    char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
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
    static bool find(const string&func){
        static const vector<string> arr=split("go_any_str_from_vec|go_any_arr_char|go_any|go_any_char","|");
        for(int i=0;i<arr.size();i++)if(arr[i]==func)return true;
        return false;
      }
      string make_code(int i){
        if(mode&&t_struct_cmd_anno::UberCast(mode.get())){
          int gg=1;
        }
        char m=cmdso?cmdso->get_mode():'D';
        QapAssert(cmdso||mode?bool(cmdso)!=bool(mode):true);
        string out=CToS(mode?mode->get_mode():m);
        vector<string> params_code;
        {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
        auto check=out!="O"?"    if(!ok)return ok;\n":"";
        out=out!="O"?"ok=":"";
        string func_name=func.get();
        bool smart_func=find(func_name);
        if(smart_func)
        {
          QapAssert(params.arr.size()==2);
          const auto&param0=params.arr[0].body;
           const auto&param1=params.arr[1].body;
          auto get_param1=[&func_name,&param1]()->string{
            if(func_name=="go_any_str_from_vec")return "QapStrFinder::fromArr("+param1+")";
            return "CharMask::fromStr("+param1+")";
          };
          string varname="g_static_var_"+IToS(i);
          string vardecl="    static const auto "+varname+"="+get_param1()+";\n";
          out=vardecl+"    "+out+"dev."+func.get()+"("+param0+","+varname+");\n"+check;
          return out;
        }
        out="    "+out+"dev."+func.get()+templ_params+"("+join(params_code,",")+");\n"+check;
        return out;
      }
      string make_code_gp(){
        char m=cmdso?cmdso->get_mode():'D';
        QapAssert(cmdso||mode?bool(cmdso)!=bool(mode):true);
        string out=CToS(mode?mode->get_mode():m);
        vector<string> params_code;
        {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
        out="    "+out+"+=dev."+func.get()+templ_params+"("+join(params_code,",")+");\n    if(!ok)return ok;\n";
        return out;
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
    string make_code(int i){
        return body.make_code(i);
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(sep);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
        return sep.make_code();
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
        string out;
        auto*p=body.get();
        out=p->make_code();
        return out;
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_major*p){
        if(!p)return nullptr;Is<TYPE,i_major_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_major*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_major_visitor{
    //  void Do(t_fields*p){}
    //  void Do(t_cmds*p){}
    //  void Do(t_atr*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_bayan*p){
        if(!p)return nullptr;Is<TYPE,i_bayan_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_bayan*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_bayan_visitor{
    //  void Do(t_with_bayan*p){}
    //  void Do(t_without_bayan*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_strong_bayan*p){
        if(!p)return nullptr;Is<TYPE,i_strong_bayan_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_strong_bayan*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_strong_bayan_visitor{
    //  void Do(t_a*p){}
    //  void Do(t_b*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    static string align(const string&source){
        auto arr=split(source,"\n");
        if(arr.empty())return source;
        auto get=[](const string&line)->int{
          if(line=="public:")return -2;
          for(int i=0;i<line.size();i++)if(line[i]!=' ')return i;
          return -1;
        };
        int count=-1;
        for(int i=0;i<arr.size();i++){
          auto m=get(arr[i]);
          if(m<0)continue;
          if(count<0){count=m;continue;}
          count=std::min<int>(m,count);
        }
        if(count<0)return source;
        vector<string> out;
        for(int i=0;i<arr.size();i++){
          auto m=get(arr[i]);
          auto s=m<0?arr[i]:"  "+arr[i].substr(count);
          if(m==-1)s.clear();
          out.push_back(s);
        }
        return join(out,"\n");
      }
      //struct t_visitor:/*i_cpp_code::i_visitor,i_major::i_visitor,*/i_bayan::i_visitor{
      //  const t_cpp_code&c;
      //  t_visitor(const t_cpp_code&c):c(c){}
      //  void Do(t_cpp_code*p){}
      //  void Do(t_fields*p){}
      //  void Do(t_cmds*p){}
      //  void Do(t_eater*p){}
      //  void Do(t_with_bayan*p){}
      //  void Do(t_without_bayan*p){p->wb.bayan}
      //};
      string make_code()const{
        string out;
        //t_visitor v{*this};
        //bayan->Use(v);
        //for(int i=0;i<arr.size();i++){
        //  auto&ex=arr[i];
        //  QapAssert(ex);
        //  auto*p=ex.get();
        //  out+=p->make_code();
        //}
        if(bayan)save_obj(*bayan.get(),out);
        return out;
      }
  };
// test
  struct t_fields_cmds_cppcode{
  public:
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
  public:
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
    struct t_target_item_out;
      struct t_out{
        vector<i_target_item*> nested;
        string provars;
        string procmds;
        string cppcode;
      };
      struct t_target_item_out{
        string sep;
        string name;
        string parent;
        t_out out;
      };
      //template<int>
      //static t_target_item_out weak_make_code(const t_target_item&ref,t_ic_dev&icdev);
      struct t_visitor:t_fields_cmds_cppcode,t_cpp_code::i_strong_bayan::i_visitor,t_cpp_code::i_bayan::i_visitor{
        t_sep_struct_cmds*pcmds{};
        vector<t_sep_struct_field>*pfs{};
        string c;
        void Do(t_cpp_code::t_a*p){save_obj(p->wb.eater,c);}
        void Do(t_cpp_code::t_b*p){save_obj(p->e,c);}
        void Do(t_cpp_code::t_with_bayan*p){save_obj(p->eater,c);}
        void Do(t_cpp_code::t_without_bayan*p){save_obj(p->eater,c);}
        void Do(t_cpp_code::i_strong_bayan*p){p->Use(*this);}
        void Do(t_cpp_code::i_bayan*p){p->Use(*this);}
        virtual void Do(t_cmds*p){pcmds=p->cmds.get();if(p->cppcode)Do(p->cppcode.get());}
        virtual void Do(t_true_fcc*p){pfs=&p->arr;pcmds=p->cmds?p->cmds.get():nullptr;if(p->cppcode)Do(p->cppcode.get());}
        virtual void Do(t_cppcode*p){if(p->cppcode)Do(p->cppcode->bayan.get());}
        void Do(const t_fields_cmds_cppcode&fcc){
          if(fcc.tfcc)Do(fcc.tfcc.get());
          if(fcc.cmds)Do(fcc.cmds.get());
          if(fcc.c)Do(fcc.c.get());
        }
      };
      struct t_cmd_fs_getter:t_visitor{
        using t_visitor::Do;
        void Do(t_cppcode*p)override{}
      };
      t_out make_code(t_ic_dev&icdev)const{
        t_out out;
        {
          auto&arr=nested;
          out.nested.resize(arr.size());
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            auto&to=out.nested[i];
            to=ex.get();
          }
        }
        if(!fcc)return out;
        t_visitor v;
        v.Do(*fcc.get());
        if(v.pfs){
          auto&arr=*v.pfs;
          vector<string> tmp;
          for(int i=0;i<arr.size();i++){
            tmp.push_back(arr[i].make_code(i,icdev));
          }
          out.provars=join(tmp,"");
        }
        if(v.pcmds)
        {
          auto&arr=v.pcmds->body.arr;
          vector<string> tmp;
          for(int i=0;i<arr.size();i++){
            tmp.push_back(arr[i].make_code(i));
          }
          out.procmds=join(tmp,"");
        }
        string sep=sep0.value.empty()?sep1.value:sep0.value;
        out.cppcode=v.c.size()?sep+v.c+"\n":"";
        return out;
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
    void Use(i_visitor&A){A.Do(this);}
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
    t_out make_code(){
        t_out out;
        out.name=name.get();
        out.parent=parent.get();
        return out;
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
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      return ok;
    }
    t_out make_code(){
        t_out out;
        out.name=name.get();
        return out;
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
    void Use(i_visitor&A){A.Do(this);}
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
    void Use(i_visitor&A){A.Do(this);}
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
    typedef t_struct_body::t_target_item_out t_out;
      t_out make_code(t_ic_dev&icdev)const{
        t_out out;
        out.sep=sep0.value;
        {
          auto tmp=def->make_code();
          out.name=tmp.name;
          out.parent=tmp.parent;
        }
        auto tmp=body.make_code(icdev);
        out.out=std::move(tmp);
        return out;
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
    void Use(i_visitor&A){A.Do(this);}
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
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
      static TYPE*UberCast(i_qa*p){
        if(!p)return nullptr;Is<TYPE,i_qa_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_qa*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_qa_visitor{
    //  void Do(t_str_ap*p){}
    //  void Do(t_str_qu*p){}
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
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
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
      void Use(i_visitor&A){A.Do(this);}
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
      void Use(i_visitor&A){A.Do(this);}
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
  public:
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
    void Use(i_visitor&A){A.Do(this);}
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
  ADDVAR(TAutoPtr<i_expr>,unused,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_target_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_target
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_target
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(unused);
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
    vector<t_target_item::t_out> make_code(t_ic_dev&icdev){
        vector<t_target_item::t_out> out;
        for(int i=0;i<arr.size();i++){
          auto&ex=arr[i];
          if(auto*p=dynamic_cast<t_target_item*>(ex.get())){
            out.push_back(p->make_code(icdev));
          }
        }
        return out;
      }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_expra                       )\
  F(t_exprb                       )\
  F(i_code                        )\
  F(t_name_code                   )\
  F(t_num_code                    )\
  F(t_str_seq                     )\
  F(t_sep_str_seq                 )\
  F(t_str_code                    )\
  F(t_char_code                   )\
  F(t_sign_code                   )\
  F(i_code_with_sep               )\
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
  F(i_type_templ                  )\
  F(t_type_scope                  )\
  F(t_type_templ                  )\
  F(i_type_item                   )\
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
  F(i_struct_cmd_xxxx             )\
  F(t_struct_cmd_mode             )\
  F(t_sep_value                   )\
  F(t_attr                        )\
  F(i_struct_field                )\
  F(t_const_field                 )\
  F(t_struct_field_value          )\
  F(t_struct_field                )\
  F(t_sep_struct_field            )\
  F(t_templ_params                )\
  F(t_cmd_params                  )\
  F(t_cmd_param                   )\
  F(t_struct_cmd_anno             )\
  F(i_struct_cmd_so               )\
  F(t_struct_cmd_suffix           )\
  F(t_struct_cmd_optional         )\
  F(t_struct_cmd_opt_v2           )\
  F(t_struct_cmd                  )\
  F(t_sep_struct_cmd              )\
  F(t_struct_cmds                 )\
  F(t_sep_struct_cmds             )\
  F(i_cpp_code                    )\
  F(t_cpp_code_sep                )\
  F(t_cpp_code_main               )\
  F(t_cpp_code                    )\
  F(t_fields_cmds_cppcode         )\
  F(t_struct_body                 )\
  F(i_def                         )\
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
  F(t_var_expr);
  F(t_block_expr);
  F(t_call_expr);
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

bool t_cppcore::t_var_expr::i_part::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_dd_part);
  F(t_template_part);
  #undef F
  main();
  return scope.ok;
}

bool t_meta_lexer::i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_expra);
  F(t_exprb);
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
F(t_cppcore)F(t_test20250618_atrr)F(t_meta_lexer)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fcppcore%7b%0a%0at%5flev03%7b%0a%20%20string%20oper%3b%0a%20%20TAutoPtr%3ci%5
fexpr%3e%20expr%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fany%5fstr%5ffrom%5fvec%
28oper%2csplit%28%22%2b%2c%2d%2c%21%2c%7e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20
M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%7d%0a%7d%0at%5flev05%7b%0a%20%20t%5foper%
7b%0a%20%20%20%20string%20value%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fan
y%5fstr%5ffrom%5fvec%28value%2csplit%28%22%2a%2c%2f%2c%25%22%2c%22%2c%22%29%29%3
b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20ope
r%3b%0a%20%20%20%20t%5flev03%20expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%
5fauto%28oper%29%3b%0a%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d
%0a%20%20%7d%0a%20%20t%5flev03%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0
a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5
fauto%28arr%29%3b%0a%20%20%7d%0a%7d%0at%5flev06%7b%0a%20%20t%5foper%7b%0a%20%20%
20%20string%20value%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffr
om%5fvec%28value%2csplit%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7
d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%2
0t%5flev05%20expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3
b%0a%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20
%20t%5flev05%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%2
0%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%
0a%20%20%7d%0a%7d%0at%5flev07%7b%0a%20%20t%5foper%7b%0a%20%20%20%20string%20valu
e%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2
csplit%28%22%3c%3c%2c%3e%3e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7
d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20t%5flev06%2
0expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%2
0%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev06
%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%
3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%
0a%7d%0at%5flev08%7b%0a%20%20t%5foper%7b%0a%20%20%20%20string%20value%3b%0a%20%2
0%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22
%3c%2c%3c%3d%2c%3e%2c%3e%3d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7
d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20t%5flev07%2
0expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%2
0%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev07
%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%
3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%
0a%7d%0at%5flev09%7b%0a%20%20t%5foper%7b%0a%20%20%20%20string%20value%3b%0a%20%2
0%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22
%3d%3d%2c%21%3d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%
5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20t%5flev08%20expr%3b%0a%
20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20go
%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev08%20expr%3b%0
a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%
28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0a%7d%0at%5f
lev10%7b%0a%20%20t%5foper%7b%0a%20%20%20%20string%20value%3b%0a%20%20%20%20%7b%0
a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%26%22%2c%22
%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20
t%5foper%20oper%3b%0a%20%20%20%20t%5flev09%20expr%3b%0a%20%20%20%20%7b%0a%20%20%
20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%
20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev09%20expr%3b%0a%20%20vector%3ct%5fitem
%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20
%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0a%7d%0at%5flev11%7b%0a%20%20t%5fope
r%7b%0a%20%20%20%20string%20value%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5f
any%5fstr%5ffrom%5fvec%28value%2csplit%28%22%5e%22%2c%22%2c%22%29%29%3b%0a%20%20
%20%20%7d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20
%20%20%20t%5flev10%20expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28o
per%29%3b%0a%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%
7d%0a%20%20t%5flev10%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b
%0a%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28ar
r%29%3b%0a%20%20%7d%0a%7d%0at%5flev12%7b%0a%20%20t%5foper%7b%0a%20%20%20%20strin
g%20value%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%2
8value%2csplit%28%22%7c%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a
%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20t%5flev11%20exp
r%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20
%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev11%20e
xpr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo
%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0a%7
d%0at%5flev13%7b%0a%20%20t%5foper%7b%0a%20%20%20%20string%20value%3b%0a%20%20%20
%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%26%
26%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%
20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20t%5flev12%20expr%3b%0a%20%20%20%20%7
b%0a%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20go%5fauto%28exp
r%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev12%20expr%3b%0a%20%20vector
%3ct%5fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%
0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0a%7d%0at%5flev14%7b%0a%2
0%20t%5foper%7b%0a%20%20%20%20string%20value%3b%0a%20%20%20%20%7b%0a%20%20%20%20
%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%7c%7c%22%2c%22%2c%22%29%
29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20t%5foper%2
0oper%3b%0a%20%20%20%20t%5flev13%20expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%2
0go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%2
0%7d%0a%20%20%7d%0a%20%20t%5flev13%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%
3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20O%2b%3d
go%5fauto%28arr%29%3b%0a%20%20%7d%0a%7d%0at%5fstring%7b%0a%20%20%22%5c%22%22%0a%
20%20string%20value%3dstr%3cvector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%3e%28%29%3f
%3b%0a%20%20%22%5c%22%22%0a%7d%0a%0at%5fint%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fzer
o%3ai%5fval%7b%220%22%7d%0a%20%20t%5fnum%3ai%5fval%7b%0a%20%20%20%20char%20first
%3dany%5fchar%28gen%5fdips%28%2219%22%29%29%3b%0a%20%20%20%20string%20num%3dany%
28gen%5fdips%28%2209%22%29%29%3f%3b%0a%20%20%7d%0a%20%20string%20value%3dstr%3cT
AutoPtr%3ci%5fval%3e%3e%28%29%3b%0a%7d%0a%0at%5ftype%5fexpr%7b%0a%20%20t%5fparam
s%7b%0a%20%20%20%20%22%7b%22%0a%20%20%20%20string%20type%3dstr%3ct%5ftype%5fexpr
%3e%28%29%3b%0a%20%20%20%20%22%2c%22%0a%20%20%20%20t%5fint%5fexpr%20count%3b%0a%
20%20%20%20%22%7d%22%0a%20%20%7d%0a%20%20t%5felem%7b%0a%20%20%20%20t%5fname%20na
me%3b%0a%20%20%20%20TAutoPtr%3ct%5fparams%3e%20params%3f%3b%0a%20%20%7d%0a%20%20
t%5fitem%7b%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20%22%3a%3a%22%0a%20%
20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20t%5felem%20body%3b%0a%20%20%7d%0a%20%
20t%5felem%20first%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0a%0at%5fch
ar%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fchar%5fitem%20body%3b%0a%7d%0a%0at%5fbool%5f
expr%3ai%5fexpr%7b%0a%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22
true%2cfalse%22%2c%22%2c%22%29%29%3b%0a%7d%0a%0at%5fstring%5fexpr%3ai%5fexpr%7b%
0a%20%20t%5fstring%20body%3b%0a%7d%0a%0at%5freal%5fexpr%3ai%5fexpr%7b%0a%20%20t%
5ffrac%7b%0a%20%20%20%20%22%2e%22%0a%20%20%20%20string%20arr%3dany%28gen%5fdips%
28%2209%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fsign%7b%0a%20%20%20%20char%20sign%3d
any%5fchar%28%22%2d%2b%22%29%3b%0a%20%20%7d%0a%20%20t%5fexp%7b%0a%20%20%20%20cha
r%20e%3dany%5fchar%28%22eE%22%29%3b%0a%20%20%20%20TAutoPtr%3ct%5fsign%3e%20sign%
3f%3b%0a%20%20%20%20string%20arr%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20
%7d%0a%20%20t%5fnum%3ai%5fval%7b%0a%20%20%20%20char%20first%3dany%5fchar%28gen%5
fdips%28%2219%22%29%29%3b%0a%20%20%20%20string%20num%3dany%28gen%5fdips%28%2209%
22%29%29%3f%3b%0a%20%20%7d%0a%20%20t%5fzero%3ai%5fval%7b%220%22%7d%0a%20%20t%5fi
mpl%7b%0a%20%20%20%20TAutoPtr%3ci%5fval%3e%20val%3b%0a%20%20%20%20TAutoPtr%3ct%5
ffrac%3e%20frac%3b%0a%20%20%20%20TAutoPtr%3ct%5fexp%3e%20exp%3f%3b%0a%20%20%7d%0
a%20%20string%20value%3dstr%3ct%5fimpl%3e%28%29%3b%0a%7d%0a%0at%5fvar%5fexpr%3ai
%5fexpr%7b%0a%20%20t%5fsb%5fexpr%7b%0a%20%20%20%20%22%5b%22%0a%20%20%20%20t%5fse
p%20sep0%3f%3b%0a%20%20%20%20t%5flev14%20expr%3b%0a%20%20%20%20t%5fsep%20sep1%3f
%3b%0a%20%20%20%20%22%5d%22%0a%20%20%7d%0a%20%20t%5fdd%5fpart%3ai%5fpart%7b%0a%2
0%20%20%20t%5felem%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20%20
%20%22%3a%3a%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20%20%20t%5
fname%20name%3b%0a%20%20%20%20%7d%0a%20%20%20%20vector%3ct%5felem%3e%20arr%3b%0a
%20%20%7d%0a%20%20t%5ftemplate%5fpart%3ai%5fpart%7b%0a%20%20%20%20t%5fsep%20sepB
%3f%3b%0a%20%20%20%20%22%3c%22%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20
TAutoPtr%3ci%5fexpr%3e%20expr%3b%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%
20%22%3e%22%0a%20%20%20%20TAutoPtr%3ct%5fdd%5fpart%3e%20ddp%3f%3b%0a%20%20%7d%0a
%20%20t%5farr%7b%0a%20%20%20%20t%5fsep%20sep%3f%3b%0a%20%20%20%20vector%3ct%5fsb
%5fexpr%3e%20arr%3b%0a%20%20%7d%0a%20%20t%5fitem%7b%0a%20%20%20%20%22%2e%22%0a%2
0%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20t%
5farr%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fname%20name%3b%0a%20%20TAutoPtr%3ci%5f
part%3e%20tp%3f%3b%0a%20%20TAutoPtr%3ct%5farr%3e%20arr%3f%3b%0a%20%20vector%3ct%
5fitem%3e%20items%3f%3b%0a%7d%0a%0at%5fblock%5fexpr%3ai%5fexpr%7b%0a%20%20%22%28
%22%0a%20%20t%5flev14%20body%3b%0a%20%20%22%29%22%0a%7d%0a%0at%5fcall%5fparam%7b
%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20t%5flev14%20body%3b%0a%20%20t%5fsep%20sep1
%3f%3b%0a%7d%0a%0at%5fcall%5fparams%7b%0a%20%20%22%28%22%0a%20%20t%5fsep%20sep%3
f%3b%0a%20%20vector%3ct%5fcall%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20
%20%22%29%22%0a%7d%0a%0at%5fcall%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fvar%5fexpr%20c
all%3b%0a%20%20t%5fsep%20sep%3f%3b%0a%20%20t%5fcall%5fparams%20params%3b%0a%7d%0
a%0a%7d%0a%0ausing%20%22%20%22%20as%20t%5fsep%3b%0a%0at%5ftest20250618%5fatrr%7b
%0a%20%20t%5ffoo%7b%7b%7d%5b%3a%3a%5d%7d%0a%20%20t%5ffoo%20foo%3b%20%5bskip%5d%0
a%20%20t%5fsep%20sep%3b%20%5boptimize%2c%22sep%22%2c%28%22sep%22%29%2csep%5bx%5d
%5d%0a%20%20%7b%0a%20%20%20%20go%5fauto%28foo%29%3b%0a%20%20%20%20go%5fauto%28se
p%29%3b%0a%20%20%7d%0a%7d%0a%0a%2f%2ft%5ftest20250620%5fdev%7b%0a%2f%2f%20%20t%5
ffoo%7b%7b%7d%7d%0a%2f%2f%20%20t%5fbar%7b%0a%2f%2f%20%20%20%20%22more%20tests%22
%0a%2f%2f%20%20%20%20%22test%22%0a%2f%2f%20%20%20%20t%5fsep%20sep%3b%0a%2f%2f%20
%20%20%20%22another%20test%22%20%2f%2a%20yes%20%60%20%22%3b%22%20%2a%2f%20%3b%0a
%2f%2f%20%20%20%20t%5ffoo%20foo%3f%3b%0a%2f%2f%20%20%20%20%22nope%22%3b%0a%2f%2f
%20%20%7d%0a%2f%2f%20%20string%20dev%3dany%28%22%3b%3f%27%2d%3e%3d%3c%60%28%29%2
f%5c%5c%2b%22%29%3f%3b%0a%2f%2f%20%20t%5ffoo%20%24dev0%3b%0a%2f%2f%20%20t%5fbar%
20%24dev1%3b%0a%2f%2f%20%20%2f%2a%7b%0a%2f%2f%20%20%20%20go%5fany%28dev%2c%22%3b
%3f%27%2d%3e%3d%3c%60%28%29%2f%5c%5c%2b%22%29%3b%0a%2f%2f%20%20%20%20go%5fauto%2
8%24dev0%29%3b%0a%2f%2f%20%20%20%20go%5fauto%28%24dev1%29%3b%0a%2f%2f%20%20%7d%2
a%2f%0a%2f%2f%7d%0at%5fmeta%5flexer%7b%0a%20%20t%5fexpra%3ai%5fexpr%7b%22expra%2
2%7d%0a%20%20t%5fexprb%3ai%5fexpr%7b%22exprb%22%7d%0a%0ai%5fcode%20%7b%0a%20%20v
irtual%20string%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3b
return%20%22%22%3b%7d%3b%0a%7d%0a%0at%5fname%5fcode%3ai%5fcode%7b%0a%20%20string
%20value%3dstr%3ct%5fname%3a%3at%5fimpl%3e%28%29%3b%0a%20%20string%20make%5fcode
%28%29const%7breturn%20value%3b%7d%0a%7d%0a%0at%5fnum%5fcode%3ai%5fcode%7b%0a%20
%20t%5fnumber%20body%3b%0a%20%20string%20make%5fcode%28%29const%7breturn%20body%
2ebody%3b%7d%0a%7d%0a%0at%5fstr%5fseq%7b%0a%20%20%22%5c%22%22%0a%20%20vector%3cT
AutoPtr%3ci%5fstr%5fitem%3e%3e%20arr%3f%3b%0a%20%20%22%5c%22%22%0a%20%20string%2
0get%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20for%28int%
20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20out%2b%3darr%
5bi%5d%2d%3eget%5fcode%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20out%3b%
0a%20%20%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20string%20ou
t%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%2
0%20%20%20%20%20out%2b%3darr%5bi%5d%2d%3eget%5fvalue%28%29%3b%0a%20%20%20%20%7d%
0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29cons
t%7breturn%20%22%5c%22%22%2bget%5fcode%28%29%2b%22%5c%22%22%3b%7d%0a%7d%0a%0at%5
fsep%5fstr%5fseq%7b%0a%20%20%22%20%22%0a%20%20t%5fstr%5fseq%20body%3b%0a%7d%0a%0
at%5fstr%5fcode%3ai%5fcode%7b%0a%20%20t%5fstr%5fseq%20first%3b%0a%20%20vector%3c
t%5fsep%5fstr%5fseq%3e%20arr%3f%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a
%20%20%20%20string%20out%3dfirst%2eget%5fcode%28%29%3b%0a%20%20%20%20if%28%21arr
%2eempty%28%29%29%0a%20%20%20%20%7b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3c
arr%2esize%28%29%3bi%2b%2b%29out%2b%3darr%5bi%5d%2ebody%2eget%5fcode%28%29%3b%0a
%20%20%20%20%20%20int%20gg%3d1%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20%22%5
c%22%22%2bout%2b%22%5c%22%22%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%5fcode%3ai%5fcod
e%7b%0a%20%20%22%27%22%0a%20%20TAutoPtr%3ci%5fchar%5fitem%3e%20body%3b%0a%20%20%
22%27%22%0a%20%20string%20get%5fcode%28%29const%7breturn%20body%2d%3eget%5fcode%
28%29%3b%7d%0a%20%20string%20get%5fvalue%28%29const%7breturn%20body%2d%3eget%5fv
alue%28%29%3b%7d%0a%20%20string%20make%5fcode%28%29const%7breturn%20%22%27%22%2b
get%5fcode%28%29%2b%22%27%22%3b%7d%0a%7d%0a%0at%5fsign%5fcode%3ai%5fcode%7b%0a%2
0%20t%5fsign%20body%3b%0a%20%20string%20make%5fcode%28%29const%7breturn%20CToS%2
8body%2ebody%29%3b%7d%0a%7d%0a%0ai%5fcode%5fwith%5fsep%7b%0a%20%20virtual%20stri
ng%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%22%
22%3b%7d%0a%7d%0a%0at%5fname%5fcode%5fwith%5fsep%3ai%5fcode%5fwith%5fsep%7b%0a%2
0%20t%5fname%5fcode%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%2
0M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%
20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20body%2em
ake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fnum%5fc
ode%5fwith%5fsep%3ai%5fcode%5fwith%5fsep%7b%0a%20%20t%5fnum%5fcode%20body%3b%0a%
20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a
%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcod
e%28%29const%7b%0a%20%20%20%20return%20body%2emake%5fcode%28%29%2bsep%2emake%5fc
ode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fstr%5fcode%5fwith%5fsep%3ai%5fcode%5fwit
h%5fsep%7b%0a%20%20t%5fstr%5fcode%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b
%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28se
p%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20ret
urn%20body%2emake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a
%0at%5fchar%5fcode%5fwith%5fsep%3ai%5fcode%5fwith%5fsep%7b%0a%20%20t%5fchar%5fco
de%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto
%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20str
ing%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20body%2emake%5fcode%28%29%
2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fsign%5fcode%5fwith%5fsep
%3ai%5fcode%5fwith%5fsep%7b%0a%20%20t%5fsign%5fcode%20body%3b%0a%20%20t%5fsep%20
sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2
b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b
%0a%20%20%20%20return%20body%2emake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b%0a
%20%20%7d%0a%7d%0a%0at%5fsoft%5fbrackets%5fcode%5fwith%5fsep%3ai%5fcode%5fwith%5
fsep%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5f
sep%3e%3e%20body%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dg
o%5fconst%28%22%28%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20
%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%
29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20m
ake%5fcode%28%29const%7b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%
20sep0%2emake%5fcode%28%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29
%2c%0a%20%20%20%20%20%20sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%2
0%20%20return%20%22%28%22%2bv%5b0%5d%2bv%5b1%5d%2b%22%29%22%2bv%5b2%5d%3b%0a%20%
20%7d%0a%7d%0a%0at%5fhard%5fbrackets%5fcode%5fwith%5fsep%3ai%5fcode%5fwith%5fsep
%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%
3e%3e%20body%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5f
const%28%22%5b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%
20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5d%22%29%3
b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20make%
5fcode%28%29const%7b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%20se
p0%2emake%5fcode%28%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29%2c%
0a%20%20%20%20%20%20sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%20%20
%20return%20%22%5b%22%2bv%5b0%5d%2bv%5b1%5d%2b%22%5d%22%2bv%5b2%5d%3b%0a%20%20%7
d%0a%7d%0a%0at%5fcurly%5fbrackets%5fcode%5fwith%5fsep%3ai%5fcode%5fwith%5fsep%7b
%0a%20%20t%5fsep%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%
3e%20body%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fcon
st%28%22%7b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20O
%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0
a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20make%5fc
ode%28%29const%7b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%20sep0%
2emake%5fcode%28%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29%2c%0a%
20%20%20%20%20%20sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%20%20%20
return%20%22%7b%22%2bv%5b0%5d%2bv%5b1%5d%2b%22%7d%22%2bv%5b2%5d%3b%0a%20%20%7d%0
a%7d%0a%0a%2f%2freal%5fsource%5fdata%3a%0a%2f%2a%0at%5fname%5fcode%0at%5fnum%5fc
ode%0at%5fstr%5fcode%0at%5fchar%5fcode%0at%5fsign%5fcode%0at%5fsoft%5fbrackets%5
fcode%0at%5fhard%5fbrackets%5fcode%0at%5fcurly%5fbrackets%5fcode%0a%40%40%40publ
ic%3a%0a%20%20string%20make%5fcode%28%29const%7breturn%20body%2emake%5fcode%28%2
9%2bsep%2emake%5fcode%28%29%3b%7d%0a%2a%2f%0a%0a%2f%2freal%5fsource%5fcode%3a%0a
%2f%2a%0avar%20mk%3dPOST%5b%27data%27%5d%2esplit%28%22%40%40%40%22%29%5b1%5d%3b%
0avar%20gen%3dfunction%28lex%2cmk%29%7b%0a%20%20return%20lex%2b%22%5fwith%5fsep%
3d%3ei%5fcode%5fwith%5fsep%7b%22%2blex%2b%22%20body%3bt%5fsep%20sep%3b%7bM%2b%3d
go%5fauto%28body%29%3bO%2b%3dgo%5fauto%28sep%29%3b%7d%22%2bmk%2b%22%5cn%7d%22%3b
%0a%7d%0avar%20out%3d%5b%5d%3b%0avar%20arr%3dPOST%5b%27data%27%5d%2esplit%28%22%
5cn%40%40%40%22%29%5b0%5d%2esplit%28%22%5cr%22%29%2ejoin%28%22%22%29%2esplit%28%
22%5cn%22%29%3b%0afor%28var%20i%3d0%3bi%3carr%2elength%3bi%2b%2b%29%7b%0a%20%20o
ut%2epush%28gen%28arr%5bi%5d%2cmk%29%29%3b%0a%7d%0areturn%20out%2ejoin%28%22%5cn
%22%29%3b%0a%2a%2f%0at%5fcode%7b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%3e%3e%20ar
r%3b%0a%20%20string%20make%5fcode%28%29const%7breturn%20vector%5fmake%5fcode%28a
rr%29%3b%7d%3b%0a%7d%0a%0at%5fsoft%5fbrackets%5fcode%3ai%5fcode%7b%0a%20%20%22%2
8%22%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3f%3b%0a
%20%20t%5fsep%20sep1%3f%3b%0a%20%20%22%29%22%0a%20%20string%20make%5fcode%28%29c
onst%7b%0a%20%20%20%20string%20v%5b3%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5f
code%28%29%2c%0a%20%20%20%20%20%20body%3fbody%2d%3emake%5fcode%28%29%3a%22%22%2c
%0a%20%20%20%20%20%20sep1%2emake%5fcode%28%29%0a%20%20%20%20%7d%3b%0a%20%20%20%2
0return%20%22%28%22%2bv%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2b%22%29%22%3b%0a%20%20%7d%
3b%0a%7d%0a%0at%5fhard%5fbrackets%5fcode%3ai%5fcode%7b%0a%20%20%22%5b%22%0a%20%2
0t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3f%3b%0a%20%20t%5fse
p%20sep1%3f%3b%0a%20%20%22%5d%22%0a%20%20string%20make%5fcode%28%29const%7b%0a%2
0%20%20%20string%20v%5b3%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%28%29%2
c%0a%20%20%20%20%20%20body%3fbody%2d%3emake%5fcode%28%29%3a%22%22%2c%0a%20%20%20
%20%20%20sep1%2emake%5fcode%28%29%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%2
2%5b%22%2bv%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2b%22%5d%22%3b%0a%20%20%7d%3b%0a%7d%0a%
0at%5fcurly%5fbrackets%5fcode%3ai%5fcode%7b%0a%20%20%22%7b%22%0a%20%20t%5fsep%20
sep0%3f%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3f%3b%0a%20%20t%5fsep%20sep1%3f
%3b%0a%20%20%22%7d%22%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20s
tring%20v%5b3%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%28%29%2c%0a%20%20%
20%20%20%20body%3fbody%2d%3emake%5fcode%28%29%3a%22%22%2c%0a%20%20%20%20%20%20se
p1%2emake%5fcode%28%29%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%22%7b%22%2bv
%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2b%22%7d%22%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5fsemic
olon%7b%0a%20%20%22%3b%22%0a%7d%0a%0at%5fvalue%5fitem%7b%0a%20%20string%20body%3
dstr%3cTAutoPtr%3ct%5fcppcore%3a%3ai%5fexpr%3e%3e%28%29%3b%0a%20%20string%20make
%5fcode%28%29const%7b%0a%20%20%20%20return%20body%3b%0a%20%20%7d%0a%7d%0a%0at%5f
value%7b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%0a%20%20string%20body%3dstr%3cTA
utoPtr%3ct%5fcppcore%3a%3ai%5fexpr%3e%3e%28%29%3b%0a%20%20string%20make%5fcode%2
8%29const%7b%0a%20%20%20%20string%20out%3dbody%3b%0a%20%20%20%20%2f%2ffor%28int%
20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29out%2b%3darr%5bi%5d%2emake%5fcode%28%
29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0ai%5ftype%5ftempl%7b%0
a%20%20virtual%20string%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%
22%29%3b%20return%20%22%22%3b%7d%3b%0a%7d%0a%0at%5ftype%5fscope%7b%0a%20%20%22%3
a%3a%22%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20%22%3a
%3a%22%3b%0a%20%20%7d%0a%7d%0a%0at%5ftype%5ftempl%7b%0a%20%20TAutoPtr%3ci%5ftype
%5ftempl%3e%20body%3b%0a%7d%0a%0ai%5ftype%5fitem%7b%0a%20%20virtual%20string%20m
ake%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%22%22%3b%
7d%3b%0a%7d%0a%0at%5ftype%5fitem%5fstring%3ai%5ftype%5fitem%7b%0a%20%20t%5fstr%5
fitem%20body%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%
20body%2eget%5fcode%28%29%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5ftype%5fitem%5fchar%3a
i%5ftype%5fitem%7b%0a%20%20t%5fchar%5fitem%20body%3b%0a%20%20string%20make%5fcod
e%28%29const%7b%0a%20%20%20%20return%20body%2eget%5fcode%28%29%3b%0a%20%20%7d%3b
%0a%7d%0a%0at%5ftype%5fitem%5fnumber%3ai%5ftype%5fitem%7b%0a%20%20t%5fnumber%20b
ody%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20body%2e
body%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5ftype%5fitem%5ftype%3b%0a%0at%5fscope%5ftyp
e%5fitem%7b%0a%20%20t%5ftype%5fscope%20scope%3b%0a%20%20TAutoPtr%3ct%5ftype%5fit
em%5ftype%3e%20body%3b%0a%20%20template%3cclass%20TYPE%3e%0a%20%20static%20strin
g%20weak%5fbody%5fmake%5fcode%28const%20TAutoPtr%3cTYPE%3e%26ref%29%7b%0a%20%20%
20%20return%20ref%2d%3emake%5fcode%28%29%3b%0a%20%20%7d%0a%20%20string%20make%5f
code%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3dscope%2e
make%5fcode%28%29%3b%0a%20%20%20%20out%2b%3dweak%5fbody%5fmake%5fcode%28body%29%
3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5ftype%5fitem%5ftype%3
ai%5ftype%5fitem%20%7b%0a%20%20TAutoPtr%3ct%5ftype%5fscope%3e%20scope%3f%3b%0a%2
0%20t%5fname%20type%3b%0a%20%20TAutoPtr%3ct%5ftype%5ftempl%3e%20param%3f%3b%0a%2
0%20vector%3ct%5fscope%5ftype%5fitem%3e%20arr%3f%3b%0a%0a%20%20template%3cclass%
20TYPE%3e%0a%20%20static%20string%20weak%5farr%5fmake%5fcode%28const%20vector%3c
TYPE%3e%26arr%29%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20for%28int%20i%3d
0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20auto%26ex%3darr%5bi
%5d%3b%0a%20%20%20%20%20%20out%2b%3dex%2emake%5fcode%28%29%3b%0a%20%20%20%20%7d%
0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29cons
t%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20if%28scope%29out%2b%3dscope%2d%
3emake%5fcode%28%29%3b%0a%20%20%20%20out%2b%3dtype%2eget%28%29%3b%0a%20%20%20%20
if%28param%29%7b%0a%20%20%20%20%20%20auto%2ap%3dparam%2eget%28%29%3b%0a%20%20%20
%20%20%20auto%2apParam%3dp%2d%3ebody%2eget%28%29%3b%0a%20%20%20%20%20%20QapAsser
t%28pParam%29%3b%0a%20%20%20%20%20%20out%2b%3dpParam%2d%3emake%5fcode%28%29%3b%0
a%20%20%20%20%7d%0a%20%20%20%20out%2b%3dweak%5farr%5fmake%5fcode%28this%2d%3earr
%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5ftype%5fexpr2%7b%
0a%20%20TAutoPtr%3ct%5ftype%5fscope%3e%20scope%3f%3b%0a%20%20t%5ftype%5fitem%5ft
ype%20body%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20
out%3b%0a%20%20%20%20if%28scope%29out%2b%3dscope%2d%3emake%5fcode%28%29%3b%0a%20
%20%20%20out%2b%3dbody%2emake%5fcode%28%29%3b%0a%20%20%20%20return%20out%3b%0a%2
0%20%7d%0a%7d%0a%0at%5ftype%5ftempl%5fparam%7b%0a%20%20TAutoPtr%3ci%5ftype%5fite
m%3e%20body%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%2
0body%2d%3emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%5ftype%5ftempl%5f
param%7b%0a%20%20%22%2c%22%0a%20%20t%5ftype%5ftempl%5fparam%20body%3b%0a%20%20st
ring%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out
%2b%3d%22%2c%22%3b%0a%20%20%20%20out%2b%3dbody%2emake%5fcode%28%29%3b%0a%20%20%2
0%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5ftype%5ftempl%5fparams%7b%0a%20%20
t%5ftype%5ftempl%5fparam%20first%3b%0a%20%20vector%3ct%5fsep%5ftype%5ftempl%5fpa
ram%3e%20arr%3f%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20stri
ng%20out%3b%0a%20%20%20%20out%2b%3dfirst%2emake%5fcode%28%29%3b%0a%20%20%20%20fo
r%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20auto%
26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20out%2b%3dex%2emake%5fcode%28%29%3b%0a%2
0%20%20%20%7d%0a%20%20%20%20return%20out%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5ftype%5
ftempl%5fangle%3ai%5ftype%5ftempl%7b%0a%20%20%22%3c%22%0a%20%20TAutoPtr%3ct%5fty
pe%5ftempl%5fparams%3e%20params%3f%3b%0a%20%20%22%3e%22%0a%20%20string%20make%5f
code%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3d%22%3c%2
2%3b%0a%20%20%20%20if%28params%29%7b%0a%20%20%20%20%20%20auto%2ap%3dparams%2eget
%28%29%3b%0a%20%20%20%20%20%20out%2b%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%2
0%7d%0a%20%20%20%20out%2b%3d%22%3e%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%
7d%3b%0a%7d%0a%0at%5ftype%5ftempl%5fsoft%3ai%5ftype%5ftempl%7b%0a%20%20%22%28%22
%0a%20%20TAutoPtr%3ct%5ftype%5ftempl%5fparams%3e%20params%3f%3b%0a%20%20%22%29%2
2%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20
%20%20%20out%2b%3d%22%28%22%3b%0a%20%20%20%20if%28params%29%7b%0a%20%20%20%20%20
%20auto%2ap%3dparams%2eget%28%29%3b%0a%20%20%20%20%20%20out%2b%3dp%2d%3emake%5fc
ode%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20out%2b%3d%22%29%22%3b%0a%20%20%20%2
0return%20out%3b%0a%20%20%7d%3b%0a%7d%0a%0ai%5fstruct%5fcmd%5fxxxx%7b%0a%20%20vi
rtual%20char%20get%5fmode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3bretu
rn%20%27D%27%3b%7d%0a%7d%0a%0at%5fstruct%5fcmd%5fmode%3ai%5fstruct%5fcmd%5fxxxx%
7b%0a%20%20char%20body%3dany%5fchar%28%22DMO%22%29%3b%0a%20%20%22%20%22%3f%0a%20
%20%22%2b%3d%22%0a%20%20%22%20%22%3f%0a%20%20char%20get%5fmode%28%29const%7bretu
rn%20body%3b%7d%0a%7d%0a%0at%5fsep%5fvalue%7b%0a%20%20%22%20%22%3f%0a%20%20t%5fv
alue%5fitem%20value%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fattr%7b%0a%20%20%22%5
b%22%0a%20%20vector%3ct%5fsep%5fvalue%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%
20%22%20%22%3f%0a%20%20%22%5d%22%0a%7d%0ai%5fstruct%5ffield%7b%0a%20%20virtual%2
0string%20make%5fcode%28int%20id%2ct%5fic%5fdev%26icdev%29const%7bQapNoWay%28%29
%3breturn%20%7b%7d%3b%7d%0a%20%20virtual%20string%20make%5fcmd%28t%5fic%5fdev%26
icdev%29const%7bQapNoWay%28%29%3breturn%20%7b%7d%3b%7d%0a%7d%0at%5fconst%5ffield
%3ai%5fstruct%5ffield%7b%0a%20%20t%5fqst%7b%22%3f%22%7d%0a%20%20t%5fc%5fitem%3ai
%5fsc%5fitem%7bt%5fchar%5fitem%20body%3b%7d%0a%20%20t%5fs%5fitem%3ai%5fsc%5fitem
%7bt%5fstr%5fitem%20body%3b%7d%0a%20%20string%20value%3dstr%3cTAutoPtr%3ci%5fsc%
5fitem%3e%3e%28%29%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fqst%3e%20qst%3
f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fsemicolon%3e%20sc%3f%3b%0a%20%2
0string%20make%5fcode%28int%20id%2ct%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%2
0const%20string%2aplexer%3dicdev%2eget%5fsep%5flex%28value%29%3b%0a%20%20%20%20i
f%28%21plexer%29return%20%7b%7d%3b%0a%20%20%20%20return%20%22ADDVAR%28%22%2b%2ap
lexer%2b%22%2c%24sep%22%2bIToS%28id%29%2b%22%2cDEF%2c%24%2c%24%29%5c%5c%5cn%22%3
b%0a%20%20%7d%0a%20%20string%20make%5fcmd%28t%5fic%5fdev%26icdev%29const%7bretur
n%20%22M%2b%3dgo%5fconst%28%22%2bvalue%2b%22%29%3b%22%3b%7d%0a%7d%0a%0at%5fstruc
t%5ffield%5fvalue%20%7b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%3b%0a%20%20%22%20
%22%3f%0a%20%20TAutoPtr%3ct%5fcppcore%3a%3at%5fcall%5fexpr%3e%20expr%3b%0a%7d%0a
t%5fstruct%5ffield%3ai%5fstruct%5ffield%7b%0a%20%20t%5fqst%7bstring%20s%3b%7bgo%
5fany%28s%2c%22%2a%3f%22%29%3b%7d%7d%0a%20%20TAutoPtr%3ci%5fstruct%5fcmd%5fxxxx%
3e%20mode%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fcppcore%3a%3ai%5fexp
r%3e%20type%3b%0a%20%20%22%20%22%0a%20%20t%5fname%20name%3b%0a%20%20TAutoPtr%3ct
%5fstruct%5ffield%5fvalue%3e%20value%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr
%3ct%5fqst%3e%20qst%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%20%20%22%20%
22%3f%0a%20%20TAutoPtr%3ct%5fattr%3e%20attr%3f%3b%0a%20%20string%20make%5fcode%2
8int%20id%2ct%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20vector%3cstring%3e%20o
ut%3b%0a%20%20%20%20string%20mode%3d%22DEF%22%3b%2f%2fvalue%3f%22SET%22%3a%22DEF
%22%3b%0a%20%20%20%20%2f%2fout%2epush%5fback%28IToS%28id%29%29%3b%0a%20%20%20%20
string%20type%5fmem%3b%0a%20%20%20%20QapAssert%28type%26%26save%5fobj%28%2atype%
2eget%28%29%2ctype%5fmem%29%29%3b%0a%20%20%20%20auto%20t%3dtype%5fmem%3b%0a%20%2
0%20%20if%28bool%20vec%5falgo%3dtrue%29%7b%0a%20%20%20%20%20%20auto%20a%3dsplit%
28t%2c%22%3c%22%29%3b%0a%20%20%20%20%20%20if%28a%2esize%28%29%3d%3d2%26%26a%5b0%
5d%3d%3d%22vector%22%29%7b%0a%20%20%20%20%20%20%20%20auto%20b%3dsplit%28a%5b1%5d
%2c%22%3e%22%29%3b%0a%20%20%20%20%20%20%20%20QapAssert%28b%2esize%28%29%3d%3d2%2
9%3b%0a%20%20%20%20%20%20%20%20QapAssert%28b%5b1%5d%3d%3d%22%22%29%3b%0a%20%20%2
0%20%20%20%20%20if%28icdev%2eneed%5ftautoptr%28b%5b0%5d%29%29t%3d%22vector%3cTAu
toPtr%3c%22%2bb%5b0%5d%2b%22%3e%3e%22%2bb%5b1%5d%3b%0a%20%20%20%20%20%20%7d%0a%2
0%20%20%20%7d%0a%20%20%20%20if%28icdev%2eneed%5ftautoptr%28t%29%29t%3d%22TAutoPt
r%3c%22%2bt%2b%22%3e%22%3b%0a%20%20%20%20if%28bool%20need%5fvec%3dqst%26%26qst%2
d%3es%2efind%28%27%2a%27%29%21%3dstring%3a%3anpos%29t%3d%22vector%3c%22%2bt%2b%2
2%3e%22%3b%0a%20%20%20%20out%2epush%5fback%28t%29%3b%0a%20%20%20%20out%2epush%5f
back%28name%2evalue%29%3b%0a%20%20%20%20out%2epush%5fback%28mode%29%3b%0a%20%20%
20%20string%20value%5fmem%3d%22%24%22%3b%0a%20%20%20%20%2f%2fif%28value%29QapAss
ert%28save%5fobj%28%2avalue%2eget%28%29%2cvalue%5fmem%29%29%3b%0a%20%20%20%20out
%2epush%5fback%28%21value%3f%22%24%22%3avalue%5fmem%29%3b%0a%20%20%20%20string%2
0s%3b%0a%20%20%20%20%2f%2fif%28attr%29%7b%0a%20%20%20%20%2f%2f%20%20bool%20ok%3d
save%5fobj%28%2aattr%2eget%28%29%2cs%29%3b%0a%20%20%20%20%2f%2f%20%20QapAssert%2
8ok%29%3b%0a%20%20%20%20%2f%2f%7d%0a%20%20%20%20return%20%22ADDVAR%28%22%2bjoin%
28out%2c%22%2c%22%29%2b%22%2c%22%2b%28s%2eempty%28%29%3f%22%24%22%3as%29%2b%22%2
9%5c%5c%5cn%22%3b%0a%20%20%7d%0a%20%20string%20make%5fcmd%28t%5fic%5fdev%26icdev
%29const%7b%0a%20%20%20%20char%20m%3dqst%3f%28qst%2d%3es%2efind%28%27%3f%27%29%3
d%3dstring%3a%3anpos%3f%27M%27%3a%27O%27%29%3a%27D%27%3b%0a%20%20%20%20QapAssert
%28qst%7c%7cmode%3fbool%28qst%29%21%3dbool%28mode%29%3atrue%29%3b%0a%20%20%20%20
string%20out%3dCToS%28%21qst%3f%28mode%3fmode%2d%3eget%5fmode%28%29%3a%27D%27%29
%3am%29%2b%22%2b%3d%22%3b%0a%20%20%20%20string%20call%2cparams%3b%0a%20%20%20%20
if%28value%29%7b%0a%20%20%20%20%20%20auto%2apce%3dvalue%2d%3eexpr%2eget%28%29%3b
%2f%2ft%5fcppcore%3a%3at%5fcall%5fexpr%3a%3aUberCast%28value%2d%3eexpr%2eget%28%
29%29%3b%0a%20%20%20%20%20%20QapAssert%28pce%29%3b%0a%20%20%20%20%20%20QapAssert
%28save%5fobj%28pce%2d%3ecall%2ccall%29%29%3b%0a%20%20%20%20%20%20QapAssert%28pc
e%2d%3eparams%2earr%2eempty%28%29%7c%7csave%5fobj%28pce%2d%3eparams%2earr%2cpara
ms%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20go%3dvalue%3fcall%2b%22%28%
22%2bname%2evalue%2bstring%28params%2esize%28%29%3f%22%2c%22%2bparams%3a%22%22%2
9%2b%22%29%3b%22%3a%22auto%28%22%2bname%2evalue%2b%22%29%3b%22%3b%0a%20%20%20%20
return%20out%2b%3d%22go%5f%22%2bgo%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%5fstruct%5f
field%7b%0a%20%20%22%20%22%3f%0a%20%20i%5fstruct%5ffield%20body%3b%0a%20%20strin
g%20make%5fcode%28int%20id%2ct%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20retur
n%20body%2d%3emake%5fcode%28id%2cicdev%29%3b%0a%20%20%7d%0a%7d%0a%0at%5ftempl%5f
params%7b%0a%20%20%22%3c%22%0a%20%20string%20body%3dstr%3cTAutoPtr%3ct%5ftype%5f
templ%5fparams%3e%3e%28%29%3b%0a%20%20%22%3e%22%0a%7d%0a%0at%5fcmd%5fparam%3b%0a
t%5fcmd%5fparams%7b%0a%20%20vector%3ct%5fcmd%5fparam%3e%20arr%3dvec%28%22%2c%22%
29%3b%0a%7d%0a%0at%5fcmd%5fparam%7b%0a%20%20t%5fimpl%7b%0a%20%20%20%20vector%3cT
AutoPtr%3ci%5fcmd%5fparam%5fexpr%3e%3e%20arr%3dvec%28%22%2b%22%29%3b%0a%20%20%7d
%0a%20%20t%5fexpr%5fcall%3ai%5fcmd%5fparam%5fexpr%7b%0a%20%20%20%20t%5fname%20fu
nc%3b%0a%20%20%20%20%22%28%22%0a%20%20%20%20TAutoPtr%3ct%5fcmd%5fparams%3e%20par
ams%3b%0a%20%20%20%20%22%29%22%0a%20%20%7d%0a%20%20t%5fexpr%5fstr%3ai%5fcmd%5fpa
ram%5fexpr%7b%0a%20%20%20%20string%20body%3dstr%3ct%5fstr%5fseq%3e%28%29%3b%0a%2
0%20%7d%0a%20%20t%5fexpr%5fvar%3ai%5fcmd%5fparam%5fexpr%7b%0a%20%20%20%20t%5fthi
s%7b%22this%2d%3e%22%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%20%20%20TAutoPtr%3
ct%5fthis%3e%20self%3f%3b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%
7d%0a%20%20%20%20string%20body%3dstr%3ct%5fimpl%3e%28%29%3b%0a%20%20%7d%0a%20%20
string%20body%3dstr%3ct%5fimpl%3e%28%29%3b%0a%7d%0at%5fstruct%5fcmd%5fanno%3ai%5
fstruct%5fcmd%5fxxxx%7b%0a%20%20string%20mode%3dany%5fstr%5ffrom%5fvec%28split%2
8%22%40mandatory%2c%40optional%2c%40mand%2c%40opti%2c%40man%2c%40opt%2c%40ma%2c%
40op%2c%40m%2c%40o%2cm%2co%22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22%3b%0a%20%20
char%20get%5fmode%28%29const%7breturn%20mode%2esubstr%280%2c2%29%3d%3d%22%40m%22
%3f%27M%27%3a%28mode%5b0%5d%3d%3d%27m%27%3f%27M%27%3a%27D%27%29%3b%7d%0a%7d%0a%0
ai%5fstruct%5fcmd%5fso%7b%0a%20%20virtual%20char%20get%5fmode%28%29const%7bQapDe
bugMsg%28%22no%20way%2e%22%29%3breturn%20%27D%27%3b%7d%0a%7d%0a%0at%5fstruct%5fc
md%5fsuffix%3ai%5fstruct%5fcmd%5fso%7b%0a%20%20char%20value%3dany%5fchar%28%22%3
f%21%22%29%3b%0a%20%20char%20get%5fmode%28%29const%20override%7breturn%20value%3
d%3d%27%3f%27%3f%27O%27%3a%28value%3d%3d%27%21%27%3f%27M%27%3a%27D%27%29%3b%7d%0
a%7d%0a%0at%5fstruct%5fcmd%5foptional%3ai%5fstruct%5fcmd%5fso%7b%0a%20%20%22%5b%
22%0a%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22optional%2cmanda
tory%22%2c%22%2c%22%29%29%3b%0a%20%20%22%5d%22%0a%20%20char%20get%5fmode%28%29co
nst%20override%7breturn%20value%3d%3d%22optional%22%3f%27O%27%3a%28%22mandatory%
22%3d%3dvalue%3f%27M%27%3a%27D%27%29%3b%7d%0a%7d%0a%0at%5fstruct%5fcmd%5fopt%5fv
2%3ai%5fstruct%5fcmd%5fso%7b%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%20%20stri
ng%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22optional%2cmandatory%22%2c%22%2
c%22%29%29%3b%0a%20%20char%20get%5fmode%28%29const%20override%7breturn%20value%3
d%3d%22optional%22%3f%27O%27%3a%28%22mandatory%22%3d%3dvalue%3f%27M%27%3a%27D%27
%29%3b%7d%0a%7d%0a%0at%5fstruct%5fcmd%7b%0a%20%20TAutoPtr%3ci%5fstruct%5fcmd%5fx
xxx%3e%20mode%3f%3b%0a%20%20t%5fname%20func%3b%0a%20%20%22%20%22%3f%0a%20%20stri
ng%20templ%5fparams%3dstr%3cTAutoPtr%3ct%5ftempl%5fparams%3e%3e%28%29%3f%3b%0a%2
0%20%22%28%22%0a%20%20t%5fcmd%5fparams%20params%3b%0a%20%20%22%29%22%0a%20%20%22
%20%22%3f%0a%20%20TAutoPtr%3ci%5fstruct%5fcmd%5fso%3e%20cmdso%3f%3b%0a%20%20%22%
20%22%3f%0a%20%20%22%3b%22%0a%20%20static%20bool%20find%28const%20string%26func%
29%7b%0a%20%20%20%20static%20const%20vector%3cstring%3e%20arr%3dsplit%28%22go%5f
any%5fstr%5ffrom%5fvec%7cgo%5fany%5farr%5fchar%7cgo%5fany%7cgo%5fany%5fchar%22%2
c%22%7c%22%29%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2
b%29if%28arr%5bi%5d%3d%3dfunc%29return%20true%3b%0a%20%20%20%20return%20false%3b
%0a%20%20%7d%0a%20%20string%20make%5fcode%28int%20i%29%7b%0a%20%20%20%20if%28mod
e%26%26t%5fstruct%5fcmd%5fanno%3a%3aUberCast%28mode%2eget%28%29%29%29%7b%0a%20%2
0%20%20%20%20int%20gg%3d1%3b%0a%20%20%20%20%7d%0a%20%20%20%20char%20m%3dcmdso%3f
cmdso%2d%3eget%5fmode%28%29%3a%27D%27%3b%0a%20%20%20%20QapAssert%28cmdso%7c%7cmo
de%3fbool%28cmdso%29%21%3dbool%28mode%29%3atrue%29%3b%0a%20%20%20%20string%20out
%3dCToS%28mode%3fmode%2d%3eget%5fmode%28%29%3am%29%3b%0a%20%20%20%20vector%3cstr
ing%3e%20params%5fcode%3b%0a%20%20%20%20%7bauto%26arr%3dparams%2earr%3bfor%28int
%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29params%5fcode%2epush%5fback%28arr%5b
i%5d%2ebody%29%3b%7d%0a%20%20%20%20auto%20check%3dout%21%3d%22O%22%3f%22%20%20%2
0%20if%28%21ok%29return%20ok%3b%5cn%22%3a%22%22%3b%0a%20%20%20%20out%3dout%21%3d
%22O%22%3f%22ok%3d%22%3a%22%22%3b%0a%20%20%20%20string%20func%5fname%3dfunc%2ege
t%28%29%3b%0a%20%20%20%20bool%20smart%5ffunc%3dfind%28func%5fname%29%3b%0a%20%20
%20%20if%28smart%5ffunc%29%0a%20%20%20%20%7b%0a%20%20%20%20%20%20QapAssert%28par
ams%2earr%2esize%28%29%3d%3d2%29%3b%0a%20%20%20%20%20%20const%20auto%26param0%3d
params%2earr%5b0%5d%2ebody%3b%0a%20%20%20%20%20%20%20const%20auto%26param1%3dpar
ams%2earr%5b1%5d%2ebody%3b%0a%20%20%20%20%20%20auto%20get%5fparam1%3d%5b%26func%
5fname%2c%26param1%5d%28%29%2d%3estring%7b%0a%20%20%20%20%20%20%20%20if%28func%5
fname%3d%3d%22go%5fany%5fstr%5ffrom%5fvec%22%29return%20%22QapStrFinder%3a%3afro
mArr%28%22%2bparam1%2b%22%29%22%3b%0a%20%20%20%20%20%20%20%20return%20%22CharMas
k%3a%3afromStr%28%22%2bparam1%2b%22%29%22%3b%0a%20%20%20%20%20%20%7d%3b%0a%20%20
%20%20%20%20string%20varname%3d%22g%5fstatic%5fvar%5f%22%2bIToS%28i%29%3b%0a%20%
20%20%20%20%20string%20vardecl%3d%22%20%20%20%20static%20const%20auto%20%22%2bva
rname%2b%22%3d%22%2bget%5fparam1%28%29%2b%22%3b%5cn%22%3b%0a%20%20%20%20%20%20ou
t%3dvardecl%2b%22%20%20%20%20%22%2bout%2b%22dev%2e%22%2bfunc%2eget%28%29%2b%22%2
8%22%2bparam0%2b%22%2c%22%2bvarname%2b%22%29%3b%5cn%22%2bcheck%3b%0a%20%20%20%20
%20%20return%20out%3b%0a%20%20%20%20%7d%0a%20%20%20%20out%3d%22%20%20%20%20%22%2
bout%2b%22dev%2e%22%2bfunc%2eget%28%29%2btempl%5fparams%2b%22%28%22%2bjoin%28par
ams%5fcode%2c%22%2c%22%29%2b%22%29%3b%5cn%22%2bcheck%3b%0a%20%20%20%20return%20o
ut%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%5fgp%28%29%7b%0a%20%20%20%20char%
20m%3dcmdso%3fcmdso%2d%3eget%5fmode%28%29%3a%27D%27%3b%0a%20%20%20%20QapAssert%2
8cmdso%7c%7cmode%3fbool%28cmdso%29%21%3dbool%28mode%29%3atrue%29%3b%0a%20%20%20%
20string%20out%3dCToS%28mode%3fmode%2d%3eget%5fmode%28%29%3am%29%3b%0a%20%20%20%
20vector%3cstring%3e%20params%5fcode%3b%0a%20%20%20%20%7bauto%26arr%3dparams%2ea
rr%3bfor%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29params%5fcode%2epush%5
fback%28arr%5bi%5d%2ebody%29%3b%7d%0a%20%20%20%20out%3d%22%20%20%20%20%22%2bout%
2b%22%2b%3ddev%2e%22%2bfunc%2eget%28%29%2btempl%5fparams%2b%22%28%22%2bjoin%28pa
rams%5fcode%2c%22%2c%22%29%2b%22%29%3b%5cn%20%20%20%20if%28%21ok%29return%20ok%3
b%5cn%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%5fstruc
t%5fcmd%7b%0a%20%20%22%20%22%3f%0a%20%20t%5fstruct%5fcmd%20body%3b%0a%20%20strin
g%20make%5fcode%28int%20i%29%7b%0a%20%20%20%20return%20body%2emake%5fcode%28i%29
%3b%0a%20%20%7d%0a%7d%0a%0at%5fstruct%5fcmds%7b%0a%20%20%22%7b%22%0a%20%20vector
%3ct%5fsep%5fstruct%5fcmd%3e%20arr%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%7d%22%
0a%7d%0a%0at%5fsep%5fstruct%5fcmds%7b%0a%20%20%22%20%22%3f%0a%20%20t%5fstruct%5f
cmds%20body%3b%0a%7d%0a%0ai%5fcpp%5fcode%7b%0a%20%20virtual%20string%20make%5fco
de%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%22%22%3b%7d%0a%7d
%0a%0at%5fcpp%5fcode%5fsep%3ai%5fcpp%5fcode%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20
string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20sep%2emake%5fcode%28%2
9%3b%0a%20%20%7d%0a%7d%0a%0at%5fcpp%5fcode%5fmain%3ai%5fcpp%5fcode%7b%0a%20%20TA
utoPtr%3ci%5fcode%5fwith%5fsep%3e%20body%3b%0a%20%20string%20make%5fcode%28%29co
nst%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20auto%2ap%3dbody%2eget%28%29%3
b%0a%20%20%20%20out%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20return%20out%3b%
0a%20%20%7d%0a%7d%0a%0at%5fcpp%5fcode%7b%0a%20%20t%5fbayan%7b%22%5b%3a%3a%5d%22%
7d%0a%20%20t%5ffields%3ai%5fmajor%7bt%5fsep%5fstruct%5ffield%20f%3b%7d%0a%20%20t
%5fcmds%3ai%5fmajor%7bt%5fsep%5fstruct%5fcmds%20c%3b%7d%0a%20%20t%5fatr%3ai%5fma
jor%7bTAutoPtr%3ct%5fattr%3e%20attr%3b%7d%0a%20%20t%5feater%7bvector%3cTAutoPtr%
3ci%5fcpp%5fcode%3e%3e%20arr%3b%7d%0a%20%20t%5fwith%5fbayan%3ai%5fbayan%7b%0a%20
%20%20%20t%5fbayan%20bayan%3b%0a%20%20%20%20t%5feater%20eater%3f%3b%0a%20%20%7d%
0a%20%20t%5fwithout%5fbayan%3ai%5fbayan%7b%0a%20%20%20%20t%5feater%20eater%3dmin
or%3cTAutoPtr%3ci%5fmajor%3e%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5fa%3ai%5fstrong%
5fbayan%7b%0a%20%20%20%20t%5fwith%5fbayan%20wb%3b%0a%20%20%7d%0a%20%20t%5fb%3ai%
5fstrong%5fbayan%7b%0a%20%20%20%20t%5feater%20e%3dminor%3ct%5fwith%5fbayan%3e%28
%29%3b%0a%20%20%7d%0a%20%20TAutoPtr%3ci%5fbayan%3e%20bayan%3b%0a%20%20static%20s
tring%20align%28const%20string%26source%29%7b%0a%20%20%20%20auto%20arr%3dsplit%2
8source%2c%22%5cn%22%29%3b%0a%20%20%20%20if%28arr%2eempty%28%29%29return%20sourc
e%3b%0a%20%20%20%20auto%20get%3d%5b%5d%28const%20string%26line%29%2d%3eint%7b%0a
%20%20%20%20%20%20if%28line%3d%3d%22public%3a%22%29return%20%2d2%3b%0a%20%20%20%
20%20%20for%28int%20i%3d0%3bi%3cline%2esize%28%29%3bi%2b%2b%29if%28line%5bi%5d%2
1%3d%27%20%27%29return%20i%3b%0a%20%20%20%20%20%20return%20%2d1%3b%0a%20%20%20%2
0%7d%3b%0a%20%20%20%20int%20count%3d%2d1%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%
3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20auto%20m%3dget%28arr%5bi%
5d%29%3b%0a%20%20%20%20%20%20if%28m%3c0%29continue%3b%0a%20%20%20%20%20%20if%28c
ount%3c0%29%7bcount%3dm%3bcontinue%3b%7d%0a%20%20%20%20%20%20count%3dstd%3a%3ami
n%3cint%3e%28m%2ccount%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20if%28count%3c0%29re
turn%20source%3b%0a%20%20%20%20vector%3cstring%3e%20out%3b%0a%20%20%20%20for%28i
nt%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20auto%20m%3
dget%28arr%5bi%5d%29%3b%0a%20%20%20%20%20%20auto%20s%3dm%3c0%3farr%5bi%5d%3a%22%
20%20%22%2barr%5bi%5d%2esubstr%28count%29%3b%0a%20%20%20%20%20%20if%28m%3d%3d%2d
1%29s%2eclear%28%29%3b%0a%20%20%20%20%20%20out%2epush%5fback%28s%29%3b%0a%20%20%
20%20%7d%0a%20%20%20%20return%20join%28out%2c%22%5cn%22%29%3b%0a%20%20%7d%0a%20%
20%2f%2fstruct%20t%5fvisitor%3a%2f%2ai%5fcpp%5fcode%3a%3ai%5fvisitor%2ci%5fmajor
%3a%3ai%5fvisitor%2c%2a%2fi%5fbayan%3a%3ai%5fvisitor%7b%0a%20%20%2f%2f%20%20cons
t%20t%5fcpp%5fcode%26c%3b%0a%20%20%2f%2f%20%20t%5fvisitor%28const%20t%5fcpp%5fco
de%26c%29%3ac%28c%29%7b%7d%0a%20%20%2f%2f%20%20void%20Do%28t%5fcpp%5fcode%2ap%29
%7b%7d%0a%20%20%2f%2f%20%20void%20Do%28t%5ffields%2ap%29%7b%7d%0a%20%20%2f%2f%20
%20void%20Do%28t%5fcmds%2ap%29%7b%7d%0a%20%20%2f%2f%20%20void%20Do%28t%5feater%2
ap%29%7b%7d%0a%20%20%2f%2f%20%20void%20Do%28t%5fwith%5fbayan%2ap%29%7b%7d%0a%20%
20%2f%2f%20%20void%20Do%28t%5fwithout%5fbayan%2ap%29%7bp%2d%3ewb%2ebayan%7d%0a%2
0%20%2f%2f%7d%3b%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20string
%20out%3b%0a%20%20%20%20%2f%2ft%5fvisitor%20v%7b%2athis%7d%3b%0a%20%20%20%20%2f%
2fbayan%2d%3eUse%28v%29%3b%0a%20%20%20%20%2f%2ffor%28int%20i%3d0%3bi%3carr%2esiz
e%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%2f%2f%20%20auto%26ex%3darr%5bi%5d%3b%0a%2
0%20%20%20%2f%2f%20%20QapAssert%28ex%29%3b%0a%20%20%20%20%2f%2f%20%20auto%2ap%3d
ex%2eget%28%29%3b%0a%20%20%20%20%2f%2f%20%20out%2b%3dp%2d%3emake%5fcode%28%29%3b
%0a%20%20%20%20%2f%2f%7d%0a%20%20%20%20if%28bayan%29save%5fobj%28%2abayan%2eget%
28%29%2cout%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%2f%2f%20tes
t%0a%0at%5ffields%5fcmds%5fcppcode%7b%0a%20%20t%5ftrue%5ffcc%7b%0a%20%20%20%20ve
ctor%3ct%5fsep%5fstruct%5ffield%3e%20arr%3b%0a%20%20%20%20TAutoPtr%3ct%5fsep%5fs
truct%5fcmds%3e%20cmds%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fcpp%5fcode%3a%3ai%5fst
rong%5fbayan%3e%20cppcode%3f%3b%0a%20%20%7d%0a%20%20t%5fcmds%7b%0a%20%20%20%20TA
utoPtr%3ct%5fsep%5fstruct%5fcmds%3e%20cmds%3b%0a%20%20%20%20TAutoPtr%3ct%5fcpp%5
fcode%3a%3ai%5fstrong%5fbayan%3e%20cppcode%3f%3b%0a%20%20%7d%0a%20%20t%5fcppcode
%7b%0a%20%20%20%20TAutoPtr%3ct%5fcpp%5fcode%3e%20cppcode%3b%0a%20%20%7d%0a%20%20
TAutoPtr%3ct%5ftrue%5ffcc%3e%20tfcc%3f%3b%0a%20%20TAutoPtr%3ct%5fcmds%3e%20cmds%
3f%3b%0a%20%20TAutoPtr%3ct%5fcppcode%3e%20c%3f%3b%0a%7d%0a%0at%5fstruct%5fbody%7
b%0a%20%20%22%7b%22%0a%20%20vector%3cTAutoPtr%3ci%5ftarget%5fitem%3e%3e%20nested
%3f%3b%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ct%5ffields%5fcmds%5fcppco
de%3e%20fcc%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a%20%20%22%7d%22%0a%20%20struct%20t
%5ftarget%5fitem%5fout%3b%0a%20%20struct%20t%5fout%7b%0a%20%20%20%20vector%3ci%5
ftarget%5fitem%2a%3e%20nested%3b%0a%20%20%20%20string%20provars%3b%0a%20%20%20%2
0string%20procmds%3b%0a%20%20%20%20string%20cppcode%3b%0a%20%20%7d%3b%0a%20%20st
ruct%20t%5ftarget%5fitem%5fout%7b%0a%20%20%20%20string%20sep%3b%0a%20%20%20%20st
ring%20name%3b%0a%20%20%20%20string%20parent%3b%0a%20%20%20%20t%5fout%20out%3b%0
a%20%20%7d%3b%0a%20%20%2f%2ftemplate%3cint%3e%0a%20%20%2f%2fstatic%20t%5ftarget%
5fitem%5fout%20weak%5fmake%5fcode%28const%20t%5ftarget%5fitem%26ref%2ct%5fic%5fd
ev%26icdev%29%3b%0a%20%20struct%20t%5fvisitor%3at%5ffields%5fcmds%5fcppcode%2ct%
5fcpp%5fcode%3a%3ai%5fstrong%5fbayan%3a%3ai%5fvisitor%2ct%5fcpp%5fcode%3a%3ai%5f
bayan%3a%3ai%5fvisitor%7b%0a%20%20%20%20t%5fsep%5fstruct%5fcmds%2apcmds%7b%7d%3b
%0a%20%20%20%20vector%3ct%5fsep%5fstruct%5ffield%3e%2apfs%7b%7d%3b%0a%20%20%20%2
0string%20c%3b%0a%20%20%20%20void%20Do%28t%5fcpp%5fcode%3a%3at%5fa%2ap%29%7bsave
%5fobj%28p%2d%3ewb%2eeater%2cc%29%3b%7d%0a%20%20%20%20void%20Do%28t%5fcpp%5fcode
%3a%3at%5fb%2ap%29%7bsave%5fobj%28p%2d%3ee%2cc%29%3b%7d%0a%20%20%20%20void%20Do%
28t%5fcpp%5fcode%3a%3at%5fwith%5fbayan%2ap%29%7bsave%5fobj%28p%2d%3eeater%2cc%29
%3b%7d%0a%20%20%20%20void%20Do%28t%5fcpp%5fcode%3a%3at%5fwithout%5fbayan%2ap%29%
7bsave%5fobj%28p%2d%3eeater%2cc%29%3b%7d%0a%20%20%20%20void%20Do%28t%5fcpp%5fcod
e%3a%3ai%5fstrong%5fbayan%2ap%29%7bp%2d%3eUse%28%2athis%29%3b%7d%0a%20%20%20%20v
oid%20Do%28t%5fcpp%5fcode%3a%3ai%5fbayan%2ap%29%7bp%2d%3eUse%28%2athis%29%3b%7d%
0a%20%20%20%20virtual%20void%20Do%28t%5fcmds%2ap%29%7bpcmds%3dp%2d%3ecmds%2eget%
28%29%3bif%28p%2d%3ecppcode%29Do%28p%2d%3ecppcode%2eget%28%29%29%3b%7d%0a%20%20%
20%20virtual%20void%20Do%28t%5ftrue%5ffcc%2ap%29%7bpfs%3d%26p%2d%3earr%3bpcmds%3
dp%2d%3ecmds%3fp%2d%3ecmds%2eget%28%29%3anullptr%3bif%28p%2d%3ecppcode%29Do%28p%
2d%3ecppcode%2eget%28%29%29%3b%7d%0a%20%20%20%20virtual%20void%20Do%28t%5fcppcod
e%2ap%29%7bif%28p%2d%3ecppcode%29Do%28p%2d%3ecppcode%2d%3ebayan%2eget%28%29%29%3
b%7d%0a%20%20%20%20void%20Do%28const%20t%5ffields%5fcmds%5fcppcode%26fcc%29%7b%0
a%20%20%20%20%20%20if%28fcc%2etfcc%29Do%28fcc%2etfcc%2eget%28%29%29%3b%0a%20%20%
20%20%20%20if%28fcc%2ecmds%29Do%28fcc%2ecmds%2eget%28%29%29%3b%0a%20%20%20%20%20
%20if%28fcc%2ec%29Do%28fcc%2ec%2eget%28%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%3
b%0a%20%20struct%20t%5fcmd%5ffs%5fgetter%3at%5fvisitor%7b%0a%20%20%20%20using%20
t%5fvisitor%3a%3aDo%3b%0a%20%20%20%20void%20Do%28t%5fcppcode%2ap%29override%7b%7
d%0a%20%20%7d%3b%0a%20%20t%5fout%20make%5fcode%28t%5fic%5fdev%26icdev%29const%7b
%0a%20%20%20%20t%5fout%20out%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20auto%26arr
%3dnested%3b%0a%20%20%20%20%20%20out%2enested%2eresize%28arr%2esize%28%29%29%3b%
0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%
20%20%20%20%20%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20%20%20auto%
26to%3dout%2enested%5bi%5d%3b%0a%20%20%20%20%20%20%20%20to%3dex%2eget%28%29%3b%0
a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20if%28%21fcc%29return%20ou
t%3b%0a%20%20%20%20t%5fvisitor%20v%3b%0a%20%20%20%20v%2eDo%28%2afcc%2eget%28%29%
29%3b%0a%20%20%20%20if%28v%2epfs%29%7b%0a%20%20%20%20%20%20auto%26arr%3d%2av%2ep
fs%3b%0a%20%20%20%20%20%20vector%3cstring%3e%20tmp%3b%0a%20%20%20%20%20%20for%28
int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20%20%20tmp
%2epush%5fback%28arr%5bi%5d%2emake%5fcode%28i%2cicdev%29%29%3b%0a%20%20%20%20%20
%20%7d%0a%20%20%20%20%20%20out%2eprovars%3djoin%28tmp%2c%22%22%29%3b%0a%20%20%20
%20%7d%0a%20%20%20%20if%28v%2epcmds%29%0a%20%20%20%20%7b%0a%20%20%20%20%20%20aut
o%26arr%3dv%2epcmds%2d%3ebody%2earr%3b%0a%20%20%20%20%20%20vector%3cstring%3e%20
tmp%3b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29
%7b%0a%20%20%20%20%20%20%20%20tmp%2epush%5fback%28arr%5bi%5d%2emake%5fcode%28i%2
9%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20out%2eprocmds%3djoin%28tmp%2
c%22%22%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20sep%3dsep0%2evalue%2eempt
y%28%29%3fsep1%2evalue%3asep0%2evalue%3b%0a%20%20%20%20out%2ecppcode%3dv%2ec%2es
ize%28%29%3fsep%2bv%2ec%2b%22%5cn%22%3a%22%22%3b%0a%20%20%20%20return%20out%3b%0
a%20%20%7d%0a%7d%0ai%5fdef%7b%0a%20%20struct%20t%5fout%7b%0a%20%20%20%20string%2
0name%3b%0a%20%20%20%20string%20parent%3b%0a%20%20%7d%3b%0a%20%20virtual%20t%5fo
ut%20make%5fcode%28%29%7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%2a%28t%5
fout%2a%29nullptr%3b%7d%0a%7d%0a%0at%5fclass%5fdef%3ai%5fdef%7b%0a%20%20t%5fname
%20name%3b%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20string%20arrow%5for%5fcolon%3dan
y%5fstr%5ffrom%5fvec%28split%28%22%3d%3e%2c%3a%22%2c%22%2c%22%29%29%3b%0a%20%20t
%5fsep%20sep1%3f%3b%0a%20%20t%5fname%20parent%3b%0a%20%20t%5fout%20make%5fcode%2
8%29%7b%0a%20%20%20%20t%5fout%20out%3b%0a%20%20%20%20out%2ename%3dname%2eget%28%
29%3b%0a%20%20%20%20out%2eparent%3dparent%2eget%28%29%3b%0a%20%20%20%20return%20
out%3b%0a%20%20%7d%0a%7d%0a%0at%5fstruct%5fdef%3ai%5fdef%7b%0a%20%20t%5fname%20n
ame%3b%0a%20%20t%5fout%20make%5fcode%28%29%7b%0a%20%20%20%20t%5fout%20out%3b%0a%
20%20%20%20out%2ename%3dname%2eget%28%29%3b%0a%20%20%20%20return%20out%3b%0a%20%
20%7d%0a%7d%0at%5ftarget%5fsep%3ai%5ftarget%5fitem%7b%22%20%22%7d%0at%5ftarget%5
fitem%3ai%5ftarget%5fitem%7b%0a%20%20t%5fsep%20sep0%3f%3b%0a%20%20TAutoPtr%3ci%5
fdef%3e%20def%3b%0a%20%20t%5fsep%20sep1%3f%3b%0a%20%20t%5fstruct%5fbody%20body%3
b%0a%20%20typedef%20t%5fstruct%5fbody%3a%3at%5ftarget%5fitem%5fout%20t%5fout%3b%
0a%20%20t%5fout%20make%5fcode%28t%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20t%
5fout%20out%3b%0a%20%20%20%20out%2esep%3dsep0%2evalue%3b%0a%20%20%20%20%7b%0a%20
%20%20%20%20%20auto%20tmp%3ddef%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%20%20ou
t%2ename%3dtmp%2ename%3b%0a%20%20%20%20%20%20out%2eparent%3dtmp%2eparent%3b%0a%2
0%20%20%20%7d%0a%20%20%20%20auto%20tmp%3dbody%2emake%5fcode%28icdev%29%3b%0a%20%
20%20%20out%2eout%3dstd%3a%3amove%28tmp%29%3b%0a%20%20%20%20return%20out%3b%0a%2
0%20%7d%0a%7d%0a%0at%5ftarget%5fdecl%3ai%5ftarget%5fitem%7b%0a%20%20%22%20%22%3f
%0a%20%20string%20name%3dstr%3ct%5fname%3e%28%29%3b%0a%20%20%22%20%22%3f%0a%20%2
0%22%3b%22%0a%7d%0a%0at%5ftarget%5fusing%3ai%5ftarget%5fitem%7b%0a%20%20t%5fstr%
5fap%3ai%5fqa%7b%0a%20%20%20%20%22%27%22%0a%20%20%20%20string%20body%3dstr%3cTAu
toPtr%3ci%5fchar%5fitem%3e%3e%28%29%3b%0a%20%20%20%20%22%27%22%0a%20%20%7d%0a%20
%20t%5fstr%5fqu%3ai%5fqa%7b%0a%20%20%20%20%22%5c%22%22%0a%20%20%20%20string%20bo
dy%3dstr%3cvector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%3e%28%29%3b%0a%20%20%20%20%2
2%5c%22%22%0a%20%20%7d%0a%20%20%22%20%22%3f%0a%20%20%22using%22%0a%20%20%22%20%2
2%0a%20%20string%20s%3dstr%3cTAutoPtr%3ci%5fqa%3e%3e%28%29%3b%0a%20%20%22%20%22%
0a%20%20%22as%22%0a%20%20%22%20%22%0a%20%20string%20lexer%3dstr%3ct%5fname%3e%28
%29%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%7d%0a%0at%5ftarget%7b%0a%20%20T
AutoPtr%3ci%5fexpr%3e%20unused%3f%3b%0a%20%20vector%3cTAutoPtr%3ci%5ftarget%5fit
em%3e%3e%20arr%3b%0a%20%20vector%3ct%5ftarget%5fitem%3a%3at%5fout%3e%20make%5fco
de%28t%5fic%5fdev%26icdev%29%7b%0a%20%20%20%20vector%3ct%5ftarget%5fitem%3a%3at%
5fout%3e%20out%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%
2b%29%7b%0a%20%20%20%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20if%28
auto%2ap%3ddynamic%5fcast%3ct%5ftarget%5fitem%2a%3e%28ex%2eget%28%29%29%29%7b%0a
%20%20%20%20%20%20%20%20out%2epush%5fback%28p%2d%3emake%5fcode%28icdev%29%29%3b%
0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20return%20out%3b%0a%20%20
%7d%0a%7d%0a%7d%0a%2f%2f
*/