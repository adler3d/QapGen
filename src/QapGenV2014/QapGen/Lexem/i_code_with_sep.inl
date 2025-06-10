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
    bool load()
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
    }
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


template<class TYPE>
static string vector_make_code(const vector<TYPE>&arr){
  string out;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    out+=ex->make_code();
  }
  return out;
}

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