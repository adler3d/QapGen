#ifdef DEF_BUILD_MACRO
  #include "../Macro/part2.h"
#else
//=====>>>>>part2

class TTypeInfo{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(int,Size,SET,0,$)\
ADDVAR(int,Align,SET,0,$)\
ADDEND()
//=====+>>>>>TTypeInfo
#include "QapGenStruct.inl"
//<<<<<+=====TTypeInfo
public:
};

//не конкретный описатель метатипов.
class TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(THardPtr<IEnvRTTI>,Env,DEF,$,$)\
ADDVAR(THardPtr<IFactory>,Factory,DEF,$,$)\
ADDVAR(TTypeInfo,Info,DEF,$,$)\
ADDEND()
//=====+>>>>>TType
#include "QapGenStruct.inl"
//<<<<<+=====TType
public:
  static void SysHasSelf();
public:
  virtual void Use(IVisitorRTTI&){QapDebugMsg("no way.");}
  virtual string GetFullName(){return Info.Name;}
  virtual TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<SelfClass>::GetRTTI(Env);};
  virtual TType*GetSubType()const{return nullptr;}
  bool ready()const{return Env&&Env->GetAlloc()&&Factory;}
  IAllocator*GetAlloc(){return Env?Env->GetAlloc():nullptr;}
  bool CanDestroy()const{return 1==Self.P.HardCount;}
public:
  bool IsBasedOn(TType*A)const{
    if(this==A)return true;
    TType*subtype=this->GetSubType();
    return subtype?subtype->IsBasedOn(A):false;
  }
};
//ќписатель системных метатипов.
class TTypeSys:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeSys)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<IBinIO>,BinIO,DEF,$,$)\
ADDVAR(THardPtr<ITxtIO>,TxtIO,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeSys
#include "QapGenStruct.inl"
//<<<<<+=====TTypeSys
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  ~TTypeSys()
  {
    if(BinIO||TxtIO)
    {
      QapDebugMsg("bad idea");
    }
    BinIO=nullptr;
    TxtIO=nullptr;
  }
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//ќписатель метатипов описывающих вектор.
class TTypeVector:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeVector)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,SizeType,DEF,$,$)\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(THardPtr<IVectorAPI>,VecAPI,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeVector
#include "QapGenStruct.inl"
//<<<<<+=====TTypeVector
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//ќписатель метатипов описывающих массив.
class TTypeArray:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeArray)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,Size,SET,0,$)\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeArray
#include "QapGenStruct.inl"
//<<<<<+=====TTypeArray
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+","+IToS(Size)+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//ќписатель метатипов описывающих виртуальный коструктор.
class TTypeFactory:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeFactory)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(THardPtr<TType>,SubType,DEF,$,$)\
ADDVAR(THardPtr<TType>,SmartType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeFactory
#include "QapGenStruct.inl"
//<<<<<+=====TTypeFactory
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const{return SubType?SubType.get():nullptr;}
};

class IEsoteric;

class QapSysMember{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapSysMember)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(THardPtr<TType>,Type,DEF,$,$)\
ADDEND()
//=====+>>>>>QapSysMember
#include "QapGenStruct.inl"
//<<<<<+=====QapSysMember
public:
  void set(const string&Name,TType*Type)
  {
    this->Name=Name;
    this->Type=Type;
  }
};

//ќписатель метатипов описывающих умный указатель "точка входа".
class TTypeSelfPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeSelfPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeSelfPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeSelfPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mSaveIDType)CLASS(TServerPtr<IEsoteric>)FIELD(SaveID)
    //=====+>>>>>mSaveIDType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  typedef TDynSelfPtrFactory TDynamicFactory;
};
//ќписатель метатипов описывающих "владеющий умный указатель".
class TTypeAutoPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeAutoPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeAutoPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeAutoPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TRTTIProduct mProductType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mProductType)CLASS(TAutoPtr<IEsoteric>)FIELD(Product)
    //=====+>>>>>mProductType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mProductType
    {}
    typedef THardPtr<TType> mProduct_pTypeType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mProduct_pTypeType)CLASS(mProductType)FIELD(pType)
    //=====+>>>>>mProduct_pTypeType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mProduct_pTypeType
    {}
    mType.set("Product.pType",Sys$$<mProduct_pTypeType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//ќписатель метатипов описывающих "слабый след€щий умный указатель".
class TTypeWeakPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeWeakPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeWeakPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeWeakPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mSaveIDType)CLASS(TServerPtr<IEsoteric>)FIELD(SaveID)
    //=====+>>>>>mSaveIDType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};
