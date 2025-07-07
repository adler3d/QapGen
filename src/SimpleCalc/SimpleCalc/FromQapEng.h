#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #define NOMINMAX
  #undef UNICODE
  #include <windows.h>
  #include <intrin.h>
#endif
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
//#include <tchar.h>
#ifndef _WIN32
#ifdef __EMSCRIPTEN
#include <emscripten.h>
#endif
#else
#endif
#include <vector>
#include <map>
#include <functional>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <atomic>
#include <thread>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <string>
#include <memory>
#include <array>
#include <math.h>
#include <iomanip>
#include <iostream>
//#include <ctype.h>

enum TMouseButton{mbLeft=257,mbRight=258,mbMiddle=259,};
auto now=std::chrono::high_resolution_clock::now;
typedef std::chrono::duration<double, std::milli> dms;
double dmsc(dms diff){return diff.count();}
using namespace std;
//#include "thirdparty/sweepline/sweepline.hpp"
template<typename TYPE>TYPE Sign(TYPE value){if(value>0){return TYPE(+1);}else{return TYPE(value<0?-1:0);}};
#define QAP_DEBUG
#ifdef _WIN32
class QapClock{
public:
  typedef long long int int64;
  int64 freq,beg,tmp;
  bool run;
public:
  QapClock(){QueryPerformanceFrequency((LARGE_INTEGER*)&freq);run=false;tmp=0;Start();}
  void Start(){QueryPerformanceCounter((LARGE_INTEGER*)&beg);run=true;}
  void Stop(){QueryPerformanceCounter((LARGE_INTEGER*)&tmp);run=false;tmp-=beg;}
  double Time(){if(run)QueryPerformanceCounter((LARGE_INTEGER*)&tmp);return run?double(tmp-beg)/double(freq):double(tmp)/double(freq);}
  double MS()
  {
    double d1000=1000.0;
    if(run)QueryPerformanceCounter((LARGE_INTEGER*)&tmp);
    if(run)return (double(tmp-beg)*d1000)/double(freq);
    if(!run)return (double(tmp)*d1000)/double(freq);
    return 0;
  }
  static int64 qpc(){int64 tmp;QueryPerformanceCounter((LARGE_INTEGER*)&tmp);return tmp;}
};
QapClock g_sys_clock;
#define QAP_EM_LOG(TEXT)
#else
#ifndef __EMSCRIPTEN__
//https://github.com/copilot/share/c05603ac-4240-8476-b813-be01a48a201d
#include <chrono>
class QapClock{
public:
  typedef long long int int64;
  int64 freq,beg,tmp;
  bool run;
  typedef std::chrono::high_resolution_clock clock;
  typedef std::chrono::time_point<clock> time_point;
  time_point t_beg,t_tmp;
public:
  QapClock(){Start();}
  #define F(diff)std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
  void Start(){t_beg=clock::now();run=true;}
  void Stop(){t_tmp=clock::now();run=false;tmp=F(t_tmp-t_beg);}
  double MS(){
    if(run){t_tmp=clock::now();return F(t_tmp-t_beg)*0.001;}
    return double(tmp)*0.001;
  }
  static int64 qpc(){return F(clock::now().time_since_epoch());}
  #undef F
};
#define QAP_EM_LOG(TEXT)
#else
class QapClock{
public:
  typedef long long int int64;
  int64 freq,beg,tmp;
  bool run;
public:
  QapClock(){Start();}
  void Start(){beg=qpc();run=true;}
  void Stop(){run=false;tmp=qpc()-beg;}
  double MS(){
    if(run){tmp=qpc();return (tmp-beg)*0.001;}
    return tmp*0.001;
  }
  static int64 qpc(){return EM_ASM_INT({return (1000*performance.now())|0;});}
};
#define QAP_EM_LOG(TEXT)EM_ASM({console.log(UTF8ToString($0));},string(TEXT).c_str());
#endif //__EMSCRIPTEN__
#endif //_WIN32
#ifndef _WIN32
#define VK_SLEEP          0x5F
#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87
#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F
#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D
#define VK_BACK           0x08
#define VK_TAB            0x09
#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#endif
#ifdef __EMSCRIPTEN__
static string file_get_contents(const string&fn){
  QAP_EM_LOG("file_get_contents:"+fn);
  int length=EM_ASM_INT({
    let key=UTF8ToString($0);
    let val=localStorage.getItem(key);
    if(val===null)return 0;
    return lengthBytesUTF8(val);
  },fn.c_str());
  if(!length)return {};
  string out;out.resize(length);
  EM_ASM({
    let key=UTF8ToString($0);
    let val=localStorage.getItem(key);
    if(val!==null)stringToUTF8(val,$1,$2+1);
  },fn.c_str(),out.data(),length);
  return out;
}
static bool file_put_contents(const string&fn,const string&mem){
  QAP_EM_LOG("file_put_contents:"+fn);
  EM_ASM({
    let key=UTF8ToString($0);
    let val=UTF8ToString($1);
    localStorage.setItem(key,val);
  },fn.c_str(),mem.c_str());
  return true;
}
#else
static bool file_put_contents(const string&FN,const string&mem){std::fstream f(FN,std::ios::out|std::ios::trunc);f<<mem;return true;}
static string file_get_contents(const string&fn){std::ifstream file(fn);return std::string((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));}
#endif

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
struct TScreenMode{
  int W,H,BPP,Freq;
};
struct TSys{int UPS=128;TScreenMode SM;bool UPS_enabled=true;bool NeedClose=false;void ResetClock(){}}; TSys Sys;
static const int Sys_UPD=64;
inline string IToS(const int&val){return to_string(val);}
inline string FToS(const double&val){return to_string(val);}
inline string FToS2(const float&val){std::stringstream ss;ss<<std::fixed<<std::setprecision(2)<<val;return ss.str();}
#ifdef __EMSCRIPTEN__
#define __debugbreak()EM_ASM({throw new Error("__debugbreak");});
#else
  #ifndef _WIN32
  #define __debugbreak()__builtin_trap()
  #endif
