#ifdef DEF_BUILD_MACRO
  #include "../Macro/part3.h"
#else
//=====>>>>>part3

class IEsoteric{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IEsoteric)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IEsoteric
#include "QapGenStruct.inl"
//<<<<<+=====IEsoteric
public:
  static void SysHasSelf();
};

struct TRawPtr
{
  TType*pType;
  void*pValue;
  TRawPtr():pType(nullptr),pValue(nullptr){}
  TRawPtr(TType*pType,void*pValue):pType(pType),pValue(pValue){}
  template<class TYPE>
  TRawPtr(IEnvRTTI&Env,TYPE&Ref):pType(nullptr),pValue(nullptr)
  {
    set(Env,Ref);
  }
  template<class TYPE>
  TRawPtr(TAutoPtr<TYPE>&Ref)
  {
    set(Ref);
  }
  template<class TYPE>
  void set(IEnvRTTI&Env,TYPE&Ref)
  {
    pType=Sys$$<TYPE>::GetRTTI(Env);
    pValue=&Ref;
  }
  template<class TYPE>
  void set(TAutoPtr<TYPE>&Ref)
  {
    if(Ref){
      pType=Ref.Product.pType.get();
      pValue=Ref.get();
    }else{
      setZero();
    }
  }
  void set(TType*pType,void*pValue){this->pType=pType;this->pValue=pValue;}
  void setZero()
  {
    pType=nullptr;
    pValue=nullptr;
  }
  bool IsValid()
  {
    return pType&&pValue;
  }
};

class TVoidPtr{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TVoidPtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,type,SYS,nullptr,$)\
ADDVAR(TWeakPtr<IEsoteric>,ptr,SYS,nullptr,$)\
ADDEND()
//=====+>>>>>TVoidPtr
#include "QapGenStruct.inl"
//<<<<<+=====TVoidPtr
public:
  operator bool()const{return bool(ptr);}
public:
  void oper_set(SelfClass&&ref){
    off();
    type=std::move(ref.type);
    ptr=std::move(ref.ptr);
  }
  void operator=(SelfClass&&ref){oper_set(std::move(ref));}
public:
  //template<class TYPE>
  //TWeakPtr<TYPE>&get(TWeakPtr<IEsoteric>&Ref){return *(TWeakPtr<TYPE>*)(void*)&Ref;};
public:
  void off(){type=nullptr;ptr=nullptr;}
  void operator=(const nullptr_t&null){off();}
  void mega_unsafe_connect(TType*pType,void*pValue){
    off();
    if(!pType||!pValue)return;
    auto*ex=TTypeStruct::IsStruct::GetNearSelf(pType);
    if(!ex)
    {
      string fn=pType->GetFullName();
      QapDebugMsg("field \""+fn+"::Self\" not found");
      return;
    }
    TSelfPtr<IEsoteric>*self=(TSelfPtr<IEsoteric>*)ex->getValue(pValue);
    this->ptr.P=&self->P;
    this->type=pType;
  }
  void mega_unsafe_connect(const TRawPtr&ptr){
    mega_unsafe_connect(ptr.pType,ptr.pValue);
  }
  template<class TYPE>
  void operator=(TAutoPtr<TYPE>&Ref)
  {
    off();
    if(!Ref)return;
    auto*pType=Ref.Product.pType.get();
    auto*pValue=Ref.get();
    mega_unsafe_connect(pType,pValue);
  }
};

#include "SubFieldsInfo.inl"

