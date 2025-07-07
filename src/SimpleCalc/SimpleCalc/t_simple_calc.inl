// 680.655800 ms
struct t_simple_calc{
  //===>>===i_term_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_number)\
    ADD(t_scope)\
  ADDEND()
  class i_term;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_term_visitor{
  public:
    typedef t_simple_calc::i_term i_term;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_simple_calc::U U;//typedef t_simple_calc::U U;
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
    static TYPE*UberCast(i_term*p){
      if(!p)return nullptr;Is<TYPE,i_term_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_term*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_term_visitor{
  //  void Do(t_number&r){}
  //  void Do(t_scope&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_term_visitor
  struct i_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_term
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_term
  public:
    typedef i_term_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_term()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_number);
        F(t_scope);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //обьявляемы и реализуем вложенные в t_simple_calc лексеры
  struct t_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_term>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_term
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_term
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(value);
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_number:public i_term{
    struct t_ext{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ext)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,v,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_ext
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_ext
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        ok=dev.go_const(".");
        if(!ok)return ok;
        static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
        ok=dev.go_any(v,g_static_var_1);
        if(!ok)return ok;
        return ok;
      }
    };
    struct t_impl{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_number)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,bef,DEF,$,$)\
    ADDVAR(TAutoPtr<t_ext>,ext,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_impl
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_impl
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=CharMask::fromStr(gen_dips("09"));
        ok=dev.go_any(bef,g_static_var_0);
        if(!ok)return ok;
        dev.go_auto(ext);
        return ok;
      }
    };
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
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_number
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_str<t_impl>(value);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_divmul{
    struct t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_divmul)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_term,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("/,*",","));
        ok=dev.go_any_str_from_vec(oper,g_static_var_0);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
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
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_divmul
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_addsub{
    struct t_elem{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_addsub)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,oper,DEF,$,$)\
    ADDVAR(t_divmul,expr,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_elem
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_elem
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,__FUNCTION__);
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
        ok=dev.go_any_str_from_vec(oper,g_static_var_0);
        if(!ok)return ok;
        ok=dev.go_auto(expr);
        if(!ok)return ok;
        return ok;
      }
    };
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
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_addsub
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_auto(first);
      if(!ok)return ok;
      dev.go_auto(arr);
      return ok;
    }
  public:
  };
  struct t_scope:public i_term{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)PARENT(i_term)OWNER(t_simple_calc)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_addsub,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_scope
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,__FUNCTION__);
      auto&ok=$.ok;
      ok=dev.go_const("(");
      if(!ok)return ok;
      ok=dev.go_auto(value);
      if(!ok)return ok;
      ok=dev.go_const(")");
      if(!ok)return ok;
      return ok;
    }
  };
  // точка входа:
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
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_simple_calc
public:
  bool go(i_dev&dev){
    t_fallback $(dev,__FUNCTION__);
    auto&ok=$.ok;
    ok=dev.go_auto(value);
    if(!ok)return ok;
    return ok;
  }
