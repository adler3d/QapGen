#ifdef DEF_BUILD_MACRO
  #include "../Macro/IEnvRTTI.h"
#else
//=====>>>>>IEnvRTTI

class IEnvRTTI;
class IFactory;
class IAllocator;
class TProduct;
class TRTTIProduct;

//Менеджер-костыль.
template<class TYPE>
class RTTIManager{
public:
  typedef std::pair<TWeakPtr<IEnvRTTI>,TWeakPtr<TType>> elem;
  vector<elem> Arr;
public:
  static RTTIManager<TYPE>*Get(){static RTTIManager<TYPE> global;return &global;}
public:
  elem*FindEnv(IEnvRTTI*Env)
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&EX=Arr[i];
      auto*ptr=EX.first.get();
      if(ptr==Env)return &EX;
    }
    return nullptr;
  }
  template<class U>
  bool GetPleaseInfo(IEnvRTTI*Env,U*(&val))
  {
    {U*u=nullptr;TType*t=nullptr;t=u;}
    elem*el=FindEnv(Env);
    val=(U*)(el?el->second.get():nullptr);
    return el;
  }
  template<class U>
  void SetPleaseInfo(IEnvRTTI*Env,U*val)
  {
    elem*el=FindEnv(Env);
    if(!el)
    {
      Arr.push_back(std::move(elem(Env,val)));
      if(Arr.size()>1)
      {
        QapDebugMsg("over 1 IEnvRTTI instance detected!");
      }
      return;
    }
    el->first=Env;
    el->second=val;
    return;
  }
};


template<class TYPE>
bool QapCanDestroy(TAutoPtr<TYPE>&Ref)
{
  return Ref&&Ref->Self.P.HardCount==1;
}

class EnvType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<TType>,Type,DEF,$,$)\
ADDVAR(TAutoPtr<IFactory>,Factory,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvType
#include "QapGenStruct.inl"
//<<<<<+=====EnvType
public:
  static void SysHasSelf();
public:
  #define MACRO_WEAK
  #include "macro_scope.inl"
  MACRO_WEAK_FUNC(bool,CheckFactory,(),())
  {
    if(Factory)
    {
      QapAssert(Type);
      return Type->Factory.get()==Factory.get();
    }
    if(!Factory)
    {
      QapAssert(Type&&Type->Factory);
      return true;
    }
    return false;
  }
  #include "macro_scope.inl"
public:
//  TType*GetType()
//  {
//    noway;
//    return Type.get();
//  }
//public:
//  #define MACRO_WEAK
//  #include "macro_scope.inl"
//  MACRO_WEAK_FUNC(IAllocator*,GetAlloc,(),()){return Env->GetAlloc();}
//  #include "macro_scope.inl"
//public:
//  IFactory*GetFactory()
//  {
//    noway;
//    return Factory.get();
//  }
//  EnvType*GetTypeProductEnvType()
//  {
//    noway;
//    return Type.getProductEnvType();
//  }
//  bool CanDestroy()
//  {
//    noway;
//    bool flag=Self.P.HardCount==1;
//    QapAssert(bool(Type)==bool(Factory));
//    if(QapCanDestroy(Type))return flag;
//    if(!Type&&!Factory)return flag;
//    return false;
//  }
};

//Окружение метатипов.
class IEnvRTTI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IEnvRTTI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====IEnvRTTI
public:
  static void SysHasSelf();
public:
  virtual IAllocator*GetAlloc(){QapDebugMsg("no way");return nullptr;}
  virtual int RegInfo(TAutoPtr<TType>&&_Right){QapDebugMsg("no way");return 0;}
  virtual EnvType&GetEnvTypeById(int id){QapDebugMsg("no way");return *(EnvType*)nullptr;}
  virtual vector<EnvType>&GetArr(){QapDebugMsg("no way");return *(vector<EnvType>*)nullptr;}
  virtual void OnRegBeg(TType*Info){QapDebugMsg("no way");}
  virtual void OnRegRet(TType*Info){QapDebugMsg("no way");}
  virtual void OnRegEnd(TType*Info){QapDebugMsg("no way");}
  virtual IEnvRTTI*GetOwnerEnv(){QapDebugMsg("no way");return nullptr;}
