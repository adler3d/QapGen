class i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_sep
#include "QapGenStruct.inl"
//<<<<<+=====i_sep
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load()
    {
      F(t_sep_seq);
      F(t_c_comment);
      F(t_cpp_comment);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
    #include "QapLexPolyEnd.inl"
  };
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
};
class i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_expr
#include "QapGenStruct.inl"
//<<<<<+=====i_expr
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load()
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
    }
    #include "QapLexPolyEnd.inl"
  };
};

class t_sep_seq:public i_sep{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_seq)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_seq
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_seq
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any(body," \t\r\n");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body;
  }
};
class t_c_comment:public i_sep{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_c_comment
#include "QapGenStruct.inl"
//<<<<<+=====t_c_comment
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
class t_cpp_comment:public i_sep{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_comment
#include "QapGenStruct.inl"
//<<<<<+=====t_cpp_comment
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
class t_sep{
public:
  class t_impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_sep>>,arr,DEF,$,$)\
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
#define DEF_PRO_NESTED(F)F(t_impl)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl>(value);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{return value;}
};

class t_str:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_str_item,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str
#include "QapGenStruct.inl"
//<<<<<+=====t_str
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
};

class t_char:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_char)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_char_item,body,DEF,$,$)\
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
    D+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};
class t_num:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_number,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_num
#include "QapGenStruct.inl"
//<<<<<+=====t_num
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
};
class t_name{
public:
  class t_keyword{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_keyword
  #include "QapGenStruct.inl"
  //<<<<<+=====t_keyword
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      static const auto g_static_split_arr_0=QapStrFinder::fromArr(split(
        "false,true,this,struct,class,for,if,while,const,else,operator,auto,continue,"
        "break,return,goto,virtual,template,typedef,using",
        ","
      ));
      D+=dev.go_any_str_from_vec(value,g_static_split_arr_0);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,A,SET,'A',$)\
  ADDVAR(string,B,DEF,$,$)\
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
      static const auto dip_for_a=CharMask::fromStr(gen_dips("azAZ")+"_$@");
      M+=dev.go_any_char(A,dip_for_a);
      if(!ok)return ok;
      static const auto dip_for_b=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
      O+=dev.go_any(B,dip_for_b);
      if(!ok)return ok;
      return ok;
    }
    string get()const{return CToS(A)+B;}
  };
  class t_impl_ex{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_ex)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,impl,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl_ex
  #include "QapGenStruct.inl"
  //<<<<<+=====t_impl_ex
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_diff<t_keyword>(impl);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)F(t_keyword)F(t_impl)F(t_impl_ex)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name
#include "QapGenStruct.inl"
//<<<<<+=====t_name
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl_ex>(value);
    if(!ok)return ok;
    return ok;
  }
  string get()const{return value;}
};
class t_id:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_id)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_id
#include "QapGenStruct.inl"
//<<<<<+=====t_id
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
};
class t_sign:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,SET,'?',$)\
ADDEND()
//=====+>>>>>t_sign
#include "QapGenStruct.inl"
//<<<<<+=====t_sign
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_any_char(body,"~|&=<>!:?;,.+-*/%^");
    if(!ok)return ok;
    return ok;
  }
};
class t_soft_brackets:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_soft_brackets
#include "QapGenStruct.inl"
//<<<<<+=====t_soft_brackets
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("(");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const(")");
    if(!ok)return ok;
    return ok;
  }
};
class t_hard_brackets:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_hard_brackets
#include "QapGenStruct.inl"
//<<<<<+=====t_hard_brackets
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("[");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("]");
    if(!ok)return ok;
    return ok;
  }
};
class t_curly_brackets:public i_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_curly_brackets
#include "QapGenStruct.inl"
//<<<<<+=====t_curly_brackets
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    O+=dev.go_auto(arr);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
};

class t_param{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_expr>>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_param
#include "QapGenStruct.inl"
//<<<<<+=====t_param
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};

