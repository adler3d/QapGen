#define QAP_LOG(MSG)
class TPrinter{
public:
  string&s;
  string indent;
  string sep;
  TPrinter(string&s):s(s){sep=" = ";}
public:
  virtual void Indent(){indent+="  ";}
  virtual void Outdent(){indent.resize(max(0,indent.size()-2));}
  //virtual void Print(string const&name,string const&data){s+=indent+name+sep+data+"\n";}
  virtual void Print(string const&data){s+=indent+data+"\n";}
};

class TMessage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMessage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<TType>,type,DEF,$,$)\
ADDVAR(int,mode,SET,mmRet,$)\
ADDEND()
//=====+>>>>>TEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====TEnvRTTI
public:
  enum TMode{
    mmBeg,
    mmRet,
    mmEnd
  };
};

class EnvTypeHolder{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvTypeHolder)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,FullName,DEF,$,$)\
ADDVAR(TProduct,Type,DEF,$,$)\
ADDVAR(TProduct,Factory,DEF,$,$)\
ADDEND()
//=====+>>>>>EnvTypeHolder
#include "QapGenStruct.inl"
//<<<<<+=====EnvTypeHolder
public:
  static void hack_move(TProduct&out,TRTTIProduct&inp)
  {
    out.Alloc=inp.GetAlloc();
    out.Factory=inp.GetFactory();
    out.Memory=std::move(inp.Memory);
    inp.pType=nullptr;
  }
  void eat(EnvType&item)
  {
    FullName=item.Type->GetFullName();
    hack_move(Type,item.Type.Product);
    if(item.Factory)hack_move(Factory,item.Factory.Product);
  }
  void boom()
  {
    Type.Free();
    if(Factory)Factory.Free();
  }
  TType*GetType(){return (TType*)Type.Memory.ptr;}
  IFactory*GetFactory(){return (IFactory*)Factory.Memory.ptr;}
};

class TEnvRTTI:public IEnvRTTI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TEnvRTTI)PARENT(IEnvRTTI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<EnvType>,Arr,DEF,$,$)\
ADDVAR(THardPtr<IAllocator>,Alloc,DEF,$,$)\
ADDVAR(UniqueID,ID,DEF,$,$)\
ADDVAR(vector<TMessage>,messages,DEF,$,$)\
ADDVAR(THardPtr<IEnvRTTI>,OwnerEnv,DEF,$,$)\
ADDEND()
//=====+>>>>>TEnvRTTI
#include "QapGenStruct.inl"
//<<<<<+=====TEnvRTTI
public:
  static void SysHasSelf();
