template<class TYPE>
struct QapDeclareDetail
{
  //typedef TYPE Impl;
  static string GetFullName(const DeclareType*ptr)
  {
    //typedef DeclareDetail Impl;
    DeclareDetail::GetFullName GFN;
    DeclareType*p=(DeclareType*)ptr;
    p->Use(GFN);
    return GFN.fullname;
  }
  static DeclareType*GetSubType(const DeclareType*ptr)
  {
    auto*p=DeclareTypeStruct::UberCast((DeclareType*)ptr);
    return p?p->SubType.get():nullptr;
  }
  static bool IsBasedOn(const DeclareType*ptr,const DeclareType*A)
  {
    if(ptr==A)return true;
    auto*subtype=ptr->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};

//struct IDeclareVisitorRTTI{};

class DeclareType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareType
#include "QapGenStruct.inl"
//<<<<<+=====DeclareType
public:
  static void SysHasSelf();
public:
  virtual void Use(IDeclareVisitorRTTI&){QapDebugMsg("no way.");}
  string GetFullName()const
  {
    return QapDeclareDetail<void>::GetFullName(this);
  }
  DeclareType*GetSubType()const
  {
    return QapDeclareDetail<void>::GetSubType(this);
  }
  bool IsBasedOn(const DeclareType*A)const
  {
    return QapDeclareDetail<void>::IsBasedOn(this,A);
  }
};
#define DEF_PRO_INJECTION()\
  void Use(IDeclareVisitorRTTI&A){A.Do(this);}\
  static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};

class DeclareTypeSys:public DeclareType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeSys)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,FullName,SET,"unnamed",$)\
ADDEND()
//=====+>>>>>DeclareTypeSys
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeSys
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeSelfPtr:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeSelfPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeSelfPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeSelfPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeAutoPtr:public DeclareType
{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeAutoPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeAutoPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeAutoPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeWeakPtr:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeWeakPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeWeakPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeWeakPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeHardPtr:public DeclareType
{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeHardPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeHardPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeHardPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeFieldPtr:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeFieldPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>DeclareTypeFieldPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeFieldPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeVoidPtr:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeVoidPtr)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>DeclareTypeVoidPtr
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeVoidPtr
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeVector:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeVector)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeVector
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeVector
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareTypeArray:public DeclareType
{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeArray)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TWeakPtr<DeclareType>,ElementType,DEF,$,$)\
ADDVAR(int,Size,SET,0,$)\
ADDEND()
//=====+>>>>>DeclareTypeArray
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeArray
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class DeclareMember{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareMember)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(TWeakPtr<DeclareType>,Type,DEF,$,$)\
ADDVAR(string,Mode,DEF,$,$)\
ADDVAR(string,Value,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareMember
#include "QapGenStruct.inl"
//<<<<<+=====DeclareMember
public:
  bool IsEqual(SelfClass&other)
  {
    QapDebugMsg("no way.");
  }
};

