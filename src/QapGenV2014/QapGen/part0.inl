#ifdef DEF_BUILD_MACRO
  #include "../Macro/part0.h"
#else
//=====>>>>>part0

namespace detail{};

//`class IVisitorRTTI{
//`public:
//`  virtual void Do(TTypeStruct*p)=0;
//`  virtual void Do(TTypeSys*p)=0;
//`  virtual void Do(TTypeFactory*p){}
//`  virtual void Do(TTypeVector*p)=0;
//`  virtual void Do(TTypeArray*p)=0;
//`  virtual void Do(TTypeSelfPtr*p)=0;
//`  virtual void Do(TTypeAutoPtr*p)=0;
//`  virtual void Do(TTypeWeakPtr*p)=0;
//`  virtual void Do(TTypeHardPtr*p)=0;
//`  virtual void Do(TTypeVoidPtr*p)=0;
//`  virtual void Do(TTypeFieldPtr*p)=0;
//`};

//===>>===IVisitorRTTI
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
ADD(TTypeStruct)\
ADD(TTypeSys)\
ADD(TTypeFactory)\
ADD(TTypeVector)\
ADD(TTypeArray)\
ADD(TTypeSelfPtr)\
ADD(TTypeAutoPtr)\
ADD(TTypeWeakPtr)\
ADD(TTypeHardPtr)\
ADD(TTypeVoidPtr)\
ADD(TTypeFieldPtr)\
ADDEND()

class IEnvRTTI;
class TType;
class TTypeSys;

#define DEF_PRO_BLANK()
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
#undef DEF_PRO_BLANK

#define DEF_PRO_BLANK()
class IVisitorRTTI{
public:
  //#define ADD(TYPE)virtual void Do(TYPE*p)=0;
  //  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  //#undef ADD
  virtual void Do(TTypeStruct*p)=0;
  virtual void Do(TTypeSys*p)=0;
  virtual void Do(TTypeFactory*p){}
  virtual void Do(TTypeVector*p)=0;
  virtual void Do(TTypeArray*p)=0;
  virtual void Do(TTypeSelfPtr*p)=0;
  virtual void Do(TTypeAutoPtr*p)=0;
  virtual void Do(TTypeWeakPtr*p)=0;
  virtual void Do(TTypeHardPtr*p)=0;
  virtual void Do(TTypeVoidPtr*p)=0;
  virtual void Do(TTypeFieldPtr*p)=0;
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
  static TYPE*UberCast(TType*p){
    if(!p)return nullptr;Is<TYPE,IVisitorRTTI> IS;p->Use(IS);return IS.ptr;
  }
};
#undef DEF_PRO_BLANK

#undef LIST
//===<<===IVisitorRTTI

template<class SYS_TYPE>class Sys$$;

//<<<<<=====part0
#endif //DEF_BUILD_MICRO//