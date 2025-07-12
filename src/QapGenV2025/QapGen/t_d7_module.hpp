// 699.346200 ms
//===>>===i_type_decl_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_class_decl)\
  ADD(t_record_decl)\
  ADD(t_proc_decl)\
  ADD(t_type_ptr_decl)\
  ADD(t_array_decl)\
  ADD(t_sep_type_decl)\
ADDEND()
class i_type_decl;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_type_decl_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
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
  static TYPE*UberCast(i_type_decl*p){
    if(!p)return nullptr;Is<TYPE,i_type_decl_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_type_decl*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_type_decl_visitor{
//  void Do(t_class_decl&r){}
//  void Do(t_record_decl&r){}
//  void Do(t_proc_decl&r){}
//  void Do(t_type_ptr_decl&r){}
//  void Do(t_array_decl&r){}
//  void Do(t_sep_type_decl&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_type_decl_visitor
struct i_type_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_type_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_type_decl
public:
  typedef i_type_decl_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_type_decl()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_class_decl);
      F(t_record_decl);
      F(t_proc_decl);
      F(t_type_ptr_decl);
      F(t_array_decl);
      F(t_sep_type_decl);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_decl_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_types)\
  ADD(t_var)\
  ADD(t_func)\
  ADD(t_sep_decl)\
ADDEND()
class i_decl;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_decl_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
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
  static TYPE*UberCast(i_decl*p){
    if(!p)return nullptr;Is<TYPE,i_decl_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_decl*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_decl_visitor{
//  void Do(t_types&r){}
//  void Do(t_var&r){}
//  void Do(t_func&r){}
//  void Do(t_sep_decl&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_decl_visitor
struct i_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_decl
public:
  typedef i_decl_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_decl()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_types);
      F(t_var);
      F(t_func);
      F(t_sep_decl);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
struct t_sep{
  //===>>===i_sep_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_comment)\
    ADD(t_c_comment)\
    ADD(t_raw_sep)\
  ADDEND()
  class i_sep;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_sep_visitor{
  public:
    typedef t_sep::i_sep i_sep;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sep::U U;//typedef t_sep::U U;
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
    static TYPE*UberCast(i_sep*p){
      if(!p)return nullptr;Is<TYPE,i_sep_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_sep*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_sep_visitor{
  //  void Do(t_comment&r){}
  //  void Do(t_c_comment&r){}
  //  void Do(t_raw_sep&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_sep_visitor
  struct i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_sep
  public:
    typedef i_sep_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_sep()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_comment);
        F(t_c_comment);
        F(t_raw_sep);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comment)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,s,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comment
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_comment
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("{");
      if(!ok)return ok;
      ok=dev.go_end(s,"}");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_c_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_comment)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_c_comment
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_c_comment
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("//");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(dip_inv("\n\r"));
      ok=dev.go_any(body,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_raw_sep:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_sep)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,s,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(" \r\n\t");
      ok=dev.go_any(s,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_comment  )\
  F(t_c_comment)\
  F(t_raw_sep  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_str<vector<TAutoPtr<i_sep>>>(value);
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_name{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,s,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_name
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ09"));
    ok=dev.go_any(s,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
};
struct t_name_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_name,n,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name_with_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_name_with_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    dev.go_auto($sep0);
    ok=dev.go_auto(n);
    if(!ok)return ok;
    dev.go_auto($sep2);
    return ok;
  }
};
struct t_class_decl:public i_type_decl{
  //===>>===i_class_impl_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_of)\
    ADD(t_semicolon)\
    ADD(t_class_body)\
  ADDEND()
  class i_class_impl;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_class_impl_visitor{
  public:
    typedef t_class_decl::i_class_impl i_class_impl;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_class_decl::U U;//typedef t_class_decl::U U;
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
    static TYPE*UberCast(i_class_impl*p){
      if(!p)return nullptr;Is<TYPE,i_class_impl_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_class_impl*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_class_impl_visitor{
  //  void Do(t_of&r){}
  //  void Do(t_semicolon&r){}
  //  void Do(t_class_body&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_class_impl_visitor
  struct i_class_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_class_impl)OWNER(t_class_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_class_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_class_impl
  public:
    typedef i_class_impl_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_class_impl()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_of);
        F(t_semicolon);
        F(t_class_body);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_of:public i_class_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_of)PARENT(i_class_impl)OWNER(t_class_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,n,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_of
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_of
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("of");
      if(!ok)return ok;
      dev.go_auto($sep1);
      ok=dev.go_auto(n);
      if(!ok)return ok;
      dev.go_auto($sep3);
      ok=dev.go_const(";");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_semicolon:public i_class_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon)PARENT(i_class_impl)OWNER(t_class_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_semicolon
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_semicolon
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
  struct t_class_body:public i_class_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_body)PARENT(i_class_impl)OWNER(t_class_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<t_name_with_sep>,interfaces,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_class_body
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_class_body
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
      ok=dev.go_vec(interfaces,",");
      if(!ok)return ok;
      dev.go_auto($sep3);
      ok=dev.go_const(")");
      if(!ok)return ok;
      ok=dev.go_end(body,"end;");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_of        )\
  F(t_semicolon )\
  F(t_class_body)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<i_class_impl>,impl,DEF,$,$)\
ADDEND()
//=====+>>>>>t_class_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_class_decl
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_const("=");
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("class");
    if(!ok)return ok;
    dev.go_auto($sep5);
    dev.go_auto(impl);
    return ok;
  }
public:
};
struct t_field{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(t_name,type,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDEND()
//=====+>>>>>t_field
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_field
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    dev.go_auto($sep0);
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep2);
    ok=dev.go_const(":");
    if(!ok)return ok;
    dev.go_auto($sep4);
    ok=dev.go_auto(type);
    if(!ok)return ok;
    dev.go_auto($sep6);
    ok=dev.go_const(";");
    if(!ok)return ok;
    dev.go_auto($sep8);
    return ok;
  }
};
struct t_record_decl:public i_type_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_record_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(vector<t_field>,fields,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDEND()
//=====+>>>>>t_record_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_record_decl
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_const("=");
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("record");
    if(!ok)return ok;
    dev.go_auto($sep5);
    dev.go_auto(fields);
    ok=dev.go_const("end");
    if(!ok)return ok;
    dev.go_auto($sep8);
    ok=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};