class t_line{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,cmd,DEF,$,$)\
ADDVAR(vector<t_param>,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_line
#include "QapGenStruct.inl"
//<<<<<+=====t_line
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(cmd);
    if(!ok)return ok;
    O+=dev.go_auto(params);
    if(!ok)return ok;
    return ok;
  }
  vector<string> get_raw_params(IEnvRTTI&Env){
    vector<string> out;
    for(int i=0;i<params.size();i++){
      auto&ex=params[i];
      string mem;
      bool ok=save_obj(Env,ex.body,mem);
      QapAssert(ok);
      out.push_back(mem);
    }
    return std::move(out);
  }
};

static void QapLexerRegAll(IEnvRTTI&Env){
  #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
  F(t_sep_seq);
  F(t_c_comment);
  F(t_cpp_comment);
  F(t_sep);
  F(t_str);
  F(t_char);
  F(t_num);
  F(t_name);
  F(t_id);
  F(t_sign);
  F(t_soft_brackets);
  F(t_hard_brackets);
  F(t_curly_brackets);
  F(t_line);
  F(t_param);
  #undef F
}

/*
//list of types:
F(t_sep_seq);
F(t_c_comment);
F(t_cpp_comment);
F(t_sep);
F(t_raw_item);
F(t_hex_item);
F(t_num_item);
F(t_fix_item);
F(t_str);
F(t_raw_char);
F(t_hex_char);
F(t_num_char);
F(t_fix_char);
F(t_char);
F(t_number);
F(t_name);
F(t_id);
F(t_sign);
F(t_soft_brackets);
F(t_hard_brackets);
F(t_curly_brackets);
F(t_line);
F(t_param);

//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fsep%5Fseq%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%20%2
0go%5Fany%28body%2C%22%20%5Ct%5Cr%5Cn%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fc%5Fco
mment%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fco
nst%28%22%2F%2A%22%29%3B%0A%20%20%20%20go%5Fend%28body%2C%22%2A%2F%22%29%3B%0A%2
0%20%7D%0A%7D%0A%0At%5Fcpp%5Fcomment%3D%3Ei%5Fsep%7B%0A%20%20string%20body%3B%0A
%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%2F%2F%22%29%3B%0A%20%20%20%20go%5Fend%2
8body%2C%22%5Cn%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fsep%7B%0A%20%20vector%3CTAut
oPtr%3Ci%5Fsep%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28arr%29%3B%0A
%20%20%7D%0A%7D%0A%0At%5Fraw%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20string%20body
%3B%0A%20%20%7B%0A%20%20%20%20go%5Fany%28body%2Cdip%5Finv%28%22%5C%22%5C%5C%5Cn%
22%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fhex%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%2
0array%28char%2C2%29%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cx
%22%29%3B%0A%20%20%20%20go%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209afAF%22
%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fnum%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20a
rray%28char%2C2%29%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cu%2
2%29%3B%0A%20%20%20%20go%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209%22%29%29
%3B%0A%20%20%7D%0A%7D%0A%0At%5Ffix%5Fitem%3D%3Ei%5Fstr%5Fitem%7B%0A%20%20char%20
body%3D%27%5Cx00%27%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5C%22%29%3B
%0A%20%20%20%20go%5Fany%5Fchar%28body%2C%22tfbrn%5C%5C%5C%22%5C%27%22%2Bgen%5Fdi
ps%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fstr%3D%3Ei%5Fparam%7B%0A%20%20
vector%3CTAutoPtr%3Ci%5Fstr%5Fitem%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B
%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A
%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5C%22%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fra
w%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20string%20body%3B%0A%20%20%7B%0A%20%20%2
0%20go%5Fany%28body%2Cdip%5Finv%28%22%5C%27%5C%5C%5Cn%22%29%29%3B%0A%20%20%7D%0A
%7D%0A%0At%5Fhex%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20array%28char%2C2%29%20bo
dy%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cx%22%29%3B%0A%20%20%20%20g
o%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209afAF%22%29%29%3B%0A%20%20%7D%0A%
7D%0A%0At%5Fnum%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20array%28char%2C4%29%20bod
y%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%5Cu%22%29%3B%0A%20%20%20%20go
%5Fany%5Farr%5Fchar%28body%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%0A
%0At%5Ffix%5Fchar%3D%3Ei%5Fchar%5Fitem%7B%0A%20%20char%20body%3B%0A%20%20%7B%0A%
20%20%20%20go%5Fconst%28%22%5C%5C%22%29%3B%0A%20%20%20%20go%5Fany%5Fchar%28body%
2C%22tfbrn%5C%5C%5C%22%5C%27%22%2Bgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%
7D%0A%0At%5Fchar%3D%3Ei%5Fparam%7B%0A%20%20TAutoPtr%3Ci%5Fchar%5Fitem%3E%20body%
3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%5C%27%22%29%3B%0A%20%20%20%20go%5F
auto%28dev%2Cbody%29%3B%0A%20%20%20%20go%5Fconst%28%22%5C%27%22%29%3B%0A%20%20%7
D%0A%7D%0A%0At%5Fnumber%3D%3Ei%5Fparam%7B%0A%20%20string%20body%3B%0A%20%20%7B%0
A%20%20%20%20go%5Fany%28body%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%7D%0A%7D%
0A%0At%5Fname%7B%0A%20%20char%20A%3D%270x00%27%3B%0A%20%20string%20B%3B%0A%20%20
%7B%0A%20%20%20%20M%2B%3Dgo%5Fany%5Fchar%28A%2Cgen%5Fdips%28%22azAZ%22%29%2B%22%
5F%24%40%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fany%28B%2Cgen%5Fdips%28%22azAZ09%22%
29%2B%22%5F%24%40%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fid%3D%3Ei%5Fparam%7B%0A%20
%20t%5Fname%20body%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28body%29%3B%0A%20%20%
7D%0A%7D%0A%0At%5Fsign%3D%3Ei%5Fparam%7B%0A%20%20char%20body%3B%0A%20%20%7B%0A%2
0%20%20%20go%5Fany%5Fchar%28body%2C%22%7E%7C%26%3D%3C%3E%21%3A%3F%3B%2C%2E%2B%2D
%2A%2F%25%5E%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fsoft%5Fbrackets%3D%3Ei%5Fparam%
7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fparam%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%
20M%2B%3Dgo%5Fconst%28%22%28%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B
%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fha
rd%5Fbrackets%3D%3Ei%5Fparam%7B%0A%20%20vector%3CTAutoPtr%3Ci%5Fparam%3E%3E%20ar
r%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5B%22%29%3B%0A%20%20%20%2
0O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5D%22%29%3B%
0A%20%20%7D%0A%7D%0A%0At%5Fcurly%5Fbrackets%3D%3Ei%5Fparam%7B%0A%20%20vector%3CT
AutoPtr%3Ci%5Fparam%3E%3E%20arr%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fconst%2
8%22%7B%22%29%3B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3
Dgo%5Fconst%28%22%7D%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fline%7B%0A%20%20t%5Fnam
e%20cmd%3B%0A%20%20vector%3Ct%5Fparam%3E%20params%3B%0A%20%20%7B%0A%20%20%20%20g
o%5Fauto%28cmd%29%3B%0A%20%20%20%20go%5Fauto%28params%29%3B%0A%20%20%7D%0A%7D%0A
%0At%5Fparam%7B%0A%20%20t%5Fsep%20sep%3B%0A%20%20TAutoPtr%3Ci%5Fparam%3E%20body%
3B%0A%20%20%7B%0A%20%20%20%20O%2B%3Dgo%5Fauto%28sep%29%3B%0A%20%20%20%20M%2B%3Dg
o%5Fauto%28body%29%3B%0A%20%20%7D%0A%7D
*/