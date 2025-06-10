class TClientPtrVcbCounter:public TClientPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  TClientPtrVcbCounter(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
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
        //bool good=pType->IsBasedOn(elemType);
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if(!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};

class TClientPtrVcbCounter20120828:public TClientPtrVisitor::ICallBack{
public:
  TServerPtrSpace&Space;
  TType*pTType;
  TType*pDeclareType;
  bool firstmode;
  TClientPtrVcbCounter20120828(IEnvRTTI&Env,TServerPtrSpace&Space):Space(Space),pTType(nullptr),pDeclareType(nullptr),firstmode(true)
  {
    prepare(Env);
  }
public:
  void prepare(IEnvRTTI&Env)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
  }
public:
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
    if(item.system)return;
    if(true)
    {
      QapAssert(item.ptr.type);
      auto*pType=item.ptr.type;
      bool trigger=pType->IsBasedOn(pTType)||pType->IsBasedOn(pDeclareType);
      if(trigger)
      {
        int gg=1;
      }
      QapAssert(!item.hidden);
      if(safe)
      {
        //bool good=pType->IsBasedOn(elemType);
        bool good=EnvAdapter::IsBasedOn(pType,elemType);
        QapAssert(good);
      }
    }
    item.count++;
    return;
  }
public:
  void DoVisitServerPtr(TServerPtr<IEsoteric>*serv,bool safe,TType*elemType)
  {
    if(!serv)return;
    DoVisitSaveID(serv->SaveID,safe,elemType);
  }
};

class DependsSolver{
public:
  typedef TServerPtrSpace TSpace;
  //typedef TSmartPtrVisitor::ICallBack TClientPtrCounter;
  TClientPtrVisitor&CPC;
  TType*pTType;
  TType*pDeclareType;
  vector<int> Arr;
  bool fullprocess;
  DependsSolver(IEnvRTTI&Env,TClientPtrVisitor&CPC):CPC(CPC)
  {
    pTType=Sys$$<TType>::GetRTTI(Env);
    pDeclareType=Sys$$<DeclareType>::GetRTTI(Env);
    fullprocess=false;
  }
  void prepare(TSpace&Space,bool force)
  {
    Arr.clear();
    for(int i=0;i<Space.size();i++)
    {
      auto&item=Space[i];
      //bool skip=!item.count||force?false:item.passed;
      if(item.hidden)QapAssert(item.system);
      bool skip=item.system||item.passed||!item.count;
      if(skip)continue;
      if(false)
      {
        bool skip=item.ptr.type->IsBasedOn(pTType);
        if(skip)
        {
          int gg=1;
          continue;
        }
      }
      if(!fullprocess)
      {
        //пропускаем заместителей.
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if(skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      Arr.push_back(item.id);
    }
  }
  void pass(TSpace&Space,const TRawPtr&ptr)
  {
    TType*pType=ptr.pType;
    void*pValue=ptr.pValue;
    if(true)
    {
      int sid=pType->Self.P.SaveID;
      QapAssert(sid);
      //помечаем описатель элемента, как достигнутый
      CPC.CB.DoVisitServerPtr(pType->Self.P,true,pTType);
    }
    //помечаем зависимые элементы, как достигнутые
    ClientMarker(CPC,pType,pValue);
  }
  TRawPtr get(const EnvVoidPtr&ptr)
  {
    TRawPtr tmp;
    tmp.pType=ptr.type;
    tmp.pValue=ptr.get();
    return tmp;
  }
  void step(TSpace&Space)
  {
    for(int i=0;i<Arr.size();i++)
    {
      int id=Arr[i];
      if(!id)continue;
      auto&item=Space[id];
      QapAssert(!item.system);
      if(!item.ptr.type)
      {
        QapAssert(item.passed&&item.ptr.type);
        item.passed=true;
        continue;
      }
      if(!fullprocess)
      {
        bool skip=item.ptr.type->IsBasedOn(pDeclareType);
        if(skip)
        {
          QapDebugMsg("WTF?");
          continue;
        }
      }
      //проходимся по элементу
      pass(Space,get(item.ptr));
      //помечаем элемент, как пройденный
      item.passed=true;
    }
  }
  void SolveDepends(TSpace&Space,bool fullprocess=true)
  {
    this->fullprocess=fullprocess;
    prepare(Space,false);
    //ищем новые цели и помечаем их пройденными
    for(int loop_counter=0;!Arr.empty()&&(loop_counter<1024);loop_counter++)
    {
      //посещаем все цели
      step(Space);
      //ищем новые цели
      prepare(Space,false);
    }
    QapAssert(Arr.empty());
    QapAssert(Space[0].count>0);
    this->fullprocess=false;
  }
  //operator bool(){return !Arr.empty();}
};