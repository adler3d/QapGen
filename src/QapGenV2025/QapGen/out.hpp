// 2788.457900 ms
struct t_inl_file{
  //===>>===i_class_stat_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_access_mod_class_stat)\
    ADD(t_fv_class_stat)\
    ADD(t_typedef_class_stat)\
    ADD(t_dtor_class_stat)\
    ADD(t_ctor_class_stat)\
    ADD(t_oper_cast_class_stat)\
    ADD(t_common_oper_class_stat)\
    ADD(t_namespace_class_stat)\
    ADD(t_template_class_stat)\
    ADD(t_enum_class_stat)\
    ADD(t_using_class_stat)\
    ADD(t_pragma_class_stat)\
    ADD(t_include_class_stat)\
    ADD(t_preproc_if_class_stat)\
    ADD(t_preproc_else_class_stat)\
    ADD(t_preproc_endif_class_stat)\
    ADD(t_define_class_stat)\
    ADD(t_undef_class_stat)\
    ADD(t_sep_class_stat)\
    ADD(t_null_class_stat)\
    ADD(t_class_class_stat)\
  ADDEND()
  class i_class_stat;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_class_stat_visitor{
  public:
    typedef t_inl_file::i_class_stat i_class_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;//typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_class_stat*p){
      if(!p)return nullptr;Is<TYPE,i_class_stat_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_class_stat*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_class_stat_visitor{
  //  void Do(t_access_mod_class_stat&r){}
  //  void Do(t_fv_class_stat&r){}
  //  void Do(t_typedef_class_stat&r){}
  //  void Do(t_dtor_class_stat&r){}
  //  void Do(t_ctor_class_stat&r){}
  //  void Do(t_oper_cast_class_stat&r){}
  //  void Do(t_common_oper_class_stat&r){}
  //  void Do(t_namespace_class_stat&r){}
  //  void Do(t_template_class_stat&r){}
  //  void Do(t_enum_class_stat&r){}
  //  void Do(t_using_class_stat&r){}
  //  void Do(t_pragma_class_stat&r){}
  //  void Do(t_include_class_stat&r){}
  //  void Do(t_preproc_if_class_stat&r){}
  //  void Do(t_preproc_else_class_stat&r){}
  //  void Do(t_preproc_endif_class_stat&r){}
  //  void Do(t_define_class_stat&r){}
  //  void Do(t_undef_class_stat&r){}
  //  void Do(t_sep_class_stat&r){}
  //  void Do(t_null_class_stat&r){}
  //  void Do(t_class_class_stat&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_class_stat_visitor
  struct i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_class_stat
  public:
    typedef i_class_stat_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_class_stat()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_access_mod_class_stat);
        F(t_fv_class_stat);
        F(t_typedef_class_stat);
        F(t_dtor_class_stat);
        F(t_ctor_class_stat);
        F(t_oper_cast_class_stat);
        F(t_common_oper_class_stat);
        F(t_namespace_class_stat);
        F(t_template_class_stat);
        F(t_enum_class_stat);
        F(t_using_class_stat);
        F(t_pragma_class_stat);
        F(t_include_class_stat);
        F(t_preproc_if_class_stat);
        F(t_preproc_else_class_stat);
        F(t_preproc_endif_class_stat);
        F(t_define_class_stat);
        F(t_undef_class_stat);
        F(t_sep_class_stat);
        F(t_null_class_stat);
        F(t_class_class_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_expr_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_call_expr)\
    ADD(t_block_expr)\
    ADD(t_bool_expr)\
    ADD(t_string_expr)\
    ADD(t_char_expr)\
    ADD(t_num_expr)\
    ADD(t_real_expr)\
    ADD(t_nullptr_expr)\
    ADD(t_or_expr)\
    ADD(t_hex_expr)\
    ADD(t_var_expr)\
  ADDEND()
  class i_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_expr_visitor{
  public:
    typedef t_inl_file::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;//typedef t_inl_file::U U;
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
  //  void Do(t_call_expr&r){}
  //  void Do(t_block_expr&r){}
  //  void Do(t_bool_expr&r){}
  //  void Do(t_string_expr&r){}
  //  void Do(t_char_expr&r){}
  //  void Do(t_num_expr&r){}
  //  void Do(t_real_expr&r){}
  //  void Do(t_nullptr_expr&r){}
  //  void Do(t_or_expr&r){}
  //  void Do(t_hex_expr&r){}
  //  void Do(t_var_expr&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_expr_visitor
  struct i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_inl_file)
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
        F(t_call_expr);
        F(t_block_expr);
        F(t_bool_expr);
        F(t_string_expr);
        F(t_char_expr);
        F(t_num_expr);
        F(t_real_expr);
        F(t_nullptr_expr);
        F(t_or_expr);
        F(t_hex_expr);
        F(t_var_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_func_body_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_zero_func_body)\
    ADD(t_null_func_body)\
    ADD(t_delete_func_body)\
    ADD(t_impl_func_body)\
  ADDEND()
  class i_func_body;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_func_body_visitor{
  public:
    typedef t_inl_file::i_func_body i_func_body;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;//typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_func_body*p){
      if(!p)return nullptr;Is<TYPE,i_func_body_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_func_body*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_func_body_visitor{
  //  void Do(t_zero_func_body&r){}
  //  void Do(t_null_func_body&r){}
  //  void Do(t_delete_func_body&r){}
  //  void Do(t_impl_func_body&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_func_body_visitor
  struct i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_func_body
  public:
    typedef i_func_body_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_func_body()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_zero_func_body);
        F(t_null_func_body);
        F(t_delete_func_body);
        F(t_impl_func_body);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_tmpl_expr_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_call_tmpl_expr)\
    ADD(t_block_tmpl_expr)\
    ADD(t_bool_tmpl_expr)\
    ADD(t_string_tmpl_expr)\
    ADD(t_char_tmpl_expr)\
    ADD(t_num_tmpl_expr)\
    ADD(t_real_tmpl_expr)\
    ADD(t_nullptr_tmpl_expr)\
    ADD(t_or_tmpl_expr)\
    ADD(t_hex_tmpl_expr)\
    ADD(t_var_tmpl_expr)\
  ADDEND()
  class i_tmpl_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_tmpl_expr_visitor{
  public:
    typedef t_inl_file::i_tmpl_expr i_tmpl_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;//typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_tmpl_expr*p){
      if(!p)return nullptr;Is<TYPE,i_tmpl_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_tmpl_expr*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_tmpl_expr_visitor{
  //  void Do(t_call_tmpl_expr&r){}
  //  void Do(t_block_tmpl_expr&r){}
  //  void Do(t_bool_tmpl_expr&r){}
  //  void Do(t_string_tmpl_expr&r){}
  //  void Do(t_char_tmpl_expr&r){}
  //  void Do(t_num_tmpl_expr&r){}
  //  void Do(t_real_tmpl_expr&r){}
  //  void Do(t_nullptr_tmpl_expr&r){}
  //  void Do(t_or_tmpl_expr&r){}
  //  void Do(t_hex_tmpl_expr&r){}
  //  void Do(t_var_tmpl_expr&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_tmpl_expr_visitor
  struct i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_tmpl_expr
  public:
    typedef i_tmpl_expr_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_tmpl_expr()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_call_tmpl_expr);
        F(t_block_tmpl_expr);
        F(t_bool_tmpl_expr);
        F(t_string_tmpl_expr);
        F(t_char_tmpl_expr);
        F(t_num_tmpl_expr);
        F(t_real_tmpl_expr);
        F(t_nullptr_tmpl_expr);
        F(t_or_tmpl_expr);
        F(t_hex_tmpl_expr);
        F(t_var_tmpl_expr);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_concrete_param_way_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_pfunc_concrete_param_way)\
    ADD(t_type_concrete_param_way)\
    ADD(t_expr_concrete_param_way)\
  ADDEND()
  class i_concrete_param_way;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_concrete_param_way_visitor{
  public:
    typedef t_inl_file::i_concrete_param_way i_concrete_param_way;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_inl_file::U U;//typedef t_inl_file::U U;
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
    static TYPE*UberCast(i_concrete_param_way*p){
      if(!p)return nullptr;Is<TYPE,i_concrete_param_way_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_concrete_param_way*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_concrete_param_way_visitor{
  //  void Do(t_pfunc_concrete_param_way&r){}
  //  void Do(t_type_concrete_param_way&r){}
  //  void Do(t_expr_concrete_param_way&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_concrete_param_way_visitor
  struct i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_concrete_param_way
  public:
    typedef i_concrete_param_way_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_concrete_param_way()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_pfunc_concrete_param_way);
        F(t_type_concrete_param_way);
        F(t_expr_concrete_param_way);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_inl_file)
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev09)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev10)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev11)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev12)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev13)OWNER(t_inl_file)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev14)OWNER(t_inl_file)
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
  struct t_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expr
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_tmpl_lev03{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev03)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,oper,DEF,$,$)\
  ADDVAR(TAutoPtr<i_tmpl_expr>,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev03
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev03
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("&,*,+,-,!,~",","));
      dev.go_any_str_from_vec(oper,g_static_var_0);
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_tmpl_lev05{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev05)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev05)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev03,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev05)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev03,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev05
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev05
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
  struct t_tmpl_lev06{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev06)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev06)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev05,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev06)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev05,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev06
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev06
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
  struct t_tmpl_lev09{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev09)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev09)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev06,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev09)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev06,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev09
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev09
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
  struct t_tmpl_lev10{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev10)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev10)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev09,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev10)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev09,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev10
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev10
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
  struct t_tmpl_lev11{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev11)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev11)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev10,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev11)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev10,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev11
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev11
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
  struct t_tmpl_lev12{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev12)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev12)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev11,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev12)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev11,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev12
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev12
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
  struct t_tmpl_lev13{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev13)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev13)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev12,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev13)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev12,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev13
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev13
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
  struct t_tmpl_lev14{
    struct t_oper{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_tmpl_lev14)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_tmpl_lev14)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_oper,oper,DEF,$,$)\
    ADDVAR(t_tmpl_lev13,expr,DEF,$,$)\
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_lev14)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev13,expr,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_lev14
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_lev14
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
  struct t_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_lev14,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_expr
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_concrete_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_concrete_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<i_concrete_param_way>,body,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_concrete_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_concrete_param
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
  struct t_concrete_params{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_concrete_params)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_concrete_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_concrete_params
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_concrete_params
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("<");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      ok=dev.go_const(">");
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_access_mod{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_access_mod)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_access_mod
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_access_mod
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("public,protected,private",","));
      ok=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_access_mod_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_access_mod_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_access_mod,mod,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_access_mod_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_access_mod_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(mod);
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_const(":");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_raw_func_body{
    //===>>===i_item_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_sep_item)\
      ADD(t_s_item)\
      ADD(t_c_item)\
      ADD(t_code_item)\
      ADD(t_div_item)\
      ADD(t_block_item)\
    ADDEND()
    class i_item;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_item_visitor{
    public:
      typedef t_raw_func_body::i_item i_item;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_raw_func_body::U U;//typedef t_raw_func_body::U U;
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
      static TYPE*UberCast(i_item*p){
        if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_item*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_item_visitor{
    //  void Do(t_sep_item&r){}
    //  void Do(t_s_item&r){}
    //  void Do(t_c_item&r){}
    //  void Do(t_code_item&r){}
    //  void Do(t_div_item&r){}
    //  void Do(t_block_item&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_item_visitor
    struct i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_raw_func_body)
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
          F(t_sep_item);
          F(t_s_item);
          F(t_c_item);
          F(t_code_item);
          F(t_div_item);
          F(t_block_item);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_sep_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_sep_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_sep_item
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
    struct t_s_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_s_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
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
        ok=dev.go_str<t_str_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_c_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
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
        ok=dev.go_str<t_char_item::t_impl>(value);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_code_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,code,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_code_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_code_item
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");
        ok=dev.go_any(code,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_div_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_div_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_div_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_div_item
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("/");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_block_item:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_item)PARENT(i_item)OWNER(t_raw_func_body)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_raw_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_block_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_block_item
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
    F(t_sep_item  )\
    F(t_s_item    )\
    F(t_c_item    )\
    F(t_code_item )\
    F(t_div_item  )\
    F(t_block_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_func_body
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
  public:
  };
  struct t_func_path{
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_func_path)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_str<t_name>(value);
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_const("::");
        if(!ok)return ok;
        dev.go_auto(sep1);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_path)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_func_path
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_func_path
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_const_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_const_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      static const auto g_static_var_1=QapStrFinder::fromArr(split("typename,const,unsigned",","));
      ok=dev.go_any_str_from_vec(keyword,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_keyword{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_keyword
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_keyword
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
      ok=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  };
  struct t_ptr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(cv);
      dev.go_auto(sep);
      ok=dev.go_const("*");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_ref{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ref)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,ref,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ref
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ref
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(cv);
      dev.go_auto(sep);
      static const auto g_static_var_2=QapStrFinder::fromArr(split("&&,&",","));
      ok=dev.go_any_str_from_vec(ref,g_static_var_2);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_str<t_name>(name);
      if(!ok)return ok;
      dev.go_auto(concrete_params);
      return ok;
    }
  };
  struct t_scope_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_with_sep)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope_with_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_scope_with_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_const("::");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_scopes{
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_scopes)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_scope_with_sep,sws,DEF,$,$)\
    ADDVAR(t_type_with_sep,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(sws);
        if(!ok)return ok;
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scopes)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_with_sep,first,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scopes
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_scopes
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
  struct t_fv_class_stat:public i_class_stat{
    struct t_type_expr{
      //===>>===i_name_part_visitor
      #define DEF_PRO_BLANK()
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
        ADD(t_raw_name_part)\
        ADD(t_brackets_name_part)\
      ADDEND()
      class i_name_part;
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      class i_name_part_visitor{
      public:
        typedef t_type_expr::i_name_part i_name_part;
      public:
        #define ADD(TYPE)virtual void Do(TYPE&r)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;//typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_name_part*p){
          if(!p)return nullptr;Is<TYPE,i_name_part_visitor> IS;p->Use(IS);return IS.ptr;
        }
        #else
        template<class TYPE>
        static TYPE*UberCast(i_name_part*p){return dynamic_cast<TYPE*>(p);}
        #endif
      };
      //struct t_visitor:public i_name_part_visitor{
      //  void Do(t_raw_name_part&r){}
      //  void Do(t_brackets_name_part&r){}
      //};
      #undef LIST
      #undef DEF_PRO_BLANK
      //===<<===i_name_part_visitor
      struct i_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_name_part
      public:
        typedef i_name_part_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
        virtual ~i_name_part()=default;
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          void load();/*
          {
            F(t_raw_name_part);
            F(t_brackets_name_part);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }*/
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      //===>>===i_func_param_visitor
      #define DEF_PRO_BLANK()
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
        ADD(t_pfunc_func_param)\
        ADD(t_var_args_func_param)\
        ADD(t_type_func_param)\
        ADD(t_expr_func_param)\
      ADDEND()
      class i_func_param;
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      class i_func_param_visitor{
      public:
        typedef t_type_expr::i_func_param i_func_param;
      public:
        #define ADD(TYPE)virtual void Do(TYPE&r)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;//typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_func_param*p){
          if(!p)return nullptr;Is<TYPE,i_func_param_visitor> IS;p->Use(IS);return IS.ptr;
        }
        #else
        template<class TYPE>
        static TYPE*UberCast(i_func_param*p){return dynamic_cast<TYPE*>(p);}
        #endif
      };
      //struct t_visitor:public i_func_param_visitor{
      //  void Do(t_pfunc_func_param&r){}
      //  void Do(t_var_args_func_param&r){}
      //  void Do(t_type_func_param&r){}
      //  void Do(t_expr_func_param&r){}
      //};
      #undef LIST
      #undef DEF_PRO_BLANK
      //===<<===i_func_param_visitor
      struct i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_func_param
      public:
        typedef i_func_param_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
        virtual ~i_func_param()=default;
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          void load();/*
          {
            F(t_pfunc_func_param);
            F(t_var_args_func_param);
            F(t_type_func_param);
            F(t_expr_func_param);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }*/
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      //===>>===i_typeexpr_visitor
      #define DEF_PRO_BLANK()
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
        ADD(t_impl_typeexpr)\
        ADD(t_decl_typeexpr)\
      ADDEND()
      class i_typeexpr;
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      class i_typeexpr_visitor{
      public:
        typedef t_type_expr::i_typeexpr i_typeexpr;
      public:
        #define ADD(TYPE)virtual void Do(TYPE&r)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_type_expr::U U;//typedef t_type_expr::U U;
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
        static TYPE*UberCast(i_typeexpr*p){
          if(!p)return nullptr;Is<TYPE,i_typeexpr_visitor> IS;p->Use(IS);return IS.ptr;
        }
        #else
        template<class TYPE>
        static TYPE*UberCast(i_typeexpr*p){return dynamic_cast<TYPE*>(p);}
        #endif
      };
      //struct t_visitor:public i_typeexpr_visitor{
      //  void Do(t_impl_typeexpr&r){}
      //  void Do(t_decl_typeexpr&r){}
      //};
      #undef LIST
      #undef DEF_PRO_BLANK
      //===<<===i_typeexpr_visitor
      struct i_typeexpr{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_typeexpr
      public:
        typedef i_typeexpr_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
        virtual ~i_typeexpr()=default;
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          void load();/*
          {
            F(t_impl_typeexpr);
            F(t_decl_typeexpr);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }*/
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      struct t_type_expr_with_sep_and_cv{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr_with_sep_and_cv)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(vector<t_const_with_sep>,cvs,DEF,$,$)\
      ADDVAR(TAutoPtr<t_type_expr>,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_type_expr_with_sep_and_cv
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_type_expr_with_sep_and_cv
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(cvs);
          ok=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<i_name_part>,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_name_part
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_arr_body{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_body)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(t_expr,expr,DEF,$,$)\
      ADDVAR(t_sep,sep2,DEF,$,$)\
      ADDVAR(t_sep,sep3,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_arr_body
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_arr_body
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(sep0);
          ok=dev.go_const("[");
          if(!ok)return ok;
          dev.go_auto(sep1);
          ok=dev.go_auto(expr);
          if(!ok)return ok;
          dev.go_auto(sep2);
          ok=dev.go_const("]");
          if(!ok)return ok;
          dev.go_auto(sep3);
          return ok;
        }
      };
      struct t_raw_name_part:public i_name_part{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_name_part)PARENT(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(string,name,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_raw_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_raw_name_part
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_str<t_name>(name);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_brackets_name_part:public i_name_part{
        //===>>===i_part_visitor
        #define DEF_PRO_BLANK()
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
          ADD(t_amp_part)\
          ADD(t_star_part)\
        ADDEND()
        class i_part;
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        class i_part_visitor{
        public:
          typedef t_brackets_name_part::i_part i_part;
        public:
          #define ADD(TYPE)virtual void Do(TYPE&r)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_brackets_name_part::U U;//typedef t_brackets_name_part::U U;
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
        //  void Do(t_amp_part&r){}
        //  void Do(t_star_part&r){}
        //};
        #undef LIST
        #undef DEF_PRO_BLANK
        //===<<===i_part_visitor
        struct i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_part
        public:
          typedef i_part_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
          virtual ~i_part()=default;
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            void load();/*
            {
              F(t_amp_part);
              F(t_star_part);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }*/
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
        struct t_amp{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_amp)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(string,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_amp
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_amp
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            static const auto g_static_var_0=QapStrFinder::fromArr(split("&,&&",","));
            ok=dev.go_any_str_from_vec(body,g_static_var_0);
            if(!ok)return ok;
            return ok;
          }
        };
        struct t_amp_part:public i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_amp_part)PARENT(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_amp,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_amp_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_amp_part
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
        struct t_star_part:public i_part{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_star_part)PARENT(i_part)OWNER(t_brackets_name_part)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(string,stars,DEF,$,$)\
        ADDVAR(TAutoPtr<t_amp>,amp,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_star_part
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_star_part
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            static const auto g_static_var_0=CharMask::fromStr("*");
            ok=dev.go_any(stars,g_static_var_0);
            if(!ok)return ok;
            dev.go_auto(amp);
            return ok;
          }
        };
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_amp      )\
        F(t_amp_part )\
        F(t_star_part)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_brackets_name_part)PARENT(i_name_part)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<i_part>,stamp_part,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(TAutoPtr<t_name_part>,namepart,DEF,$,$)\
      ADDVAR(TAutoPtr<t_arr_body>,arrbody,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_brackets_name_part
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_brackets_name_part
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("(");
          if(!ok)return ok;
          ok=dev.go_auto(stamp_part);
          if(!ok)return ok;
          dev.go_auto(sep);
          dev.go_auto(namepart);
          ok=dev.go_const(")");
          if(!ok)return ok;
          dev.go_auto(arrbody);
          return ok;
        }
      public:
      };
      struct t_func_param_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param_value)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(t_expr,value,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_param_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_param_value
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("=");
          if(!ok)return ok;
          dev.go_auto(sep);
          ok=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(TAutoPtr<i_func_param>,body,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(TAutoPtr<t_func_param_value>,value,DEF,$,$)\
      ADDVAR(t_sep,sep2,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_param
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(sep0);
          ok=dev.go_auto(body);
          if(!ok)return ok;
          dev.go_auto(sep1);
          dev.go_auto(value);
          dev.go_auto(sep2);
          return ok;
        }
      };
      struct t_func_params{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_params)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(vector<t_func_param>,arr,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_func_params
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_func_params
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(sep);
          ok=dev.go_const("(");
          if(!ok)return ok;
          dev.go_vec(arr,",");
          ok=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_pfunc{
        struct t_addr{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_addr)OWNER(t_pfunc)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_addr
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_addr
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_auto(type);
            if(!ok)return ok;
            ok=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
        };
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_addr)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
      ADDVAR(t_addr,addr,DEF,$,$)\
      ADDVAR(string,name,DEF,$,$)\
      ADDVAR(t_func_params,params,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pfunc
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pfunc
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_auto(type);
          if(!ok)return ok;
          ok=dev.go_const("(");
          if(!ok)return ok;
          dev.go_auto(addr);
          ok=dev.go_const("*");
          if(!ok)return ok;
          dev.go_str<t_name>(name);
          ok=dev.go_const(")");
          if(!ok)return ok;
          ok=dev.go_auto(params);
          if(!ok)return ok;
          return ok;
        }
      public:
      };
      struct t_pfunc_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_pfunc,value,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pfunc_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pfunc_func_param
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_auto(value);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_var_args_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_args_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_var_args_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_var_args_func_param
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("...");
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_type_func_param:public i_func_param{
        struct t_const{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const)OWNER(t_type_func_param)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_sep,sep,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_const
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_const
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_const("const");
            if(!ok)return ok;
            dev.go_auto(sep);
            return ok;
          }
        };
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_const)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_type_expr_with_sep_and_cv,type,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(TAutoPtr<t_const>,cv,DEF,$,$)\
      ADDVAR(TAutoPtr<t_name_part>,namepart,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_type_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_type_func_param
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_auto(type);
          if(!ok)return ok;
          dev.go_auto(sep);
          dev.go_auto(cv);
          dev.go_auto(namepart);
          return ok;
        }
      public:
      };
      struct t_expr_func_param:public i_func_param{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_func_param)PARENT(i_func_param)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_expr,body,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_expr_func_param
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_expr_func_param
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_minor<t_type_func_param>(body);
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_fv_stat{
        //===>>===i_fv_body_visitor
        #define DEF_PRO_BLANK()
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
          ADD(t_impl_func_body)\
          ADD(t_zero_func_body)\
          ADD(t_delete_func_body)\
        ADDEND()
        class i_fv_body;
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        class i_fv_body_visitor{
        public:
          typedef t_fv_stat::i_fv_body i_fv_body;
        public:
          #define ADD(TYPE)virtual void Do(TYPE&r)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_fv_stat::U U;//typedef t_fv_stat::U U;
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
          static TYPE*UberCast(i_fv_body*p){
            if(!p)return nullptr;Is<TYPE,i_fv_body_visitor> IS;p->Use(IS);return IS.ptr;
          }
          #else
          template<class TYPE>
          static TYPE*UberCast(i_fv_body*p){return dynamic_cast<TYPE*>(p);}
          #endif
        };
        //struct t_visitor:public i_fv_body_visitor{
        //  void Do(t_impl_func_body&r){}
        //  void Do(t_zero_func_body&r){}
        //  void Do(t_delete_func_body&r){}
        //};
        #undef LIST
        #undef DEF_PRO_BLANK
        //===<<===i_fv_body_visitor
        struct i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_fv_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_fv_body
        public:
          typedef i_fv_body_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
          virtual ~i_fv_body()=default;
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            void load();/*
            {
              F(t_impl_func_body);
              F(t_zero_func_body);
              F(t_delete_func_body);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }*/
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
        //===>>===i_fv_end_visitor
        #define DEF_PRO_BLANK()
        #define LIST(ADDBEG,ADD,ADDEND)\
        ADDBEG()\
          ADD(t_func_fv_end)\
          ADD(t_var_fv_end)\
        ADDEND()
        class i_fv_end;
        #define ADD(TYPE)class TYPE;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
        class i_fv_end_visitor{
        public:
          typedef t_fv_stat::i_fv_end i_fv_end;
        public:
          #define ADD(TYPE)virtual void Do(TYPE&r)=0;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
        public:
          #define ADD(U)typedef t_fv_stat::U U;//typedef t_fv_stat::U U;
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
          static TYPE*UberCast(i_fv_end*p){
            if(!p)return nullptr;Is<TYPE,i_fv_end_visitor> IS;p->Use(IS);return IS.ptr;
          }
          #else
          template<class TYPE>
          static TYPE*UberCast(i_fv_end*p){return dynamic_cast<TYPE*>(p);}
          #endif
        };
        //struct t_visitor:public i_fv_end_visitor{
        //  void Do(t_func_fv_end&r){}
        //  void Do(t_var_fv_end&r){}
        //};
        #undef LIST
        #undef DEF_PRO_BLANK
        //===<<===i_fv_end_visitor
        struct i_fv_end{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>i_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====i_fv_end
        public:
          typedef i_fv_end_visitor i_visitor;
          virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
          virtual ~i_fv_end()=default;
        public:
          virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
          struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
          {
            #include "QapLexPolyBeg.inl"
            void load();/*
            {
              F(t_func_fv_end);
              F(t_var_fv_end);
              (void)count;(void)first_id;(void)out_arr;(void)this;
              main();
              return scope.ok;
            }*/
            #include "QapLexPolyEndNoTemplate.inl"
          };
        };
        struct t_impl_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(t_sep,sep,DEF,$,$)\
        ADDVAR(t_raw_func_body,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_impl_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_impl_func_body
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            dev.go_auto(sep);
            ok=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
        };
        struct t_zero_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_zero_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_zero_func_body
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_const("=0;");
            if(!ok)return ok;
            return ok;
          }
        };
        struct t_delete_func_body:public i_fv_body{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_func_body)PARENT(i_fv_body)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_delete_func_body
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_delete_func_body
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_const("=delete;");
            if(!ok)return ok;
            return ok;
          }
        };
        struct t_func_fv_end:public i_fv_end{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_fv_end)PARENT(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(TAutoPtr<t_func_params>,params,DEF,$,$)\
        ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
        ADDVAR(t_sep,sep1,DEF,$,$)\
        ADDVAR(TAutoPtr<i_fv_body>,body,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_func_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_func_fv_end
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_auto(params);
            if(!ok)return ok;
            dev.go_auto(cv1);
            dev.go_auto(sep1);
            ok=dev.go_auto(body);
            if(!ok)return ok;
            return ok;
          }
        };
        struct t_var_fv_end:public i_fv_end{
          //===>>===i_fv_item_visitor
          #define DEF_PRO_BLANK()
          #define LIST(ADDBEG,ADD,ADDEND)\
          ADDBEG()\
            ADD(t_func_fv_item)\
            ADD(t_var_fv_item)\
          ADDEND()
          class i_fv_item;
          #define ADD(TYPE)class TYPE;
          LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
          #undef ADD
          class i_fv_item_visitor{
          public:
            typedef t_var_fv_end::i_fv_item i_fv_item;
          public:
            #define ADD(TYPE)virtual void Do(TYPE&r)=0;
            LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
            #undef ADD
          public:
            #define ADD(U)typedef t_var_fv_end::U U;//typedef t_var_fv_end::U U;
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
            static TYPE*UberCast(i_fv_item*p){
              if(!p)return nullptr;Is<TYPE,i_fv_item_visitor> IS;p->Use(IS);return IS.ptr;
            }
            #else
            template<class TYPE>
            static TYPE*UberCast(i_fv_item*p){return dynamic_cast<TYPE*>(p);}
            #endif
          };
          //struct t_visitor:public i_fv_item_visitor{
          //  void Do(t_func_fv_item&r){}
          //  void Do(t_var_fv_item&r){}
          //};
          #undef LIST
          #undef DEF_PRO_BLANK
          //===<<===i_fv_item_visitor
          struct i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDEND()
          //=====+>>>>>i_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====i_fv_item
          public:
            typedef i_fv_item_visitor i_visitor;
            virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
            virtual ~i_fv_item()=default;
          public:
            virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
            struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
            {
              #include "QapLexPolyBeg.inl"
              void load();/*
              {
                F(t_func_fv_item);
                F(t_var_fv_item);
                (void)count;(void)first_id;(void)out_arr;(void)this;
                main();
                return scope.ok;
              }*/
              #include "QapLexPolyEndNoTemplate.inl"
            };
          };
          struct t_func_fv_item:public i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_fv_item)PARENT(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<t_func_params>,params,DEF,$,$)\
          ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_func_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_func_fv_item
          public:
            void Use(i_visitor&A){A.Do(*this);}
            static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
          public:
            bool go(i_dev&dev){
              t_fallback $(dev,__FUNCTION__);
              auto&ok=$.ok;
              ok=dev.go_auto(params);
              if(!ok)return ok;
              dev.go_auto(cv1);
              return ok;
            }
          };
          struct t_var_fv_item:public i_fv_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_fv_item)PARENT(i_fv_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<t_arr_body>,arrbody,DEF,$,$)\
          ADDVAR(TAutoPtr<t_func_param_value>,value,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_var_fv_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_var_fv_item
          public:
            void Use(i_visitor&A){A.Do(*this);}
            static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
          public:
            bool go(i_dev&dev){
              t_fallback $(dev,__FUNCTION__);
              auto&ok=$.ok;
              dev.go_auto(arrbody);
              dev.go_auto(value);
              return ok;
            }
          };
          struct t_body{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(TAutoPtr<i_fv_item>,body,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_body
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_body
          public:
            bool go(i_dev&dev){
              t_fallback $(dev,__FUNCTION__);
              auto&ok=$.ok;
              ok=dev.go_auto(body);
              if(!ok)return ok;
              return ok;
            }
          };
          struct t_item{
          #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_fv_end)
          #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
          ADDBEG()\
          ADDVAR(t_sep,sep0,DEF,$,$)\
          ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
          ADDVAR(t_sep,sep1,DEF,$,$)\
          ADDVAR(string,name,DEF,$,$)\
          ADDVAR(t_sep,sep2,DEF,$,$)\
          ADDVAR(t_body,body,DEF,$,$)\
          ADDVAR(t_sep,sep3,DEF,$,$)\
          ADDEND()
          //=====+>>>>>t_item
          #include "QapGenStructNoTemplate.inl"
          //<<<<<+=====t_item
          public:
            bool go(i_dev&dev){
              t_fallback $(dev,__FUNCTION__);
              auto&ok=$.ok;
              ok=dev.go_const(",");
              if(!ok)return ok;
              dev.go_auto(sep0);
              dev.go_auto(cv);
              dev.go_auto(sep1);
              ok=dev.go_str<t_name>(name);
              if(!ok)return ok;
              dev.go_auto(sep2);
              ok=dev.go_auto(body);
              if(!ok)return ok;
              dev.go_auto(sep3);
              return ok;
            }
          };
        #define DEF_PRO_NESTED(F)\
          /*<DEF_PRO_NESTED>*/\
          F(t_func_fv_item)\
          F(t_var_fv_item )\
          F(t_body        )\
          F(t_item        )\
          /*</DEF_PRO_NESTED>*/
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_fv_end)PARENT(i_fv_end)OWNER(t_fv_stat)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDVAR(TAutoPtr<t_body>,body,DEF,$,$)\
        ADDVAR(vector<t_item>,arr,DEF,$,$)\
        ADDEND()
        //=====+>>>>>t_var_fv_end
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_var_fv_end
        public:
          void Use(i_visitor&A){A.Do(*this);}
          static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            dev.go_auto(body);
            dev.go_auto(arr);
            ok=dev.go_const(";");
            if(!ok)return ok;
            return ok;
          }
        public:
        };
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_impl_func_body  )\
        F(t_zero_func_body  )\
        F(t_delete_func_body)\
        F(t_func_fv_end     )\
        F(t_var_fv_end      )\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fv_stat)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep_wa,DEF,$,$)\
      ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
      ADDVAR(TAutoPtr<t_type_expr>,type,DEF,$,$)\
      ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
      ADDVAR(t_name_part,name,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(TAutoPtr<i_fv_end>,way,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_fv_stat
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_fv_stat
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(sep_wa);
          dev.go_auto(keywords);
          ok=dev.go_auto(type);
          if(!ok)return ok;
          dev.go_auto(cv);
          dev.go_auto(sep0);
          dev.go_auto(path);
          ok=dev.go_auto(name);
          if(!ok)return ok;
          dev.go_auto(sep1);
          ok=dev.go_auto(way);
          if(!ok)return ok;
          return ok;
        }
      public:
      };
      struct t_impl_typeexpr:public i_typeexpr{
        struct t_global{
        #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_global)OWNER(t_impl_typeexpr)
        #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
        ADDBEG()\
        ADDEND()
        //=====+>>>>>t_global
        #include "QapGenStructNoTemplate.inl"
        //<<<<<+=====t_global
        public:
          bool go(i_dev&dev){
            t_fallback $(dev,__FUNCTION__);
            auto&ok=$.ok;
            ok=dev.go_const("::");
            if(!ok)return ok;
            return ok;
          }
        };
      #define DEF_PRO_NESTED(F)\
        /*<DEF_PRO_NESTED>*/\
        F(t_global)\
        /*</DEF_PRO_NESTED>*/
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_typeexpr)PARENT(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(TAutoPtr<t_global>,global,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDVAR(t_scopes,scopes,DEF,$,$)\
      ADDVAR(vector<t_ptr>,ptrs,DEF,$,$)\
      ADDVAR(TAutoPtr<t_ref>,ref,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_impl_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_impl_typeexpr
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          dev.go_auto(global);
          dev.go_auto(sep);
          ok=dev.go_auto(scopes);
          if(!ok)return ok;
          dev.go_auto(ptrs);
          dev.go_auto(ref);
          return ok;
        }
      public:
      };
      struct t_decl_typeexpr:public i_typeexpr{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_decl_typeexpr)PARENT(i_typeexpr)OWNER(t_type_expr)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep0,DEF,$,$)\
      ADDVAR(t_sep,sep1,DEF,$,$)\
      ADDVAR(t_expr,expr,DEF,$,$)\
      ADDVAR(t_sep,sep2,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_decl_typeexpr
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_decl_typeexpr
      public:
        void Use(i_visitor&A){A.Do(*this);}
        static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("decltype");
          if(!ok)return ok;
          dev.go_auto(sep0);
          ok=dev.go_const("(");
          if(!ok)return ok;
          dev.go_auto(sep1);
          ok=dev.go_auto(expr);
          if(!ok)return ok;
          dev.go_auto(sep2);
          ok=dev.go_const(")");
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_type_expr_with_sep_and_cv)\
      F(t_name_part                )\
      F(t_arr_body                 )\
      F(t_raw_name_part            )\
      F(t_brackets_name_part       )\
      F(t_func_param_value         )\
      F(t_func_param               )\
      F(t_func_params              )\
      F(t_pfunc                    )\
      F(t_pfunc_func_param         )\
      F(t_var_args_func_param      )\
      F(t_type_func_param          )\
      F(t_expr_func_param          )\
      F(t_fv_stat                  )\
      F(t_impl_typeexpr            )\
      F(t_decl_typeexpr            )\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)OWNER(t_fv_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_typeexpr>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_expr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_type_expr
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_type_expr)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fv_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_type_expr::t_fv_stat,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_fv_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fv_class_stat
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
  struct t_typedef_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_typedef_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_fv_stat,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_typedef_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_typedef_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("typedef");
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_real{
    struct t_f{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_f)OWNER(t_real)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_f
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_f
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr("fF");
        ok=dev.go_any_char(body,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_f)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,bef,DEF,$,$)\
  ADDVAR(string,aft,DEF,$,$)\
  ADDVAR(TAutoPtr<t_f>,ext,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_real
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(bef,g_static_var_0);
      if(!ok)return ok;
      ok=dev.go_const(".");
      if(!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      dev.go_any(aft,g_static_var_2);
      dev.go_auto(ext);
      return ok;
    }
  public:
  };
  struct t_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_expr,expr,DEF,$,$)\
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
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
  };
  struct t_call_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,func,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
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
      ok=dev.go_str<t_name>(func);
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
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
      dev.go_auto(sep0);
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_inl_file)
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_string_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      ok=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_char_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      ok=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_real_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_expr)PARENT(i_expr)OWNER(t_inl_file)
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
      ok=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_nullptr_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullptr_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nullptr_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_nullptr_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_or_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_or_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_name>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_or_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_or_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_hex_expr:public i_expr{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_hex_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,x,DEF,$,$)\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        ok=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        ok=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hex_expr
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
  };
  struct t_var_expr:public i_expr{
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_type_with_sep,body,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_auto(body);
        if(!ok)return ok;
        dev.go_auto(sep);
        ok=dev.go_const("::");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_field{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,bef,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_field
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_field
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(bef);
        ok=dev.go_str<t_name>(name);
        if(!ok)return ok;
        dev.go_auto(aft);
        return ok;
      }
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_var_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_item>,items,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(vector<t_field>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(items);
        dev.go_auto(sep);
        ok=dev.go_vec(arr,".");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item )\
    F(t_field)\
    F(t_impl )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_expr)PARENT(i_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
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
      ok=dev.go_str<t_impl>(name);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_ctor_init_list{
    struct t_init_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_init_param)OWNER(t_ctor_init_list)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(vector<t_call_param>,arr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_init_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_init_param
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_str<t_name>(name);
        if(!ok)return ok;
        ok=dev.go_const("(");
        if(!ok)return ok;
        dev.go_vec(arr,",");
        ok=dev.go_const(")");
        if(!ok)return ok;
        dev.go_auto(sep1);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_init_param)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_init_list)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_init_param>,params,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ctor_init_list
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ctor_init_list
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(":");
      if(!ok)return ok;
      ok=dev.go_vec(params,",");
      if(!ok)return ok;
      dev.go_auto(sep);
      return ok;
    }
  public:
  };
  struct t_zero_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_zero_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_zero_func_body
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("=0;");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_null_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_null_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null_func_body
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_delete_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_delete_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_delete_func_body
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("=delete;");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_impl_func_body:public i_func_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_func_body)PARENT(i_func_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(TAutoPtr<t_ctor_init_list>,init_list,DEF,$,$)\
  ADDVAR(t_raw_func_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl_func_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl_func_body
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      dev.go_auto(init_list);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_dtor_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dtor_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
  ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_dtor_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_dtor_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(path);
      ok=dev.go_const("~");
      if(!ok)return ok;
      dev.go_auto(sep0);
      ok=dev.go_str<t_name>(name);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(params);
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_ctor_class_stat:public i_class_stat{
    struct t_impl{
      struct t_explicit{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_explicit)OWNER(t_impl)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_explicit
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_explicit
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("explicit");
          if(!ok)return ok;
          ok=dev.go_auto(sep);
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_explicit)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_ctor_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_explicit>,prefix,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(prefix);
        dev.go_auto(path);
        ok=dev.go_str<t_name>(name);
        if(!ok)return ok;
        dev.go_auto(concrete_params);
        ok=dev.go_auto(params);
        if(!ok)return ok;
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    public:
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ctor_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ctor_class_stat
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
  struct t_oper_cast_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper_cast_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
  ADDVAR(TAutoPtr<t_const_with_sep>,cv,DEF,$,$)\
  ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper_cast_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper_cast_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(path);
      ok=dev.go_const("operator");
      if(!ok)return ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(type);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_auto(params);
      if(!ok)return ok;
      dev.go_auto(cv);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_common_oper_class_stat:public i_class_stat{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_common_oper_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(TAutoPtr<t_func_path>,path,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(keywords);
        ok=dev.go_auto(type);
        if(!ok)return ok;
        dev.go_auto(cv0);
        dev.go_auto(sep0);
        dev.go_auto(path);
        ok=dev.go_const("operator");
        if(!ok)return ok;
        dev.go_auto(sep1);
        static const auto g_static_var_7=QapStrFinder::fromArr(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
        ok=dev.go_any_str_from_vec(oper,g_static_var_7);
        if(!ok)return ok;
        ok=dev.go_auto(params);
        if(!ok)return ok;
        dev.go_auto(cv1);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_common_oper_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_common_oper_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_common_oper_class_stat
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
  struct t_parents{
    struct t_item{
      struct t_pub{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pub)OWNER(t_item)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_access_mod,mod,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_pub
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_pub
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_auto(mod);
          if(!ok)return ok;
          dev.go_auto(sep);
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_pub)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_parents)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(TAutoPtr<t_pub>,pub,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep);
        dev.go_auto(pub);
        ok=dev.go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
        if(!ok)return ok;
        return ok;
      }
    public:
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_item)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_parents)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_parents
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_parents
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(":");
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_vec(arr,",");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_class_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_body)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_class_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_body
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
  struct t_class{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,keyword,DEF,$,$)\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_parents>,parents,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_class_body>,body,DEF,$,$)\
  ADDVAR(t_sep,sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
      ok=dev.go_any_str_from_vec(keyword,g_static_var_0);
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_str<t_name>(name);
      dev.go_auto(sep1);
      dev.go_auto(parents);
      dev.go_auto(sep2);
      dev.go_auto(body);
      dev.go_auto(sep3);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_namespace_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_namespace_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_class_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_namespace_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_namespace_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("namespace");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_str<t_name>(name);
      dev.go_auto(sep1);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_template_class_stat:public i_class_stat{
    //===>>===i_template_body_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_common_oper_template_body)\
      ADD(t_ctor_template_body)\
      ADD(t_func_template_body)\
      ADD(_template_body)\
    ADDEND()
    class i_template_body;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_template_body_visitor{
    public:
      typedef t_template_class_stat::i_template_body i_template_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_class_stat::U U;//typedef t_template_class_stat::U U;
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
      static TYPE*UberCast(i_template_body*p){
        if(!p)return nullptr;Is<TYPE,i_template_body_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_template_body*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_template_body_visitor{
    //  void Do(t_common_oper_template_body&r){}
    //  void Do(t_ctor_template_body&r){}
    //  void Do(t_func_template_body&r){}
    //  void Do(_template_body&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_template_body_visitor
    struct i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_template_body
    public:
      typedef i_template_body_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_template_body()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_common_oper_template_body);
          F(t_ctor_template_body);
          F(t_func_template_body);
          F(_template_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    //===>>===i_template_param_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_name_template_param)\
      ADD(t_type_template_param)\
    ADDEND()
    class i_template_param;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_template_param_visitor{
    public:
      typedef t_template_class_stat::i_template_param i_template_param;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_template_class_stat::U U;//typedef t_template_class_stat::U U;
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
      static TYPE*UberCast(i_template_param*p){
        if(!p)return nullptr;Is<TYPE,i_template_param_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_template_param*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_template_param_visitor{
    //  void Do(t_name_template_param&r){}
    //  void Do(t_type_template_param&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_template_param_visitor
    struct i_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_template_param
    public:
      typedef i_template_param_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_template_param()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_name_template_param);
          F(t_type_template_param);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,bef,DEF,$,$)\
    ADDVAR(TAutoPtr<i_template_param>,body,DEF,$,$)\
    ADDVAR(t_sep,aft,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_template_param
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(bef);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        dev.go_auto(aft);
        return ok;
      }
    };
    struct t_common_oper_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_common_oper_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_common_oper_class_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_common_oper_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_common_oper_template_body
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
    struct t_ctor_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ctor_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_ctor_class_stat::t_impl,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ctor_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_ctor_template_body
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
    struct t_func_template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_keyword>,keywords,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,func_name,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,concrete_params,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(t_fv_class_stat::t_type_expr::t_func_params,params,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(TAutoPtr<t_const_with_sep>,cv1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_func_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_func_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_func_template_body
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(keywords);
        ok=dev.go_auto(type);
        if(!ok)return ok;
        dev.go_auto(cv0);
        dev.go_auto(sep0);
        ok=dev.go_str<t_name>(func_name);
        if(!ok)return ok;
        dev.go_auto(concrete_params);
        dev.go_auto(sep1);
        ok=dev.go_auto(params);
        if(!ok)return ok;
        dev.go_auto(sep2);
        dev.go_auto(cv1);
        ok=dev.go_auto(body);
        if(!ok)return ok;
        return ok;
      }
    };
    struct _template_body:public i_template_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(_template_body)PARENT(i_template_body)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,keyword,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_concrete_params>,params,DEF,$,$)\
    ADDVAR(TAutoPtr<t_parents>,parents,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(TAutoPtr<t_class_body>,body,DEF,$,$)\
    ADDVAR(t_sep,sep3,DEF,$,$)\
    ADDEND()
    //=====+>>>>>_template_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====_template_body
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("struct,class,union",","));
        ok=dev.go_any_str_from_vec(keyword,g_static_var_0);
        if(!ok)return ok;
        ok=dev.go_auto(sep0);
        if(!ok)return ok;
        dev.go_str<t_name>(name);
        dev.go_auto(sep1);
        dev.go_auto(params);
        dev.go_auto(parents);
        dev.go_auto(sep2);
        dev.go_auto(body);
        dev.go_auto(sep3);
        ok=dev.go_const(";");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_name_template_param:public i_template_param{
      struct t_unsgnd{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_unsgnd)OWNER(t_name_template_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_unsgnd
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_unsgnd
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("unsigned");
          if(!ok)return ok;
          return ok;
        }
      };
      struct t_value{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_name_template_param)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDVAR(t_expr,body,DEF,$,$)\
      ADDVAR(t_sep,sep,DEF,$,$)\
      ADDEND()
      //=====+>>>>>t_value
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_value
      public:
        bool go(i_dev&dev){
          t_fallback $(dev,__FUNCTION__);
          auto&ok=$.ok;
          ok=dev.go_const("=");
          if(!ok)return ok;
          dev.go_auto(sep);
          ok=dev.go_auto(body);
          if(!ok)return ok;
          return ok;
        }
      };
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_unsgnd)\
      F(t_value )\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_template_param)PARENT(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,unsgnd0,DEF,$,$)\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(string,unsgnd1,DEF,$,$)\
    ADDVAR(t_sep,sep2,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep3,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_name_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_name_template_param
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_str<t_unsgnd>(unsgnd0);
        dev.go_auto(sep0);
        ok=dev.go_str<t_name>(type);
        if(!ok)return ok;
        dev.go_auto(sep1);
        dev.go_str<t_unsgnd>(unsgnd1);
        dev.go_auto(sep2);
        dev.go_str<t_name>(name);
        dev.go_auto(sep3);
        dev.go_auto(value);
        return ok;
      }
    public:
    };
    struct t_head{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_head)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(vector<t_template_param>,params,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_head
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_head
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("template");
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_const("<");
        if(!ok)return ok;
        dev.go_vec(params,",");
        ok=dev.go_const(">");
        if(!ok)return ok;
        dev.go_auto(sep1);
        return ok;
      }
    };
    struct t_type_template_param:public i_template_param{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_template_param)PARENT(i_template_param)OWNER(t_template_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_head>,head,DEF,$,$)\
    ADDVAR(string,type,DEF,$,$)\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_type_template_param
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_type_template_param
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(head);
        static const auto g_static_var_1=QapStrFinder::fromArr(split("class,typename",","));
        ok=dev.go_any_str_from_vec(type,g_static_var_1);
        if(!ok)return ok;
        dev.go_auto(sep);
        dev.go_str<t_name>(name);
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_template_param           )\
    F(t_common_oper_template_body)\
    F(t_ctor_template_body       )\
    F(t_func_template_body       )\
    F(_template_body             )\
    F(t_name_template_param      )\
    F(t_head                     )\
    F(t_type_template_param      )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_template_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_head,head,DEF,$,$)\
  ADDVAR(TAutoPtr<i_template_body>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_template_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_template_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(head);
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_enum_class_stat:public i_class_stat{
    //===>>===i_body_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_impl_body)\
      ADD(t_empty_body)\
    ADDEND()
    class i_body;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_body_visitor{
    public:
      typedef t_enum_class_stat::i_body i_body;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_enum_class_stat::U U;//typedef t_enum_class_stat::U U;
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
    //  void Do(t_impl_body&r){}
    //  void Do(t_empty_body&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_body_visitor
    struct i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_body)OWNER(t_enum_class_stat)
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
          F(t_impl_body);
          F(t_empty_body);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(t_expr,expr,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_value
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_value
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("=");
        if(!ok)return ok;
        dev.go_auto(sep0);
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        dev.go_auto(sep1);
        return ok;
      }
    };
    struct t_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(t_sep,sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_item
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        dev.go_auto(sep0);
        ok=dev.go_str<t_name>(name);
        if(!ok)return ok;
        dev.go_auto(sep1);
        dev.go_auto(value);
        return ok;
      }
    };
    struct t_comma_with_sep{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comma_with_sep)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,sep,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_comma_with_sep
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_comma_with_sep
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const(",");
        if(!ok)return ok;
        dev.go_auto(sep);
        return ok;
      }
    };
    struct t_impl_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_body)PARENT(i_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<t_item>,arr,DEF,$,$)\
    ADDVAR(TAutoPtr<t_comma_with_sep>,comma,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl_body
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("{");
        if(!ok)return ok;
        dev.go_vec(arr,",");
        dev.go_auto(comma);
        ok=dev.go_const("}");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_empty_body:public i_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_body)PARENT(i_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_empty_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_empty_body
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
    struct t_body{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_body)OWNER(t_enum_class_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<i_body>,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_body
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_body
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
    F(t_value         )\
    F(t_item          )\
    F(t_comma_with_sep)\
    F(t_impl_body     )\
    F(t_empty_body    )\
    F(t_body          )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_enum_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(string,name,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_body,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_enum_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_enum_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("enum");
      if(!ok)return ok;
      dev.go_auto(sep0);
      dev.go_str<t_name>(name);
      dev.go_auto(sep1);
      dev.go_auto(body);
      return ok;
    }
  public:
  };
  struct t_using_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_using_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_fv_class_stat::t_type_expr,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_using_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_using_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("using");
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_auto(type);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_tmpl_call_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_tmpl_call_param)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_tmpl_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_tmpl_call_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_tmpl_call_param
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(sep1);
      return ok;
    }
  };
  struct t_call_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_call_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,func,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(vector<t_tmpl_call_param>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_call_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_call_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_name>(func);
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_block_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_tmpl_expr,expr,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_block_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_block_tmpl_expr
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
      ok=dev.go_auto(expr);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_pfunc_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pfunc_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_fv_class_stat::t_type_expr::t_pfunc,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pfunc_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_pfunc_concrete_param_way
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_type_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_type_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_type_concrete_param_way
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_expr_concrete_param_way:public i_concrete_param_way{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_concrete_param_way)PARENT(i_concrete_param_way)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_tmpl_expr,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_concrete_param_way
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_expr_concrete_param_way
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_minor<t_type_concrete_param_way>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_bool_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_bool_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_bool_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_string_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_string_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_str_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_char_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_char_item::t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_real_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_real_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_real_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_real_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_real>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_nullptr_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullptr_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_nullptr_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_nullptr_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("nullptr");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_or_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_or_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_name>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_or_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_or_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_bin_oper(arr,"|");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_hex_tmpl_expr:public i_tmpl_expr{
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_hex_tmpl_expr)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,x,DEF,$,$)\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("0");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("xX");
        ok=dev.go_any_char(x,g_static_var_1);
        if(!ok)return ok;
        static const auto g_static_var_2=CharMask::fromStr(gen_dips("09afAF"));
        ok=dev.go_any(value,g_static_var_2);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hex_tmpl_expr
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
  };
  struct t_var_tmpl_expr:public i_tmpl_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_tmpl_expr)PARENT(i_tmpl_expr)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_tmpl_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_tmpl_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_fv_class_stat::t_type_expr>(name);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_pragma_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pragma_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pragma_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_pragma_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#pragma");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_include_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_include_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_include_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_include_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#include");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_preproc_if_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_if_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_if_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_if_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#if");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_preproc_else_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_else_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_else_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_else_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#else");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_preproc_endif_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_preproc_endif_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_preproc_endif_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_preproc_endif_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#endif");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_define_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_define_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_define_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_define_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#define");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_undef_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_undef_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_undef_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_undef_class_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("#undef");
      if(!ok)return ok;
      ok=dev.go_end(body,"\n");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep_class_stat
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
  struct t_null_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null_class_stat
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
  struct t_class_class_stat:public i_class_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_class_stat)PARENT(i_class_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_class,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_class_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_class_stat
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
  struct t_inl_file_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inl_file_stat)OWNER(t_inl_file)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(TAutoPtr<t_class>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_inl_file_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_inl_file_stat
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_lev03                   )\
  F(t_lev05                   )\
  F(t_lev06                   )\
  F(t_lev07                   )\
  F(t_lev08                   )\
  F(t_lev09                   )\
  F(t_lev10                   )\
  F(t_lev11                   )\
  F(t_lev12                   )\
  F(t_lev13                   )\
  F(t_lev14                   )\
  F(t_expr                    )\
  F(t_tmpl_lev03              )\
  F(t_tmpl_lev05              )\
  F(t_tmpl_lev06              )\
  F(t_tmpl_lev09              )\
  F(t_tmpl_lev10              )\
  F(t_tmpl_lev11              )\
  F(t_tmpl_lev12              )\
  F(t_tmpl_lev13              )\
  F(t_tmpl_lev14              )\
  F(t_tmpl_expr               )\
  F(t_concrete_param          )\
  F(t_concrete_params         )\
  F(t_access_mod              )\
  F(t_access_mod_class_stat   )\
  F(t_raw_func_body           )\
  F(t_func_path               )\
  F(t_const_with_sep          )\
  F(t_keyword                 )\
  F(t_ptr                     )\
  F(t_ref                     )\
  F(t_type_with_sep           )\
  F(t_scope_with_sep          )\
  F(t_scopes                  )\
  F(t_fv_class_stat           )\
  F(t_typedef_class_stat      )\
  F(t_real                    )\
  F(t_call_param              )\
  F(t_call_expr               )\
  F(t_block_expr              )\
  F(t_bool_expr               )\
  F(t_string_expr             )\
  F(t_char_expr               )\
  F(t_num_expr                )\
  F(t_real_expr               )\
  F(t_nullptr_expr            )\
  F(t_or_expr                 )\
  F(t_hex_expr                )\
  F(t_var_expr                )\
  F(t_ctor_init_list          )\
  F(t_zero_func_body          )\
  F(t_null_func_body          )\
  F(t_delete_func_body        )\
  F(t_impl_func_body          )\
  F(t_dtor_class_stat         )\
  F(t_ctor_class_stat         )\
  F(t_oper_cast_class_stat    )\
  F(t_common_oper_class_stat  )\
  F(t_parents                 )\
  F(t_class_body              )\
  F(t_class                   )\
  F(t_namespace_class_stat    )\
  F(t_template_class_stat     )\
  F(t_enum_class_stat         )\
  F(t_using_class_stat        )\
  F(t_tmpl_call_param         )\
  F(t_call_tmpl_expr          )\
  F(t_block_tmpl_expr         )\
  F(t_pfunc_concrete_param_way)\
  F(t_type_concrete_param_way )\
  F(t_expr_concrete_param_way )\
  F(t_bool_tmpl_expr          )\
  F(t_string_tmpl_expr        )\
  F(t_char_tmpl_expr          )\
  F(t_num_tmpl_expr           )\
  F(t_real_tmpl_expr          )\
  F(t_nullptr_tmpl_expr       )\
  F(t_or_tmpl_expr            )\
  F(t_hex_tmpl_expr           )\
  F(t_var_tmpl_expr           )\
  F(t_pragma_class_stat       )\
  F(t_include_class_stat      )\
  F(t_preproc_if_class_stat   )\
  F(t_preproc_else_class_stat )\
  F(t_preproc_endif_class_stat)\
  F(t_define_class_stat       )\
  F(t_undef_class_stat        )\
  F(t_sep_class_stat          )\
  F(t_null_class_stat         )\
  F(t_class_class_stat        )\
  F(t_inl_file_stat           )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_inl_file)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_class_stat>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_inl_file
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_inl_file
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
public:
};
void t_inl_file::i_class_stat::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_access_mod_class_stat);
  F(t_fv_class_stat);
  F(t_typedef_class_stat);
  F(t_dtor_class_stat);
  F(t_ctor_class_stat);
  F(t_oper_cast_class_stat);
  F(t_common_oper_class_stat);
  F(t_namespace_class_stat);
  F(t_template_class_stat);
  F(t_enum_class_stat);
  F(t_using_class_stat);
  F(t_pragma_class_stat);
  F(t_include_class_stat);
  F(t_preproc_if_class_stat);
  F(t_preproc_else_class_stat);
  F(t_preproc_endif_class_stat);
  F(t_define_class_stat);
  F(t_undef_class_stat);
  F(t_sep_class_stat);
  F(t_null_class_stat);
  F(t_class_class_stat);
  #undef F
  main();
}
void t_inl_file::i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_call_expr);
  F(t_block_expr);
  F(t_bool_expr);
  F(t_string_expr);
  F(t_char_expr);
  F(t_num_expr);
  F(t_real_expr);
  F(t_nullptr_expr);
  F(t_or_expr);
  F(t_hex_expr);
  F(t_var_expr);
  #undef F
  main();
}
void t_inl_file::i_func_body::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_zero_func_body);
  F(t_null_func_body);
  F(t_delete_func_body);
  F(t_impl_func_body);
  #undef F
  main();
}
void t_inl_file::i_tmpl_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_call_tmpl_expr);
  F(t_block_tmpl_expr);
  F(t_bool_tmpl_expr);
  F(t_string_tmpl_expr);
  F(t_char_tmpl_expr);
  F(t_num_tmpl_expr);
  F(t_real_tmpl_expr);
  F(t_nullptr_tmpl_expr);
  F(t_or_tmpl_expr);
  F(t_hex_tmpl_expr);
  F(t_var_tmpl_expr);
  #undef F
  main();
}
void t_inl_file::i_concrete_param_way::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_pfunc_concrete_param_way);
  F(t_type_concrete_param_way);
  F(t_expr_concrete_param_way);
  #undef F
  main();
}
void t_inl_file::t_raw_func_body::i_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_sep_item);
  F(t_s_item);
  F(t_c_item);
  F(t_code_item);
  F(t_div_item);
  F(t_block_item);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_name_part::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_raw_name_part);
  F(t_brackets_name_part);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_func_param::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_pfunc_func_param);
  F(t_var_args_func_param);
  F(t_type_func_param);
  F(t_expr_func_param);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::i_typeexpr::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_impl_typeexpr);
  F(t_decl_typeexpr);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_brackets_name_part::i_part::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_amp_part);
  F(t_star_part);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_body::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_impl_func_body);
  F(t_zero_func_body);
  F(t_delete_func_body);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::i_fv_end::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_func_fv_end);
  F(t_var_fv_end);
  #undef F
  main();
}
void t_inl_file::t_fv_class_stat::t_type_expr::t_fv_stat::t_var_fv_end::i_fv_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_func_fv_item);
  F(t_var_fv_item);
  #undef F
  main();
}
void t_inl_file::t_template_class_stat::i_template_body::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_common_oper_template_body);
  F(t_ctor_template_body);
  F(t_func_template_body);
  F(_template_body);
  #undef F
  main();
}
void t_inl_file::t_template_class_stat::i_template_param::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_name_template_param);
  F(t_type_template_param);
  #undef F
  main();
}
void t_inl_file::t_enum_class_stat::i_body::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_impl_body);
  F(t_empty_body);
  #undef F
  main();
}
/*
//list of types:
F(t_inl_file)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5finl%5ffile%7b%0a%20%20t%5flev03%7b%0a%20%20%20%20string%20oper%3b%0a%20%20%2
0%20TAutoPtr%3ci%5fexpr%3e%20expr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%
3dgo%5fany%5fstr%5ffrom%5fvec%28oper%2csplit%28%22%26%2c%2a%2c%2b%2c%2d%2c%21%2c
%7e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a
%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev05%7b%0a%20%20%20%20t%5foper%7b%0a%20
%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20
%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%2a%2c%2f%2c%25%22%2c%22%2c%
22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%
0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev03%20expr%3b%0
a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20
%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%
7d%0a%20%20%20%20t%5flev03%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b
%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20
%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5f
lev06%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%2
0%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2
csplit%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%2
0%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%2
0%20%20%20%20t%5flev05%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20
%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20
%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev05%20expr%3b%0a%20%20%
20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3d
go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20
%20%20%7d%0a%20%20%7d%0a%20%20t%5flev07%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20
%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%
5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%3c%3c%2c%3e%3e%22%2c%22%2c%22%29%
29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%
20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev06%20expr%3b%0a%20%2
0%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20
%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%
20%20%20%20t%5flev06%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20
%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20
%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev08%
7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%2
0%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit
%28%22%3c%2c%3c%3d%2c%3e%2c%3e%3d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7
d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20ope
r%3b%0a%20%20%20%20%20%20t%5flev07%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20
%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr
%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev07%20expr%
3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%
20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29
%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev09%7b%0a%20%20%20%20t%5foper%7b
%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20
%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%3d%3d%2c%21%3d%22%2c%
22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fit
em%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev08%20exp
r%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a
%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%
20%20%7d%0a%20%20%20%20t%5flev08%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20
arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20
%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%
20t%5flev10%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0
a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28v
alue%2csplit%28%22%26%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%2
0%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%2
0%20%20%20%20t%5flev09%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20
%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20
%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev09%20expr%3b%0a%20%20%
20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3d
go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20
%20%20%7d%0a%20%20%7d%0a%20%20t%5flev11%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20
%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%
5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%5e%22%2c%22%2c%22%29%29%3b%0a%20%
20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%
20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev10%20expr%3b%0a%20%20%20%20%20%2
0%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20
go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t
%5flev10%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b
%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo
%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev12%7b%0a%20%20%
20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0
a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%7c%22
%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%
5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev11%2
0expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3
b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20
%20%20%20%7d%0a%20%20%20%20t%5flev11%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3
e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0
a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a
%20%20t%5flev13%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%
3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec
%28value%2csplit%28%22%26%26%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%
20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%
0a%20%20%20%20%20%20t%5flev12%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%2
0%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3
b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5flev12%20expr%3b%0a
%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20
M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0
a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5flev14%7b%0a%20%20%20%20t%5foper%7b%0a%2
0%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%2
0%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%7c%7c%22%2c%22%2c%22%29%29
%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20
%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5flev13%20expr%3b%0a%20%20%
20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%2
0%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20
%20%20%20t%5flev13%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%2
0%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%2
0O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fexpr%7bt
%5flev14%20body%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20t%5ftmpl%5flev03%7b%0a
%20%20%20%20string%20oper%3b%0a%20%20%20%20TAutoPtr%3ci%5ftmpl%5fexpr%3e%20expr%
3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fany%5fstr%5ffrom%5fvec%28op
er%2csplit%28%22%26%2c%2a%2c%2b%2c%2d%2c%21%2c%7e%22%2c%22%2c%22%29%29%3b%0a%20%
20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%
20t%5ftmpl%5flev05%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20val
ue%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5f
vec%28value%2csplit%28%22%2a%2c%2f%2c%25%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%
20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5fope
r%20oper%3b%0a%20%20%20%20%20%20t%5ftmpl%5flev03%20expr%3b%0a%20%20%20%20%20%20%
7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go
%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5
ftmpl%5flev03%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%
20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b
%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5flev06%
7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%2
0%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit
%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7
d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%2
0%20%20t%5ftmpl%5flev05%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%2
0%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%2
0%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftmpl%5flev05%20expr%3b%0
a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%2
0M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%
0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5flev09%7b%0a%20%20%20%20t%5foper
%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20
%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%3d%3d%2c%21%3d%22%
2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5
fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5ftmpl%5fl
ev06%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28ope
r%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d
%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftmpl%5flev06%20expr%3b%0a%20%20%20%20vector
%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%2
8expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0
a%20%20%7d%0a%20%20t%5ftmpl%5flev10%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%
20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fan
y%5fstr%5ffrom%5fvec%28value%2csplit%28%22%26%22%2c%22%2c%22%29%29%3b%0a%20%20%2
0%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%
5foper%20oper%3b%0a%20%20%20%20%20%20t%5ftmpl%5flev09%20expr%3b%0a%20%20%20%20%2
0%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20
%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%
20t%5ftmpl%5flev09%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%2
0%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%2
0O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5fl
ev11%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20
%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2c
split%28%22%5e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d
%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20
%20%20t%5ftmpl%5flev10%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20
%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20
%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftmpl%5flev10%20expr%3b%0a
%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20
M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0
a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5flev12%7b%0a%20%20%20%20t%5foper%
7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%
20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%22%7c%22%2c%22%2c%22%2
9%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%2
0%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t%5ftmpl%5flev11%20expr%3
b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20
%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%
20%7d%0a%20%20%20%20t%5ftmpl%5flev11%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3
e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0
a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a
%20%20t%5ftmpl%5flev13%7b%0a%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%2
0value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffro
m%5fvec%28value%2csplit%28%22%26%26%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20
%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20o
per%3b%0a%20%20%20%20%20%20t%5ftmpl%5flev12%20expr%3b%0a%20%20%20%20%20%20%7b%0a
%20%20%20%20%20%20%20%20go%5fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fau
to%28expr%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftmpl
%5flev12%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b
%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo
%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5flev14%7b%0a
%20%20%20%20t%5foper%7b%0a%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%20%
20%7b%0a%20%20%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%28%2
2%7c%7c%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%
20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5foper%20oper%3b%0a%20%20%20%20%20%20t
%5ftmpl%5flev13%20expr%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5
fauto%28oper%29%3b%0a%20%20%20%20%20%20%20%20go%5fauto%28expr%29%3b%0a%20%20%20%
20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftmpl%5flev13%20expr%3b%0a%20%20%
20%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3d
go%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20
%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5fexpr%7bt%5ftmpl%5flev14%20body%3b%7bgo%
5fauto%28body%29%3b%7d%7d%0a%20%20t%5fconcrete%5fparam%7b%0a%20%20%20%20t%5fsep%
20sep0%3b%0a%20%20%20%20TAutoPtr%3ci%5fconcrete%5fparam%5fway%3e%20body%3b%0a%20
%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5faut
o%28sep0%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%
20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fcon
crete%5fparams%7b%0a%20%20%20%20vector%3ct%5fconcrete%5fparam%3e%20arr%3b%0a%20%
20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst
%28%22%3c%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fvec%28arr%2c%22%2c%22%29%3b%0
a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3e%22%29%3b%0a%20%20%20%20%20%20O%2b%
3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5faccess%5fmod%7
bstring%20keyword%3b%7bgo%5fany%5fstr%5ffrom%5fvec%28keyword%2csplit%28%22public
%2cprotected%2cprivate%22%2c%22%2c%22%29%29%3b%7d%7d%0a%20%20t%5faccess%5fmod%5f
class%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20t%5faccess%5fmod%20mod%3b%0a
%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fa
uto%28mod%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%
20%20M%2b%3dgo%5fconst%28%22%3a%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t
%5fraw%5ffunc%5fbody%7b%0a%20%20%20%20t%5fsep%5fitem%3d%3ei%5fitem%7bt%5fsep%20s
ep%3b%7bgo%5fauto%28sep%29%3b%7d%7d%0a%20%20%20%20t%5fs%5fitem%3d%3ei%5fitem%7bs
tring%20value%3b%7bgo%5fstr%3ct%5fstr%5fitem%3a%3at%5fimpl%3e%28value%29%3b%7d%7
d%0a%20%20%20%20t%5fc%5fitem%3d%3ei%5fitem%7bstring%20value%3b%7bgo%5fstr%3ct%5f
char%5fitem%3a%3at%5fimpl%3e%28value%29%3b%7d%7d%0a%20%20%20%20t%5fcode%5fitem%3
d%3ei%5fitem%7bstring%20code%3b%7bgo%5fany%28code%2cgen%5fdips%28%22AZaz09%22%29
%2b%22%2b%2d%2a%3f%3c%3e%5b%5d%28%29%2c%2e%3a%3b%7e%21%40%23%24%5f%3d%25%5e%26%5
c%5c%7c%22%29%3b%7d%7d%0a%20%20%20%20t%5fdiv%5fitem%3d%3ei%5fitem%7b%7bgo%5fcons
t%28%22%2f%22%29%3b%7d%7d%0a%20%20%20%20t%5fblock%5fitem%3d%3ei%5fitem%7bTAutoPt
r%3ct%5fraw%5ffunc%5fbody%3e%20body%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20%2
0%20t%5fsep%20sep%3b%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fitem%3e%3e%20arr%3b%0
a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%29%3b%0a%20%2
0%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%
28%22%7d%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ffunc%5fpath%7b%0a%20
%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20%20%20string%20value%3b%0a%20%20%20%20%
20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%2
0%7b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28value%29%3b%0a%20
%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20%20%20M%2
b%3dgo%5fconst%28%22%3a%3a%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%2
8sep1%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20vector%3ct%5
fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28arr%29%3b%0a
%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fconst%5fwith%5fsep%7bt%5fsep%20sep%3bstr
ing%20keyword%3b%7bO%2b%3dgo%5fauto%28sep%29%3bM%2b%3dgo%5fany%5fstr%5ffrom%5fve
c%28keyword%2csplit%28%22typename%2cconst%2cunsigned%22%2c%22%2c%22%29%29%3b%7d%
7d%0a%20%20t%5fkeyword%7b%0a%20%20%20%20string%20keyword%3b%0a%20%20%20%20t%5fse
p%20sep%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fany%5fstr%5ffrom%5f
vec%28keyword%2csplit%28%22friend%2ctypename%2cextern%2cexplicit%2cconstexpr%2cv
irtual%2cconst%2cstatic%2cinline%2cunsigned%22%2c%22%2c%22%29%29%3b%0a%20%20%20%
20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fp
tr%7b%0a%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv%3b%0a%20%20%20%20t
%5fsep%20sep%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv%29%3
b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20M%2b%3dgo
%5fconst%28%22%2a%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fref%7b%0a%2
0%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv%3b%0a%20%20%20%20t%5fsep%20s
ep%3b%0a%20%20%20%20string%20ref%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3
dgo%5fauto%28cv%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%
20%20%20%20M%2b%3dgo%5fany%5fstr%5ffrom%5fvec%28ref%2csplit%28%22%26%26%2c%26%22
%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftype%5fwith%5fse
p%7b%0a%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20string%20name%3b%0a%20%20%20%2
0TAutoPtr%3ct%5fconcrete%5fparams%3e%20concrete%5fparams%3b%0a%20%20%20%20%7b%0a
%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fs
tr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28concrete%5f
params%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fscope%5fwith%5fsep%7bt%5f
sep%20sep%3b%7bO%2b%3dgo%5fauto%28sep%29%3bM%2b%3dgo%5fconst%28%22%3a%3a%22%29%3
b%7d%7d%0a%20%20t%5fscopes%7b%0a%20%20%20%20t%5fitem%7bt%5fscope%5fwith%5fsep%20
sws%3bt%5ftype%5fwith%5fsep%20body%3b%7bgo%5fauto%28sws%29%3bgo%5fauto%28body%29
%3b%7d%7d%0a%20%20%20%20t%5ftype%5fwith%5fsep%20first%3b%0a%20%20%20%20vector%3c
t%5fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28fi
rst%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%
20%20%7d%0a%20%20t%5ffv%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20t%
5ftype%5fexpr%7b%0a%20%20%20%20%20%20t%5ftype%5fexpr%5fwith%5fsep%5fand%5fcv%7b%
0a%20%20%20%20%20%20%20%20vector%3ct%5fconst%5fwith%5fsep%3e%20cvs%3b%0a%20%20%2
0%20%20%20%20%20TAutoPtr%3ct%5ftype%5fexpr%3e%20body%3b%0a%20%20%20%20%20%20%20%
20%7b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cvs%29%3b%0a%20%20%20%2
0%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20%7d%0
a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5fname%5fpart%7bTAutoPtr%3ci%5fname
%5fpart%3e%20body%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20%20%20t%5farr%
5fbody%7b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20%20%20
t%5fsep%20sep1%3b%0a%20%20%20%20%20%20%20%20t%5fexpr%20expr%3b%0a%20%20%20%20%20
%20%20%20t%5fsep%20sep2%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep3%3b%0a%20%20%
20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%
3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%5b%22%29%3b%0a%20%20%
20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%20%20%
20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fa
uto%28sep2%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%5d%22%2
9%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep3%29%3b%0a%20%20%20%2
0%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5fraw%5fname%5fpa
rt%3d%3ei%5fname%5fpart%7bstring%20name%3b%7bgo%5fstr%3ct%5fname%3e%28name%29%3b
%7d%7d%0a%20%20%20%20%20%20t%5fbrackets%5fname%5fpart%3d%3ei%5fname%5fpart%7b%0a
%20%20%20%20%20%20%20%20t%5famp%7bstring%20body%3b%7bgo%5fany%5fstr%5ffrom%5fvec
%28body%2csplit%28%22%26%2c%26%26%22%2c%22%2c%22%29%29%3b%7d%7d%0a%20%20%20%20%2
0%20%20%20t%5famp%5fpart%3d%3ei%5fpart%7bt%5famp%20body%3b%7bgo%5fauto%28body%29
%3b%7d%7d%0a%20%20%20%20%20%20%20%20t%5fstar%5fpart%3d%3ei%5fpart%7bstring%20sta
rs%3bTAutoPtr%3ct%5famp%3e%20amp%3b%7bM%2b%3dgo%5fany%28stars%2c%22%2a%22%29%3bO
%2b%3dgo%5fauto%28amp%29%3b%7d%7d%0a%20%20%20%20%20%20%20%20TAutoPtr%3ci%5fpart%
3e%20stamp%5fpart%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%2
0%20%20%20TAutoPtr%3ct%5fname%5fpart%3e%20namepart%3b%0a%20%20%20%20%20%20%20%20
TAutoPtr%3ct%5farr%5fbody%3e%20arrbody%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20
%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20
%20%20%20%20M%2b%3dgo%5fauto%28stamp%5fpart%29%3b%0a%20%20%20%20%20%20%20%20%20%
20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%
28namepart%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%2
9%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28arrbody%29%3b%0a%20%20%2
0%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5ffunc%5fparam
%5fvalue%7b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%20%20%20%2
0t%5fexpr%20value%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20
%20M%2b%3dgo%5fconst%28%22%3d%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo
%5fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28value%29%
3b%0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5
ffunc%5fparam%7b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%2
0%20%20TAutoPtr%3ci%5ffunc%5fparam%3e%20body%3b%0a%20%20%20%20%20%20%20%20t%5fse
p%20sep1%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5ffunc%5fparam%5fvalue%3e%20v
alue%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep2%3b%0a%20%20%20%20%20%20%20%20%7
b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%2
0%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%
2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28v
alue%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%2
0%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5ffunc%5fpa
rams%7b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%20%20%20%20vec
tor%3ct%5ffunc%5fparam%3e%20arr%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%
20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%
2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fve
c%28arr%2c%22%2c%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%2
2%29%22%29%3b%0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%
20%20%20t%5fpfunc%7b%0a%20%20%20%20%20%20%20%20t%5faddr%7b%0a%20%20%20%20%20%20%
20%20%20%20t%5ftype%5fexpr%5fwith%5fsep%5fand%5fcv%20type%3b%0a%20%20%20%20%20%2
0%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28type%2
9%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3a%3a%22%29%3
b%0a%20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%
20%20%20%20%20t%5ftype%5fexpr%5fwith%5fsep%5fand%5fcv%20type%3b%0a%20%20%20%20%2
0%20%20%20t%5faddr%20addr%3b%0a%20%20%20%20%20%20%20%20string%20name%3b%0a%20%20
%20%20%20%20%20%20t%5ffunc%5fparams%20params%3b%0a%20%20%20%20%20%20%20%20%7b%0a
%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28type%29%3b%0a%20%20%20%20%20%20
%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20
O%2b%3dgo%5fauto%28addr%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%
28%22%2a%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%
28name%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b
%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20%
20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5fpfunc%5ffunc%5fpa
ram%3d%3ei%5ffunc%5fparam%7bt%5fpfunc%20value%3b%7bgo%5fauto%28value%29%3b%7d%7d
%0a%20%20%20%20%20%20t%5fvar%5fargs%5ffunc%5fparam%3d%3ei%5ffunc%5fparam%7b%7bgo
%5fconst%28%22%2e%2e%2e%22%29%3b%7d%7d%0a%20%20%20%20%20%20t%5ftype%5ffunc%5fpar
am%3d%3ei%5ffunc%5fparam%7b%0a%20%20%20%20%20%20%20%20t%5fconst%7bt%5fsep%20sep%
3b%7bM%2b%3dgo%5fconst%28%22const%22%29%3bO%2b%3dgo%5fauto%28sep%29%3b%7d%7d%0a%
20%20%20%20%20%20%20%20t%5ftype%5fexpr%5fwith%5fsep%5fand%5fcv%20type%3b%0a%20%2
0%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fcon
st%3e%20cv%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fname%5fpart%3e%20namepart
%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fau
to%28type%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%
20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv%29%3b%0a%20%20%20%20%20%20%20
%20%20%20O%2b%3dgo%5fauto%28namepart%29%3b%0a%20%20%20%20%20%20%20%20%7d%0a%20%2
0%20%20%20%20%7d%0a%20%20%20%20%20%20t%5fexpr%5ffunc%5fparam%3d%3ei%5ffunc%5fpar
am%7bt%5fexpr%20body%3b%7bgo%5fminor%3ct%5ftype%5ffunc%5fparam%3e%28body%29%3b%7
d%7d%0a%20%20%20%20%20%20t%5ffv%5fstat%7b%0a%20%20%20%20%20%20%20%20t%5fimpl%5ff
unc%5fbody%3d%3ei%5ffv%5fbody%7bt%5fsep%20sep%3bt%5fraw%5ffunc%5fbody%20body%3b%
7bO%2b%3dgo%5fauto%28sep%29%3bM%2b%3dgo%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20
%20%20%20%20t%5fzero%5ffunc%5fbody%3d%3ei%5ffv%5fbody%7b%7bgo%5fconst%28%22%3d0%
3b%22%29%3b%7d%7d%0a%20%20%20%20%20%20%20%20t%5fdelete%5ffunc%5fbody%3d%3ei%5ffv
%5fbody%7b%7bgo%5fconst%28%22%3ddelete%3b%22%29%3b%7d%7d%0a%20%20%20%20%20%20%20
%20t%5ffunc%5ffv%5fend%3d%3ei%5ffv%5fend%7b%0a%20%20%20%20%20%20%20%20%20%20TAut
oPtr%3ct%5ffunc%5fparams%3e%20params%3b%0a%20%20%20%20%20%20%20%20%20%20TAutoPtr
%3ct%5fconst%5fwith%5fsep%3e%20cv1%3b%0a%20%20%20%20%20%20%20%20%20%20t%5fsep%20
sep1%3b%0a%20%20%20%20%20%20%20%20%20%20TAutoPtr%3ci%5ffv%5fbody%3e%20body%3b%0a
%20%20%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dg
o%5fauto%28params%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%2
8cv1%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0
a%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%2
0%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20t
%5fvar%5ffv%5fend%3d%3ei%5ffv%5fend%7b%0a%20%20%20%20%20%20%20%20%20%20t%5ffunc%
5ffv%5fitem%3d%3ei%5ffv%5fitem%7b%0a%20%20%20%20%20%20%20%20%20%20%20%20TAutoPtr
%3ct%5ffunc%5fparams%3e%20params%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20TAutoP
tr%3ct%5fconst%5fwith%5fsep%3e%20cv1%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20%7
b%0a%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28params%29%3b%0a
%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv1%29%3b%0a%20%20%
20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20
%20%20%20%20%20%20%20t%5fvar%5ffv%5fitem%3d%3ei%5ffv%5fitem%7b%0a%20%20%20%20%20
%20%20%20%20%20%20%20TAutoPtr%3ct%5farr%5fbody%3e%20arrbody%3b%0a%20%20%20%20%20
%20%20%20%20%20%20%20TAutoPtr%3ct%5ffunc%5fparam%5fvalue%3e%20value%3b%0a%20%20%
20%20%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2
b%3dgo%5fauto%28arrbody%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3
dgo%5fauto%28value%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20%2
0%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20%20%20t%5fbody%7bTAutoPtr%3ci%5
ffv%5fitem%3e%20body%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20%20%20%20%2
0%20%20t%5fitem%7b%0a%20%20%20%20%20%20%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20
%20%20%20%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv%3b%0a
%20%20%20%20%20%20%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%20%20%20
%20%20%20%20string%20name%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20t%5fsep%20sep
2%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20t%5fbody%20body%3b%0a%20%20%20%20%20%
20%20%20%20%20%20%20t%5fsep%20sep3%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20%7b%
0a%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%2c%22%29%3b%
0a%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%
20%20%20%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv%29%3b%0a%20%20%20%20
%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20
%20%20%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%2
0%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20%20%20%20%2
0%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%2
0%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep3%29%3b%0a%20%20%20%20%20%20%20%20%20%2
0%20%20%7d%0a%20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%20%20%20T
AutoPtr%3ct%5fbody%3e%20body%3b%0a%20%20%20%20%20%20%20%20%20%20vector%3ct%5fite
m%3e%20arr%3b%0a%20%20%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%
20%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20O%2b
%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst
%28%22%3b%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%20%2
0%7d%0a%20%20%20%20%20%20%20%20t%5fsep%20sep%5fwa%3b%0a%20%20%20%20%20%20%20%20v
ector%3ct%5fkeyword%3e%20keywords%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fty
pe%5fexpr%3e%20type%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fs
ep%3e%20cv%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20%2
0%20TAutoPtr%3ct%5ffunc%5fpath%3e%20path%3b%0a%20%20%20%20%20%20%20%20t%5fname%5
fpart%20name%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%20
%20%20TAutoPtr%3ci%5ffv%5fend%3e%20way%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20
%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%5fwa%29%3b%0a%20%20%20%20%20%20%2
0%20%20%20O%2b%3dgo%5fauto%28keywords%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b
%3dgo%5fauto%28type%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv%
29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%
20%20%20%20%20%20%20O%2b%3dgo%5fauto%28path%29%3b%0a%20%20%20%20%20%20%20%20%20%
20M%2b%3dgo%5fauto%28name%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto
%28sep1%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28way%29%3b%0a%20
%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20t%5fimpl%5f
typeexpr%3d%3ei%5ftypeexpr%7b%0a%20%20%20%20%20%20%20%20t%5fglobal%7b%7bM%2b%3dg
o%5fconst%28%22%3a%3a%22%29%3b%7d%7d%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fgl
obal%3e%20global%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%20
%20%20%20t%5fscopes%20scopes%3b%0a%20%20%20%20%20%20%20%20vector%3ct%5fptr%3e%20
ptrs%3b%0a%20%20%20%20%20%20%20%20TAutoPtr%3ct%5fref%3e%20ref%3b%0a%20%20%20%20%
20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28global%29%3b%0
a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20
%20%20%20%20M%2b%3dgo%5fauto%28scopes%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b
%3dgo%5fauto%28ptrs%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28ref
%29%3b%0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%2
0t%5fdecl%5ftypeexpr%3d%3ei%5ftypeexpr%7b%0a%20%20%20%20%20%20%20%20t%5fsep%20se
p0%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%20%20%20t%5f
expr%20expr%3b%0a%20%20%20%20%20%20%20%20t%5fsep%20sep2%3b%0a%20%20%20%20%20%20%
20%20%7b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22decltype%22%29%3
b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%2
0%20%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20%20%20%2
0%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fau
to%28expr%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a
%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%20%20
%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20TAutoPtr%3ci%5ftypee
xpr%3e%20body%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fauto%28b
ody%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftype%5fexp
r%3a%3at%5ffv%5fstat%20body%3b%0a%20%20%20%20%7bgo%5fauto%28body%29%3b%7d%0a%20%
20%7d%0a%20%20t%5ftypedef%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20
t%5fsep%20sep%3b%0a%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%3a%3at
%5ffv%5fstat%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%2
8%22typedef%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%2
0%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%
5freal%7b%0a%20%20%20%20t%5ff%7bchar%20body%3b%7bgo%5fany%5fchar%28body%2c%22fF%
22%29%3b%7d%7d%0a%20%20%20%20string%20bef%3b%0a%20%20%20%20string%20aft%3b%0a%20
%20%20%20TAutoPtr%3ct%5ff%3e%20ext%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b
%3dgo%5fany%28bef%2cgen%5fdips%28%2209%22%29%29%3b%0a%20%20%20%20%20%20M%2b%3dgo
%5fconst%28%22%2e%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fany%28aft%2cgen%5fdip
s%28%2209%22%29%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28ext%29%3b%0a%20%20%
20%20%7d%0a%20%20%7d%0a%20%20t%5fcall%5fparam%7b%0a%20%20%20%20t%5fsep%20sep0%3b
%0a%20%20%20%20t%5fexpr%20expr%3b%0a%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20
%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20M%2b%3
dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%
20%20%20%7d%0a%20%20%7d%0a%20%20t%5fcall%5fexpr%3d%3ei%5fexpr%7b%0a%20%20%20%20s
tring%20func%3b%0a%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20vector%3ct%5fcall%5
fparam%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fn
ame%3e%28func%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20
%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fvec
%28arr%2c%22%2c%22%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b
%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fblock%5fexpr%3d%3ei%5fexpr%7b%0a%20%2
0%20%20t%5fsep%20sep0%3b%0a%20%20%20%20t%5fexpr%20expr%3b%0a%20%20%20%20t%5fsep%
20sep1%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29
%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20M%2b%3
dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%
20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%
0a%20%20t%5fbool%5fexpr%3d%3ei%5fexpr%7bstring%20value%3b%7bgo%5fany%5fstr%5ffro
m%5fvec%28value%2csplit%28%22false%2ctrue%22%2c%22%2c%22%29%29%3b%7d%7d%0a%20%20
t%5fstring%5fexpr%3d%3ei%5fexpr%7bstring%20value%3b%7bgo%5fstr%3ct%5fstr%5fitem%
3a%3at%5fimpl%3e%28value%29%3b%7d%7d%0a%20%20t%5fchar%5fexpr%3d%3ei%5fexpr%7bstr
ing%20value%3b%7bgo%5fstr%3ct%5fchar%5fitem%3a%3at%5fimpl%3e%28value%29%3b%7d%7d
%0a%20%20t%5fnum%5fexpr%3d%3ei%5fexpr%7bstring%20value%3b%7bgo%5fany%28value%2cg
en%5fdips%28%2209%22%29%29%3b%7d%7d%0a%20%20t%5freal%5fexpr%3d%3ei%5fexpr%7bstri
ng%20value%3b%7bgo%5fstr%3ct%5freal%3e%28value%29%3b%7d%7d%0a%20%20t%5fnullptr%5
fexpr%3d%3ei%5fexpr%7b%7bgo%5fconst%28%22nullptr%22%29%3b%7d%7d%0a%20%20t%5for%5
fexpr%3d%3ei%5fexpr%7bvector%3ct%5fname%3e%20arr%3b%7bgo%5fbin%5foper%28arr%2c%2
2%7c%22%29%3b%7d%7d%0a%20%20t%5fhex%5fexpr%3d%3ei%5fexpr%7bt%5fimpl%7bchar%20x%3
bstring%20value%3b%7bgo%5fconst%28%220%22%29%3bgo%5fany%5fchar%28x%2c%22xX%22%29
%3bgo%5fany%28value%2cgen%5fdips%28%2209afAF%22%29%29%3b%7d%7dstring%20value%3b%
7bgo%5fstr%3ct%5fimpl%3e%28value%29%3b%7d%7d%0a%20%20t%5fvar%5fexpr%3d%3ei%5fexp
r%7b%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5ftype%5fwith%5fsep%20body%
3b%0a%20%20%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%2
0%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fau
to%28sep%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3a%3a%22%29%3b%
0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ffield%7bt%5fsep%20be
f%3bstring%20name%3bt%5fsep%20aft%3b%7bO%2b%3dgo%5fauto%28bef%29%3bM%2b%3dgo%5fs
tr%3ct%5fname%3e%28name%29%3bO%2b%3dgo%5fauto%28aft%29%3b%7d%7d%0a%20%20%20%20t%
5fimpl%7b%0a%20%20%20%20%20%20vector%3ct%5fitem%3e%20items%3b%0a%20%20%20%20%20%
20t%5fsep%20sep%3b%0a%20%20%20%20%20%20vector%3ct%5ffield%3e%20arr%3b%0a%20%20%2
0%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28items%29%3b%0a%20%20%
20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dg
o%5fvec%28arr%2c%22%2e%22%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%
20%20%20string%20name%3b%7bgo%5fstr%3ct%5fimpl%3e%28name%29%3b%7d%0a%20%20%7d%0a
%20%20t%5fctor%5finit%5flist%7b%0a%20%20%20%20t%5finit%5fparam%7b%0a%20%20%20%20
%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20string%20name%3b%0a%20%20%20%20%20%2
0vector%3ct%5fcall%5fparam%3e%20arr%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%
20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%
20%20%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20
%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3
dgo%5fvec%28arr%2c%22%2c%22%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28
%22%29%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20
%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20vector%3ct%5finit%5fparam%3e%20p
arams%3b%0a%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%
2b%3dgo%5fconst%28%22%3a%22%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fvec%28params%2
c%22%2c%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20
%7d%0a%20%20%7d%0a%20%20t%5fzero%5ffunc%5fbody%3d%3ei%5ffunc%5fbody%7b%7bgo%5fco
nst%28%22%3d0%3b%22%29%3b%7d%7d%0a%20%20t%5fnull%5ffunc%5fbody%3d%3ei%5ffunc%5fb
ody%7bt%5fsep%20sep%3b%7bO%2b%3dgo%5fauto%28sep%29%3bM%2b%3dgo%5fconst%28%22%3b%
22%29%3b%7d%7d%0a%20%20t%5fdelete%5ffunc%5fbody%3d%3ei%5ffunc%5fbody%7b%7bgo%5fc
onst%28%22%3ddelete%3b%22%29%3b%7d%7d%0a%20%20t%5fimpl%5ffunc%5fbody%3d%3ei%5ffu
nc%5fbody%7b%0a%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20TAutoPtr%3ct%5fctor%5f
init%5flist%3e%20init%5flist%3b%0a%20%20%20%20t%5fraw%5ffunc%5fbody%20body%3b%0a
%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%
20%20O%2b%3dgo%5fauto%28init%5flist%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%2
8body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fdtor%5fclass%5fstat%3d%3ei
%5fclass%5fstat%7b%0a%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20TAutoPtr%3ct%5f
func%5fpath%3e%20path%3b%0a%20%20%20%20string%20name%3b%0a%20%20%20%20t%5fsep%20
sep1%3b%0a%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%3a%3at%5ffunc%5
fparams%20params%3b%0a%20%20%20%20TAutoPtr%3ci%5ffunc%5fbody%3e%20body%3b%0a%20%
20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28path%29%3b%0a%20%20%20%20%20%
20M%2b%3dgo%5fconst%28%22%7e%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep
0%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%
20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28
params%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%7d
%0a%20%20%7d%0a%20%20t%5fctor%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%2
0%20t%5fimpl%7b%0a%20%20%20%20%20%20t%5fexplicit%7bt%5fsep%20sep%3b%7bM%2b%3dgo%
5fconst%28%22explicit%22%29%3bM%2b%3dgo%5fauto%28sep%29%3b%7d%7d%0a%20%20%20%20%
20%20TAutoPtr%3ct%5fexplicit%3e%20prefix%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5ff
unc%5fpath%3e%20path%3b%0a%20%20%20%20%20%20string%20name%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fconcrete%5fparams%3e%20con
crete%5fparams%3b%0a%20%20%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr
%3a%3at%5ffunc%5fparams%20params%3b%0a%20%20%20%20%20%20TAutoPtr%3ci%5ffunc%5fbo
dy%3e%20body%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fau
to%28prefix%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28path%29%3b%0a%20%
20%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20%20
%20%20%20O%2b%3dgo%5fauto%28concrete%5fparams%29%3b%0a%20%20%20%20%20%20%20%20M%
2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%
29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%20body%3b
%7bgo%5fauto%28body%29%3b%7d%0a%20%20%7d%0a%20%20t%5foper%5fcast%5fclass%5fstat%
3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20TAutoPtr%3ct%5ffunc%5fpath%3e%20path%3b%0
a%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype
%5fexpr%20type%3b%0a%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20t%5ffv%5fclass%5
fstat%3a%3at%5ftype%5fexpr%3a%3at%5ffunc%5fparams%20params%3b%0a%20%20%20%20TAut
oPtr%3ct%5fconst%5fwith%5fsep%3e%20cv%3b%0a%20%20%20%20TAutoPtr%3ci%5ffunc%5fbod
y%3e%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28path%29%
3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22operator%22%29%3b%0a%20%20%20%20%2
0%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28type%29
%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20M%2b%3
dgo%5fauto%28params%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv%29%3b%0a%20%
20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%
20t%5fcommon%5foper%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20t%5fim
pl%7b%0a%20%20%20%20%20%20vector%3ct%5fkeyword%3e%20keywords%3b%0a%20%20%20%20%2
0%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%20type%3b%0a%20%20%20%20%20%20TAu
toPtr%3ct%5fconst%5fwith%5fsep%3e%20cv0%3b%0a%20%20%20%20%20%20t%5fsep%20sep0%3b
%0a%20%20%20%20%20%20TAutoPtr%3ct%5ffunc%5fpath%3e%20path%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3b%0a%20%20%20%20%20%20string%20oper%3b%0a%20%20%20%20%20%20t%5f
fv%5fclass%5fstat%3a%3at%5ftype%5fexpr%3a%3at%5ffunc%5fparams%20params%3b%0a%20%
20%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv1%3b%0a%20%20%20%20%20%20
TAutoPtr%3ci%5ffunc%5fbody%3e%20body%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%2
0%20%20%20O%2b%3dgo%5fauto%28keywords%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%
5fauto%28type%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv0%29%3b%0a%20
%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20%20%20O%2
b%3dgo%5fauto%28path%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22oper
ator%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%2
0%20%20%20%20%20M%2b%3dgo%5fany%5fstr%5ffrom%5fvec%28oper%2csplit%28%22%3d%2c%2b
%3d%2c%2d%3d%2c%2a%3d%2c%2f%3d%2c%25%3d%2c%7c%3d%2c%26%3d%2c%5e%3d%2c%3c%3c%3d%2
c%3e%3e%3d%2c%7c%7c%2c%26%26%2c%7c%2c%5e%2c%26%2c%3d%3d%2c%21%3d%2c%3c%2c%3c%3d%
2c%3e%2c%3e%3d%2c%3c%3c%2c%3e%3e%2c%2b%2c%2d%2c%2a%2c%2f%2c%25%2c%2b%2b%2c%2d%2d
%2c%7e%2c%21%2c%28%29%2c%5b%5d%2c%2d%3e%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%2
0%20%20%20M%2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5f
auto%28cv1%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%2
0%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%20body%3b%7bgo%5fauto%
28body%29%3b%7d%0a%20%20%7d%0a%20%20t%5fparents%7b%0a%20%20%20%20t%5fitem%7b%0a%
20%20%20%20%20%20t%5fpub%7bt%5faccess%5fmod%20mod%3bt%5fsep%20sep%3b%7bM%2b%3dgo
%5fauto%28mod%29%3bO%2b%3dgo%5fauto%28sep%29%3b%7d%7d%0a%20%20%20%20%20%20t%5fse
p%20sep%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fpub%3e%20pub%3b%0a%20%20%20%20%20%
20string%20name%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5
fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28pub%29%3b%0a%20%2
0%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%
3a%3at%5ftype%5fexpr%5fwith%5fsep%5fand%5fcv%3e%28name%29%3b%0a%20%20%20%20%20%2
0%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fsep%20sep%3b%0a%20%20%20%20vector%3ct%5
fitem%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%
3a%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%2
0M%2b%3dgo%5fvec%28arr%2c%22%2c%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t
%5fclass%5fbody%7b%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fclass%5fstat%3e%3e%20ar
r%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%29%3b%0
a%20%20%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5f
const%28%22%7d%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fclass%7b%0a%20
%20%20%20string%20keyword%3b%0a%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20strin
g%20name%3b%0a%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20TAutoPtr%3ct%5fparents
%3e%20parents%3b%0a%20%20%20%20t%5fsep%20sep2%3b%0a%20%20%20%20TAutoPtr%3ct%5fcl
ass%5fbody%3e%20body%3b%0a%20%20%20%20t%5fsep%20sep3%3b%0a%20%20%20%20%7b%0a%20%
20%20%20%20%20M%2b%3dgo%5fany%5fstr%5ffrom%5fvec%28keyword%2csplit%28%22struct%2
cclass%2cunion%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28se
p0%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20
%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%2
8parents%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20%20%20%
20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep3%2
9%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3b%22%29%3b%0a%20%20%20%20%7d%0
a%20%20%7d%0a%20%20t%5fnamespace%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%2
0%20%20t%5fsep%20sep0%3b%0a%20%20%20%20string%20name%3b%0a%20%20%20%20t%5fsep%20
sep1%3b%0a%20%20%20%20t%5fclass%5fbody%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%2
0%20%20M%2b%3dgo%5fconst%28%22namespace%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5
fauto%28sep0%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3
b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20M%2b%3dg
o%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftemplate%5fclass
%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20t%5ftemplate%5fparam%7b%0a%20%20%
20%20%20%20t%5fsep%20bef%3b%0a%20%20%20%20%20%20TAutoPtr%3ci%5ftemplate%5fparam%
3e%20body%3b%0a%20%20%20%20%20%20t%5fsep%20aft%3b%0a%20%20%20%20%20%20%7b%0a%20%
20%20%20%20%20%20%20O%2b%3dgo%5fauto%28bef%29%3b%0a%20%20%20%20%20%20%20%20M%2b%
3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28aft%29%3b%
0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fcommon%5foper%5ftemp
late%5fbody%3d%3ei%5ftemplate%5fbody%7bt%5fcommon%5foper%5fclass%5fstat%3a%3at%5
fimpl%20body%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20t%5fctor%5ftemplate
%5fbody%3d%3ei%5ftemplate%5fbody%7bt%5fctor%5fclass%5fstat%3a%3at%5fimpl%20body%
3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20t%5ffunc%5ftemplate%5fbody%3d%3e
i%5ftemplate%5fbody%7b%0a%20%20%20%20%20%20vector%3ct%5fkeyword%3e%20keywords%3b
%0a%20%20%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%20type%3b%0a%20%
20%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv0%3b%0a%20%20%20%20%20%20
t%5fsep%20sep0%3b%0a%20%20%20%20%20%20string%20func%5fname%3b%0a%20%20%20%20%20%
20TAutoPtr%3ct%5fconcrete%5fparams%3e%20concrete%5fparams%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3b%0a%20%20%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexp
r%3a%3at%5ffunc%5fparams%20params%3b%0a%20%20%20%20%20%20t%5fsep%20sep2%3b%0a%20
%20%20%20%20%20TAutoPtr%3ct%5fconst%5fwith%5fsep%3e%20cv1%3b%0a%20%20%20%20%20%2
0TAutoPtr%3ci%5ffunc%5fbody%3e%20body%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%
20%20%20%20O%2b%3dgo%5fauto%28keywords%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo
%5fauto%28type%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28cv0%29%3b%0a%2
0%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20%20%20M%
2b%3dgo%5fstr%3ct%5fname%3e%28func%5fname%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3
dgo%5fauto%28concrete%5fparams%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%
28sep1%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28params%29%3b%0a%20%20%
20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3d
go%5fauto%28cv1%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a
%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20class%5ftemplate%5fbody%3d
%3ei%5ftemplate%5fbody%7b%0a%20%20%20%20%20%20string%20keyword%3b%0a%20%20%20%20
%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20string%20name%3b%0a%20%20%20%20%20%2
0t%5fsep%20sep1%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fconcrete%5fparams%3e%20par
ams%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fparents%3e%20parents%3b%0a%20%20%20%20
%20%20t%5fsep%20sep2%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fclass%5fbody%3e%20bod
y%3b%0a%20%20%20%20%20%20t%5fsep%20sep3%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%2
0%20%20%20%20M%2b%3dgo%5fany%5fstr%5ffrom%5fvec%28keyword%2csplit%28%22struct%2c
class%2cunion%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto
%28sep0%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%
3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%
20%20O%2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%
28parents%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20
%20%20%20%20%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3
dgo%5fauto%28sep3%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3b%22%
29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fname%5ftemplat
e%5fparam%3d%3ei%5ftemplate%5fparam%7b%0a%20%20%20%20%20%20t%5funsgnd%7bt%5fsep%
20sep%3b%7bM%2b%3dgo%5fconst%28%22unsigned%22%29%3b%7d%7d%0a%20%20%20%20%20%20t%
5fvalue%7b%0a%20%20%20%20%20%20%20%20t%5fexpr%20body%3b%0a%20%20%20%20%20%20%20%
20t%5fsep%20sep%3b%0a%20%20%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20%20%2
0M%2b%3dgo%5fconst%28%22%3d%22%29%3b%0a%20%20%20%20%20%20%20%20%20%20O%2b%3dgo%5
fauto%28sep%29%3b%0a%20%20%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%
0a%20%20%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%20%20string
%20unsgnd0%3b%0a%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20string%2
0type%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%20string%20unsg
nd1%3b%0a%20%20%20%20%20%20t%5fsep%20sep2%3b%0a%20%20%20%20%20%20string%20name%3
b%0a%20%20%20%20%20%20t%5fsep%20sep3%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fvalue
%3e%20value%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fstr
%3ct%5funsgnd%3e%28unsgnd0%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28se
p0%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28type%29%3b%0a
%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%20%20
O%2b%3dgo%5fstr%3ct%5funsgnd%3e%28unsgnd1%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3
dgo%5fauto%28sep2%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%
28name%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep3%29%3b%0a%20%20%20
%20%20%20%20%20O%2b%3dgo%5fauto%28value%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%2
0%20%7d%0a%20%20%20%20t%5fhead%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20
%20%20%20%20vector%3ct%5ftemplate%5fparam%3e%20params%3b%0a%20%20%20%20%20%20t%5
fsep%20sep1%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fcon
st%28%22template%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3
b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3c%22%29%3b%0a%20%20%20%20%2
0%20%20%20O%2b%3dgo%5fvec%28params%2c%22%2c%22%29%3b%0a%20%20%20%20%20%20%20%20M
%2b%3dgo%5fconst%28%22%3e%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28
sep1%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5ftype%5fte
mplate%5fparam%3d%3ei%5ftemplate%5fparam%7b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fh
ead%3e%20head%3b%0a%20%20%20%20%20%20string%20type%3b%0a%20%20%20%20%20%20t%5fse
p%20sep%3b%0a%20%20%20%20%20%20string%20name%3b%0a%20%20%20%20%20%20%7b%0a%20%20
%20%20%20%20%20%20O%2b%3dgo%5fauto%28head%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3
dgo%5fany%5fstr%5ffrom%5fvec%28type%2csplit%28%22class%2ctypename%22%2c%22%2c%22
%29%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%
20%20%20%20O%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20%20%20%7d%0a
%20%20%20%20%7d%0a%20%20%20%20t%5fhead%20head%3b%0a%20%20%20%20TAutoPtr%3ci%5fte
mplate%5fbody%3e%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5faut
o%28head%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%
7d%0a%20%20%7d%0a%20%20t%5fenum%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20
%20%20t%5fvalue%7b%0a%20%20%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20%20%20t%5
fexpr%20expr%3b%0a%20%20%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20%20%20%7b%0a
%20%20%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%3d%22%29%3b%0a%20%20%20%20%20%20
%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%2
8expr%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%
20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fitem%7b%0a%20%20%20%20%20%20t%5f
sep%20sep0%3b%0a%20%20%20%20%20%20string%20name%3b%0a%20%20%20%20%20%20t%5fsep%2
0sep1%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fvalue%3e%20value%3b%0a%20%20%20%20%2
0%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%2
0%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20%20%20%20%20O
%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28value%
29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fcomma%5fwith%5
fsep%7bt%5fsep%20sep%3b%7bM%2b%3dgo%5fconst%28%22%2c%22%29%3bO%2b%3dgo%5fauto%28
sep%29%3b%7d%7d%0a%20%20%20%20t%5fimpl%5fbody%3d%3ei%5fbody%7b%0a%20%20%20%20%20
%20vector%3ct%5fitem%3e%20arr%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fcomma%5fwith
%5fsep%3e%20comma%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20M%2b%3dgo
%5fconst%28%22%7b%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fvec%28arr%2c%22
%2c%22%29%3b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28comma%29%3b%0a%20%20%2
0%20%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%20%20%20%20%7d%0a%2
0%20%20%20%7d%0a%20%20%20%20t%5fempty%5fbody%3d%3ei%5fbody%7b%7bgo%5fconst%28%22
%3b%22%29%3b%7d%7d%0a%20%20%20%20t%5fbody%7bTAutoPtr%3ci%5fbody%3e%20body%3b%7bg
o%5fauto%28body%29%3b%7d%7d%0a%20%20%20%20t%5fsep%20sep0%3b%0a%20%20%20%20string
%20name%3b%0a%20%20%20%20t%5fsep%20sep1%3b%0a%20%20%20%20t%5fbody%20body%3b%0a%2
0%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22enum%22%29%3b%0a%20%20%
20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fstr%3ct
%5fname%3e%28name%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%
20%20%20%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%
20t%5fusing%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%0a%20%20%20%20t%5fsep%20sep%
3b%0a%20%20%20%20t%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%20type%3b%0a%20%20%2
0%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22using%22%29%3b%0a%20%20%20%20
%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28type%2
9%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5ftmpl%5fcall%5fparam%7b%0a%20%20%2
0%20t%5fsep%20sep0%3b%0a%20%20%20%20t%5ftmpl%5fexpr%20expr%3b%0a%20%20%20%20t%5f
sep%20sep1%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3
b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dg
o%5fauto%28sep1%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fcall%5ftmpl%5fex
pr%3d%3ei%5ftmpl%5fexpr%7b%0a%20%20%20%20string%20func%3b%0a%20%20%20%20t%5fsep%
20sep%3b%0a%20%20%20%20vector%3ct%5ftmpl%5fcall%5fparam%3e%20arr%3b%0a%20%20%20%
20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28func%29%3b%0a%20%20%20
%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%2
2%28%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fvec%28arr%2c%22%2c%22%29%3b%0a%20%
20%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%
0a%20%20t%5fblock%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7b%0a%20%20%20%20t%5fsep%20
sep0%3b%0a%20%20%20%20t%5ftmpl%5fexpr%20expr%3b%0a%20%20%20%20t%5fsep%20sep1%3b%
0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%
20%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fauto
%28expr%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20%2
0%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%
5fpfunc%5fconcrete%5fparam%5fway%3d%3ei%5fconcrete%5fparam%5fway%7bt%5ffv%5fclas
s%5fstat%3a%3at%5ftype%5fexpr%3a%3at%5fpfunc%20value%3b%7bgo%5fauto%28value%29%3
b%7d%7d%0a%20%20t%5ftype%5fconcrete%5fparam%5fway%3d%3ei%5fconcrete%5fparam%5fwa
y%7bt%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%3a%3at%5ftype%5fexpr%5fwith%5fsep
%5fand%5fcv%20value%3b%7bgo%5fauto%28value%29%3b%7d%7d%0a%20%20t%5fexpr%5fconcre
te%5fparam%5fway%3d%3ei%5fconcrete%5fparam%5fway%7bt%5ftmpl%5fexpr%20value%3b%7b
go%5fminor%3ct%5ftype%5fconcrete%5fparam%5fway%3e%28value%29%3b%7d%7d%0a%20%20t%
5fbool%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7bstring%20value%3b%7bgo%5fany%5fstr%5
ffrom%5fvec%28value%2csplit%28%22false%2ctrue%22%2c%22%2c%22%29%29%3b%7d%7d%0a%2
0%20t%5fstring%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7bstring%20value%3b%7bgo%5fstr
%3ct%5fstr%5fitem%3a%3at%5fimpl%3e%28value%29%3b%7d%7d%0a%20%20t%5fchar%5ftmpl%5
fexpr%3d%3ei%5ftmpl%5fexpr%7bstring%20value%3b%7bgo%5fstr%3ct%5fchar%5fitem%3a%3
at%5fimpl%3e%28value%29%3b%7d%7d%0a%20%20t%5fnum%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fe
xpr%7bstring%20value%3b%7bgo%5fany%28value%2cgen%5fdips%28%2209%22%29%29%3b%7d%7
d%0a%20%20t%5freal%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7bstring%20value%3b%7bgo%5
fstr%3ct%5freal%3e%28value%29%3b%7d%7d%0a%20%20t%5fnullptr%5ftmpl%5fexpr%3d%3ei%
5ftmpl%5fexpr%7b%7bgo%5fconst%28%22nullptr%22%29%3b%7d%7d%0a%20%20t%5for%5ftmpl%
5fexpr%3d%3ei%5ftmpl%5fexpr%7bvector%3ct%5fname%3e%20arr%3b%7bgo%5fbin%5foper%28
arr%2c%22%7c%22%29%3b%7d%7d%0a%20%20t%5fhex%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7
b%0a%20%20%20%20t%5fimpl%7bchar%20x%3bstring%20value%3b%7bgo%5fconst%28%220%22%2
9%3bgo%5fany%5fchar%28x%2c%22xX%22%29%3bgo%5fany%28value%2cgen%5fdips%28%2209afA
F%22%29%29%3b%7d%7dstring%20value%3b%0a%20%20%20%20%7bgo%5fstr%3ct%5fimpl%3e%28v
alue%29%3b%7d%0a%20%20%7d%0a%20%20t%5fvar%5ftmpl%5fexpr%3d%3ei%5ftmpl%5fexpr%7bs
tring%20name%3b%7bgo%5fstr%3ct%5ffv%5fclass%5fstat%3a%3at%5ftype%5fexpr%3e%28nam
e%29%3b%7d%7d%0a%20%20t%5fpragma%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%2
0body%3b%7bgo%5fconst%28%22%23pragma%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%
7d%7d%0a%20%20t%5finclude%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3
b%7bgo%5fconst%28%22%23include%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%
0a%20%20t%5fpreproc%5fif%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3b
%7bgo%5fconst%28%22%23if%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%0a%20%
20t%5fpreproc%5felse%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3b%7bg
o%5fconst%28%22%23else%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%0a%20%20
t%5fpreproc%5fendif%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3b%7bgo
%5fconst%28%22%23endif%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%0a%20%20
t%5fdefine%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3b%7bgo%5fconst%
28%22%23define%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%0a%20%20t%5funde
f%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bstring%20body%3b%7bgo%5fconst%28%22%23u
ndef%22%29%3bgo%5fend%28body%2c%22%5cn%22%29%3b%7d%7d%0a%20%20t%5fsep%5fclass%5f
stat%3d%3ei%5fclass%5fstat%7bt%5fsep%20sep%3b%7bgo%5fauto%28sep%29%3b%7d%7d%0a%2
0%20t%5fnull%5fclass%5fstat%3d%3ei%5fclass%5fstat%7b%7bgo%5fconst%28%22%3b%22%29
%3b%7d%7d%0a%20%20t%5fclass%5fclass%5fstat%3d%3ei%5fclass%5fstat%7bt%5fclass%20b
ody%3b%7bgo%5fauto%28body%29%3b%7d%7d%0a%20%20t%5finl%5ffile%5fstat%7b%0a%20%20%
20%20t%5fsep%20sep%3b%0a%20%20%20%20TAutoPtr%3ct%5fclass%3e%20body%3b%0a%20%20%2
0%20%7b%0a%20%20%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20%20%20M%2
b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20vector%3cTAutoP
tr%3ci%5fclass%5fstat%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28arr%2
9%3b%0a%20%20%7d%0a%7d
*/