//ќписатель метатипов описывающих "сильный след€щий умный указатель".
class TTypeHardPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeHardPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeHardPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeHardPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef int mSaveIDType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mSaveIDType)CLASS(TServerPtr<IEsoteric>)FIELD(SaveID)
    //=====+>>>>>mSaveIDType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mSaveIDType
    {}
    mSaveID.set("SaveID",Sys$$<mSaveIDType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetElementName(){return std::move(ElementType?ElementType->GetFullName():IToH(ElementType.P.UID.id));}
  string GetFullName(){return std::move(Info.Name+"<"+GetElementName()+">");}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//SmartType - это TWeakPtr<TType> спецально дл€ внутреностей.
class TTypeVoidPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeVoidPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDVAR(QapSysMember,mPtr,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeVoidPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeVoidPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef THardPtr<TType> mTypeType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mTypeType)CLASS(TVoidPtr)FIELD(type)
    //=====+>>>>>mTypeType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mTypeType
    {}
    typedef TWeakPtr<IEsoteric> mPtrType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mPtrType)CLASS(TVoidPtr)FIELD(ptr)
    //=====+>>>>>mPtrType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mPtrType
    {}
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mPtr.set("ptr",Sys$$<mPtrType>::GetRTTI(Env));
  }
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

class TVoidPtr;
//костыль
class TTypeFieldPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeFieldPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapSysMember,mObject,DEF,$,$)\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDVAR(QapSysMember,mOffset,DEF,$,$)\
ADDVAR(QapSysMember,mIndex,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeFieldPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeFieldPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env)
  {
    {}
    typedef TVoidPtr mObjectType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mObjectType)CLASS(TFieldPtr)FIELD(object)
    //=====+>>>>>mObjectType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mObjectType
    {}
    typedef THardPtr<TType> mTypeType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mTypeType)CLASS(TFieldPtr)FIELD(type)
    //=====+>>>>>mTypeType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mTypeType
    {}
    typedef int mOffsetType;
    #define DEF_PRO_GET_FIELD_TYPE(RESULT,CLASS,FIELD)RESULT(mOffsetType)CLASS(TFieldPtr)FIELD(offset)
    //=====+>>>>>mOffsetType
    #include "QapProGetFieldType.inl"
    //<<<<<+=====mOffsetType
    {}
    mObject.set("object",Sys$$<mObjectType>::GetRTTI(Env));
    mType.set("type",Sys$$<mTypeType>::GetRTTI(Env));
    mOffset.set("offset",Sys$$<mOffsetType>::GetRTTI(Env));
    {}
    mIndex.set("index",Sys$$<int>::GetRTTI(Env));
  }
  void Use(IVisitorRTTI&A){A.Do(this);}
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
};

//ќписатель метатипов описывающих конкретные структуры.
class TTypeStruct:public TType{
public:
  class Member{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Member)OWNER(TTypeStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,Name,SET,"unnamed",$)\
    ADDVAR(int,Offset,SET,0,$)\
    ADDVAR(THardPtr<TType>,Type,DEF,$,$)\
    ADDVAR(string,Mode,DEF,$,$)\
    ADDVAR(string,Value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Member
    #include "QapGenStruct.inl"
    //<<<<<+=====Member
  public:
    void*getValue(void*pValue)
    {
      return (void*)(Offset+int(pValue));
    }
  };
  class TExtInfo{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TExtInfo)OWNER(TTypeStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,SelfId,SET,-1,$)\
    ADDVAR(string,SpecInfo,DEF,$,$)\
    ADDVAR(bool,Polymorph,SET,false,$)\
    ADDVAR(bool,Abstract,SET,false,$)\
    ADDVAR(bool,PoorDesign,SET,false,$)\
    ADDEND()
    //=====+>>>>>TExtInfo
    #include "QapGenStruct.inl"
    //<<<<<+=====TExtInfo
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(Member)F(TExtInfo)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeStruct)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,SubType,DEF,$,$)\
ADDVAR(THardPtr<TType>,OwnType,DEF,$,$)\
ADDVAR(vector<Member>,Members,DEF,$,$)\
ADDVAR(vector<THardPtr<TType>>,Nesteds,DEF,$,$)\
ADDVAR(TExtInfo,extInfo,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeStruct
#include "QapGenStruct.inl"
//<<<<<+=====TTypeStruct
public:
  void Use(IVisitorRTTI&A){A.Do(this);}
  static string GetElementName(THardPtr<TType>&ElementType)
  {
    return std::move(ElementType?ElementType->GetFullName()+"::":"");
  }
  string GetFullName(){return std::move(GetElementName(OwnType)+Info.Name);}
public:
  string GetDebugInfo()
  {
    string fn=GetFullName();
    string code;
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      code+=(i?",":"")+ex.Name;
    }
    return fn+"={"+code+"}";
  }
