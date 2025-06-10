#ifdef DEF_BUILD_MACRO
  #include "../Macro/memory.h"
#else
//=====>>>>>memory

struct noused_t{noused_t(nullptr_t){}};
class EnvType;
class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;

/*TMemory - дискриптор выделеной памяти*/
class TMemory{
public:
  struct ptr_t{};
  ptr_t*ptr;
  int size;
  TMemory():ptr(nullptr),size(0){}
  //TMemory(ptr_t*ptr,int size):ptr(ptr),size(size){}
  //TMemory(int size,void*ptr):ptr(ptr),size(size){}
  operator bool()const
  {
    QapAssert(bool(ptr)==bool(size));
    return ptr;
  }
  void operator=(nullptr_t){ptr=nullptr;size=0;}
  void operator=(TMemory&&_Right){
    ptr=_Right.ptr;
    _Right.ptr=nullptr;
    size=_Right.size;
    _Right.size=0;
  }
};

/*IProduct - дискриптор продукта(динамически объект)*/
class IProduct{
public:
//#define DEF_PRO_MANUAL_RESET()
//#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IProduct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>IProduct
#include "QapGenStruct.inl"
//<<<<<+=====IProduct
public:
  virtual void safe_free()
  {
    if(bool(*this))Free();
  }
public:
  virtual const TMemory&GetMemory()const{QapDebugMsg("no way.");return *(TMemory*)nullptr;}
  virtual TMemory&GetMemory(){QapDebugMsg("no way.");return *(TMemory*)nullptr;}
  virtual IAllocator*GetAlloc(){QapDebugMsg("no way.");return nullptr;}
  virtual IFactory*GetFactory(){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetType(){QapDebugMsg("no way.");return nullptr;}
public:
  #define MACRO_WEAK
  #include "macro_scope.inl"
  MACRO_WEAK_PROC(Init,(),())
  {
    //flag_init=true;
    //flag_free=false;
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(!Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Init(pAlloc,Memory);
  }
  struct{};
  MACRO_WEAK_PROC(Free,(),())
  {
    //if(!flag_init&&flag_free)
    //{
    //  QapAssert(flag_init);
    //}
    //flag_free=true;
    TMemory&Memory=GetMemory();
    IAllocator*pAlloc=GetAlloc();
    IFactory*pFactory=GetFactory();
    QapAssert(Memory);
    QapAssert(pAlloc&&pFactory);
    pFactory->Free(pAlloc,Memory);
    QapAssert(!Memory);
  }
  #include "macro_scope.inl"
  operator bool()const{return bool(GetMemory());}
};

/*TProduct - дискриптор продукта(динамически объект)*/
class TProduct:public IProduct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TProduct)PARENT(IProduct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TMemory,Memory,DEF,$,$)\
ADDVAR(THardPtr<IAllocator>,Alloc,DEF,$,$)\
ADDVAR(THardPtr<IFactory>,Factory,DEF,$,$)\
ADDEND()
//=====+>>>>>TProduct
#include "QapGenStruct.inl"
//<<<<<+=====TProduct
public:
  const TMemory&GetMemory()const{return Memory;}
  TMemory&GetMemory(){return Memory;}
  IAllocator*GetAlloc(){return Alloc.get();}
  IFactory*GetFactory(){return Factory.get();}
  TType*GetType(){return nullptr;}
public:
  ~TProduct(){safe_free();}
};

/*TProduct - дискриптор продукта(динамически объект)*/
class TRTTIProduct:public IProduct{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TRTTIProduct)PARENT(IProduct)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TMemory,Memory,DEF,$,$)\
ADDVAR(THardPtr<TType>,pType,DEF,$,$)\
ADDEND()
//=====+>>>>>TRTTIProduct
#include "QapGenStruct.inl"
//<<<<<+=====TRTTIProduct
public:
  #define MACRO_WEAK
  #include "macro_scope.inl"
  const TMemory&GetMemory()const{return Memory;}
  TMemory&GetMemory(){return Memory;}
  MACRO_WEAK_FUNC(IAllocator*,GetAlloc,(),()){return pType->GetAlloc();}
  MACRO_WEAK_FUNC(IFactory*,GetFactory,(),()){return pType->Factory.get();}
  MACRO_WEAK_FUNC(TType*,GetType,(),()){return pType.get();}
  #include "macro_scope.inl"
