// 26.141900 ms
struct t_config_2013{
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_config_2013::t_item");
      auto&ok=$.ok;
      ok=dev.go_const("\n");$(ok,",\"\\n\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("azAZ09")+"_$@:");
      ok=dev.go_any(type,g_static_var_1);$(ok,",gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_info{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_info)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,type,DEF,$,$)\
  ADDVAR(string,pos,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_info
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_info
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_config_2013::t_info");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ09")+"_$@:");
      ok=dev.go_any(type,g_static_var_0);$(ok,",gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      ok=dev.go_const("(");$(ok,",\"(\"");
      if(!ok)return ok;
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(pos,g_static_var_2);$(ok,",\"0123456789\"");
      if(!ok)return ok;
      ok=dev.go_const(")");$(ok,",\")\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_event{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_event)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,time,DEF,$,$)\
  ADDVAR(t_info,A,DEF,$,$)\
  ADDVAR(t_info,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_event
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_event
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_config_2013::t_event");
      auto&ok=$.ok;
      ok=dev.go_const("\n+[");$(ok,",\"\\n\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09")+".: ");
      ok=dev.go_any(time,g_static_var_1);$(ok,",\"0123456789.: \"");
      if(!ok)return ok;
      ok=dev.go_const("] ");$(ok,",\"]\"");
      if(!ok)return ok;
      ok=dev.go_auto(A);$(ok,"t_info,gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      ok=dev.go_const(" ");$(ok,",\" \"");
      if(!ok)return ok;
      ok=dev.go_auto(B);$(ok,"t_info,gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_line{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_line)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,head,DEF,$,$)\
  ADDVAR(vector<t_item>,arr,DEF,$,$)\
  ADDVAR(vector<t_event>,events,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_line
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_line
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_config_2013::t_line");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ09")+"_$@:");
      ok=dev.go_any(head,g_static_var_0);$(ok,",gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      ok=dev.go_const("\n====>");$(ok,",\"\\n\"");
      if(!ok)return ok;
      ok=dev.go_const("\n[arr]");$(ok,",\"\\n\"");
      if(!ok)return ok;
      ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\n\"");
      if(!ok)return ok;
      ok=dev.go_const("\n[events]");$(ok,",\"\\n\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto(events);$(ok,"vector<t_event>,\"\\n\"");}
      ok=dev.go_const("\n<====\n");$(ok,",\"\\n\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_doc{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_doc)OWNER(t_config_2013)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_line>,lines,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_doc
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_doc
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_config_2013::t_doc");
      auto&ok=$.ok;
      ok=dev.go_auto(lines);$(ok,"vector<t_line>,gen_dips(\"0:@Zaz\")+\"$_\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_item )\
  F(t_info )\
  F(t_event)\
  F(t_line )\
  F(t_doc  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_config_2013)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_line>,lines,DEF,$,$)\
ADDEND()
//=====+>>>>>t_config_2013
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_config_2013
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_config_2013");
    auto&ok=$.ok;
    ok=dev.go_auto(lines);$(ok,"vector<t_line>,gen_dips(\"0:@Zaz\")+\"$_\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
/*
//list of types:
F(t_config_2013)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fconfig%5f2013%7b%0at%5fitem%7b%0a%20%20string%20type%3b%0a%20%20%7b%0a%20%20
%20%20go%5fconst%28%22%5cn%22%29%3b%0a%20%20%20%20go%5fany%28type%2cgen%5fdips%2
8%22azAZ09%22%29%2b%22%5f%24%40%3a%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5finfo%7b%0
a%20%20string%20type%3b%0a%20%20string%20pos%3b%0a%20%20%7b%0a%20%20%20%20go%5fa
ny%28type%2cgen%5fdips%28%22azAZ09%22%29%2b%22%5f%24%40%3a%22%29%3b%0a%20%20%20%
20go%5fconst%28%22%28%22%29%3b%0a%20%20%20%20go%5fany%28pos%2cgen%5fdips%28%2209
%22%29%29%3b%0a%20%20%20%20go%5fconst%28%22%29%22%29%3b%0a%20%20%7d%0a%7d%0a%0at
%5fevent%7b%0a%20%20string%20time%3b%0a%20%20t%5finfo%20A%3b%0a%20%20t%5finfo%20
B%3b%0a%20%20%7b%0a%20%20%20%20go%5fconst%28%22%5cn%2b%5b%22%29%3b%0a%20%20%20%2
0go%5fany%28time%2cgen%5fdips%28%2209%22%29%2b%22%2e%3a%20%22%29%3b%0a%20%20%20%
20go%5fconst%28%22%5d%20%22%29%3b%0a%20%20%20%20go%5fauto%28A%29%3b%0a%20%20%20%
20go%5fconst%28%22%20%22%29%3b%0a%20%20%20%20go%5fauto%28B%29%3b%0a%20%20%7d%0a%
7d%0a%0at%5fline%7b%0a%20%20string%20head%3b%0a%20%20vector%3ct%5fitem%3e%20arr%
3b%0a%20%20vector%3ct%5fevent%3e%20events%3b%0a%20%20%7b%0a%20%20%20%20M%2b%3dgo
%5fany%28head%2cgen%5fdips%28%22azAZ09%22%29%2b%22%5f%24%40%3a%22%29%3b%0a%20%20
%20%20M%2b%3dgo%5fconst%28%22%5cn%3d%3d%3d%3d%3e%22%29%3b%0a%20%20%20%20M%2b%3dg
o%5fconst%28%22%5cn%5barr%5d%22%29%3b%0a%20%20%20%20M%2b%3dgo%5fauto%28arr%29%3b
%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5cn%5bevents%5d%22%29%3b%0a%20%20%20%20O%
2b%3dgo%5fauto%28events%29%3b%0a%20%20%20%20M%2b%3dgo%5fconst%28%22%5cn%3c%3d%3d
%3d%3d%5cn%22%29%3b%0a%20%20%7d%0a%7d%0a%0at%5fdoc%7b%0a%20%20vector%3ct%5fline%
3e%20lines%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28lines%29%3b%0a%20%20%7d%0a%7
d%0avector%3ct%5fline%3e%20lines%3b%0a%7d
*/