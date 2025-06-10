template<class TYPE>
class Sys$$<vector<TYPE>>{
public:
  typedef TTypeVector metatype;
  typedef vector<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="vector";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->SizeType=Sys$$<IVectorAPI::SizeType>::GetRTTI(RTTI);
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->VecAPI=TVectorAPI<elemtype>::Get();
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "vector<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<class TYPE,size_t Count>
class Sys$$<array<TYPE,Count>>{
public:
  typedef TTypeArray metatype;
  typedef array<TYPE,Count> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="array";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->Size=Count;
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "array<"+Sys$$<TYPE>::GetFullName()+","+IToS(Count)+">";
  }
};

template<class TYPE>
class Sys$$<TFactory<TYPE>>{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFactory";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
    typedef TSelfPtr<IFactory> SmartType;
    {
      #define GET_FIELD(TYPE,NAME)(((TYPE*)nullptr)->*(&TYPE::NAME))
      typedef decltype(GET_FIELD(type,Self)) realtype;
      typedef std::remove_reference<realtype>::type fieldtype;
      static_assert(std::is_same<SmartType,fieldtype>::value,"ok");
      #undef GET_FIELD
    }
    Info->SmartType=Sys$$<SmartType>::GetRTTI(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFactory<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<class TYPE>
class Sys$$<TFactory<TFactory<TYPE>>>{
public:
  typedef TTypeFactory metatype;
  typedef TFactory<TFactory<TYPE>> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    QapDebugMsg("WTF?");
    //metatype*Info=NULL;
    static string Name="TFactory";
    static metatype sys;
    static bool flag=true;
    if(flag){
      sys.Info.Name=Name;
      sys.Info.Size=sizeof(Name);
      //if(RTTI.Register<type>(Info,Name))return Info;
      //Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
      //Info->SubType=Info->SubType=detail::GetParentClassOf<type>::GetRTTI(RTTI);
      flag=false;
    }
    //RTTI.OnRegEnd(Info);
    return &sys;
  }
  static string GetFullName()
  {
    return "TFactory<TFactory<"+Sys$$<TYPE>::GetFullName()+">>";
  }
};

template<class TYPE>
class Sys$$<TSelfPtr<TYPE>>{
public:
  typedef TTypeSelfPtr metatype;
  typedef TSelfPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TSelfPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TSelfPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<class TYPE>
class Sys$$<TAutoPtr<TYPE>>{
public:
  typedef TTypeAutoPtr metatype;
  typedef TAutoPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TAutoPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TAutoPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<class TYPE>
class Sys$$<TWeakPtr<TYPE>>{
public:
  typedef TTypeWeakPtr metatype;
  typedef TWeakPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TWeakPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TWeakPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<class TYPE>
class Sys$$<THardPtr<TYPE>>{
public:
  typedef TTypeHardPtr metatype;
  typedef THardPtr<TYPE> type;
  typedef TYPE elemtype;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="THardPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->ElementType=Sys$$<elemtype>::GetRTTI(RTTI);
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "THardPtr<"+Sys$$<TYPE>::GetFullName()+">";
  }
};

template<>
class Sys$$<TVoidPtr>{
public:
  typedef TTypeVoidPtr metatype;
  typedef TVoidPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TVoidPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TVoidPtr";
  }
};

template<>
class Sys$$<TFieldPtr>{
public:
  typedef TTypeFieldPtr metatype;
  typedef TFieldPtr type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    metatype*Info=NULL;
    string Name="TFieldPtr";
    if(RTTI.Register<type>(Info,Name))return Info;
    Info->InitFields(RTTI);
    RTTI.OnRegEnd(Info);
    return Info;
  }
  static string GetFullName()
  {
    return "TFieldPtr";
  }
};
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
// ----- ----- ----- ----- -----
template<>
class TTxtIO<uint>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef uint type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=std::to_string(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    val=std::stoul(s);
  }
};

template<>
class TTxtIO<int>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef int type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    val=SToI(s);
  }
};

template<>
class TTxtIO<real>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef real type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    SToF(s,val);
  }
};

template<>
class TTxtIO<float>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef float type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=FToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    real tmp;
    SToF(s,tmp);
    val=tmp;
  }
};

template<>
class TTxtIO<bool>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef bool type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=BToS(val);
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    SToB(s,val);
  }
};

template<>
class TTxtIO<char>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef char type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    if(CppString::IsValidCppChar(val)){
      char out[4]={'\'',val,'\'',0};
      s=out;
    }else{
      string tmp=CToH_raw(val);
      s="'\\x"+tmp+"'";
    }
  }
  void Load(string&s,void*p){
    QapDebugMsg("under construction");return;
    type&val=*(type*)p;
    SToC(s,val);
  }
};

template<>
class TTxtIO<uchar>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef uchar type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    s=IToS(val);
  }
  void Load(string&s,void*p){
    QapDebugMsg("under construction");return;
    type&val=*(type*)p;
    val=SToI(s);
  }
};

template<>
class TBinIO<string>:public IBinIO{
public:
  typedef IBinIO ParentClass;
  typedef string type;
  typedef TBinIO<type> SelfClass;
public:
  void Save(QapIO&IO,void*p){
    type&val=*(type*)p;
    int count=val.size();
    IO.SavePOD(&count,sizeof(count));
    if(!count)return;
    IO.SavePOD(&val[0],count);
  }
  void Load(QapIO&IO,void*p){
    type&val=*(type*)p;
    int count=0;
    if(!IO.TryLoad(sizeof(count)))
    {
      IO.Crash();
      return;
    }
    IO.LoadPOD(&count,sizeof(count));
    if(!IO.TryLoad(count))
    {
      IO.Crash();
      return;
    }
    val.resize(count);
    if(!count)return;
    IO.LoadPOD(&val[0],count);
  }
public:
  void Copy(void*pOut,void*pInp){
    string&out=*(string*)pOut;
    string&inp=*(string*)pInp;
    out=inp;
  }
  bool IsSame(void*pA,void*pB){
    string&a=*(string*)pA;
    string&b=*(string*)pB;
    return a==b;
  }
};

template<>
class TTxtIO<string>:public ITxtIO{
public:
  typedef ITxtIO ParentClass;
  typedef string type;
  typedef TTxtIO<type> SelfClass;
public:
  void Save(string&s,void*p){
    type&val=*(type*)p;
    CppString cs=val;
    s="\""+cs.data+"\"";
  }
  void Load(string&s,void*p){
    type&val=*(type*)p;
    if(s.size()<2){QapDebugMsg("WTF?");return;}
    bool flag1=s.front()=='"';
    bool flag2=s.back()=='"';
    if(!flag1||!flag2){
      QapDebugMsg("WTF?");return;
    }
    val=s.substr(1,int(s.size())-2);
    BinString bs=val;
    val=bs.data;
  }
};

#define DEF_PRO_REG_TYPES_POD(F)\
F(uint)\
F(int)\
F(real)\
F(float)\
F(bool)\
F(char)\
F(uchar)\
F(string)\
//#define DEF_PRO_REG_TYPES_SYS(F)
//=====+++>>>>>TYPES(POD)
#include "DefGenReg.inl"
//<<<<<+++=====TYPES(POD)