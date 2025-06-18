struct t_ic_dev{
  struct t_level{
    string name,full_name;
    vector<string> iarr;
    vector<string> carr;
  };
  vector<t_level> arr;
  t_level top;
  bool need_tautoptr(const string&name){
    if(qap_includes(top.iarr,name))return true;
    if(qap_includes(top.carr,name))return false;
    for(auto&it=arr.rbegin();it!=arr.rend();it++){
      if(qap_includes(it->iarr,name))return true;
      if(qap_includes(it->carr,name))return false;
    }
    return false;
  }
  void push(const string&name,const string&full_name){arr.push_back(std::move(top));top.name=name;top.full_name=full_name;}
  void pop(){top=std::move(arr.back());arr.pop_back();}
};

template<class TYPE>
static string vector_make_code(const vector<TYPE>&arr){
  string out;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    out+=ex->make_code();
  }
  return out;
}

class i_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_code
#include "QapGenStruct.inl"
//<<<<<+=====i_code
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

/*
//list of types:
F(t_name_code_with_sep)F(t_num_code_with_sep)F(t_str_code_with_sep)F(t_char_code_with_sep)
F(t_sign_code_with_sep)F(t_soft_brackets_code_with_sep)F(t_hard_brackets_code_with_sep)
F(t_curly_brackets_code_with_sep)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fname%5Fcode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fname%5Fcode%20body
%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%
7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%7Breturn%20body%2Emake%5Fcod
e%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D%0At%5Fnum%5Fcode%5Fwith%5Fsep%3D%3
Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fnum%5Fcode%20body%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5F
auto%28body%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7Dpublic%3A%0A%20%20string%20make%
5Fcode%28%29const%7Breturn%20body%2Emake%5Fcode%28%29%2Bsep%2Emake%5Fcode%28%29%
3B%7D%0A%7D%0At%5Fstr%5Fcode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fstr%5
Fcode%20body%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5Fauto%
28sep%29%3B%7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%7Breturn%20body%
2Emake%5Fcode%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D%0At%5Fchar%5Fcode%5Fwi
th%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fchar%5Fcode%20body%3Bt%5Fsep%20sep%3B%
7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%7Dpublic%3A%0A%20%20
string%20make%5Fcode%28%29const%7Breturn%20body%2Emake%5Fcode%28%29%2Bsep%2Emake
%5Fcode%28%29%3B%7D%0A%7D%0At%5Fsign%5Fcode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5F
sep%7Bt%5Fsign%5Fcode%20body%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO
%2B%3Dgo%5Fauto%28sep%29%3B%7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%
7Breturn%20body%2Emake%5Fcode%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D%0At%5F
soft%5Fbrackets%5Fcode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fsoft%5Fbrac
kets%5Fcode%20body%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5
Fauto%28sep%29%3B%7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%7Breturn%2
0body%2Emake%5Fcode%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D%0At%5Fhard%5Fbra
ckets%5Fcode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fhard%5Fbrackets%5Fcod
e%20body%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5Fauto%28se
p%29%3B%7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%7Breturn%20body%2Ema
ke%5Fcode%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D%0At%5Fcurly%5Fbrackets%5Fc
ode%5Fwith%5Fsep%3D%3Ei%5Fcode%5Fwith%5Fsep%7Bt%5Fcurly%5Fbrackets%5Fcode%20body
%3Bt%5Fsep%20sep%3B%7BM%2B%3Dgo%5Fauto%28body%29%3BO%2B%3Dgo%5Fauto%28sep%29%3B%
7Dpublic%3A%0A%20%20string%20make%5Fcode%28%29const%7Breturn%20body%2Emake%5Fcod
e%28%29%2Bsep%2Emake%5Fcode%28%29%3B%7D%0A%7D
*/

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

class t_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_code>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_code
#include "QapGenStruct.inl"
//<<<<<+=====t_code
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
  string make_code()const{return vector_make_code(arr);};
};

class t_soft_brackets_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_soft_brackets_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_soft_brackets_code
#include "QapGenStruct.inl"
//<<<<<+=====t_soft_brackets_code
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

class t_hard_brackets_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hard_brackets_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_hard_brackets_code
#include "QapGenStruct.inl"
//<<<<<+=====t_hard_brackets_code
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

class t_curly_brackets_code:public i_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_curly_brackets_code)PARENT(i_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(TAutoPtr<t_code>,body,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_curly_brackets_code
#include "QapGenStruct.inl"
//<<<<<+=====t_curly_brackets_code
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

class t_semicolon{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_semicolon
#include "QapGenStruct.inl"
//<<<<<+=====t_semicolon
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const(";");
    if(!ok)return ok;
    return ok;
  }
};

class t_value_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_code_with_sep>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_value_item
#include "QapGenStruct.inl"
//<<<<<+=====t_value_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_minor<t_semicolon>(body);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return body->make_code();
  }
};

