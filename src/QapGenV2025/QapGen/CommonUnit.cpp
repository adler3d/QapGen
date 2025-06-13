#define DEF_PRO_FULL
#include "FromQapEng.h"
//#include "QapMicro2/QapTools.h"
typedef unsigned char uchar;
#include "CppString.inl"
#define TAutoPtr unique_ptr
#include "detail.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"

#include "visitor_gen.h"
template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}

#include <iostream>
#ifdef _WIN32
#include <shellapi.h>
int main()
{
  return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL);
}
#include "out.hpp"
/*
  static i_foobarbaz*id2instance(int id){
    int i=0;
    #define ADD(U)if(i++==id)return new t_branch_lexem::U();
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    return nullptr;
  }
*/
//#include "json_lexer.hpp"
//#include "main2.inl"
/*
  public:
    static i_foobarbaz*id2instance(int id){
      int i=0;
      #define ADD(U)if(i++==id)return new t_branch_lexem::U();
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      return nullptr;
    }*/
void UberCast_bench2(){
  //vector<t_branch_lexem::i_foobarbaz*> arr;
  //for(int i=0;i<10000000;i++)arr.push_back(t_branch_lexem::id2instance(rand()%128));
  //vector<size_t> out;out.resize(arr.size());
  //QapClock c;
  //for(auto&ex:arr){
  //  auto*q=t_branch_lexem::t_foobarbaz_v53::UberCast(ex);
  //  size_t qw=size_t(q)*size_t(q);
  //  out.push_back(qw);
  //}
  //auto ms=c.MS();
  //cerr<<ms<<endl;
  //out.clear();
  //QapClock c2;
  //for(auto&ex:arr){
  //  auto*q=dynamic_cast<t_branch_lexem::t_foobarbaz_v53*>(ex);
  //  size_t qw=size_t(q)*size_t(q);
  //  out.push_back(qw);
  //}
  //auto ms2=c2.MS();
  //cerr<<ms2;
  // 19.85 sec -- 18.28 -- 18.98  // 701 Êֱ (718 336 באיע)
  // 12.94 sec -- 13.63           // 701 Êֱ (717 824 באיע)
  // 12.49 sec -- 11.17
  // 21.76 sec
  // 29.22+26.95+30.21+27.21 empty  28.3975
  // 30.45+35.17+33.54+32.95                         dycast 33.0275 // 4.63 sec // 36.17 ms/cast
  // 39.59+41.59+34.35+35.93+33.79+38.20+37.33+37.61 ubcast 37.29   // 8.90 sec // 69.54 ms/cast
}
/*
void UberCast_bench(){
  t_branch_lexem::i_case*ptr=new t_branch_lexem::t_hard();
  t_branch_lexem::i_case*wtr=new t_branch_lexem::t_soft();
  vector<t_branch_lexem::i_case*> arr;
  for(int i=0;i<10000000;i++)arr.push_back(rand()%2?ptr:wtr);
  vector<size_t> out;out.resize(arr.size());
  QapClock c;
  for(auto&ex:arr){
    auto*q=t_branch_lexem::t_hard::UberCast(ex);
    size_t qw=size_t(q)*size_t(q);
    out.push_back(qw);
  }
  auto ms=c.MS();
  out.clear();
  QapClock c2;
  for(auto&ex:arr){
    auto*q=dynamic_cast<t_branch_lexem::t_hard*>(ex);
    size_t qw=size_t(q)*size_t(q);
    out.push_back(qw);
  }
  auto ms2=c2.MS();
  cerr<<ms<<" "<<ms2;
}
*/
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //TAutoPtr<t_json::i_value> json;
  //auto r=load_obj_full(json,"[1, 2, {\"a\":-10.5e2}]");
  //r.msg;
  UberCast_bench2();
  int argc=0;
  LPWSTR*argv=CommandLineToArgvW(GetCommandLineW(),&argc);
  string fn;if(argc>1)fn.resize(wcslen(argv[1]));
  if(fn.size())wcstombs(&fn[0],argv[1],wcslen(argv[1])+1);
  test_2025_06_10(fn);
  return 0;
}
#else
int main(int argc,char*argv[])
{
  string fn;
  if(argc>1)fn=argv[1];
  test_2025_06_10(fn);
  return 0;
}
#endif


//-----
#undef DEF_PRO_FULL