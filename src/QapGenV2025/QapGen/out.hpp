// 2071.406800 ms
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code)
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_code_with_sep_visitor
struct i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code_with_sep)
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_type_item_visitor
struct i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_item)
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_type_templ_visitor
struct i_type_templ{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_templ)
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_cpp_code_visitor
struct i_cpp_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cpp_code)
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
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)
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
  ADD(t_target_item)\
  ADD(t_target_decl)\
ADDEND()
class i_target_item;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_target_item_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_target_item_visitor
struct i_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_target_item)
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
      F(t_target_item);
      F(t_target_decl);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
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
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(foo);
    if(!ok)return ok;
    D+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  static const vector<string>&foo_attributes(){static const vector<string> a={"skip"};return a;}
  static const vector<string>&sep_attributes(){static const vector<string> a={"optimize","inline","\"sep\"","(\"sep\")","[sep]","{ sep , sep }"};return a;}
};
struct t_name_code:public i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_str<t_name::t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return value;};
};
struct t_num_code:public i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return body.body;};
};
struct t_str_seq{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_seq)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_seq
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_seq
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("\"");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("\"");
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_str_seq)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_str_seq,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_str_seq
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_str_seq
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(sep);
    if(!ok)return ok;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_code:public i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(first);
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_const("'");
    if(!ok)return ok;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    D+=dev.go_const("'");
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{
    return body->get_code();
  }
  string get_value()const{
    return body->get_value();
  }
  string make_code()const{return "'"+get_code()+"'";}
};
struct t_sign_code:public i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return CToS(body.body);}
};
struct t_name_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
};
struct t_num_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
};
struct t_str_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
};
struct t_char_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
};
struct t_sign_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
};
struct t_soft_brackets_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    M+=dev.go_const(")");
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    M+=dev.go_const("]");
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code_with_sep)PARENT(i_code_with_sep)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_code>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_code
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_code
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return vector_make_code(arr);};
};
struct t_soft_brackets_code:public i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_const(")");
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_const("]");
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code)PARENT(i_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(body);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_const("}");
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_semicolon
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_semicolon
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};
struct t_value_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_code_with_sep>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_value_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_value_item
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_minor<t_semicolon>(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body->make_code();
  }
};
struct t_value{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_value
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_value
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_const("=");
    if(!ok)return ok;
    M+=dev.go_str<vector<t_value_item>>(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const
  {
    string out=body;
    //for(int i=0;i<arr.size();i++)out+=arr[i].make_code();
    return out;
  }
};
struct t_type_scope{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_type_scope
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type_scope
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_const("::");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "::";
  }
};
struct t_type_templ{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_type_templ>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type_templ
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_type_item_string:public i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_string)PARENT(i_type_item)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.get_code();
  };
};
struct t_type_item_char:public i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_char)PARENT(i_type_item)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.get_code();
  };
};
struct t_type_item_number:public i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_number)PARENT(i_type_item)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body.body;
  };
};
struct t_scope_type_item;
struct t_type_item_type:public i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_type)PARENT(i_type_item)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(scope);
    if(!ok)return ok;
    M+=dev.go_auto(type);
    if(!ok)return ok;
    O+=dev.go_auto(param);
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
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
struct t_scope_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_type_scope,scope,DEF,$,$)\
ADDVAR(t_type_item_type,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_scope_type_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_scope_type_item
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(scope);
    if(!ok)return ok;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    string out;
    out+=scope.make_code();
    out+=body.make_code();
    /*if(body){
      auto*p=body.get();
      out+=p->make_code();
    }*/
    return out;
  }
};
struct t_type_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_type_scope>,scope,DEF,$,$)\
ADDVAR(t_type_item_type,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type_expr
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(scope);
    if(!ok)return ok;
    M+=dev.go_auto(body);
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_type_item>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ_param
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type_templ_param
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body->make_code();
  };
};
struct t_sep_type_templ_param{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_type_templ_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_type_templ_param,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_type_templ_param
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_type_templ_param
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_const(",");
    if(!ok)return ok;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    string out;
    out+=",";
    out+=body.make_code();
    return out;
  };
};
struct t_type_templ_params{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_params)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(first);
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_angle)PARENT(i_type_templ)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("<");
    if(!ok)return ok;
    O+=dev.go_auto(params);
    if(!ok)return ok;
    M+=dev.go_const(">");
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_soft)PARENT(i_type_templ)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(params);
    if(!ok)return ok;
    M+=dev.go_const(")");
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
struct t_struct_cmd_mode{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_mode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,DEF,$,$)\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmd_mode
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_struct_cmd_mode
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    static const auto g_static_var_0=CharMask::fromStr("MO");
    M+=dev.go_any_char(body,g_static_var_0);
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    M+=dev.go_const("+=");
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    return ok;
  }
};
struct t_sep_value{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_value)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(t_value_item,value,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_value
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_value
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    M+=dev.go_auto(value);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    return ok;
  }
};
struct t_attr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_attr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_sep_value>,arr,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_attr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_attr
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_vec(arr,",");
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_const("]");
    if(!ok)return ok;
    return ok;
  }
};
struct t_struct_field{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_struct_cmd_mode>,mode,DEF,$,$)\
ADDVAR(t_sep,sepcm,DEF,$,$)\
ADDVAR(t_type_expr,type,DEF,$,$)\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
ADDVAR(t_sep,sep2,DEF,$,$)\
ADDVAR(TAutoPtr<t_attr>,attr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_field
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_struct_field
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(mode);
    if(!ok)return ok;
    O+=dev.go_auto(sepcm);
    if(!ok)return ok;
    M+=dev.go_auto(type);
    if(!ok)return ok;
    M+=dev.go_auto(sep0);
    if(!ok)return ok;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    O+=dev.go_auto(value);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_const(";");
    if(!ok)return ok;
    O+=dev.go_auto(sep2);
    if(!ok)return ok;
    O+=dev.go_auto(attr);
    if(!ok)return ok;
    return ok;
  }
  string make_code(int id,t_ic_dev&icdev)const{
    vector<string> out;
    string mode=value?"SET":"DEF";
    //out.push_back(IToS(id));
    auto t=type.make_code();
    if(bool vec_algo=true){
      auto a=split(t,"<");
      if(a.size()==2&&a[0]=="vector"){
        auto b=split(a[1],">");
        QapAssert(b.size()==2);
        QapAssert(b[1]=="");
        if(icdev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>";
      }
    }
    if(icdev.need_tautoptr(t))t="TAutoPtr<"+t+">";
    out.push_back(t);
    out.push_back(name.get());
    out.push_back(mode);
    out.push_back(!value?"$":value->make_code());
    string s;
    //if(attr){
    //  bool ok=save_obj(*attr.get(),s);
    //  QapAssert(ok);
    //}
    return "ADDVAR("+join(out,",")+","+(s.empty()?"$":s)+")\\\n";
  }
};
struct t_sep_struct_field{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_field,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_field
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_struct_field
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code(int id,t_ic_dev&icdev)const{
    return body.make_code(id,icdev);
  }
};
struct t_templ_params{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_params)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_params
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_templ_params
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_const("<");
    if(!ok)return ok;
    D+=dev.go_str<TAutoPtr<t_type_templ_params>>(body);
    if(!ok)return ok;
    D+=dev.go_const(">");
    if(!ok)return ok;
    return ok;
  }
};
struct t_cmd_param;
struct t_cmd_params{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_params)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_cmd_param>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cmd_params
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_cmd_params
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_vec(arr,",");
    if(!ok)return ok;
    return ok;
  }
};
struct t_cmd_param{
  //===>>===i_expr_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_expr_call)\
    ADD(t_expr_str)\
    ADD(t_expr_var)\
  ADDEND()
  class i_expr;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_expr_visitor{
  public:
    typedef t_cmd_param::i_expr i_expr;
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
    static TYPE*UberCast(i_expr*p){
      if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_expr*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_expr_visitor
  struct i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_cmd_param)
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
  ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
      D+=dev.go_vec(arr,"+");
      if(!ok)return ok;
      return ok;
    }
};
  struct t_expr_call:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_call)PARENT(i_expr)OWNER(t_cmd_param)
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
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
      D+=dev.go_auto(func);
      if(!ok)return ok;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_auto(params);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
};
  struct t_expr_str:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_str)PARENT(i_expr)OWNER(t_cmd_param)
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
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
      D+=dev.go_str<t_str_seq>(body);
      if(!ok)return ok;
      return ok;
    }
};
  struct t_expr_var:public i_expr{
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
        t_fallback $scope(dev,__FUNCTION__);
        auto&ok=$scope.ok;
        auto&D=$scope.mandatory;
        auto&M=$scope.mandatory;
        auto&O=$scope.optional;
        D+=dev.go_const("this->");
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
        t_fallback $scope(dev,__FUNCTION__);
        auto&ok=$scope.ok;
        auto&D=$scope.mandatory;
        auto&M=$scope.mandatory;
        auto&O=$scope.optional;
        O+=dev.go_auto(self);
        if(!ok)return ok;
        M+=dev.go_auto(name);
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_var)PARENT(i_expr)OWNER(t_cmd_param)
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
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
      D+=dev.go_str<t_impl>(body);
      if(!ok)return ok;
      return ok;
    }
};
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_impl     )\
  F(t_expr_call)\
  F(t_expr_str )\
  F(t_expr_var )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cmd_param
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_cmd_param
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_str<t_impl>(body);
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_struct_cmd{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_struct_cmd_mode>,mode,DEF,$,$)\
ADDVAR(t_name,func,DEF,$,$)\
ADDVAR(string,templ_params,DEF,$,$)\
ADDVAR(t_cmd_params,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmd
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_struct_cmd
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(mode);
    if(!ok)return ok;
    M+=dev.go_auto(func);
    if(!ok)return ok;
    O+=dev.go_str<TAutoPtr<t_templ_params>>(templ_params);
    if(!ok)return ok;
    M+=dev.go_const("(");
    if(!ok)return ok;
    M+=dev.go_auto(params);
    if(!ok)return ok;
    M+=dev.go_const(");");
    if(!ok)return ok;
    return ok;
  }
  static bool find(const string&func){
    static const vector<string> arr=split("go_any_str_from_vec|go_any_arr_char|go_any|go_any_char","|");
    for(int i=0;i<arr.size();i++)if(arr[i]==func)return true;
    return false;
  }
  string make_code(int i){
    string out=mode?CToS(mode->body):"D";
    vector<string> params_code;
    {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
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
      out=vardecl+"    "+out+"+=dev."+func.get()+"("+param0+","+varname+");\n    if(!ok)return ok;\n";
      return out;
    }
    out="    "+out+"+=dev."+func.get()+templ_params+"("+join(params_code,",")+");\n    if(!ok)return ok;\n";
    return out;
  }
  string make_code_gp(){
    string out=mode?CToS(mode->body):"D";
    vector<string> params_code;
    {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
    out="    "+out+"+=dev."+func.get()+templ_params+"("+join(params_code,",")+");\n    if(!ok)return ok;\n";
    return out;
  }
};
struct t_sep_struct_cmd{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_cmd,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_cmd
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_struct_cmd
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code(int i){
    return body.make_code(i);
  }
};
struct t_struct_cmds{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmds)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_sep_struct_cmd>,arr,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmds
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_struct_cmds
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sep_struct_cmds{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmds)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_cmds,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_cmds
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_struct_cmds
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_cpp_code_sep:public i_cpp_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_sep)PARENT(i_cpp_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return sep.make_code();
  }
};
struct t_cpp_code_main:public i_cpp_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_main)PARENT(i_cpp_code)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    D+=dev.go_auto(body);
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
public:
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
      t_fallback $scope(dev,__FUNCTION__);
      auto&ok=$scope.ok;
      auto&D=$scope.mandatory;
      auto&M=$scope.mandatory;
      auto&O=$scope.optional;
      D+=dev.go_const("[::]");
      if(!ok)return ok;
      return ok;
    }
};
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_bayan)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_bayan>,bayan,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_cpp_code>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_code
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_cpp_code
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(bayan);
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
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
  string make_code()const{
    string out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(ex);
      auto*p=ex.get();
      out+=p->make_code();
    }
    return out;
  }
};
// test
struct t_struct_body{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_body)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_target_item>,nested,DEF,$,$)\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(vector<t_sep_struct_field>,arr,DEF,$,$)\
ADDVAR(TAutoPtr<t_sep_struct_cmds>,cmds,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_cpp_code>,cppcode,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_body
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_struct_body
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(nested);
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    O+=dev.go_auto(cmds);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    O+=dev.go_auto(cppcode);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
  struct t_target_item_out;
  struct t_out{
    vector<const t_target_item*> nested;
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
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
    {
      auto&arr=nested;
      out.nested.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&to=out.nested[i];
        to=&ex;
      }
    }
    {
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i,icdev));
      }
      out.provars=join(tmp,"");
    }
    if(cmds)
    {
      auto*pCmds=cmds.get();
      auto&arr=pCmds->body.arr;
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i));
      }
      out.procmds=join(tmp,"");
    }
    string sep=sep0.value.empty()?sep1.value:sep0.value;
    out.cppcode=cppcode?sep+cppcode->make_code()+"\n":"";
    return out;
  }
};
struct t_class_def:public i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_class_def)PARENT(i_def)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    static const auto g_static_var_2=QapStrFinder::fromArr(split("=>,:",","));
    M+=dev.go_any_str_from_vec(arrow_or_colon,g_static_var_2);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_auto(parent);
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def)PARENT(i_def)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    return ok;
  }
  t_out make_code(){
    t_out out;
    out.name=name.get();
    return out;
  }
};
struct t_target_item:public i_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_item)PARENT(i_target_item)
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
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    M+=dev.go_auto(def);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_auto(body);
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_decl)PARENT(i_target_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_target_decl
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    M+=dev.go_str<t_name>(name);
    if(!ok)return ok;
    O+=dev.go_auto(sep1);
    if(!ok)return ok;
    M+=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};