struct t_proc_decl:public i_type_decl{
  struct t_of{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_of)OWNER(t_proc_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_name,n,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_of
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_of
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      dev.go_auto($sep0);
      ok=dev.go_const("of");
      if(!ok)return ok;
      dev.go_auto($sep2);
      ok=dev.go_auto(n);
      if(!ok)return ok;
      dev.go_auto($sep4);
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_of)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_proc_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,proc_name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_name,param_name,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDVAR(t_sep,$sep10,DEF,$,$)\
ADDVAR(t_name,param_type,DEF,$,$)\
ADDVAR(TAutoPtr<t_of>,of,DEF,$,$)\
ADDEND()
//=====+>>>>>t_proc_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_proc_decl
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(proc_name);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_const("=");
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("procedure");
    if(!ok)return ok;
    dev.go_auto($sep5);
    ok=dev.go_const("(");
    if(!ok)return ok;
    ok=dev.go_auto(param_name);
    if(!ok)return ok;
    dev.go_auto($sep8);
    ok=dev.go_const(":");
    if(!ok)return ok;
    dev.go_auto($sep10);
    ok=dev.go_auto(param_type);
    if(!ok)return ok;
    ok=dev.go_const(")");
    if(!ok)return ok;
    dev.go_auto(of);
    ok=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_type_ptr_decl:public i_type_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_ptr_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_name,type,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_ptr_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type_ptr_decl
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_const("=");
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("^");
    if(!ok)return ok;
    ok=dev.go_auto(type);
    if(!ok)return ok;
    dev.go_auto($sep6);
    ok=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};
