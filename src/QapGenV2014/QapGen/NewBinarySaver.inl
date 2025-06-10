#pragma once
class TMegaConvBase{
public:
  #pragma region DEF_PRO_LIST_DECLARE_AND_TTYPE
  //---
  #define DEF_PRO_LIST_DECLARE_AND_TTYPE(ADDBEG,ADDFOO,ADDEND)\
  ADDBEG()\
  ADDFOO(DeclareTypeSys,TTypeSys)\
  ADDFOO(DeclareTypeSelfPtr,TTypeSelfPtr)\
  ADDFOO(DeclareTypeAutoPtr,TTypeAutoPtr)\
  ADDFOO(DeclareTypeWeakPtr,TTypeWeakPtr)\
  ADDFOO(DeclareTypeHardPtr,TTypeHardPtr)\
  ADDFOO(DeclareTypeVoidPtr,TTypeVoidPtr)\
  ADDFOO(DeclareTypeFieldPtr,TTypeFieldPtr)\
  ADDFOO(DeclareTypeVector,TTypeVector)\
  ADDFOO(DeclareTypeArray,TTypeArray)\
  ADDFOO(DeclareTypeStruct,TTypeStruct)\
  ADDEND()
  //---
  template<class TYPE>
  struct TTypeToDeclare{};
  //---
  #define F()
  #define ADDFOO(DEST,SOURCE)template<>struct TTypeToDeclare<SOURCE>{typedef DEST type;};;
  DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
  #undef ADDFOO
  #undef F
  //---
  template<class TYPE>
  struct DeclareToTType{};
  //---
  #define F()
  #define ADDFOO(SOURCE,DEST)template<>struct DeclareToTType<SOURCE>{typedef DEST type;};;
  DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
  #undef ADDFOO
  #undef F
  //---
  template<class,class>
  struct InpTypeToOutType{};
  //---
  template<>
  struct InpTypeToOutType<DeclareType,TType>{
    template<class TYPE>
    struct Conv{typedef typename DeclareToTType<TYPE>::type type;};
  };
  template<>
  struct InpTypeToOutType<TType,DeclareType>{
    template<class TYPE>
    struct Conv{typedef typename TTypeToDeclare<TYPE>::type type;};
  };
  //---
  template<class FUNC>
  static void DeclareVisitAll(IEnvRTTI&Env,FUNC&func)
  {
    #define F()
    #define ADDFOO(DECLARE,TYPE)func(Sys$$<DECLARE>::GetRTTI(Env),Sys$$<TYPE>::GetRTTI(Env));
    DEF_PRO_LIST_DECLARE_AND_TTYPE(F,ADDFOO,F);
    #undef ADDFOO
    #undef F
  }
  //---
  #undef DEF_PRO_LIST_DECLARE_AND_TTYPE
  //---
  #pragma endregion
public:
};

