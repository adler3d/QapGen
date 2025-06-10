#include "StdAfx.h"

#include "templ_lexer_v02.inl"
#include "meta_lexer.inl"

#include "templ_lexer_v03.inl"

extern void UberInfoBox(const string&caption,const string&text);

class t_templ_sys_v04{
public:
  class t_scope{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_scope)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,head,DEF,$,$)\
  ADDVAR(t_templ_sys_v02,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_scope
  #include "QapGenStruct.inl"
  //<<<<<+=====t_scope
  };
public:
#define DEF_PRO_NESTED(F)F(t_scope)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_templ_sys_v04)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_scope>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_templ_sys_v04
#include "QapGenStruct.inl"
//<<<<<+=====t_templ_sys_v04
public:
  void load(IEnvRTTI&Env,t_templ_sys_v03&v3)
  {
    arr.resize(v3.arr.size());
    for(int i=0;i<arr.size();i++)
    {
      arr[i].head=v3.arr[i].head.name;
      auto&ex=arr[i].body;
      auto&data=v3.arr[i].body;
      load_obj(Env,ex,data);
    }
  }
public:
  static string move_block(const string&source,const string&sep){
    //string tmp=moveleft(source);
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    return sep+join(arr,"\n"+sep);
  }
  static vector<string> get_parent_list(const vector<t_target_item::t_out>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.parent.empty())continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(ex.parent==out[j]);
      if(flag)continue;
      out.push_back(ex.parent);
    }
    return out;
  }
  static vector<string> get_child_list(const vector<t_target_item::t_out>&arr,const string&parent)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      if(arr[i].parent==parent){
        out.push_back(arr[i].name);
      }
    }
    return out;
  }
  static vector<string> get_nested_list(const vector<t_struct_body::t_target_item_out>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out.push_back(ex.name);
    }
    return out;
  }
public:
  static string pad_end(const string&s,size_t ms){
    return s+string(ms-s.size(),' ');
  }
  static string get_nested_def(const vector<string>&arr)
  {
    if(arr.empty())return "";
    size_t ms=0;
    for(int i=0;i<arr.size();i++){
      ms=std::max<size_t>(ms,arr[i].size());
    }
    vector<string> out;
    out.push_back("  /*<DEF_PRO_NESTED>*/\\");
    for(int i=0;i<arr.size();i++){
      out.push_back("  F("+pad_end(arr[i],ms)+")\\");
    }
    out.push_back("  /*</DEF_PRO_NESTED>*/");
    return "public:\n#define DEF_PRO_NESTED(F)\\\n"+join(out,"\n")+"\n";
  }
  string make_head(
    IEnvRTTI&Env,
    const vector<t_struct_body::t_target_item_out>&arr,
    const string&name,
    const string&parent,
    const string&owner,
    const vector<string>&nested_list
  ){
    string out;
    string parent_part=!parent.empty()?":public "+parent:"";
    string parent_info=!parent.empty()?"PARENT("+parent+")":"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    string target_code=get_target_code(Env,arr,name);
    bool hasVirtual=false;
    for(int i=0;i<arr.size();i++)if(!arr[i].parent.empty())hasVirtual=true;
    string class_code;
    class_code+="class "+name+parent_part+"{\n";
    class_code+=target_code.empty()?"":((hasVirtual?"":"public:\n")+target_code+"\n");
    class_code+=get_nested_def(nested_list);
    class_code+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    class_code+="NAME("+name+")"+parent_info+owner_info;
    out+=move_block(class_code,owner.empty()?"":"  ")+"\n";
    //out+="#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\\\n";
    return out;
  }
  t_templ_sys_v02&get_templ(const string&name)
  {
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(ex.head==name)return arr[i].body;
    }
    QapDebugMsg("no way for:\n"+name);
    return *(t_templ_sys_v02*)nullptr;
  }
