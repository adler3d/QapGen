// 484.187400 ms
struct t_xml_scope{
  //===>>===i_node_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_comment)\
    ADD(t_text)\
    ADD(t_start)\
    ADD(t_end)\
  ADDEND()
  class i_node;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_node_visitor{
  public:
    typedef t_xml_scope::i_node i_node;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_xml_scope::U U;//typedef t_xml_scope::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
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
    static TYPE*UberCast(i_node*p){
      if(!p)return nullptr;Is<TYPE,i_node_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_node*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_node_visitor{
  //  void Do(t_comment&r){}
  //  void Do(t_text&r){}
  //  void Do(t_start&r){}
  //  void Do(t_end&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_node_visitor
  struct i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_node
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_node
  public:
    typedef i_node_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_node()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_comment);
        F(t_text);
        F(t_start);
        F(t_end);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_name{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,A,DEF,$,$)\
  ADDVAR(string,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ")+"_$@");
      ok=dev.go_any_char(A,g_static_var_0);
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("azAZ09")+"_$@-.:");
      dev.go_any(B,g_static_var_1);
      return ok;
    }
  };
  struct t_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(" \r\n");
      ok=dev.go_any(body,g_static_var_0);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_comment:public i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comment)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comment
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_comment
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("<!--");
      if(!ok)return ok;
      ok=dev.go_end(body,"-->");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_text:public i_node{
    struct t_raw{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)OWNER(t_text)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,text,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_raw
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_raw
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(dip_inv("<"));
        ok=dev.go_any(text,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_raw)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_text)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,text,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_text
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_text
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<vector<TAutoPtr<t_raw>>>(text);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_start:public i_node{
    //===>>===i_value_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
      ADD(t_string)\
      ADD(t_number)\
    ADDEND()
    class i_value;
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_value_visitor{
    public:
      typedef t_start::i_value i_value;
    public:
      #define ADD(TYPE)virtual void Do(TYPE&r)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_start::U U;//typedef t_start::U U;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #ifdef QAP_FAST_UBERCAST
      template<class TYPE,class Visitor>
      struct Is:public Visitor{
        TYPE*ptr{};
      public:
        #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
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
      static TYPE*UberCast(i_value*p){
        if(!p)return nullptr;Is<TYPE,i_value_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_value*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    //struct t_visitor:public i_value_visitor{
    //  void Do(t_string&r){}
    //  void Do(t_number&r){}
    //};
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_value_visitor
    struct i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_value
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_value
    public:
      typedef i_value_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
      virtual ~i_value()=default;
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        void load();/*
        {
          F(t_string);
          F(t_number);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    struct t_string:public i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_string
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_string
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("\"");
        if(!ok)return ok;
        dev.go_str<vector<TAutoPtr<i_str_item>>>(value);
        ok=dev.go_const("\"");
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_number:public i_value{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_value)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_number
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_number
    public:
      void Use(i_visitor&A){A.Do(*this);}
      static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
        ok=dev.go_any(value,g_static_var_0);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_attr{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_attr)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,sep0,DEF,$,$)\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(string,sep1,DEF,$,$)\
    ADDVAR(string,sep2,DEF,$,$)\
    ADDVAR(TAutoPtr<i_value>,value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_attr
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_attr
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_str<t_sep>(sep0);
        if(!ok)return ok;
        ok=dev.go_str<t_name>(name);
        if(!ok)return ok;
        dev.go_str<t_sep>(sep1);
        ok=dev.go_const("=");
        if(!ok)return ok;
        dev.go_str<t_sep>(sep2);
        ok=dev.go_auto(value);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_slash{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_slash)OWNER(t_start)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_slash
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_slash
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const("/");
        if(!ok)return ok;
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_string)\
    F(t_number)\
    F(t_attr  )\
    F(t_slash )\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_start)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,sep0,DEF,$,$)\
  ADDVAR(string,tag,DEF,$,$)\
  ADDVAR(vector<t_attr>,attrs,DEF,$,$)\
  ADDVAR(string,sep1,DEF,$,$)\
  ADDVAR(string,slash,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_start
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_start
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("<");
      if(!ok)return ok;
      dev.go_str<t_sep>(sep0);
      ok=dev.go_str<t_name>(tag);
      if(!ok)return ok;
      dev.go_auto(attrs);
      dev.go_str<t_sep>(sep1);
      dev.go_str<TAutoPtr<t_slash>>(slash);
      ok=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_end:public i_node{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_end)PARENT(i_node)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,tag,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_end
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_end
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("</");
      if(!ok)return ok;
      ok=dev.go_str<t_name>(tag);
      if(!ok)return ok;
      ok=dev.go_const(">");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_content{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_content)OWNER(t_xml_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_node>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_content
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_content
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(arr);
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_name   )\
  F(t_sep    )\
  F(t_comment)\
  F(t_text   )\
  F(t_start  )\
  F(t_end    )\
  F(t_content)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_xml_scope)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_xml_scope
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_xml_scope
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    return ok;
  }
public:
};
void t_xml_scope::i_node::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,4> lex={
    F(t_comment,"<"),
    F(t_text,gen_dips("\x00;=\xFF")),
    F(t_start,"<"),
    F(t_end,"<")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void t_xml_scope::t_start::i_value::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '"':F(t_string);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':F(t_number);
    default:{scope.ok=false;return;}
  }
  #undef F
}
/*
//list of types:
F(t_xml_scope)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fxml%5fscope%7b%0a%20%20t%5fname%7b%0a%20%20%20%20char%20A%3dany%5fchar%28gen
%5fdips%28%22azAZ%22%29%2b%22%5f%24%40%22%29%3b%0a%20%20%20%20string%20B%3dany%2
8gen%5fdips%28%22azAZ09%22%29%2b%22%5f%24%40%2d%2e%3a%22%29%3f%3b%0a%20%20%7d%0a
%20%20t%5fsep%7b%0a%20%20%20%20string%20body%3dany%28%22%20%5cr%5cn%22%29%3b%0a%
20%20%7d%0a%20%20t%5fcomment%3ai%5fnode%7b%0a%20%20%20%20%22%3c%21%2d%2d%22%0a%2
0%20%20%20string%20body%3dend%28%22%2d%2d%3e%22%29%3b%0a%20%20%7d%0a%20%20t%5fte
xt%3ai%5fnode%7b%0a%20%20%20%20t%5fraw%7b%0a%20%20%20%20%20%20string%20text%3dan
y%28dip%5finv%28%22%3c%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20text
%3dstr%3cvector%3cTAutoPtr%3ct%5fraw%3e%3e%3e%28%29%3b%0a%20%20%7d%0a%20%20t%5fs
tart%3ai%5fnode%7b%0a%20%20%20%20t%5fstring%3ai%5fvalue%7b%0a%20%20%20%20%20%20%
22%5c%22%22%0a%20%20%20%20%20%20string%20value%3dstr%3cvector%3cTAutoPtr%3ci%5fs
tr%5fitem%3e%3e%3e%28%29%3f%3b%0a%20%20%20%20%20%20%22%5c%22%22%0a%20%20%20%20%7
d%0a%20%20%20%20t%5fnumber%3ai%5fvalue%7b%0a%20%20%20%20%20%20string%20value%3da
ny%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fattr%7b%
0a%20%20%20%20%20%20string%20sep0%3dstr%3ct%5fsep%3e%28%29%3b%0a%20%20%20%20%20%
20string%20name%3dstr%3ct%5fname%3e%28%29%3b%0a%20%20%20%20%20%20string%20sep1%3
dstr%3ct%5fsep%3e%28%29%3f%3b%0a%20%20%20%20%20%20%22%3d%22%0a%20%20%20%20%20%20
string%20sep2%3dstr%3ct%5fsep%3e%28%29%3f%3b%0a%20%20%20%20%20%20TAutoPtr%3ci%5f
value%3e%20value%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fslash%7b%0a%20%20%20%20%
20%20%22%2f%22%0a%20%20%20%20%7d%0a%20%20%20%20%22%3c%22%0a%20%20%20%20string%20
sep0%3dstr%3ct%5fsep%3e%28%29%3f%3b%0a%20%20%20%20string%20tag%3dstr%3ct%5fname%
3e%28%29%3b%0a%20%20%20%20vector%3ct%5fattr%3e%20attrs%3f%3b%0a%20%20%20%20strin
g%20sep1%3dstr%3ct%5fsep%3e%28%29%3f%3b%0a%20%20%20%20string%20slash%3dstr%3cTAu
toPtr%3ct%5fslash%3e%3e%28%29%3f%3b%0a%20%20%20%20%22%3e%22%0a%20%20%7d%0a%20%20
t%5fend%3ai%5fnode%7b%0a%20%20%20%20%22%3c%2f%22%0a%20%20%20%20string%20tag%3dst
r%3ct%5fname%3e%28%29%3b%0a%20%20%20%20%22%3e%22%0a%20%20%7d%0a%20%20t%5fcontent
%7b%0a%20%20%20%20vector%3cTAutoPtr%3ci%5fnode%3e%3e%20arr%3b%0a%20%20%7d%0a%7d
*/