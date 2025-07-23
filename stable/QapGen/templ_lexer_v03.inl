// 251.456800 ms
struct t_templ_sys_v03{
  struct t_head{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_head)OWNER(t_templ_sys_v03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_head
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_head
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v03::t_head");
      auto&ok=$.ok;
      ok=dev.go_const("----------------------------------------------------------------\n");$(ok,",\"-\"");
      if(!ok)return ok;
      ok=dev.go_const("#####-");$(ok,",\"#\"");
      if(!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("azAZ09")+"_$@");
      ok=dev.go_any(name,g_static_var_2);$(ok,",gen_dips(\"09@Zaz\")+\"$_\"");
      if(!ok)return ok;
      ok=dev.go_const("-#####\n");$(ok,",\"-\"");
      if(!ok)return ok;
      ok=dev.go_const("----------------------------------------------------------------\n");$(ok,",\"-\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)OWNER(t_templ_sys_v03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_head,head,DEF,$,$)\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_scope
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_templ_sys_v03::t_scope");
      auto&ok=$.ok;
      ok=dev.go_auto(head);$(ok,"t_head,\"-\"");
      if(!ok)return ok;
      {bool ok=dev.go_str_without<t_head>(body);$(ok,",gen_dips(\"\\x00\\xFF\")");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_head )\
  F(t_scope)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_sys_v03)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_scope>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_sys_v03
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_templ_sys_v03
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_templ_sys_v03");
    auto&ok=$.ok;
    ok=dev.go_auto(arr);$(ok,"vector<t_scope>,\"-\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
/*
//list of types:
F(t_templ_sys_v03)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5ftempl%5fsys%5fv03%7b%0a%20%20t%5fhead%7b%0a%20%20%20%20string%20name%3b%0a%2
0%20%20%20%7b%0a%20%20%20%20%20%20go%5fconst%28%22%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d
%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2
d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%
2d%5cn%22%29%3b%0a%20%20%20%20%20%20go%5fconst%28%22%23%23%23%23%23%2d%22%29%3b%
0a%20%20%20%20%20%20go%5fany%28name%2cgen%5fdips%28%22azAZ09%22%29%2b%22%5f%24%4
0%22%29%3b%0a%20%20%20%20%20%20go%5fconst%28%22%2d%23%23%23%23%23%5cn%22%29%3b%0
a%20%20%20%20%20%20go%5fconst%28%22%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d
%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2
d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%5cn%22%29%3b
%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20t%5fscope%7b%0a%20%20%20%20t%5fhead%20hea
d%3b%0a%20%20%20%20string%20body%3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20M%2b%3
dgo%5fauto%28head%29%3b%0a%20%20%20%20%20%20O%2b%3dgo%5fstr%5fwithout%3ct%5fhead
%3e%28body%29%3b%0a%20%20%20%20%7d%0a%20%20%7d%0a%20%20vector%3ct%5fscope%3e%20a
rr%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28arr%29%3b%0a%20%20%7d%0a%7d
*/