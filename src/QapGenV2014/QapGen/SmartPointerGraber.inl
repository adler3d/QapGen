//#include "SmartPointerGraber.inl"

class TSmartPtrVisitor:public IVisitorRTTI{
public:
  class ICallBack{
  public:
    virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType)=0;
    virtual void Visit(TClientPtr<IEsoteric>&A)=0;
    virtual void Visit(THardClientPtr<IEsoteric>&A)=0;
  };
public:
  ICallBack&CB;
  void*pValue;
  typedef TSmartPtrVisitor SelfClass;
  TSmartPtrVisitor(ICallBack&CB,void*pValue):CB(CB),pValue(pValue){}
  TSmartPtrVisitor(TSmartPtrVisitor&owner,void*pValue):CB(owner.CB),pValue(pValue){}
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    auto&arr=p->Members;
    //static bool debug=true;
    //if(debug)
    //{
    //  string fn=p->GetFullName();
    //  if(fn=="TTypeSys")
    //  {
    //    auto*pMetaType=(TTypeSys*)pValue;
    //    string mt_fn=pMetaType->GetFullName();
    //    if(mt_fn=="string")
    //    {
    //      int gg=1;
    //    }
    //  }
    //}
    static bool debug_flag=false;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      if(debug_flag)
      {
        string fn=p->GetFullName();
        if(fn=="TType")if(ex.Name=="Factory")do
        {
          TType*pval=(TType*)(void*)pValue;
          string val_fn=pval->GetFullName();
          THardPtr<TType>&value=*(THardPtr<TType>*)(void*)next.pValue;
          auto*ptr=value.P.ptr;
          if(!ptr)break;
          int sid=ptr->SaveID;
          sid=sid+1-1;
        }while(false);
      }

      ex.Type->Use(next);
      
      if(debug_flag)
      {
        string fn=ex.Type->GetFullName();
        int ksjdlasd=0;
      }
    }
  }
  void Do(TTypeSys*p)
  {
    //`p->BinIO->Save(io,pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  virtual void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      SelfClass next(*this,&type);
      p->mType.Type->Use(next);
    }
    auto*ptr=value.get();
    if(ptr&&type)
    {
      SelfClass next(*this,ptr);
      type->Use(next);
    }
  }
  virtual void Do(TTypeWeakPtr*p)
  {
    TWeakPtr<IEsoteric>&value=*(TWeakPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeHardPtr*p)
  {
    THardPtr<IEsoteric>&value=*(THardPtr<IEsoteric>*)pValue;
    CB.Visit(value.P,p->ElementType.get());
  }
  virtual void Do(TTypeVoidPtr*p)
  {
    TVoidPtr&value=*(TVoidPtr*)pValue;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    CB.Visit(value.ptr.P);
  }
  virtual void Do(TTypeFieldPtr*p)
  {
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    TType*pmIndexType=p->mIndex.Type.get();
    {
      SelfClass next(*this,&value.offset);
      pmIndexType->Use(next);
    }
  }
  virtual void Do(TTypeFactory*p)
  {
    IFactory&value=*(IFactory*)pValue;
    TSelfPtr<IEsoteric>&Self=*(TSelfPtr<IEsoteric>*)(void*)&value.Self;
    TType*SmartType=p->SmartType.get();
    CB.Visit(Self.P,SmartType);
  }
public:
};

