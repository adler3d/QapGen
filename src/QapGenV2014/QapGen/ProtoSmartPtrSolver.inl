class IProtoSmartPtrSolver{
public:
  bool Result;
  IProtoSmartPtrSolver():Result(true){}
public:
  typedef string SaveIDType;
public:
  virtual void SolveClient(TType*pType,void*pValue){QapDebugMsg("no way.");}
public:
  virtual TType*PreSolve(THardPtr<TType>&pInput,TType*pElemType){QapDebugMsg("no way.");return nullptr;}
public:
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void GetSaveID(SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
public:
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
  virtual void SetSaveID(const SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref){QapDebugMsg("no way.");}
public:
  static TServerPtr<IEsoteric>*const&get(const SaveIDType&SaveID){return (TServerPtr<IEsoteric>*const&)(void*const&)SaveID;}
  static const SaveIDType&get(TServerPtr<IEsoteric>*const&serv){return (const SaveIDType&)(void*const&)serv;}
};

class TProtoSmartPtrSolver:public IProtoSmartPtrSolver{
public:
  typedef TServerPtrSpace TSpace;
  typedef TClientPtrSolver::TwoMetaType TwoMetaType;
public:
  TSpace&Space;
  TType*pDeclareType;
  TType*pTType;
public:
  TProtoSmartPtrSolver(TSpace&Space,TwoMetaType&tmt):Space(Space),pTType(tmt.pTType),pDeclareType(tmt.pDeclareType){};
public:
  //struct GetEnvVoidPtr_context{
  //  const EnvItem&item;
  //  TType*pElemType;
  //  EnvVoidPtr*ptr;
  //  string error_msg;
  //};
  //EnvVoidPtr*unsafe_GetEnvVoidPtr(GetEnvVoidPtr_context&context)
  //{
  //  item.ptr
  //}
  void ST_CheckSaveID(const int&id,TType*pElemType)
  {
    QapAssert(Space.IsAllowed(id));
    auto&item=Space[id];
    QapAssert(item.ptr.ptr);
    auto bulid_msg=[](TType*obj_type,TType*base_type)->string
    {
      string obj_fn=obj_type->GetFullName();
      string base_fn=base_type->GetFullName();
      return "IsBasedOn(\""+obj_fn+"\",\""+base_fn+"\") == false";
    };
    auto get_flag=[&pElemType,&item]()->bool
    {
      if(!item.ptr_lnk.IsValid())return false;
      return item.ptr_lnk.type->IsBasedOn(pElemType);
    };
    if(!item.ptr.type->IsBasedOn(pElemType))
    {
      if(!get_flag())
      {
        bool flag=item.ptr_lnk.IsValid();
        string msg;
        msg+=bulid_msg(item.ptr.type,pElemType);
        if(flag)msg+="\nand\n";
        if(flag)msg+=bulid_msg(item.ptr_lnk.type,pElemType);
        QapDebugMsg(msg);
      }
    }
    //int&sid=item.ptr.ptr->SaveID;
    //QapAssert(&sid==&id);
  }
  int ST_GetSID(TServerPtr<IEsoteric>*serv,TType*pElemType)
  {
    if(serv)
    {
      auto&id=serv->SaveID;
      if(id)ST_CheckSaveID(id,pElemType);
      if(!id)
      {
        QapAssert(id);
      }
      return id;
    }
    return 0;
  }
  void SaveResult(SaveIDType&Result,int id,TType*pElemType)
  {
    if(!id)
    {
      auto&item=Space[id];
      item.CheckNullptr();
      Result=item.name;
      return;
    }
    auto GetEnvVoidPtr=[](const EnvItem&item,TType*pElemType)->const EnvVoidPtr*
    {
      bool f1=item.ptr.IsValid();
      if(f1&&item.ptr.type->IsBasedOn(pElemType))return &item.ptr;
      bool f2=item.ptr_lnk.IsValid();
      if(f2&&item.ptr_lnk.type->IsBasedOn(pElemType))return &item.ptr;
      return nullptr;
    };
    auto*ptr=GetEnvVoidPtr(Space[id],pElemType);
    QapAssert(ptr);
    const string&name=Space[ptr->ptr->SaveID].name;
    Result=name.empty()?IToH(id):name;
  }
public:
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TSelfPtr<IEsoteric>&ref)
  {
    auto&id=ref.P.SaveID;
    ST_CheckSaveID(id,pElemType);
    QapAssert(&Space[id].ptr.ptr->SaveID==&id);
    SaveResult(sid,id,pElemType);
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,TWeakPtr<IEsoteric>&ref)
  {
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    SaveResult(sid,ST_GetSID(serv,pElemType),pElemType);
  }
  //SaveTime
  void GetSaveID(SaveIDType&sid,TType*pElemType,THardPtr<IEsoteric>&ref)
  {
    TServerPtr<IEsoteric>*serv=ref.P.ptr;
    SaveResult(sid,ST_GetSID(serv,pElemType),pElemType);
  }
};