class t_templ_sys_v03{
public:
  class t_head{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_head)OWNER(t_templ_sys_v03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_head
  #include "QapGenStruct.inl"
  //<<<<<+=====t_head
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      ok=dev.go_const("----------------------------------------------------------------\n");
      if(!ok)return ok;
      ok=dev.go_const("#####-");
      if(!ok)return ok;
      static const string g_static_dip_2=gen_dips("azAZ09")+"_$@";
      ok=dev.go_any(name,g_static_dip_2);
      if(!ok)return ok;
      ok=dev.go_const("-#####\n");
      if(!ok)return ok;
      ok=dev.go_const("----------------------------------------------------------------\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)OWNER(t_templ_sys_v03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_head,head,DEF,$,$)\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scope
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      ok=dev.go_auto(head);
      if(!ok)return ok;
      dev.go_str_without<t_head>(body);
      if(!ok)return ok;
      return ok;
    }
  };
public:
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
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_sys_v03
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    ok=dev.go_auto(arr);
    if(!ok)return ok;
    return ok;
  }
public:
  //class t_static_visitor{
  //public:
  //  #define F(TYPE)typedef t_templ_sys_v03::TYPE TYPE;
  //  F(t_head);
  //  F(t_scope);
  //  #undef F
  //public:
  //  void Do(t_head&ref){}
  //  void Do(t_scope&ref){}
  //};
};

/*
//list of types:
F(t_templ_sys_v03)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Ftempl%5Fsys%5Fv03%7B%0A%20%20t%5Fhead%7B%0A%20%20%20%20string%20name%3B%0A%2
0%20%20%20%7B%0A%20%20%20%20%20%20go%5Fconst%28%22%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D
%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2
D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%
2D%5Cn%22%29%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%23%23%23%23%23%2D%22%29%3B%
0A%20%20%20%20%20%20go%5Fany%28name%2Cgen%5Fdips%28%22azAZ09%22%29%2B%22%5F%24%4
0%22%29%3B%0A%20%20%20%20%20%20go%5Fconst%28%22%2D%23%23%23%23%23%5Cn%22%29%3B%0
A%20%20%20%20%20%20go%5Fconst%28%22%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D
%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2
D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%2D%5Cn%22%29%3B
%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20t%5Fscope%7B%0A%20%20%20%20t%5Fhead%20hea
d%3B%0A%20%20%20%20string%20body%3B%0A%20%20%20%20%7B%0A%20%20%20%20%20%20M%2B%3
Dgo%5Fauto%28head%29%3B%0A%20%20%20%20%20%20O%2B%3Dgo%5Fstr%5Fwithout%3Ct%5Fhead
%3E%28body%29%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20vector%3Ct%5Fscope%3E%20a
rr%3B%0A%20%20%7B%0A%20%20%20%20go%5Fauto%28arr%29%3B%0A%20%20%7D%0A%7D
*/