#endif
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
#if(defined(_DEBUG)||defined(QAP_DEBUG))
#define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCTION__))__debugbreak();}
#else
#define QapAssert(_Expression)if(bool(_Expression)){};
#endif
#if(defined(_DEBUG)||defined(QAP_DEBUG))
#define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCTION__))__debugbreak();}
#else
#define QapDebugMsg(_Message)
#endif
#if(defined(_DEBUG)||defined(QAP_DEBUG))
#define QapNoWay(){QapDebugMsg("no way!");}
#else
#define QapNoWay()
#endif
enum QapMsgBoxRetval{qmbrSkip,qmbrBreak,qmbrIgnore};
inline int WinMessageBox(const string&caption,const string&text)
{
  #ifdef _WIN32
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
  #else
  #ifdef __EMSCRIPTEN__
  EM_ASM({alert(UTF8ToString($0)+"\n"+UTF8ToString($1));},int(caption.c_str()),int(text.c_str()));
  return qmbrBreak;
  #else
  std::cerr<<caption<<"\n"<<text<<endl;
  return qmbrBreak;
  #endif
  #endif
}
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller
{
  static int Call(const string&caption,const string&text)
  {
    return Get()(caption,text);
  }
  static TQapMessageBox&Get()
  {
    static TQapMessageBox func=WinMessageBox;
    return func;
  }
  struct t_hack
  {
    TQapMessageBox old;
    t_hack(TQapMessageBox func)
    {
      old=Get();
      Get()=func;
    }
    ~t_hack()
    {
      Get()=old;
    }
  };
};
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+std::to_string(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nAssertion failed :\n"+exp;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Assertion failed",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
      +"\n\nLine : "+std::to_string(line)
      +"\n\nFunction :\n"+funcname
      +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
class CrutchIO{
public:
  static bool FileExist(const string&FN)
  {
    std::fstream f;
    f.open(FN.c_str(),std::ios::in|std::ios::binary);
    return f.is_open();
  }
private:
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
public:
  int pos;
  string mem;
  CrutchIO():mem(""),pos(0){};
  bool LoadFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    //printf("f->size=%i\n",L);
    //printf("f->Chcount=%i\n",f._Chcount);
    f.close(); pos=0;
    return true;
  };
  bool SaveFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)return false;
    if(!mem.empty())f.write(&mem[0],mem.size());
    f.close(); pos=0; int L=mem.size();
    return true;
  };
  void read(char*c,int count)
  {
    for(int i=0;i<count;i++)c[i]=mem[pos++];//FIXME: тут можно юзать memcpy
  };
  void write(char*c,int count)
  {
    //mem.reserve(max(mem.capacity(),mem.size()+count));
    int n=mem.size();
    mem.resize(n+count);//Hint: resize гарантировано копирует содержимое.
    for(int i=0;i<count;i++)mem[n+i]=c[i];//FIXME: тут можно юзать memcpy
    pos+=count;
  };
};
template<typename TYPE,size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){
  return COUNT;
}
//template<class TYPE>inline TYPE Lerp(const TYPE&A,const TYPE&B,const real&v){return A+(B-A)*v;}
template<class TYPE>inline TYPE Clamp(const TYPE&v,const TYPE&a,const TYPE&b){return max(a,min(v, b));}
std::string cur_date_str() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    
    std::tm tm_struct = *std::localtime(&now_c);
    
    std::stringstream dateStream;
    dateStream << std::setfill('0')
               << std::setw(4) << (tm_struct.tm_year + 1900) << '.'
               << std::setw(2) << (tm_struct.tm_mon + 1) << '.'
               << std::setw(2) << tm_struct.tm_mday << ' '
               << std::setw(2) << tm_struct.tm_hour << ':'
               << std::setw(2) << tm_struct.tm_min << ':'
               << std::setw(2) << tm_struct.tm_sec;
    
    return dateStream.str();
}