public:
  ~TRTTIProduct(){safe_free();}
};

/*IFactory - завод объектов*/
class IFactory{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IFactory)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IFactory
#include "QapGenStruct.inl"
//<<<<<+=====IFactory
public:
  //IFactory(){}
  ~IFactory(){}
public:
  void operator=(const IFactory&)=delete;
public:
  //virtual constructor
  virtual void Init(IAllocator*pAlloc,TMemory&){QapDebugMsg("no way.");}
  //virtual destructor
  virtual void Free(IAllocator*pAlloc,TMemory&){QapDebugMsg("no way.");}
public:
  virtual string GetElementTypeFullName()const{QapDebugMsg("no way.");return "";}
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  virtual int GetSize(){QapDebugMsg("no way.");return 0;}
  virtual void UnsafeInit(const TMemory&){QapDebugMsg("no way.");}
  virtual void UnsafeFree(const TMemory&){QapDebugMsg("no way.");}
  virtual void UnsafeMove(const TMemory&Dest,const TMemory&Source){QapDebugMsg("no way.");}
public:
  virtual void unlink(){};
};

/*IAllocator - владелец пузыря памяти*/
class IAllocator{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IAllocator)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IAllocator
#include "QapGenStruct.inl"
//<<<<<+=====IAllocator
public:
  static void SysHasSelf();
public:
  //allocate storage
  virtual void Alloc(TMemory&){QapDebugMsg("no way.");};
  //deallocate storage
  virtual void Dealloc(TMemory&){QapDebugMsg("no way.");};
public:
  class TMemInfo;
  virtual TMemInfo&GetMemInfo(){QapDebugMsg("no way.");return *(TMemInfo*)nullptr;}
public:
  class TMemInfo{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMemInfo)OWNER(IAllocator)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(int,AllocCount,SET,0,$)\
  ADDVAR(int,DeallocCount,SET,0,$)\
  ADDVAR(int,MemoryUsed,SET,0,$)\
  ADDEND()
  //=====+>>>>>TMemInfo
  #include "QapGenStruct.inl"
  //<<<<<+=====TMemInfo
  public:
    ~TMemInfo()
    {
      QapAssert(AllocCount==DeallocCount);
      QapAssert(!MemoryUsed);
    }
  public:
    inline void OnAlloc(TMemory&Mem){
      AllocCount++;
      MemoryUsed+=Mem.size;
    }
    inline void OnDealloc(TMemory&Mem){
      DeallocCount++;
      MemoryUsed-=Mem.size;
    }
  };
};

template<typename PARAM,typename TYPE>
void UberReset(PARAM*Param,TYPE&Ref){
  detail::Reset<PARAM,TYPE,detail::is_dynamic<PARAM,TYPE>::value>::Do(Param,Ref);
}

//=====implementation=====//
bool TDynStructFactory_set_not_sys_field_from_string(TType*p,const string&source,void*pValue);

class TDynStructFactory:public IFactory{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDynStructFactory)PARENT(IFactory)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TTypeStruct>,pType,DEF,$,$)\
ADDEND()
//=====+>>>>>TDynStructFactory
#include "QapGenStruct.inl"
//<<<<<+=====TDynStructFactory
public:
  struct ptr_t{};
