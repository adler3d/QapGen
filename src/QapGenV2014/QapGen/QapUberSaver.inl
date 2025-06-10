#include "QapStrFinder.inl"
class QapBinaryObject{
public:
  typedef TServerPtrSpace TSpace;
  static void DoSave(ISmartPtrSolver&Solver,QapIO&IO,TType*pType,void*pValue)
  {
    TBinarySaver BS(Solver,IO,pValue);
    pType->Use(BS);
  }
  static bool DoLoad(ISmartPtrSolver&Solver,QapIO&IO,TType*pType,void*pValue)
  {
    if(!Solver.Result)return false;
    TBinaryLoader BL(Solver,IO,pType,pValue);
    pType->Use(BL);
    if(!Solver.Result)return false;
    Solver.SolveClient(pType,pValue);
    return Solver.Result;
  }
};

class TQapBinaryObject{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TQapBinaryObject)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,SpaceSize,SET,0,$)\
ADDVAR(vector<EnvDefTypeStr>,MetaSpec,DEF,$,$)\
ADDVAR(FullDeclareEnvRTTI,FullDeclEnv,DEF,$,$)\
ADDVAR(THardPtr<TType>,RootType,DEF,$,$)\
ADDEND()
//=====+>>>>>TQapBinaryObject
#include "QapGenStruct.inl"
//<<<<<+=====TQapBinaryObject
public:
  typedef vector<EnvDefTypeStr> TMetaSpec;
  struct TRawPtrs
  {
    TRawPtr SpaceSize;
    TRawPtr MetaSpec;
    TRawPtr FullDeclEnv;
    TRawPtr RootType;
    TRawPtr Root;
  public:
    void Init(IEnvRTTI&Env,TQapBinaryObject&qbo)
    {
      #define F(FIELD)this->FIELD.set(Env,qbo.FIELD);
      F(SpaceSize);F(MetaSpec);F(FullDeclEnv);F(RootType);
      #undef F
      Root.setZero();
    }
  };
};

struct TConservationMachine;

struct IUberSaveDevice
{
  typedef TConservationMachine TMachine;
  virtual void DoSave(TMachine&machine,TRawPtr&raw_ptr){}
  virtual void Save(TMachine&machine,TRawPtr&raw_ptr){}
};

struct IUberLoadDevice
{
  typedef TConservationMachine TMachine;
  virtual bool DoLoad(TMachine&machine,TRawPtr&raw_ptr){return false;}
  virtual bool Load(TMachine&machine,TRawPtr&raw_ptr){return false;}
};

#include "QapUberSaver_TConservationMachine.inl"

struct UberSaveDeviceBin:IUberSaveDevice
{
  IQapStream&Stream;
  struct TContext
  {
    QapIO&Content;
    TSmartPtrSolver&Solver;
  };
  TContext*pContext;
  UberSaveDeviceBin(IQapStream&Stream):Stream(Stream),pContext(nullptr){}
  void Begin(TContext&Ref){QapAssert(!pContext);pContext=&Ref;}
  void End(){QapAssert(pContext);pContext=nullptr;}
  void Save(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&Dev=*this;
    auto&Content=Stream.GetContent();
    {
      TSmartPtrSolver Solver(machine.Space,machine.Tools.get_tmt());
      TContext Context={Content,Solver};
      Begin(Context);
      machine.Save(Dev,raw_ptr);
      End();
    }
    if(Content.IsCrashed())return;
    Stream.Save();
    //bool result=!Content.IO.mem.empty()&&Stream.Save();
  }
  void DoSave(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&Content=pContext->Content;
    auto&Solver=pContext->Solver;
    QapBinaryObject::DoSave(Solver,Content,raw_ptr.pType,raw_ptr.pValue);
  }
};

struct UberLoadDeviceBin:IUberLoadDevice
{
  IQapStream&Stream;
  struct TContext
  {
    QapIO&Content;
    TSmartPtrSolver&Solver;
  };
  TContext*pContext;
  UberLoadDeviceBin(IQapStream&Stream):Stream(Stream),pContext(nullptr){}
  void Begin(TContext&Ref){QapAssert(!pContext);pContext=&Ref;}
  void End(){QapAssert(pContext);pContext=nullptr;}
  bool Load(TMachine&machine,TRawPtr&raw_ptr)
  {
    if(!Stream.Load())return false;
    bool Result=false;
    auto&Dev=*this;
    auto&Content=Stream.GetContent();
    {
      TSmartPtrSolver Solver(machine.Space,machine.Tools.get_tmt());
      TContext Context={Content,Solver};
      Begin(Context);
      Result=machine.Load(Dev,raw_ptr);
      End();
    }
    return Result;
  }
  bool DoLoad(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&Content=pContext->Content;
    auto&Solver=pContext->Solver;
    return QapBinaryObject::DoLoad(Solver,Content,raw_ptr.pType,raw_ptr.pValue);
  }
};

struct UberSaveDeviceProto:IUberSaveDevice
{
  IQapStream&Stream;
  struct TContext
  {
    TProtoCodeGen&dev;
    TProtoSmartPtrSolver&Solver;
  };
  TContext*pContext;
  UberSaveDeviceProto(IQapStream&Stream):Stream(Stream),pContext(nullptr){}
  void Begin(TContext&Ref){QapAssert(!pContext);pContext=&Ref;}
  void End(){QapAssert(pContext);pContext=nullptr;}
  void Save(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&Dev=*this;
    auto&Content=Stream.GetContent();
    TDataIO tmpIO;
    TProtoCodeGen dev(tmpIO.IO.mem);
    TProtoSmartPtrSolver Solver(machine.Space,machine.Tools.get_tmt());
    {
      TContext Context={dev,Solver};
      Begin(Context);
      machine.Save(Dev,raw_ptr);
      End();
    }
    bool result=!tmpIO.IO.mem.empty();
    if(result)tmpIO.WriteTo(Content);
    result=result&&Stream.Save();
  }
  void DoSave(TMachine&machine,TRawPtr&raw_ptr)
  {
    auto&dev=pContext->dev;
    auto&solver=pContext->Solver;
    IndirectProtoSaver::DoSave(solver,dev,raw_ptr.pType,raw_ptr.pValue);
  }
};

bool QapUberFullSaver(IEnvRTTI&Env,IQapRawObject&&Object,IUberSaveDevice&Dev)
{
  auto&raw_ptr=Object.Get(Env);
  //begin
  {
    TQapBinaryObject qbo;
    TConservationMachine Machine(Env,qbo);
    Machine.FullSave(Dev,raw_ptr);
    auto&arr=qbo.FullDeclEnv.DeclEnv.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!ex->Self.P.SaveID)continue;
      string fn=ex->GetFullName();
      bool breakpoint=true;
    }
    qbo.FullDeclEnv.DeclEnv.Arr.clear();
  }
  //end
  return true;
}

bool QapUberFullLoader(IEnvRTTI&Env,IQapRawObject&&Object,IUberLoadDevice&Dev)
{
  auto&raw_ptr=Object.Get(Env);
  bool Result=false;
  //begin
  {
    TQapBinaryObject qbo;
    TConservationMachine Machine(Env,qbo);
    Result=Machine.FullLoad(Dev,raw_ptr);
    qbo.FullDeclEnv.DeclEnv.Arr.clear();
  }
  //end
  return Result;
}