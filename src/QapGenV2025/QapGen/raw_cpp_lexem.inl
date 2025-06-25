// 50.075100 ms
//===>>===i_str_item_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_str_item_raw)\
  ADD(t_str_item_hex)\
  ADD(t_str_item_num)\
  ADD(t_str_item_fix)\
ADDEND()
class i_str_item;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_str_item_visitor{
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
  static TYPE*UberCast(i_str_item*p){
    if(!p)return nullptr;Is<TYPE,i_str_item_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_str_item*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_str_item_visitor
struct i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_str_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_str_item
public:
  typedef i_str_item_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load();/*
    {
      F(t_str_item_raw);
      F(t_str_item_hex);
      F(t_str_item_num);
      F(t_str_item_fix);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
  virtual string get_code()const{ QapDebugMsg("no way."); return ""; }
  virtual string get_value()const{ QapDebugMsg("no way."); return ""; }
};
//===>>===i_char_item_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_char_item_raw)\
  ADD(t_char_item_hex)\
  ADD(t_char_item_num)\
  ADD(t_char_item_fix)\
ADDEND()
class i_char_item;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_char_item_visitor{
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
  static TYPE*UberCast(i_char_item*p){
    if(!p)return nullptr;Is<TYPE,i_char_item_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_char_item*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_char_item_visitor
struct i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_char_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_char_item
public:
  typedef i_char_item_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load();/*
    {
      F(t_char_item_raw);
      F(t_char_item_hex);
      F(t_char_item_num);
      F(t_char_item_fix);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
};
struct t_number{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_number
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_number
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    auto&D=$.mandatory;
    auto&M=$.mandatory;
    auto&O=$.optional;
    static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
    D+=dev.go_any(body,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_item_raw:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_raw)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_raw
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_item_raw
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
    static const auto g_static_var_0=CharMask::fromStr(dip_inv("\"\\\n"));
    D+=dev.go_any(body,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};
struct t_str_item_hex:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_hex)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_hex
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_item_hex
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
    M+=dev.go_const("\\x");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
    D+=dev.go_any_arr_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    return CToS(n);
  }
};
struct t_str_item_num:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_num)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_num
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_item_num
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
    M+=dev.go_const("\\u");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
    D+=dev.go_any_arr_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    return CToS(n);
  }
};
struct t_str_item_fix:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_fix)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_fix
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_item_fix
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
    M+=dev.go_const("\\");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr("tfbrn\\\"\'"+gen_dips("07"));
    D+=dev.go_any_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=get_code();
    BinString str=code;
    return str.data;
  }
};
struct t_str_item{
public:
  struct t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_str_item)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
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
      M+=dev.go_const("\"");
      if(!ok)return ok;
      D+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("\"");
      if(!ok)return ok;
      return ok;
    }
      string get_code()const{
        string out;
        for(int i=0;i<arr.size();i++) out+=arr[i]->get_code();
        return out;
      }
      string get_value()const{
        string out;
        for(int i=0;i<arr.size();i++) out+=arr[i]->get_value();
        return out;
      }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_impl)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_item
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
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
};
struct t_char_item_raw:public i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_raw)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_raw
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char_item_raw
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
    static const auto g_static_var_0=CharMask::fromStr(dip_inv("'\\\n"));
    D+=dev.go_any(body,g_static_var_0);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};
struct t_char_item_hex:public i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_hex)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_hex
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char_item_hex
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
    M+=dev.go_const("\\x");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
    D+=dev.go_any_arr_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    return CToS(n);
  }
};
struct t_char_item_num:public i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_num)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,4),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_num
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char_item_num
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
    M+=dev.go_const("\\u");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
    D+=dev.go_any_arr_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    return CToS(n);
  }
};
struct t_char_item_fix:public i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_fix)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_fix
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char_item_fix
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
    M+=dev.go_const("\\");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr("tfbrn\\\"\'"+gen_dips("07"));
    D+=dev.go_any_char(body,g_static_var_1);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=get_code();
    BinString str=code;
    return str.data;
  }
};
struct t_char_item{
public:
  struct t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_char_item)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_char_item>,body,DEF,$,$)\
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
      M+=dev.go_const("'");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      M+=dev.go_const("'");
      if(!ok)return ok;
      return ok;
    }
      string get_code()const{return "'"+body->get_code()+"'";}
      string get_value()const{return body->get_value();}
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_impl)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_char_item
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
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl"); return "";}
};
bool i_str_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_str_item_raw);
  F(t_str_item_hex);
  F(t_str_item_num);
  F(t_str_item_fix);
  #undef F
  main();
  return scope.ok;
}

bool i_char_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_char_item_raw);
  F(t_char_item_hex);
  F(t_char_item_num);
  F(t_char_item_fix);
  #undef F
  main();
  return scope.ok;
}

/*
//list of types:
F(t_number)F(i_str_item)F(t_str_item_raw)F(t_str_item_hex)F(t_str_item_num)
F(t_str_item_fix)F(t_str_item)F(i_char_item)F(t_char_item_raw)
F(t_char_item_hex)F(t_char_item_num)F(t_char_item_fix)F(t_char_item)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fnumber%7b%0a%20%20string%20body%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%7d
%0a%0a%0ai%5fstr%5fitem%7b%0a%20%20virtual%20string%20get%5fcode%28%29const%7b%2
0QapDebugMsg%28%22no%20way%2e%22%29%3b%20return%20%22%22%3b%20%7d%0a%20%20virtua
l%20string%20get%5fvalue%28%29const%7b%20QapDebugMsg%28%22no%20way%2e%22%29%3b%2
0return%20%22%22%3b%20%7d%0a%7d%0a%0at%5fstr%5fitem%5fraw%3d%3ei%5fstr%5fitem%7b
%0a%20%20string%20body%3dany%28dip%5finv%28%22%5c%22%5c%5c%5cn%22%29%29%3b%0a%20
%20string%20get%5fcode%28%29const%7breturn%20body%3b%7d%0a%20%20string%20get%5fv
alue%28%29const%7breturn%20body%3b%7d%0a%7d%0a%0at%5fstr%5fitem%5fhex%3d%3ei%5fs
tr%5fitem%7b%0a%20%20%22%5c%5cx%22%0a%20%20array%28char%2c2%29%20body%3dany%5far
r%5fchar%28gen%5fdips%28%2209afAF%22%29%29%3b%0a%20%20string%20get%5fcode%28%29c
onst%7breturn%20%22%5c%5cx%22%2bCToS%28body%5b0%5d%29%2bCToS%28body%5b1%5d%29%3b
%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20string%20code%3b%0a
%20%20%20%20code%2epush%5fback%28body%5b0%5d%29%3b%0a%20%20%20%20code%2epush%5fb
ack%28body%5b1%5d%29%3b%0a%20%20%20%20auto%20n%3dHToI%5fraw%28code%29%3b%0a%20%2
0%20%20return%20CToS%28n%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fstr%5fitem%5fnum%3d%3e
i%5fstr%5fitem%7b%0a%20%20%22%5c%5cu%22%0a%20%20array%28char%2c2%29%20body%3dany
%5farr%5fchar%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20string%20get%5fcode%28%29
const%7breturn%20%22%5c%5cu%22%2bCToS%28body%5b0%5d%29%2bCToS%28body%5b1%5d%29%3
b%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20string%20code%3b%0
a%20%20%20%20code%2epush%5fback%28body%5b0%5d%29%3b%0a%20%20%20%20code%2epush%5f
back%28body%5b1%5d%29%3b%0a%20%20%20%20auto%20n%3dSToI%28code%29%3b%0a%20%20%20%
20return%20CToS%28n%29%3b%0a%20%20%7d%0a%7d%0at%5fstr%5fitem%5ffix%3d%3ei%5fstr%
5fitem%7b%0a%20%20%22%5c%5c%22%0a%20%20char%20body%3dany%5fchar%28%22tfbrn%5c%5c
%5c%22%5c%27%22%2bgen%5fdips%28%2207%22%29%29%3b%0a%20%20string%20get%5fcode%28%
29const%7breturn%20%22%5c%5c%22%2bCToS%28body%29%3b%7d%0a%20%20string%20get%5fva
lue%28%29const%7b%0a%20%20%20%20string%20code%3dget%5fcode%28%29%3b%0a%20%20%20%
20BinString%20str%3dcode%3b%0a%20%20%20%20return%20str%2edata%3b%0a%20%20%7d%0a%
7d%0a%0at%5fstr%5fitem%7b%0a%20%20t%5fimpl%7b%0a%20%20%20%20%22%5c%22%22%0a%20%2
0%20%20vector%3cTAutoPtr%3ci%5fstr%5fitem%3e%3e%20arr%3b%0a%20%20%20%20%22%5c%22
%22%0a%20%20%20%20string%20get%5fcode%28%29const%7b%0a%20%20%20%20%20%20string%2
0out%3b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esize%28%29%3bi%2b%2b%2
9%20out%2b%3darr%5bi%5d%2d%3eget%5fcode%28%29%3b%0a%20%20%20%20%20%20return%20ou
t%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20get%5fvalue%28%29const%7b%0a%20%20
%20%20%20%20string%20out%3b%0a%20%20%20%20%20%20for%28int%20i%3d0%3bi%3carr%2esi
ze%28%29%3bi%2b%2b%29%20out%2b%3darr%5bi%5d%2d%3eget%5fvalue%28%29%3b%0a%20%20%2
0%20%20%20return%20out%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20string%20value%3
dstr%3ct%5fimpl%3e%28%29%3b%0a%20%20string%20get%5fcode%28%29const%7breturn%20va
lue%3b%7d%0a%20%20string%20get%5fvalue%28%29const%7bQapDebugMsg%28%22no%20impl%2
2%29%3breturn%20%22%22%3b%7d%0a%7d%0a%0ai%5fchar%5fitem%7b%0a%20%20virtual%20str
ing%20get%5fcode%28%29const%7bQapDebugMsg%28%22no%20way%2e%22%29%3breturn%20%22%
22%3b%7d%0a%20%20virtual%20string%20get%5fvalue%28%29const%7bQapDebugMsg%28%22no
%20way%2e%22%29%3breturn%20%22%22%3b%7d%0a%7d%0a%0at%5fchar%5fitem%5fraw%3d%3ei%
5fchar%5fitem%7b%0a%20%20string%20body%3dany%28dip%5finv%28%22%27%5c%5c%5cn%22%2
9%29%3b%0a%20%20string%20get%5fcode%28%29const%7breturn%20body%3b%7d%0a%20%20str
ing%20get%5fvalue%28%29const%7breturn%20body%3b%7d%0a%7d%0a%0at%5fchar%5fitem%5f
hex%3d%3ei%5fchar%5fitem%7b%0a%20%20%22%5c%5cx%22%0a%20%20array%28char%2c2%29%20
body%3dany%5farr%5fchar%28gen%5fdips%28%2209afAF%22%29%29%3b%0a%20%20string%20ge
t%5fcode%28%29const%7breturn%20%22%5c%5cx%22%2bCToS%28body%5b0%5d%29%2bCToS%28bo
dy%5b1%5d%29%3b%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20stri
ng%20code%3b%0a%20%20%20%20code%2epush%5fback%28body%5b0%5d%29%3b%0a%20%20%20%20
code%2epush%5fback%28body%5b1%5d%29%3b%0a%20%20%20%20auto%20n%3dHToI%5fraw%28cod
e%29%3b%0a%20%20%20%20return%20CToS%28n%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%5f
item%5fnum%3d%3ei%5fchar%5fitem%7b%0a%20%20%22%5c%5cu%22%0a%20%20array%28char%2c
4%29%20body%3dany%5farr%5fchar%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20string%2
0get%5fcode%28%29const%7breturn%20%22%5c%5cu%22%2bCToS%28body%5b0%5d%29%2bCToS%2
8body%5b1%5d%29%3b%7d%0a%20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20s
tring%20code%3b%0a%20%20%20%20code%2epush%5fback%28body%5b0%5d%29%3b%0a%20%20%20
%20code%2epush%5fback%28body%5b1%5d%29%3b%0a%20%20%20%20auto%20n%3dSToI%28code%2
9%3b%0a%20%20%20%20return%20CToS%28n%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fchar%5fite
m%5ffix%3d%3ei%5fchar%5fitem%7b%0a%20%20%22%5c%5c%22%0a%20%20char%20body%3dany%5
fchar%28%22tfbrn%5c%5c%5c%22%5c%27%22%2bgen%5fdips%28%2207%22%29%29%3b%0a%20%20s
tring%20get%5fcode%28%29const%7breturn%20%22%5c%5c%22%2bCToS%28body%29%3b%7d%0a%
20%20string%20get%5fvalue%28%29const%7b%0a%20%20%20%20string%20code%3dget%5fcode
%28%29%3b%0a%20%20%20%20BinString%20str%3dcode%3b%0a%20%20%20%20return%20str%2ed
ata%3b%0a%20%20%7d%0a%7d%0at%5fchar%5fitem%7b%0a%20%20t%5fimpl%7b%0a%20%20%20%20
%22%27%22%0a%20%20%20%20TAutoPtr%3ci%5fchar%5fitem%3e%20body%3b%0a%20%20%20%20%2
2%27%22%0a%20%20%20%20string%20get%5fcode%28%29const%7breturn%20%22%27%22%2bbody
%2d%3eget%5fcode%28%29%2b%22%27%22%3b%7d%0a%20%20%20%20string%20get%5fvalue%28%2
9const%7breturn%20body%2d%3eget%5fvalue%28%29%3b%7d%0a%20%20%7d%0a%20%20string%2
0value%3dstr%3ct%5fimpl%3e%28%29%3b%0a%20%20string%20get%5fcode%28%29const%7bret
urn%20value%3b%7d%0a%20%20string%20get%5fvalue%28%29const%7bQapDebugMsg%28%22no%
20impl%22%29%3b%20return%20%22%22%3b%7d%0a%7d
*/