public:
  bool TestField(const Member&it,int depth=0)
  {
    QapAssert((it.Mode=="DEF")||(it.Mode=="SET"));
    if(it.Mode=="DEF")do
    {
      auto*pFieldType=TTypeSys::UberCast(it.Type.get());
      if(!pFieldType)break;
      string ftfn=pFieldType->GetFullName();
      static const vector<string> white_list=split("bool|uint|int|float|real|char|uchar|string","|");
      bool white=false;
      for(int i=0;i<white_list.size();i++)
      {
        white=white||(ftfn==white_list[i]);
      }
      if(white)break;
      string fn=GetFullName();
      QapDebugMsg("field - \""+fn+"\"::"+it.Name+"\" has illegal DEF mode");
    }while(false);
    if(SubType)
    {
      auto*pSubType=TTypeStruct::UberCast(SubType.get());
      bool result=pSubType->TestField(it,depth+1);
      if(!result)return result;
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      int cmp_id=0;
      #define DEF_LIST(F)F(Name)F(Offset)//F(Number)//F(Mode)
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
        if((-1==it.Offset)&&(-1==Info.Size))continue;
        QapDebugMsg("wrong "+tmp+" in "+fn+"::"+it.Name);
        return depth;
      }
    }
    return true;
  }
public:
  static SelfClass*UberCast(TType*ptr){return IVisitorRTTI::UberCast<SelfClass>(ptr);};
public:
  template<class TYPE>
  static TYPE*AddOffset(TYPE*pValue,int offset){return (TYPE*)(void*)(offset+int(pValue));}
  struct IsStruct
  {
    static Member*GetNearSelf(THardPtr<TType>&pType)
    {
      if(!pType)return nullptr;
      TType*type=pType.get();
      return GetNearSelf(type);
    }
    static Member*GetNearSelf(TType*type)
    {
      if(!type)return nullptr;
      auto*tmp=UberCast(type);
      if(!tmp){
        return GetNearSelf(type->GetSubType());
      }
      return tmp->GetNearSelf();
    }
    struct MemberIndexByOffset
    {
      struct FieldInfo{
        TTypeStruct*base;
        int index;
        Member*get()
        {
          if(!base)return nullptr;
          auto&it=base->Members[index];
          return &it;
        }
      };
      struct Input{
        TType*type;
        int offset;
        TType*fieldtype;
      };
      struct Output{
        int index;
        FieldInfo info;
      };
      static bool get(Input&in,Output&out)
      {
        auto*base=UberCast(in.type);
        string in_ft_fn=in.fieldtype->GetFullName();
        if(base)
        {
          //проходим сверху.
          auto&arr=base->Members;
          for(int i=0;i<arr.size();i++,out.index++)
          {
            auto&it=arr[i];
            if(it.Offset!=in.offset)
            {
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if(!result)continue;
              return result;
            }
            auto*type=it.Type.get();
            {
              string type_fn=type->GetFullName();
              string base_fn=base->GetFullName();
              in_ft_fn=in_ft_fn;
            }
            if(type==in.fieldtype)
            {
              out.info.base=base;
              out.info.index=i;
              return true;
            }else{
              TType*mt=it.Type.get();
              int mos=in.offset-it.Offset;
              Input input={mt,mos,in.fieldtype};
              bool result=get(input,out);
              if(!result)continue;
              return result;
            }
            QapDebugMsg("breakpoint");
          }
        }
        if(!base&&in.type)
        {
          TType*SubType=in.type->GetSubType();
          if(SubType)
          {
            Input input={SubType,in.offset,in.fieldtype};
            return get(input,out);
          }
        }
        return false;
      }
    };
  };
  Member*GetNearSelf()
  {
    return extInfo.SelfId<0?IsStruct::GetNearSelf(GetSubType()):&Members[extInfo.SelfId];
  }