typedef double real;
typedef long long int int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned char uchar;

class CharMask{
public:
  array<bool,256> mask;
  CharMask(CharMask&&ref){for(uint i=0;i<sizeof(mask);i++)mask[i]=ref.mask[i];}
  CharMask(){for(uint i=0;i<sizeof(mask);i++)mask[i]=false;}
public:
  static CharMask fromStr(const string&str,bool weak=false)
  {
    CharMask tmp;
    tmp.prepare(str,weak);
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
  void prepare(const std::string&allowed,bool weak=false)
  {
    for(uint i=0;i<sizeof(mask);i++)mask[i]=false;
    for(uint i=0;i<uint(allowed.size());i++)
    {
      unsigned char uc=uchar(allowed[i]);
      bool&flag=mask[uc];
      if(!weak)QapAssert(!flag);
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
inline string BToS(const bool&val){return val?"true":"false";};
inline bool SToB(const string&str,bool&val){val=str=="true";return true;}
inline bool SToB(const string&str){return str=="true";}
inline bool SToC(const string&str,char&val){if(str.size()!=1)return false;val=str[0];return true;}
inline string SToS(const string&s){return s;}
template<size_t COUNT> inline string SToS(const char(&lzstr)[COUNT]){static_assert(COUNT,"WTF?");return string(&lzstr[0],size_t(COUNT-1));}
inline string SToSex(const string&S,const int&l){string s(l,' ');for(int i=0;i<int(S.size());i++)s[i]=S[i];return s;}
inline std::string CToH_raw(const unsigned char& val) {
  std::stringstream stream;
  stream << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(val);
  return stream.str();
}
inline char HToC(const std::string&str)    {return static_cast<char>(std::stoul(str,nullptr,16));}
inline int  HToI_raw(const std::string&str){return static_cast<int>(std::stoul(str,nullptr,16));}
inline int SToI(const string&s){return std::stoi(s);};
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
/*template<class TYPE>
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
*///-------------------------------------------//
static string gen_dip(char from,char to){
  auto f=(uchar)from;
  auto t=(uchar)to;
  QapAssert(f<t);
  string out;
  out.reserve(t-f);
  bool flag=f!=t;
  for(auto c=f;flag;c++){
    flag=flag&&(c!=t);
    out.push_back((char)c);
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
template<size_t size>
static string gen_dips(const char(&rule)[size]){
  string s;
  s.resize(size-1);int i=-1;
  for(auto&ex:rule){s[++i]=ex;}
  return gen_dips(s);
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
/*static vector<string> split(const string&s,const string&needle)
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
}*/
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
void QapCleanIf(vector<TYPE>&Arr,FUNC&&Pred)
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
/*template<class TYPE>
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
}*/
template<class TYPE>static TYPE&qap_add_back(vector<TYPE>&arr){arr.push_back(TYPE());return arr.back();}
//-------------------------------------------//
template<class TYPE,class FUNC>
static vector<int> qap_find(vector<TYPE>&arr,FUNC&&func){
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
static void qap_foreach(vector<TYPE>&inp,FUNC&&func)
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
template<class TYPE>bool qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}


template<class TYPE,class FUNC>
int qap_minval_id_for_vec(vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  decltype(func(arr[0],0)) val;int id=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(!i||tmp<val){
      val=tmp;id=i;
    }
  }
  return id;
}
template<class TYPE,class FUNC>
int qap_minval_id_for_vec(const vector<TYPE>&arr,FUNC func){
  if(arr.empty())return -1;
  decltype(func(arr[0],0)) val;int id=-1;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    auto tmp=func(ex,i);
    if(!i||tmp<val){
      val=tmp;id=i;
    }
  }
  return id;
}

template<class TYPE>
static void operator+=(vector<TYPE>&dest,const vector<TYPE>&arr){
  for(int i=0;i<arr.size();i++){
    dest.push_back(arr[i]);
  }
}

//template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}
template<class TYPE>int qap_includes_v2(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return i;}return -1;}

#define QAP_MINVAL_ID_OF_VEC(arr,code)qap_minval_id_for_vec(arr,[&](decltype(arr[0])&ex,int i){return code;})

template<class TYPE,class FUNC>void qap_foreach(TYPE&&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
template<class TYPE,class FUNC>void qap_foreach(const TYPE&arr,FUNC func){auto n=arr.size();for(int i=0;i<n;i++)func(arr[i],i);}
#define QAP_FOREACH(arr,code)qap_foreach(arr,[&](decltype(arr[0])&ex,int i){code;})

#include <string>
#include <vector>
#include <algorithm>

#include "CppString.inl"
struct t_ranges_result {
  std::string ranges;  // пары символов дл€ диапазонов (start < end)
  std::string singles; // одиночные символы
};
t_ranges_result build_ranges_string(const std::string& chars) {
  t_ranges_result result;
  if (chars.empty()) return result;
  size_t start = 0;
  size_t n = chars.size();
  while (start < n) {
    size_t end = start;
    // »щем максимальный диапазон подр€д идущих символов
    while (end+1<n&&((uchar)chars[end+1])==(((uchar)chars[end])+1)){
      ++end;
    }
    if (end == start) {
      // ќдиночный символ
      result.singles.push_back(chars[start]);
    } else {
      // ƒиапазон из нескольких символов
      result.ranges.push_back(chars[start]);
      result.ranges.push_back(chars[end]);
    }
    start = end + 1;
  }
  return result;
}


std::string escape_char(char c,bool str=true) {
  unsigned char uc = static_cast<unsigned char>(c);
  switch (uc) {
    case '\\': return "\\\\";
    case '\"': return str?"\\\"":"\"";
    case '\n': return "\\n";
    case '\r': return "\\r";
    case '\t': return "\\t";
    case '\'': return str?"'":"\\'";
    default:
      if (uc >= 32 && uc <= 126) { // ѕечатные ASCII символы
        return std::string(1, c);
      } else {
          // Ёкранируем все остальные в \xHH
        const char hex_chars[] = "0123456789ABCDEF";
        std::string res = "\\x";
        res += hex_chars[(uc >> 4) & 0xF];
        res += hex_chars[uc & 0xF];
        return res;
      }
  }
}

std::string generate_gen_dips_code(const std::string&chars){
  if (chars.empty()) return "\"\"";
  if(chars.size()==1)return "\""+escape_char(chars[0])+"\"";
  if(chars.size()<16){
    std::string escaped;
    for(char c:chars){escaped+=escape_char(c);}
    return "\""+escaped+"\"";
  }
  std::string sorted_chars = chars;
  auto r=build_ranges_string(sorted_chars);
  auto r2=(gen_dips(r.ranges)+r.singles);
  auto m=CharMask::fromStr(r2,true);
  string u;
  for(size_t i=0;i<256;i++)if(m.mask[i])u.push_back((char)i);
  QapAssert(sorted_chars==u);
  string out,so;
  for(auto&ex:r.ranges)out+=escape_char(ex);//CppString::toCode((uchar&)ex);
  for(auto&ex:r.singles)so+=escape_char(ex);
  // √енерируем вызов gen_dips
  if(!out.empty()){
    out="gen_dips(\""+out+"\")";
  }else QapAssert(so.size());
  if(!so.empty())so=string(out.empty()?"":"+")+"\""+so+"\"";
  std::string code=out+so;
  return code;
}

