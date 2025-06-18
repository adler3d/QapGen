class t_name_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name_code
#include "QapGenStruct.inl"
//<<<<<+=====t_name_code
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_name::t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return value;};
};

class t_num_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_number,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_num_code
#include "QapGenStruct.inl"
//<<<<<+=====t_num_code
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return body.body;};
};

class t_str_seq{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_seq)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_seq
#include "QapGenStruct.inl"
//<<<<<+=====t_str_seq
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
  string make_code()const{return "\""+get_code()+"\"";};
};

class t_sep_str_seq{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_str_seq)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_str_seq,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_str_seq
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_str_seq
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(sep);
    if(!ok)return ok;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};

class t_str_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_str_seq,first,DEF,$,$)\
ADDVAR(vector<t_sep_str_seq>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_code
#include "QapGenStruct.inl"
//<<<<<+=====t_str_code
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
  };
};

class t_char_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_char_item>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char
#include "QapGenStruct.inl"
//<<<<<+=====t_char
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
  string get_code()const{
    return body->get_code();
  }
  string get_value()const{
    return body->get_value();;
  }
  string make_code()const{return "\'"+get_code()+"\'";};
};

class t_sign_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sign,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sign_code
#include "QapGenStruct.inl"
//<<<<<+=====t_sign_code
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return CToS(body.body);};
};

class i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====i_code_with_sep
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load();
    #include "QapLexPolyEnd.inl"
  };
  virtual string make_code()const{QapDebugMsg("no way.");return "";};
};

class t_name_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name_code,body,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_name_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_num_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_num_code,body,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_num_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_num_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_str_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_str_code,body,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_str_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_char_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_char_code,body,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_char_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_char_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_sign_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sign_code,body,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sign_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_sign_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_soft_brackets_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_soft_brackets_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_soft_brackets_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_hard_brackets_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_hard_brackets_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_hard_brackets_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_curly_brackets_code_with_sep:public i_code_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code_with_sep)PARENT(i_code_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_code_with_sep>>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_curly_brackets_code_with_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_curly_brackets_code_with_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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