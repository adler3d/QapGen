struct SubFieldsInfo{
public:
  class OutDeviceEx{
  public:
    //===>>===IVisitor
    #define LIST(F)F(TMemberID)F(TSubType)
    #define F(TYPE)class TYPE;
    LIST(F)
    #undef F
    struct IVisitor{
      #define F(TYPE)virtual void Do(TYPE*p)=0;
        LIST(F)
      #undef F
    };
    #undef LIST
    //===<<===IVisitor
    struct DevCmd{virtual void Use(IVisitor&A)=0;};

    #define ADOTHIS()public:void Use(IVisitor&A){A.Do(this);}
    class TMemberID:public DevCmd{public:int id;TMemberID(int id):id(id){}ADOTHIS()};
    class TSubType:public DevCmd{ADOTHIS()};
    #undef ADOTHIS

    class TContext{
    public:
      DevCmd*pCmd;
    public:
      TType*pType;
      int Offset;
      const string*head;
    public:
      TContext():pCmd(nullptr),pType(nullptr),Offset(0),head(nullptr){}
    };

    class TCmdVisitor:public IVisitor{
    public:
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
        pContext->head=&ex.Name;
      }
      void Do(TSubType*p)
      {
        pContext->Offset=pContext->Offset;
        pContext->pType=pContext->pType->GetSubType();
        pContext->head=nullptr;
        QapAssert(pContext->pType);
      }
    };
  public:
    class TCmdOffsetVisitor:public IVisitor{
    public:
      struct TContext{
        TType*pType;
        int Offset;
      };
      TContext*pContext;
    public:
      void Do(TMemberID*p)
      {
        int id=p->id;
        TTypeStruct*pMetaType=TTypeStruct::UberCast(pContext->pType);
        QapAssert(pMetaType);
        auto&ex=pMetaType->Members[id];
        pContext->Offset+=ex.Offset;
        pContext->pType=ex.Type.get();
      }
      void Do(TSubType*p){
        pContext->pType=pContext->pType->GetSubType();
      }
    };
  public:
    TContext Context;
    vector<TContext> branch;
    // ----- ----- ----- ----- -----
    // ----- ----- ----- ----- -----
    // ----- ----- ----- ----- -----
  public:
    void push(DevCmd*pCmd)
    {
      branch.push_back(Context);
      Context.pCmd=pCmd;
      if(pCmd)
      {
        TCmdVisitor CV;
        CV.pContext=&Context;
        pCmd->Use(CV);
      }
    }
    void pop()
    {
      Context=branch.back();
      branch.pop_back();
    }
  public:
    string GetFullFieldNameByIdFromBranch(int id)
    {
      string path;
      for(int i=id;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if(ex.head)path+=*ex.head+".";
      }
      if(Context.head)
      {
        path+=*Context.head;
      }else if(!path.empty()&&(path.back()=='.')){
        path.pop_back();
      }
      return std::move(path);
    }
    int GetRelativeFieldOffsetByIdFromBranch(int id)
    {
      TType*pType=nullptr;
      {
        auto&ex=branch[id];
        pType=ex.pType;
      }
      TCmdOffsetVisitor::TContext Context={pType,0};
      TCmdOffsetVisitor COV;
      COV.pContext=&Context;
      for(int i=id+1;i<branch.size();i++)
      {
        auto&ex=branch[i];
        if(!ex.pCmd)return -1;
        ex.pCmd->Use(COV);
      }
      if(!this->Context.pCmd)
      {
        return -1;
      }
      this->Context.pCmd->Use(COV);
      return Context.Offset;
    }
  };
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  class TOffsetVerifier:public IVisitorRTTI{
  public:
    typedef TOffsetVerifier SelfClass;
    typedef OutDeviceEx TSaveDev;
  public:
    struct ICallBack{virtual bool Do(SelfClass&V,TType*p)=0;};
  public:
    struct TFieldInfo{
      TType*pType;
      int Offset;
      void setZero()
      {
        this->Offset=0;
        this->pType=nullptr;
      }
    };
    class IndexGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      const TFieldInfo&Info;
      IndexGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1){}
    public:
      bool Do(SelfClass&OV,TType*p){
        if(Result)return false;
        if(Info.Offset!=OV.Offset)return true;
        Result=bool(Info.pType==p);
        if(Result)Index=OV.Index;
        return !Result;
      }
    };
    class InfoGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      TFieldInfo&Info;
      InfoGetter(TFieldInfo&Info,int Index=-1):Info(Info),Result(false),Index(Index){}
    public:
      bool Do(SelfClass&OV,TType*p){
        if(Result)return false;
        if(OV.Index!=Index)return true;
        Info.Offset=OV.Offset;
        Info.pType=p;
        Result=true;
        return !Result;
      }
    };
    class FieldNameGetter:public ICallBack{
    public:
      bool Result;
      int Index;
      string fieldname;
      const TFieldInfo&Info;
      FieldNameGetter(const TFieldInfo&Info):Info(Info),Result(false),Index(-1){}
    public:
      bool Do(SelfClass&V,TType*p){
        if(Result)return false;
        if(Info.Offset!=V.Offset)return true;
        Result=bool(Info.pType==p);
        if(Result)
        {
          Index=V.Index;
          fieldname=V.dev.GetFullFieldNameByIdFromBranch(0);
        }
        return !Result;
      }
    };
  public:
    TSaveDev&dev;
    ICallBack&CB;
    int Offset;
    int&Index;
    TOffsetVerifier(TSaveDev&dev,ICallBack&CB,int Offset,int&Index):dev(dev),CB(CB),Offset(Offset),Index(Index){}
    TOffsetVerifier(SelfClass&owner,int Offset):dev(owner.dev),CB(owner.CB),Offset(Offset),Index(owner.Index){Index++;}
  public:
    void Do(TTypeStruct*p)
    {
      if(!CB.Do(*this,p))return;
      if(p->SubType)
      {
        TSaveDev::TSubType tmp;
        dev.push(&tmp);
        SelfClass next(*this,Offset);
        p->SubType->Use(next);
        dev.pop();
      }
      auto&arr=p->Members;  
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        TSaveDev::TMemberID tmp(i);
        dev.push(&tmp);
        SelfClass next(*this,Offset+ex.Offset);
        ex.Type->Use(next);
        dev.pop();
      }
    }
    void Do(TTypeSys*p)
    {
      if(!CB.Do(*this,p))return;
    }
    void Do(TTypeVector*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeArray*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeSelfPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeAutoPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeWeakPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeHardPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeVoidPtr*p){if(!CB.Do(*this,p))return;}
    void Do(TTypeFieldPtr*p){if(!CB.Do(*this,p))return;}
  };
public:
  typedef TOffsetVerifier::TFieldInfo TFieldInfo;
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  static string FieldInfoToFieldName(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::FieldNameGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier Visitor(dev,CB,0,tmp);
    pType->Use(Visitor);
    return CB.fieldname;
  }
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
  static int FieldInfoToIndex(TType*pType,const TOffsetVerifier::TFieldInfo&Info)
  {
    typedef TOffsetVerifier::IndexGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TCallBack CB(Info);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return CB.Index;
  }
  static TOffsetVerifier::TFieldInfo IndexToFieldInfo(TType*pType,int Index)
  {
    typedef TOffsetVerifier::InfoGetter TCallBack;
    OutDeviceEx dev;
    dev.Context.pType=pType;
    TFieldInfo Info;
    Info.setZero();
    TCallBack CB(Info,Index);
    int tmp=0;
    TOffsetVerifier OV(dev,CB,0,tmp);
    pType->Use(OV);
    return Info;
  }
public:
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
  // ----- ----- ----- ----- -----
public:
};