public:
  static vector<string> viz_with_add(const vector<string>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++)out.push_back("  ADD("+arr[i]+")\\");
    return out;
  }
  static vector<string> viz_with_doo(const vector<string>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++)out.push_back("  virtual void Do("+arr[i]+"*p)=0;");
    return out;
  }
  static vector<string> viz_with_cdo(const vector<string>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++)out.push_back("  //  void Do("+arr[i]+"*p){}");
    return out;
  }
public:
  string iclass_to_code(IEnvRTTI&Env,const string&name,const vector<string>&arr,const string&owner)
  {
    string out;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",name);
      inp.add("OWNER",owner);
      inp.add("ADDLIST",join(viz_with_add(arr),"\n"));
      inp.add("DO_LIST",join(viz_with_doo(arr),"\n"));
      inp.add("COMMENT_DO_LIST",join(viz_with_cdo(arr),"\n"));
      out+=get_templ("VISITOR").eval(inp);
    }
    {
      const vector<t_struct_body::t_target_item_out> no_arr;
      vector<string> no_nested;
      out+=make_head(Env,no_arr,name,"",owner,no_nested);
    }
    string body;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",name);
      inp.add("PROVARS","");
      body+=get_templ("VARS").eval(inp);
    }
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",name);
      body+=get_templ("USE_BASE").eval(inp);
    }
    {
      string list;
      for(int i=0;i<arr.size();i++)list+="      F("+arr[i]+");\n";
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",name);
      inp.add("LIST",list);
      body+=get_templ("GO_BASE").eval(inp);
    }
    out+=move_block(body,owner.empty()?"":"  ");
    {
      out+="};";
    }
    return out;
  }
  string class_to_code(IEnvRTTI&Env,const t_target_item::t_out&ex,const string&owner)
  {
    string out;
    {
      auto nested_list=get_nested_list(ex.out.nested);
      const vector<t_struct_body::t_target_item_out> no_arr;
      vector<string> no_nested;
      out+=make_head(Env,ex.out.nested,ex.name,ex.parent,owner,nested_list);
    }
    string body;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",ex.name);
      inp.add("PROVARS",ex.out.provars);
      body+=get_templ("VARS").eval(inp);
    }
    if(!ex.parent.empty())
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",ex.name);
      body+=get_templ("USE_IMPL").eval(inp);
    }
    if(!ex.out.procmds.empty())
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("PROCMDS",ex.out.procmds);
      body+=get_templ("GO_IMPL").eval(inp);
    }
    if(!ex.out.nested.empty())if(ex.out.nested.size()>2)
    {
      auto parents=get_parent_list(ex.out.nested);
      auto nesteds=get_nested_list(ex.out.nested);
      vector<string> list;
      for(int i=0;i<parents.size();i++)list.push_back("  //  F("+parents[i]+");");
      for(int i=0;i<nesteds.size();i++)list.push_back("  //  F("+nesteds[i]+");");
      vector<string> dolist;
      for(int i=0;i<nesteds.size();i++)dolist.push_back("  //  void Do("+nesteds[i]+"&ref){}");
      t_templ_sys_v02::t_inp inp;
      inp.add("OWNER",ex.name);
      inp.add("LIST",join(list,"\n"));
      inp.add("DO_LIST",join(dolist,"\n"));
      body+=get_templ("NESTED_VISITOR").eval(inp);
    }
    out+=move_block(body,owner.empty()?"":"  ");
    if(!ex.out.cppcode.empty()){
      QapDebugMsg("[2014.02.12 14:14]:\nuse 't_static_visitor' instead of 'usercode inside lexem'.");
    }
    if(ex.out.cppcode.empty())
    {
      out+="};";
    }
    return out;
  }
  string get_target_code(IEnvRTTI&Env,const vector<t_target_item::t_out>&arr,const string&owner)
  {
    vector<string> out;
    auto parents=get_parent_list(arr);
    for(int i=0;i<parents.size();i++){
      auto&ex=parents[i];
      auto list=get_child_list(arr,ex);
      string tmp=iclass_to_code(Env,ex,list,owner);
      out.push_back(tmp);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      string tmp=class_to_code(Env,ex,owner);
      out.push_back(tmp);
    }
    return join(out,"\n");
  }
  static vector<string> get_list_of_types(vector<t_target_item::t_out>&arr)
  {
    vector<string> out;
    string line;
    for(int i=0;i<arr.size();i++){
      string item="F("+arr[i].name+")";
      if(line.size()+item.size()>=80){
        out.push_back(std::move(line));
        line.clear();
      }
      line+=item;
    }
    if(!line.empty())out.push_back(std::move(line));
    return out;
  }
  string main(IEnvRTTI&Env,const string&data)
  {
    this->init(Env);
    t_target tar;
    string status=load_obj_ex(Env,tar,data);
    if(tar.arr.empty()){return "!target\n\n"+status;}
    vector<t_target_item::t_out> arr=tar.make_code();
    auto listoftypes=get_list_of_types(arr);
    string result=(
      get_target_code(Env,arr,"")+"\n"
      "\n"
      "/*\n"
      "//list of types:\n"+
      join(listoftypes,"\n")+"\n"
      "//app:\n"
      "adler3d.github.io/test2013/\n"
      "//code:\n"
      "return decodeURIComponent(POST['data'].split(\"\\n\").join(\"\"));\n"
      "//data:\n"+
      to80charperline(urlencode(data))+"\n"+
      "*/"
    );
    return result;
  }
  static string to80charperline(const string&mem){
    vector<string> out;
    bool stop=false;
    for(int pos=0;pos<mem.size();pos+=80){
      out.push_back(mem.substr(pos,80));
    }
    return join(out,"\n");
  }