class TMegaSolver:public TMegaConvBase{
public:
  template<class TYPE>
  static void DoPreConv(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
  {
    auto*pOutput=Ref.build<TTypeToDeclare<TYPE>::type>(Solver.Env);
    TType*pInp=p;
    DeclareType*pOut=pOutput;
    Solver.Solve(pInp->Self,pOut->Self,Ref.Product.pType.get());
  }
  template<class TYPE>
  static void CallDoConv(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
  {
    auto*pOut=(TTypeToDeclare<TYPE>::type*)Ref.get();
    Solver.DoConv(pOut,p);
  }
public:
  template<class TYPE>
  struct ProxyDoPreConv
  {
    static void call(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
    {
      DoPreConv(Solver,Ref,p);
    }
  };
  template<class TYPE>
  struct ProxyCallDoConv
  {
    static void call(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref,TYPE*p)
    {
      CallDoConv(Solver,Ref,p);
    }
  };
  template<template<class> class ConvertFunc>
  class TMegaConvertVisitor:public IVisitorRTTI{
  public:
    TMegaSolver&Solver;
    TAutoPtr<DeclareType>&Ref;
    TMegaConvertVisitor(TMegaSolver&Solver,TAutoPtr<DeclareType>&Ref):Solver(Solver),Ref(Ref){}
  public:
    template<class TYPE>
    void ProxyFunc(TYPE*p)
    {
      ConvertFunc<TYPE>::call(Solver,Ref,p);
    }
  public:
    void Do(TTypeStruct*p){ProxyFunc(p);}
    void Do(TTypeSys*p){ProxyFunc(p);}
    void Do(TTypeVector*p){ProxyFunc(p);}
    void Do(TTypeArray*p){ProxyFunc(p);}
    void Do(TTypeSelfPtr*p){ProxyFunc(p);}
    void Do(TTypeAutoPtr*p){ProxyFunc(p);}
    void Do(TTypeWeakPtr*p){ProxyFunc(p);}
    void Do(TTypeHardPtr*p){ProxyFunc(p);}
    void Do(TTypeVoidPtr*p){ProxyFunc(p);}
    void Do(TTypeFieldPtr*p){ProxyFunc(p);}
    void Do(TTypeFactory*p){QapDebugMsg("no way.");}
  };
public:
  typedef TServerPtrSpace TSpace;
  IEnvRTTI&Env;
  TSpace&Space;
  TMegaSolver(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space){}
public:
  void PreConv(TType*pInp,TAutoPtr<DeclareType>&ref)
  {
    //pInp->Use(Conv); создаёт нужный объект и вызывает нужный нам DoConv
    ref=nullptr;
    TMegaConvertVisitor<ProxyDoPreConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
  void UseConv(TType*pInp,TAutoPtr<DeclareType>&ref)
  {
    //pInp->Use(Conv); вызывает нужный нам DoConv
    TMegaConvertVisitor<ProxyCallDoConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
public:
  void DoConv(DeclareTypeSys*pOut,TTypeSys*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->GetFullName(),pOut->FullName);
  }
  void DoConv(DeclareTypeSelfPtr*pOut,TTypeSelfPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeAutoPtr*pOut,TTypeAutoPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeWeakPtr*pOut,TTypeWeakPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeHardPtr*pOut,TTypeHardPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeVoidPtr*pOut,TTypeVoidPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
  }
  void DoConv(DeclareTypeFieldPtr*pOut,TTypeFieldPtr*pInp)
  {
    Solve(pInp->Self,pOut->Self);
  }
  void DoConv(DeclareTypeVector*pOut,TTypeVector*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeArray*pOut,TTypeArray*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->Size,pOut->Size);
    Solve(pInp->ElementType.get(),pOut->ElementType);
  }
  void DoConv(DeclareTypeStruct*pOut,TTypeStruct*pInp)
  {
    Solve(pInp->Self,pOut->Self);
    Solve(pInp->Info.Name,pOut->Name);
    Solve(pInp->SubType.get(),pOut->SubType);
    Solve(pInp->OwnType.get(),pOut->OwnType);
    Solve(pInp->Members,pOut->Members);
  }
public:
  void Solve(const string&inp,string&out){out=inp;}
  void Solve(const int&inp,int&out){out=inp;}
  void Solve(TTypeStruct::Member*pInp,DeclareMember*pOut)
  {
    pOut->Name=pInp->Name;
    Solve(pInp->Type.get(),pOut->Type);
    pOut->Mode=pInp->Mode;
    pOut->Value=pInp->Value;
  }
  void Solve(vector<TTypeStruct::Member>&InpArr,vector<DeclareMember>&OutArr)
  {
    OutArr.resize(InpArr.size());
    for(int i=0;i<InpArr.size();i++)
    {
      auto&ex=InpArr[i];
      auto&ax=OutArr[i];
      Solve(&ex,&ax);
    }
  }        
  void Solve(TType*pInp,TWeakPtr<DeclareType>&out)
  {
    //pInp - оригинал
    //out - возможо пустышка.
    if(!pInp){
      out=nullptr;
      return;
    }
    int id=pInp->Self.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.get();
    QapAssert(ptr==pInp);
    QapAssert(item.ptr_lnk.IsValid());
    out=(DeclareType*)item.ptr_lnk.get();
  }
  void Solve(const TSelfPtr<TType>&inp,TSelfPtr<DeclareType>&out,TType*pOutType=nullptr)
  {
    int id=inp.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.ptr;
    auto*pInp=&inp;
    QapAssert(ptr==pInp);
    bool ptr_lnk_is_null=item.ptr_lnk.IsNull();
    if(!ptr_lnk_is_null)
    {
      bool f[]={
        item.ptr_lnk.ptr==(void*)&out,
        (!pOutType&&bool(item.ptr_lnk.type)),
        (item.ptr_lnk.type==pOutType),
        item.ptr_lnk.get()->Self.P.SaveID!=id
      };
      bool flag=f[0]&&(f[1]||f[2])&&f[3];
      if(flag)return;
      QapDebugMsg("WTF?");
      return;
    }
    QapAssert(ptr_lnk_is_null);
    QapAssert(!out.P.SaveID);
    item.ptr_lnk.ptr=EnvAdapter::get(out);
    item.ptr_lnk.type=pOutType;
  }
};

class TMegaSolverReverse:public TMegaConvBase{
public:
  typedef TMegaSolverReverse SelfClass;
  typedef DeclareType InpType;
  typedef TType OutType;
public:
  template<class TYPE>
  struct Conv{
    typedef typename InpTypeToOutType<InpType,OutType>::Conv<TYPE>::type type;
  };
public:
  template<class TYPE>
  static void DoPreConv(SelfClass&Solver,TAutoPtr<OutType>&Ref,TYPE*p)
  {
    auto*pInp=p;
    auto*pOut=Ref.build<Conv<TYPE>::type>(Solver.Env);
    Solver.Solve(pOut->Self,pInp->Self,Ref.Product.pType.get());
  }
  template<class TYPE>
  static void CallDoConv(SelfClass&Solver,TAutoPtr<OutType>&Ref,TYPE*p)
  {
    auto*pOut=(Conv<TYPE>::type*)Ref.get();
    Solver.DoConv(pOut,p);
  }
public:
  template<class TYPE>
  struct ProxyDoPreConv
  {
    static void call(SelfClass&Solver,TAutoPtr<OutType>&Ref,TYPE*p)
    {
      DoPreConv(Solver,Ref,p);
    }
  };
  template<class TYPE>
  struct ProxyCallDoConv
  {
    static void call(SelfClass&Solver,TAutoPtr<OutType>&Ref,TYPE*p)
    {
      CallDoConv(Solver,Ref,p);
    }
  };
  template<template<class> class ConvertFunc>
  class TMegaConvertVisitor:public IDeclareVisitorRTTI{
  public:
    SelfClass&Solver;
    TAutoPtr<OutType>&Ref;
    TMegaConvertVisitor(SelfClass&Solver,TAutoPtr<OutType>&Ref):Solver(Solver),Ref(Ref){}
  public:
    template<class TYPE>
    void ProxyFunc(TYPE*p)
    {
      ConvertFunc<TYPE>::call(Solver,Ref,p);
    }
  public:
    void Do(DeclareTypeStruct*p){ProxyFunc(p);}
    void Do(DeclareTypeSys*p){ProxyFunc(p);}
    void Do(DeclareTypeVector*p){ProxyFunc(p);}
    void Do(DeclareTypeArray*p){ProxyFunc(p);}
    void Do(DeclareTypeSelfPtr*p){ProxyFunc(p);}
    void Do(DeclareTypeAutoPtr*p){ProxyFunc(p);}
    void Do(DeclareTypeWeakPtr*p){ProxyFunc(p);}
    void Do(DeclareTypeHardPtr*p){ProxyFunc(p);}
    void Do(DeclareTypeVoidPtr*p){ProxyFunc(p);}
    void Do(DeclareTypeFieldPtr*p){ProxyFunc(p);}
    //void Do(DeclareTypeFactory*p){QapDebugMsg("no way.");}
  };
public:
  typedef TServerPtrSpace TSpace;
  IEnvRTTI&Env;
  TSpace&Space;
  TMegaSolverReverse(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space){}
public:
  void PreConv(InpType*pInp,TAutoPtr<OutType>&ref)
  {
    //pInp->Use(Conv); создаёт нужный объект и вызывает нужный нам DoConv
    ref=nullptr;
    TMegaConvertVisitor<ProxyDoPreConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
  void UseConv(InpType*pInp,TAutoPtr<OutType>&ref)
  {
    //pInp->Use(Conv); вызывает нужный нам DoConv
    TMegaConvertVisitor<ProxyCallDoConv> Conv(*this,ref);
    pInp->Use(Conv);
  }
public:
  void DoConv(TTypeSys*pOut,DeclareTypeSys*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->Info.Name,pInp->GetFullName());
    QapDebugMsg("deprecated conversion\nsource_type : "+pInp->GetFullName());
  }
  void DoConv(TTypeSelfPtr*pOut,DeclareTypeSelfPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeAutoPtr*pOut,DeclareTypeAutoPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeWeakPtr*pOut,DeclareTypeWeakPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeHardPtr*pOut,DeclareTypeHardPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeVoidPtr*pOut,DeclareTypeVoidPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
  }
  void DoConv(TTypeFieldPtr*pOut,DeclareTypeFieldPtr*pInp)
  {
    Solve(pOut->Self,pInp->Self);
  }
  void DoConv(TTypeVector*pOut,DeclareTypeVector*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeArray*pOut,DeclareTypeArray*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    Solve(pOut->Size,pInp->Size);
    Solve(pOut->ElementType,pInp->ElementType.get());
  }
  void DoConv(TTypeStruct*pOut,DeclareTypeStruct*pInp)
  {
    Solve(pOut->Self,pInp->Self);
    pOut->Info.Name=pInp->Name;
    pOut->Info.Align=-1;
    pOut->Info.Size=-1;
    Solve(pOut->SubType,pInp->SubType.get());
    Solve(pOut->OwnType,pInp->OwnType.get());
    Solve(pOut->Members,pInp->Members);
  }
public:
  void Solve(string&out,const string&inp){out=inp;}
  void Solve(int&out,const int&inp){out=inp;}
  void Solve(TTypeStruct::Member*pOut,DeclareMember*pInp)
  {
    pOut->Name=pInp->Name;
    Solve(pOut->Type,pInp->Type.get());
    pOut->Mode=pInp->Mode;
    pOut->Value=pInp->Value;
    pOut->Offset=-1;
  }
  void Solve(vector<TTypeStruct::Member>&OutArr,vector<DeclareMember>&InpArr)
  {
    OutArr.resize(InpArr.size());
    for(int i=0;i<InpArr.size();i++)
    {
      auto&ax=OutArr[i];
      auto&ex=InpArr[i];
      Solve(&ax,&ex);
    }
  }        
  void Solve(THardPtr<TType>&out,DeclareType*pInp)
  {
    QapDebugMsg("first pass");
    //pInp - оригинал
    //out - возможо пустышка.
    if(!pInp){
      out=nullptr;
      return;
    }
    int id=pInp->Self.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.get();
    QapAssert(ptr==pInp);
    QapAssert(item.ptr_lnk.IsValid());
    out=(TType*)item.ptr_lnk.get();
  }
  void Solve(TSelfPtr<TType>&out,const TSelfPtr<DeclareType>&inp,TType*pOutType=nullptr)// pOutType??? WTF?
  {  
    QapDebugMsg("first pass");
    int id=inp.P.SaveID;
    QapAssert(id);
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    void*ptr=item.ptr.ptr;
    auto*pInp=&inp;
    QapAssert(ptr==pInp);
    bool ptr_lnk_is_null=item.ptr_lnk.IsNull();
    if(!ptr_lnk_is_null)
    {
      bool f[]={
        item.ptr_lnk.ptr==(void*)&out,
        (!pOutType&&bool(item.ptr_lnk.type)),
        (item.ptr_lnk.type==pOutType),
        item.ptr_lnk.get()->Self.P.SaveID!=id
      };
      bool flag=f[0]&&(f[1]||f[2])&&f[3];
      if(flag)return;
      QapDebugMsg("WTF?");
      return;
    }
    QapAssert(ptr_lnk_is_null);
    QapAssert(!out.P.SaveID);
    item.ptr_lnk.ptr=EnvAdapter::get(out);
    item.ptr_lnk.type=pOutType;
  }
};

struct TSpaceDependsTools{
public:
  typedef TServerPtrSpace TSpace;
  typedef vector<std::pair<TType*,TType*>> TDeclareTypeArray;
  IEnvRTTI&Env;
  TSpace&Space;
  TMegaSolver Solver;
  DeclareEnvRTTI DeclEnv;
  //vector<TAutoPtr<DeclareType>> DeclArr;
  TDeclareTypeArray DeclareTypeArray;
  TType*pTType;
  TType*pTypeSys;
  TType*pDeclareType;
  DeclareType*pdTType;
  DeclareType*pdDeclareType;
  TSpaceDependsTools(IEnvRTTI&Env,TSpace&Space):Env(Env),Space(Space),Solver(Env,Space)
  {
    Prepare(Env);
  }
public:
  typedef TClientPtrSolver::TwoMetaType TwoMetaType;
public:
  TwoMetaType get_tmt()const
  {
    TwoMetaType tmt;
    tmt.pTType=pTType;
    tmt.pDeclareType=pDeclareType;
    return tmt;
  }
  TwoDeclareMetaType get_tdmt()
  {
    TwoDeclareMetaType tdmt;
    tdmt.pdTType=pdTType;
    tdmt.pdDeclareType=pdDeclareType;
    return tdmt;
  }
public:
  void PrepareDeclareTypeArray()
  {
    auto&arr=DeclareTypeArray;
    auto addfunc=[&arr](TType*pDeclareType,TType*pTType)
    {// problem("error C2872: <lambda0>:") => solution("MSVS2010 + VS10sp1-KB983509.exe")
      typedef std::pair<TType*,TType*> pair;
      pair tmp(pDeclareType,pTType);
      arr.push_back(std::move(tmp));
    };
    addfunc(pDeclareType,pTType);
    TMegaSolver::DeclareVisitAll(Env,addfunc);
  }
  void Prepare(IEnvRTTI&Env)
  {
    pTypeSys=Sys$$<TTypeSys>::GetRTTI(Env);
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    pdTType=nullptr;
    pdDeclareType=nullptr;
    PrepareDeclareTypeArray();
  }
  void PrepareEx()
  {
    auto Get=[this](TType*pType)->DeclareType*
    {
      QapAssert(pType);
      auto&item=Space[pType->Self];
      bool good=item.ptr_lnk.type->IsBasedOn(pDeclareType);
      QapAssert(good);
      auto*pOut=(DeclareType*)item.ptr_lnk.get();
      QapAssert(pOut);
      return pOut;
    };
    pdTType=Get(pTType);
    pdDeclareType=Get(pDeclareType);
  }
  void ExcludeInternal()
  {
    auto&arr=Space.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=ex.ptr.type;
      if(!pType)continue;
      bool f[]=
      {
        pType->IsBasedOn(pTypeSys),
        pType->IsBasedOn(pDeclareType)
      };
      if(!f[0]&&!f[1])continue;
      ex.passed=true;//помечаем пройденым, ибо системный тип.
    }
  }
  void GuardTheDeclare()
  {
    auto&Space=this->Space;
    auto&arr=DeclareTypeArray;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pDeclareType=ex.first;
      auto*pTType=ex.second;
      auto pass=[&Space](TType*pType,bool inc)->void
      {
        auto&item=Space[pType->Self];
        item.passed=true;
        auto*p=(DeclareType*)item.ptr_lnk.get();
        auto&ex=Space[p->Self];
        if(inc)ex.count++;
        ex.passed=true;
      };
      pass(pDeclareType,true);
      pass(pTType,true);
    }
  }
  void BuildProxy()
  {
    BuildProxyEx(Solver,Space,TwoMetaType(*this),DeclEnv);
  }
  static void BuildProxyEx(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    FirstPass(Solver,Space,tmt,DeclEnv);
    SecondPass(Solver,Space,tmt,DeclEnv);
    //AddToSpace();
  }
  typedef TSpaceDependsTools SelfClass;
  static void FirstPass(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    auto*pTType=tmt.pTType;
    auto&DeclArr=DeclEnv.Arr;
    TAutoPtr<DeclareType> DeclNull;
    auto&arr=Space.Arr;
    int cur_size=arr.size();
    QapAssert(DeclArr.empty());
    DeclArr.reserve(cur_size);
    for(int i=0;i<cur_size;i++)
    {
      auto&ex=arr[i];
      auto*pType=TTypeStruct::UberCast(ex.ptr.type);
      if(!pType)continue;
      if(!EnvAdapter::IsBasedOn(pType,pTType))continue;
      auto*pValue=(TType*)ex.ptr.get();
      DeclArr.push_back(std::move(DeclNull));
      auto&back=DeclArr.back();
      Solver.PreConv(pValue,back);
      {
        auto&item=Space.AddExt(EnvAdapter::get(back.get()->Self),back.Product.pType.get());
        item.name="Def$$<"+pValue->GetFullName()+">::GetRTTI()";
        item.ptr_lnk.ptr=EnvAdapter::get(pValue->Self);
        item.ptr_lnk.type=pType;
      }
    }
  }
  static void SecondPass(TMegaSolver&Solver,TSpace&Space,TwoMetaType&tmt,DeclareEnvRTTI&DeclEnv)
  {
    auto*pTType=tmt.pTType;
    auto&DeclArr=DeclEnv.Arr;
    int j=0;
    auto&arr=Space.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pType=TTypeStruct::UberCast(ex.ptr.type);
      if(!pType)continue;
      if(!EnvAdapter::IsBasedOn(pType,pTType))continue;
      auto*pValue=(TType*)ex.ptr.get();
      auto&ref=DeclArr[j++];
      Solver.UseConv(pValue,ref);
    }
  }/*
  void AddToSpace()
  {
    QapDebugMsg("no way.");
    auto&arr=DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&item=Space.AddExt(EnvAdapter::get(ex.get()->Self),ex.Product.pType.get());
      item.name="Def$$<"+ex->GetFullName()+">::GetRTTI()";
    }
  }*/
  void RemoveFromSpace(TSpace&Space)
  {
    QapDebugMsg("no way.");
    //auto&arr=DeclEnv.Arr;
    //for(int i=0;i<arr.size();i++)
    //{
    //  auto&ex=arr[i];
    //  auto&item=Space[ex->Self];
    //  Space.Del(item);
    //}
  }
  void MegaPass()
  {
    auto&arr=DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pValue=ex.get();
      auto&item=Space[pValue->Self];
      bool f[]=
      {
        pValue->IsBasedOn(pdTType),
        pValue->IsBasedOn(pdDeclareType),
      };
      item.system=f[0]||f[1];
    }
  }
};
class EnvDefEntryPoint{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefEntryPoint)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefEntryPoint
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefEntryPoint
public:
  static void SysHasSelf();
};

