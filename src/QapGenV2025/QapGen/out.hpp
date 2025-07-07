// 1549.297000 ms
struct t_simple_stat_lex{
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
    typedef t_simple_stat_lex::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_stat_lex::U U;//typedef t_simple_stat_lex::U U;
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
  //  void Do(t_var_expr&r){}
  //  void Do(t_block_expr&r){}
  //  void Do(t_call_expr&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_expr_visitor
  struct i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_expr
  public:
    typedef i_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_expr()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
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
  //===>>===i_stat_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_var_stat)\
    ADD(t_sep_stat)\
    ADD(t_block_stat)\
    ADD(t_expr_stat)\
    ADD(t_set_oper_stat)\
    ADD(t_func_stat)\
    ADD(t_oper_stat)\
    ADD(t_ret_stat)\
    ADD(t_null_stat)\
    ADD(t_postfix_oper_stat)\
    ADD(t_break_stat)\
    ADD(t_continue_stat)\
    ADD(t_for_stat)\
    ADD(t_if_stat)\
    ADD(t_struct_stat)\
    ADD(t_template_stat)\
  ADDEND()
  class i_stat;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_stat_visitor{
  public:
    typedef t_simple_stat_lex::i_stat i_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_stat_lex::U U;//typedef t_simple_stat_lex::U U;
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
    static TYPE*UberCast(i_stat*p){
      if(!p)return nullptr;Is<TYPE,i_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_stat*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_stat_visitor{
  //  void Do(t_var_stat&r){}
  //  void Do(t_sep_stat&r){}
  //  void Do(t_block_stat&r){}
  //  void Do(t_expr_stat&r){}
  //  void Do(t_set_oper_stat&r){}
  //  void Do(t_func_stat&r){}
  //  void Do(t_oper_stat&r){}
  //  void Do(t_ret_stat&r){}
  //  void Do(t_null_stat&r){}
  //  void Do(t_postfix_oper_stat&r){}
  //  void Do(t_break_stat&r){}
  //  void Do(t_continue_stat&r){}
  //  void Do(t_for_stat&r){}
  //  void Do(t_if_stat&r){}
  //  void Do(t_struct_stat&r){}
  //  void Do(t_template_stat&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_stat_visitor
  struct i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_stat
  public:
    typedef i_stat_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_stat()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_var_stat);
        F(t_sep_stat);
        F(t_block_stat);
        F(t_expr_stat);
        F(t_set_oper_stat);
        F(t_func_stat);
        F(t_oper_stat);
        F(t_ret_stat);
        F(t_null_stat);
        F(t_postfix_oper_stat);
        F(t_break_stat);
        F(t_continue_stat);
        F(t_for_stat);
        F(t_if_stat);
        F(t_struct_stat);
        F(t_template_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_oper)\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)OWNER(t_simple_stat_lex)
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
      virtual ~i_val()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
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
        return ok;
      }
      char first='1';
        string num;
        {
          M+=go_any_char(first,gen_dips("19"));
          O+=go_any(num,gen_dips("09"));
        }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_zero)\
    F(t_num )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)OWNER(t_simple_stat_lex)
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
  struct t_var_stat:public i_stat{
    //===>>===i_impl_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_type_impl)\
      ADD(t_auto_impl)\
    ADDEND()
    class i_impl;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_impl_visitor{
    public:
      typedef t_var_stat::i_impl i_impl;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_var_stat::U U;//typedef t_var_stat::U U;
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
      static TYPE*UberCast(i_impl*p){
        if(!p)return nullptr;Is<TYPE,i_impl_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_impl*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_impl_visitor{
    //  void Do(t_type_impl&r){}
    //  void Do(t_auto_impl&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_impl_visitor
    struct i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_impl
    public:
      typedef i_impl_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_impl()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_type_impl);
          F(t_auto_impl);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_lev14,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_value
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_value
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_const("=");
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_type_impl:public i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_impl)PARENT(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_type_expr,type,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_type_impl
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(type);
        if(!ok)return ok;
        ok=dev.go_auto(sep0);
        if(!ok)return ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(value);
        dev.go_auto(sep1);
        return ok;
      }
    };
    struct t_auto_impl:public i_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_auto_impl)PARENT(i_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_auto_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_auto_impl
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("auto");
        if(!ok)return ok;
        ok=dev.go_auto(sep0);
        if(!ok)return ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(value);
        dev.go_auto(sep1);
        return ok;
      }
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_impl>,impl,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(impl);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_value    )\
    F(t_type_impl)\
    F(t_auto_impl)\
    F(t_impl     )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_sep_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_stat
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
  struct t_command_block{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_command_block)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_command_block
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_command_block
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(arr);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_block_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_command_block,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_block_stat
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
  struct t_expr_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expr_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_char_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
      virtual ~i_val()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
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
    ADDEND()
    //=====+>>>>>t_sign
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_sign
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        return ok;
      }
      char sign='+';
        {
          go_any_char(sign,"-+");
        }
    };
    struct t_exp{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_exp
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_exp
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        return ok;
      }
      char e='e';
        TAutoPtr<t_sign> sign;
        string arr;
        {
          M+=go_any_char(e,"eE");
          O+=go_auto(sign);
          M+=go_any(arr,gen_dips("09"));
        }
    };
    struct t_num:public i_val{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_val)OWNER(t_real_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
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
        return ok;
      }
      char first='1';
        string num;
        {
          M+=go_any_char(first,gen_dips("19"));
          O+=go_any(num,gen_dips("09"));
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  struct t_var_expr:public i_expr{
    struct t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_lev14,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_elem
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
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(vector<t_elem>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(arr);
        return ok;
      }
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_item>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_vec(arr,".");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_elem)\
    F(t_item)\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_expr
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
  public:
  };
  struct t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
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
  struct t_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_simple_stat_lex)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_params)OWNER(t_simple_stat_lex)
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
    //===>>===i_call_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_dot)\
      ADD(t_colon)\
    ADDEND()
    class i_call;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_call_visitor{
    public:
      typedef t_call_expr::i_call i_call;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_call_expr::U U;//typedef t_call_expr::U U;
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
      static TYPE*UberCast(i_call*p){
        if(!p)return nullptr;Is<TYPE,i_call_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_call*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_call_visitor{
    //  void Do(t_dot&r){}
    //  void Do(t_colon&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_call_visitor
    struct i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_call
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_call
    public:
      typedef i_call_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_call()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_dot);
          F(t_colon);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_dot:public i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dot)PARENT(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_var_expr::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_dot
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_dot
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
    struct t_colon:public i_call{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_colon)PARENT(i_call)OWNER(t_call_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_name>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_colon
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_colon
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_bin_oper(arr,"::");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_dot  )\
    F(t_colon)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_call>,call,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_call_params,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
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
  public:
  };
  struct t_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep0);
      ok=dev.go_str<t_type_expr>(type);
      if(!ok)return ok;
      ok=dev.go_auto(sep1);
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      dev.go_auto(sep2);
      return ok;
    }
  };
  struct t_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      dev.go_auto(sep);
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_set_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var_expr::t_impl,var,DEF,$,$)\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(t_lev14,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_set_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(var);
      if(!ok)return ok;
      static const auto g_static_var_1=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",","));
      ok=dev.go_any_str_from_vec(oper,g_static_var_1);
      if(!ok)return ok;
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_set_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_set_oper,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_set_oper_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_set_oper_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_func_stat:public i_stat{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_func_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_params,params,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(t_command_block,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_str<t_type_expr>(type);
        if(!ok)return ok;
        ok=dev.go_auto(sep0);
        if(!ok)return ok;
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_auto(params);
        if(!ok)return ok;
        dev.go_auto(sep2);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_func_stat
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
  public:
  };
  struct t_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(t_params,params,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDVAR(t_command_block,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(type);
      if(!ok)return ok;
      ok=dev.go_auto(sep0);
      if(!ok)return ok;
      ok=dev.go_const("operator");
      if(!ok)return ok;
      dev.go_auto(sep1);
      static const auto g_static_var_4=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!",","));
      ok=dev.go_any_str_from_vec(oper,g_static_var_4);
      if(!ok)return ok;
      dev.go_auto(sep2);
      ok=dev.go_auto(params);
      if(!ok)return ok;
      dev.go_auto(sep3);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_ret_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ret_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ret_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("return");
      if(!ok)return ok;
      ok=dev.go_auto(sep0);
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_null_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_postfix_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix_oper)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var_expr::t_impl,var,DEF,$,$)\
  ADDVAR(string,oper,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_postfix_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_postfix_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(var);
      if(!ok)return ok;
      static const auto g_static_var_1=QapStrFinder::fromArr(split("++,--",","));
      ok=dev.go_any_str_from_vec(oper,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_postfix_oper_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix_oper_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_postfix_oper,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_postfix_oper_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_postfix_oper_stat
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
  struct t_break_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_break_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_break_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_break_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("break;");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_continue_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_continue_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_continue_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_continue_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("continue;");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_for_stat:public i_stat{
    //===>>===i_next_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_set)\
      ADD(t_postfix)\
    ADDEND()
    class i_next;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_next_visitor{
    public:
      typedef t_for_stat::i_next i_next;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_for_stat::U U;//typedef t_for_stat::U U;
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
      static TYPE*UberCast(i_next*p){
        if(!p)return nullptr;Is<TYPE,i_next_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_next*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_next_visitor{
    //  void Do(t_set&r){}
    //  void Do(t_postfix&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_next_visitor
    struct i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_next
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_next
    public:
      typedef i_next_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_next()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_set);
          F(t_postfix);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_set:public i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_set)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_set_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_set
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_set
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
    struct t_postfix:public i_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_postfix)PARENT(i_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_postfix_oper,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_postfix
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_postfix
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
    struct t_next{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_next)OWNER(t_for_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_next>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_next
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_next
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
    F(t_set    )\
    F(t_postfix)\
    F(t_next   )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_var_stat::t_impl>,init,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDVAR(TAutoPtr<t_lev14>,cond,DEF,$,$)\
  ADDVAR(t_sep,sep4,DEF,$,$)\
  ADDVAR(t_sep,sep5,DEF,$,$)\
  ADDVAR(TAutoPtr<t_next>,next,DEF,$,$)\
  ADDVAR(t_sep,sep6,DEF,$,$)\
  ADDVAR(t_sep,sep7,DEF,$,$)\
  ADDVAR(TAutoPtr<i_stat>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_for_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_for_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("for");
      if(!ok)return ok;
      dev.go_auto(sep0);
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(sep1);
      dev.go_auto(init);
      dev.go_auto(sep2);
      ok=dev.go_const(";");
      if(!ok)return ok;
      dev.go_auto(sep3);
      dev.go_auto(cond);
      dev.go_auto(sep4);
      ok=dev.go_const(";");
      if(!ok)return ok;
      dev.go_auto(sep5);
      dev.go_auto(next);
      dev.go_auto(sep6);
      ok=dev.go_const(")");
      if(!ok)return ok;
      dev.go_auto(sep7);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_if_stat:public i_stat{
    struct t_else{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else)OWNER(t_if_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_stat>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_else
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_else
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_const("else");
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_else)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_lev14,cond,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDVAR(TAutoPtr<i_stat>,bef,DEF,$,$)\
  ADDVAR(TAutoPtr<t_else>,aft,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_if_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_if_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("if");
      if(!ok)return ok;
      dev.go_auto(sep0);
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(cond);
      if(!ok)return ok;
      dev.go_auto(sep2);
      ok=dev.go_const(")");
      if(!ok)return ok;
      dev.go_auto(sep3);
      ok=dev.go_auto(bef);
      if(!ok)return ok;
      dev.go_auto(aft);
      return ok;
    }
  public:
  };
  struct t_struct{
    struct t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_struct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_var_stat::t_type_impl,body,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_field
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        ok=dev.go_const(";");
        if(!ok)return ok;
        dev.go_auto(sep1);
        return ok;
      }
    };
    struct t_method{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_method)OWNER(t_struct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_func_stat::t_impl,body,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_method
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_method
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_field )\
    F(t_method)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(vector<t_sep_struct>,arr,DEF,$,$)\
  ADDVAR(vector<t_field>,fields,DEF,$,$)\
  ADDVAR(vector<t_method>,methods,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("struct");
      if(!ok)return ok;
      ok=dev.go_auto(sep0);
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(arr);
      dev.go_auto(fields);
      dev.go_auto(methods);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_sep_struct{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_struct,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_struct
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_struct
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
  struct t_struct_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_struct,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_stat
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
  struct t_template_stat:public i_stat{
    //===>>===i_body_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_func_body)\
      ADD(t_oper_body)\
      ADD(t_struct_body)\
    ADDEND()
    class i_body;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_body_visitor{
    public:
      typedef t_template_stat::i_body i_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_stat::U U;//typedef t_template_stat::U U;
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
      static TYPE*UberCast(i_body*p){
        if(!p)return nullptr;Is<TYPE,i_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_body*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_body_visitor{
    //  void Do(t_func_body&r){}
    //  void Do(t_oper_body&r){}
    //  void Do(t_struct_body&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_body_visitor
    struct i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_body
    public:
      typedef i_body_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_body()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_func_body);
          F(t_oper_body);
          F(t_struct_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_param{
      struct t_type{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type)OWNER(t_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_type
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_type
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("class");
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_type)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_type,type,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_param
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(type);
        if(!ok)return ok;
        dev.go_auto(sep1);
        ok=dev.go_auto(name);
        if(!ok)return ok;
        dev.go_auto(sep2);
        return ok;
      }
    public:
    };
    struct t_params{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_param>,arr,DEF,$,$)\
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
        ok=dev.go_vec(arr,",");
        if(!ok)return ok;
        ok=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_func_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_func_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_func_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_func_body
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
    struct t_oper_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper_stat,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_oper_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_oper_body
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
    struct t_struct_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_body)PARENT(i_body)OWNER(t_template_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_struct,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_struct_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_struct_body
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
    F(t_param      )\
    F(t_params     )\
    F(t_func_body  )\
    F(t_oper_body  )\
    F(t_struct_body)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_stat)PARENT(i_stat)OWNER(t_simple_stat_lex)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_params,params,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<i_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_template_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_template_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("template");
      if(!ok)return ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(params);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03            )\
  F(t_lev05            )\
  F(t_lev06            )\
  F(t_lev07            )\
  F(t_lev08            )\
  F(t_lev09            )\
  F(t_lev10            )\
  F(t_lev11            )\
  F(t_lev12            )\
  F(t_lev13            )\
  F(t_lev14            )\
  F(t_string           )\
  F(t_int_expr         )\
  F(t_type_expr        )\
  F(t_var_stat         )\
  F(t_sep_stat         )\
  F(t_command_block    )\
  F(t_block_stat       )\
  F(t_expr_stat        )\
  F(t_char_expr        )\
  F(t_bool_expr        )\
  F(t_string_expr      )\
  F(t_real_expr        )\
  F(t_var_expr         )\
  F(t_block_expr       )\
  F(t_call_param       )\
  F(t_call_params      )\
  F(t_call_expr        )\
  F(t_param            )\
  F(t_params           )\
  F(t_set_oper         )\
  F(t_set_oper_stat    )\
  F(t_func_stat        )\
  F(t_oper_stat        )\
  F(t_ret_stat         )\
  F(t_null_stat        )\
  F(t_postfix_oper     )\
  F(t_postfix_oper_stat)\
  F(t_break_stat       )\
  F(t_continue_stat    )\
  F(t_for_stat         )\
  F(t_if_stat          )\
  F(t_struct           )\
  F(t_sep_struct       )\
  F(t_struct_stat      )\
  F(t_template_stat    )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_simple_stat_lex)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_simple_stat_lex
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_simple_stat_lex
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    return ok;
  }
public:
};
void t_simple_stat_lex::i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
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
}
void t_simple_stat_lex::i_stat::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_var_stat);
  F(t_sep_stat);
  F(t_block_stat);
  F(t_expr_stat);
  F(t_set_oper_stat);
  F(t_func_stat);
  F(t_oper_stat);
  F(t_ret_stat);
  F(t_null_stat);
  F(t_postfix_oper_stat);
  F(t_break_stat);
  F(t_continue_stat);
  F(t_for_stat);
  F(t_if_stat);
  F(t_struct_stat);
  F(t_template_stat);
  #undef F
  main();
}
void t_simple_stat_lex::t_int_expr::i_val::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_zero);
  F(t_num);
  #undef F
  main();
}
void t_simple_stat_lex::t_var_stat::i_impl::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_type_impl);
  F(t_auto_impl);
  #undef F
  main();
}
void t_simple_stat_lex::t_real_expr::i_val::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_num);
  F(t_zero);
  #undef F
  main();
}
void t_simple_stat_lex::t_call_expr::i_call::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_dot);
  F(t_colon);
  #undef F
  main();
}
void t_simple_stat_lex::t_for_stat::i_next::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_set);
  F(t_postfix);
  #undef F
  main();
}
void t_simple_stat_lex::t_template_stat::i_body::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_func_body);
  F(t_oper_body);
  F(t_struct_body);
  #undef F
  main();
}
/*
//list of types:
F(t_simple_stat_lex)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fsimple%5fstat%5flex%7b%0a%20%20t%5flev03%7b%0a%20%20%20%20string%20oper%3dan
y%5fstr%5ffrom%5fvec%28split%28%22%2b%2c%2d%2c%21%2c%7e%22%2c%22%2c%22%29%29%3f%
3b%0a%20%20%20%20TAutoPtr%3ci%5fexpr%3e%20expr%3b%0a%20%20%7d%0a%20%20t%5flev05%
7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffr
om%5fvec%28split%28%22%2a%2c%2f%2c%25%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%
0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%
20%20t%5flev03%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev03%20expr%3b%0a%
20%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev06%7b%0a%
20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fv
ec%28split%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%
20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev
05%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev05%20expr%3b%0a%20%20%20%20v
ector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev07%7b%0a%20%20%20%20t
%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%2
8%22%3c%3c%2c%3e%3e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5f
item%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev06%20e
xpr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev06%20expr%3b%0a%20%20%20%20vector%
3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev08%7b%0a%20%20%20%20t%5fope
r%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%3
c%2c%3c%3d%2c%3e%2c%3e%3d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%
20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev
07%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev07%20expr%3b%0a%20%20%20%20v
ector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev09%7b%0a%20%20%20%20t
%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%2
8%22%3d%3d%2c%21%3d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5f
item%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev08%20e
xpr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev08%20expr%3b%0a%20%20%20%20vector%
3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev10%7b%0a%20%20%20%20t%5fope
r%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%2
6%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%2
0%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev09%20expr%3b%0a%20%20%20
%20%7d%0a%20%20%20%20t%5flev09%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20ar
r%3f%3b%0a%20%20%7d%0a%20%20t%5flev11%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%2
0%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%5e%22%2c%22%2c%22%2
9%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper
%20oper%3b%0a%20%20%20%20%20%20t%5flev10%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20
%20t%5flev10%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7
d%0a%20%20t%5flev12%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20va
lue%3dany%5fstr%5ffrom%5fvec%28split%28%22%7c%22%2c%22%2c%22%29%29%3b%0a%20%20%2
0%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%2
0%20%20%20%20t%5flev11%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev11%20exp
r%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev1
3%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5f
from%5fvec%28split%28%22%26%26%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%2
0%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%
5flev12%20expr%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev12%20expr%3b%0a%20%20%2
0%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev14%7b%0a%20%20%2
0%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28sp
lit%28%22%7c%7c%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem
%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev13%20expr%
3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev13%20expr%3b%0a%20%20%20%20vector%3ct%
5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fstring%7b%0a%20%20%20%20%22%5c%22%
22%0a%20%20%20%20string%20value%3dstr%3cvector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e
%3e%28%29%3f%3b%0a%20%20%20%20%22%5c%22%22%0a%20%20%7d%0a%20%20t%5fint%5fexpr%3a
i%5fexpr%7b%0a%20%20%20%20t%5fzero%3ai%5fval%7b%0a%20%20%20%20%20%20%220%22%0a%2
0%20%20%20%7d%0a%20%20%20%20t%5fnum%3ai%5fval%7b%0a%20%20%20%20%20%20char%20firs
t%3d%271%27%3b%0a%20%20%20%20%20%20string%20num%3b%0a%20%20%20%20%20%20%7b%0a%20
%20%20%20%20%20%20%20M%2b%3dgo%5fany%5fchar%28first%2cgen%5fdips%28%2219%22%29%2
9%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fany%28num%2cgen%5fdips%28%2209%22%29%
29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20string%20value%3ds
tr%3cTAutoPtr%3ci%5fval%3e%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5ftype%5fexpr%7b%0a
%20%20%20%20t%5fparams%7b%0a%20%20%20%20%20%20%22%7b%22%0a%20%20%20%20%20%20stri
ng%20type%3dstr%3ct%5ftype%5fexpr%3e%28%29%3b%0a%20%20%20%20%20%20%22%2c%22%0a%2
0%20%20%20%20%20t%5fint%5fexpr%20count%3b%0a%20%20%20%20%20%20%22%7d%22%0a%20%20
%20%20%7d%0a%20%20%20%20t%5felem%7b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20
%20%20%20%20%20TAutoPtr%3ct%5fparams%3e%20params%3f%3b%0a%20%20%20%20%7d%0a%20%2
0%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20%20%20
%22%3a%3a%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20%20%20t%5fel
em%20body%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5felem%20first%3b%0a%20%20%20%20v
ector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fvar%5fstat%3ai%5fstat%7b
%0a%20%20%20%20t%5fvalue%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20
%20%20%20%22%3d%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20%20%20
t%5flev14%20value%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftype%5fimpl%3ai%5fimpl%
7b%0a%20%20%20%20%20%20t%5ftype%5fexpr%20type%3b%0a%20%20%20%20%20%20t%5fsep%20s
ep0%3b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5
fvalue%3e%20value%3f%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20%
7d%0a%20%20%20%20t%5fauto%5fimpl%3ai%5fimpl%7b%0a%20%20%20%20%20%20%22auto%22%0a
%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20
%20%20%20%20%20TAutoPtr%3ct%5fvalue%3e%20value%3f%3b%0a%20%20%20%20%20%20t%5fsep
%20sep1%3f%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%20%20%20TA
utoPtr%3ci%5fimpl%3e%20impl%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%20body%3
b%0a%20%20%20%20%22%3b%22%0a%20%20%7d%0a%20%20t%5fsep%5fstat%3ai%5fstat%7b%0a%20
%20%20%20t%5fsep%20sep%3b%0a%20%20%7d%0a%20%20t%5fcommand%5fblock%7b%0a%20%20%20
%20%22%7b%22%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fstat%3e%3e%20arr%3f%3b%0a%20%
20%20%20%22%7d%22%0a%20%20%7d%0a%20%20t%5fblock%5fstat%3ai%5fstat%7b%0a%20%20%20
%20t%5fcommand%5fblock%20body%3b%0a%20%20%7d%0a%20%20t%5fexpr%5fstat%3ai%5fstat%
7b%0a%20%20%20%20t%5flev14%20body%3b%0a%20%20%20%20%22%3b%22%0a%20%20%7d%0a%20%2
0t%5fchar%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5fchar%5fitem%20body%3b%0a%20%20%
7d%0a%20%20t%5fbool%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20string%20value%3dany%5fst
r%5ffrom%5fvec%28split%28%22true%2cfalse%22%2c%22%2c%22%29%29%3b%0a%20%20%7d%0a%
20%20t%5fstring%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5fstring%20body%3b%0a%20%20
%7d%0a%20%20t%5freal%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5ffrac%7b%0a%20%20%20%
20%20%20%22%2e%22%0a%20%20%20%20%20%20string%20arr%3dany%28gen%5fdips%28%2209%22
%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fsign%7b%0a%20%20%20%20%20%20char%2
0sign%3d%27%2b%27%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%
5fchar%28sign%2c%22%2d%2b%22%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%
20%20%20%20t%5fexp%7b%0a%20%20%20%20%20%20char%20e%3d%27e%27%3b%0a%20%20%20%20%2
0%20TAutoPtr%3ct%5fsign%3e%20sign%3b%0a%20%20%20%20%20%20string%20arr%3b%0a%20%2
0%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fany%5fchar%28e%2c%22eE%22
%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sign%29%3b%0a%20%20%20%20%20
%20%20%20M%2b%3dgo%5fany%28arr%2cgen%5fdips%28%2209%22%29%29%3b%0a%20%20%20%20%2
0%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fnum%3ai%5fval%7b%0a%20%20%20%20%20%2
0char%20first%3d%271%27%3b%0a%20%20%20%20%20%20string%20num%3b%0a%20%20%20%20%20
%20%7b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fany%5fchar%28first%2cgen%5fdips%28%
2219%22%29%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fany%28num%2cgen%5fdips%28
%2209%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fze
ro%3ai%5fval%7b%0a%20%20%20%20%20%20%220%22%0a%20%20%20%20%7d%0a%20%20%20%20t%5f
impl%7b%0a%20%20%20%20%20%20TAutoPtr%3ci%5fval%3e%20val%3b%0a%20%20%20%20%20%20T
AutoPtr%3ct%5ffrac%3e%20frac%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fexp%3e%20exp%
3f%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20value%3dstr%3ct%5fimpl%3e%28%29%3
b%0a%20%20%7d%0a%20%20t%5fvar%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5felem%7b%0a%
20%20%20%20%20%20%22%5b%22%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%
20%20%20t%5flev14%20expr%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20
%20%20%20%22%5d%22%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20
%20t%5fname%20name%3b%0a%20%20%20%20%20%20vector%3ct%5felem%3e%20arr%3f%3b%0a%20
%20%20%20%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%20%20%20vector%3ct%5fitem%3e%
20arr%3dvec%28%22%2e%22%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%20body%3b
%0a%20%20%7d%0a%20%20t%5fblock%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20%22%28%22%0a%2
0%20%20%20t%5flev14%20body%3b%0a%20%20%20%20%22%29%22%0a%20%20%7d%0a%20%20t%5fca
ll%5fparam%7b%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5flev14%20body%
3b%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%7d%0a%20%20t%5fcall%5fparams%7b%0
a%20%20%20%20%22%28%22%0a%20%20%20%20t%5fsep%20sep%3f%3b%0a%20%20%20%20vector%3c
t%5fcall%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%20%20%22%29%22%0a%
20%20%7d%0a%20%20t%5fcall%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5fdot%3ai%5fcall%
7b%0a%20%20%20%20%20%20t%5fvar%5fexpr%3a%3at%5fimpl%20body%3b%0a%20%20%20%20%7d%
0a%20%20%20%20t%5fcolon%3ai%5fcall%7b%0a%20%20%20%20%20%20vector%3ct%5fname%3e%2
0arr%3dbin%5foper%28%22%3a%3a%22%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20TAutoPtr%
3ci%5fcall%3e%20call%3b%0a%20%20%20%20t%5fsep%20sep%3f%3b%0a%20%20%20%20t%5fcall
%5fparams%20params%3b%0a%20%20%7d%0a%20%20t%5fparam%7b%0a%20%20%20%20t%5fsep%20s
ep0%3f%3b%0a%20%20%20%20string%20type%3dstr%3ct%5ftype%5fexpr%3e%28%29%3b%0a%20%
20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20t%5fsep
%20sep2%3f%3b%0a%20%20%7d%0a%20%20t%5fparams%7b%0a%20%20%20%20%22%28%22%0a%20%20
%20%20vector%3ct%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%20%20t%5fs
ep%20sep%3f%3b%0a%20%20%20%20%22%29%22%0a%20%20%7d%0a%20%20t%5fset%5foper%7b%0a%
20%20%20%20t%5fvar%5fexpr%3a%3at%5fimpl%20var%3b%0a%20%20%20%20string%20oper%3da
ny%5fstr%5ffrom%5fvec%28split%28%22%3d%2c%2b%3d%2c%2d%3d%2c%2a%3d%2c%2f%3d%2c%25
%3d%2c%7c%3d%2c%26%3d%2c%5e%3d%2c%3c%3c%3d%2c%3e%3e%3d%22%2c%22%2c%22%29%29%3b%0
a%20%20%20%20t%5flev14%20expr%3b%0a%20%20%7d%0a%20%20t%5fset%5foper%5fstat%3ai%5
fstat%7b%0a%20%20%20%20t%5fset%5foper%20body%3b%0a%20%20%20%20%22%3b%22%0a%20%20
%7d%0a%20%20t%5ffunc%5fstat%3ai%5fstat%7b%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%
20%20%20string%20type%3dstr%3ct%5ftype%5fexpr%3e%28%29%3b%0a%20%20%20%20%20%20t%
5fsep%20sep0%3b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%20%20t%5fs
ep%20sep1%3f%3b%0a%20%20%20%20%20%20t%5fparams%20params%3b%0a%20%20%20%20%20%20t
%5fsep%20sep2%3f%3b%0a%20%20%20%20%20%20t%5fcommand%5fblock%20body%3b%0a%20%20%2
0%20%7d%0a%20%20%20%20t%5fimpl%20body%3b%0a%20%20%7d%0a%20%20t%5foper%5fstat%3ai
%5fstat%7b%0a%20%20%20%20t%5fname%20type%3b%0a%20%20%20%20t%5fsep%20sep0%3b%0a%2
0%20%20%20%22operator%22%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20string
%20oper%3dany%5fstr%5ffrom%5fvec%28split%28%22%3d%2c%2b%3d%2c%2d%3d%2c%2a%3d%2c%
2f%3d%2c%25%3d%2c%7c%3d%2c%26%3d%2c%5e%3d%2c%3c%3c%3d%2c%3e%3e%3d%2c%7c%7c%2c%26
%26%2c%7c%2c%5e%2c%26%2c%3d%3d%2c%21%3d%2c%3c%2c%3c%3d%2c%3e%2c%3e%3d%2c%3c%3c%2
c%3e%3e%2c%2b%2c%2d%2c%2a%2c%2f%2c%25%2c%2b%2b%2c%2d%2d%2c%7e%2c%21%22%2c%22%2c%
22%29%29%3b%0a%20%20%20%20t%5fsep%20sep2%3f%3b%0a%20%20%20%20t%5fparams%20params
%3b%0a%20%20%20%20t%5fsep%20sep3%3f%3b%0a%20%20%20%20t%5fcommand%5fblock%20body%
3b%0a%20%20%7d%0a%20%20t%5fret%5fstat%3ai%5fstat%7b%0a%20%20%20%20%22return%22%0
a%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20t%5flev14%20body%3b%0a%20%20%20%20t
%5fsep%20sep1%3f%3b%0a%20%20%20%20%22%3b%22%0a%20%20%7d%0a%20%20t%5fnull%5fstat%
3ai%5fstat%7b%0a%20%20%20%20%22%3b%22%0a%20%20%7d%0a%20%20t%5fpostfix%5foper%7b%
0a%20%20%20%20t%5fvar%5fexpr%3a%3at%5fimpl%20var%3b%0a%20%20%20%20string%20oper%
3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2b%2c%2d%2d%22%2c%22%2c%22%29%29%3b%0a
%20%20%7d%0a%20%20t%5fpostfix%5foper%5fstat%3ai%5fstat%7b%0a%20%20%20%20t%5fpost
fix%5foper%20body%3b%0a%20%20%7d%0a%20%20t%5fbreak%5fstat%3ai%5fstat%7b%0a%20%20
%20%20%22break%3b%22%0a%20%20%7d%0a%20%20t%5fcontinue%5fstat%3ai%5fstat%7b%0a%20
%20%20%20%22continue%3b%22%0a%20%20%7d%0a%20%20t%5ffor%5fstat%3ai%5fstat%7b%0a%2
0%20%20%20t%5fset%3ai%5fnext%7b%0a%20%20%20%20%20%20t%5fset%5foper%20body%3b%0a%
20%20%20%20%7d%0a%20%20%20%20t%5fpostfix%3ai%5fnext%7b%0a%20%20%20%20%20%20t%5fp
ostfix%5foper%20body%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fnext%7b%0a%20%20%20%
20%20%20TAutoPtr%3ci%5fnext%3e%20body%3b%0a%20%20%20%20%7d%0a%20%20%20%20%22for%
22%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20%22%28%22%0a%20%20%20%20t%5f
sep%20sep1%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fvar%5fstat%3a%3at%5fimpl%3e%20init
%3f%3b%0a%20%20%20%20t%5fsep%20sep2%3f%3b%0a%20%20%20%20%22%3b%22%0a%20%20%20%20
t%5fsep%20sep3%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5flev14%3e%20cond%3f%3b%0a%20%20
%20%20t%5fsep%20sep4%3f%3b%0a%20%20%20%20%22%3b%22%0a%20%20%20%20t%5fsep%20sep5%
3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fnext%3e%20next%3f%3b%0a%20%20%20%20t%5fsep%20
sep6%3f%3b%0a%20%20%20%20%22%29%22%0a%20%20%20%20t%5fsep%20sep7%3f%3b%0a%20%20%2
0%20TAutoPtr%3ci%5fstat%3e%20body%3b%0a%20%20%7d%0a%20%20t%5fif%5fstat%3ai%5fsta
t%7b%0a%20%20%20%20t%5felse%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20
%20%20%20%20%22else%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20%2
0%20TAutoPtr%3ci%5fstat%3e%20body%3b%0a%20%20%20%20%7d%0a%20%20%20%20%22if%22%0a
%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20%22%28%22%0a%20%20%20%20t%5fsep%2
0sep1%3f%3b%0a%20%20%20%20t%5flev14%20cond%3b%0a%20%20%20%20t%5fsep%20sep2%3f%3b
%0a%20%20%20%20%22%29%22%0a%20%20%20%20t%5fsep%20sep3%3f%3b%0a%20%20%20%20TAutoP
tr%3ci%5fstat%3e%20bef%3b%0a%20%20%20%20TAutoPtr%3ct%5felse%3e%20aft%3f%3b%0a%20
%20%7d%0a%20%20t%5fstruct%7b%0a%20%20%20%20t%5ffield%7b%0a%20%20%20%20%20%20t%5f
sep%20sep0%3f%3b%0a%20%20%20%20%20%20t%5fvar%5fstat%3a%3at%5ftype%5fimpl%20body%
3b%0a%20%20%20%20%20%20%22%3b%22%0a%20%20%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%
20%20%20%7d%0a%20%20%20%20t%5fmethod%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3f%3b
%0a%20%20%20%20%20%20t%5ffunc%5fstat%3a%3at%5fimpl%20body%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3f%3b%0a%20%20%20%20%7d%0a%20%20%20%20%22struct%22%0a%20%20%20%2
0t%5fsep%20sep0%3b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20t%5fsep%20sep1
%3f%3b%0a%20%20%20%20%22%7b%22%0a%20%20%20%20vector%3ct%5fsep%5fstruct%3e%20arr%
3f%3b%0a%20%20%20%20vector%3ct%5ffield%3e%20fields%3f%3b%0a%20%20%20%20vector%3c
t%5fmethod%3e%20methods%3f%3b%0a%20%20%20%20%22%7d%22%0a%20%20%7d%0a%20%20t%5fse
p%5fstruct%7b%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5fstruct%20body
%3b%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%7d%0a%20%20t%5fstruct%5fstat%3ai
%5fstat%7b%0a%20%20%20%20t%5fstruct%20body%3b%0a%20%20%7d%0a%20%20t%5ftemplate%5
fstat%3ai%5fstat%7b%0a%20%20%20%20t%5fparam%7b%0a%20%20%20%20%20%20t%5ftype%7b%0
a%20%20%20%20%20%20%20%20%22class%22%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%2
0t%5fsep%20sep0%3f%3b%0a%20%20%20%20%20%20t%5ftype%20type%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3f%3b%0a%20%20%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep2%3f%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fparams%7b%0a%20%20%20%
20%20%20%22%7b%22%0a%20%20%20%20%20%20vector%3ct%5fparam%3e%20arr%3dvec%28%22%2c
%22%29%3b%0a%20%20%20%20%20%20%22%7d%22%0a%20%20%20%20%7d%0a%20%20%20%20t%5ffunc
%5fbody%3ai%5fbody%7b%0a%20%20%20%20%20%20t%5ffunc%5fstat%3a%3at%5fimpl%20body%3
b%0a%20%20%20%20%7d%0a%20%20%20%20t%5foper%5fbody%3ai%5fbody%7b%0a%20%20%20%20%2
0%20t%5foper%5fstat%20body%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fstruct%5fbody%
3ai%5fbody%7b%0a%20%20%20%20%20%20t%5fstruct%20body%3b%0a%20%20%20%20%7d%0a%20%2
0%20%20%22template%22%0a%20%20%20%20t%5fsep%20sep0%3f%3b%0a%20%20%20%20t%5fparam
s%20params%3b%0a%20%20%20%20t%5fsep%20sep1%3f%3b%0a%20%20%20%20TAutoPtr%3ci%5fbo
dy%3e%20body%3b%0a%20%20%7d%0a%7d
*/