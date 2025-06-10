#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include "QapType.h"
#include "QapAssert.h"
//-------------------------------------------//
struct TScreenMode{int W,H,BPP,Freq;};
//-------------------------------------------//
template<class TYPE>
inline static TYPE max(const TYPE&a,const TYPE&b){return a>b?a:b;}
template<class TYPE>
inline static TYPE min(const TYPE&a,const TYPE&b){return a<b?a:b;}
template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}
inline static int max(int a,int b){return a>b?a:b;}
inline static int min(int a,int b){return a<b?a:b;}
inline static float max(float a,float b){return a>b?a:b;}
inline static float min(float a,float b){return a<b?a:b;}
inline static double max(double a,double b){return a>b?a:b;}
inline static double min(double a,double b){return a<b?a:b;}
//-------------------------------------------//
template<typename TYPE>TYPE Sign(TYPE value){if(value>0){return TYPE(+1);}else{return TYPE(value<0?-1:0);};};
template<typename TYPE>bool InDip(TYPE min,TYPE val,TYPE max){return (val>=min)&&(val<=max);};
//-------------------------------------------//
inline TScreenMode GetScreenMode()
{
  HDC DC=GetDC(0); 
  TScreenMode Res={GetDeviceCaps(DC,HORZRES),GetDeviceCaps(DC,VERTRES),GetDeviceCaps(DC,BITSPIXEL),GetDeviceCaps(DC,VREFRESH)};
  ReleaseDC(0,DC);
  return Res;
}
//-------------------------------------------//
class CharMask{
public:
  bool mask[256];
  CharMask(CharMask&&ref){for(uint i=0;i<sizeof(mask);i++)mask[i]=ref.mask[i];}
  CharMask(){for(uint i=0;i<sizeof(mask);i++)mask[i]=false;}
public:
  static CharMask fromStr(const string&str)
  {
    CharMask tmp;
    tmp.prepare(str);
    return std::move(tmp);
  }
public:
  template<size_t COUNT>
  explicit CharMask(const char(&allowed)[COUNT]){
    string str;
    str.resize(COUNT-1);
    for(int i=0;i<str.size();i++)str[i]=*(char*)(void*)&allowed[i];
    prepare(str);
    if(false)
    {
      string unallowed;
      for(int i=1;i<256;i++)if(!mask[i])unallowed.push_back(i);
      QapDebugMsg(unallowed);
    }
  }
  void prepare(const std::string&allowed)
  {
    for(uint i=0;i<sizeof(mask);i++)mask[i]=false;
    for(uint i=0;i<uint(allowed.size());i++)
    {
      unsigned char uc=uchar(allowed[i]);
      bool&flag=mask[uc];
      QapAssert(!flag);
      flag=true;
    }
  };
  bool check(const std::string&str)const
  {
    auto n=str.size();
    if(!n)return true;
    const auto*p=&str[0];
    auto e=p+n;
    for(;p<e;p++)
    {
      if(!mask[uchar(*p)])return false;
    }
    return true;
  }
  bool operator[](uchar index)const{return mask[index];}
};
//-------------------------------------------//
inline real RndReal(const real&min,const real&max){return min+(max-min)*(real)rand()/(real)RAND_MAX;};
inline string CToS(const char&val){string tmp="";tmp.push_back(val);return tmp;};
inline string IToS(const int&val){char c[16];_itoa_s(val,c,10);return string(c);}
inline string UCToS(const unsigned char&val){char d[8]; sprintf_s(d,sizeof(d),"%u",val); return string(d);}
inline string HToS(const int&val){char c[16];_itoa_s(val,c,16);return "0x"+string(c);}
inline string IToSex(const int&val){char c[40];sprintf_s(c,"%08i",val);int i=0;while(c[i]=='0')c[i++]='-';return string(c);}
inline string FToS(const real&val){char c[64];if(abs(val)>1e9){_snprintf_s(c,32,32,"%e",val);}else{sprintf_s(c,"%.2f",val);}return string(c);}
inline string BToS(const bool&val){return val?"true":"false";};
inline string IToH(const int&val){char d[255]; sprintf_s(d,sizeof(d),"0x%08X",val); return string(d);}
inline string IToH(const int&val,int n){char d[255]; n=n<0?8:n>8?8:n; string c=IToS(n); sprintf_s(d,sizeof(d),("0x%0"+c+"X").c_str(),val); return string(d);}
inline string IToH_raw(const int&val){char d[255]; sprintf_s(d,sizeof(d),"%08X",val); return string(d);}
inline char HToC(const string&str){size_t val;sscanf_s(str.c_str(),"%02x",&val); return char(val);}
//-------------------------------------------//
inline bool SToF(const string&str,real&val){sscanf_s(str.c_str(),"%lf",&val);return true;}
inline bool SToB(const string&str,bool&val){val=str=="true";return true;}
inline bool SToB(const string&str){return str=="true";}
inline bool SToC(const string&str,char&val){if(str.size()!=1)return false;val=str[0];return true;}
inline bool HToI(const string&str,int&val){sscanf_s(str.c_str(),"0x%08X",&val); return true;}
inline int HToI(const string&str){int val;sscanf_s(str.c_str(),"0x%08X",&val); return val;}
inline int HToI_raw(const string&str){int val;sscanf_s(str.c_str(),"%08X",&val); return val;}
inline string CToH_raw(const unsigned char&val){char d[3]; sprintf_s(d,sizeof(d),"%02X",val); return string(d);}
inline string SToS(const string&s){return s;}
template<size_t COUNT> inline string SToS(const char(&lzstr)[COUNT]){static_assert(COUNT,"WTF?");return string(&lzstr[0],size_t(COUNT-1));}
inline string SToSex(const string&S,const int&l){string s(l,' ');for(int i=0;i<int(S.size());i++)s[i]=S[i];return s;}
inline int SToI(const string&S){int i;sscanf_s(S.c_str(),"%i",&i);return i;};
inline int SToI_fast(const string&S){
  //return atoi(S.c_str());
  int i;sscanf_s(S.c_str(),"%i",&i);return i;
  //stringstream ss(S);
  //int i=0;ss>>i;
  //return i;
};
//-------------------------------------------//
inline string GetFileName(const string&filename)
{
  static CharMask mask("\\/");
  if(filename.empty())return filename;
  int c=0;
  for(int i=filename.size()-1;i>=0;i--)
  {
    if(mask.mask[filename[i]])
    {
      string out=filename.substr(i+1,c);
      return out;
    }
    c++;
  }
  return filename;
}
//-------------------------------------------//
inline bool IsRawDirName(const std::string&dirname)
{
  static CharMask mask(".");
  const string&raw=GetFileName(dirname);
  return !mask.check(raw);
}
//-------------------------------------------//
inline string RemoveFileExt(const string&FN)
{
  const int pos=FN.rfind(".");
  return std::move(FN.substr(0,pos));
}
//-------------------------------------------//
inline string ChangeFileExt(const string&FN,const string&Ext)
{
  string tmp=RemoveFileExt(FN)+Ext;
  return std::move(tmp);
}
//-------------------------------------------//
inline string BackSlashesToSlashes(const string&data)
{
  string tmp=data;
  for(int i=0;i<tmp.size();i++)
  {
    char&c=tmp[i];
    if(c=='\\'){
      c='/';
    }
  }
  return std::move(tmp);
}
//-------------------------------------------//
inline string ScanParam(const string&Before,const string&Where,const string&After,int&Pos)
{
  int E=Where.find(Before, Pos);
  if(E==-1){Pos=-1; return "";}
  Pos=Where.find(Before,Pos)+Before.length();
  E=After.empty()?Where.size():Where.find(After,Pos);
  if(E==-1){Pos=-1; return "";}
  string result; result.assign(Where,Pos,E-Pos);
  return std::move(result);
}
//-------------------------------------------//
inline string GetDataTimeStr()
{
  class UG{public:static inline string X(int val,string fs){char c[40];sprintf_s(c,fs.c_str(),val);return string(c);}};
  SYSTEMTIME LT;
  GetLocalTime(&LT);
  string Str;
  #define F(VAL,D)UG::X(LT.VAL,"%0"#D"i")
    Str=F(wYear,2)+"-"+F(wMonth,2)+"-"+F(wDay,2)+" "
      +F(wHour,2)+"-"+F(wMinute,2)+"-"+F(wSecond,2)+"-"+F(wMilliseconds,3);
  #undef F
  Str.resize(Str.size()-1);
  return Str;
}
//-------------------------------------------//
inline string GetFileExt(const string&FN){int e=FN.rfind(".");string ext=ScanParam(".",FN,"",e);return ext;}
inline string LowerStr(const string&s){string str=s;for(int i=0;i<int(str.size());i++)str[i]=tolower(str[i]);return std::move(str);}
inline string UpperStr(const string&s){string str=s;for(int i=0;i<int(str.size());i++)str[i]=toupper(str[i]);return std::move(str);}
//-------------------------------------------//
inline bool IsNumChar(const uchar&c)
{
  #define F(A,B)bool(uchar(A)<=c&&uchar(B)>=c)
  return F('0','9');
  #undef F
}
//-------------------------------------------//
inline bool IsLegalChar(const uchar&c)
{
  #define F(A,B)bool(uchar(A)<=c&&uchar(B)>=c)
  return F('a','z')||F('A','Z')||F('0','9');
  #undef F
}
//-------------------------------------------//
template<typename Callback>
class LineVisitor{
public:
  int line;
  int pos;
  const string&mem;
  LineVisitor(const string&mem):mem(mem){pos=0;line=0;}
  bool Next(Callback&callback)
  {
    line++;
    const string sepstr="\n";
    int npos=mem.find(sepstr,pos);
    if(npos<0)return false;
    string line=std::move(mem.substr(pos,npos-pos));
    callback(line);
    pos=npos+sepstr.size();
    return true;
  }
};
//-------------------------------------------//
class Extractor{
public:
  class Gripper{
  public:
    string before;
    string after;
    Gripper(const string&before,const string&after):before(before),after(after){}
    string grip(const string&source)const{return before+source+after;}
  };
public:
  int pos;
  string source;
  Extractor(const string&source):pos(0),source(source){}
  string extract(const Gripper&ref){
    string s=ScanParam(ref.before,source,ref.after,pos);
    if(pos>=0)pos+=s.size()+ref.after.size();
    return s;
  }
  template<class TYPE>
  void extract_all(TYPE&visitor,const Gripper&ref)
  {
    while(pos>=0){
      string s=extract(ref);
      if(pos<0)break;
      visitor.accept(s);
    }
  }
  operator bool(){return pos>=0;}
};
//-------------------------------------------//
template<class TYPE>
class FindData{
public:
  WIN32_FIND_DATA ffd;
  //string Ext;
  string Dir;
  HANDLE hFind;
  char buff[1024];
  TYPE&Functor;
  FindData(const string&dir,TYPE&Functor,bool manual=false):hFind(nullptr),Functor(Functor){
    //Ext=LowerStr(ext);
    Dir=dir;
    if(manual)return;
    Start();
    do{}while(Next());
    Stop();
  }
  void Start(){
    if(hFind)return;
    string filename=Dir+"/*";
    hFind=FindFirstFileA(filename.c_str(),&ffd);
    if(INVALID_HANDLE_VALUE==hFind){QapDebugMsg("INVALID_HANDLE_VALUE");return;}
  }
  bool Next(){
    if(!hFind)return false;
    string fn=ffd.cFileName;
    //if(LowerStr(GetFileExt(fn))==Ext)
    {
      fn=Dir+"/"+fn;
      Functor(fn,bool(ffd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY));
    }
    if(!FindNextFile(hFind,&ffd))
    {
      auto dwError=GetLastError();
      if(dwError!=ERROR_NO_MORE_FILES){
        QapDebugMsg("failed");
      }
      Stop();
      return false;
    }
    return true;
  }
  void Stop(){
    if(!hFind)FindClose(hFind);hFind=nullptr;
  }
  operator bool(){return hFind;}
  ~FindData(){
    Stop();
  }
};
//-------------------------------------------//
static string gen_dip(char from,char to){
  QapAssert(from<to);
  string out;
  out.reserve(to-from);
  bool flag=from!=to;
  for(auto c=from;flag;c++){
    flag=flag&&(c!=to);
    out.push_back(c);
  }
  return out;
}
//-------------------------------------------//
static string gen_dips(const string&rule){
  QapAssert(!(rule.size()%2));
  string out;
  for(int i=0;i<rule.size();i+=2){
    out+=gen_dip(rule[i+0],rule[i+1]);
  }
  return out;
}
//-------------------------------------------//
static string dip_inv(const string&dip){
  string out;
  char min=std::numeric_limits<char>::min();
  char max=std::numeric_limits<char>::max();
  bool flag=min!=max;
  for(auto c=min;flag;c++){
    flag=flag&&(c!=max);
    auto e=dip.find(CToS(c));
    if(e!=std::string::npos)continue;
    out.push_back(c);
  }
  return out;
}
//-------------------------------------------//
static vector<string> split(const string&s,const string&needle)
{
  vector<string> arr;
  if(s.empty())return arr;
  size_t p=0;
  for(;;){
    auto pos=s.find(needle,p);
    if(pos==std::string::npos){arr.push_back(s.substr(p));return arr;}
    arr.push_back(s.substr(p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}
//-------------------------------------------//
static string join(const vector<string>&arr,const string&glue)
{
  string out;
  size_t c=0;
  size_t dc=glue.size();
  for(int i=0;i<arr.size();i++){if(i)c+=dc;c+=arr[i].size();}
  out.reserve(c);
  for(int i=0;i<arr.size();i++){if(i)out+=glue;out+=arr[i];}
  return out;
}
//-------------------------------------------//
inline string StrReplace(const string&input,const string&sub,const string&now)
{
  return join(split(input,sub),now);
  //old version is slow and wrong
  //string result=input;
  //for(unsigned index=0;index=result.find(sub,index),index!=string::npos;)
  //{
  //  result.replace(index,sub.length(),now);
  //  index+=now.length();
  //}
  //return std::move(result);
}
//-------------------------------------------//
static string urlencode(const string&str)
{
  string tmp;tmp.reserve(str.size()*3);
  for(int i=0;i<str.size();i++)
    tmp+=IsLegalChar(str[i])?CToS(str[i]):"%"+CToH_raw(str[i]);
  return tmp;
}
//-------------------------------------------//
static string urldecode(const string&s)
{
  auto arr=split(s,"%");
  string out="";
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    if(i==0){out+=ex;continue;}
    QapAssert(ex.size()>=2);
    out.push_back(char(HToC(ex.substr(0,2))));
    out+=ex.substr(2);
  }
  return out;
}
//-------------------------------------------//
/*
template<class TYPE>
static vector<TYPE> subarr(const vector<TYPE>&arr,int offset,int count)
{
  QapAssert(offset>=0);QapAssert(count>=0);
  vector<TYPE*> out;
  int limit=std::min<int>(arr.size(),offset+count);
  for(int i=offset;i<limit;i++){
    out.push_back(arr[i]);
  }
  return std::move(out);
}
//-------------------------------------------//
template<class TYPE>
static vector<TYPE*> subarr(const vector<TYPE>&arr,int offset)
{
  QapAssert(offset>=0);
  return std::move(subarr(arr,offset,arr.size()-offset));
}
*/
//-------------------------------------------//
template<class TYPE>
static void subarr_in_place(vector<TYPE>&arr,int offset)
{
  if(offset==0)return;
  QapAssert(offset>0);QapAssert(offset<arr.size());
  for(int i=0;i+offset<arr.size();i++){
    arr[i]=std::move(arr[i+offset]);
  }
  arr.resize(arr.size()-offset);
}
template<class TYPE>
vector<TYPE> qap_arr_slice(vector<TYPE>&arr,int offset)
{
  vector<TYPE> out;
  if(offset==0)return out;
  QapAssert(offset>0);QapAssert(offset<arr.size());
  offset=std::max<int>(0,std::min<int>(offset,arr.size()));
  for(int i=0;i<offset;i++){
    out.push_back(std::move(arr[i]));
  }
  subarr_in_place(arr,offset);
  return out;
}
template<class TYPE>
void qap_arr_join(vector<TYPE>&arr,vector<TYPE>&end)
{
  arr.reserve(arr.size()+end.size());
  for(int i=0;i<end.size();i++){
    arr.push_back(std::move(end[i]));
  }
}
//-------------------------------------------//
template<class TYPE>class TAutoPtr;
template<class TYPE>class TWeakPtr;
template<class TYPE>
void QapClean(vector<TAutoPtr<TYPE>>&Arr)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(!ex)continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
template<class TYPE>
void QapClean(vector<TWeakPtr<TYPE>>&Arr)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(!ex)continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
//-------------------------------------------//
template<class TYPE,class FUNC>
void QapCleanIf(vector<TYPE>&Arr,FUNC&Pred)
{
  int last=0;
  for(int i=0;i<Arr.size();i++)
  {
    auto&ex=Arr[i];
    if(Pred(ex))continue;
    if(last!=i)
    {
      auto&ax=Arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==Arr.size())return;
  Arr.resize(last);
}
//-------------------------------------------//
template<class TYPE>
void QapPopFront(vector<TYPE>&arr)
{
  int last=0;
  for(int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(last!=i)
    {
      auto&ax=arr[last];
      ax=std::move(ex);
    }
    last++;
  }
  if(last==arr.size())return;
  arr.resize(last);
}
template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}
//-------------------------------------------//
template<class TYPE,class FUNC>
static vector<int> qap_find(vector<TYPE>&arr,FUNC&func){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(func(ex))out.push_back(i);}
  return out;
}
//-------------------------------------------//
static vector<int> qap_find_str(const vector<string>&arr,const string&value){
  vector<int> out;
  for(int i=0;i<arr.size();i++){auto&ex=arr[i];if(ex==value)out.push_back(i);}
  return out;
}
//-------------------------------------------//
template<class TYPE,class FUNC>
static void qap_foreach(vector<TYPE>&inp,FUNC&func)
{
  auto&arr=inp;
  for(int i=0;i<arr.size();i++)
  {
    auto&ex=arr[i];
    func(ex);
  }
}
//-------------------------------------------//
template<class TYPE>
struct QapToolsVector
{
  vector<TYPE>&arr;
  void operator+=(vector<TYPE>&&ref)
  {
    arr.reserve(arr.size()+ref.size());
    for(int i=0;i<ref.size();i++)
    {
      arr.push_back(std::move(ref[i]));
    }
    ref.clear();
  }
};
//-------------------------------------------//
template<class TYPE>
QapToolsVector<TYPE> QapToolsVectorEx(vector<TYPE>&ref)
{
  QapToolsVector<TYPE> tmp={ref};return std::move(tmp);
}
//-------------------------------------------//
//   {<|          04.08.2014           |>}   //
//-------------------------------------------//