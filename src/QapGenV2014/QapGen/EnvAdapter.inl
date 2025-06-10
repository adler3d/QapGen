struct EnvVoidPtr
{
  typedef TServerPtr<IEsoteric>ptr_t;
  ptr_t*ptr;
  TType*type;
  EnvVoidPtr():ptr(nullptr),type(nullptr){};
  EnvVoidPtr(ptr_t*ptr,TType*type=nullptr):ptr(ptr),type(type){}
  ptr_t::ptr_t*get()const{return ptr?ptr->ptr:nullptr;}
  bool IsValid()const{return bool(ptr)&&bool(type);}
  bool IsNull()const{return bool(!ptr)&&bool(!type);}
  template<class TYPE>
  void set(const TAutoPtr<TYPE>&ref)
  {
    ptr=nullptr;
    type=nullptr;
    if(!ref)return;
    ptr=(ptr_t*)(void*)&ref.get()->Self;
    type=ref.Product.pType.get();
  }
  void set_zero(){ptr=nullptr;type=nullptr;}
  bool operator==(const EnvVoidPtr&ref)const{return oper_eq(ref);}
  bool operator!=(const EnvVoidPtr&ref)const{return !oper_eq(ref);}
  bool oper_eq(const EnvVoidPtr&ref)const
  {
    return (this->ptr==ref.ptr)&&(this->type==ref.type);
  }
  //template<class TYPE>
  //void set(TSelfPtr<TYPE>&ref){ptr=(ptr_t*)&ref.P;}
};

class EnvItem{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(EnvItem)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,id,SET,0,$)\
ADDVAR(EnvVoidPtr,ptr,DEF,$,$)\
ADDVAR(EnvVoidPtr,ptr_lnk,DEF,$,$)\
ADDVAR(string,name,SET,"",$)\
ADDVAR(int,count,SET,0,$)\
ADDVAR(bool,passed,SET,false,$)\
ADDVAR(bool,system,SET,false,$)\
ADDVAR(bool,hidden,SET,false,$)\
ADDEND()
//=====+>>>>>EnvItem
#include "QapGenStruct.inl"
//<<<<<+=====EnvItem
public:
  EnvItem&copy(const EnvItem&source)
  {
    //hard code detected
    #define F(FIELD)this->FIELD=source.FIELD;
    F(id)F(name)F(ptr)F(ptr_lnk)F(count)F(passed)F(system)F(hidden)
    #undef F
    return *this;
  }
  void CheckNullptr()
  {
    QapAssert(id==0);
    QapAssert(ptr.IsNull());
    QapAssert(ptr_lnk.IsNull());
    QapAssert(name=="nullptr");
    QapAssert(count==1);
    QapAssert(passed==true);
    QapAssert(system==true);
    QapAssert(hidden==false);
  }
  bool oper_eq(const SelfClass&ref,bool ignore_id=false)const
  {
    bool result=ignore_id||(this->id==ref.id);
    #define F(FIELD)result=result&&(this->FIELD==ref.FIELD);
    //`F(id)   See: bool result=ignore_id||(this->id==ref.id);
    F(name)F(ptr)F(ptr_lnk)F(count)F(passed)F(system)F(hidden)
    #undef F
    return result;
  }
  bool operator==(const SelfClass&ref)const{return oper_eq(ref);}
  bool IsNoUsed()
  {
    return id&&ptr.IsNull()&&ptr_lnk.IsNull();
  }
  void SetAsNullptr()
  {
    name="nullptr";
    count=1;
    passed=true;
    system=true;
    hidden=false;
  }
  template<class TYPE>
  EnvItem&weak_get_lnk(TServerPtrSpace&Space)const
  {
    QapAssert(ptr_lnk.IsValid());
    int SID=ptr_lnk.ptr->SaveID;
    QapAssert(Space.IsAllowed(SID));
    auto&item=Space[SID];
    QapAssert(this->ptr_lnk.ptr==item.ptr.ptr);
    QapAssert(this->ptr_lnk.type==item.ptr.type);
    return item;
  }
  EnvItem&get_lnk(TServerPtrSpace&Space)const{return weak_get_lnk<void>(Space);}
};