public:
  void init(IEnvRTTI&Env)
  {
    string content=file_get_contents("LexemGenData.inl");
    content=StrReplace(content,"\r","");
    t_templ_sys_v03 v3;
    bool ok=load_obj(Env,v3,content);
    QapAssert(ok);
    this->load(Env,v3);
    int gg=1;
  }
};
/*
class TLexemGeneratorFuncs_v01{
public:
#define DEF_PRO_NESTED(F)F(gen_lexem_v01)F(to80cpl)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TLexemGeneratorFuncs_v01)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>TLexemGeneratorFuncs_v00
#include "QapGenStruct.inl"
//<<<<<+=====TLexemGeneratorFuncs_v00
public:
  class gen_lexem_v01:public i_sysfunc_with_rtti{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(gen_lexem_v01)PARENT(i_sysfunc_with_rtti)OWNER(TLexemGeneratorFuncs_v01)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,out,DEF,$,$)\
  ADDVAR(string,data,DEF,$,$)\
  ADDEND()
  //=====+>>>>>gen_lexem_v01
  #include "QapGenStruct.inl"
  //<<<<<+=====gen_lexem_v01
  public:
    void exec(IEnvRTTI&Env)
    {
      t_templ_sys_v04 v4;
      out=v4.main(Env,data);
    }
  };
  class to80cpl:public i_sys_impl{
  public:
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(to80cpl)PARENT(i_sys_impl)OWNER(TLexemGeneratorFuncs_v01)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(0,string,out,DEF,$,$)\
  ADDVAR(1,string,data,DEF,$,$)\
  ADDEND()
  //=====+>>>>>to80cpl
  #include "QapGenStruct.inl"
  //<<<<<+=====to80cpl
  public:
    void exec()
    {
      out=t_templ_sys_v04::to80charperline(data);
    }
  };
};
*/
//#include "Lexem/t_qapclass_parser.inl"
#if(0)
class t_qaplexem_class_visitor{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_qaplexem_class_visitor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,offset,DEF,$,$)\
ADDVAR(string,output,DEF,$,$)\
ADDEND()
//=====+>>>>>t_qaplexem_class_visitor
#include "QapGenStruct.inl"
//<<<<<+=====t_qaplexem_class_visitor
public:
  #define F(TYPE)typedef t_file_with_lex::t_class::TYPE TYPE;
  F(i_def);
  F(i_stat);
  F(t_with_parent);
  F(t_without_parent);
  F(t_head);
  F(t_vars);
  F(t_body);
  F(t_end);
  F(t_sep_stat);
  F(t_public_stat);
  F(t_class_stat);
  #undef F