class t_value{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_value
#include "QapGenStruct.inl"
//<<<<<+=====t_value
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class i_type_templ{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_templ)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_type_templ
#include "QapGenStruct.inl"
//<<<<<+=====i_type_templ
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load();
    #include "QapLexPolyEnd.inl"
  };
  virtual string make_code()const{QapDebugMsg("no way."); return "";};
};

class t_type_scope{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_type_scope
#include "QapGenStruct.inl"
//<<<<<+=====t_type_scope
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("::");
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return "::";
  }
};

class t_type_templ{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_type_templ>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ
#include "QapGenStruct.inl"
//<<<<<+=====t_type_templ
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

class i_type_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_type_item
#include "QapGenStruct.inl"
//<<<<<+=====i_type_item
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

class t_type_item_string:public i_type_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_string)PARENT(i_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_str_item,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_item_string
#include "QapGenStruct.inl"
//<<<<<+=====t_type_item_string
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
  string make_code()const{
    return body.get_code();
  };
};

class t_type_item_char:public i_type_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_char)PARENT(i_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_char_item,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_item_char
#include "QapGenStruct.inl"
//<<<<<+=====t_type_item_char
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
  string make_code()const{
    return body.get_code();
  };
};

class t_type_item_number:public i_type_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_number)PARENT(i_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_number,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_item_number
#include "QapGenStruct.inl"
//<<<<<+=====t_type_item_number
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
  string make_code()const{
    return body.body;
  };
};

class t_scope_type_item;

class t_type_item_type:public i_type_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_item_type)PARENT(i_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_type_scope>,scope,DEF,$,$)\
ADDVAR(t_name,type,DEF,$,$)\
ADDVAR(TAutoPtr<t_type_templ>,param,DEF,$,$)\
ADDVAR(vector<t_scope_type_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_item_type
#include "QapGenStruct.inl"
//<<<<<+=====t_type_item_type
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(this->scope);
    if(!ok)return ok;
    M+=dev.go_auto(this->type);
    if(!ok)return ok;
    O+=dev.go_auto(this->param);
    if(!ok)return ok;
    O+=dev.go_auto(this->arr);
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

class t_scope_type_item{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope_type_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_type_scope,scope,DEF,$,$)\
ADDVAR(t_type_item_type,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_scope_type_item
#include "QapGenStruct.inl"
//<<<<<+=====t_scope_type_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(this->scope);
    if(!ok)return ok;
    D+=dev.go_auto(this->body);
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

class t_type_expr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_type_scope>,scope,DEF,$,$)\
ADDVAR(t_type_item_type,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_expr
#include "QapGenStruct.inl"
//<<<<<+=====t_type_expr
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(this->scope);
    if(!ok)return ok;
    M+=dev.go_auto(this->body);
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

class t_type_templ_param{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_type_item>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ_param
#include "QapGenStruct.inl"
//<<<<<+=====t_type_templ_param
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
  string make_code()const{
    return body->make_code();
  };
};

class t_sep_type_templ_param{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_type_templ_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_type_templ_param,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_type_templ_param
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_type_templ_param
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_type_templ_params{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_params)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_type_templ_param,first,DEF,$,$)\
ADDVAR(vector<t_sep_type_templ_param>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ_params
#include "QapGenStruct.inl"
//<<<<<+=====t_type_templ_params
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
    string out;
    out+=first.make_code();
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out+=ex.make_code();
    }
    return out;
  };
};

class t_type_templ_angle:public i_type_templ{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_angle)PARENT(i_type_templ)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_type_templ_params>,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ_angle
#include "QapGenStruct.inl"
//<<<<<+=====t_type_templ_angle
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_type_templ_soft:public i_type_templ{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type_templ_soft)PARENT(i_type_templ)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_type_templ_params>,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type_templ_soft
#include "QapGenStruct.inl"
//<<<<<+=====t_type_templ_soft
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_struct_cmd_mode{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd_mode)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,SET,'M',$)\
ADDEND()
//=====+>>>>>t_struct_cmd_mode
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_cmd_mode
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_any_char(body,"MO");
    if(!ok)return ok;
    M+=dev.go_const("+=");
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_field{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_struct_cmd_mode>,mode,DEF,$,$)\
ADDVAR(t_sep,sepcm,DEF,$,$)\
ADDVAR(string,type,DEF,$,$)\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_field
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_field
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(mode);
    if(!ok)return ok;
    O+=dev.go_auto(sepcm);
    if(!ok)return ok;
    M+=dev.go_str<t_type_expr>(type);
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
    return ok;
  }
  string make_code(int id,t_ic_dev&icdev)const{
    vector<string> out;
    string mode=value?"SET":"DEF";
    //out.push_back(IToS(id));
    auto t=type;//.make_code();
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
    return "ADDVAR("+join(out,",")+",$)\\\n";
  }
};

