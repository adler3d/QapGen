#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include "QapType.h"
//-------------------------------------------//
#ifndef DEF_BUILD_MICRO
  #if defined(_DEBUG)||defined(QAP_KEEP_ASSERTS)
    #define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
    #define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCTION__))_CrtDbgBreak();}
    #define QapNoWay(){QapDebugMsg("no way!");}
  #else
    #define QapAssert(_Expression)if(bool(_Expression)){};
    #define QapDebugMsg(_Message)
    #define QapNoWay()
  #endif
#endif //DEF_BUILD_MICRO//
//-------------------------------------------//
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname);
inline bool SysQapDebugMsg(const string&msg,bool&ignore,const string&filename,const int line,const string&funcname);
//-------------------------------------------//
#include "QapTools.h"
//-------------------------------------------//
enum QapMsgBoxRetval{
  qmbrSkip,qmbrBreak,qmbrIgnore
};
inline int WinMessageBox(const string&caption,const string&text){
  string full_text=text+"\n\n    [Skip]            [Break]            [Ignore]";
  const int nCode=MessageBoxA(NULL,full_text.c_str(),caption.c_str(),MB_CANCELTRYCONTINUE|MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  QapMsgBoxRetval retval=qmbrSkip;
  if(IDCONTINUE==nCode)retval=qmbrIgnore;
  if(IDTRYAGAIN==nCode)retval=qmbrBreak;
  return retval;
}
typedef int(*TQapMessageBox)(const string&caption,const string&text);
struct TMessageBoxCaller{
  static int Call(const string&caption,const string&text){
    return Get()(caption,text);
  }
  static TQapMessageBox&Get(){
    static TQapMessageBox func=WinMessageBox;
    return func;
  }
  struct t_hack{
    TQapMessageBox old;
    t_hack(TQapMessageBox func){old=Get();Get()=func;}
   ~t_hack(){Get()=old;}
  };
};
inline bool SysQapAssert(const string&exp,bool&ignore,const string&filename,const int line,const string&funcname)
{
  if(ignore)return false;
  std::string text="Source file :\n"+filename
    +"\n\nLine : "+IToS(line)
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
    +"\n\nLine : "+IToS(line)
    +"\n\nFunction :\n"+funcname
    +"\n\nDebug message :\n"+msg;
  auto retval=(QapMsgBoxRetval)TMessageBoxCaller::Call("Debug message",text);
  if(qmbrIgnore==retval)ignore=true;
  return qmbrBreak==retval;
}
//-------------------------------------------//
//   {<|          10.10.2014           |>}   //
//-------------------------------------------//