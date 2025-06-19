// 1242.670800 ms
//===>>===i_sep_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_sep_seq)\
  ADD(t_c_comment)\
  ADD(t_cpp_comment)\
ADDEND()
class i_sep;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_sep_visitor{
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
  static TYPE*UberCast(i_sep*p){
    if(!p)return nullptr;Is<TYPE,i_sep_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_sep*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_sep_visitor
struct i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_sep
public:
  typedef i_sep_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load();/*
    {
      F(t_sep_seq);
      F(t_c_comment);
      F(t_cpp_comment);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
};
//===>>===i_expr_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_str)\
  ADD(t_char)\
  ADD(t_num)\
  ADD(t_id)\
  ADD(t_sign)\
  ADD(t_soft_brackets)\
  ADD(t_hard_brackets)\
  ADD(t_curly_brackets)\
ADDEND()
class i_expr;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_expr_visitor{
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
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)
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
      F(t_str);
      F(t_char);
      F(t_num);
      F(t_id);
      F(t_sign);
      F(t_soft_brackets);
      F(t_hard_brackets);
      F(t_curly_brackets);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
struct t_sep_seq:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_seq)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_seq
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_seq
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    static const auto g_static_var_0=CharMask::fromStr(" \t\r\n");
    D+=dev.go_any(body,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body;
  }
};
struct t_c_comment:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_c_comment
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_c_comment
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_const("/*");
    if(!ok)return ok;
    D+=dev.go_end(body,"*/");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "/*"+body+"*/";
  }
};
struct t_cpp_comment:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_comment
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_cpp_comment
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_const("//");
    if(!ok)return ok;
    D+=dev.go_end(body,"\n");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "//"+body+"\n";
  }
};
struct t_sep{
public:
  struct t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_sep>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      auto&D=$.mandatory;
      auto&M=$.mandatory;
      auto&O=$.optional;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
    string make_code()const{
      string out="";
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->make_code();
      }
      return out;
    }
};
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_impl)\
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
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_str<t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return value;}
};
struct t_str:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_str_item,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_char:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_char_item,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_num:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_number,body,DEF,$,$)\
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
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_name{
public:
  struct t_keyword{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_keyword
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_keyword
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      auto&D=$.mandatory;
      auto&M=$.mandatory;
      auto&O=$.optional;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("false,true,nullptr,this,struct,class,for,if,while,do,const,constexpr,else,operator,auto,continue,break,return,goto,virtual,override,public,private,protected,friend,template,typedef,using,namespace,decltype",","));
      D+=dev.go_any_str_from_vec(value,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
};
  struct t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,A,DEF,$,$)\
  ADDVAR(string,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      auto&D=$.mandatory;
      auto&M=$.mandatory;
      auto&O=$.optional;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ")+"_$@");
      M+=dev.go_any_char(A,g_static_var_0);
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
      O+=dev.go_any(B,g_static_var_1);
      if(!ok)return ok;
      return ok;
    }
    string get()const{return CToS(A)+B;}
};
  struct t_impl_ex{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_ex)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,impl,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl_ex
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl_ex
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      auto&D=$.mandatory;
      auto&M=$.mandatory;
      auto&O=$.optional;
      D+=dev.go_diff<t_keyword>(impl);
      if(!ok)return ok;
      return ok;
    }
};
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_keyword)\
  F(t_impl   )\
  F(t_impl_ex)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_name
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_str<t_impl_ex>(value);
    if(!ok)return ok;
    return ok;
  }
public:
  string get()const{return value;}
};
struct t_id:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_id)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_id
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_id
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_sign:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sign
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sign
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    static const auto g_static_var_0=CharMask::fromStr("~|&=<>!:?;,.+-*/%^");
    D+=dev.go_any_char(body,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
};
struct t_soft_brackets:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_soft_brackets
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_soft_brackets
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const(")");
    if(!ok)return ok;
    return ok;
  }
};
struct t_hard_brackets:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_hard_brackets
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_hard_brackets
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("]");
    if(!ok)return ok;
    return ok;
  }
};
struct t_curly_brackets:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_curly_brackets
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_curly_brackets
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
};
struct t_param{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_expr>>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_param
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_param
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    M+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
struct t_line{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,cmd,DEF,$,$)\
ADDVAR(vector<t_param>,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_line
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_line
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    M+=dev.go_auto(cmd);
    if(!ok)return ok;
    O+=dev.go_auto(params);
    if(!ok)return ok;
    return ok;
  }
  vector<string> get_raw_params(/*IEnvRTTI&Env*/){
    vector<string> out;
    for(int i=0;i<params.size();i++){
      auto&ex=params[i];
      string mem;
      bool ok=save_obj(/*Env,*/ex.body,mem);
      QapAssert(ok);
      out.push_back(mem);
    }
    return std::move(out);
  }
};
bool i_sep::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_sep_seq);
  F(t_c_comment);
  F(t_cpp_comment);
  #undef F
  main();
  return scope.ok;
}