public:
  template<class TYPE>
  void Move(TYPE*pd,TYPE*ps)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)(void*)pd;
      dMem.size=subtype->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)(void*)ps;
      sMem.size=subtype->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory dMem;
      dMem.ptr=(TMemory::ptr_t*)ex.getValue(pd);
      dMem.size=ty->Info.Size;
      TMemory sMem;
      sMem.ptr=(TMemory::ptr_t*)ex.getValue(ps);
      sMem.size=ty->Info.Size;
      ft->UnsafeMove(dMem,sMem);
    }
  }
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeInit(Mem);
    }
    auto&arr=type->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeInit(Mem);
    }
    //DoReset();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Mode!="SET")continue;
      void*p=ex.getValue(ptr);
      string&value=ex.Value;
      auto*fieldtype=TTypeSys::UberCast(ex.Type.get());
      if(fieldtype)
      {
        auto*txtio=fieldtype->TxtIO.get();
        txtio->Load(value,p);
      }else{
        auto*pcommontype=ex.Type.get();
        bool ok=TDynStructFactory_set_not_sys_field_from_string(pcommontype,value,p);
        if(!ok)
        {
          string msg=(
            "the type use SET mode with no sys type:\n"+pcommontype->GetFullName()+"\n\n"
            "and TDynStructFactory_set_not_sys_field_from_string return false"
          );
          QapDebugMsg(msg);
        }
        int gg=1;
      }
      int gg=1;
    }
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    auto*type=pType.get();
    auto*subtype=type->GetSubType();
    auto&arr=type->Members;
    for(int i=int(arr.size())-1;i>=0;i--)
    {
      auto&ex=arr[i];
      auto*ft=ex.Type->Factory.get();
      auto*ty=ex.Type.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)ex.getValue(ptr);
      Mem.size=ty->Info.Size;
      ft->UnsafeFree(Mem);
    }
    if(subtype)
    {
      auto*ft=subtype->Factory.get();
      TMemory Mem;
      Mem.ptr=(TMemory::ptr_t*)(void*)ptr;
      Mem.size=subtype->Info.Size;
      ft->UnsafeFree(Mem);
    }
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  int weak_GetSize()
  {
    return pType->Info.Size;
  }
  int GetSize()
  {
    return weak_GetSize<void>();
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
  }
public:
  void unlink(){pType=nullptr;};
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if(!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env){
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env){
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr){return (ptr_t*)(void*)ptr;}
};

class TDynSelfPtrFactory:public IFactory{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TDynSelfPtrFactory)PARENT(IFactory)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TTypeSelfPtr>,pType,DEF,$,$)\
ADDEND()
//=====+>>>>>TDynSelfPtrFactory
#include "QapGenStruct.inl"
//<<<<<+=====TDynSelfPtrFactory
public:
  struct ptr_t{};