public:
  /*void add_pack(const vector<string>&arr){
    string off=string(offset,' ');
    for(int i=0;i<arr.size();i++){
      output+=off+arr[i]+"\n";
    }
  }*/
  void add_str(const string&s){
    output+=string(offset,' ')+s+"\n";
  }
  void push(const string&s){
    add_str(s+"{");
    offset+=2;
  }
  void push(){push("");}
  void pop(){
    QapAssert(offset>=2);
    offset-=2;
    add_str("}");
  }
public:
  //void Do(t_with_parent&ref){}
  //void Do(t_without_parent&ref){}
  //void Do(t_head&ref){}
  void Do(t_vars&ref){
    auto&arr=ref.arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(ex.mode=="DEF"||ex.mode=="SET");
      add_str(ex.type+" "+ex.name+(ex.mode=="DEF"?"":"="+ex.value)+";");
    }
  }
  void Do(t_body&ref){
    auto*p=ref.body.get();
    auto*ptr=t_file_with_lex::t_class::t_lex_impl::UberCast(p);
    if(!ptr)return;
    auto&arr=ptr->arr;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      string line;
      if(ex.mode!='D')line=CToS(ex.mode)+"+=";
      line+=ex.line;
      add_str(line);
    }
  }
  //void Do(t_end&ref){}
  //void Do(t_sep_stat&ref){}
  //void Do(t_public_stat&ref){}
  //void Do(t_class_stat&ref){}
public:
  static bool CheckImplBody(t_body&ref){
    auto*p=ref.body.get();
    auto*ptr=t_file_with_lex::t_class::t_lex_impl::UberCast(p);
    return ptr;
  }
public:
  class t_def_visitor:public t_file_with_lex::t_class::i_def_visitor{
  public:
    class t_dev{
    public:
      string name;
      string parent;
    };
    t_dev&dev;
    t_def_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_with_parent*p){dev.name=p->name;dev.parent=p->parent;}
    void Do(t_without_parent*p){dev.name=p->name;}
  public:
    static t_dev get(TAutoPtr<i_def>&ref){
      t_def_visitor::t_dev dev;
      t_def_visitor V(dev);
      auto*p=ref.get();
      p->Use(V);
      return dev;
    }
  };
public:
  void Do(vector<TAutoPtr<i_stat>>&arr){
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*p=ex.get();
      auto*ptr=t_class_stat::UberCast(p);
      if(!ptr)continue;
      auto&ref=*ptr->body.get();
      main(ref);
    }
  }
public:
  void main(t_file_with_lex::t_class&ref)
  {
    if(!CheckImplBody(ref.body))return;
    string head;
    auto info=t_def_visitor::get(ref.def);
    head+=info.name;
    if(!info.parent.empty())head+="=>"+info.parent;
    push(head);
    {
      Do(ref.stats);
      Do(ref.vars);
      push();
      {
        Do(ref.body);
      }
      pop();
    }
    pop();
    //auto nesteds=get_nesteds(ref.stats);
  }
};

