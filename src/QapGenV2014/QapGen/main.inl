//-------------------------------------------//
#if(defined(_CSTDLIB_)||defined(_WINDOWS_))
  static_assert(false,"fail");
#endif
//-------------------------------------------//
#if(!defined(DEF_BUILD_MICRO)&&!defined(DEF_BUILD_MACRO)&&!defined(DEF_BUILD_DEFAULT))
  #define DEF_BUILD_DEFAULT
  //`MICRO - compile with key /P /EP /C
  //`MACRO - full compile
#endif
//-------------------------------------------//
#ifdef DEF_BUILD_MICRO
  #define _WINDOWS_
  #define _D3D9_H_
#else
  //#define NOMENUS
  //#define NOHELP
  #define NOMENUS
  #define NOHELP
  #define NOPROFILER
  #define NOKANJI
  #define NOWH
  #define NOSERVICE
  #define NOMINMAX
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
  #include <d3d9.h>
  #pragma comment(lib,"d3d9")
  #pragma comment(lib,"user32")
  #pragma comment(lib,"gdi32")
#endif //DEF_BUILD_MICRO//
//-------------------------------------------//
#ifdef DEF_BUILD_MICRO
  #include "QapMicro\QapAssert.h"
  //`#include "QapMicro\NakedIO.h"
  //`#include "QapMicro\QapClock.h"
#else
  #include "QapMicro\QapAssert.h"
  #include "QapMicro\QapIO.h"
  #include "QapMicro\QapClock.h"
#endif //DEF_BUILD_MICRO//
//-------------------------------------------//
#include "CppString.inl"
//-------------------------------------------//
#include "part0.inl"
#include "detail.inl"
#include "part5.inl"
#include "ptr.inl"
#include "part1.inl"
#include "memory.inl"
#include "IEnvRTTI.inl"
#include "part2.inl"
#include "part3.inl"
#include "QapMicro\QapVec.h"
#include "DeclareEnvRTTI.inl"
#include "part4.inl"
//-------------------------------------------//