class t_number{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_number
#include "QapGenStruct.inl"
//<<<<<+=====t_number
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body,gen_dips("09"));
    if(!ok)return ok;
    return ok;
  }
};

class i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_str_item
#include "QapGenStruct.inl"
//<<<<<+=====i_str_item
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load()
    {
      F(t_str_item_raw);
      F(t_str_item_hex);
      F(t_str_item_num);
      F(t_str_item_fix);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
    #include "QapLexPolyEnd.inl"
  };
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
};


class t_str_item_raw:public i_str_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_raw)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_raw
#include "QapGenStruct.inl"
//<<<<<+=====t_str_item_raw
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    static const auto dip_for_body=CharMask::fromStr(dip_inv("\"\\\n"));
    D+=dev.go_any(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};

class t_str_item_hex:public i_str_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_hex)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_hex
#include "QapGenStruct.inl"
//<<<<<+=====t_str_item_hex
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\x");
    if(!ok)return ok;
    static const string dip_for_body=gen_dips("09afAF");
    D+=dev.go_any_arr_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
};

class t_str_item_num:public i_str_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_num)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item_num
#include "QapGenStruct.inl"
//<<<<<+=====t_str_item_num
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\u");
    if(!ok)return ok;
    static const string dip_for_body=gen_dips("09");
    D+=dev.go_any_arr_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
};

class t_str_item_fix:public i_str_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item_fix)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,SET,'n',$)\
ADDEND()
//=====+>>>>>t_str_item_fix
#include "QapGenStruct.inl"
//<<<<<+=====t_str_item_fix
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\");
    if(!ok)return ok;
    static const string dip_for_body="tfbrn\\\"\'"+gen_dips("07");
    D+=dev.go_any_char(body,dip_for_body);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
};

class t_str_item{
public:
  class t_impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_str_item)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStruct.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
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
  };
public:
#define DEF_PRO_NESTED(F)F(t_impl)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_item
#include "QapGenStruct.inl"
//<<<<<+=====t_str_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_str<t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
};

class i_char_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_char_item
#include "QapGenStruct.inl"
//<<<<<+=====i_char_item
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load()
    {
      F(t_char_item_raw);
      F(t_char_item_hex);
      F(t_char_item_num);
      F(t_char_item_fix);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
    #include "QapLexPolyEnd.inl"
  };
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
};

class t_char_item_raw:public i_char_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_raw)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_raw
#include "QapGenStruct.inl"
//<<<<<+=====t_char_item_raw
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body,dip_inv("\'\\\n"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return body;}
  string get_value()const{return body;}
};

class t_char_item_hex:public i_char_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_hex)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,2),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_hex
#include "QapGenStruct.inl"
//<<<<<+=====t_char_item_hex
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\x");
    if(!ok)return ok;
    D+=dev.go_any_arr_char(body,gen_dips("09afAF"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    auto value=CToS(n);
    return value;
  }
};

class t_char_item_num:public i_char_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_num)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(array(char,4),body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item_num
#include "QapGenStruct.inl"
//<<<<<+=====t_char_item_num
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\u");
    if(!ok)return ok;
    D+=dev.go_any_arr_char(body,gen_dips("09"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    auto value=CToS(n);
    return value;
  }
};

class t_char_item_fix:public i_char_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item_fix)PARENT(i_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,SET,'\0',$)\
ADDEND()
//=====+>>>>>t_char_item_fix
#include "QapGenStruct.inl"
//<<<<<+=====t_char_item_fix
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("\\");
    if(!ok)return ok;
    D+=dev.go_any_char(body,"tfbrn\\\"\'"+gen_dips("07"));
    if(!ok)return ok;
    return ok;
  }
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=SelfClass::get_code();
    BinString str=code;
    return str.data;
  }
};

class t_char_item{
public:
  class t_impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_char_item)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_char_item>,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStruct.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\'");
      if(!ok)return ok;
      D+=dev.go_auto(body);
      if(!ok)return ok;
      D+=dev.go_const("\'");
      if(!ok)return ok;
      return ok;
    }
    string get_code()const{return "\'"+body->get_code()+"\'";}
    string get_value()const{
      return body->get_value();
    }
  };
public:
#define DEF_PRO_NESTED(F)F(t_impl)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_item
#include "QapGenStruct.inl"
//<<<<<+=====t_char_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl>(value);
    return ok;
  }
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
};

static void RegAllCppLex(IEnvRTTI&Env){
  #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};
  F(t_char_item_raw);
  F(t_char_item_hex);
  F(t_char_item_num);
  F(t_char_item_fix);
  F(t_str_item_raw);
  F(t_str_item_hex);
  F(t_str_item_num);
  F(t_str_item_fix);
  #undef F
}