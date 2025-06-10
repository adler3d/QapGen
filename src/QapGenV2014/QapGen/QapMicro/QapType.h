#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#ifndef DEF_BUILD_MICRO
  #include <algorithm>
  #include <string>
  #include <vector>
  #include <memory>
  #include <map>
  #include <fstream>
  #include <sstream>
  #include <array>
  #include <time.h>
  #include <math.h>
#endif //DEF_BUILD_MICRO
//-------------------------------------------//
using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::stringstream;
using std::array;
using std::unique_ptr;
//using std::auto_ptr;
//-------------------------------------------//
typedef double real;
typedef INT64 int64;
typedef UINT64 uint64;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef vector<string> StringArray;
typedef vector<void*> PtrArray;
//-------------------------------------------//
//#pragma warning(disable:4800)
//#pragma warning(disable:4018)
//#pragma warning(disable:4244)
//-------------------------------------------//
//   {<|          17.10.2014           |>}   //
//-------------------------------------------//