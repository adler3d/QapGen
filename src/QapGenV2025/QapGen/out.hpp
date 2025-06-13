// 72.974500 ms
class t_test20250613{
public:
  //===>>===i_yyy_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_fozy)\
  ADD(t_bazz)\
  ADDEND()

  class i_yyy;

  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_yyy_visitor{
  public:
    typedef t_test20250613::i_yyy i_yyy;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_test20250613::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBER_CAST
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
    static TYPE*UberCast(i_yyy*p){
      if(!p)return nullptr;Is<TYPE,i_yyy_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_yyy*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_yyy_visitor
public:
  class i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_yyy
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_yyy
  public:
    typedef i_yyy_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_fozy);
        F(t_bazz);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
public:
  //===>>===i_xxx_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
  ADD(t_fooa)\
  ADD(t_barb)\
  ADD(t_baz)\
  ADDEND()

  class i_xxx;

  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_xxx_visitor{
  public:
    typedef t_test20250613::i_xxx i_xxx;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_test20250613::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBER_CAST
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
    static TYPE*UberCast(i_xxx*p){
      if(!p)return nullptr;Is<TYPE,i_xxx_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_xxx*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_xxx_visitor
public:
  class i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_xxx
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_xxx
  public:
    typedef i_xxx_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      bool load();/*
      {
        F(t_fooa);
        F(t_barb);
        F(t_baz);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  class t_fozy:public i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fozy)PARENT(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_fozy
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fozy
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
      D+=dev.go_const("Y");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_bazz:public i_yyy{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bazz)PARENT(i_yyy)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_bazz
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_bazz
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
      D+=dev.go_const("Z");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_fooa:public i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fooa)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_fooa
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fooa
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
      D+=dev.go_const("A");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_barb:public i_xxx{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_barb)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_barb
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_barb
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
      D+=dev.go_const("B");
      if(!ok)return ok;
      return ok;
    }
  };
  class t_baz:public i_xxx{
  public:
    //===>>===i_xxx1_visitor
    #define DEF_PRO_BLANK()
    #define LIST(ADDBEG,ADD,ADDEND)\
    ADDBEG()\
    ADD(t_foo1)\
    ADD(t_bar1)\
    ADD(t_baz1)\
    ADDEND()
  
    class i_xxx1;
  
    #define ADD(TYPE)class TYPE;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    class i_xxx1_visitor{
    public:
      typedef t_baz::i_xxx1 i_xxx1;
    public:
      #define ADD(TYPE)virtual void Do(TYPE*p)=0;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #define ADD(U)typedef t_baz::U U;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    public:
      #ifdef QAP_FAST_UBER_CAST
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
      static TYPE*UberCast(i_xxx1*p){
        if(!p)return nullptr;Is<TYPE,i_xxx1_visitor> IS;p->Use(IS);return IS.ptr;
      }
      #else
      template<class TYPE>
      static TYPE*UberCast(i_xxx1*p){return dynamic_cast<TYPE*>(p);}
      #endif
    };
    #undef LIST
    #undef DEF_PRO_BLANK
    //===<<===i_xxx1_visitor
  public:
    class i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>i_xxx1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====i_xxx1
    public:
      typedef i_xxx1_visitor i_visitor;
      virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
    public:
      virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
      struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
      {
        #include "QapLexPolyBeg.inl"
        bool load();/*
        {
          F(t_foo1);
          F(t_bar1);
          F(t_baz1);
          (void)count;(void)first_id;(void)out_arr;(void)this;
          main();
          return scope.ok;
        }*/
        #include "QapLexPolyEndNoTemplate.inl"
      };
    };
    class t_foo1:public i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_foo1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_foo1
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
        D+=dev.go_const("foo");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_bar1:public i_xxx1{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_bar1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_bar1
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
        D+=dev.go_const("bar");
        if(!ok)return ok;
        return ok;
      }
    };
    class t_baz1:public i_xxx1{
    public:
      //===>>===i_xxx2_visitor
      #define DEF_PRO_BLANK()
      #define LIST(ADDBEG,ADD,ADDEND)\
      ADDBEG()\
      ADD(t_foo2)\
      ADD(t_bar2)\
      ADDEND()
    
      class i_xxx2;
    