public:
  string GetTypeFullNames()
  {
    string tmp;
    for(int i=0;i<Arr.size();i++)
    {
      if(i)tmp+=",\n";
      tmp+=Arr[i].Type->GetFullName();
    }
    return std::move(tmp);
  }
  void PrintLog(const string&fn="outlog.cpp")
  {
    CrutchIO io;
    TPrinter printer(io.mem);
    for(int i=0;i<messages.size();i++)
    {
      TMessage&EX=messages[i];
      TType*Info=EX.type.get();
      if(EX.mode==TMessage::mmBeg){
        printer.Print("Register(\""+Info->GetFullName()+"\")");
        printer.Print("{");
        printer.Indent();
      }
      if(EX.mode==TMessage::mmRet){
        printer.Print("Ret(\""+Info->GetFullName()+"\");");
      }
      if(EX.mode==TMessage::mmEnd){
        printer.Outdent();
        printer.Print("}//"+Info->GetFullName());
      }
    }
    io.SaveFile(fn);
  }
  void OnRegBeg(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmBeg;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegRet(TType*Info)
  {
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmRet;
    messages.emplace_back(std::move(tmp));
  };
  void OnRegEnd(TType*Info){
    TMessage tmp;
    tmp.type=Info;
    tmp.mode=TMessage::mmEnd;
    messages.emplace_back(std::move(tmp));
  };
public:
  IAllocator*GetAlloc(){return Alloc.get();}
  virtual int RegInfo(TAutoPtr<TType>&&_Right)
  {
    EnvType tmp;
    tmp.Type=std::move(_Right);
    Arr.push_back(std::move(tmp));
    return Arr.size()-1;
  }
  virtual EnvType&GetEnvTypeById(int id)
  {
    return Arr[id];
  }
  virtual vector<EnvType>&GetArr(){
    return Arr;
  }
  ~TEnvRTTI(){clear();}
public:
  IEnvRTTI*GetOwnerEnv()
  {
    return OwnerEnv.get();
  }
public:
  void update()
  {
    QapCleanIf(Arr,[](EnvType&ex){return !ex.Type;});
  }
  bool IsValid()
  {
    for(int i=Arr.size()-1;i>=0;i--)
    {
      auto&ex=Arr[i].Type;
      if(!ex)
      {
        int temp=0;
        QapDebugMsg("fail");
        return false;
      }
    }
    return true;
  }
  void clear()
  {
    if(!IsValid())
    {
      QapDebugMsg("fail");
      update();
      QapAssert(IsValid());
    }
    unlink();
    int skip_count=0;
    for(int i=Arr.size()-1;i>=0;i=i?--i:i=Arr.size()-1)
    {
      skip_count++;
      auto&item=Arr[i];
      TAutoPtr<TType>&ex=item.Type;
      auto&nm=ex->Info.Name;
      auto&fn=ex->GetFullName();
      bool skip=!ex->CanDestroy();
      if(skip&&skip_count>Arr.size())break;
      if(skip)continue;
      item.Type=nullptr;
      item.Factory=nullptr;
      std::swap(item,Arr.back());
      Arr.pop_back();
      skip_count=0;
    }
    //CleanIf(Arr,[](EnvType&ex){return !ex.Type;});
    if(!Arr.empty())
    {
      PrintCur();
      QapAssert(Arr.empty());
      Arr.clear();
    }
  }
  //typedef vector<std::pair<string,TSaver_yEd::Container>> TScope_UG;
  static inline bool IsLegalChar(const unsigned char&c){
    return InDip<char>('a',c,'z')||InDip<char>('A',c,'Z')||InDip<char>('0',c,'9');
  }
  static string string2xml(const string&str)
  {
    string tmp;tmp.reserve(str.size()*3);
    for(int i=0;i<str.size();i++){
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"&#"+IToS(str[i])+";";
    }
    return std::move(tmp);
  }
  void PrintCur()
  {
    QAP_LOG("---PrintCur---");
    for(int i=0;i<Arr.size();i++)
    {
      TAutoPtr<TType>&EX=Arr[i].Type;
      TType*pVal=EX.get();
      TType*pType=EX.Product.GetType();
      IAllocator*pAlloc=EX.Product.GetAlloc();
      IFactory*pFactory=EX.Product.GetFactory();
      auto&fn=EX->GetFullName();
      QAP_LOG("["+IToS(EX->Self.P.HardCount)+"]"+fn);
    }
  }
  static void add_sniper_job(THardClientSpace&Space,TRawPtr&raw_ptr)
  {
    THardClientPtrGraber Graber(Space);
    TSmartPtrVisitor CPG(Graber,raw_ptr.pValue);
    raw_ptr.pType->Use(CPG);
  }
  void unlink()
  {
    if(Arr.empty())return;
    THardClientSpace Space;
    //ставим цели для снайперов
    for(int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      TRawPtr type(item.Type.Product.pType.get(),item.Type.get());
      add_sniper_job(Space,type);
      if(!item.Factory)continue;
      TRawPtr fact(item.Factory.Product.pType.get(),item.Factory.get());
      add_sniper_job(Space,fact);
    }
    //говорим метатипам метатипов, что мол всё хорошо и под контролем.
    //а сами отвязываем метатипы от владеющего указателя и привзываем к бочке с порохом.
    vector<EnvTypeHolder> holders;
    holders.resize(Arr.size());
    for(int i=0;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      auto&holder=holders[i];
      holder.eat(item);
    };
    //выбрасываем старые держатели метатипов
    Arr.clear();
    //снайперы снимают шляпы.
    Space.Do();
    //взрываем бочки с порохом.
    int skip_count=0;
    for(int i=int(holders.size())-1;skip_count<=int(holders.size());skip_count++,i=(!i?holders.size()-1:i-1))
    {
      auto&holder=holders[i];
      auto*pType=holder.GetType();
      bool skip=!pType->CanDestroy();
      if(skip)
      {
        QapDebugMsg("type : '"+holder.FullName+"'\nWTF?");
        continue;
      }
      //QAP_LOG(fn);
      holders[i].boom();
      std::swap(holder,holders.back());
      holders.pop_back();
      skip_count=0;
    }
    if(!holders.empty())
    {
      for(int i=0;i<holders.size();i++)
      {
        auto&holder=holders[i];
        auto&fn=holder.FullName;
        TType*pType=holder.GetType();
        int hc=pType->Self.P.HardCount;
        QAP_LOG("["+IToS(hc)+"]  "+fn);
      }
      bool please_no=true;
      QapAssert(holders.empty());
      holders.clear();//build a memory leak? lol
    }
  }
};

static TType*FindTypeByFullName(IEnvRTTI&Env,const string&FullName)
{
  auto&arr=Env.GetArr();
  for(int i=0;i<arr.size();i++)
  {
    auto*p=arr[i].Type.get();
    if(p->GetFullName()==FullName)
    {
      return p;
    }
  }
  return nullptr;
}