class TFieldPtr{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TFieldPtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TVoidPtr,object,SYS,nullptr,$)\
ADDVAR(THardPtr<TType>,type,SYS,nullptr,$)\
ADDVAR(int,offset,SYS,-1,$)\
ADDEND()
//=====+>>>>>TFieldPtr
#include "QapGenStruct.inl"
//<<<<<+=====TFieldPtr
public:
  void off(){
    object=nullptr;
    type=nullptr;
    offset=-1;
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void ConnectToField(QAP_RTTI&RTTI,OBJECT_TYPE&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"bad");
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=&object;
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE,class FIELD_TYPE>
  void Connect(QAP_RTTI&RTTI,TAutoPtr<OBJECT_TYPE>&object,FIELD_TYPE&field)
  {
    static_assert(!std::is_pointer<FIELD_TYPE>::value,"bad");
    IEnvRTTI&Env=RTTI;
    off();
    if(!object)return;
    auto*objecttype=object.Product.pType.get();
    auto*fieldtype=Sys$$<FIELD_TYPE>::GetRTTI(Env);
    {
      string ot_fn=objecttype->GetFullName();
      string ft_fn=fieldtype->GetFullName();
    }
    int offset=0;
    {
      auto*ptr=object.get();
      offset=int(&field)-int(ptr);
    }
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object=object;
      this->type=fieldtype;
      this->offset=offset;
    }
  }
  template<class QAP_RTTI,class OBJECT_TYPE>
  void ConnectEx(QAP_RTTI&RTTI,OBJECT_TYPE&object)
  {
    static_assert(!std::is_pointer<OBJECT_TYPE>::value,"fail");
    IEnvRTTI&Env=RTTI;
    off();
    auto*objecttype=Sys$$<OBJECT_TYPE>::GetRTTI(Env);
    auto*fieldtype=objecttype;
    {
      string ot_fn=objecttype->GetFullName();
    }
    int offset=0;
    bool result=IsValid(objecttype,fieldtype,offset);
    QapAssert(result);
    if(result){
      this->object.mega_unsafe_connect(objecttype,&object);
      this->type=fieldtype;
      this->offset=offset;
    }
  }
public:
  operator bool(){return object;}
  void*getValue(){
    void*pValue=object.ptr.get();
    return TTypeStruct::AddOffset(pValue,offset);
  }
  TType*getType()
  {
    if(!object)return nullptr;
    if(!type)return nullptr;
    return type.get();
  }
public:
  struct TInfo
  {
    TTypeStruct*pType;
    void*pValue;
    TType*pFieldType;
    int Offset;
    void SetToField(TFieldPtr&Field){Field=*this;}
    operator bool()const{return pValue&&pType&&pFieldType&&(Offset>=0);}
    TInfo():pType(nullptr),pValue(nullptr),pFieldType(nullptr),Offset(-1){}
    void set(TTypeStruct*pType,void*pValue,TType*pFieldType,int Offset)
    {
      this->pType=pType;
      this->pValue=pValue;
      this->pFieldType=pFieldType;
      this->Offset=Offset;
    }
    void GrabFrom(TFieldPtr&FP)
    {
      this->pType=TTypeStruct::UberCast(FP.object.type.get());
      this->pValue=FP.object.ptr.get();
      this->pFieldType=FP.type.get();
      this->Offset=FP.offset;
    }
  };
public:
  void oper_set(SelfClass&&ref){
    off();
    object=std::move(ref.object);
    type=std::move(ref.type);
    offset=std::move(ref.offset);ref.offset=-1;
  }
  void operator=(SelfClass&&ref){oper_set(std::move(ref));}
  TFieldPtr(SelfClass&&ref){oper_set(std::move(ref));}
public:
  void operator=(const TInfo&ref)
  {
    off();
    if(!ref)return;
    bool result=IsValid(ref.pType,ref.pFieldType,ref.Offset);//SubFieldsInfo::IsValid(pType,pFieldType,Offset);
    //
    if(!result)QapDebugMsg("WTF?");
    // 
    object.mega_unsafe_connect(ref.pType,ref.pValue);
    type=ref.pFieldType;
    offset=ref.Offset;
  }
public:
  static bool IsValid(TType*pType,TType*pFieldType,int Offset)
  {
    SubFieldsInfo::TOffsetVerifier::TFieldInfo Info={pFieldType,Offset};
    return 0<=SubFieldsInfo::FieldInfoToIndex(pType,Info);
  }
};

//<<<<<=====part3
#endif //DEF_BUILD_MICRO//