class DeclareTypeStruct:public DeclareType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(DeclareTypeStruct)PARENT(DeclareType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(TWeakPtr<DeclareType>,SubType,DEF,$,$)\
ADDVAR(TWeakPtr<DeclareType>,OwnType,DEF,$,$)\
ADDVAR(vector<DeclareMember>,Members,DEF,$,$)\
ADDEND()
//=====+>>>>>DeclareTypeStruct
#include "QapGenStruct.inl"
//<<<<<+=====DeclareTypeStruct
public:
  DEF_PRO_INJECTION()
  //void Use(IDeclareVisitorRTTI&A){A.Do(this);}
  //static SelfClass*UberCast(DeclareType*ptr){return IDeclareVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  bool TestField(const DeclareMember&it,int depth=0)
  {
    if(SubType)
    {
      auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if(!result)return result;
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
      #define DEF_LIST(F)F(Name)//F(Number)//F(Offset)F(Mode)
      #define F(NAME)#NAME,
        static string idToStr[]={DEF_LIST(F)};
      #undef F
      const int cmp_n=lenof(idToStr)-(depth?1:0);
      #define F(NAME)if(cmp_id<cmp_n){if(it.NAME==ex.NAME)break;cmp_id++;;}
        do{DEF_LIST(F);}while(false);
      #undef F
      #undef DEF_LIST
      if(cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        string fn=GetFullName();
        if(tmp=="Name")if(it.Name=="Self")if(fn=="QapWinProgram")continue;
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
  DeclareMember*GetNearSelf()
  {
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(ex.Name!="Self")continue;
      auto*pFieldType=DeclareTypeSelfPtr::UberCast(ex.Type.get());
      QapAssert(pFieldType);
      QapAssert(pFieldType->ElementType.get()==this);
      return &ex;
    }
    auto*pSubType=DeclareTypeStruct::UberCast(GetSubType());
    return pSubType?pSubType->GetNearSelf():nullptr;
  }
  void AddField(DeclareMember&&field)
  {
    QapAssert(TestField(field));
    if(field.Name=="Self")
    {
      if(true)do
      {
        auto*type=DeclareTypeSelfPtr::UberCast(field.Type.get());
        QapAssert(type);
        if(this!=type->ElementType.get())
        {
          string fn=GetFullName();
          QapDebugMsg("field - \""+fn+"\"::"+field.Name+"\" has wrong type");
        }
      }while(false);
      if(GetNearSelf())do
      {
        auto*type=field.Type.get();
        auto*pSubType=DeclareTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
        #define F(SUBCLASS,CLASS)if(#SUBCLASS==subtype)if(#CLASS==fn)break;
          F(QapWinProgram,eWinProgram)
          F(QapWinProgram,QapProgramD3D9)
        #undef F
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }while(false);
    }
    Members.push_back(std::move(field));
  }
  void AddMember(DeclareType*MemType,const string&MemName,const string&Mode,const string&Value)
  {
    DeclareMember tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
};
#undef DEF_PRO_INJECTION

class DeclareDetail{
public:
  class StructTools{
  public:
    struct field_cmp_result_item{
      string fna;
      string fnb;
      int ida;
      int idb;
      void SetToDef(){
        ida=-1;
        idb=-1;
      }
    };
    static vector<field_cmp_result_item> CompareFieldsLists(const vector<DeclareMember>&A,const vector<DeclareMember>&B)
    {
      field_cmp_result_item tmp;
      tmp.SetToDef();
      vector<field_cmp_result_item> result;
      result.reserve(A.size()+B.size());
      vector<bool> passed;
      passed.resize(B.size(),false);
      for(int i=0;i<A.size();i++)
      {
        result.push_back(tmp);
        auto&ex=result.back();
        auto&ax=A[i];
        ex.ida=i;
        ex.fna=ax.Name;
        for(int j=0;j<B.size();j++)
        {
          if(passed[j])continue;
          auto&bx=B[j];
          if(ax.Name!=bx.Name)continue;
          ex.fnb=bx.Name;
          ex.idb=j;
          passed[j]=true;
        }
      }
      for(int j=0;j<B.size();j++)
      {
        if(passed[j])continue;
        result.push_back(tmp);
        auto&ex=result.back();
        auto&bx=B[j];
        ex.fnb=bx.Name;
        ex.idb=j;
        passed[j]=true;
      }
      return std::move(result);
    }
    static void Filter_RemoveEqual(vector<field_cmp_result_item>&arr)
    {
      vector<field_cmp_result_item> tmp;
      std::swap(tmp,arr);
      for(int i=0;i<tmp.size();i++)
      {
        auto&ex=tmp[i];
        if((ex.ida<0)!=(ex.idb<0))
        {
          arr.push_back(std::move(ex));
        }
      }
    }
    static string CompareFieldsLists_ToString(const vector<field_cmp_result_item>&arr)
    {
      string out;
      int n_a=[&]()->size_t{size_t n=0;for(size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fna.size(),n);return n;}();
      int n_b=[&]()->size_t{size_t n=0;for(size_t i=0;i<arr.size();i++)n=std::max<size_t>(arr[i].fnb.size(),n);return n;}();
      auto&f=[](const string&s,size_t n)->string{string tmp=s;for(size_t i=s.size();i<n;i++)tmp+=" ";return tmp;};
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        out+=f(ex.fna,n_a)+" = "+f(ex.fnb,n_b)+"\n";
      }
      return out;
    }
  };
public:
  class GetFullName:public IDeclareVisitorRTTI{
  public:
    string fullname;
  public:
    void Do(DeclareTypeSys*p)
    {
      fullname=p->FullName;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      string template_name="TSelfPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      string template_name="TAutoPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      string template_name="TWeakPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeHardPtr*p)
    {
      string template_name="THardPtr";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      string name="TVoidPtr";
      fullname=name;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      string name="TFieldPtr";
      fullname=name;
    }
    void Do(DeclareTypeVector*p)
    {
      string template_name="vector";
      fullname=template_name+"<"+p->ElementType->GetFullName()+">";
    }
    void Do(DeclareTypeArray*p)
    {
      string template_name="array";
      fullname=template_name+"<"+p->ElementType->GetFullName()+","+IToS(p->Size)+">";
    }
    void Do(DeclareTypeStruct*p)
    {
      string template_name="TSelfPtr";
      auto*pOwnType=p->OwnType.get();
      fullname=pOwnType?pOwnType->GetFullName()+"::"+p->Name:p->Name;
    }
  };
  class GetSubType:public IDeclareVisitorRTTI{
  public:
    DeclareType*pValue;
    GetSubType():pValue(nullptr){}
  public:
    void Do(DeclareTypeSys*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeHardPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeVector*p)
    {
      pValue=nullptr;
    }
    void Do(DeclareTypeStruct*p)
    {
      pValue=p->SubType.get();
    }
  };
  template<class TSPACE>
  class IsEqualTo:public IDeclareVisitorRTTI{
  public:
    TSPACE&Space;
    bool Result;
    DeclareType*pValue;
    bool Mute;
    IsEqualTo(TSPACE&Space):Space(Space),Result(false),pValue(nullptr),Mute(false){}
  public:
    struct EqualDetail
    {
      static bool Equal(TSPACE&Space,...){return false;}
      static bool Equal(TSPACE&Space,DeclareTypeSys*pA,DeclareTypeSys*pB,bool Mute)
      {
        return pA->FullName==pB->FullName;
      }
      static bool Equal(TSPACE&Space,DeclareTypeSelfPtr*pA,DeclareTypeSelfPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeAutoPtr*pA,DeclareTypeAutoPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeWeakPtr*pA,DeclareTypeWeakPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeHardPtr*pA,DeclareTypeHardPtr*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVoidPtr*pA,DeclareTypeVoidPtr*pB,bool Mute)
      {
        //QapDebugMsg("no way");
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeFieldPtr*pA,DeclareTypeFieldPtr*pB,bool Mute)
      {
        //QapDebugMsg("no way");
        return true;
      }
      static bool Equal(TSPACE&Space,DeclareTypeVector*pA,DeclareTypeVector*pB,bool Mute)
      {
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeArray*pA,DeclareTypeArray*pB,bool Mute)
      {
        if(pA->Size!=pB->Size)return false;
        return IsEqualFuncEx(Space,pA->ElementType.get(),pB->ElementType.get());
        return false;
      }
      static bool Equal(TSPACE&Space,DeclareTypeStruct*pA,DeclareTypeStruct*pB,bool Mute)
      {
        string fna=pA->GetFullName();
        string fnb=pB->GetFullName();
        bool flag=fna==fnb;
        if(!flag)return false;
        auto&A=pA->Members;
        auto&B=pB->Members;
        if(A.size()!=B.size())
        {
          string msg="type : \""+fna+"\"\n";
          msg+="A.size = "+IToS(A.size())+"\n";
          msg+="B.size = "+IToS(B.size())+"\n";
          if(!Mute)QapDebugMsg(msg);
          auto detail_result=StructTools::CompareFieldsLists(A,B);
          StructTools::Filter_RemoveEqual(detail_result);
          auto str_detail_result=StructTools::CompareFieldsLists_ToString(detail_result);
          if(!Mute)QapDebugMsg(msg+"\n"+str_detail_result);
          flag=false;
        }
        for(int i=0;i<std::min(A.size(),B.size());i++)
        {
          auto&a=A[i];
          auto&b=B[i];
          bool f[]=
          {
            a.Name==b.Name,
            a.Mode==b.Mode,
            a.Value==b.Value,
            //a.Type==b.Type
          };
          bool flag=true;
          for(int j=0;j<lenof(f);j++)
          {
            flag=flag&&f[j];
          }
          if(flag)
          {
            IsEqualTo<TSPACE> other(Space);
            other.Mute=Mute;
            other.pValue=a.Type.get();
            b.Type.get()->Use(other);
            flag=flag&&other.Result;
          }
          if(!flag)
          {
            if(!Mute)QapDebugMsg("type : \""+fna+"\"");
            return false;
          }
        }
        return flag;
      }
    };
    template<class TYPE>
    class IsEqual:public IDeclareVisitorRTTI{
    public:
      TSPACE&Space;
      TYPE*pInput;
      bool Result;
    bool Mute;
      IsEqual(TSPACE&Space):Space(Space),Result(false),pInput(nullptr),Mute(false){}
    public:
      void Do(DeclareTypeSys*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeSelfPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeAutoPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeWeakPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeHardPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVoidPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeFieldPtr*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeVector*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeArray*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
      void Do(DeclareTypeStruct*p)
      {
        Result=EqualDetail::Equal(Space,p,pInput,Mute);
      }
    };
    template<class TYPE>
    static bool IsEqualFunc(TSPACE&Space,TYPE*pInput,DeclareType*pValue,bool Mute)
    {
      static_assert(std::is_same<TSPACE,TServerPtrSpace>::value,"renamed?");
      TServerPtrSpace&space=Space;
      if(pInput==pValue)return true;
      bool fA=space.IsAllowed(pInput->Self.P.SaveID);
      bool fB=space.IsAllowed(pValue->Self.P.SaveID);
      if(!fA||!fB)
      {
        QapDebugMsg("no way");
        return false;
      }
      auto&eA=space[pInput->Self];
      auto&eB=space[pValue->Self];
      EnvItem&A=eA;
      EnvItem&B=eB;
      bool f[]=
      {
        A.ptr_lnk.IsValid(),
        B.ptr_lnk.IsValid(),
        A.ptr.get()==(void*)pInput,
        B.ptr.get()==(void*)pValue,
      };
      QapAssert(f[2]&&f[3]);
      if(f[0]&&f[1])
      {
        bool g0=A.ptr_lnk.get()==B.ptr.get();
        bool g1=B.ptr_lnk.get()==A.ptr.get();
        QapAssert(g0==g1);
        return g0&&g1;
      }
      if(!f[0]&&!f[1])
      {
        //так... тут надо поставить замочек, чтобы там внутри pValue->Use(Is); не вызвать этоже с теме же параметрами.
        QapAssert(!A.system&&!B.system);
        A.system=true;
        B.system=true;
        //так. это не даст пройтись дважды по одному маршруту.
        //но мы не можем блокировать оба объекта для любых вызовов.
        //мы можем заблокировать только для этого же вызова.
        //готово.
        IsEqual<TYPE> Is(space);
        Is.pInput=pInput;
        Is.Mute=Mute;
        pValue->Use(Is);
        
        A.system=false;
        B.system=false;

        if(Is.Result||Mute)
        {
          A.ptr_lnk=B.ptr;
          B.ptr_lnk=A.ptr;
        }
        return Is.Result;
      }
      return false;
    }
    static bool IsEqualFuncEx(TSPACE&Space,DeclareType*pInput,DeclareType*pValue)
    {
      IsEqualTo<TSPACE> next(Space);
      next.pValue=pValue;
      pInput->Use(next);
      return next.Result;
    }
    void Do(DeclareTypeSys*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeSelfPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeAutoPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeWeakPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeHardPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVoidPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeFieldPtr*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeVector*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeArray*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
    void Do(DeclareTypeStruct*p)
    {
      Result=IsEqualFunc(Space,p,pValue,Mute);
    }
  };
};