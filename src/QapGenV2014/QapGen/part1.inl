#ifdef DEF_BUILD_MACRO
  #include "../Macro/part1.h"
#else
//=====>>>>>part1

class IBinIO{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IBinIO)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IBinIO
#include "QapGenStruct.inl"
//<<<<<+=====IBinIO
public:
  static void SysHasSelf();
public:
  virtual void Save(QapIO&IO,void*p){QapDebugMsg("no way.");}
  virtual void Load(QapIO&IO,void*p){QapDebugMsg("no way.");}
public:
  virtual void Copy(void*pOut,void*pInp){QapDebugMsg("no way.");}
  virtual bool IsSame(void*pA,void*pB){QapDebugMsg("no way.");return *(bool*)nullptr;}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  ~IBinIO(){}
};

class ITxtIO{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ITxtIO)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>ITxtIO
#include "QapGenStruct.inl"
//<<<<<+=====ITxtIO
public:
  static void SysHasSelf();
public:
  virtual void Save(string&s,void*p){QapDebugMsg("no way.");}
  virtual void Load(string&s,void*p){QapDebugMsg("no way.");}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
public:
  ~ITxtIO(){}
};

//` 
//`#define DEF_PRO_REG_TYPES_STRUCT(F)F(IBinIO)F(ITxtIO)
//`//=====+++>>>>>TYPES(STRUCT)
//`#include "DefGenReg.inl"
//`//<<<<<+++=====TYPES(STRUCT)
//`

template<class TYPE>
class TBinIO:public IBinIO{
public:
  typedef IBinIO ParentClass;
  typedef typename TYPE type;
  typedef typename TBinIO<TYPE> SelfClass;
public:
  void Save(QapIO&IO,void*p){
    IO.SavePOD(p,sizeof(type));
  }
  void Load(QapIO&IO,void*p){
    IO.LoadPOD(p,sizeof(type));
  }
public:
  void Copy(void*pOut,void*pInp){
    TYPE&out=*(TYPE*)pOut;
    TYPE&inp=*(TYPE*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB){
    TYPE&a=*(TYPE*)pA;
    TYPE&b=*(TYPE*)pB;
    return a==b;
  }
};

template<class TYPE>
class TTxtIO:public TBinIO<TYPE>{
public:
  typedef void SelfClass;
public:
  virtual void Save(string&s,void*p){static_assert(false,"not ready");}
  virtual void Load(string&s,void*p){static_assert(false,"not ready");}
};

template<class TYPE>
class THeadBinIO:public TBinIO<TYPE>{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<ParentClass>::GetRTTI(Env);};
public:
  static THeadBinIO<TYPE>*Get(){
    static THeadBinIO<TYPE>tmp;
    static bool flag=true;
    if(flag){
      THeadBinIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};

template<class TYPE>
class THeadCppIO:public TTxtIO<TYPE>{
public:
  typedef TTxtIO<TYPE> ParentClass;
  typedef typename TYPE type;
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env){return (TType*)Sys$$<ParentClass>::GetRTTI(Env);};
public:
  static THeadCppIO<TYPE>*Get(){
    static THeadCppIO<TYPE>tmp;
    static bool flag=true;
    if(flag){
      THeadCppIO<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};

template<>
class THeadBinIO<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IBinIO>>&GetArr(){
    static vector<TWeakPtr<IBinIO>> tmp; return tmp;
  }
};

template<>
class THeadCppIO<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<ITxtIO>>&GetArr(){
    static vector<TWeakPtr<ITxtIO>> tmp; return tmp;
  }
};

// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----

class IVectorAPI{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IVectorAPI)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDEND()
//=====+>>>>>IVectorAPI
#include "QapGenStruct.inl"
//<<<<<+=====IVectorAPI
public:
  typedef int SizeType;
  //IVectorAPI(){}//please do not remove constructor
  ~IVectorAPI(){}//please do not remove destructor
  virtual SizeType GetCount(void*p){QapDebugMsg("no way.");return 0;}//{vector<TYPE>&v=*(vector<TYPE>*)p;return v.size();}
  virtual void SetCount(void*p,SizeType c){QapDebugMsg("no way.");}//{vector<TYPE>&v=*(vector<TYPE>*)p;v.resize(c);}
  virtual void*GetItem(void*p,SizeType i){QapDebugMsg("no way.");return nullptr;}//{vector<TYPE>&v=*(vector<TYPE>*)p;return &v[i];}
public:
  virtual TType*GetElementType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
  virtual TType*GetMetaType(IEnvRTTI&Env){QapDebugMsg("no way.");return nullptr;}
};

template<class TYPE>
class TVectorAPI:public IVectorAPI{
public:
  typedef typename TYPE type;
  typedef IVectorAPI ParentClass;
  typedef TVectorAPI<type> SelfClass;
public:
  virtual SizeType GetCount(void*p){vector<TYPE>&v=*(vector<TYPE>*)p;return v.size();}
  virtual void SetCount(void*p,SizeType c){vector<TYPE>&v=*(vector<TYPE>*)p;v.resize(c);}
  virtual void*GetItem(void*p,SizeType i){vector<TYPE>&v=*(vector<TYPE>*)p;return &v[i];}
public:
  TType*GetElementType(IEnvRTTI&Env){return Sys$$<type>::GetRTTI(Env);}
  TType*GetMetaType(IEnvRTTI&Env)
  {
    QapDebugMsg("What does this code mean?");
    return nullptr;
    //return (TType*)Sys$$<SelfClass>::GetRTTI(Env);
  };
public:
  static TVectorAPI<TYPE>*Get(){
    static TVectorAPI<TYPE>tmp;
    static bool flag=true;
    if(flag){
      TVectorAPI<void>::GetArr().push_back(&tmp);
      flag=false;
    }
    return &tmp;
  }
};

template<>
class TVectorAPI<void>{
public:
  static nullptr_t Get(){return nullptr;}
  static vector<TWeakPtr<IVectorAPI>>&GetArr(){
    static vector<TWeakPtr<IVectorAPI>> tmp; return tmp;
  }
};

//<<<<<=====part1
#endif //DEF_BUILD_MICRO//