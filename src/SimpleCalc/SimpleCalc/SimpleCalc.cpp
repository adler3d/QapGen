#define DEF_PRO_FULL
#include <bitset>
#include "FromQapEng.h"
//#include "QapMicro2/QapTools.h"
typedef unsigned char uchar;
size_t g_unique_pool_ptr_counter=0;

#define QAP_USE_UNIQUE_POOL_PTR
#define QAP_STD_DEBUG
#ifdef QAP_STD_DEBUG
#define QAP_LOAD_OBJ_DEBUG
#define QAP_POLY_TOOL_DEBUG
#else
//#define QAP_WITHOUT_ALL_DEBUG
#endif
#ifdef QAP_WITHOUT_ALL_DEBUG
#undef QapAssert
#undef QapNoWay
#undef QapDebugMsg
#define QapAssert(CODE){CODE;}
#define QapNoWay(...){}
#define QapDebugMsg(...){}
#endif
#ifndef QAP_USE_UNIQUE_POOL_PTR
#define TAutoPtr unique_ptr
#else
#include "unique_pool_ptr.hpp"
#define TAutoPtr UniquePoolPtr
#define make_unique make_unique_pool
#endif
#include "detail.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
string g_qap_poly_tool_config_path;
string g_qap_poly_tool_config_path2;
#include "t_poly_tool.inl"

#include "t_simple_calc.inl"

struct t_simple_calc_evalutor:t_simple_calc{
  typedef t_simple_calc t_ast;
  struct t_go:i_term_visitor{
    void Do(t_number*ptr){Do(*ptr);}
    void Do(t_scope*ptr){Do(*ptr);}
    template<class TYPE>void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(ex);}
    void Do(t_term&ref){
      auto*ptr=ref.value.get();
      ptr->Use(*this);
    }
    void Do(t_number&ref){
      rv=t_rv{"imm",ref.value};
      v=std::stod(ref.value);
    }
    void Do(t_scope&ref){
      Do(ref.value);
    }
    void Do(t_divmul&ref){
      Do(ref.first);
      auto cur_rv=rv;
      auto cur=v;
      for(auto&ex:ref.arr){
        Do(ex.expr);
        if("/"==ex.oper)cur/=v;
        if("*"==ex.oper)cur*=v;
        if("/"==ex.oper)cur_rv=div(cur_rv,rv);
        if("*"==ex.oper)cur_rv=mul(cur_rv,rv);
      }
      v=cur;
      rv=cur_rv;
    }
    void Do(t_addsub&ref){
      Do(ref.first);
      auto cur_rv=rv;
      auto cur=v;
      for(auto&ex:ref.arr){
        Do(ex.expr);
        if("+"==ex.oper)cur+=v;
        if("-"==ex.oper)cur-=v;
        if("+"==ex.oper)cur_rv=add(cur_rv,rv);
        if("-"==ex.oper)cur_rv=sub(cur_rv,rv);
      }
      v=cur;
      rv=cur_rv;
    }
    struct t_rv{
      string type;
      string value;
      string get_reg()const{
        auto t=split(value,"\n");
        if(t.back().empty())t.pop_back();
        auto b=t.back();
        return split(b,"=")[0];
      }
      int get_reg_id()const{
        return std::stoi(split(get_reg(),"\2")[0].substr(1));
      }
    };
    t_rv rv_do(string cmd,t_rv a,t_rv b){
      int reg_id=0;
      auto reg=[](int reg_id){return "\1"+std::to_string(reg_id)+"\2";};
      auto alloc_reg=[&](){return reg(reg_id++);};
      auto foo=[&](const t_rv&a){
        if(a.type!="imm")return a;
        auto reg=alloc_reg();
        return t_rv{"asm",reg+"="+a.value};
      };
      auto fix=[&](const t_rv&a,int bef,int aft){
        return t_rv{"asm",join(split(a.value,reg(bef)),reg(aft))};
      };
      string out;
      auto ra=foo(a);auto a_id=ra.get_reg_id();reg_id=a_id+1;
      auto rb=foo(b);auto b_id=rb.get_reg_id();reg_id=std::max(a_id+1,b_id+1);
      for(int i=0;i<=b_id;i++)if(i<=a_id)if(rb.value.find(reg(i))!=std::string::npos)rb=fix(rb,i,reg_id++);
      out+=ra.value+"\n";
      out+=rb.value+"\n";
      out+=alloc_reg()+"="+cmd+"("+ra.get_reg()+","+rb.get_reg()+")\n";
      return t_rv{"asm",out};
    }
    t_rv div(t_rv a,t_rv b){
      return rv_do("div",a,b);
    }
    t_rv mul(t_rv a,t_rv b){
      return rv_do("mul",a,b);
    }
    t_rv add(t_rv a,t_rv b){
      return rv_do("add",a,b);
    }
    t_rv sub(t_rv a,t_rv b){
      return rv_do("sub",a,b);
    }
    real v=0;
    t_rv rv;
  };
};
#include <iostream>
#ifdef _WIN32
#pragma comment(lib,"user32")
#pragma comment(lib,"shell32.lib")
#endif
void main_2021(){
  for(;;){
    std::cout<<"type expr below and press enter: "<<endl;
    string inp;
    std::cin>>inp;
    cout<<std::endl;
    string input=inp;//"100+2*(10+1*2)+30/2-15-16-3/1+3.14/2.5*1-1000";
    t_simple_calc::t_addsub ast;
    auto ok=load_obj(ast,input);
    int gg=1;
    t_simple_calc_evalutor::t_go go;
    go.Do(ast);
    string output=join(split(join(split(go.rv.value,"\1"),"r"),"\2"),"");
    std::cout<<output<<std::endl;
    std::cout<<"Result: "<<go.v<<std::endl<<std::endl;
  }
  int gg2=2;
}

int main(int argc,char*argv[])
{
  main_2021();
  return 0;
}

//-----
#undef DEF_PRO_FULL