struct t_target{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_target_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_target
public:
  bool go(i_dev&dev){
    t_fallback $scope(dev,__FUNCTION__);
    auto&ok=$scope.ok;
    auto&D=$scope.mandatory;
    auto&M=$scope.mandatory;
    auto&O=$scope.optional;
    M+=dev.go_auto(arr);
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
bool i_code::t_poly_impl::load()
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

bool i_code_with_sep::t_poly_impl::load()
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

bool i_type_item::t_poly_impl::load()
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

bool i_type_templ::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_type_templ_angle);
  F(t_type_templ_soft);
  #undef F
  main();
  return scope.ok;
}

bool i_cpp_code::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_cpp_code_sep);
  F(t_cpp_code_main);
  #undef F
  main();
  return scope.ok;
}

bool i_def::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_class_def);
  F(t_struct_def);
  #undef F
  main();
  return scope.ok;
}

bool i_target_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_target_item);
  F(t_target_decl);
  #undef F
  main();
  return scope.ok;
}

bool t_cmd_param::i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_expr_call);
  F(t_expr_str);
  F(t_expr_var);
  #undef F
  main();
  return scope.ok;
}

/*
//list of types:
F(t_test20250618_atrr)F(i_code)F(t_name_code)F(t_num_code)F(t_str_seq)
F(t_sep_str_seq)F(t_str_code)F(t_char_code)F(t_sign_code)F(i_code_with_sep)
F(t_name_code_with_sep)F(t_num_code_with_sep)F(t_str_code_with_sep)
F(t_char_code_with_sep)F(t_sign_code_with_sep)F(t_soft_brackets_code_with_sep)
F(t_hard_brackets_code_with_sep)F(t_curly_brackets_code_with_sep)F(t_code)
F(t_soft_brackets_code)F(t_hard_brackets_code)F(t_curly_brackets_code)
F(t_semicolon)F(t_value_item)F(t_value)F(i_type_templ)F(t_type_scope)
F(t_type_templ)F(i_type_item)F(t_type_item_string)F(t_type_item_char)
F(t_type_item_number)F(t_type_item_type)F(t_scope_type_item)F(t_type_expr)
F(t_type_templ_param)F(t_sep_type_templ_param)F(t_type_templ_params)
F(t_type_templ_angle)F(t_type_templ_soft)F(t_struct_cmd_mode)F(t_sep_value)
F(t_attr)F(t_struct_field)F(t_sep_struct_field)F(t_templ_params)F(t_cmd_params)
F(t_cmd_param)F(t_struct_cmd)F(t_sep_struct_cmd)F(t_struct_cmds)
F(t_sep_struct_cmds)F(i_cpp_code)F(t_cpp_code_sep)F(t_cpp_code_main)
F(t_cpp_code)F(t_struct_body)F(i_def)F(t_class_def)F(t_struct_def)
F(t_target_item)F(t_target_decl)F(t_target)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5ftest20250618%5fatrr%7b%0a%20%20t%5ffoo%7b%7b%7d%5b%3a%3a%5d%7d%0a%20%20t%5ff
oo%20foo%3b%20%5bskip%5d%0a%20%20t%5fsep%20sep%3b%20%5boptimize%2cinline%2c%22se
p%22%2c%28%22sep%22%29%2c%5bsep%5d%2c%7b%20sep%20%2c%20sep%20%7d%5d%0a%20%20%7b%
0a%20%20%20%20go%5fauto%28foo%29%3b%0a%20%20%20%20go%5fauto%28sep%29%3b%0a%20%20
%7d%0a%7d%0a%0ai%5fcode%20%7b%0a%20%20virtual%20string%20make%5fcode%28%29const%
7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%22%22%3b%7d%3b%0a%7d%0a%0at%5fn
ame%5fcode%20%3d%3e%20i%5fcode%20%7b%0a%20%20string%20value%3b%0a%20%20%7b%0a%20
%20%20%20M%20%2b%3d%20go%5fstr%3ct%5fname%3a%3at%5fimpl%3e%28value%29%3b%0a%20%2
0%7d%0a%20%20string%20make%5fcode%28%29const%7breturn%20value%3b%7d%3b%0a%7d%0a%
0at%5fnum%5fcode%3d%3ei%5fcode%7b%0a%20%20t%5fnumber%20body%3b%0a%20%20%7b%0a%20
%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%
28%29const%7breturn%20body%2ebody%3b%7d%3b%0a%7d%0a%0at%5fstr%5fseq%7b%0a%20%20v
ector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%
3dgo%5fconst%28%22%5c%22%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%
20%20%20%20M%2b%3dgo%5fconst%28%22%5c%22%22%29%3b%0a%20%20%7d%0a%20%20string%20g
et%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20for%28int%20
i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20out%2b%3darr%5b
i%5d%2d%3eget%5fcode%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20out%3b%0a
%20%20%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20string%20out%
3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%
20%20%20%20%20out%2b%3darr%5bi%5d%2d%3eget%5fvalue%28%29%3b%0a%20%20%20%20%7d%0a
%20%20%20%20return%20out%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%
7breturn%20%22%5c%22%22%2bget%5fcode%28%29%2b%22%5c%22%22%3b%7d%0a%7d%0a%0at%5fs
ep%5fstr%5fseq%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fstr%5fseq%20body%3b%0a%20
%20%7b%0a%20%20%20%20go%5fauto%28sep%29%3b%0a%20%20%20%20go%5fauto%28body%29%3b%
0a%20%20%7d%0a%7d%0a%0at%5fstr%5fcode%3d%3ei%5fcode%7b%0a%20%20t%5fstr%5fseq%20f
irst%3b%0a%20%20vector%3ct%5fsep%5fstr%5fseq%3e%20arr%3b%0a%20%20%7b%0a%20%20%20
%20M%2b%3dgo%5fauto%28first%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%
20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3
dfirst%2eget%5fcode%28%29%3b%0a%20%20%20%20if%28%21arr%2eempty%28%29%29%0a%20%20
%20%20%7b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b
%29out%2b%3darr%5bi%5d%2ebody%2eget%5fcode%28%29%3b%0a%20%20%20%20%20%20int%20gg
%3d1%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20%22%5c%22%22%2bout%2b%22%5c%22%
22%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%5fcode%3d%3ei%5fcode%7b%0a%20%20TAutoPtr%3
ci%5fchar%5fitem%3e%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%27%22%2
9%3b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%20%20go%5fconst%28%22%27%22%2
9%3b%0a%20%20%7d%0a%20%20string%20get%5fcode%28%29const%7b%0a%20%20%20%20return%
20body%2d%3eget%5fcode%28%29%3b%0a%20%20%7d%0a%20%20string%20get%5fvalue%28%29co
nst%7b%0a%20%20%20%20return%20body%2d%3eget%5fvalue%28%29%3b%0a%20%20%7d%0a%20%2
0string%20make%5fcode%28%29const%7breturn%20%22%27%22%2bget%5fcode%28%29%2b%22%2
7%22%3b%7d%0a%7d%0a%0at%5fsign%5fcode%3d%3ei%5fcode%7b%0a%20%20t%5fsign%20body%3
b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20
make%5fcode%28%29const%7breturn%20CToS%28body%2ebody%29%3b%7d%0a%7d%0a%0ai%5fcod
e%5fwith%5fsep%7b%0a%20%20virtual%20string%20make%5fcode%28%29const%7bQapDebugMs
g%28%22no%20way%2e%22%29%3breturn%20%22%22%3b%7d%0a%7d%0a%0at%5fname%5fcode%5fwi
th%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fname%5fcode%20body%3b%0a%20%2
0t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%
20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28
%29const%7b%0a%20%20%20%20return%20body%2emake%5fcode%28%29%2bsep%2emake%5fcode%
28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fnum%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith
%5fsep%7b%0a%20%20t%5fnum%5fcode%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%
0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep
%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20retu
rn%20body%2emake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%
0at%5fstr%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fstr%5fco
de%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto
%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20str
ing%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20body%2emake%5fcode%28%29%
2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%5fcode%5fwith%5fsep
%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fchar%5fcode%20body%3b%0a%20%20t%5fsep
%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20
O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const
%7b%0a%20%20%20%20return%20body%2emake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b
%0a%20%20%7d%0a%7d%0a%0at%5fsign%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%
7b%0a%20%20t%5fsign%5fcode%20body%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%
20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b
%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20b
ody%2emake%5fcode%28%29%2bsep%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5f
soft%5fbrackets%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fse
p%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3b%0a
%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%
29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto
%28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%20%20O%
2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%
7b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%2
8%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29%2c%0a%20%20%20%20%20%
20sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%22%28
%22%2bv%5b0%5d%2bv%5b1%5d%2b%22%29%22%2bv%5b2%5d%3b%0a%20%20%7d%0a%7d%0a%0at%5fh
ard%5fbrackets%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fsep
%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3b%0a%
20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5b%22%2
9%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%
28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5d%22%29%3b%0a%20%20%20%20O%2
b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7
b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%28
%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29%2c%0a%20%20%20%20%20%2
0sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%22%5b%
22%2bv%5b0%5d%2bv%5b1%5d%2b%22%5d%22%2bv%5b2%5d%3b%0a%20%20%7d%0a%7d%0a%0at%5fcu
rly%5fbrackets%5fcode%5fwith%5fsep%3d%3ei%5fcode%5fwith%5fsep%7b%0a%20%20t%5fsep
%20sep0%3b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%5fwith%5fsep%3e%3e%20body%3b%0a%
20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%2
9%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%
28body%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%20%20O%2
b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7
b%0a%20%20%20%20string%20v%5b%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%28
%29%2c%0a%20%20%20%20%20%20vector%5fmake%5fcode%28body%29%2c%0a%20%20%20%20%20%2
0sep1%2emake%5fcode%28%29%2c%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%22%7b%
22%2bv%5b0%5d%2bv%5b1%5d%2b%22%7d%22%2bv%5b2%5d%3b%0a%20%20%7d%0a%7d%0a%0a%2f%2f
real%5fsource%5fdata%3a%0a%2f%2a%0at%5fname%5fcode%0at%5fnum%5fcode%0at%5fstr%5f
code%0at%5fchar%5fcode%0at%5fsign%5fcode%0at%5fsoft%5fbrackets%5fcode%0at%5fhard
%5fbrackets%5fcode%0at%5fcurly%5fbrackets%5fcode%0a%40%40%40public%3a%0a%20%20st
ring%20make%5fcode%28%29const%7breturn%20body%2emake%5fcode%28%29%2bsep%2emake%5
fcode%28%29%3b%7d%0a%2a%2f%0a%0a%2f%2freal%5fsource%5fcode%3a%0a%2f%2a%0avar%20m
k%3dPOST%5b%27data%27%5d%2esplit%28%22%40%40%40%22%29%5b1%5d%3b%0avar%20gen%3dfu
nction%28lex%2cmk%29%7b%0a%20%20return%20lex%2b%22%5fwith%5fsep%3d%3ei%5fcode%5f
with%5fsep%7b%22%2blex%2b%22%20body%3bt%5fsep%20sep%3b%7bM%2b%3dgo%5fauto%28body
%29%3bO%2b%3dgo%5fauto%28sep%29%3b%7d%22%2bmk%2b%22%5cn%7d%22%3b%0a%7d%0avar%20o
ut%3d%5b%5d%3b%0avar%20arr%3dPOST%5b%27data%27%5d%2esplit%28%22%5cn%40%40%40%22%
29%5b0%5d%2esplit%28%22%5cr%22%29%2ejoin%28%22%22%29%2esplit%28%22%5cn%22%29%3b%
0afor%28var%20i%3d0%3bi%3carr%2elength%3bi%2b%2b%29%7b%0a%20%20out%2epush%28gen%
28arr%5bi%5d%2cmk%29%29%3b%0a%7d%0areturn%20out%2ejoin%28%22%5cn%22%29%3b%0a%2a%
2f%0a%0at%5fcode%7b%0a%20%20vector%3cTAutoPtr%3ci%5fcode%3e%3e%20arr%3b%0a%20%20
%7b%0a%20%20%20%20go%5fauto%28arr%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode
%28%29const%7breturn%20vector%5fmake%5fcode%28arr%29%3b%7d%3b%0a%7d%0a%0at%5fsof
t%5fbrackets%5fcode%3d%3ei%5fcode%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20TAutoPtr%
3ct%5fcode%3e%20body%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b
%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%2
0%20%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29
%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%7d%0a%20%20string
%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20v%5b3%5d%3d%7b%0a%20%20%20%2
0%20%20sep0%2emake%5fcode%28%29%2c%0a%20%20%20%20%20%20body%3fbody%2d%3emake%5fc
ode%28%29%3a%22%22%2c%0a%20%20%20%20%20%20sep1%2emake%5fcode%28%29%0a%20%20%20%2
0%7d%3b%0a%20%20%20%20return%20%22%28%22%2bv%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2b%22%
29%22%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5fhard%5fbrackets%5fcode%3d%3ei%5fcode%7b%0
a%20%20t%5fsep%20sep0%3b%0a%20%20TAutoPtr%3ct%5fcode%3e%20body%3b%0a%20%20t%5fse
p%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5b%22%29%3b%0a%20%
20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28body%29%3
b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28
%22%5d%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%
20%20string%20v%5b3%5d%3d%7b%0a%20%20%20%20%20%20sep0%2emake%5fcode%28%29%2c%0a%
20%20%20%20%20%20body%3fbody%2d%3emake%5fcode%28%29%3a%22%22%2c%0a%20%20%20%20%2
0%20sep1%2emake%5fcode%28%29%0a%20%20%20%20%7d%3b%0a%20%20%20%20return%20%22%5b%
22%2bv%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2b%22%5d%22%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5
fcurly%5fbrackets%5fcode%3d%3ei%5fcode%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20TAut
oPtr%3ct%5fcode%3e%20body%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%2
0M%2b%3dgo%5fconst%28%22%7b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b
%0a%20%20%20%20O%2b%3dgo%5fauto%28body%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28se
p1%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%7d%0a%20%20s
tring%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20v%5b3%5d%3d%7b%0a%20%20
%20%20%20%20sep0%2emake%5fcode%28%29%2c%0a%20%20%20%20%20%20body%3fbody%2d%3emak
e%5fcode%28%29%3a%22%22%2c%0a%20%20%20%20%20%20sep1%2emake%5fcode%28%29%0a%20%20
%20%20%7d%3b%0a%20%20%20%20return%20%22%7b%22%2bv%5b0%5d%2bv%5b1%5d%2bv%5b2%5d%2
b%22%7d%22%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5fsemicolon%7b%0a%20%20%7b%0a%20%20%20
%20go%5fconst%28%22%3b%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fvalue%5fitem%7b%0a%20
%20TAutoPtr%3ci%5fcode%5fwith%5fsep%3e%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5f
minor%3ct%5fsemicolon%3e%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%2
8%29const%7b%0a%20%20%20%20return%20body%2d%3emake%5fcode%28%29%3b%0a%20%20%7d%0
a%7d%0a%0at%5fvalue%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20string%20body%3b%0a%20%2
0%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%
28%22%3d%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fstr%3cvector%3ct%5fvalue%5fitem%3e%3
e%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%0a%20%20%7b%0
a%20%20%20%20string%20out%3dbody%3b%0a%20%20%20%20%2f%2ffor%28int%20i%3d0%3bi%3c
arr%2esize%28%29%3bi%2b%2b%29out%2b%3darr%5bi%5d%2emake%5fcode%28%29%3b%0a%20%20
%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0ai%5ftype%5ftempl%7b%0a%20%20virtual
%20string%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3b%20ret
urn%20%22%22%3b%7d%3b%0a%7d%0a%0at%5ftype%5fscope%7b%0a%20%20%7b%0a%20%20%20%20g
o%5fconst%28%22%3a%3a%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29con
st%7b%0a%20%20%20%20return%20%22%3a%3a%22%3b%0a%20%20%7d%0a%7d%0a%0at%5ftype%5ft
empl%7b%0a%20%20TAutoPtr%3ci%5ftype%5ftempl%3e%20body%3b%0a%20%20%7b%0a%20%20%20
%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0ai%5ftype%5fitem%7b%0a%20%20virt
ual%20string%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3bret
urn%20%22%22%3b%7d%3b%0a%7d%0a%0at%5ftype%5fitem%5fstring%3d%3ei%5ftype%5fitem%7
b%0a%20%20t%5fstr%5fitem%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28body%29
%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%
20body%2eget%5fcode%28%29%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5ftype%5fitem%5fchar%3d
%3ei%5ftype%5fitem%7b%0a%20%20t%5fchar%5fitem%20body%3b%0a%20%20%7b%0a%20%20%20%
20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%
0a%20%20%20%20return%20body%2eget%5fcode%28%29%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5f
type%5fitem%5fnumber%3d%3ei%5ftype%5fitem%7b%0a%20%20t%5fnumber%20body%3b%0a%20%
20%7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fc
ode%28%29const%7b%0a%20%20%20%20return%20body%2ebody%3b%0a%20%20%7d%3b%0a%7d%0a%
0at%5fscope%5ftype%5fitem%3b%0at%5ftype%5fitem%5ftype%3d%3ei%5ftype%5fitem%7b%0a
%20%20TAutoPtr%3ct%5ftype%5fscope%3e%20scope%3b%0a%20%20t%5fname%20type%3b%0a%20
%20TAutoPtr%3ct%5ftype%5ftempl%3e%20param%3b%0a%20%20vector%3ct%5fscope%5ftype%5
fitem%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28scope%29%3b%0a%20
%20%20%20M%2b%3dgo%5fauto%28type%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28param%29
%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0a%20%20template%3ccl
ass%20TYPE%3e%0a%20%20static%20string%20weak%5farr%5fmake%5fcode%28const%20vecto
r%3cTYPE%3e%26arr%29%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20for%28int%20
i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20auto%26ex%3darr
%5bi%5d%3b%0a%20%20%20%20%20%20out%2b%3dex%2emake%5fcode%28%29%3b%0a%20%20%20%20
%7d%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29
const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20if%28scope%29out%2b%3dscope
%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20out%2b%3dtype%2eget%28%29%3b%0a%20%20%2
0%20if%28param%29%7b%0a%20%20%20%20%20%20auto%2ap%3dparam%2eget%28%29%3b%0a%20%2
0%20%20%20%20auto%2apParam%3dp%2d%3ebody%2eget%28%29%3b%0a%20%20%20%20%20%20QapA
ssert%28pParam%29%3b%0a%20%20%20%20%20%20out%2b%3dpParam%2d%3emake%5fcode%28%29%
3b%0a%20%20%20%20%7d%0a%20%20%20%20out%2b%3dweak%5farr%5fmake%5fcode%28this%2d%3
earr%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5fscope%5ftype
%5fitem%7b%0a%20%20t%5ftype%5fscope%20scope%3b%0a%20%20t%5ftype%5fitem%5ftype%20
body%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28scope%29%3b%0a%20%20%20%20go%5faut
o%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%2
0%20string%20out%3b%0a%20%20%20%20out%2b%3dscope%2emake%5fcode%28%29%3b%0a%20%20
%20%20out%2b%3dbody%2emake%5fcode%28%29%3b%0a%20%20%20%20%2f%2aif%28body%29%7b%0
a%20%20%20%20%20%20auto%2ap%3dbody%2eget%28%29%3b%0a%20%20%20%20%20%20out%2b%3dp
%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%7d%2a%2f%0a%20%20%20%20return%20out%3b
%0a%20%20%7d%0a%7d%0a%0at%5ftype%5fexpr%7b%0a%20%20TAutoPtr%3ct%5ftype%5fscope%3
e%20scope%3b%0a%20%20t%5ftype%5fitem%5ftype%20body%3b%0a%20%20%7b%0a%20%20%20%20
O%2b%3dgo%5fauto%28scope%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20
%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20string%20out%3b%
0a%20%20%20%20if%28scope%29out%2b%3dscope%2d%3emake%5fcode%28%29%3b%0a%20%20%20%
20out%2b%3dbody%2emake%5fcode%28%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d
%0a%7d%0a%0at%5ftype%5ftempl%5fparam%7b%0a%20%20TAutoPtr%3ci%5ftype%5fitem%3e%20
body%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20str
ing%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20body%2d%3emake%5fcode%28%
29%3b%0a%20%20%7d%3b%0a%7d%0a%0at%5fsep%5ftype%5ftempl%5fparam%7b%0a%20%20t%5fty
pe%5ftempl%5fparam%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%2c%22%29
%3b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcod
e%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3d%22%2c%22%3
b%0a%20%20%20%20out%2b%3dbody%2emake%5fcode%28%29%3b%0a%20%20%20%20return%20out%
3b%0a%20%20%7d%3b%0a%7d%0a%0at%5ftype%5ftempl%5fparams%7b%0a%20%20t%5ftype%5ftem
pl%5fparam%20first%3b%0a%20%20vector%3ct%5fsep%5ftype%5ftempl%5fparam%3e%20arr%3
b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28first%29%3b%0a%20%20%20%20O%2b%3d
go%5fauto%28arr%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%
20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3dfirst%2emake%5fcode%28%29%3b%0
a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%2
0%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20out%2b%3dex%2emake%5fcod
e%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20out%3b%0a%20%20%7d%3b%0a%7d%
0a%0at%5ftype%5ftempl%5fangle%3d%3ei%5ftype%5ftempl%7b%0a%20%20TAutoPtr%3ct%5fty
pe%5ftempl%5fparams%3e%20params%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%2
8%22%3c%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20M%2
b%3dgo%5fconst%28%22%3e%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29c
onst%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3d%22%3c%22%3b%0a%20%
20%20%20if%28params%29%7b%0a%20%20%20%20%20%20auto%2ap%3dparams%2eget%28%29%3b%0
a%20%20%20%20%20%20out%2b%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%7d%0a%20%
20%20%20out%2b%3d%22%3e%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%3b%0a%7d
%0a%0at%5ftype%5ftempl%5fsoft%3d%3ei%5ftype%5ftempl%7b%0a%20%20TAutoPtr%3ct%5fty
pe%5ftempl%5fparams%3e%20params%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%2
8%22%28%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28params%29%3b%0a%20%20%20%20M%2
b%3dgo%5fconst%28%22%29%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29c
onst%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20out%2b%3d%22%28%22%3b%0a%20%
20%20%20if%28params%29%7b%0a%20%20%20%20%20%20auto%2ap%3dparams%2eget%28%29%3b%0
a%20%20%20%20%20%20out%2b%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%7d%0a%20%
20%20%20out%2b%3d%22%29%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%3b%0a%7d
%0a%0at%5fstruct%5fcmd%5fmode%7b%0a%20%20char%20body%3b%0a%20%20t%5fsep%20sep0%3
b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fany%5fchar%28b
ody%2c%22MO%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20M
%2b%3dgo%5fconst%28%22%2b%3d%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3
b%0a%20%20%7d%0a%7d%0a%0at%5fsep%5fvalue%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20t%
5fvalue%5fitem%20value%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20O%
2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28value%29%3b%0a%20%2
0%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fattr%7b%0a%20%20
vector%3ct%5fsep%5fvalue%3e%20arr%3b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%
20%20%20M%2b%3dgo%5fconst%28%22%5b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fvec%28arr%
2c%22%2c%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M%2b%
3dgo%5fconst%28%22%5d%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fstruct%5ffield%7b%0a%2
0%20TAutoPtr%3ct%5fstruct%5fcmd%5fmode%3e%20mode%3b%0a%20%20t%5fsep%20sepcm%3b%0
a%20%20t%5ftype%5fexpr%20type%3b%0a%20%20t%5fsep%20sep0%3b%0a%20%20t%5fname%20na
me%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20TAutoPtr%3ct%5fvalue%3e%20value%3b%0a%20
%20t%5fsep%20sep2%3b%0a%20%20TAutoPtr%3ct%5fattr%3e%20attr%3b%0a%20%20%7b%0a%20%
20%20%20O%2b%3dgo%5fauto%28mode%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sepcm%29%
3b%0a%20%20%20%20M%2b%3dgo%5fauto%28type%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28
sep0%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28name%29%3b%0a%20%20%20%20O%2b%3dgo%5
fauto%28value%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20M%
2b%3dgo%5fconst%28%22%3b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep2%29%3b%0a
%20%20%20%20O%2b%3dgo%5fauto%28attr%29%3b%0a%20%20%7d%0a%20%20string%20make%5fco
de%28int%20id%2ct%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20vector%3cstring%3e
%20out%3b%0a%20%20%20%20string%20mode%3dvalue%3f%22SET%22%3a%22DEF%22%3b%0a%20%2
0%20%20%2f%2fout%2epush%5fback%28IToS%28id%29%29%3b%0a%20%20%20%20auto%20t%3dtyp
e%2emake%5fcode%28%29%3b%0a%20%20%20%20if%28bool%20vec%5falgo%3dtrue%29%7b%0a%20
%20%20%20%20%20auto%20a%3dsplit%28t%2c%22%3c%22%29%3b%0a%20%20%20%20%20%20if%28a
%2esize%28%29%3d%3d2%26%26a%5b0%5d%3d%3d%22vector%22%29%7b%0a%20%20%20%20%20%20%
20%20auto%20b%3dsplit%28a%5b1%5d%2c%22%3e%22%29%3b%0a%20%20%20%20%20%20%20%20Qap
Assert%28b%2esize%28%29%3d%3d2%29%3b%0a%20%20%20%20%20%20%20%20QapAssert%28b%5b1
%5d%3d%3d%22%22%29%3b%0a%20%20%20%20%20%20%20%20if%28icdev%2eneed%5ftautoptr%28b
%5b0%5d%29%29t%3d%22vector%3cTAutoPtr%3c%22%2bb%5b0%5d%2b%22%3e%3e%22%3b%0a%20%2
0%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20if%28icdev%2eneed%5ftautoptr%28
t%29%29t%3d%22TAutoPtr%3c%22%2bt%2b%22%3e%22%3b%0a%20%20%20%20out%2epush%5fback%
28t%29%3b%0a%20%20%20%20out%2epush%5fback%28name%2eget%28%29%29%3b%0a%20%20%20%2
0out%2epush%5fback%28mode%29%3b%0a%20%20%20%20out%2epush%5fback%28%21value%3f%22
%24%22%3avalue%2d%3emake%5fcode%28%29%29%3b%0a%20%20%20%20string%20s%3b%0a%20%20
%20%20%2f%2fif%28attr%29%7b%0a%20%20%20%20%2f%2f%20%20bool%20ok%3dsave%5fobj%28%
2aattr%2eget%28%29%2cs%29%3b%0a%20%20%20%20%2f%2f%20%20QapAssert%28ok%29%3b%0a%2
0%20%20%20%2f%2f%7d%0a%20%20%20%20return%20%22ADDVAR%28%22%2bjoin%28out%2c%22%2c
%22%29%2b%22%2c%22%2b%28s%2eempty%28%29%3f%22%24%22%3as%29%2b%22%29%5c%5c%5cn%22
%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%5fstruct%5ffield%7b%0a%20%20t%5fsep%20sep%3b%
0a%20%20t%5fstruct%5ffield%20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%
28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20stri
ng%20make%5fcode%28int%20id%2ct%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20retu
rn%20body%2emake%5fcode%28id%2cicdev%29%3b%0a%20%20%7d%0a%7d%0a%0at%5ftempl%5fpa
rams%7b%0a%20%20string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%3c%2
2%29%3b%0a%20%20%20%20go%5fstr%3cTAutoPtr%3ct%5ftype%5ftempl%5fparams%3e%3e%28bo
dy%29%3b%0a%20%20%20%20go%5fconst%28%22%3e%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fc
md%5fparam%3b%0at%5fcmd%5fparams%7b%0a%20%20vector%3ct%5fcmd%5fparam%3e%20arr%3b
%0a%20%20%7b%0a%20%20%20%20go%5fvec%28arr%2c%22%2c%22%29%3b%0a%20%20%7d%0a%7d%0a
%0at%5fcmd%5fparam%7b%0a%20%20t%5fimpl%7b%0a%20%20%20%20vector%3cTAutoPtr%3ci%5f
expr%3e%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fvec%28arr%2c%22%2
b%22%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fexpr%5fcall%3ai%5fexpr%7b%0
a%20%20%20%20t%5fname%20func%3b%0a%20%20%20%20TAutoPtr%3ct%5fcmd%5fparams%3e%20p
arams%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28func%29%3b%0a%20%20%2
0%20%20%20go%5fconst%28%22%28%22%29%3b%0a%20%20%20%20%20%20go%5fauto%28params%29
%3b%0a%20%20%20%20%20%20go%5fconst%28%22%29%22%29%3b%0a%20%20%20%20%7d%0a%20%20%
7d%0a%20%20t%5fexpr%5fstr%3ai%5fexpr%7b%0a%20%20%20%20string%20body%3b%0a%20%20%
20%20%7b%0a%20%20%20%20%20%20go%5fstr%3ct%5fstr%5fseq%3e%28body%29%3b%0a%20%20%2
0%20%7d%0a%20%20%7d%0a%20%20t%5fexpr%5fvar%3ai%5fexpr%7b%0a%20%20%20%20t%5fthis%
7b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20go%5fconst%28%22this%2d%3e%
22%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%7b%0a%
20%20%20%20%20%20TAutoPtr%3ct%5fthis%3e%20self%3b%0a%20%20%20%20%20%20t%5fname%2
0name%3b%0a%20%20%20%20%20%20%7b%0a%20%20%20%20%20%20%20%20O%2b%3dgo%5fauto%28se
lf%29%3b%0a%20%20%20%20%20%20%20%20M%2b%3dgo%5fauto%28name%29%3b%0a%20%20%20%20%
20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20string%20body%3b%0a%20%20%20%20%7b%0a%2
0%20%20%20%20%20go%5fstr%3ct%5fimpl%3e%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7
d%0a%20%20string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fstr%3ct%5fimpl%3e%28bo
dy%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fstruct%5fcmd%7b%0a%20%20TAutoPtr%3ct%5fstruc
t%5fcmd%5fmode%3e%20mode%3b%0a%20%20t%5fname%20func%3b%0a%20%20string%20templ%5f
params%3b%0a%20%20t%5fcmd%5fparams%20params%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3d
go%5fauto%28mode%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28func%29%3b%0a%20%20%20%2
0O%2b%3dgo%5fstr%3cTAutoPtr%3ct%5ftempl%5fparams%3e%3e%28templ%5fparams%29%3b%0a
%20%20%20%20M%2b%3dgo%5fconst%28%22%28%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%2
8params%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%29%3b%22%29%3b%0a%20%20%7d%0
a%20%20static%20bool%20find%28const%20string%26func%29%7b%0a%20%20%20%20static%2
0const%20vector%3cstring%3e%20arr%3dsplit%28%22go%5fany%5fstr%5ffrom%5fvec%7cgo%
5fany%5farr%5fchar%7cgo%5fany%7cgo%5fany%5fchar%22%2c%22%7c%22%29%3b%0a%20%20%20
%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29if%28arr%5bi%5d%3d%3dfun
c%29return%20true%3b%0a%20%20%20%20return%20false%3b%0a%20%20%7d%0a%20%20string%
20make%5fcode%28int%20i%29%7b%0a%20%20%20%20string%20out%3dmode%3fCToS%28mode%2d
%3ebody%29%3a%22D%22%3b%0a%20%20%20%20vector%3cstring%3e%20params%5fcode%3b%0a%2
0%20%20%20%7bauto%26arr%3dparams%2earr%3bfor%28int%20i%3d0%3bi%3carr%2esize%28%2
9%3bi%2b%2b%29params%5fcode%2epush%5fback%28arr%5bi%5d%2ebody%29%3b%7d%0a%20%20%
20%20string%20func%5fname%3dfunc%2eget%28%29%3b%0a%20%20%20%20bool%20smart%5ffun
c%3dfind%28func%5fname%29%3b%0a%20%20%20%20if%28smart%5ffunc%29%0a%20%20%20%20%7
b%0a%20%20%20%20%20%20QapAssert%28params%2earr%2esize%28%29%3d%3d2%29%3b%0a%20%2
0%20%20%20%20const%20auto%26param0%3dparams%2earr%5b0%5d%2ebody%3b%0a%20%20%20%2
0%20%20%20const%20auto%26param1%3dparams%2earr%5b1%5d%2ebody%3b%0a%20%20%20%20%2
0%20auto%20get%5fparam1%3d%5b%26func%5fname%2c%26param1%5d%28%29%2d%3estring%7b%
0a%20%20%20%20%20%20%20%20if%28func%5fname%3d%3d%22go%5fany%5fstr%5ffrom%5fvec%2
2%29return%20%22QapStrFinder%3a%3afromArr%28%22%2bparam1%2b%22%29%22%3b%0a%20%20
%20%20%20%20%20%20return%20%22CharMask%3a%3afromStr%28%22%2bparam1%2b%22%29%22%3
b%0a%20%20%20%20%20%20%7d%3b%0a%20%20%20%20%20%20string%20varname%3d%22g%5fstati
c%5fvar%5f%22%2bIToS%28i%29%3b%0a%20%20%20%20%20%20string%20vardecl%3d%22%20%20%
20%20static%20const%20auto%20%22%2bvarname%2b%22%3d%22%2bget%5fparam1%28%29%2b%2
2%3b%5cn%22%3b%0a%20%20%20%20%20%20out%3dvardecl%2b%22%20%20%20%20%22%2bout%2b%2
2%2b%3ddev%2e%22%2bfunc%2eget%28%29%2b%22%28%22%2bparam0%2b%22%2c%22%2bvarname%2
b%22%29%3b%5cn%20%20%20%20if%28%21ok%29return%20ok%3b%5cn%22%3b%0a%20%20%20%20%2
0%20return%20out%3b%0a%20%20%20%20%7d%0a%20%20%20%20out%3d%22%20%20%20%20%22%2bo
ut%2b%22%2b%3ddev%2e%22%2bfunc%2eget%28%29%2btempl%5fparams%2b%22%28%22%2bjoin%2
8params%5fcode%2c%22%2c%22%29%2b%22%29%3b%5cn%20%20%20%20if%28%21ok%29return%20o
k%3b%5cn%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%20%20string%20make%5
fcode%5fgp%28%29%7b%0a%20%20%20%20string%20out%3dmode%3fCToS%28mode%2d%3ebody%29
%3a%22D%22%3b%0a%20%20%20%20vector%3cstring%3e%20params%5fcode%3b%0a%20%20%20%20
%7bauto%26arr%3dparams%2earr%3bfor%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2
b%29params%5fcode%2epush%5fback%28arr%5bi%5d%2ebody%29%3b%7d%0a%20%20%20%20out%3
d%22%20%20%20%20%22%2bout%2b%22%2b%3ddev%2e%22%2bfunc%2eget%28%29%2btempl%5fpara
ms%2b%22%28%22%2bjoin%28params%5fcode%2c%22%2c%22%29%2b%22%29%3b%5cn%20%20%20%20
if%28%21ok%29return%20ok%3b%5cn%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%
0a%7d%0a%0at%5fsep%5fstruct%5fcmd%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fstruct
%5fcmd%20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20
%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28i
nt%20i%29%7b%0a%20%20%20%20return%20body%2emake%5fcode%28i%29%3b%0a%20%20%7d%0a%
7d%0a%0at%5fstruct%5fcmds%7b%0a%20%20vector%3ct%5fsep%5fstruct%5fcmd%3e%20arr%3b
%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%2
2%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20O%2b%3dgo%5faut
o%28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%7d%0a%7
d%0a%0at%5fsep%5fstruct%5fcmds%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20t%5fstruct%5f
cmds%20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%2
0%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0ai%5fcpp%5fcode%7b%0a%20
%20virtual%20string%20make%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%2
9%3breturn%20%22%22%3b%7d%0a%7d%0a%0at%5fcpp%5fcode%5fsep%20%3d%3e%20i%5fcpp%5fc
ode%7b%0a%20%20t%5fsep%20sep%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28sep%29%3b%
0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20se
p%2emake%5fcode%28%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fcpp%5fcode%5fmain%20%3d%3e%2
0i%5fcpp%5fcode%7b%0a%20%20TAutoPtr%3ci%5fcode%5fwith%5fsep%3e%20body%3b%0a%20%2
0%7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20string%20make%5fco
de%28%29const%7b%0a%20%20%20%20string%20out%3b%0a%20%20%20%20auto%2ap%3dbody%2eg
et%28%29%3b%0a%20%20%20%20out%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20return
%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5fcpp%5fcode%7b%0a%20%20t%5fbayan%7b%7bgo%5fc
onst%28%22%5b%3a%3a%5d%22%29%3b%7d%7d%0a%20%20TAutoPtr%3ct%5fbayan%3e%20bayan%3b
%0a%20%20vector%3cTAutoPtr%3ci%5fcpp%5fcode%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%
20%20O%2b%3dgo%5fauto%28bayan%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0
a%20%20%7d%0a%20%20static%20string%20align%28const%20string%26source%29%7b%0a%20
%20%20%20auto%20arr%3dsplit%28source%2c%22%5cn%22%29%3b%0a%20%20%20%20if%28arr%2
eempty%28%29%29return%20source%3b%0a%20%20%20%20auto%20get%3d%5b%5d%28const%20st
ring%26line%29%2d%3eint%7b%0a%20%20%20%20%20%20if%28line%3d%3d%22public%3a%22%29
return%20%2d2%3b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3cline%2esize%28%29%3
bi%2b%2b%29if%28line%5bi%5d%21%3d%27%20%27%29return%20i%3b%0a%20%20%20%20%20%20r
eturn%20%2d1%3b%0a%20%20%20%20%7d%3b%0a%20%20%20%20int%20count%3d%2d1%3b%0a%20%2
0%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%2
0%20auto%20m%3dget%28arr%5bi%5d%29%3b%0a%20%20%20%20%20%20if%28m%3c0%29continue%
3b%0a%20%20%20%20%20%20if%28count%3c0%29%7bcount%3dm%3bcontinue%3b%7d%0a%20%20%2
0%20%20%20count%3dstd%3a%3amin%3cint%3e%28m%2ccount%29%3b%0a%20%20%20%20%7d%0a%2
0%20%20%20if%28count%3c0%29return%20source%3b%0a%20%20%20%20vector%3cstring%3e%2
0out%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0
a%20%20%20%20%20%20auto%20m%3dget%28arr%5bi%5d%29%3b%0a%20%20%20%20%20%20auto%20
s%3dm%3c0%3farr%5bi%5d%3a%22%20%20%22%2barr%5bi%5d%2esubstr%28count%29%3b%0a%20%
20%20%20%20%20if%28m%3d%3d%2d1%29s%2eclear%28%29%3b%0a%20%20%20%20%20%20out%2epu
sh%5fback%28s%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20join%28out%2c%22%5c
n%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20
string%20out%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b
%29%7b%0a%20%20%20%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20QapAsse
rt%28ex%29%3b%0a%20%20%20%20%20%20auto%2ap%3dex%2eget%28%29%3b%0a%20%20%20%20%20
%20out%2b%3dp%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%2
0out%3b%0a%20%20%7d%0a%7d%0a%2f%2f%20test%0a%0at%5fstruct%5fbody%7b%0a%20%20vect
or%3ct%5ftarget%5fitem%3e%20nested%3b%0a%20%20t%5fsep%20sep0%3b%0a%20%20vector%3
ct%5fsep%5fstruct%5ffield%3e%20arr%3b%0a%20%20TAutoPtr%3ct%5fsep%5fstruct%5fcmds
%3e%20cmds%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20TAutoPtr%3ct%5fcpp%5fcode%3e%20c
ppcode%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%29%3b%0a%20%20
%20%20O%2b%3dgo%5fauto%28nested%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3
b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28cm
ds%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20O%2b%3dgo%5fa
uto%28cppcode%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7d%22%29%3b%0a%20%20%7
d%0a%20%20struct%20t%5ftarget%5fitem%5fout%3b%0a%20%20struct%20t%5fout%7b%0a%20%
20%20%20vector%3cconst%20t%5ftarget%5fitem%2a%3e%20nested%3b%0a%20%20%20%20strin
g%20provars%3b%0a%20%20%20%20string%20procmds%3b%0a%20%20%20%20string%20cppcode%
3b%0a%20%20%7d%3b%0a%20%20struct%20t%5ftarget%5fitem%5fout%7b%0a%20%20%20%20stri
ng%20sep%3b%0a%20%20%20%20string%20name%3b%0a%20%20%20%20string%20parent%3b%0a%2
0%20%20%20t%5fout%20out%3b%0a%20%20%7d%3b%0a%20%20%2f%2ftemplate%3cint%3e%0a%20%
20%2f%2fstatic%20t%5ftarget%5fitem%5fout%20weak%5fmake%5fcode%28const%20t%5ftarg
et%5fitem%26ref%2ct%5fic%5fdev%26icdev%29%3b%0a%20%20t%5fout%20make%5fcode%28t%5
fic%5fdev%26icdev%29const%7b%0a%20%20%20%20t%5fout%20out%3b%0a%20%20%20%20%7b%0a
%20%20%20%20%20%20auto%26arr%3dnested%3b%0a%20%20%20%20%20%20out%2enested%2eresi
ze%28arr%2esize%28%29%29%3b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esi
ze%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%
20%20%20%20%20%20%20%20auto%26to%3dout%2enested%5bi%5d%3b%0a%20%20%20%20%20%20%2
0%20to%3d%26ex%3b%0a%20%20%20%20%20%20%7d%0a%20%20%20%20%7d%0a%20%20%20%20%7b%0a
%20%20%20%20%20%20vector%3cstring%3e%20tmp%3b%0a%20%20%20%20%20%20for%28int%20i%
3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20%20%20tmp%2epush%
5fback%28arr%5bi%5d%2emake%5fcode%28i%2cicdev%29%29%3b%0a%20%20%20%20%20%20%7d%0
a%20%20%20%20%20%20out%2eprovars%3djoin%28tmp%2c%22%22%29%3b%0a%20%20%20%20%7d%0
a%20%20%20%20if%28cmds%29%0a%20%20%20%20%7b%0a%20%20%20%20%20%20auto%2apCmds%3dc
mds%2eget%28%29%3b%0a%20%20%20%20%20%20auto%26arr%3dpCmds%2d%3ebody%2earr%3b%0a%
20%20%20%20%20%20vector%3cstring%3e%20tmp%3b%0a%20%20%20%20%20%20for%28int%20i%3
d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%20%20%20tmp%2epush%5
fback%28arr%5bi%5d%2emake%5fcode%28i%29%29%3b%0a%20%20%20%20%20%20%7d%0a%20%20%2
0%20%20%20out%2eprocmds%3djoin%28tmp%2c%22%22%29%3b%0a%20%20%20%20%7d%0a%20%20%2
0%20string%20sep%3dsep0%2evalue%2eempty%28%29%3fsep1%2evalue%3asep0%2evalue%3b%0
a%20%20%20%20out%2ecppcode%3dcppcode%3fsep%2bcppcode%2d%3emake%5fcode%28%29%2b%2
2%5cn%22%3a%22%22%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0ai%5fdef%7
b%0a%20%20struct%20t%5fout%7b%0a%20%20%20%20string%20name%3b%0a%20%20%20%20strin
g%20parent%3b%0a%20%20%7d%3b%0a%20%20virtual%20t%5fout%20make%5fcode%28%29%7bQap
DebugMsg%28%22no%20way%2e%22%29%3breturn%20%2a%28t%5fout%2a%29nullptr%3b%7d%0a%7
d%0a%0at%5fclass%5fdef%20%3d%3e%20i%5fdef%7b%0a%20%20t%5fname%20name%3b%0a%20%20
t%5fsep%20sep0%3b%0a%20%20string%20arrow%5for%5fcolon%3b%0a%20%20t%5fsep%20sep1%
3b%0a%20%20t%5fname%20parent%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28nam
e%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20M%2b%3dgo%5fan
y%5fstr%5ffrom%5fvec%28arrow%5for%5fcolon%2csplit%28%22%3d%3e%2c%3a%22%2c%22%2c%
22%29%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%20%20%20M%2b%3dgo%
5fauto%28parent%29%3b%0a%20%20%7d%0a%20%20t%5fout%20make%5fcode%28%29%7b%0a%20%2
0%20%20t%5fout%20out%3b%0a%20%20%20%20out%2ename%3dname%2eget%28%29%3b%0a%20%20%
20%20out%2eparent%3dparent%2eget%28%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20
%7d%0a%7d%0a%0at%5fstruct%5fdef%20%3d%3e%20i%5fdef%7b%0a%20%20t%5fname%20name%3b
%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28name%29%3b%0a%20%20%7d%0a%20%20t%5
fout%20make%5fcode%28%29%7b%0a%20%20%20%20t%5fout%20out%3b%0a%20%20%20%20out%2en
ame%3dname%2eget%28%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at
%5ftarget%5fitem%3d%3ei%5ftarget%5fitem%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20TAu
toPtr%3ci%5fdef%3e%20def%3b%0a%20%20t%5fsep%20sep1%3b%0a%20%20t%5fstruct%5fbody%
20body%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%3b%0a%20%20%20%20
M%2b%3dgo%5fauto%28def%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep1%29%3b%0a%20%2
0%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20%7d%0a%20%20typedef%20t%5fstruct%5f
body%3a%3at%5ftarget%5fitem%5fout%20t%5fout%3b%0a%20%20t%5fout%20make%5fcode%28t
%5fic%5fdev%26icdev%29const%7b%0a%20%20%20%20t%5fout%20out%3b%0a%20%20%20%20out%
2esep%3dsep0%2evalue%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20auto%20tmp%3ddef%2
d%3emake%5fcode%28%29%3b%0a%20%20%20%20%20%20out%2ename%3dtmp%2ename%3b%0a%20%20
%20%20%20%20out%2eparent%3dtmp%2eparent%3b%0a%20%20%20%20%7d%0a%20%20%20%20auto%
20tmp%3dbody%2emake%5fcode%28icdev%29%3b%0a%20%20%20%20out%2eout%3dstd%3a%3amove
%28tmp%29%3b%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d%0a%0at%5ftarget%5fd
ecl%3d%3ei%5ftarget%5fitem%7b%0a%20%20t%5fsep%20sep0%3b%0a%20%20string%20name%3b
%0a%20%20t%5fsep%20sep1%3b%0a%20%20%7b%0a%20%20%20%20O%2b%3dgo%5fauto%28sep0%29%
3b%0a%20%20%20%20M%2b%3dgo%5fstr%3ct%5fname%3e%28name%29%3b%0a%20%20%20%20O%2b%3
dgo%5fauto%28sep1%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%3b%22%29%3b%0a%20%
20%7d%0a%7d%0a%0at%5ftarget%7b%0a%20%20vector%3cTAutoPtr%3ci%5ftarget%5fitem%3e%
3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%7d%0
a%20%20vector%3ct%5ftarget%5fitem%3a%3at%5fout%3e%20make%5fcode%28t%5fic%5fdev%2
6icdev%29%7b%0a%20%20%20%20vector%3ct%5ftarget%5fitem%3a%3at%5fout%3e%20out%3b%0
a%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%2
0%20%20%20auto%26ex%3darr%5bi%5d%3b%0a%20%20%20%20%20%20if%28auto%2ap%3ddynamic%
5fcast%3ct%5ftarget%5fitem%2a%3e%28ex%2eget%28%29%29%29%7b%0a%20%20%20%20%20%20%
20%20out%2epush%5fback%28p%2d%3emake%5fcode%28icdev%29%29%3b%0a%20%20%20%20%20%2
0%7d%0a%20%20%20%20%7d%0a%20%20%20%20return%20out%3b%0a%20%20%7d%0a%7d
*/