class t_cpp2lex_funcs{
public:
  class parse_cpp_file_with_lex:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(parse_cpp_file_with_lex)PARENT(i_sysfunc_with_rtti)OWNER(t_cpp2lex_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,out,DEF,$,$)\
  ADDVAR(string,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>parse_cpp_file_with_lex
  #include "QapGenStruct.inl"
  //<<<<<+=====parse_cpp_file_with_lex
  public:
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start();  //conv_cpp_to_lex
      t_file_with_lex ug;
      //string code=file_get_contents("asm_test.asm");
      string load_status=load_obj_ex(Env,ug,code);
      if(load_status.find("true")>16){
        int fail=1;
        QapDebugMsg(load_status);return;
      }
      QapDebugMsg("loadtime = "+FToS(clock.MS()*1000.0));
      out=QapPublicUberFullSaverProtoToStr(Env,QapRawUberObject(ug));
    }
  };
  class conv_cpp_to_lex:public i_sysfunc_with_rtti{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(conv_cpp_to_lex)PARENT(i_sysfunc_with_rtti)OWNER(t_cpp2lex_funcs)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,out,DEF,$,$)\
  ADDVAR(string,code,DEF,$,$)\
  ADDEND()
  //=====+>>>>>conv_cpp_to_lex
  #include "QapGenStruct.inl"
  //<<<<<+=====conv_cpp_to_lex
  public:
    void exec(IEnvRTTI&Env)
    {
      QapClock clock;clock.Start(); //conv_cpp_to_lex
      t_file_with_lex ug;
      string load_status=load_obj_ex(Env,ug,code);
      if(load_status.find("true")>16){
        int fail=1;
        QapDebugMsg(load_status);return;
      }
      t_qaplexem_class_visitor V;
      for(int i=0;i<ug.arr.size();i++){
        auto&ex=ug.arr[i];
        auto*p=ex.get();
        auto*ptr=t_file_with_lex::t_class::UberCast(p);
        if(!ptr)continue;
        V.main(*ptr);
      }
      out=V.output;
    }
  };
public:
#define DEF_PRO_NESTED(F)F(parse_cpp_file_with_lex)F(conv_cpp_to_lex)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_cpp2lex_funcs)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_cpp2lex_funcs
#include "QapGenStruct.inl"
//<<<<<+=====t_cpp2lex_funcs
public:
};
#endif
/*
void test_2014_02_14(IEnvRTTI&Env)
{
  t_file_with_lex::t_class ug;
  //string code=file_get_contents("meta_lexer.mod.inl");
  string code=file_get_contents("easy_ssl.h");
  code=StrReplace(code,"\r","");
  string status=load_obj_ex(Env,ug,code);
  int gg=1;
}

void test_2014_02_13(IEnvRTTI&Env)
{
  t_file_with_lex ug;
  string code=file_get_contents("meta_lexer.mod.inl");
  code=StrReplace(code,"\r","");
  string status=load_obj_ex(Env,ug,code);
  t_qaplexem_class_visitor V;
  for(int i=0;i<ug.arr.size();i++){
    auto&ex=ug.arr[i];
    auto*p=ex.get();
    auto*ptr=t_file_with_lex::t_class::UberCast(p);
    if(!ptr)continue;
    V.main(*ptr);
  }
  int gg=1;
}*/
#include <iostream>

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)//F(TLexemGeneratorFuncs_v01)F(t_cpp2lex_funcs)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
      //test_2014_02_12(Env);
      /*static bool debug=false;
      if(debug)
      {
        test_2014_02_14(Env);
      }
      if(debug)
      {
        test_2014_02_13(Env);
      }*/
    }
    static void test_2014_02_12(IEnvRTTI&Env)
    {
      QapClock clock;
      string content=file_get_contents("LexemGenData.inl");
      content=StrReplace(content,"\r","");
      t_templ_sys_v03 templates_v03;
      load_obj(Env,templates_v03,content);
      int gg=1;
      t_templ_sys_v04 v4;
      v4.load(Env,templates_v03);
      gg=1;
      //string asm_code=file_get_contents("input.qapdsl.hpp");
      //auto out=v4.main(Env,asm_code);
      string inp,line;
      while(std::getline(std::cin,line)){
        inp+=line+"\n";
      }
      //std::cout<<inp<<std::endl<<std::endl;
      string str=v4.main(Env,inp);
      string out="// "+FToS(clock.MS())+" ms\n"+str;
      std::cout<<out;
      gg=2;
    }
    void Run(IEnvRTTI&Env)
    {
      test_2014_02_12(Env);
      return;
    }
    ThisCompileUnit(){
    }
  };
  ThisCompileUnit ThisUnit;
}