class EnvDefTypeSymbol{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypeSymbol)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(EnvDefEntryPoint,Decl,DEF,$,$)\
ADDVAR(string,Name,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypeSymbol
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypeSymbol
};

class EnvDefTypeStr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypeStr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(EnvDefTypeSymbol,Decl,DEF,$,$)\
ADDVAR(EnvDefEntryPoint,Impl,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypeStr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypeStr
};

class EnvDefTypePtr{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvDefTypePtr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,Decl,DEF,$,$)\
ADDVAR(EnvDefEntryPoint,Impl,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvDefTypePtr
#include "QapGenStruct.inl"
//<<<<<+=====EnvDefTypePtr
};

class FullDeclareEnvRTTI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FullDeclareEnvRTTI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(DeclareEnvRTTI,DeclEnv,DEF,$,$)\
ADDVAR(vector<EnvDefTypePtr>,ImplPtrs,DEF,$,$)\
ADDEND()
//=====+>>>>>FullDeclareEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====FullDeclareEnvRTTI
public:
  typedef vector<EnvDefTypePtr> TImplPtrs;
public:
  void MakeImplPtrs()
  {
    auto&arr=DeclEnv.Arr;
    ImplPtrs.resize(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto*pdType=arr[i].get();
      ImplPtrs[i].Decl=pdType;
      string fn=pdType->GetFullName();
    }
  }
  void AddDeclToSpace(TServerPtrSpace&Space,TServerPtrSpace&SpaceFFDE)
  {
    QapDebugMsg("imposible");
    //auto&arr=DefPtrs;
    //for(int i=0;i<arr.size();i++)
    //{
    //  auto&ex=arr[i];
    //  Space[ex.Decl->Self];
    //}
  }
  void AddImplToSpace(TServerPtrSpace&Space,TServerPtrSpace&SpaceFFDE)
  {
    auto&arr=ImplPtrs;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&item=SpaceFFDE.AddExt(EnvAdapter::get(ex.Impl.Self),nullptr,"Sys$$<"+ex.Decl->GetFullName()+">::GetRTTI()");
      auto&jtem=Space[Space[ex.Decl->Self].ptr_lnk.ptr->SaveID];
      QapAssert(item.name==jtem.name);
      item.ptr_lnk=jtem.ptr;
    }
  }
};