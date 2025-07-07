// 480.204400 ms
struct t_asmcpplike2016{
  //===>>===i_param_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_char_param)\
    ADD(t_str_param)\
    ADD(t_num_param)\
    ADD(t_ptr_reg_param)\
    ADD(t_ptr_num_param)\
    ADD(t_name_param)\
  ADDEND()
  class i_param;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_param_visitor{
  public:
    typedef t_asmcpplike2016::i_param i_param;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;//typedef t_asmcpplike2016::U U;
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
    static TYPE*UberCast(i_param*p){
      if(!p)return nullptr;Is<TYPE,i_param_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_param*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_param_visitor{
  //  void Do(t_char_param&r){}
  //  void Do(t_str_param&r){}
  //  void Do(t_num_param&r){}
  //  void Do(t_ptr_reg_param&r){}
  //  void Do(t_ptr_num_param&r){}
  //  void Do(t_name_param&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_param_visitor
  struct i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_param
  public:
    typedef i_param_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_param()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_char_param);
        F(t_str_param);
        F(t_num_param);
        F(t_ptr_reg_param);
        F(t_ptr_num_param);
        F(t_name_param);
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
    ADD(t_cmd_stat)\
    ADD(t_block_stat)\
    ADD(t_sep_stat)\
  ADDEND()
  class i_stat;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_stat_visitor{
  public:
    typedef t_asmcpplike2016::i_stat i_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;//typedef t_asmcpplike2016::U U;
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
  //  void Do(t_cmd_stat&r){}
  //  void Do(t_block_stat&r){}
  //  void Do(t_sep_stat&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_stat_visitor
  struct i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)OWNER(t_asmcpplike2016)
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
        F(t_cmd_stat);
        F(t_block_stat);
        F(t_sep_stat);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_proc_item)\
    ADD(t_sep_item)\
    ADD(t_struct_item)\
  ADDEND()
  class i_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_item_visitor{
  public:
    typedef t_asmcpplike2016::i_item i_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_asmcpplike2016::U U;//typedef t_asmcpplike2016::U U;
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
  //  void Do(t_proc_item&r){}
  //  void Do(t_sep_item&r){}
  //  void Do(t_struct_item&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_item_visitor
  struct i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_asmcpplike2016)
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
        F(t_proc_item);
        F(t_sep_item);
        F(t_struct_item);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_minus{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_minus)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_minus
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_minus
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("-");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_impl)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,minus,DEF,$,$)\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_impl
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_str<t_minus>(minus);
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(num,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_num_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_char_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_char,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_char_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_char_param
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
  struct t_str_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_param
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
  struct t_num_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_num,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num_param
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
  struct t_ptr_reg_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_reg_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,reg,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_reg_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_reg_param
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("ptr[");
      if(!ok)return ok;
      ok=dev.go_str<t_name>(reg);
      if(!ok)return ok;
      ok=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_ptr_num_param:public i_param{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ptr_num_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ptr_num_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ptr_num_param
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("ptr[");
      if(!ok)return ok;
      ok=dev.go_str<t_num>(num);
      if(!ok)return ok;
      ok=dev.go_const("]");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_name_param:public i_param{
    struct t_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ext)OWNER(t_name_param)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,field,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_ext
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("[\"");
        if(!ok)return ok;
        ok=dev.go_str<t_name>(field);
        if(!ok)return ok;
        ok=dev.go_const("\"]");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_ext)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_param)PARENT(i_param)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(vector<t_ext>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name_param
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name_param
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_cmd_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,cmd,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_param>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_cmd_stat
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_cmd_stat
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_name>(cmd);
      if(!ok)return ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      dev.go_vec(arr,",");
      ok=dev.go_const(");");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_block_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
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
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(arr);
      ok=dev.go_const("}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sep_stat:public i_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_stat)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      ok=dev.go_str<t_sep>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_proc_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_proc_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
  ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_proc_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_proc_item
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{proc(");
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      ok=dev.go_const("){");
      if(!ok)return ok;
      dev.go_str<t_sep>(sep);
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      ok=dev.go_const("}}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_field{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,type,DEF,$,$)\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_field
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_field
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("FIELD(");
      if(!ok)return ok;
      ok=dev.go_auto(type);
      if(!ok)return ok;
      ok=dev.go_const(",");
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      ok=dev.go_const(");");
      if(!ok)return ok;
      dev.go_str<t_sep>(sep);
      return ok;
    }
  };
  struct t_sep_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
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
      ok=dev.go_str<t_sep>(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_struct_item:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_item)PARENT(i_item)OWNER(t_asmcpplike2016)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_str,name,DEF,$,$)\
  ADDVAR(string,sep,DEF,$,$)\
  ADDVAR(vector<t_field>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_struct_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_struct_item
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{STRUCT(");
      if(!ok)return ok;
      ok=dev.go_auto(name);
      if(!ok)return ok;
      ok=dev.go_const("){");
      if(!ok)return ok;
      dev.go_str<t_sep>(sep);
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      ok=dev.go_const("}}");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_minus        )\
  F(t_num_impl     )\
  F(t_num          )\
  F(t_char_param   )\
  F(t_str_param    )\
  F(t_num_param    )\
  F(t_ptr_reg_param)\
  F(t_ptr_num_param)\
  F(t_name_param   )\
  F(t_cmd_stat     )\
  F(t_block_stat   )\
  F(t_sep_stat     )\
  F(t_proc_item    )\
  F(t_field        )\
  F(t_sep_item     )\
  F(t_struct_item  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_asmcpplike2016)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_asmcpplike2016
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_asmcpplike2016
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_const("{");
    if(!ok)return ok;
    ok=dev.go_auto(arr);
    if(!ok)return ok;
    ok=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
public:
};
void t_asmcpplike2016::i_param::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_char_param);
  F(t_str_param);
  F(t_num_param);
  F(t_ptr_reg_param);
  F(t_ptr_num_param);
  F(t_name_param);
  #undef F
  main();
}
void t_asmcpplike2016::i_stat::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_cmd_stat);
  F(t_block_stat);
  F(t_sep_stat);
  #undef F
  main();
}
void t_asmcpplike2016::i_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<TYPE>();
  F(t_proc_item);
  F(t_sep_item);
  F(t_struct_item);
  #undef F
  main();
}
/*
//list of types:
F(t_asmcpplike2016)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fasmcpplike2016%7b%0a%20%20t%5fminus%7b%0a%20%20%20%20%22%2d%22%0a%20%20%7d%0
a%20%20t%5fnum%5fimpl%7b%0a%20%20%20%20string%20minus%3dstr%3ct%5fminus%3e%28%29
%3f%3b%0a%20%20%20%20string%20num%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%20%2
0%7d%0a%20%20t%5fnum%7b%0a%20%20%20%20string%20value%3dstr%3ct%5fnum%5fimpl%3e%2
8%29%3b%0a%20%20%7d%0a%20%20t%5fchar%5fparam%3ai%5fparam%7b%0a%20%20%20%20t%5fch
ar%20value%3b%0a%20%20%7d%0a%20%20t%5fstr%5fparam%3ai%5fparam%7b%0a%20%20%20%20t
%5fstr%20value%3b%0a%20%20%7d%0a%20%20t%5fnum%5fparam%3ai%5fparam%7b%0a%20%20%20
%20t%5fnum%20value%3b%0a%20%20%7d%0a%20%20t%5fptr%5freg%5fparam%3ai%5fparam%7b%0
a%20%20%20%20%22ptr%5b%22%0a%20%20%20%20string%20reg%3dstr%3ct%5fname%3e%28%29%3
b%0a%20%20%20%20%22%5d%22%0a%20%20%7d%0a%20%20t%5fptr%5fnum%5fparam%3ai%5fparam%
7b%0a%20%20%20%20%22ptr%5b%22%0a%20%20%20%20string%20num%3dstr%3ct%5fnum%3e%28%2
9%3b%0a%20%20%20%20%22%5d%22%0a%20%20%7d%0a%20%20t%5fname%5fparam%3ai%5fparam%7b
%0a%20%20%20%20t%5fext%7b%0a%20%20%20%20%20%20%22%5b%5c%22%22%0a%20%20%20%20%20%
20string%20field%3dstr%3ct%5fname%3e%28%29%3b%0a%20%20%20%20%20%20%22%5c%22%5d%2
2%0a%20%20%20%20%7d%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20vector%3ct%5f
ext%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fcmd%5fstat%3ai%5fstat%7b%0a%20%20%20%
20string%20cmd%3dstr%3ct%5fname%3e%28%29%3b%0a%20%20%20%20%22%28%22%0a%20%20%20%
20vector%3cTAutoPtr%3ci%5fparam%3e%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%
20%20%22%29%3b%22%0a%20%20%7d%0a%20%20t%5fblock%5fstat%3ai%5fstat%7b%0a%20%20%20
%20%22%7b%22%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fstat%3e%3e%20arr%3f%3b%0a%20%
20%20%20%22%7d%22%0a%20%20%7d%0a%20%20t%5fsep%5fstat%3ai%5fstat%7b%0a%20%20%20%2
0string%20value%3dstr%3ct%5fsep%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5fproc%5fitem%
3ai%5fitem%7b%0a%20%20%20%20%22%7bproc%28%22%0a%20%20%20%20t%5fstr%20name%3b%0a%
20%20%20%20%22%29%7b%22%0a%20%20%20%20string%20sep%3dstr%3ct%5fsep%3e%28%29%3f%3
b%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fstat%3e%3e%20arr%3b%0a%20%20%20%20%22%7d
%7d%22%0a%20%20%7d%0a%20%20t%5ffield%7b%0a%20%20%20%20%22FIELD%28%22%0a%20%20%20
%20t%5fstr%20type%3b%0a%20%20%20%20%22%2c%22%0a%20%20%20%20t%5fstr%20name%3b%0a%
20%20%20%20%22%29%3b%22%0a%20%20%20%20string%20sep%3dstr%3ct%5fsep%3e%28%29%3f%3
b%0a%20%20%7d%0a%20%20t%5fsep%5fitem%3ai%5fitem%7b%0a%20%20%20%20string%20value%
3dstr%3ct%5fsep%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5fstruct%5fitem%3ai%5fitem%7b%
0a%20%20%20%20%22%7bSTRUCT%28%22%0a%20%20%20%20t%5fstr%20name%3b%0a%20%20%20%20%
22%29%7b%22%0a%20%20%20%20string%20sep%3dstr%3ct%5fsep%3e%28%29%3f%3b%0a%20%20%2
0%20vector%3ct%5ffield%3e%20arr%3b%0a%20%20%20%20%22%7d%7d%22%0a%20%20%7d%0a%20%
20%22%7b%22%0a%20%20vector%3cTAutoPtr%3ci%5fitem%3e%3e%20arr%3b%0a%20%20%22%7d%2
2%0a%7d
*/