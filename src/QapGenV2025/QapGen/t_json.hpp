// 44.380000 ms
struct t_json{
  //===>>===i_value_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_true)\
    ADD(t_false)\
    ADD(t_null)\
    ADD(t_string)\
    ADD(t_number)\
    ADD(t_empty_array)\
    ADD(t_array)\
    ADD(t_empty_object)\
    ADD(t_object)\
  ADDEND()
  class i_value;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_value_visitor{
  public:
    typedef t_json::i_value i_value;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_json::U U;//typedef t_json::U U;
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
    static TYPE*UberCast(i_value*p){
      if(!p)return nullptr;Is<TYPE,i_value_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_value*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_value_visitor{
  //  void Do(t_true&r){}
  //  void Do(t_false&r){}
  //  void Do(t_null&r){}
  //  void Do(t_string&r){}
  //  void Do(t_number&r){}
  //  void Do(t_empty_array&r){}
  //  void Do(t_array&r){}
  //  void Do(t_empty_object&r){}
  //  void Do(t_object&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_value_visitor
  struct i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_value
  public:
    typedef i_value_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_true);
        F(t_false);
        F(t_null);
        F(t_string);
        F(t_number);
        F(t_empty_array);
        F(t_array);
        F(t_empty_object);
        F(t_object);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_true:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_true)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_true
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_true
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("true");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_false:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_false)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_false
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_false
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("false");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_null:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_null)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_null
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_null
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("null");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_string:public i_value{
    //===>>===i_item_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_raw)\
      ADD(t_fix)\
      ADD(t_hex)\
    ADDEND()
    class i_item;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_item_visitor{
    public:
      typedef t_string::i_item i_item;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_string::U U;//typedef t_string::U U;
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
    //  void Do(t_raw&r){}
    //  void Do(t_fix&r){}
    //  void Do(t_hex&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_item_visitor
    struct i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_item
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_item
    public:
      typedef i_item_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_raw);
          F(t_fix);
          F(t_hex);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_raw:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_item)OWNER(t_string)
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
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(dip_inv("\"\\\n"));
        ok=dev.go_any(body,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_fix:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fix)PARENT(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(char,body,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_fix
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_fix
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("\\");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr("\"\\/bfnrt");
        ok=dev.go_any_char(body,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_hex:public i_item{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex)PARENT(i_item)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(array(char,4),arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_hex
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_hex
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("\\u");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
        ok=dev.go_any_arr_char(arr,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_items{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_items)OWNER(t_string)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_items
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_items
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
    F(t_raw  )\
    F(t_fix  )\
    F(t_hex  )\
    F(t_items)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_items,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_string
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_string
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("\"");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      ok=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_number:public i_value{
    //===>>===i_int_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_num)\
      ADD(t_zero)\
    ADDEND()
    class i_int;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_int_visitor{
    public:
      typedef t_number::i_int i_int;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_number::U U;//typedef t_number::U U;
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
      static TYPE*UberCast(i_int*p){
        if(!p)return nullptr;Is<TYPE,i_int_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_int*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_int_visitor{
    //  void Do(t_num&r){}
    //  void Do(t_zero&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_int_visitor
    struct i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_int)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_int
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_int
    public:
      typedef i_int_visitor i_visitor;
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
    struct t_minus{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_minus)OWNER(t_number)
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
    struct t_frac{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_number)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_number)
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
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_number)
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
    struct t_num:public i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_int)OWNER(t_number)
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
    struct t_zero:public i_int{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_int)OWNER(t_number)
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
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_minus)\
    F(t_frac )\
    F(t_sign )\
    F(t_exp  )\
    F(t_num  )\
    F(t_zero )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_minus>,minus,DEF,$,$)\
  ADDVAR(TAutoPtr<i_int>,val,DEF,$,$)\
  ADDVAR(TAutoPtr<t_frac>,frac,DEF,$,$)\
  ADDVAR(TAutoPtr<t_exp>,exp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_number
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(minus);
      ok=dev.go_auto(val);
      if(!ok)return ok;
      dev.go_auto(frac);
      dev.go_auto(exp);
      return ok;
    }
  public:
  };
  struct t_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(" \t\r\n");
      ok=dev.go_any(body,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_empty_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_array)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_empty_array
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_empty_array
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_const("]");
      if(!ok)return ok;
      dev.go_auto(sep2);
      return ok;
    }
  };
  struct t_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(TAutoPtr<i_value>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_value
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
  struct t_comma_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comma_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_value,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comma_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_comma_value
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_const(",");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_array:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_value,first,DEF,$,$)\
  ADDVAR(vector<t_comma_value>,arr,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_array
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_array
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("[");
      if(!ok)return ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      dev.go_auto(sep);
      ok=dev.go_const("]");
      if(!ok)return ok;
      dev.go_auto(sep2);
      return ok;
    }
  };
  struct t_empty_object:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_empty_object)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_empty_object
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_empty_object
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      dev.go_auto(sep);
      ok=dev.go_const("}");
      if(!ok)return ok;
      dev.go_auto(sep2);
      return ok;
    }
  };
  struct t_pair{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pair)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep0,DEF,$,$)\
  ADDVAR(t_string,key,DEF,$,$)\
  ADDVAR(t_sep,sep1,DEF,$,$)\
  ADDVAR(t_value,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_pair
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_pair
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep0);
      ok=dev.go_auto(key);
      if(!ok)return ok;
      dev.go_auto(sep1);
      ok=dev.go_const(":");
      if(!ok)return ok;
      ok=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_comma_pair{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comma_pair)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_pair,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comma_pair
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_comma_pair
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto(sep);
      ok=dev.go_const(",");
      if(!ok)return ok;
      ok=dev.go_auto(body);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_object:public i_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_object)PARENT(i_value)OWNER(t_json)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_pair,first,DEF,$,$)\
  ADDVAR(vector<t_comma_pair>,arr,DEF,$,$)\
  ADDVAR(t_sep,sep,DEF,$,$)\
  ADDVAR(t_sep,sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_object
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_object
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      dev.go_auto(sep);
      ok=dev.go_const("}");
      if(!ok)return ok;
      dev.go_auto(sep2);
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_true        )\
  F(t_false       )\
  F(t_null        )\
  F(t_string      )\
  F(t_number      )\
  F(t_sep         )\
  F(t_empty_array )\
  F(t_value       )\
  F(t_comma_value )\
  F(t_array       )\
  F(t_empty_object)\
  F(t_pair        )\
  F(t_comma_pair  )\
  F(t_object      )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_json)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_json
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_json
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    return ok;
  }
