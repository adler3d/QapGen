class t_config_2013{
public:
  class t_item{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStruct.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\n");
      if(!ok)return ok;
      D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_info{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_info)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,pos,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_info
  #include "QapGenStruct.inl"
  //<<<<<+=====t_info
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_any(type,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_any(pos,gen_dips("09"));
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_event{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_event)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,time,DEF,$,$)\
  ADDVAR(t_info,A,DEF,$,$)\
  ADDVAR(t_info,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_event
  #include "QapGenStruct.inl"
  //<<<<<+=====t_event
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("\n+[");
      if(!ok)return ok;
      D+=dev.go_any(time,gen_dips("09")+".: ");
      if(!ok)return ok;
      D+=dev.go_const("] ");
      if(!ok)return ok;
      D+=dev.go_auto(A);
      if(!ok)return ok;
      D+=dev.go_const(" ");
      if(!ok)return ok;
      D+=dev.go_auto(B);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_line{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,head,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDVAR(vector<t_event>,events,DEF,$,$)\
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
      M+=dev.go_any(head,gen_dips("azAZ09")+"_$@:");
      if(!ok)return ok;
      M+=dev.go_const("\n====>");
      if(!ok)return ok;
      M+=dev.go_const("\n[arr]");
      if(!ok)return ok;
      M+=dev.go_auto(arr);
      if(!ok)return ok;
      M+=dev.go_const("\n[events]");
      if(!ok)return ok;
      O+=dev.go_auto(events);
      if(!ok)return ok;
      M+=dev.go_const("\n<====\n");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_doc{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_doc)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_line>,lines,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_doc
  #include "QapGenStruct.inl"
  //<<<<<+=====t_doc
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(lines);
      if(!ok)return ok;
      return ok;
    }
  };

  /*
  //list of types:
  F(t_item)F(t_info)F(t_event)F(t_line)F(t_doc)
  //app:
  adler3d.github.io/test2013/
  //code:
  return decodeURIComponent(POST['data'].split("\n").join(""));
  //data:
  t%5Fitem%7B%0A%20%20string%20type%3B%0A%20%20%7B%0A%20%20%20%20go%5Fconst%28%22%
  5Cn%22%29%3B%0A%20%20%20%20go%5Fany%28type%2Cgen%5Fdips%28%22azAZ09%22%29%2B%22%
  5F%24%40%3A%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Finfo%7B%0A%20%20string%20type%3B
  %0A%20%20string%20pos%3B%0A%20%20%7B%0A%20%20%20%20go%5Fany%28type%2Cgen%5Fdips%
  28%22azAZ09%22%29%2B%22%5F%24%40%3A%22%29%3B%0A%20%20%20%20go%5Fconst%28%22%28%2
  2%29%3B%0A%20%20%20%20go%5Fany%28pos%2Cgen%5Fdips%28%2209%22%29%29%3B%0A%20%20%2
  0%20go%5Fconst%28%22%29%22%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fevent%7B%0A%20%20str
  ing%20time%3B%0A%20%20t%5Finfo%20A%3B%0A%20%20t%5Finfo%20B%3B%0A%20%20%7B%0A%20%
  20%20%20go%5Fconst%28%22%5Cn%2B%5B%22%29%3B%0A%20%20%20%20go%5Fany%28time%2Cgen%
  5Fdips%28%2209%22%29%2B%22%2E%3A%20%22%29%3B%0A%20%20%20%20go%5Fconst%28%22%5D%2
  0%22%29%3B%0A%20%20%20%20go%5Fauto%28A%29%3B%0A%20%20%20%20go%5Fconst%28%22%20%2
  2%29%3B%0A%20%20%20%20go%5Fauto%28B%29%3B%0A%20%20%7D%0A%7D%0A%0At%5Fline%7B%0A%
  20%20string%20head%3B%0A%20%20vector%3Ct%5Fitem%3E%20arr%3B%0A%20%20vector%3Ct%5
  Fevent%3E%20events%3B%0A%20%20%7B%0A%20%20%20%20M%2B%3Dgo%5Fany%28head%2Cgen%5Fd
  ips%28%22azAZ09%22%29%2B%22%5F%24%40%3A%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst
  %28%22%5Cn%3D%3D%3D%3D%3E%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5Cn%5Ba
  rr%5D%22%29%3B%0A%20%20%20%20M%2B%3Dgo%5Fauto%28arr%29%3B%0A%20%20%20%20M%2B%3Dg
  o%5Fconst%28%22%5Cn%5Bevents%5D%22%29%3B%0A%20%20%20%20O%3D%2Bgo%5Fauto%28events
  %29%3B%0A%20%20%20%20M%2B%3Dgo%5Fconst%28%22%5Cn%3C%3D%3D%3D%3D%5Cn%22%29%3B%0A%
  20%20%7D%0A%7D%0A%0At%5Fdoc%7B%0A%20%20vector%3Ct%5Fline%3E%20lines%3B%0A%20%20%
  7B%0A%20%20%20%20go%5Fauto%28lines%29%3B%0A%20%20%7D%0A%7D
  */
public:
#define DEF_PRO_NESTED(F)F(t_item)F(t_info)F(t_event)F(t_line)F(t_doc)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_config_2013)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_config_2013
#include "QapGenStruct.inl"
//<<<<<+=====t_config_2013
};