struct SpaceMutator
{
  vector<EnvVoidPtr::ptr_t*> arr;
  int find_key_by_value(EnvVoidPtr::ptr_t*ptr)
  {
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i]==ptr)return i;
    }
    return -1;
  }
  bool has_value(EnvVoidPtr::ptr_t*ptr)
  {
    return find_key_by_value(ptr)!=-1;
  }
};

class TServerPtrSpace{
public:
  typedef TServerPtrSpace SelfClass;
public:
  vector<EnvItem> Arr;
public:
  void operator=(SelfClass&&Ref)
  {
    clear();
    //hard code detected
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace(SelfClass&&Ref)
  {
    clear();
    //hard code detected
    Arr=std::move(Ref.Arr);
  }
  TServerPtrSpace()
  {
    Arr.reserve(1024*128);
    auto&ex=UnsafeAdd(nullptr,nullptr);
    ex.SetAsNullptr();
  }
  ~TServerPtrSpace(){clear();}
public:
  void hack_clear()
  {
    for(int i=0;i<Arr.size();i++)
    {
      Del(Arr[i],true);
    }
    Arr.clear();
  }
  void clear()
  {
    for(int i=0;i<Arr.size();i++)
    {
      Del(Arr[i]);
    }
    Arr.clear();
  }
public:
  static void make_linked(EnvItem&a,EnvItem&b)
  {
    bool f0=a.ptr_lnk.IsNull();
    bool f1=b.ptr_lnk.IsNull();
    QapAssert(f0&&f1);
    a.ptr_lnk=b.ptr;
    b.ptr_lnk=a.ptr;
  };
public:
  bool CheckServTID(int tid)
  {
    if(!IsAllowed(tid))return false;
    auto&item=Arr[tid];
    bool flag=true;
    flag=item.ptr.ptr;
    QapAssert(flag);
    flag=tid==item.ptr.ptr->SaveID;
    QapAssert(flag);
    return flag;
  }
  bool CheckServSaveID(TServerPtr<IEsoteric>*pServ=nullptr)const
  {
    QapAssert(pServ);
    int SaveID=pServ->SaveID;
    {
      bool flag=(SaveID>0)&&(SaveID<Arr.size());
      if(!flag){
        QapAssert(!SaveID);
        return false;
      }
    }
    auto&ex=Arr[SaveID];
    bool flag=ex.ptr.ptr==pServ;
    QapAssert(flag);
    return flag;
  }
  EnvItem&UnsafeAdd(const EnvVoidPtr&ptr)
  {
    // mod time : 29.06.2012
    int id=Arr.size();
    {
      if(id>=Arr.capacity())QapDebugMsg("grow are not allowed here.\n"+IToS(Arr.capacity()));
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    auto*pServ=ptr.ptr;
    if(pServ)pServ->SaveID=id;
    back.id=id;
    back.ptr=ptr;
    return back;
  }
  EnvItem&Insert(const EnvItem&item)
  {
    // mod time : 05.07.2012
    int id=Arr.size();
    {
      EnvItem tmp;
      Arr.push_back(std::move(tmp));
    }
    auto&back=Arr.back();
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if(!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    //neverconnect(back.ptr_adv);
    return back;
  }
  EnvItem&InsertTo(int id,const EnvItem&item)
  {
    auto&back=Arr[id];
    QapAssert(back.IsNoUsed());
    back.copy(item).id=id;
    auto connect=[id](EnvVoidPtr&ptr)->void
    {
      auto*p=ptr.ptr;
      if(!p)return;
      int&sid=p->SaveID;
      QapAssert(!sid);
      sid=id;
    };
    connect(back.ptr);
    //neverconnect(back.ptr_adv);
    return back;
  }
  EnvItem&UnsafeAdd(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr)
  {
    return UnsafeAdd(EnvVoidPtr(pServ,pType));
  }
  EnvItem&AddExt(TServerPtr<IEsoteric>*pServ=nullptr,TType*pType=nullptr,const string&name="")
  {
    QapAssert(pServ);
    if(true)
    {
      bool flag=CheckServSaveID(pServ);
      if(flag)
      {
        QapAssert(false);
        return Arr[pServ->SaveID];
      }
    }
    auto&back=UnsafeAdd(pServ,pType);
    back.name=name;
    return back;
  }
  void Del(EnvItem&item,bool hack_mode=false)
  {
    Del(item.ptr.ptr,hack_mode);
  }
  void Del(TServerPtr<IEsoteric>*pServ,bool hack_mode=false)
  {
    // mod time : 01.08.2012
    if(!pServ)return;
    QapAssert(pServ->SaveID);
    {
      const int&id=pServ->SaveID;
      QapAssert(IsAllowed(id));
      auto&ex=Arr[id];
      QapAssert(ex.id==id);
      if(1)
      {
        bool f[]={
          ex.ptr.ptr==pServ,
          ex.ptr_lnk.ptr==pServ
        };
        QapAssert(f[0]!=f[1]);
      }
      ex.ptr=nullptr;
      if(!hack_mode)if(ex.ptr_lnk.ptr)
      {
        QapAssert(ex.ptr_lnk.ptr->SaveID!=id);
      }
      ex.ptr_lnk=nullptr;
    }
    pServ->SaveID=0;
  }
  EnvVoidPtr::ptr_t*GetPtrByID(int id){return Arr[id].ptr.ptr;}
  EnvVoidPtr::ptr_t*GetAdvPtrByID(int id){return Arr[id].ptr_lnk.ptr;}
public:
  //Item&operator[](const EnvItem&index){return Arr[index.id];}
  //const Item&operator[](const EnvItem&index)const{return Arr[index.id];}
  EnvItem&operator[](int index){return Arr[index];}
  const EnvItem&operator[](int index)const{return Arr[index];}
public:
  template<class TYPE>
  EnvItem&operator[](const TSelfPtr<TYPE>&index){
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
  template<class TYPE>
  const EnvItem&operator[](const TSelfPtr<TYPE>&index)const{
    const int&id=index.P.SaveID;
    QapAssert(id&&IsAllowed(id));
    return Arr[id];
  }
public:
  bool IsAllowed(int index){
    return (0<=index)&&(index<Arr.size());
  }
  bool IsSolved(int index){
    return IsAllowed(index)&&(Arr[index].ptr.ptr);
  }
  int size(){return Arr.size();}
public:
  void resize(int count)
  {
    QapAssert(count>=size());
    for(int i=size();i<count;i++)
    {
      UnsafeAdd(nullptr,nullptr);
    }
  }
public:
  void Repack()
  {
    //Эта штука выбрасывает из Arr все EnvItem'ы у которых count==0.
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    for(int i=0;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if(!item.count)continue;
      {
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
  }
  /*
    RepackV2 разделяет одно пространство на два.
    примечание:
      нулевой элемент во всех проастарнства - nullptr. nullptr`ы мы не трогаем.

    Space0.size() == N.
    Space1.size() == X.
    Space2.size() == N.

    Space0: все N - элементов исправны.
    Space1: все X - элементов исправны.
    Space2: превые X - элементов не исправны. остальные исправны.

    Space0: this - до RepackV2
    Space1: this - после RepackV2
    Space2: Out - после RepackV2
  */
  void RepackV2(SelfClass&Out)
  {
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space=std::move(TSpace());
    Out=std::move(TSpace());
    Out.resize(tmpSpace.size());
    int X=1;for(int i=1;i<tmpSpace.size();i++)if(tmpSpace[i].count)X++;
    for(int i=1;i<tmpSpace.size();i++)
    {
      auto&item=tmpSpace[i];
      if(!item.count)
      {
        auto&space=Out;
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.InsertTo(X,temp);
        QapAssert(&back==&space[back.id]);
        X++;
        continue;
      }
      if(item.count)
      {
        auto&space=Space;
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        auto&back=space.Insert(temp);
        QapAssert(&back==&space[back.id]);
        continue;
      }
    }
  }
public:
  void Mutate(SpaceMutator&SM)
  {
    //Эта штука выбрасывает из Arr все EnvItem'ы у которых count==0.
    typedef TServerPtrSpace TSpace;
    TSpace&Space=*this;
    TSpace tmpSpace=std::move(Space);
    Space.reserve(tmpSpace.size());
    auto func=[&tmpSpace,&Space](int i)
    {
      auto&item=tmpSpace[i];
      if(item.id==-1)return;
      EnvItem temp; temp.copy(item);
      tmpSpace.Del(item);
      auto&back=Space.Insert(temp);
      QapAssert(&back==&Space[back.id]);
    };
    func(0);
    auto&arr=SM.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      QapAssert(ex->SaveID);
      QapAssert(tmpSpace.IsAllowed(ex->SaveID));
      auto&item=tmpSpace[ex->SaveID];
      QapAssert(item.id>0);
      QapAssert(item.id==ex->SaveID);
      //if(!item.count)continue;
      {
        EnvItem temp; temp.copy(item);
        tmpSpace.Del(item);
        item.id=-1;
        auto&back=Space.Insert(temp);
        QapAssert(&back==&Space[back.id]);
      }
    }
    for(int i=1;i<tmpSpace.size();i++)func(i);
  }
public:
  void CopyAdvFrom(SelfClass&Source)
  {
    QapDebugMsg("deprecated");
    auto&arr=Source.Arr;
    clear();
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      //string&name=Source[ex.ptr_adv.ptr->SaveID].name;
      auto name=ex.name+"->getLink()";
      AddExt(ex.ptr_lnk.ptr,ex.ptr_lnk.type,name);
    }
  }
  void CopyAdvFromV2(SelfClass&Source,SelfClass&BigSpace)
  {
    auto&arr=Source.Arr;
    (*this)=std::move(SelfClass());
    for(int i=1;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.ptr_lnk.IsNull())
      {
        EnvItem tmp;
        Insert(tmp);
        continue;
      }
      auto&item=BigSpace[ex.ptr_lnk.ptr->SaveID];
      EnvItem temp;
      temp.copy(item);
      BigSpace.Del(item);
      Insert(temp);
    }
  }
public:
  void Swap(int A,int B)
  {
    //QapAssert(A!=B);
    if(A==B)return;
    EnvItem ta;
    EnvItem tb;
    auto&Space=*this;
    auto&a=Space[A];
    auto&b=Space[B];
    ta.copy(a);
    tb.copy(b);
    Del(a);
    Del(b);
    InsertTo(A,tb);
    InsertTo(B,ta);
  }
public:
  template<class TYPE>
  static void ClientMarker(TYPE&Space,TType*pType,void*pValue)
  {
    ::ClientMarker(Space,pType,pValue);
  }
public:
  template<class TYPE>
  void SolveDepends(TYPE&temp)
  {
    static_assert(std::is_same<DependsSolver,TYPE>::value,"error");
    temp.SolveDepends(*this);
  }
public:
  string GetListOfNoPassed(bool all)
  {
    string log;
    auto&arr=Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(!all)if(!ex.count||ex.passed)continue;
      log+=ex.name+"\n";
    }
    return log;
  };
  bool CheckHidden()
  {
    int errors=0;
    auto&arr=Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&item=arr[i];
      if(item.hidden&&item.count)
      {
        QapDebugMsg("item(\""+item.name+"\").count = "+IToS(item.count));
        errors++;
      }
    }
    return !errors;
  };
    
public:
  EnvItem*find_by_name(const string&name)
  {
    for(int i=0;i<size();i++)
    {
      EnvItem&EX=Arr[i];
      if(name==EX.name)return &EX;
    }
    return nullptr;
  }
public:
  bool IsValid()
  {
    if(Arr.empty())
    {
      QapAssert("undefine behevior. also: may be true");
      return true;
    }
    Arr[0].CheckNullptr();
    for(int i=1;i<Arr.size();i++)
    {
      auto&item=Arr[i];
      if(!item.ptr.type&&!item.ptr.ptr)return false;
      if(1)
      {
        bool flag=bool(item.ptr_lnk.ptr)==bool(item.ptr_lnk.type);
        if(!flag)return false;
      }
    }
    return true;
  }
public:
  void reserve(int _Count)
  {
    Arr.reserve(_Count);
  }
public:
  void AddPointsFromSys()
  {
    weak_detail<void>::AddPointsFromSys(*this);
  }
  void AddPointsFromEnv(IEnvRTTI&Env)
  {
    weak_detail<void>::AddPointsFromEnv(*this,Env);
  }
  void AddPointsFrom(const TRawPtr&ptr)
  {
     weak_detail<void>::AddPointsFrom(*this,ptr);
  }
  void UpdatePointsTypeFrom(const TRawPtr&ptr)
  {
    weak_detail<void>::UpdatePointsTypeFrom(*this,ptr);
  }
  template<class TYPE>
  struct weak_detail
  {
    static void AddPointsFromSys(TServerPtrSpace&Space)
    {
      EnvAdapter::GoSys(Space);
    }
    static void AddPointsFromEnv(TServerPtrSpace&Space,IEnvRTTI&Env)
    {
      EnvAdapter::GoEnv(Space,Env,EnvAdapter::TMetaTypePack(Env));
    }
    static void AddPointsFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      GrabServerPtr(Space,ptr.pType,ptr.pValue,true);
    }
    struct UnnamedStruct
    {
      typedef TServerPtrSpace TSpace;
      TSpace&Space;
      UnnamedStruct(TSpace&Space):Space(Space){}
      void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
      {
        if(!Space.CheckServSaveID(&Serv))
        {
          QapDebugMsg("bad news");return;
        }
        auto&ex=Space[Serv.SaveID];
        QapAssert(elemType);
        if(ex.ptr.type==elemType)
        {
          QapAssert(elemType);
          QapAssert(!ex.ptr.type);
          return;
        }
        ex.ptr.type=elemType;
      }
    };
    static void UpdatePointsTypeFrom(TServerPtrSpace&Space,const TRawPtr&ptr)
    {
      class TServerPtrTypeUpdater:public TSmartPtrVisitor::ICallBack{
      public:
        UnnamedStruct Field;
        TServerPtrTypeUpdater(TServerPtrSpace&Space):Field(Space){}
      public:
        void Visit(TServerPtr<IEsoteric>&Serv,TType*elemType)
        {
          Field.Visit(Serv,elemType);
        }
        void Visit(TClientPtr<IEsoteric>&A,TType*elemType){}
        void Visit(THardClientPtr<IEsoteric>&A,TType*elemType){}
        void Visit(TClientPtr<IEsoteric>&A){}
        void Visit(THardClientPtr<IEsoteric>&A){}
      };
      TServerPtrTypeUpdater Updater(Space);
      TSmartPtrVisitor SPG(Updater,ptr.pValue);
      ptr.pType->Use(SPG);
    }
  };
};