public:
};
void t_simple_calc::i_term::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
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
    case '(':F(t_scope);
    default:{scope.ok=false;return;}
  }
  #undef F
}
/*
//list of types:
F(t_simple_calc)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fsimple%5fcalc%7b%0a%20%20%2f%2f%ee%e1%fc%ff%e2%eb%ff%e5%ec%fb%20%e8%20%f0%e5
%e0%eb%e8%e7%f3%e5%ec%20%e2%eb%ee%e6%e5%ed%ed%fb%e5%20%e2%20t%5fsimple%5fcalc%20
%eb%e5%ea%f1%e5%f0%fb%0a%20%20t%5fterm%7b%0a%20%20%20%20TAutoPtr%3ci%5fterm%3e%2
0value%3b%20%2f%2f%20%e2%fb%e7%fb%e2%e0%e5%ec%20%ef%e0%f0%f1%e8%ed%e3%20%ef%ee%e
b%e8%ec%ee%f0%f4%ed%ee%e9%20%ed%ee%e4%fb%2f%eb%e5%ea%f1%e5%f0%e0%2e%0a%20%20%7d%
0a%20%20t%5fnumber%3ai%5fterm%7b%0a%20%20%20%20t%5fext%7b%0a%20%20%20%20%20%20%2
2%2e%22%20%2f%2f%20%e6%f0%b8%ec%20%f2%ee%f7%e5%f7%ea%f3%2e%0a%20%20%20%20%20%20s
tring%20v%3dany%28gen%5fdips%28%2209%22%29%29%3b%20%2f%2f%20%e6%f0%b8%ec%20%e2%f
1%b8%20%ee%f2%200%20%e4%ee%209%20%ef%ee%ea%e0%20%ee%ed%ee%20%e5%f1%f2%fc%2e%0a%2
0%20%20%20%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%20%20%20string%20bef%3dany%2
8gen%5fdips%28%2209%22%29%29%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fext%3e%20ext%
3f%3b%20%2f%2f%20%ef%e0%f0%f1%e8%ec%20%ee%ef%f6%e8%ee%ed%e0%eb%fc%ed%fb%e9%20t%5
fext%0a%20%20%20%20%7d%0a%20%20%20%20string%20value%3dstr%3ct%5fimpl%3e%28%29%3b
%20%2f%2f%20%ef%e0%f0%f1%e8%ec%20t%5fimpl%20%e8%20%f1%ee%f5%f0%e0%ed%ff%e5%ec%20
%e5%e3%ee%20%e2%20%f1%f2%f0%ee%ea%f3%2e%0a%20%20%7d%0a%20%20t%5fdivmul%7b%0a%20%
20%20%20t%5felem%7b%0a%20%20%20%20%20%20string%20oper%3dany%5fstr%5ffrom%5fvec%2
8split%28%22%2f%2c%2a%22%2c%22%2c%22%29%29%3b%20%2f%2f%20%f1%e6%e8%f0%e0%e5%ec%2
0%2f%20%e8%eb%e8%20%2a%0a%20%20%20%20%20%20t%5fterm%20expr%3b%20%2f%2f%20%e7%e0%
ef%f3%f1%ea%e0%e5%ec%20%ef%ee%eb%e8%ec%ee%f0%f4%e0%20%ea%ee%f2%ee%f0%fb%e9%20%e5
%f1%f2%fc%20%f1%ea%ee%e1%ea%e8%20%e8%20%f7%e8%f1%eb%e0%0a%20%20%20%20%7d%0a%20%2
0%20%20t%5fterm%20first%3b%0a%20%20%20%20vector%3ct%5felem%3e%20arr%3f%3b%20%2f%
2f%20%e7%e0%ef%f3%f1%ea%e0%e5%ec%20%ee%ef%f6%e8%ee%ed%e0%eb%fc%ed%fb%e9%20%ef%e0
%f0%f1%e8%ed%e3%20%ec%e0%f1%f1%e8%e2%e0%20t%5felem%0a%20%20%7d%0a%20%20t%5faddsu
b%7b%0a%20%20%20%20t%5felem%7b%0a%20%20%20%20%20%20string%20oper%3dany%5fstr%5ff
rom%5fvec%28split%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%20%2f%2f%20%f1%e6%e8%f0
%e0%e5%ec%20%2b%20%e8%eb%e8%20%2d%0a%20%20%20%20%20%20t%5fdivmul%20expr%3b%0a%20
%20%20%20%7d%0a%20%20%20%20t%5fdivmul%20first%3b%20%2f%2f%20%ef%e0%f0%f1%e8%ec%2
0t%5fdivmul%2c%20%f2%2e%ea%20%f3%20%ed%e5%e3%ee%20%e2%fb%f8%e5%20%ef%f0%e8%ee%f0
%e5%f2%e5%f2%0a%20%20%20%20vector%3ct%5felem%3e%20arr%3f%3b%20%2f%2f%20%f2%e5%ef
%e5%f0%fc%20%ee%ef%f6%e8%ee%ed%e0%eb%fc%ed%ee%20%e2%f1%e5%20%ee%f1%f2%e0%eb%fc%e
d%fb%e5%0a%20%20%7d%0a%20%20t%5fscope%3ai%5fterm%7b%0a%20%20%20%20%22%28%22%20%2
f%2f%20%e5%e4%e8%ec%20%f1%ea%ee%e1%ea%f3%0a%20%20%20%20t%5faddsub%20value%3b%20%
2f%2f%20%ed%e0%f7%e8%ed%e0%e5%ec%20%f1%20%2b%20%e8%eb%e8%20%2d%2c%f2%2e%ea%20%f3
%20%ed%e8%f5%20%ed%e8%e7%ea%e8%e9%20%ef%f0%e8%ee%f0%f2%e5%f2%0a%20%20%20%20%22%2
9%22%20%2f%2f%20%e5%f9%b8%20%f1%ea%ee%e1%ee%f7%ea%f3%0a%20%20%7d%0a%20%20%2f%2f%
20%f2%ee%f7%ea%e0%20%e2%f5%ee%e4%e0%3a%0a%20%20t%5faddsub%20value%3b%20%2f%2f%20
%ef%e0%f0%f1%e8%ec%20t%5faddsub%0a%7d
*/