public:
  template<int>
  struct template_detail{
    static bool campare_type_full_name(TType*pType,const string&fn)
    {
      return pType->GetFullName()==fn;
    }
  };
  struct TTypeFullNameComparator{
    const string&fn;
    TTypeFullNameComparator(const string&fn):fn(fn){}
    bool operator()(EnvType&ex){
      return template_detail<0>::campare_type_full_name(ex.Type.get(),fn);
    }
  };
public:
  TType*FindTypeByName_is_ug_but_work(const string&fn)
  {
    auto&types=GetArr();
    auto&arr=qap_find(types,TTypeFullNameComparator(fn));
    QapAssert(arr.size()<=1);
    if(arr.empty())return nullptr;
    return types[arr[0]].Type.get();
  }
  TType*FindTypeByFactory(IFactory*pFactory)
  {
    return weak_FindTypeByFactory<void>(pFactory);
  }
  template<class TYPE>
  TType*weak_FindTypeByFactory(IFactory*pFactory)
  {
    if(!pFactory)return nullptr;
    auto&arr=GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if(pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
public:
  bool IsRootEnv()
  {
    return GetOwnerEnv()==this;
  }
  IEnvRTTI*GetRootEnv()
  {
    IEnvRTTI*pEnv=this;
    while(pEnv)
    {
      auto*p=pEnv->GetOwnerEnv();
      if(p==pEnv)return pEnv;
      pEnv=p;
    }
    QapDebugMsg("WTF?");
    return nullptr;
  }
public:
  template<class REG_TYPE,class INFO_TYPE>
  bool Register(INFO_TYPE*(&Info),const string&Name)
  {
    typedef RTTIManager<REG_TYPE> ManType;
    static_assert(std::is_base_of<TType,INFO_TYPE>::value,"bad");
    if(true)
    {
      auto*RootEnv=GetRootEnv();
      if(RootEnv!=this)
      {
        bool flag=RootEnv->Register<REG_TYPE>(Info,Name);
        TType*pType=Info;
        pType=FindTypeByFactory(pType->Factory.get());
        if(!flag)QapAssert(!pType);
        if(!pType)
        {
          QapDebugMsg("type '"+Sys$$<REG_TYPE>::GetFullName()+"' - not found");
        }
        Info=(INFO_TYPE*)pType;
        return true;
      }
    }
    ManType*Man=ManType::Get();
    Man->GetPleaseInfo(this,Info);
    if(Info){
      if(false)OnRegRet(Info);
      return true;
    }else{
      {
        TProduct prod;
        prod.Alloc=GetAlloc();
        prod.Factory=TFactory<INFO_TYPE>::Get();
        prod.Init();
        Info=(INFO_TYPE*)prod.Memory.ptr;
        Man->SetPleaseInfo(this,Info);
        Info->Info.Name=Name;
        Info->Info.Size=sizeof(REG_TYPE);
        Info->Info.Align=detail::QapAlignOf<REG_TYPE>::value;
        //`Начало регистрации.
        this->OnRegBeg(Info);
        //`
        {
          TAutoPtr<INFO_TYPE> tmp;//=UberInit<INFO_TYPE>(*this);
          tmp.Product.Memory=std::move(prod.Memory);
          int id=RegInfo(std::move(tmp));
          TType*pType=Sys$$<INFO_TYPE>::GetRTTI(*this);// this is fucking design error
          GetEnvTypeById(id).Type.Product.pType=pType;
        }
        __if_exists(INFO_TYPE::extInfo){
          Info->extInfo.SpecInfo=detail::GetSpecInfo<REG_TYPE>();
          Info->extInfo.Polymorph=std::is_polymorphic<REG_TYPE>::value;
          Info->extInfo.Abstract=std::is_abstract<REG_TYPE>::value;
        }
      }
      typedef detail::select<std::is_abstract<REG_TYPE>::value,void,REG_TYPE>::type select;
      Info->Factory=TFactory<select>::Get();
      Info->Env=this;
      //`
      //this->EndReg(Info);
      //`Конец регистрации.
      return false;
    }
  }
};

//<<<<<=====IEnvRTTI
#endif //DEF_BUILD_MICRO//