class TBigMetaTypePack{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TBigMetaTypePack)
#define DEF_PRO_METATYPE_LIST(ADDBEG,ADDTYPE,ADDEND)\
ADDBEG()\
ADDTYPE(EnvType)\
ADDTYPE(TType)\
ADDTYPE(TTypeStruct)\
ADDTYPE(TTypeSys)\
ADDTYPE(DeclareType)\
ADDTYPE(DeclareTypeStruct)\
ADDTYPE(DeclareTypeSys)\
ADDEND()
//=====+>>>>>TBigMetaTypePack
#include "QapGenTypePack.inl"
//<<<<<+=====TBigMetaTypePack
};

class EnvAdapter{
public:
  template<class TYPE>
  static TServerPtr<IEsoteric>*get(TSelfPtr<TYPE>&ref){
    return (TServerPtr<IEsoteric>*)&ref.P;
  }
public:
  class TMetaTypePack{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TMetaTypePack)
  #define DEF_PRO_METATYPE_LIST(ADDBEG,ADDTYPE,ADDEND)\
  ADDBEG()\
  ADDTYPE(TType)\
  ADDTYPE(TTypeStruct)\
  ADDEND()
  //=====+>>>>>TMetaTypePack
  #include "QapGenTypePack.inl"
  //<<<<<+=====TMetaTypePack
  };