public:
  void AddField(Member&&field)
  {
    QapAssert(field.Type);
    QapAssert(TestField(field));
    QapAssert(field.Type&&field.Type->Info.Align>0);
    if(field.Name=="Self")
    {
      if(true)do
      {
        auto*type=TTypeSelfPtr::UberCast(field.Type.get());
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
        auto*pSubType=TTypeStruct::UberCast(SubType.get());
        string fn=GetFullName();
        string subtype=pSubType->GetFullName();
        #define F(SUBCLASS,CLASS)if(#SUBCLASS==subtype)if(#CLASS==fn)break;
          F(QapWinProgram,eWinProgram)
          F(QapWinProgram,QapProgramD3D9)
        #undef F
        QapDebugMsg("field - \""+subtype+"::"+field.Name+"\" overload in \""+fn+"\"");
      }while(false);
      extInfo.SelfId=Members.size();
    }
    Members.push_back(std::move(field));
  }
  void AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    //if(FindMember(Number))MACRO_ADD_LOG("Member("+MemName+":"+MemType->GetName()+") id("+IToS(Number)+") not unique",lml_ERROR);
    //Members.push_back(Member(Number,MemType,MemName,Offset));
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value)
  {
    Member tmp;
    tmp.Type=MemType;
    tmp.Name=MemName;
    tmp.Offset=Offset;
    tmp.Mode=Mode;
    tmp.Value=Value;
    AddField(std::move(tmp));
  }
  void AddMemberSYS(...){}
  void AddMemberSYD(...){}
  void AddNested(TType*NestedType)
  {
    Nesteds.push_back(NestedType);
  }