public:
  template<class TYPE>
  void Create(TYPE*ptr)
  {
    auto*type=pType.get();
    QapAssert(type);
    auto*elemtype=TTypeStruct::UberCast(type->ElementType.get());
    auto&self=*elemtype->GetNearSelf();
    QapAssert(&self);
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    new(pSelfPtr) TSelfPtr<IEsoteric>;
    pSelfPtr->P=nullptr;
    IEsoteric*p=(IEsoteric*)(void*)(int(pSelfPtr)-self.Offset);
    pSelfPtr->P=p;
  }
  template<class TYPE>
  void Destroy(TYPE*ptr)
  {
    TSelfPtr<IEsoteric>*pSelfPtr=(TSelfPtr<IEsoteric>*)(void*)ptr;
    pSelfPtr->~TSelfPtr<IEsoteric>();
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=GetSize();
    pAlloc->Alloc(Mem);
    Create<ptr_t>(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy<ptr_t>(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  template<class TYPE>
  TYPE weak_GetSize()
  {
    return sizeof(TSelfPtr<IEsoteric>);
  }
  int GetSize()
  {
    return weak_GetSize<int>();
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Create<ptr_t>(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==GetSize());
    Destroy<ptr_t>(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    //Move<ptr_t>(get(Dest.ptr),get(Source.ptr));
    QapDebugMsg("no way");
  }
public:
  void unlink(){pType=nullptr;};
public:
  template<class QAP_RTTI>
  TType*weak_GetElementType(QAP_RTTI&Env)
  {
    QapAssert(pType);
    auto*ptype=pType.get();
    if(!ptype)return nullptr;
    QapAssert(&Env==ptype->Env.get());
    return ptype;
  }
  TType*GetElementType(IEnvRTTI&Env){
    return weak_GetElementType(Env);
  }
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("[2014.08.23]: it used?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
public:
  static inline ptr_t*get(TMemory::ptr_t*ptr){return (ptr_t*)(void*)ptr;}
};

template<class TYPE>
class TFactory:public IFactory{
public:
  typedef typename TFactory<TYPE> SelfClass;
  typedef IFactory ParentClass;
  typedef TYPE type;
public:
  void operator=(const TFactory<TYPE>&Ref)=delete;
public:
  void operator=(TFactory<TYPE>&&Ref)
  {
    this->Self=std::move(Ref.Self);
  }
public:
  static TFactory<TYPE>*Get(){
    static TFactory<TYPE>tmp;
    static bool flag=true;
    if(flag){
      TFactory<void>::GetFactorys().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
public:
  static void Create(TYPE*ptr){new(ptr) TYPE;detail::FieldTryDoReset(*ptr);}
  static void Destroy(TYPE*ptr){ptr->~TYPE();}
  template<class T>
  static void Move(T&dest,T&source)
  {
    dest=std::move(source);
  }
public:
  void Init(IAllocator*pAlloc,TMemory&Mem){
    Mem.size=sizeof(TYPE);
    pAlloc->Alloc(Mem);
    Create(get(Mem.ptr));
  }
  void Free(IAllocator*pAlloc,TMemory&Mem){
    Destroy(get(Mem.ptr));
    pAlloc->Dealloc(Mem);
    Mem.size=0;
  }
public:
  int GetSize(){
    return sizeof(TYPE);
  }
  void UnsafeInit(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Create(get(Mem.ptr));
  }
  void UnsafeFree(const TMemory&Mem){
    QapAssert(Mem.ptr);
    QapAssert(Mem.size==sizeof(TYPE));
    Destroy(get(Mem.ptr));
  }
  void UnsafeMove(const TMemory&Dest,const TMemory&Source){
    QapAssert(Dest.ptr);
    QapAssert(Dest.size==GetSize());
    QapAssert(Source.ptr);
    QapAssert(Source.size==GetSize());
    auto*pd=get(Dest.ptr);
    auto*ps=get(Source.ptr);
    Move<type>(*pd,*ps);
  }
public:
  string GetElementTypeFullName()const{return std::move(Sys$$<type>::GetFullName());}
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<SelfClass>::GetRTTI(Env);};
private:
  static inline TYPE*get(TMemory::ptr_t*ptr){return (TYPE*)(void*)ptr;}
};

template<>
class TFactory<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IFactory>>&GetFactorys(){
    static vector<TWeakPtr<IFactory>> tmp; return tmp;
  }
};
/*
class TAllocator:public IAllocator{
public:
  TMemInfo Info;
  uchar Blob[1024*256];
  int cur;
  TAllocator():cur(0){}
public:
  void Alloc(TProduct&P)
  {
    P.Memory.ptr=(TMemory::ptr_t*)&Blob[cur];
    cur+=P.Memory.size;
    Info.OnAlloc(P);
  }
  void Dealloc(TProduct&P)
  {
    Info.OnDealloc(P);
    memset(P.Memory.ptr,0,P.Memory.size);
    P.Memory.ptr=nullptr;
    P.Memory.size=0;
  }
  TMemInfo&GetMemInfo(){return Info;}
};
*/
class TStdAllocator:public IAllocator{
public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TStdAllocator)PARENT(IAllocator)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TMemInfo,Info,DEF,$,$)\
  ADDEND()
  //=====+>>>>>IAllocator
  #include "QapGenStruct.inl"
  //<<<<<+=====IAllocator
public:
  void Alloc(TMemory&Mem)
  {
    Mem.ptr=(TMemory::ptr_t*)new uchar[Mem.size];
    Info.OnAlloc(Mem);
  }
  void Dealloc(TMemory&Mem)
  {
    Info.OnDealloc(Mem);
    memset(Mem.ptr,0,Mem.size);
    delete[] (uchar*)Mem.ptr;
    Mem.ptr=nullptr;
  }
  TMemInfo&GetMemInfo(){return Info;}
};

//<<<<<=====memory
#endif //DEF_BUILD_MICRO//