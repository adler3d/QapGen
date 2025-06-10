class TSpaceDependsTools;
class DeclareEnvRTTI;
class TServerPtrSpace;
class DeclareType;
class DeclareTypeStruct;
class DeclareTypeSys;

struct TwoDeclareMetaType{
  DeclareType*pdTType;
  DeclareType*pdDeclareType;
  TwoDeclareMetaType():pdTType(nullptr),pdDeclareType(nullptr){}
};
template<class VOID_TYPE>
struct TDeclareEnvRTTI_WeakDetail
{
public:
  typedef TServerPtrSpace TSpace;
  //помещает в себя то, что можно сохранить из Tools.
  static void GrabFrom(DeclareEnvRTTI&Dest,DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
  {
    auto&arr=Source.Arr;
    auto&out=Dest.Arr;
    QapAssert(out.empty());
    out.reserve(arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      const auto&ex_SaveID=ex->Self.P.SaveID;
      bool skip=!Space.IsSolved(ex_SaveID);
      QapAssert(!skip);
      if(skip)continue;
      if(true)
      {
        auto&item=Space[ex_SaveID];
        if(!item.count)continue;
      }
      bool f0=ex.get()->IsBasedOn(tdmt.pdTType);
      bool f1=ex.get()->IsBasedOn(tdmt.pdDeclareType);
      QapAssert(!(f0&&f1));
      skip=f0||f1;
      if(skip)continue;
      out.push_back(std::move(ex));
    }
  }
  //struct MegaItem
  //{
  //  int SaveID;
  //  DeclareType*pdType;
  //  MegaItem():SaveID(0),pdType(nullptr){}
  //};
  //помещает в Tools то, что было в себе.
  //static bool ApplyTo(DeclareEnvRTTI&DeclEnvRTTI,TSpaceDependsTools&Tools,TSpace&tmpSpace)
  //{
  //  //QapDebugMsg("first pass");return false;
  //  struct Hack
  //  {
  //    vector<MegaItem> MegaArr;
  //    ~Hack(){clear();}
  //    void clear()
  //    {        
  //      for(int i=0;i<MegaArr.size();i++)
  //      {
  //        auto&ex=MegaArr[i];
  //        if(!ex.pdType)continue;
  //        auto&SaveID=ex.pdType->Self.P.SaveID;
  //        QapAssert(!SaveID);
  //        SaveID=ex.SaveID;
  //      }
  //      MegaArr.clear();
  //    }
  //  };
  //  Hack buff_hack;
  //  auto&MegaArr=buff_hack.MegaArr;
  //  MegaArr.resize(tmpSpace.size()+Tools.DeclEnv.Arr.size());
  //  auto&Space=Tools.Space;
  //  auto&arr=Tools.DeclEnv.Arr;
  //  for(int i=0;i<arr.size();i++)
  //  {
  //    auto&ex=arr[i];
  //    auto&item=Space[ex->Self];
  //    {
  //      auto&id=ex->Self.P.SaveID;
  //      QapAssert(item.id==id);
  //      QapAssert(ex.get()==(void*)item.ptr.get());
  //      id=0;
  //    }
  //    auto&id=tmpSpace.AddExt(item.ptr.ptr,item.ptr.type,item.name).id;
  //    auto&ax=MegaArr[id];
  //    QapAssert(!ax.pdType&&!ax.SaveID);
  //    ax.pdType=ex.get();
  //    ax.SaveID=item.id;
  //  }
  //  auto&input=DeclEnvRTTI.Arr;
  //  //linking and testing
  //  bool Result=Linking(input,arr,tmpSpace);
  //  if(Result)Result=Testing(input,arr,tmpSpace,Tools);
  //  //
  //  auto&getOriginal=[&Tools](EnvItem&item)->DeclareType*
  //  {
  //    return (DeclareType*)item.ptr_lnk.get();
  //  };
  //  auto&GetSaveID=[&](EnvItem&input)->int
  //  {
  //    DeclareType*p=getOriginal(input);
  //    TType*pSource=(TType*)Space[MegaArr[tmpSpace[p->Self].id].SaveID].ptr_lnk.get();
  //    auto&item=Space[pSource->Self];
  //    return item.id;
  //  };
  //  //general work begin
  //  vector<std::pair<int,int>> buffarr;
  //  buffarr.resize(input.size());
  //  if(Result)
  //  {
  //    for(int i=0;i<input.size();i++)
  //    {
  //      auto&ex=input[i];
  //      auto&item=tmpSpace[ex->Self];
  //      int id=GetSaveID(item);
  //      auto&swap_pair=buffarr[i];
  //      swap_pair.first=item.id;
  //      swap_pair.second=id;
  //      //Space.Swap(item.id,id);
  //    }
  //  }
  //  for(int i=0;i<arr.size();i++)
  //  {
  //    auto&ex=arr[i];
  //    auto&item=tmpSpace[ex->Self];
  //    tmpSpace.Del(item,true);
  //  }
  //  buff_hack.clear();
  //  if(Result)
  //  {
  //    for(int i=0;i<buffarr.size();i++)
  //    {
  //      auto&ex=buffarr[i];
  //      Space.Swap(ex.first,ex.second);
  //    }
  //  }
  //  //general work end
  //  return Result;
  //}
  typedef vector<TAutoPtr<DeclareType>> TArray;
  //static bool Linking(TArray&input,TArray&arr,TSpace&tmpSpace)
  //{
  //  bool Result=false;
  //  string report_msg;
  //  for(int i=0;i<input.size();i++)
  //  {
  //    auto*pValue=input[i].get();
  //    auto&item=tmpSpace[pValue->Self];
  //    string ValueFullName=pValue->GetFullName();
  //    item.name="Def$$<"+ValueFullName+">::GetRTTI()";
  //    if(item.ptr_lnk.IsValid())continue;
  //    Result=false;
  //    for(int j=0;j<arr.size();j++)
  //    {
  //      auto*p=arr[j].get();
  //      if(p->GetFullName()==ValueFullName)
  //      {
  //        auto&jtem=tmpSpace[p->Self];
  //        TSpace::make_linked(item,jtem);
  //        Result=true;
  //        break;
  //      }
  //    }
  //    if(!Result)
  //    {
  //      string msg="not found type : \""+pValue->GetFullName()+"\"";
  //      report_msg+=msg+"\n";
  //      break;
  //    }
  //  }
  //  if(!Result)
  //  {
  //    QapDebugMsg("report :\n"+report_msg);
  //  }
  //  return Result;
  //}
  //static bool Testing(TArray&input,TArray&arr,TSpace&tmpSpace,TSpaceDependsTools&Tools)
  //{
  //  auto get=[&](EnvVoidPtr&ptr)->DeclareType*
  //  {
  //    bool good=ptr.type->IsBasedOn(Tools.pDeclareType);
  //    QapAssert(good);
  //    return (DeclareType*)ptr.get();
  //  };
  //  DeclareDetail::IsEqualTo<TServerPtrSpace> V(tmpSpace);
  //  for(int i=0;i<input.size();i++)
  //  {
  //    auto&ex=input[i];
  //    auto*pValue=ex.get();
  //    V.Result=false;
  //    V.pValue=pValue;
  //    auto&item=tmpSpace[pValue->Self];
  //    if(item.ptr_lnk.IsValid())
  //    {
  //      auto*p=get(item.ptr_lnk);
  //      auto&jtem=tmpSpace[p->Self];
  //      QapAssert(jtem.ptr_lnk.get()==(void*)pValue);
  //      item.ptr_lnk.set_zero();
  //      jtem.ptr_lnk.set_zero();
  //      V.Result=false;
  //      p->Use(V);
  //      if(V.Result)
  //      {
  //        bool f0=item.ptr_lnk.get()==jtem.ptr.get();
  //        bool f1=jtem.ptr_lnk.get()==item.ptr.get();
  //        QapAssert(f0&&f1);
  //      }
  //    }else{
  //      QapDebugMsg("WTF?");
  //    }
  //    if(!V.Result)
  //    {
  //      QapDebugMsg("bad type : \""+pValue->GetFullName()+"\"");
  //      break;
  //    }
  //  }
  //  return V.Result;
  //}
  //static void RetAll(DeclareEnvRTTI&DeclEnvRTTI,TSpaceDependsTools&Tools)
  //{
  //  auto&DeclArr=DeclEnvRTTI.Arr;
  //  auto&arr=Tools.DeclEnv.Arr;
  //  //ToolsVectorEx(arr)+=DeclArr;
  //  for(int i=0;i<DeclArr.size();i++)
  //  {
  //    arr.push_back(std::move(DeclArr[i]));
  //  }
  //}
};

class DeclareEnvType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareEnvType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(TAutoPtr<DeclareType>,Type,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareEnvType
#include "QapGenStruct.inl"
//<<<<<+=====DeclareEnvType
public:
  static void SysHasSelf();
public:
  static bool IsEmpty(SelfClass&ref)
  {
    return !bool(ref.Type);
  }
};

class DeclareEnvRTTI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareEnvRTTI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<DeclareType>>,Arr,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====DeclareEnvRTTI
public:
  typedef TServerPtrSpace TSpace;
  typedef vector<TAutoPtr<DeclareType>> TArray;
public:
  struct TwoDeclareType
  {
    DeclareType*pdTType;
    DeclareType*pdDeclareType;
    TwoDeclareType(const TwoDeclareType&Ref):pdTType(nullptr),pdDeclareType(nullptr){oper_set(Ref);}
    TwoDeclareType():pdTType(nullptr),pdDeclareType(nullptr){}
    template<class TYPE>
    TwoDeclareType(TYPE&ref):pdTType(ref.pTType),pdDeclareType(ref.pDeclareType)
    {
      #define F(VAR)std::remove_reference<decltype(VAR)>::type
      #define TEST(FIELD)static_assert(std::is_same<F(this->FIELD),F(ref.FIELD)>::value,"no way");
      TEST(pdTType);
      TEST(pdDeclareType);
      #undef TEST
      #undef F
    }
    void oper_set(const TwoDeclareType&Ref)
    {
      this->pdTType=Ref.pdTType;
      this->pdDeclareType=Ref.pdDeclareType;
    }
    void operator=(const TwoDeclareType&Ref){oper_set(Ref);}
  };
public:
  void GrabFrom(DeclareEnvRTTI&Source,TSpace&Space,TwoDeclareMetaType&tdmt)
  {
    TDeclareEnvRTTI_WeakDetail<void>::GrabFrom(*this,Source,Space,tdmt);
  }
  void RetAll(TSpaceDependsTools&Tools)
  {
    QapDebugMsg("no used?");
    //TDeclareEnvRTTI_WeakDetail<void>::RetAll(*this,Tools);
  }
  bool ApplyTo(TSpaceDependsTools&Tools,TSpace&tmpSpace)
  {
    QapDebugMsg("no used?");
    return false;
    //return TDeclareEnvRTTI_WeakDetail<void>::ApplyTo(*this,Tools,tmpSpace);
  }
};