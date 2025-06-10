//===>>===IDeclareVisitorRTTI
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
ADD(DeclareTypeSys)\
ADD(DeclareTypeSelfPtr)\
ADD(DeclareTypeAutoPtr)\
ADD(DeclareTypeWeakPtr)\
ADD(DeclareTypeHardPtr)\
ADD(DeclareTypeVoidPtr)\
ADD(DeclareTypeFieldPtr)\
ADD(DeclareTypeVector)\
ADD(DeclareTypeArray)\
ADD(DeclareTypeStruct)\
ADDEND()

class DeclareType;

#define DEF_PRO_BLANK()
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
#undef DEF_PRO_BLANK

#define DEF_PRO_BLANK()
class IDeclareVisitorRTTI{
public:
  //#define ADD(TYPE)virtual void Do(TYPE*p)=0;
  //  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  //#undef ADD
  virtual void Do(DeclareTypeSys*p)=0;
  virtual void Do(DeclareTypeSelfPtr*p)=0;
  virtual void Do(DeclareTypeAutoPtr*p)=0;
  virtual void Do(DeclareTypeWeakPtr*p)=0;
  virtual void Do(DeclareTypeHardPtr*p)=0;
  virtual void Do(DeclareTypeVoidPtr*p)=0;
  virtual void Do(DeclareTypeFieldPtr*p)=0;
  virtual void Do(DeclareTypeVector*p)=0;
  virtual void Do(DeclareTypeArray*p)=0;
  virtual void Do(DeclareTypeStruct*p)=0;
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
  static TYPE*UberCast(DeclareType*p){
    if(!p)return nullptr;Is<TYPE,IDeclareVisitorRTTI> IS;p->Use(IS);return IS.ptr;
  }
};
#undef DEF_PRO_BLANK

#undef LIST
//===<<===IDeclareVisitorRTTI