struct t_array_decl:public i_type_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_name,from,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDVAR(t_sep,$sep11,DEF,$,$)\
ADDVAR(t_name,to,DEF,$,$)\
ADDVAR(t_sep,$sep13,DEF,$,$)\
ADDVAR(t_sep,$sep15,DEF,$,$)\
ADDVAR(t_sep,$sep17,DEF,$,$)\
ADDVAR(t_name,type,DEF,$,$)\
ADDVAR(t_sep,$sep19,DEF,$,$)\
ADDEND()
//=====+>>>>>t_array_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_array_decl
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_const("=");
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("array");
    if(!ok)return ok;
    dev.go_auto($sep5);
    ok=dev.go_const("[");
    if(!ok)return ok;
    dev.go_auto($sep7);
    ok=dev.go_auto(from);
    if(!ok)return ok;
    dev.go_auto($sep9);
    ok=dev.go_const("..");
    if(!ok)return ok;
    dev.go_auto($sep11);
    ok=dev.go_auto(to);
    if(!ok)return ok;
    dev.go_auto($sep13);
    ok=dev.go_const("]");
    if(!ok)return ok;
    dev.go_auto($sep15);
    ok=dev.go_const("of");
    if(!ok)return ok;
    dev.go_auto($sep17);
    ok=dev.go_auto(type);
    if(!ok)return ok;
    dev.go_auto($sep19);
    ok=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sep_type_decl:public i_type_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_type_decl)PARENT(i_type_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_type_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_type_decl
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
struct t_types:public i_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_types)PARENT(i_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_type_decl>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_types
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_types
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_const("type");
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
};
struct t_var:public i_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)PARENT(i_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_field>,fields,DEF,$,$)\
ADDEND()
//=====+>>>>>t_var
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_var
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_const("var");
    if(!ok)return ok;
    ok=dev.go_auto(fields);
    if(!ok)return ok;
    return ok;
  }
};
struct t_func:public i_decl{
  struct t_ret_type{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_type)OWNER(t_func)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,t,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ret_type
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ret_type
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const(":");
      if(!ok)return ok;
      ok=dev.go_auto(t);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_ret_type)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func)PARENT(i_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,kb,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(string,params,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDVAR(TAutoPtr<t_ret_type>,type,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDEND()
//=====+>>>>>t_func
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_func
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    static const auto g_static_var_0=QapStrFinder::fromArr(split("function,procedure",","));
    ok=dev.go_any_str_from_vec(kb,g_static_var_0);
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_auto(name);
    if(!ok)return ok;
    dev.go_auto($sep3);
    ok=dev.go_const("(");
    if(!ok)return ok;
    ok=dev.go_end(params,")");
    if(!ok)return ok;
    dev.go_auto($sep6);
    dev.go_auto(type);
    dev.go_auto($sep8);
    ok=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_sep_decl:public i_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_decl)PARENT(i_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_decl
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
struct t_unit{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_unit)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDVAR(vector<t_name_with_sep>,modules_decl,DEF,$,$)\
ADDVAR(t_sep,$sep10,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_decl>>,decls_decl,DEF,$,$)\
ADDVAR(t_sep,$sep13,DEF,$,$)\
ADDVAR(vector<t_name_with_sep>,modules_impl,DEF,$,$)\
ADDVAR(t_sep,$sep17,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_decl>>,decls_impl,DEF,$,$)\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_unit
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_unit
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_const("unit");
    if(!ok)return ok;
    dev.go_auto($sep1);
    ok=dev.go_auto(name);
    if(!ok)return ok;
    ok=dev.go_const(";");
    if(!ok)return ok;
    dev.go_auto($sep4);
    ok=dev.go_const("interface");
    if(!ok)return ok;
    dev.go_auto($sep6);
    ok=dev.go_const("uses");
    if(!ok)return ok;
    ok=dev.go_vec(modules_decl,",");
    if(!ok)return ok;
    ok=dev.go_const(";");
    if(!ok)return ok;
    dev.go_auto($sep10);
    dev.go_auto(decls_decl);
    ok=dev.go_const("implementation");
    if(!ok)return ok;
    dev.go_auto($sep13);
    ok=dev.go_const("uses");
    if(!ok)return ok;
    ok=dev.go_vec(modules_impl,",");
    if(!ok)return ok;
    ok=dev.go_const(";");
    if(!ok)return ok;
    dev.go_auto($sep17);
    dev.go_auto(decls_impl);
    ok=dev.go_end(body,"end.");
    if(!ok)return ok;
    return ok;
  }
};
void i_type_decl::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,6> lex={
    F(t_class_decl,gen_dips("09AZaz")),
    F(t_record_decl,gen_dips("09AZaz")),
    F(t_proc_decl,gen_dips("09AZaz")),
    F(t_type_ptr_decl,gen_dips("09AZaz")),
    F(t_array_decl,gen_dips("09AZaz")),
    F(t_sep_type_decl,"\t\n\r /{")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_decl::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case 't':F(t_types);
    case 'v':F(t_var);
    case 'f':
    case 'p':F(t_func);
    case '\t':
    case '\n':
    case '\r':
    case ' ':
    case '/':
    case '{':F(t_sep_decl);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_sep::i_sep::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '{':F(t_comment);
    case '/':F(t_c_comment);
    case '\t':
    case '\n':
    case '\r':
    case ' ':F(t_raw_sep);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_class_decl::i_class_impl::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case 'o':F(t_of);
    case ';':F(t_semicolon);
    case '(':F(t_class_body);
    default:{scope.ok=false;return;}
  }
  #undef F
}
/*
//list of types:
F(t_sep)F(t_name)F(t_name_with_sep)F(t_class_decl)F(t_field)F(t_record_decl)
F(t_proc_decl)F(t_type_ptr_decl)F(t_array_decl)F(t_sep_type_decl)F(t_types)
F(t_var)F(t_func)F(t_sep_decl)F(t_unit)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fsep%7b%0a%20%20t%5fcomment%3ai%5fsep%7b%22%7b%22%20string%20s%3dend%28%22%7d
%22%29%3b%7d%0a%20%20t%5fc%5fcomment%3ai%5fsep%7b%22%2f%2f%22%20string%20body%3d
any%28dip%5finv%28%22%5cn%5cr%22%29%29%3b%7d%0a%20%20t%5fraw%5fsep%3ai%5fsep%7bs
tring%20s%3dany%28%22%20%5cr%5cn%5ct%22%29%3b%7d%0a%20%20string%20value%3dstr%3c
vector%3cTAutoPtr%3ci%5fsep%3e%3e%3e%28%29%3b%0a%7d%0ausing%20%22%20%22%20as%20t
%5fsep%3b%0at%5fname%7bstring%20s%3dany%28gen%5fdips%28%22azAZ09%22%29%29%3b%7d%
0at%5fname%5fwith%5fsep%7b%22%20%22%3f%20t%5fname%20n%3b%20%22%20%22%3f%7d%0at%5
fclass%5fdecl%3ai%5ftype%5fdecl%7b%0a%20%20t%5fof%3ai%5fclass%5fimpl%7b%22of%22%
20%22%20%22%3f%20t%5fname%20n%3b%20%22%20%22%3f%20%22%3b%22%7d%0a%20%20t%5fsemic
olon%3ai%5fclass%5fimpl%7b%22%3b%22%7d%0a%20%20t%5fclass%5fbody%3ai%5fclass%5fim
pl%7b%0a%20%20%20%20%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3c
t%5fname%5fwith%5fsep%3e%20interfaces%3dvec%28%22%2c%22%29%3b%0a%20%20%20%20%22%
20%22%3f%0a%20%20%20%20%22%29%22%0a%20%20%20%20string%20body%3dend%28%22end%3b%2
2%29%3b%20%2f%2f%20%e7%e0%e3%eb%f3%f8%ea%e0%2c%20%ef%f0%ee%f1%f2%ee%20%f7%e8%f2%
e0%e5%ec%20%e2%f1%b8%20%e4%ee%20%ea%ee%ed%f6%e0%20%ef%ee%ea%e0%2e%0a%20%20%7d%0a
%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%0a%20%20%22%20%2
2%3f%0a%20%20%22class%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fclass%5fimp
l%3e%20impl%3f%3b%0a%7d%0at%5ffield%7b%22%20%22%3f%20t%5fname%20name%3b%20%22%20
%22%3f%20%22%3a%22%20%22%20%22%3f%20t%5fname%20type%3b%20%22%20%22%3f%20%22%3b%2
2%20%22%20%22%3f%7d%0at%5frecord%5fdecl%3ai%5ftype%5fdecl%7b%0a%20%20t%5fname%20
name%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%0a%20%20%22%20%22%3f%0a%20%20%22r
ecord%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5ffield%3e%20fields%3f%3b%0a%20
%20%22end%22%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%7d%0at%5fproc%5fdecl%3ai%
5ftype%5fdecl%7b%0a%20%20t%5fof%7b%22%20%22%3f%20%22of%22%20%22%20%22%3f%20t%5fn
ame%20n%3b%20%22%20%22%3f%7d%0a%20%20t%5fname%20proc%5fname%3b%0a%20%20%22%20%22
%3f%0a%20%20%22%3d%22%0a%20%20%22%20%22%3f%0a%20%20%22procedure%22%0a%20%20%22%2
0%22%3f%0a%20%20%22%28%22%0a%20%20t%5fname%20param%5fname%3b%0a%20%20%22%20%22%3
f%0a%20%20%22%3a%22%0a%20%20%22%20%22%3f%0a%20%20t%5fname%20param%5ftype%3b%0a%2
0%20%22%29%22%0a%20%20TAutoPtr%3ct%5fof%3e%20of%3f%3b%0a%20%20%22%3b%22%0a%7d%0a
t%5ftype%5fptr%5fdecl%3ai%5ftype%5fdecl%7b%0a%20%20t%5fname%20name%3b%0a%20%20%2
2%20%22%3f%0a%20%20%22%3d%22%0a%20%20%22%20%22%3f%0a%20%20%22%5e%22%0a%20%20t%5f
name%20type%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%7d%0at%5farray%5fdecl%3
ai%5ftype%5fdecl%7b%0a%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20%22%
3d%22%0a%20%20%22%20%22%3f%0a%20%20%22array%22%0a%20%20%22%20%22%3f%0a%20%20%22%
5b%22%0a%20%20%22%20%22%3f%0a%20%20t%5fname%20from%3b%0a%20%20%22%20%22%3f%0a%20
%20%22%2e%2e%22%0a%20%20%22%20%22%3f%0a%20%20t%5fname%20to%3b%0a%20%20%22%20%22%
3f%0a%20%20%22%5d%22%0a%20%20%22%20%22%3f%0a%20%20%22of%22%3f%0a%20%20%22%20%22%
3f%0a%20%20t%5fname%20type%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%7d%0at%5
fsep%5ftype%5fdecl%3ai%5ftype%5fdecl%7b%22%20%22%7d%0at%5ftypes%3ai%5fdecl%7b%0a
%20%20%22type%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ci%5ftype%5fdecl%3e%20arr%
3b%0a%7d%0at%5fvar%3ai%5fdecl%7b%0a%20%20%22var%22%0a%20%20vector%3ct%5ffield%3e
%20fields%3b%0a%7d%0at%5ffunc%3ai%5fdecl%7b%0a%20%20t%5fret%5ftype%7b%22%3a%22%2
0t%5fname%20t%3b%7d%0a%20%20string%20kb%3dany%5fstr%5ffrom%5fvec%28split%28%22fu
nction%2cprocedure%22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22%3f%0a%20%20t%5fname
%20name%3b%0a%20%20%22%20%22%3f%0a%20%20%22%28%22%0a%20%20string%20params%3dend%
28%22%29%22%29%3b%20%2f%2f%20%e7%e0%e3%eb%f3%f8%ea%e0%0a%20%20%22%20%22%3f%0a%20
%20TAutoPtr%3ct%5fret%5ftype%3e%20type%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b
%22%0a%7d%0at%5fsep%5fdecl%3ai%5fdecl%7b%22%20%22%7d%0at%5funit%7b%0a%20%20%22un
it%22%0a%20%20%22%20%22%3f%0a%20%20t%5fname%20name%3b%0a%20%20%22%3b%22%0a%20%20
%22%20%22%3f%0a%20%20%22interface%22%0a%20%20%22%20%22%3f%0a%20%20%22uses%22%0a%
20%20vector%3ct%5fname%5fwith%5fsep%3e%20modules%5fdecl%3dvec%28%22%2c%22%29%3b%
0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ci%5fdecl%3e%20decls%5fde
cl%3f%3b%0a%20%20%22implementation%22%0a%20%20%22%20%22%3f%0a%20%20%22uses%22%0a
%20%20vector%3ct%5fname%5fwith%5fsep%3e%20modules%5fimpl%3dvec%28%22%2c%22%29%3b
%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ci%5fdecl%3e%20decls%5fi
mpl%3f%3b%0a%20%20string%20body%3dend%28%22end%2e%22%29%3b%20%2f%2f%20%e7%e0%e3%
eb%f3%f8%ea%e0%0a%7d
*/