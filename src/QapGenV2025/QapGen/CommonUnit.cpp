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
int main()
{
  return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL);
}

//#include "main2.inl"
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //auto&comp_unit_man=TCompileUnitMan::get_man();
  //for(;;);
  int x=HToC("88");
  int z=HToI_raw("11BBCCDD");
  if(z==0x11BBCCDD){
    int gg=1;
  }
  test_2025_06_10();
  return 0;
}
#else
int main()
{
  test_2025_06_10();
  return 0;
}
#endif


//-----
#undef DEF_PRO_FULL