class t_sep_struct_field{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_field)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_field,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_field
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_struct_field
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_templ_params{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_params)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_params
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_params
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_const("<");
    if(!ok)return ok;
    D+=dev.go_str<TAutoPtr<t_type_templ_params>>(body);
    if(!ok)return ok;
    D+=dev.go_const(">");
    if(!ok)return ok;
    return ok;
  }
};

class t_cmd_param;
class t_cmd_params{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_params)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_cmd_param>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cmd_params
#include "QapGenStruct.inl"
//<<<<<+=====t_cmd_params
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_vec(arr,",");
    if(!ok)return ok;
    return ok;
  }
};

class t_cmd_param{
public:
  class i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_cmd_param)
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
      bool load();
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_cmd_param)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_expr>>,arr,DEF,$,$)\
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
      D+=dev.go_vec(arr,"+");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_expr_call:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_call)PARENT(i_expr)OWNER(t_cmd_param)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_name,func,DEF,$,$)\
  ADDVAR(TAutoPtr<t_cmd_params>,params,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_call
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_call
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
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
  class t_expr_str:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_str)PARENT(i_expr)OWNER(t_cmd_param)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_str
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_str
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_str_seq>(body);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_expr_var:public i_expr{
  public:
    class t_this{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_this)OWNER(t_expr_var)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_this
    #include "QapGenStruct.inl"
    //<<<<<+=====t_this
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const("this->");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_expr_var)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(TAutoPtr<t_this>,self,DEF,$,$)\
    ADDVAR(t_name,name,DEF,$,$)\
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
        O+=dev.go_auto(self);
        if(!ok)return ok;
        M+=dev.go_auto(name);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)F(t_this)F(t_impl)
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_var)PARENT(i_expr)OWNER(t_cmd_param)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_expr_var
  #include "QapGenStruct.inl"
  //<<<<<+=====t_expr_var
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_str<t_impl>(body);
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(t_impl)F(t_expr_call)F(t_expr_str)F(t_expr_var)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cmd_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cmd_param
#include "QapGenStruct.inl"
//<<<<<+=====t_cmd_param
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_str<t_impl>(body);
    if(!ok)return ok;
    return ok;
  }
};

class t_struct_cmd{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_struct_cmd_mode>,mode,DEF,$,$)\
ADDVAR(t_name,func,DEF,$,$)\
ADDVAR(string,templ_params,DEF,$,$)\
ADDVAR(t_cmd_params,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmd
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_cmd
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
    //return make_code_gp();
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

class t_sep_struct_cmd{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmd)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_cmd,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_cmd
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_struct_cmd
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_struct_cmds{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_cmds)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_sep_struct_cmd>,arr,DEF,$,$)\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_cmds
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_cmds
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("{");
    if(!ok)return ok;
    M+=dev.go_auto(arr);
    if(!ok)return ok;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_const("}");
    if(!ok)return ok;
    return ok;
  }
};

class t_sep_struct_cmds{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_struct_cmds)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(t_struct_cmds,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_struct_cmds
#include "QapGenStruct.inl"
//<<<<<+=====t_sep_struct_cmds
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
};

class i_cpp_code{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_cpp_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_cpp_code
#include "QapGenStruct.inl"
//<<<<<+=====i_cpp_code
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

class t_cpp_code_sep:public i_cpp_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_sep)PARENT(i_cpp_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_code_sep
#include "QapGenStruct.inl"
//<<<<<+=====t_cpp_code_sep
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(sep);
    if(!ok)return ok;
    return ok;
  }
  string make_code()const{
    return sep.make_code();
  }
};

class t_cpp_code_main:public i_cpp_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code_main)PARENT(i_cpp_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_code_with_sep>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_code_main
#include "QapGenStruct.inl"
//<<<<<+=====t_cpp_code_main
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
  string make_code()const{
    string out;
    auto*p=body.get();
    out=p->make_code();
    return out;
  }
};

class t_cpp_code{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp_code)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_cpp_code>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_cpp_code
#include "QapGenStruct.inl"
//<<<<<+=====t_cpp_code
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_const("[::]");
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
      //return line.size();
    };
    int count=-1;//get(arr[0]);
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
    //return align(out);
  }
};

class t_target_item;