bool i_expr::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_str);
  F(t_char);
  F(t_num);
  F(t_id);
  F(t_sign);
  F(t_soft_brackets);
  F(t_hard_brackets);
  F(t_curly_brackets);
  #undef F
  main();
  return scope.ok;
}

/*
//list of types:
F(i_sep)F(t_sep_seq)F(t_c_comment)F(t_cpp_comment)F(t_sep)F(t_str)F(t_char)
F(t_num)F(t_name)F(t_id)F(t_sign)F(t_soft_brackets)F(t_hard_brackets)
F(t_curly_brackets)F(t_param)F(t_line)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
i%5fsep%20%7b%0a%20%20virtual%20string%20make%5fcode%28%29const%7bQapDebugMsg%28
%22no%20way%2e%22%29%3breturn%20%22%22%3b%7d%0a%7d%0a%0at%5fsep%5fseq%20%3a%20i%
5fsep%20%7b%0a%20%20string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fany%28body%2
c%22%20%5ct%5cr%5cn%22%29%3b%0a%20%20%7d%0a%20%20string%20make%5fcode%28%29const
%7b%0a%20%20%20%20return%20body%3b%0a%20%20%7d%0a%7d%0a%0at%5fc%5fcomment%20%3a%
20i%5fsep%20%7b%0a%20%20string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28
%22%2f%2a%22%29%3b%0a%20%20%20%20go%5fend%28body%2c%22%2a%2f%22%29%3b%0a%20%20%7
d%0a%20%20string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20%22%2f%2a%22
%2bbody%2b%22%2a%2f%22%3b%0a%20%20%7d%0a%7d%0a%0at%5fcpp%5fcomment%20%3a%20i%5fs
ep%20%7b%0a%20%20string%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%2f%
2f%22%29%3b%0a%20%20%20%20go%5fend%28body%2c%22%5cn%22%29%3b%0a%20%20%7d%0a%20%2
0string%20make%5fcode%28%29const%7b%0a%20%20%20%20return%20%22%2f%2f%22%2bbody%2
b%22%5cn%22%3b%0a%20%20%7d%0a%7d%0a%0at%5fsep%20%7b%0a%20%20t%5fimpl%20%7b%0a%20
%20%20%20vector%3cTAutoPtr%3ci%5fsep%3e%3e%20arr%3b%0a%20%20%20%20%7b%0a%20%20%2
0%20%20%20go%5fauto%28arr%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20make%5f
code%28%29const%7b%0a%20%20%20%20%20%20string%20out%3d%22%22%3b%0a%20%20%20%20%2
0%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%29%7b%0a%20%20%20%20%20%2
0%20%20out%2b%3darr%5bi%5d%2d%3emake%5fcode%28%29%3b%0a%20%20%20%20%20%20%7d%0a%
20%20%20%20%20%20return%20out%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20string%20
value%3b%0a%20%20%7b%0a%20%20%20%20go%5fstr%3ct%5fimpl%3e%28value%29%3b%0a%20%20
%7d%0a%20%20string%20make%5fcode%28%29const%7breturn%20value%3b%7d%0a%7d%0a%0at%
5fstr%20%3a%20i%5fexpr%20%7b%0a%20%20t%5fstr%5fitem%20body%3b%0a%20%20%7b%0a%20%
20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%20%3a%20i%5fexpr%
20%7b%0a%20%20t%5fchar%5fitem%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28bo
dy%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fnum%20%3a%20i%5fexpr%20%7b%0a%20%20t%5fnumbe
r%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0
a%0at%5fname%20%7b%0a%20%20t%5fkeyword%20%7b%0a%20%20%20%20string%20value%3b%0a%
20%20%20%20%7b%0a%20%20%20%20%20%20go%5fany%5fstr%5ffrom%5fvec%28value%2csplit%2
8%22false%2ctrue%2cnullptr%2cthis%2cstruct%2cclass%2cfor%2cif%2cwhile%2cdo%2ccon
st%2cconstexpr%2celse%2coperator%2cauto%2ccontinue%2cbreak%2creturn%2cgoto%2cvir
tual%2coverride%2cpublic%2cprivate%2cprotected%2cfriend%2ctemplate%2ctypedef%2cu
sing%2cnamespace%2cdecltype%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%7
d%0a%20%20t%5fimpl%20%7b%0a%20%20%20%20char%20A%3b%0a%20%20%20%20string%20B%3b%0
a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3dgo%5fany%5fchar%28A%2cgen%5fdips%28%
22azAZ%22%29%2b%22%5f%24%40%22%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fany%28B%2cg
en%5fdips%28%22azAZ09%22%29%2b%22%5f%24%40%22%29%3b%0a%20%20%20%20%7d%0a%20%20%2
0%20string%20get%28%29const%7breturn%20CToS%28A%29%2bB%3b%7d%0a%20%20%7d%0a%20%2
0t%5fimpl%5fex%20%7b%0a%20%20%20%20t%5fimpl%20impl%3b%0a%20%20%20%20%7b%0a%20%20
%20%20%20%20go%5fdiff%3ct%5fkeyword%3e%28impl%29%3b%0a%20%20%20%20%7d%0a%20%20%7
d%0a%20%20string%20value%3b%0a%20%20%7b%0a%20%20%20%20go%5fstr%3ct%5fimpl%5fex%3
e%28value%29%3b%0a%20%20%7d%0a%20%20string%20get%28%29const%7breturn%20value%3b%
7d%0a%7d%0a%0at%5fid%20%3a%20i%5fexpr%20%7b%0a%20%20t%5fname%20body%3b%0a%20%20%
7b%0a%20%20%20%20go%5fauto%28body%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fsign%20%3a%20
i%5fexpr%20%7b%0a%20%20char%20body%3b%0a%20%20%7b%0a%20%20%20%20go%5fany%5fchar%
28body%2c%22%7e%7c%26%3d%3c%3e%21%3a%3f%3b%2c%2e%2b%2d%2a%2f%25%5e%22%29%3b%0a%2
0%20%7d%0a%7d%0a%0at%5fsoft%5fbrackets%20%3a%20i%5fexpr%20%7b%0a%20%20vector%3cT
AutoPtr%3ci%5fexpr%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28
%22%28%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20M%2b%3d
go%5fconst%28%22%29%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fhard%5fbrackets%20%3a%20
i%5fexpr%20%7b%0a%20%20vector%3cTAutoPtr%3ci%5fexpr%3e%3e%20arr%3b%0a%20%20%7b%0
a%20%20%20%20M%2b%3dgo%5fconst%28%22%5b%22%29%3b%0a%20%20%20%20O%2b%3dgo%5fauto%
28arr%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5d%22%29%3b%0a%20%20%7d%0a%7d%
0a%0at%5fcurly%5fbrackets%20%3a%20i%5fexpr%20%7b%0a%20%20vector%3cTAutoPtr%3ci%5
fexpr%3e%3e%20arr%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%7b%22%29%
3b%0a%20%20%20%20O%2b%3dgo%5fauto%28arr%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28
%22%7d%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fparam%20%7b%0a%20%20t%5fsep%20sep%3b%
0a%20%20vector%3cTAutoPtr%3ci%5fexpr%3e%3e%20body%3b%0a%20%20%7b%0a%20%20%20%20M
%2b%3dgo%5fauto%28sep%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28body%29%3b%0a%20%20
%7d%0a%7d%0a%0at%5fline%20%7b%0a%20%20t%5fname%20cmd%3b%0a%20%20vector%3ct%5fpar
am%3e%20params%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo%5fauto%28cmd%29%3b%0a%20%2
0%20%20O%2b%3dgo%5fauto%28params%29%3b%0a%20%20%7d%0a%20%20vector%3cstring%3e%20
get%5fraw%5fparams%28%2f%2aIEnvRTTI%26Env%2a%2f%29%7b%0a%20%20%20%20vector%3cstr
ing%3e%20out%3b%0a%20%20%20%20for%28int%20i%3d0%3bi%3cparams%2esize%28%29%3bi%2b
%2b%29%7b%0a%20%20%20%20%20%20auto%26ex%3dparams%5bi%5d%3b%0a%20%20%20%20%20%20s
tring%20mem%3b%0a%20%20%20%20%20%20bool%20ok%3dsave%5fobj%28%2f%2aEnv%2c%2a%2fex
%2ebody%2cmem%29%3b%0a%20%20%20%20%20%20QapAssert%28ok%29%3b%0a%20%20%20%20%20%2
0out%2epush%5fback%28mem%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20return%20std%3a%3
amove%28out%29%3b%0a%20%20%7d%0a%7d
*/