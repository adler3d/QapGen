----------------------------------------------------------------
#####-VISITOR-#####
----------------------------------------------------------------
//===>>===^^^I_BASE^^^_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
^^^ADDLIST^^^
ADDEND()

class ^^^I_BASE^^^;

#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class ^^^I_BASE^^^_visitor{
public:
  ^^^OWNER_TYPEDEF_I_BASE^^^
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)^^^OWNER_TYPEDEF_U^^^//typedef ^^^OWNER^^^::U U;
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
  static TYPE*UberCast(^^^I_BASE^^^*p){
    if(!p)return nullptr;Is<TYPE,^^^I_BASE^^^_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(^^^I_BASE^^^*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public ^^^I_BASE^^^_visitor{
^^^COMMENT_DO_LIST^^^
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===^^^I_BASE^^^_visitor
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
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
----------------------------------------------------------------
#####-GO_IMPL-#####
----------------------------------------------------------------
public:
  bool go(i_dev&^^^DEV^^^){
    t_fallback ^^^SCOPE^^^(^^^DEV^^^,__FUNCTION__);
    auto&ok=^^^SCOPE^^^.ok;
^^^PROCMDS^^^    return ok;
  }
----------------------------------------------------------------
#####-USE_BASE-#####
----------------------------------------------------------------
public:
  typedef ^^^I_BASE^^^_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
----------------------------------------------------------------
#####-GO_BASE-#####
----------------------------------------------------------------
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    bool load();/*
    {
^^^LIST^^^      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
----------------------------------------------------------------
#####-END_OF_FILE-#####
----------------------------------------------------------------
2025.06.27 19:16:18.158