public:
  static vector<string>&get_white_list()
  {
    static vector<string> arr;
    if(!arr.empty())return arr;
    string white_list[]={
      "eWindow::TForm",
      "QapKeyboard",
      "QapD3DDev9",
      "QapTexMem",
      "QapTex",
      "QapFontInfo",
      "QapDev",
      "QapResourceDetector",
      "QapTreeDebugger",
      "TDownLoader",
      "TReloadDetector",
      "T20130410_GatewayServer",
      "T20130410_ServerCallback"
    };
    for(int i=0;i<lenof(white_list);i++)
    {
      arr.push_back(white_list[i]);
    };
    return arr;
  }
  static bool find_in_white_list(const string&type_fullname)
  {
    auto&arr=get_white_list();
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i]==type_fullname)return true;
    }
    return false;
  }
  void SelfTesting()
  { 
    static string all_messages;
    if(!Members.empty())
    {
      auto&front=Members.front();
      bool bad=!SubType&&front.Offset;
      bool mute=(extInfo.Polymorph&&!SubType)&&(front.Offset==Info.Align);
      if(bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - offset of the first field of the type is "+IToS(front.Offset);
        all_messages+=msg+"\n";
        mute=mute||find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(!Members.empty())
    {
      auto&back=Members.back();
      int aligned_size=getAligned(back.Offset+back.Type->Info.Size,Info.Align);
      bool bad=aligned_size!=Info.Size;
      if(bad)
      {
        string fn=this->GetFullName();
        string msg="\""+fn+"\" - size of the type is "+IToS(Info.Size)+". expected aligned_size = "+IToS(aligned_size);
        all_messages+=msg+"\n";
        bool mute=find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(Members.empty())
    {
      int expected_size=0;
      {
        if(!SubType){
          expected_size=1;
          if(extInfo.Polymorph)expected_size=Info.Align;
        }
        if(SubType)expected_size=SubType->Info.Size;
      }
      bool bad=expected_size!=Info.Size;
      if(bad)
      {
        string fn=this->GetFullName();
        string msg=(
          "\""+fn+"\" - size of the type is "+IToS(Info.Size)+"\n"
          "expected size: "+IToS(expected_size)+"\n"
          "PoorDesign?"
        );
        all_messages+=msg+"\n";
        bool mute=extInfo.PoorDesign||find_in_white_list(fn);
        if(!mute)QapDebugMsg(msg);
      }
    }
    if(OwnType&&!Nesteds.empty())
    {
      const string&parent=OwnType->Info.Name;
      auto&arr=Nesteds;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(parent!=ex->Info.Name)continue;
        QapDebugMsg(
          "Prohibited name of a nested type.\n"
          "parent type and one of the sub-types have equal names.\n"
          "  ParentClass: "+parent+"\n"
          "  SelfClass: "+Info.Name
        );
        *(int*)nullptr=0;
      }
    }
  }
public:
  void Calc()
  {
    QapAssert(Info.Size>0);
    QapAssert(Info.Align>0);
    auto*subtype=SubType.get();
    if(subtype)
    {
      QapAssert(subtype->Info.Size>0);
      QapAssert(subtype->Info.Align>0);
    }
    auto&arr=Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      QapAssert(type->Info.Size>0);
      QapAssert(type->Info.Align>0);
      QapAssert(ex.Offset>=0);
    }
    int gfdsq=0;
  }
  static int getAligned(int offset,int align)
  {
    QapAssert(offset>=0);
    int x=offset%align;
    return offset+(x?align-x:0);
  }
  void ReCalcMembersOffset()
  {
    //QapAssert(size);
    int Offset=0;
    int MaxAlign=0;
    auto*subtype=SubType.get();
    if(subtype)
    {
      int Size=subtype->Info.Size;
      int Align=subtype->Info.Align;
      QapAssert(Size>0);
      QapAssert(Align>0);
      Offset=getAligned(Offset,Align);
      Offset+=Size;
      MaxAlign=max(MaxAlign,Align);
    }
    auto&arr=this->Members;
    MaxAlign=max(MaxAlign,!arr.empty()?arr[0].Type->Info.Align:1);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*type=ex.Type.get();
      int Size=type->Info.Size;
      int Align=type->Info.Align;
      QapAssert((Align>0)&&(Align<=1024));
      QapAssert(Size>0);
      QapAssert(-1==ex.Offset);
      ex.Offset=getAligned(Offset,Align);
      Offset=ex.Offset+Size;
      MaxAlign=max(MaxAlign,Align);
    }
    Info.Size=getAligned(Offset>0?Offset:1,MaxAlign);
    Info.Align=MaxAlign;
  }
  TType*GetMetaType(IEnvRTTI&Env){
    return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  }
  TType*GetSubType()const{return SubType?SubType.get():nullptr;}
  bool IsEqual(TTypeStruct*type)
  {
    if(Members.size()!=type->Members.size())return false;
    for(int i=0;i<Members.size();i++)
    {
      auto&it=Members[i];
      auto&ex=type->Members[i];
      if(it.Type.get()!=ex.Type.get())do
      {
        const int&id1=it.Type->Self.P.SaveID;
        const int&id2=ex.Type->Self.P.SaveID;
        if((id1&&id2)&&(id1==id2))break;
        return false;
      }while(false);
      int cmp_id=0;
      #define DEF_LIST(F)F(Name)/*F(Number)F(Offset)*/F(Mode)
      #define F(NAME)#NAME,
        static string idToStr[]={DEF_LIST(F)};
      #undef F
      static const int cmp_n=lenof(idToStr);
      #define F(NAME)if(it.NAME!=ex.NAME)break;cmp_id++;;
        do{DEF_LIST(F);}while(false);
      #undef F
      #undef DEF_LIST
      if(cmp_id!=cmp_n)
      {
        string tmp=idToStr[cmp_id];
        QapDebugMsg("wrong "+tmp+" in "+GetFullName()+"::"+it.Name);
        return false;
      }
    }
    return true;
  }
  bool hasMember(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.size()>1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return true;}
    return !arr.empty();
  }
  Member&unsafe_find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.size()!=1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return *(Member*)nullptr;}
    return Members[arr[0]];
  }
  Member*find_member(const string&name)
  {
    auto arr=qap_find(Members,[&name](Member&ex){return ex.Name==name;});
    if(arr.empty())return nullptr;
    if(arr.size()>1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+name);return nullptr;}
    return &Members[arr[0]];
  }
  Member*find_member_full(const string&name)
  {
    if(!SubType)return find_member(name);
    auto*pSubType=SubType.get();
    auto*p=TTypeStruct::UberCast(pSubType);
    if(!p){
      QapDebugMsg("parent of type is not struct?\n"+GetFullName());
      return nullptr;
    }
    auto*fromSub=p->find_member_full(name);
    auto*fromThis=this->find_member(name);
    if(bool(fromSub)==bool(fromThis))
    {
      QapAssert(!fromSub&&!fromThis);
      return false;
    }
    return fromSub?fromSub:fromThis;
  }
public:
  typedef TDynStructFactory TDynamicFactory;
};

//<<<<<=====part2
#endif //DEF_BUILD_MICRO//