public:
};
bool t_json::i_value::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_true);
  F(t_false);
  F(t_null);
  F(t_string);
  F(t_number);
  F(t_empty_array);
  F(t_array);
  F(t_empty_object);
  F(t_object);
  #undef F
  main();
  return scope.ok;
}
bool t_json::t_string::i_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_raw);
  F(t_fix);
  F(t_hex);
  #undef F
  main();
  return scope.ok;
}
bool t_json::t_number::i_int::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_num);
  F(t_zero);
  #undef F
  main();
  return scope.ok;
}
/*
//list of types:
F(t_json)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fjson%7b%0a%0at%5ftrue%3d%3ei%5fvalue%7b%7bgo%5fconst%28%22true%22%29%3b%7d%7
d%0at%5ffalse%3d%3ei%5fvalue%7b%7bgo%5fconst%28%22false%22%29%3b%7d%7d%0at%5fnul
l%3d%3ei%5fvalue%7b%7bgo%5fconst%28%22null%22%29%3b%7d%7d%0a%0at%5fstring%3d%3ei
%5fvalue%7b%0a%20%20t%5fraw%3d%3ei%5fitem%7bstring%20body%3b%7bgo%5fany%28body%2
cdip%5finv%28%22%5c%22%5c%5c%5cn%22%29%29%3b%7d%7d%0a%20%20t%5ffix%3d%3ei%5fitem
%7bchar%20body%3b%7bgo%5fconst%28%22%5c%5c%22%29%3bgo%5fany%5fchar%28body%2c%22%
5c%22%5c%5c%2fbfnrt%22%29%3b%7d%7d%0a%20%20t%5fhex%3d%3ei%5fitem%7barray%28char%
2c4%29%20arr%3b%7bgo%5fconst%28%22%5c%5cu%22%29%3bgo%5fany%5farr%5fchar%28arr%2c
gen%5fdips%28%2209afAF%22%29%29%3b%7d%7d%0a%20%20t%5fitems%7bvector%3cTAutoPtr%3
ci%5fitem%3e%3e%20arr%3b%7bgo%5fauto%28arr%29%3b%7d%7d%0a%20%20t%5fitems%20body%
3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%5c%22%22%29%3b%0a%20%20%20%20go%5f
auto%28body%29%3b%0a%20%20%20%20go%5fconst%28%22%5c%22%22%29%3b%0a%20%20%7d%0a%7
d%0a%0at%5fnumber%3d%3ei%5fvalue%7b%0a%20%20t%5fminus%7b%7bgo%5fconst%28%22%2d%2
2%29%3b%7d%7d%0a%20%20t%5ffrac%7b%0a%20%20%20%20string%20arr%3b%0a%20%20%20%20%7
b%0a%20%20%20%20%20%20M%2b%3dgo%5fconst%28%22%2e%22%29%3b%0a%20%20%20%20%20%20M%
2b%3dgo%5fany%28arr%2cgen%5fdips%28%2209%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%
7d%0a%20%20t%5fsign%7b%0a%20%20%20%20char%20sign%3b%0a%20%20%20%20%7b%0a%20%20%2
0%20%20%20go%5fany%5fchar%28sign%2c%22%2d%2b%22%29%3b%0a%20%20%20%20%7d%0a%20%20
%7d%0a%20%20t%5fexp%7b%0a%20%20%20%20char%20e%3b%0a%20%20%20%20TAutoPtr%3ct%5fsi
gn%3e%20sign%3b%0a%20%20%20%20string%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%2
0%20M%2b%3dgo%5fany%5fchar%28e%2c%22eE%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5f
auto%28sign%29%3b%0a%20%20%20%20%20%20M%2b%3dgo%5fany%28arr%2cgen%5fdips%28%2209
%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fnum%3d%3ei%5fint%7b%0a%20
%20%20%20char%20first%3b%0a%20%20%20%20string%20num%3b%0a%20%20%20%20%7b%0a%20%2
0%20%20%20%20M%2b%3dgo%5fany%5fchar%28first%2cgen%5fdips%28%2219%22%29%29%3b%0a%
20%20%20%20%20%20O%2b%3dgo%5fany%28num%2cgen%5fdips%28%2209%22%29%29%3b%0a%20%20
%20%20%7d%0a%20%20%7d%0a%20%20t%5fzero%3d%3ei%5fint%7b%7bgo%5fconst%28%220%22%29
%3b%7d%7d%0a%20%20TAutoPtr%3ct%5fminus%3e%20minus%3b%0a%20%20TAutoPtr%3ci%5fint%
3e%20val%3b%0a%20%20TAutoPtr%3ct%5ffrac%3e%20frac%3b%0a%20%20TAutoPtr%3ct%5fexp%
3e%20exp%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28minus%29%3b%0a%20%20%20
%20M%2b%3dgo%5fauto%28val%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28frac%29%3b%0a%2
0%20%20%20O%2b%3dgo%5fauto%28exp%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%7b%0a%20%2
0string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fany%28body%2c%22%20%5ct%5cr%5cn
%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fempty%5farray%3d%3ei%5fvalue%7b%0a%20%20t%5
fsep%20sep%3b%0a%20%20t%5fsep%20sep2%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fco
nst%28%22%5b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M
%2b%3dgo%5fconst%28%22%5d%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0
a%20%20%7d%0a%7d%0a%0at%5fvalue%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20TAutoPtr%3ci
%5fvalue%3e%20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%
20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fcomma%5fvalu
e%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fvalue%20body%3b%0a%20%20%7b%0a%20%20%2
0%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%2c%22%29%
3b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0at%5farray%
3d%3ei%5fvalue%7b%0a%20%20t%5fvalue%20first%3b%0a%20%20vector%3ct%5fcomma%5fvalu
e%3e%20arr%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fsep%20sep2%3b%0a%20%20%7b%0a%
20%20%20%20M%2b%3dgo%5fconst%28%22%5b%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28
first%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20O%2b%3dgo%5
fauto%28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5d%22%29%3b%0a%20%20%20%
20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fempty%5fobject%3d%3ei
%5fvalue%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fsep%20sep2%3b%0a%20%20%7b%0a%20
%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28se
p%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%20%20O%2b%3dg
o%5fauto%28sep2%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fpair%7b%0a%20%20t%5fsep%20sep0%
3b%0a%20%20t%5fstring%20key%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20t%5fvalue%20val
ue%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20M%2b
%3dgo%5fauto%28key%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20
%20M%2b%3dgo%5fconst%28%22%3a%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28value%29
%3b%0a%20%20%7d%0a%7d%0a%0at%5fcomma%5fpair%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20
t%5fpair%20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%
20%20%20M%2b%3dgo%5fconst%28%22%2c%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28bod
y%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fobject%3d%3ei%5fvalue%7b%0a%20%20t%5fpair%20f
irst%3b%0a%20%20vector%3ct%5fcomma%5fpair%3e%20arr%3b%0a%20%20t%5fsep%20sep%3b%0
a%20%20t%5fsep%20sep2%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22
%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28first%29%3b%0a%20%20%20%20O%2b%3dgo%5fau
to%28arr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M%2b%3dg
o%5fconst%28%22%7d%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a%20%20
%7d%0a%7d%0a%0a%7d
*/