/*
  Увеличивает значение count в ячейке ассоциированной с серверным указателем
  на который ссылается клиенский указатель.
*/
class TClientPtrCounter:public TSmartPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    QapDebugMsg("deprecated");
    QapDebugMsg("see TClientPtrUserCallBackCounter");
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr,class TYPE>
  inline static SmartPtr<IEsoteric>&get(SmartPtr<TYPE>&input)
  {
    static_assert(
      std::is_same<SmartPtr,TClientPtr>::value||
      std::is_same<SmartPtr,THardClientPtr>::value,"error"
    );
    return (SmartPtr<IEsoteric>&)input;
  }
  void DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)
    {
      QapDebugMsg("bad news");
      return;
    }
    auto&item=Space[id];
    if(item.passed)return;
    if(item.count)return;
    if(true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType);
      if(trigger)//если item.ptr описатель обычный.
      {
        //ищем заместитель.
        auto*pValue=(TType*)item.ptr.get();
        auto&ex=Space[pValue->Self];
        QapAssert(ex.ptr_lnk.IsValid());
        bool good=ex.ptr_lnk.type->IsBasedOn(pDeclareType);
        QapAssert(good);
        //переходим к соответствующему наследнику DeclareType'а.
        bool f[]=
        { 
          pValue->IsBasedOn(pTType),
          pValue->IsBasedOn(pDeclareType)
        };
        auto*pdValue=(DeclareType*)ex.ptr_lnk.get();
        auto&d=Space[pdValue->Self];
        d.count++;
        d.passed=f[0]||f[1];
        item.passed=true;//пройден.
        return;
      }
      QapAssert(!item.hidden);
      if(safe)
      {
        bool good=pType->IsBasedOn(elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if(!A)return;
    DoVisitSaveID(A.ptr->SaveID,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    if(!A)return;
    DoVisitSaveID(A.ptr->SaveID,false,nullptr);
  }
};

class TServerPtrGraber:public TSmartPtrVisitor::ICallBack{
public:
  bool automark;
  int SkipCount;
  int AddCount;
  TServerPtrSpace&Space;
  TServerPtrGraber(TServerPtrSpace&Space,bool automark):Space(Space),automark(automark){AddCount=0;SkipCount=0;}
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
  {
    QapDebugMsg
    (
      "[2014.05.14 12:09]\n"
      "This class can not determine the actual type of the object and is no longer using.\n"
      "Look at 'TServerPtrGraberWithRealType'"
    );
    if(Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if(automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    auto&ex=Space.UnsafeAdd(&Serv,elemType);
    //ex.system=false; system=bool(ex.ptr_adv.ptr);
    AddCount++;
    if(automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(TClientPtr<IEsoteric>&A){}
  virtual void Visit(THardClientPtr<IEsoteric>&A){}
};

class TServerPtrCounter:public TSmartPtrVisitor::ICallBack{
public:
  int&count;
  TServerPtrCounter(int&count):count(count){}
public:
  virtual void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){count++;}
  virtual void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
  virtual void Visit(TClientPtr<IEsoteric>&A){}
  virtual void Visit(THardClientPtr<IEsoteric>&A){}
};

class TClientPtrSolver:public TSmartPtrVisitor::ICallBack{
public:
  struct TwoMetaType
  {
    TType*pTType;
    TType*pDeclareType;
    TwoMetaType(const TwoMetaType&Ref):pTType(nullptr),pDeclareType(nullptr){oper_set(Ref);}
    TwoMetaType():pTType(nullptr),pDeclareType(nullptr){}
    TwoMetaType(IEnvRTTI&Env):pTType(nullptr),pDeclareType(nullptr){prepare(Env);}
    template<class TYPE>
    TwoMetaType(TYPE&ref):pTType(ref.pTType),pDeclareType(ref.pDeclareType)
    {
      #define F(VAR)std::remove_reference<decltype(VAR)>::type
      #define TEST(FIELD)static_assert(std::is_same<F(this->FIELD),F(ref.FIELD)>::value,"no way");
      TEST(pTType);
      TEST(pDeclareType);
      #undef TEST
      #undef F
    }
    void prepare(IEnvRTTI&Env)
    {
      pTType=Sys$$<TType>::GetRTTI(Env);
      pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    }
    void oper_set(const TwoMetaType&Ref)
    {
      this->pTType=Ref.pTType;
      this->pDeclareType=Ref.pDeclareType;
    }
    void operator=(const TwoMetaType&Ref){oper_set(Ref);}
  };
public:
  typedef TServerPtrSpace TSpace;
  TSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  //TClientPtrSolver(TSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr){}
  TClientPtrSolver(TSpace&Space,const TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType){}
public:
  //void used_tmt(const TwoMetaType&tmt)
  //{
  //  this->pTType=tmt.pTType;
  //  this->pDeclareType=tmt.pDeclareType;
  //}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(!id)return nullptr;
    if(id<0||id>=Space.size()){QapDebugMsg("Error!\nWrong id:\n"+IToS(id));return nullptr;}
    auto&item=Space[id];
    if(item.ptr.type)
    {
      if(!safe){
        //тут может быть проблема. Кто-то решит не безопасно решить указатель и получит не тот что хотел.
        //т.к сейчас у нас одному id соответствуют 2 совершенно разных объекта.
        //надо исправить эту ошибку проектирования. 
        return item.ptr.ptr;
      }
      QapAssert(elemType);
      bool flag=elemType->IsBasedOn(pTType);
      if(!flag)
      {
        int gg=1;
      }
      if(flag)
      {
        bool f[]=
        {
          item.ptr.type->IsBasedOn(pTType),
          item.ptr.type->IsBasedOn(pDeclareType)
        };
        bool good=!f[0]&&f[1];
        if(!good)
        {
          auto*pType=item.ptr.type;
          QapAssert(pType->IsBasedOn(elemType));
          return item.ptr.ptr;
        }
        auto*pdType=(DeclareType*)item.ptr.get();
        auto&ex=Space[pdType->Self];
        QapAssert(ex.ptr_lnk.type);
        QapAssert(ex.ptr_lnk.type->IsBasedOn(pTType));
        auto*pType=ex.ptr_lnk.type;
        auto*pValue=(TType*)ex.ptr_lnk.get();
        QapAssert(pType->IsBasedOn(elemType));
        return EnvAdapter::get(pValue->Self);
      }
      auto*pType=item.ptr.type;
      QapAssert(pType->IsBasedOn(elemType));
      return item.ptr.ptr;
    }else{
      QapDebugMsg("norm");
      return item.ptr.ptr;
    }
    QapDebugMsg("no way.");
    return nullptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
};

class TClientPtrKiller:public TSmartPtrVisitor::ICallBack{
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisit(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisit(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A)
  {
    if(!A)return;
    A=nullptr;
  }
};

class TDumpPtrSolver:public TSmartPtrVisitor::ICallBack{
public:
  typedef TServerPtrSpace TSpace;
  TSpace&ST_Space;
  TSpace&LT_Space;
  TDumpPtrSolver(TSpace&ST_Space,TSpace&LT_Space):ST_Space(ST_Space),LT_Space(LT_Space){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  TServerPtr<IEsoteric>*DoVisitSaveID(int id,bool safe=false,TType*elemType=nullptr)
  {
    if(LT_Space[id].system)return ST_Space[id].ptr.ptr;
    return LT_Space[id].ptr.ptr;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,true,elemType);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    int id=int(A.ptr);
    auto*p=DoVisitSaveID(id,false,nullptr);
    A.ptr=nullptr;
    if(!p)return;
    A=p;
  }
};

class TClientPtrVisitor:public TSmartPtrVisitor::ICallBack{
public:
  struct ICallBack{
    template<class TYPE>
    void DoVisitServerPtr(TServerPtr<TYPE>&Serv,bool safe,TType*elemType){
      DoVisitServerPtr((TServerPtr<IEsoteric>*)&Serv,safe,elemType);
    }
    virtual void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe=false,TType*elemType=nullptr){
      QapDebugMsg("no way.");
    }
  };
public:
  ICallBack&CB;
  TClientPtrVisitor(ICallBack&CB):CB(CB){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    MegaVisit(A,elemType);
  }
  virtual void Visit(TClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
  virtual void Visit(THardClientPtr<IEsoteric>&A){
    MegaVisitEx(A);
  }
public:
  template<template<class> class SmartPtr>
  inline void MegaVisit(SmartPtr<IEsoteric>&A,TType*elemType)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,true,elemType);
  }
  template<template<class> class SmartPtr>
  inline void MegaVisitEx(SmartPtr<IEsoteric>&A)
  {
    static_assert(
      std::is_same<SmartPtr<IEsoteric>,TClientPtr<IEsoteric>>::value||
      std::is_same<SmartPtr<IEsoteric>,THardClientPtr<IEsoteric>>::value,"error"
    );
    CB.DoVisitServerPtr(A.ptr,false,nullptr);
  }
};

class THardClientSpace{
public:
  vector<THardClientPtr<IEsoteric>*> Arr;
  void Do()
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i];
      auto&ex=*it;
      if(ex)ex=nullptr;
    }
  }
};

