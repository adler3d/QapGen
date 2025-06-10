//time = 11.56 ms.

class t_simple_calc{
public:
  //===>>===i_term_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_number)\
  ADD(t_scope)\
  ADDEND()

  class i_term;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class i_term_visitor{
  public:
    typedef t_simple_calc::i_term i_term;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_calc::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr;
      Is():ptr(nullptr){}
    public:
      template<class U>static TYPE*get(U*p){return nullptr;}
      template<>static TYPE*get<TYPE>(TYPE*p){return p;}
    public:
      #define ADD(U)void Do(U*p){ptr=get(p);}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_term*p){
      if(!p)return nullptr;Is<TYPE,i_term_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
  class i_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_term
  #include "QapGenStruct.inl"
  //<<<<<+=====i_term
  public:
    typedef i_term_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      template<int>
      bool load()
      {
        F(t_number);
        F(t_scope);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }
      #include "QapLexPolyEnd.inl"
    };
  };
  class t_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_term>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_term
  #include "QapGenStruct.inl"
  //<<<<<+=====t_term
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  class t_number:public i_term{
  public:
    class t_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ext)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,v,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ext
    #include "QapGenStruct.inl"
    //<<<<<+=====t_ext
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        D+=dev.go_const(".");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
        D+=dev.go_any(v,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    class t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,bef,DEF,$,$)\
    ADDVAR(TAutoPtr<t_ext>,ext,DEF,$,$)\
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
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
        M+=dev.go_any(bef,g_static_var_0);
        if(!ok)return ok;
        O+=dev.go_auto(ext);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_ext )\
    F(t_impl)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_number
  #include "QapGenStruct.inl"
  //<<<<<+=====t_number
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
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
  };
  class t_divmul{
  public:
    class t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_divmul)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_term,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStruct.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("/,*",","));
        D+=dev.go_any_str_from_vec(oper,g_static_var_0);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_elem)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_divmul)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_term,first,DEF,$,$)\
  ADDVAR(vector<t_elem>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_divmul
  #include "QapGenStruct.inl"
  //<<<<<+=====t_divmul
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
  };
  class t_addsub{
  public:
    class t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_addsub)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_divmul,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStruct.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback scope(dev,__FUNCTION__);
        auto&ok=scope.ok;
        auto&D=scope.mandatory;
        auto&M=scope.mandatory;
        auto&O=scope.optional;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        D+=dev.go_any_str_from_vec(oper,g_static_var_0);
        if(!ok)return ok;
        D+=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_elem)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_addsub)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_divmul,first,DEF,$,$)\
  ADDVAR(vector<t_elem>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_addsub
  #include "QapGenStruct.inl"
  //<<<<<+=====t_addsub
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
  };
  class t_scope:public i_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)PARENT(i_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_addsub,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scope
  public:
    void Use(i_visitor&A){A.Do(this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback scope(dev,__FUNCTION__);
      auto&ok=scope.ok;
      auto&D=scope.mandatory;
      auto&M=scope.mandatory;
      auto&O=scope.optional;
      D+=dev.go_const("(");
      if(!ok)return ok;
      D+=dev.go_auto(value);
      if(!ok)return ok;
      D+=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_term  )\
  F(t_number)\
  F(t_divmul)\
  F(t_addsub)\
  F(t_scope )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_simple_calc)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_addsub,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_simple_calc
#include "QapGenStruct.inl"
//<<<<<+=====t_simple_calc
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(value);
    if(!ok)return ok;
    return ok;
  }
public:
};

/*
//list of types:
F(t_simple_calc)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5Fsimple%5Fcalc%7B%0D%0A%20%20t%5Fterm%7B%0D%0A%20%20%20%20TAutoPtr%3Ci%5Fterm
%3E%20value%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fauto%28value%29%
3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fnumber%3D%3Ei%5Fterm%7B%0D
%0A%20%20%20%20t%5Fext%7B%0D%0A%20%20%20%20%20%20string%20v%3B%0D%0A%20%20%20%20
%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fconst%28%22%2E%22%29%3B%0D%0A%20%20%
20%20%20%20%20%20go%5Fany%28v%2Cgen%5Fdips%28%2209%22%29%29%3B%0D%0A%20%20%20%20
%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fimpl%7B%0D%0A%20%20%20%20%20
%20string%20bef%3B%0D%0A%20%20%20%20%20%20TAutoPtr%3Ct%5Fext%3E%20ext%3B%0D%0A%2
0%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20M%2B%3Dgo%5Fany%28bef%2Cgen%5Fd
ips%28%2209%22%29%29%3B%0D%0A%20%20%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28ext%29%3
B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0D%0A%20%20%20%20string%20valu
e%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fstr%3Ct%5Fimpl%3E%28value%
29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Fdivmul%7B%0D%0A%20%20%2
0%20t%5Felem%7B%0D%0A%20%20%20%20%20%20string%20oper%3B%0D%0A%20%20%20%20%20%20t
%5Fterm%20expr%3B%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fa
ny%5Fstr%5Ffrom%5Fvec%28oper%2Csplit%28%22%2F%2C%2A%22%2C%22%2C%22%29%29%3B%0D%0
A%20%20%20%20%20%20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A
%20%20%20%20%7D%0D%0A%20%20%20%20t%5Fterm%20first%3B%0D%0A%20%20%20%20vector%3Ct
%5Felem%3E%20arr%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto
%28first%29%3B%0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%2
0%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Faddsub%7B%0D%0A%20%20%20%20t%5Felem%7B%0D%
0A%20%20%20%20%20%20string%20oper%3B%0D%0A%20%20%20%20%20%20t%5Fdivmul%20expr%3B
%0D%0A%20%20%20%20%20%20%7B%0D%0A%20%20%20%20%20%20%20%20go%5Fany%5Fstr%5Ffrom%5
Fvec%28oper%2Csplit%28%22%2B%2C%2D%22%2C%22%2C%22%29%29%3B%0D%0A%20%20%20%20%20%
20%20%20go%5Fauto%28expr%29%3B%0D%0A%20%20%20%20%20%20%7D%0D%0A%20%20%20%20%7D%0
D%0A%20%20%20%20t%5Fdivmul%20first%3B%0D%0A%20%20%20%20vector%3Ct%5Felem%3E%20ar
r%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20M%2B%3Dgo%5Fauto%28first%29%3B%
0D%0A%20%20%20%20%20%20O%2B%3Dgo%5Fauto%28arr%29%3B%0D%0A%20%20%20%20%7D%0D%0A%2
0%20%7D%0D%0A%20%20t%5Fscope%3D%3Ei%5Fterm%7B%0D%0A%20%20%20%20t%5Faddsub%20valu
e%3B%0D%0A%20%20%20%20%7B%0D%0A%20%20%20%20%20%20go%5Fconst%28%22%28%22%29%3B%0D
%0A%20%20%20%20%20%20go%5Fauto%28value%29%3B%0D%0A%20%20%20%20%20%20go%5Fconst%2
8%22%29%22%29%3B%0D%0A%20%20%20%20%7D%0D%0A%20%20%7D%0D%0A%20%20t%5Faddsub%20val
ue%3B%0D%0A%20%20%7B%0D%0A%20%20%20%20go%5Fauto%28value%29%3B%0D%0A%20%20%7D%0D%
0A%7D
*/