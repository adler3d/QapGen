//#include "StdAfx.h"

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
  void load(/*IEnvRTTI&Env,*/t_templ_sys_v03&v3)
  {
    arr.resize(v3.arr.size());
    for(int i=0;i<arr.size();i++)
    {
      arr[i].head=v3.arr[i].head.name;
      auto&ex=arr[i].body;
      auto&data=v3.arr[i].body;
      load_obj(/*Env,*/ex,data);
    }
  }
public:
  static string move_block(const string&source,const string&sep,bool drop_last_line_spaces=false){
    if(sep.empty())return source;
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    auto out=sep+join(arr,"\n"+sep);
    if(drop_last_line_spaces)for(int i=0;out.size()&&out.back()==' ';i++)out.pop_back();
    return out;
  }
  static vector<string> get_iarr(const vector<const t_target_item*>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto dc=ex->def->make_code();
      if(dc.parent.empty())continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(dc.parent==out[j]);
      if(flag)continue;
      out.push_back(dc.parent);
    }
    return out;
  }
  static vector<string> get_child_list(const vector<const t_target_item*>&arr,const string&parent,t_ic_dev&ic_dev)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto ex=arr[i]->make_code(ic_dev);
      if(ex.parent==parent){
        out.push_back(ex.name);
      }
    }
    return out;
  }
  static vector<string> get_nested_list(const vector<const t_target_item*>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=*arr[i];
      out.push_back(ex.def->make_code().name);
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
    //IEnvRTTI&Env,
    const vector<const t_target_item*>&arr,
    const string&name,
    const string&parent,
    const string&owner,
    const string&full_owner,
    const vector<string>&nested_list,
    t_ic_dev&ic_dev
  ){
    string out;/*
    string parent_part=!parent.empty()?":public "+parent:"";
    string parent_info=!parent.empty()?"PARENT("+parent+")":"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    string target_code=get_target_code(arr,name,full_owner.empty()?name:full_owner+"::"+name,ic_dev);
    bool hasVirtual=false;
    for(int i=0;i<arr.size();i++)if(!arr[i]->make_code(ic_dev).parent.empty())hasVirtual=true;
    string class_code;
    class_code+="class "+name+parent_part+"{\n";
    class_code+=target_code.empty()?"":((hasVirtual?"":"public:\n")+target_code+"\n");
    class_code+=get_nested_def(nested_list);
    class_code+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    class_code+="NAME("+name+")"+parent_info+owner_info;
    out+=move_block(class_code,owner.empty()?"":"  ")+"\n";
    //out+="#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\\\n";*/
    return out;
  }
  string make_head_v2(
    const t_target_item&ti,
    const string&owner,
    const string&full_owner,
    //const vector<string>&nested_list,
    t_ic_dev&ic_dev
  ){
    string out;
    string target_code=get_target_code(ti,full_owner,ic_dev);
    auto c=ti.make_code(ic_dev);
    auto nested_list=get_nested_list(c.out.nested);
    string parent_part=!c.parent.empty()?":public "+c.parent:"";
    string parent_info=!c.parent.empty()?"PARENT("+c.parent+")":"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    bool hasVirtual=false;
    for(int i=0;i<c.out.nested.size();i++)if(!c.out.nested[i]->make_code(ic_dev).parent.empty())hasVirtual=true;
    string class_code;
    class_code+="struct "+c.name+parent_part+"{\n";
    class_code+=target_code.empty()?"":((hasVirtual?"":"public:\n")+target_code+"\n");
    class_code+=get_nested_def(nested_list);
    class_code+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    class_code+="NAME("+c.name+")"+parent_info+owner_info;
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
  struct t_at_end{
    string full_owner;
    string base;
    string list;
    string get_impl()const{
      vector<string> v={
        //"template<int>\n",
        "bool "+(full_owner.empty()?"":full_owner+"::")+base+"::t_poly_impl::load()\n",
        "{\n",
        "  #define F(TYPE)go_for<struct TYPE>();\n",
        list,
        "  #undef F\n",
        "  return scope.ok;\n"
        "}\n"
      };
      return join(v,"");
    }
  };
  vector<t_at_end> at_end;
  string iclass_to_code(const string&name,const vector<string>&arr,const string&owner,const string&full_owner)
  {
    string out;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",name);
      inp.add("OWNER",owner);
      inp.add("ADDLIST",join(viz_with_add(arr),"\n"));
      inp.add("DO_LIST",join(viz_with_doo(arr),"\n"));
      inp.add("COMMENT_DO_LIST",join(viz_with_cdo(arr),"\n"));
      out+=move_block(get_templ("VISITOR").eval(inp),owner.empty()?"":"  ",true);
    }
    {
      t_ic_dev no_dev;
      thread_local t_target_item ti;
      thread_local t_struct_def*psd=nullptr;
      if(!psd){
        auto sd=make_unique<t_struct_def>();
        psd=sd.get();
        ti.def=std::move(sd);
      }
      psd->name.value=name;
      //load_obj(ti,"t{}");
      //auto*p=i_def_visitor::UberCast<t_struct_def>(ti.def.get());
      //p->name.value=name;
      out+=make_head_v2(ti,owner,full_owner,no_dev);
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
      string list,qist;
      for(int i=0;i<arr.size();i++)list+="      F("+arr[i]+");\n";
      for(int i=0;i<arr.size();i++)qist+="  F("+arr[i]+");\n";
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",name);
      inp.add("LIST",list);
      body+=get_templ("GO_BASE").eval(inp);
      t_at_end ae={full_owner,name,qist};
      at_end.push_back(ae);
    }
    out+=move_block(body,owner.empty()?"":"  ");
    {
      out+="};";
    }
    return out;
  }
  string get_at_end()const{
    vector<string> v;
    for(auto&ex:at_end)v.push_back(ex.get_impl());
    return join(v,"\n");
  }
  string class_to_code(const t_target_item&ex,const string&owner,const string&full_owner,t_ic_dev&ic_dev)
  {
    string out;
    auto name=ex.def->make_code().name;
    auto full_name=(full_owner.empty()?"":full_owner+"::")+name;
    ic_dev.push(name,full_name);
    out+=make_head_v2(ex,owner,full_owner,ic_dev);
    auto c=ex.make_code(ic_dev);
    ic_dev.pop();
    string body;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",c.name);
      inp.add("PROVARS",c.out.provars);
      body+=get_templ("VARS").eval(inp);
    }
    if(!c.parent.empty())
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",c.name);
      body+=get_templ("USE_IMPL").eval(inp);
    }
    if(!c.out.procmds.empty())
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("PROCMDS",c.out.procmds);
      body+=get_templ("GO_IMPL").eval(inp);
    }
    if(!c.out.nested.empty())if(c.out.nested.size()>2)
    {
      auto iarr=get_iarr(c.out.nested);
      auto nesteds=get_nested_list(c.out.nested);
      vector<string> list;
      for(int i=0;i<iarr.size();i++)list.push_back("  //  F("+iarr[i]+");");
      for(int i=0;i<nesteds.size();i++)list.push_back("  //  F("+nesteds[i]+");");
      vector<string> dolist;
      for(int i=0;i<nesteds.size();i++)dolist.push_back("  //  void Do("+nesteds[i]+"&ref){}");
      t_templ_sys_v02::t_inp inp;
      inp.add("OWNER",c.name);
      inp.add("LIST",join(list,"\n"));
      inp.add("DO_LIST",join(dolist,"\n"));
      body+=get_templ("NESTED_VISITOR").eval(inp);
    }
    out+=move_block(body,owner.empty()?"":"  ");
    if(!c.out.cppcode.empty()){
      QapDebugMsg("[2014.02.12 14:14]:\nuse 't_static_visitor' instead of 'usercode inside lexem'.");
    }
    if(c.out.cppcode.empty())
    {
      out+="};";
    }else{
      out+=c.out.cppcode;
      out+="};";
    }
    return out;
  }
  string get_targets_code_orig(const vector<const t_target_item*>&arr,t_ic_dev&ic_dev)
  {
    //auto c=ti.make_code(ic_dev);
    vector<string> out;
    auto&iarr=ic_dev.top.iarr;
    iarr=get_iarr(arr);
    for(int i=0;i<iarr.size();i++){
      auto&ex=iarr[i];
      auto list=get_child_list(arr,ex,ic_dev);
      string tmp=iclass_to_code(ex,list,"","");
      out.push_back(tmp);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      ic_dev.top.carr.push_back(ex->def->make_code().name);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      string tmp=class_to_code(*ex,"","",ic_dev);
      out.push_back(tmp);
    }
    return join(out,"\n");
  }
  string get_target_code(const t_target_item&ti,const string&full_owner,t_ic_dev&ic_dev)
  {
    auto name=ti.def->make_code().name;
    auto full_name=(full_owner.empty()?"":full_owner+"::")+name;
    //ic_dev.push(name,full_name);
    auto c=ti.make_code(ic_dev);
    vector<string> out;
    auto&iarr=ic_dev.top.iarr;
    iarr=get_iarr(c.out.nested);
    for(int i=0;i<iarr.size();i++){
      auto&ex=iarr[i];
      auto list=get_child_list(c.out.nested,ex,ic_dev);
      string tmp=iclass_to_code(ex,list,name,full_name);
      out.push_back(tmp);
    }
    for(int i=0;i<c.out.nested.size();i++){
      auto&ex=c.out.nested[i];
      ic_dev.top.carr.push_back(ex->def->make_code().name);
    }
    for(int i=0;i<c.out.nested.size();i++){
      auto&ex=c.out.nested[i];
      string tmp=class_to_code(*ex,name,full_name,ic_dev);
      out.push_back(tmp);
    }
    //ic_dev.pop();
    return join(out,"\n");
  }
  static vector<string> get_list_of_types(const vector<const t_target_item*>&arr)
  {
    vector<string> out;
    string line;
    for(int i=0;i<arr.size();i++){
      string item="F("+arr[i]->def->make_code().name+")";
      if(line.size()+item.size()>=80){
        out.push_back(std::move(line));
        line.clear();
      }
      line+=item;
    }
    if(!line.empty())out.push_back(std::move(line));
    return out;
  }
  string main(/*IEnvRTTI&Env,*/const string&data)
  {
    this->init(/*Env*/);
    t_target tar;
    auto fs=load_obj_full(/*Env,*/tar,data);
    if(!fs.ok){cerr<<fs.msg<<endl;return "fail";}
    if(tar.arr.empty()){return "!target\n\n"+fs.msg;}
    //vector<t_target_item::t_out> arr=tar.make_code({});
    t_ic_dev ic_dev;
    vector<const t_target_item*> tarr;
    for(auto&ex:tar.arr)tarr.push_back(&ex);
    auto tc=get_targets_code_orig(tarr,ic_dev);
    auto listoftypes=get_list_of_types(tarr);
    auto ae=get_at_end();
    string result=(
      tc+"\n"+
      ae+
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
  void init(/*IEnvRTTI&Env*/)
  {
    string content=file_get_contents("LexemGenData.inl");
    content=StrReplace(content,"\r","");
    t_templ_sys_v03 v3;
    bool ok=load_obj(/*Env,*/v3,content);
    QapAssert(ok);
    this->load(/*Env,*/v3);
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

static void test_2025_06_10(/*IEnvRTTI&Env*/string fn)
{
  QapClock clock;
  string content=file_get_contents("LexemGenData.inl");
  content=StrReplace(content,"\r","");
  t_templ_sys_v03 templates_v03;
  load_obj(/*Env,*/templates_v03,content);
  int gg=1;
  t_templ_sys_v04 v4;
  v4.load(/*Env,*/templates_v03);
  gg=1;
  string inp;
  if(fn.empty()){
    string line;
    while(std::getline(std::cin,line)){
      inp+=line+"\n";
    }
  }else{
    inp=file_get_contents(fn);
  }
  if(inp.size()&&inp.back()=='\n')inp.pop_back();
  string str=v4.main(inp);
  string out="// "+FToS(clock.MS())+" ms\n"+str;
  std::cout<<out;
  gg=2;
}