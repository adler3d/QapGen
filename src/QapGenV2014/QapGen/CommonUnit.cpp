#define DEF_PRO_FULL
#define ThisCompileUnit ThisCompileUnit$QapPublicUberXImpl
#define ThisCompileUnitInstance ThisCompileUnitInstance$QapPublicUberXImpl
#include "QapPublicUberXImpl.cpp"
#undef ThisCompileUnitInstance
#undef ThisCompileUnit

#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"

#include "visitor_gen.h"
template<class TYPE>int qap_includes(const vector<TYPE>&arr,const TYPE&value){for(int i=0;i<arr.size();i++){if(arr[i]==value)return true;}return false;}

#include <iostream>
void main_2021(IEnvRTTI&Env){
  //{Sys$$<t_simple_calc>::GetRTTI(Env);};
  //t_simple_calc::t_addsub ast;
  string inp;
  for(;!std::cin.eof();){
    std::cin>>inp;inp+="\n";
  }
  string input=inp;//"100+2*(10+1*2)+30/2-15-16-3/1+3.14/2.5*1-1000";
  //auto ok=load_obj(Env,ast,input);
  //std::cout<<"Result: "<<go.v<<std::endl<<std::endl;
  //string output=join(split(join(split(go.rv.value,"\1"),"r"),"\2"),"");
  //std::cout<<output<<std::endl;
  int gg2=2;
}

int main()
{
  return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL);
}

#include "main2.inl"
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  auto&comp_unit_man=TCompileUnitMan::get_man();
  //string unit_name=comp_unit_man.arr[0]->get_filename();
  //static GlobalEnv gEnv(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TStdAllocator MA;
  {
    TEnvRTTI Env;
    Env.Arr.reserve(1024);
    Env.Alloc=&MA;
    Env.OwnerEnv=&Env;
    TCompileUnitMan::reg_and_run_all(Env);
    main_2021(Env);
    if(0)Env.OwnerEnv=nullptr;
  }
  return 0;
}


//-----
#undef DEF_PRO_FULL