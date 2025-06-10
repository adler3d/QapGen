----------------------------------------------------------------
#####-VISITOR-#####
----------------------------------------------------------------
public:
  //===>>===^^^I_BASE^^^_visitor
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
^^^ADDLIST^^^
  ADDEND()

  class ^^^I_BASE^^^;

  #define DEF_PRO_BLANK()
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  #undef DEF_PRO_BLANK

  #define DEF_PRO_BLANK()
  class ^^^I_BASE^^^_visitor{
  public:
    typedef ^^^OWNER^^^::^^^I_BASE^^^ ^^^I_BASE^^^;
  public:
    #define ADD(TYPE)virtual void Do(TYPE*p)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef ^^^OWNER^^^::U U;
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
    static TYPE*UberCast(^^^I_BASE^^^*p){
      if(!p)return nullptr;Is<TYPE,^^^I_BASE^^^_visitor> IS;p->Use(IS);return IS.ptr;
    }
  };
  #undef DEF_PRO_BLANK
  #undef LIST
public:
----------------------------------------------------------------
#####-NESTED_VISITOR-#####
----------------------------------------------------------------
public:
----------------------------------------------------------------
#####-VARS-#####
----------------------------------------------------------------
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
^^^PROVARS^^^ADDEND()
//=====+>>>>>^^^NAME^^^
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====^^^NAME^^^
----------------------------------------------------------------
#####-USE_IMPL-#####
----------------------------------------------------------------
public:
  void Use(i_visitor&A){A.Do(this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
----------------------------------------------------------------
#####-GO_IMPL-#####
----------------------------------------------------------------
public:
  bool go(i_dev&dev){
    t_fallback scope(dev,__FUNCTION__);
    auto&ok=scope.ok;
    auto&D=scope.mandatory;
    auto&M=scope.mandatory;
    auto&O=scope.optional;
^^^PROCMDS^^^    return ok;
  }
----------------------------------------------------------------
#####-USE_BASE-#####
----------------------------------------------------------------
public:
  typedef ^^^I_BASE^^^_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(this);*/}
----------------------------------------------------------------
#####-GO_BASE-#####
----------------------------------------------------------------
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load()
    {
^^^LIST^^^      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }
    #include "QapLexPolyEndNoTemplate.inl"
  };
----------------------------------------------------------------
#####-END_OF_FILE-#####
----------------------------------------------------------------
2014.02.12 11:58