public:
  TType*FindTypeByFactory(IEnvRTTI&Env,IFactory*pFactory)
  {
    auto&arr=Env.GetArr();
    for(int i=0;i<arr.size();i++)
    {
      auto*pType=arr[i].Type.get();
      if(pType->Factory.get()==pFactory)return pType;
    }
    return nullptr;
  }
  TType*FindTypeByFactoryFast(IEnvRTTI&Env,TServerPtrSpace&Space,IFactory*pFactory)
  {
    auto&ptr_lnk=Space[pFactory->Self].ptr_lnk;
    if(ptr_lnk.IsNull()){
      ptr_lnk=Space[FindTypeByFactory(Env,pFactory)->Self].ptr;
    }
    if(ptr_lnk.IsValid())return (TType*)ptr_lnk.get();
    return nullptr;
  }
public:
  static void GoV3(TServerPtrSpace&Space,IEnvRTTI&Env)
  {
    GoV2(Space,Env,TMetaTypePack(Env));
  }
  static void GoV2(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    Space.reserve(2048);
    {
      auto*it=&Env;
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env]");
      ex.system=true;
      ex.hidden=true;
    }
    {
      IEnvRTTI&env=Env;
      auto*it=env.GetAlloc();
      auto&ex=Space.AddExt(get(it->Self),nullptr,"[Env.GetAlloc()]");
      ex.system=true;
      ex.hidden=true;
    }
    GoSys(Space);
    GoEnv(Space,Env,TypePack);
  }
  static void GoSys(TServerPtrSpace&Space)
  {
    GoFactory(Space);
    GoCppIO(Space);
    GoBinIO(Space);
    GoVectorAPI(Space);
  }
  static void GoFactory(TServerPtrSpace&Space)
  {
    auto&Arr=TFactory<void>::GetFactorys();
    for(int i=0;i<Arr.size();i++)
    {
      IFactory*it=Arr[i].get();
      string name="TFactory<"+it->GetElementTypeFullName()+">::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoCppIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadCppIO<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadCppIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoBinIO(TServerPtrSpace&Space)
  {
    auto&Arr=THeadBinIO<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="THeadBinIO<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  static void GoVectorAPI(TServerPtrSpace&Space)
  {
    auto&Arr=TVectorAPI<void>::GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      auto*it=Arr[i].get();
      string name="TVectorAPI<...hidden...>::Get()";
      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
      ex.system=true;
      ex.hidden=true;
    }
  }
  //template<class QAP_RTTI>
  //static void Go(TServerPtrSpace&Space,QAP_RTTI&Env)
  //{
  //  QapDebugMsg("deprecated");
  //  QapDebugMsg("see GoV2");
  //  Space.reserve(2048);
  //  {
  //    QAP_RTTI*it=&Env;
  //    auto&ex=Space.AddExt(get(it->Self),Sys$$<QAP_RTTI>::GetRTTI(Env),"[Env]");
  //    ex.system=true;
  //    ex.hidden=true;
  //  }
  //  {
  //    IEnvRTTI&env=Env;
  //    auto*it=env.GetAlloc();
  //    auto&ex=Space.AddExt(get(it->Self),Sys$$<IAllocator>::GetRTTI(Env),"[Env.GetAlloc()]");
  //    ex.system=true;
  //    ex.hidden=true;
  //  }
  //  {
  //    auto&Arr=TFactory<void>::GetFactorys();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      IFactory*it=Arr[i].get();
  //      string name="TFactory<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=THeadCppIO<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="THeadCppIO<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=THeadBinIO<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="THeadBinIO<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  if(true)
  //  {
  //    auto&Arr=TVectorAPI<void>::GetArr();
  //    for(int i=0;i<Arr.size();i++)
  //    {
  //      auto*it=Arr[i].get();
  //      string name="TVectorAPI<"+it->GetElementType(Env)->GetFullName()+">::Get()";
  //      auto&ex=Space.AddExt(get(it->Self),nullptr,name);
  //      ex.system=true;
  //      ex.hidden=true;
  //    }
  //  }
  //  GoEnv(Space,Env,TMetaTypePack((IEnvRTTI&)Env));
  //};
  static void GoEnv(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      string name="Sys$$<"+it->GetFullName()+">::GetRTTI()";
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      Space.AddExt(get(it->Self),type,name).system=system;
    }
  }
  static void FixEnvType(TServerPtrSpace&Space,IEnvRTTI&Env,TMetaTypePack&TypePack)
  {
    auto*pTType=TypePack.pTType;
    auto*pTTypeStruct=TypePack.pTTypeStruct;
    auto&Arr=Env.GetArr();
    for(int i=0;i<Arr.size();i++)
    {
      TType*it=Arr[i].Type.get();
      TType*type=Arr[i].Type.Product.pType.get();
      QapAssert(IsBasedOn(type,pTType));
      bool flag1=IsBasedOn(type,pTTypeStruct);
      bool flag2=IsBasedOn(it,pTType);
      bool system=!flag1||flag2;
      auto&item=Space[it->Self];
      item.system=false;
    }
  }
  static bool IsFactoryEqual(TType*p,TType*b)
  {
    return p->Factory.get()==b->Factory.get();
  }
  static bool IsBasedOn(TType*p,TType*base)
  {
    if(IsFactoryEqual(p,base))return true;
    TType*subtype=p->GetSubType();
    return subtype?IsBasedOn(subtype,base):false;
  }
};