class THardClientPtrGraber:public TSmartPtrVisitor::ICallBack{
public:
  typedef THardClientSpace TSpace;
  TSpace&Space;
  THardClientPtrGraber(TSpace&Space):Space(Space){}
public:
  void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType){}
  void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
  void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){
    Space.Arr.push_back(&A);
  }
  void Visit(TClientPtr<IEsoteric>&A){}
  void Visit(THardClientPtr<IEsoteric>&A){
    Space.Arr.push_back(&A);
  }
public:
};

inline void ClientMarker(TSmartPtrVisitor::ICallBack&ClientCounter,TType*pType,void*pValue)
{
  TSmartPtrVisitor SPG(ClientCounter,pValue);
  pType->Use(SPG);
}

class TServerPtrGraberWithRealType:public IVisitorRTTI{
public:
  typedef TServerPtrGraberWithRealType SelfClass;
  typedef TServerPtrSpace TSpace;
public:
  TSpace&Space;
  void*pValue;
  vector<void*> values;
  vector<TType*> types;
  bool automark;
  int AddCount;
  int SkipCount;
  TServerPtrGraberWithRealType(TSpace&Space,TType*pType,void*pValue,bool automark):Space(Space),pValue(pValue),automark(automark)
  {
    AddCount=0;
    SkipCount=0;
    push(pType);
  }
public:
  void push(TType*pType)
  {
    types.push_back(pType);
  }
  void pop(TType*pType)
  {
    QapAssert(!types.empty());
    QapAssert(pType==types.back());
    types.pop_back();
  }
  void ptr_push(void*ptr)
  {
    values.push_back(pValue);
    pValue=ptr;
  }
  void ptr_pop(void*ptr)
  {
    QapAssert(!values.empty());
    QapAssert(ptr==pValue);
    pValue=values.back();
    values.pop_back();
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType)
    {
      auto*pSubType=p->SubType.get();
      ptr_push(pValue);
      pSubType->Use(*this);
      ptr_pop(pValue);
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*ptr=(void*)(ex.Offset+int(pValue));
      auto*exType=ex.Type.get();
      push(exType);
      ptr_push(ptr);
      exType->Use(*this);
      ptr_pop(ptr);
      pop(exType);
    }
  }
  void Do(TTypeSys*p){/*это вообще нас не интересует.*/}
  void Do(TTypeFactory*p){/*это вообще нас не интересует.*/}
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    push(elemType);
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeArray*p)
  {
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    push(elemType);
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      ptr_push(ptr);
      elemType->Use(*this);
      ptr_pop(ptr);
    }
    pop(elemType);
  }
  void Do(TTypeSelfPtr*p)
  {
    TSelfPtr<IEsoteric>&value=*(TSelfPtr<IEsoteric>*)pValue;
    auto&Serv=value.P;
    if(Space.CheckServSaveID(&Serv))
    {
      QapDebugMsg("the way used? ORL?");
      SkipCount++;
      auto&ex=Space[Serv.SaveID];
      if(automark)
      {
        ex.count++;
        ex.passed=true;
      }
      return;
    }
    QapAssert(types.size()>=2);
    auto*pElemType=p->ElementType.get();
    auto*type=types[types.size()-2];
    QapAssert(TTypeSelfPtr::UberCast(types.back()));
    QapAssert(type->IsBasedOn(pElemType));
    auto&ex=Space.UnsafeAdd(&Serv,type);
    //ex.system=false; system=bool(ex.ptr_adv.ptr);
    AddCount++;
    if(automark)
    {
      ex.count++;
      ex.passed=true;
    }
  }
  void Do(TTypeAutoPtr*p)
  {
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      auto*ptr=(void*)&type;
      auto*pmTypeType=p->mType.Type.get();
      ptr_push(ptr);
      pmTypeType->Use(*this);
      ptr_pop(ptr);
    }
    auto*ptr=value.get();
    auto*pType=type.get();
    push(pType);
    if(ptr&&type)
    {
      ptr_push(ptr);
      pType->Use(*this);
      ptr_pop(ptr);
    }
    pop(pType);
  }
  void Do(TTypeWeakPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeHardPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeVoidPtr*p){/*это вообще нас не интересует.*/}
  void Do(TTypeFieldPtr*p){/*это вообще нас не интересует.*/}
};

inline void GrabServerPtr(TServerPtrSpace&Space,TType*pType,void*pValue,bool automark)
{
  TServerPtrGraberWithRealType SPGWRT(Space,pType,pValue,automark);
  pType->Use(SPGWRT);
  return;
  //[2014.05.14 12:34]
  //TServerPtrGraber SmartGraber(Space,automark);
  //TSmartPtrVisitor SPG(SmartGraber,pValue);
  //pType->Use(SPG);
}