class t_struct_body{
public:
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
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_body
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
public:
  struct t_target_item_out;
  struct t_out{
    vector<const t_target_item*> nested;
    string provars;
    string procmds;
    string cppcode;
  };
  struct t_target_item_out{
    string name;
    string parent;
    t_out out;
  };
  template<int>
  static t_target_item_out weak_make_code(const t_target_item&ref,t_ic_dev&icdev);
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
    {
      auto&arr=nested;
      out.nested.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&to=out.nested[i];
        to=&ex;//std::move(weak_make_code<0>(ex,iarr));
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
    out.cppcode=cppcode?cppcode->make_code():"";
    return out;
  }
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
  #define ADD(TYPE)virtual void Do(TYPE*p)=0;
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

class i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_def
#include "QapGenStruct.inl"
//<<<<<+=====i_def
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load();
    #include "QapLexPolyEnd.inl"
  };
public:
  struct t_out{
    string name;
    string parent;
  };
  virtual t_out make_code(){QapDebugMsg("no way.");return *(t_out*)nullptr;}
};

class t_class_def:public i_def{
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
#include "QapGenStruct.inl"
//<<<<<+=====t_class_def
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    M+=dev.go_auto(name);
    if(!ok)return ok;
    O+=dev.go_auto(sep0);
    if(!ok)return ok;
    static auto static_var=split("=>,:",",");
    M+=dev.go_any_str_from_vec(arrow_or_colon,static_var);
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

class t_struct_def:public i_def{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_struct_def)PARENT(i_def)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDEND()
//=====+>>>>>t_struct_def
#include "QapGenStruct.inl"
//<<<<<+=====t_struct_def
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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
struct i_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_target_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_target_item
#include "QapGenStruct.inl"
//<<<<<+=====i_target_item
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    template<int>
    bool load();
    #include "QapLexPolyEnd.inl"
  };
};
class t_target_item:public i_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_item)PARENT(i_target_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep,DEF,$,$)\
ADDVAR(TAutoPtr<i_def>,def,DEF,$,$)\
ADDVAR(t_struct_body,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target_item
#include "QapGenStruct.inl"
//<<<<<+=====t_target_item
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    O+=dev.go_auto(sep);
    if(!ok)return ok;
    M+=dev.go_auto(def);
    if(!ok)return ok;
    M+=dev.go_auto(body);
    if(!ok)return ok;
    return ok;
  }
  typedef t_struct_body::t_target_item_out t_out;
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
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
class t_target_decl:public i_target_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target_decl)PARENT(i_target_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,sep0,DEF,$,$)\
ADDVAR(string,name,DEF,$,$)\
ADDVAR(t_sep,sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target_decl
#include "QapGenStruct.inl"
//<<<<<+=====t_target_decl
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

class t_target{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_target)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_target_item>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_target
#include "QapGenStruct.inl"
//<<<<<+=====t_target
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
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

/*void RegAllMetaLex(IEnvRTTI&Env){
  #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};
  F(t_class_def);
  F(t_struct_def);
  F(t_name_code);
  F(t_num_code);
  F(t_str_code);
  F(t_char_code);
  F(t_sign_code);
  F(t_soft_brackets_code);
  F(t_hard_brackets_code);
  F(t_curly_brackets_code);
  F(t_type_templ_angle);
  F(t_type_templ_soft);
  F(t_type_item_type);
  F(t_type_item_string);
  F(t_type_item_char);
  F(t_type_item_number);
  F(t_name_code_with_sep);
  F(t_num_code_with_sep);
  F(t_str_code_with_sep);
  F(t_char_code_with_sep);
  F(t_sign_code_with_sep);
  F(t_soft_brackets_code_with_sep);
  F(t_hard_brackets_code_with_sep);
  F(t_curly_brackets_code_with_sep);
  F(t_cpp_code_sep);
  F(t_cpp_code_main);
  #undef F
}*/

template<int>
bool i_target_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_target_item);
  F(t_target_decl);
  #undef F
  main();
  return scope.ok;
}

template<int>
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

template<int>
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

template<int>
bool i_type_templ::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_type_templ_angle);
  F(t_type_templ_soft);
  #undef F
  main();
  return scope.ok;
}

template<int>
bool i_type_item::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_type_item_type);
  F(t_type_item_string);
  F(t_type_item_char);
  F(t_type_item_number);
  #undef F
  main();
  return scope.ok;
}

template<int>
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

template<int>
bool i_cpp_code::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_cpp_code_sep);
  F(t_cpp_code_main);
  #undef F
  main();
  return scope.ok;
}

template<int>
bool i_def::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_class_def);
  F(t_struct_def);
  #undef F
  main();
  return scope.ok;
}

template<int>
t_struct_body::t_target_item_out t_struct_body::weak_make_code(const t_target_item&ref,t_ic_dev&icdev){
  return std::move(ref.make_code(icdev));
}