      #define ADD(TYPE)class TYPE;
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      class i_xxx2_visitor{
      public:
        typedef t_baz1::i_xxx2 i_xxx2;
      public:
        #define ADD(TYPE)virtual void Do(TYPE*p)=0;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #define ADD(U)typedef t_baz1::U U;
        LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
        #undef ADD
      public:
        #ifdef QAP_FAST_UBER_CAST
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
        static TYPE*UberCast(i_xxx2*p){
          if(!p)return nullptr;Is<TYPE,i_xxx2_visitor> IS;p->Use(IS);return IS.ptr;
        }
        #else
        template<class TYPE>
        static TYPE*UberCast(i_xxx2*p){return dynamic_cast<TYPE*>(p);}
        #endif
      };
      #undef LIST
      #undef DEF_PRO_BLANK
      //===<<===i_xxx2_visitor
    public:
      class i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>i_xxx2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====i_xxx2
      public:
        typedef i_xxx2_visitor i_visitor;
        virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
      public:
        virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
        struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
        {
          #include "QapLexPolyBeg.inl"
          bool load();/*
          {
            F(t_foo2);
            F(t_bar2);
            (void)count;(void)first_id;(void)out_arr;(void)this;
            main();
            return scope.ok;
          }*/
          #include "QapLexPolyEndNoTemplate.inl"
        };
      };
      class t_foo2:public i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_foo2)PARENT(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_foo2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_foo2
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
          D+=dev.go_const("foo2");
          if(!ok)return ok;
          return ok;
        }
      };
      class t_bar2:public i_xxx2{
      #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bar2)PARENT(i_xxx2)OWNER(t_baz1)
      #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
      ADDBEG()\
      ADDEND()
      //=====+>>>>>t_bar2
      #include "QapGenStructNoTemplate.inl"
      //<<<<<+=====t_bar2
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
          D+=dev.go_const("bar2");
          if(!ok)return ok;
          return ok;
        }
      };
    public:
    #define DEF_PRO_NESTED(F)\
      /*<DEF_PRO_NESTED>*/\
      F(t_foo2)\
      F(t_bar2)\
      /*</DEF_PRO_NESTED>*/
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz1)PARENT(i_xxx1)OWNER(t_baz)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDEND()
    //=====+>>>>>t_baz1
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_baz1
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
        D+=dev.go_const("baz");
        if(!ok)return ok;
        return ok;
      }
    };
  public:
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_foo1)\
    F(t_bar1)\
    F(t_baz1)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_baz)PARENT(i_xxx)OWNER(t_test20250613)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_xxx1>,x,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_baz
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_baz
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
      D+=dev.go_auto(x);
      if(!ok)return ok;
      return ok;
    }
  public:
  };
public:
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_fozy)\
  F(t_bazz)\
  F(t_fooa)\
  F(t_barb)\
  F(t_baz )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_test20250613)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_xxx>,x,DEF,$,$)\
ADDVAR(TAutoPtr<i_yyy>,y,DEF,$,$)\
ADDEND()
//=====+>>>>>t_test20250613
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_test20250613
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
    D+=dev.go_auto(x);
    if(!ok)return ok;
    return ok;
  }
public:
};
bool t_test20250613::i_yyy::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_fozy);
  F(t_bazz);
  #undef F
}

bool t_test20250613::i_xxx::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_fooa);
  F(t_barb);
  F(t_baz);
  #undef F
}

bool t_test20250613::t_baz::i_xxx1::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_foo1);
  F(t_bar1);
  F(t_baz1);
  #undef F
}

bool t_test20250613::t_baz::t_baz1::i_xxx2::t_poly_impl::load()
{
  #define F(TYPE)go_for<struct TYPE>();
  F(t_foo2);
  F(t_bar2);
  #undef F
}

/*
//list of types:
F(t_test20250613)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5ftest20250613%7b%0a%20%20t%5ffozy%3d%3ei%5fyyy%7b%7bgo%5fconst%28%22Y%22%29%3
b%7d%7d%0a%20%20t%5fbazz%3d%3ei%5fyyy%7b%7bgo%5fconst%28%22Z%22%29%3b%7d%7d%0a%2
0%20t%5ffooa%3d%3ei%5fxxx%7b%7bgo%5fconst%28%22A%22%29%3b%7d%7d%0a%20%20t%5fbarb
%3d%3ei%5fxxx%7b%7bgo%5fconst%28%22B%22%29%3b%7d%7d%0a%20%20t%5fbaz%3d%3ei%5fxxx
%7b%0a%20%20%20%20t%5ffoo1%3d%3ei%5fxxx1%7b%7bgo%5fconst%28%22foo%22%29%3b%7d%7d
%0a%20%20%20%20t%5fbar1%3d%3ei%5fxxx1%7b%7bgo%5fconst%28%22bar%22%29%3b%7d%7d%0a
%20%20%20%20t%5fbaz1%3d%3ei%5fxxx1%7b%0a%20%20%20%20%20%20t%5ffoo2%3d%3ei%5fxxx2
%7b%7bgo%5fconst%28%22foo2%22%29%3b%7d%7d%0a%20%20%20%20%20%20t%5fbar2%3d%3ei%5f
xxx2%7b%7bgo%5fconst%28%22bar2%22%29%3b%7d%7d%0a%20%20%20%20%20%20%7bgo%5fconst%
28%22baz%22%29%3b%7d%0a%20%20%20%20%7d%0a%20%20%20%20TAutoPtr%3ci%5fxxx1%3e%20x%
3b%0a%20%20%20%20%7b%0a%20%20%20%20%20%20go%5fauto%28x%29%3b%0a%20%20%20%20%7d%0
a%20%20%7d%0a%20%20TAutoPtr%3ci%5fxxx%3e%20x%3b%0a%20%20TAutoPtr%3ci%5fyyy%3e%20
y%3b%0a%20%20%7b%0a%20%20%20%20go%5fauto%28x%29%3b%0a%20%20%7d%0a%7d
*/