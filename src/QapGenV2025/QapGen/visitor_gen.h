//#include "StdAfx.h"

#include "templ_lexer_v02.inl"
struct t_meta_lexer;

#include "meta_lexer.inl"

#include "templ_lexer_v03.inl"

extern void UberInfoBox(const string&caption,const string&text);

struct t_templ_sys_v04:t_meta_lexer{
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
  static vector<string> get_nested_list(const vector<i_target_item*>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      //auto&ex=*arr[i];
      auto*p=t_target_item::UberCast(arr[i]);
      if(!p)continue;
      auto*pd=t_struct_def::UberCast(p->def.get());
      auto*ps=t_class_def::UberCast(p->def.get());
      out.push_back(pd?pd->name.value:ps->name.value);
    }
    return out;
  }
  static vector<string> get_iarr(const vector<i_target_item*>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*p=dynamic_cast<const t_target_item*>(ex);
      if(!p)continue;
      auto*pc=t_class_def::UberCast(p->def.get());
      if(!pc||pc->parent.value.empty())continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(pc->parent.value==out[j]);
      if(flag)continue;
      out.push_back(pc->parent.value);
    }
    return out;
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
public:
  static string pad_end(const string&s,size_t ms){
    return s+string(ms-s.size(),' ');
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
    for(int i=0;i<arr.size();i++)out.push_back("  virtual void Do("+arr[i]+"&r)=0;");
    return out;
  }
  static vector<string> viz_with_cdo(const vector<string>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++)out.push_back("//  void Do("+arr[i]+"&r){}");
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
        "  main();\n",
        "  return scope.ok;\n"
        "}\n"
      };
      return join(v,"");
    }
  };
  vector<t_at_end> at_end;
  string get_at_end()const{
    vector<string> v;
    for(auto&ex:at_end)v.push_back(ex.get_impl());
    return join(v,"\n");
  }
  static vector<string> get_list_of_types(const vector<i_target_item*>&arr)
  {
    vector<string> out;
    string line;
    for(int i=0;i<arr.size();i++){
      auto*p=dynamic_cast<const t_target_item*>(arr[i]);
      if(!p)continue;
      auto*pc=t_class_def::UberCast(p->def.get());
      auto*ps=t_struct_def::UberCast(p->def.get());
      string&n=pc?pc->name.value:ps->name.value;
      string item="F("+n+")";
      if(line.size()+item.size()>=80){
        out.push_back(std::move(line));
        line.clear();
      }
      line+=item;
    }
    if(!line.empty())out.push_back(std::move(line));
    return out;
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

struct t_ic_dev_v2{
  struct t_sep_lex{
    string sep;
    string lexer;
  };
  struct t_lexer{
    string name;
    string parent;
    string sep;
  };
  struct t_nesteds{
    bool need_grab=false;
    bool need_igrab=false;
    vector<string> list;
    vector<t_meta_lexer::t_target_item*> arr;
    vector<t_meta_lexer::t_target_item*> piarr;
    vector<t_meta_lexer::t_target_item*> pcarr;
  };
  struct t_level{
    t_lexer lexer;
    vector<string> iarr;
    vector<string> carr;
    vector<t_sep_lex> sep_lexs;
    t_nesteds nesteds;
    string out;
  };
  vector<t_level> arr;
  t_level top;
  string*get_sep_lex(const string&sep){
    for(auto&ex:top.sep_lexs)if(ex.sep==sep)return &ex.lexer;
    for(auto&L:arr)for(auto&ex:L.sep_lexs)if(ex.sep==sep)return &ex.lexer;
    return nullptr;
  }
  bool add_sep_lex(const string&sep,const string&lexer){
    if(get_sep_lex(sep)){QapDebugMsg("not_unique sep_lex: "+sep+" "+lexer);return false;}
    top.sep_lexs.push_back({sep,lexer});
    return true;
  }
  bool need_tautoptr(const string&name){
    if(qap_includes(top.iarr,name))return true;
    if(qap_includes(top.carr,name))return false;
    for(auto it=arr.rbegin();it!=arr.rend();it++){
      if(qap_includes(it->iarr,name))return true;
      if(qap_includes(it->carr,name))return false;
    }
    return false;
  }
  void push(){
    arr.push_back(std::move(top));
  }
  void pop(){
    top=std::move(arr.back());
    arr.pop_back();
  }
};

struct t_templ_sys_v05:t_templ_sys_v04,
  t_meta_lexer::i_target_item::i_visitor,
  t_meta_lexer::i_struct_cmd_xxxx::i_visitor,
  t_meta_lexer::i_struct_field::i_visitor,
  t_meta_lexer::i_struct_cmd_so::i_visitor,
  t_meta_lexer::i_def::i_visitor
{
  #pragma region typedefs
  #define F(T)typedef t_templ_sys_v04::T T;
  F(t_name_code                   )\
  F(t_num_code                    )\
  F(t_str_seq                     )\
  F(t_sep_str_seq                 )\
  F(t_str_code                    )\
  F(t_char_code                   )\
  F(t_sign_code                   )\
  F(t_name_code_with_sep          )\
  F(t_num_code_with_sep           )\
  F(t_str_code_with_sep           )\
  F(t_char_code_with_sep          )\
  F(t_sign_code_with_sep          )\
  F(t_soft_brackets_code_with_sep )\
  F(t_hard_brackets_code_with_sep )\
  F(t_curly_brackets_code_with_sep)\
  F(t_code                        )\
  F(t_soft_brackets_code          )\
  F(t_hard_brackets_code          )\
  F(t_curly_brackets_code         )\
  F(t_semicolon                   )\
  F(t_value_item                  )\
  F(t_value                       )\
  F(t_type_scope                  )\
  F(t_type_templ                  )\
  F(t_type_item_string            )\
  F(t_type_item_char              )\
  F(t_type_item_number            )\
  F(t_scope_type_item             )\
  F(t_type_item_type              )\
  F(t_type_expr2                  )\
  F(t_type_templ_param            )\
  F(t_sep_type_templ_param        )\
  F(t_type_templ_params           )\
  F(t_type_templ_angle            )\
  F(t_type_templ_soft             )\
  F(t_struct_cmd_mode             )\
  F(t_sep_value                   )\
  F(t_attr                        )\
  F(t_const_field                 )\
  F(t_struct_field_value          )\
  F(t_struct_field                )\
  F(t_sep_struct_field            )\
  F(t_templ_params                )\
  F(t_cmd_params                  )\
  F(t_cmd_param                   )\
  F(t_struct_cmd_anno             )\
  F(t_struct_cmd_suffix           )\
  F(t_struct_cmd_optional         )\
  F(t_struct_cmd_opt_v2           )\
  F(t_struct_cmd                  )\
  F(t_sep_struct_cmd              )\
  F(t_struct_cmds                 )\
  F(t_sep_struct_cmds             )\
  F(t_cpp_code_sep                )\
  F(t_cpp_code_main               )\
  F(t_cpp_code                    )\
  F(t_fields_cmds_cppcode         )\
  F(t_struct_body                 )\
  F(t_class_def                   )\
  F(t_struct_def                  )\
  F(t_target_sep                  )\
  F(t_target_item                 )\
  F(t_target_decl                 )\
  F(t_target_using                )\
  F(t_target                      )\
  F(i_code           )\
  F(i_code_with_sep  )\
  F(i_type_item      )\
  F(i_type_templ     )\
  F(i_struct_cmd_xxxx)\
  F(i_struct_field   )\
  F(i_struct_cmd_so  )\
  F(i_cpp_code       )\
  F(i_def            )\
  F(i_target_item    )\
  //
  #undef F
  #define F(T)void Do(T&r){r.Use(*this);}
  F(i_struct_cmd_xxxx)
  F(i_struct_field   )
  F(i_struct_cmd_so  )
  F(i_def            )
  F(i_target_item    )
  #undef F
  #pragma endregion
  void Do(t_struct_cmd_mode&r)override{}
  void Do(t_struct_cmd_anno&r)override{}
  void Do(t_struct_cmd_suffix&r)override{}
  void Do(t_struct_cmd_optional&r)override{}
  void Do(t_struct_cmd_opt_v2&r)override{}
  t_ic_dev_v2::t_lexer def_info;
  void Do(t_class_def&r)override{
    def_info.name=r.name.value;def_info.parent=r.parent.value;def_info.sep.clear();
  }
  void Do(t_struct_def&r)override{
    def_info.name=r.name.value;def_info.parent.clear();def_info.sep.clear();
  }
  void Do(t_target_sep&r)override{}
  static bool find_smart_func(const string&func){
    static const vector<string> arr=split("go_any_str_from_vec|go_any_arr_char|go_any|go_any_char","|");
    for(int i=0;i<arr.size();i++)if(arr[i]==func)return true;
    return false;
  }
  int cmd_id=-1;
  void Do(t_struct_cmd&r){
    cmd_id++;
    //cmd_anno=false;
    //Do(r.mode);
    if(r.mode&&t_struct_cmd_anno::UberCast(r.mode.get())){
      int gg=1;
    }
    char m='D';//r.cmdso?r.cmdso->get_mode():'D';
    QapAssert(r.cmdso||r.mode?bool(r.cmdso)!=bool(r.mode):true);
    auto*pm=t_struct_cmd_mode::UberCast(r.mode.get());
    string out=CToS(pm?pm->body:m);//CToS(r.mode?r.mode->get_mode():m);
    vector<string> params_code;
    {auto&arr=r.params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
    auto check=out!="O"?"    if(!ok)return ok;\n":"";
    out=out!="O"?"ok=":"";
    string func_name=r.func.get();
    bool smart_func=find_smart_func(func_name);
    if(smart_func)
    {
      QapAssert(r.params.arr.size()==2);
      const auto&param0=r.params.arr[0].body;
       const auto&param1=r.params.arr[1].body;
      auto get_param1=[&func_name,&param1]()->string{
        if(func_name=="go_any_str_from_vec")return "QapStrFinder::fromArr("+param1+")";
        return "CharMask::fromStr("+param1+")";
      };
      string varname="g_static_var_"+IToS(cmd_id);
      string vardecl="    static const auto "+varname+"="+get_param1()+";\n";
      out=vardecl+"    "+out+"dev."+r.func.get()+"("+param0+","+varname+");\n"+check;
      procmds+=out;
    }else{
      procmds+="    "+out+"dev."+r.func.value+r.templ_params+"("+join(params_code,",")+");\n"+check;
    }
  }
  void Do(t_struct_cmds&r){for(auto&ex:r.arr)Do(ex);}
  void Do(t_sep_struct_cmd&r){Do(r.body);}
  void Do(t_sep_struct_cmds&r){Do(r.body);}
  void Do(t_const_field&r)override{
    if(field.find_qst){
      field.find_qst_result=false;
      if(r.qst)field.find_qst_result=true;
      return;
    }
    cmd_id++;
    const string*plexer=dev.get_sep_lex(r.value);
    if(field.as_cmd){
      if(!plexer){field.cmdout={};return;}else{QapNoWay();return;}
      field.cmdout="M+=go_const("+r.value+");";
      return;
    }
    if(!plexer)return;
    provars+="ADDVAR("+*plexer+",$sep"+IToS(cmd_id)+",DEF,$,$)\\\n";
    //string make_cmd(t_ic_dev&icdev)const{return "M+=go_const("+value+");";}
  }
  t_ic_dev_v2 dev;
  struct t_field_info{
    bool as_cmd=false;
    bool find_qst=false;
    bool find_qst_result=false;
    string cmdout;
  };
  t_field_info field;
  void Do(t_struct_field&r)override{
    if(field.find_qst){
      field.find_qst_result=false;
      if(r.qst&&r.qst->s.find('?')!=string::npos)field.find_qst_result=true;
      return;
    }
    if(field.as_cmd){
      char m=r.qst?(r.qst->s.find('?')==string::npos?'M':'O'):'D';
      QapAssert(r.qst||r.mode?bool(r.qst)!=bool(r.mode):true);
      QapAssert(!r.mode);
      auto*pm=t_struct_cmd_mode::UberCast(r.mode.get());
      //string out=CToS(!r.qst?(r.mode?r.mode->get_mode():'D'):m)+"+=";
      string out=CToS(m)+"+=";
      string call,params;
      if(r.value){
        auto*pce=r.value->expr.get();//t_cppcore::t_call_expr::UberCast(value->expr.get());
        QapAssert(pce);
        QapAssert(save_obj(pce->call,call));
        QapAssert(pce->params.arr.empty()||save_obj(pce->params.arr,params));
      }
      string go=r.value?call+"("+r.name.value+string(params.size()?","+params:"")+");":"auto("+r.name.value+");";
      field.cmdout+=out+"go_"+go;
      return;
    }
    cmd_id++;
    vector<string> out;
    string mode="DEF";
    string type_mem;
    QapAssert(r.type&&save_obj(*r.type.get(),type_mem));
    auto t=type_mem;
    if(bool vec_algo=true){
      auto a=split(t,"<");
      if(a.size()==2&&a[0]=="vector"){
        auto b=split(a[1],">");
        QapAssert(b.size()==2);
        QapAssert(b[1]=="");
        if(dev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>"+b[1];
      }
    }
    if(dev.need_tautoptr(t))t="TAutoPtr<"+t+">";
    if(bool need_vec=r.qst&&r.qst->s.find('*')!=string::npos)t="vector<"+t+">";
    out.push_back(t);
    out.push_back(r.name.value);
    out.push_back(mode);
    string value_mem="$";
    out.push_back(!r.value?"$":value_mem);
    string s;
    provars+="ADDVAR("+join(out,",")+","+(s.empty()?"$":s)+")\\\n";
  }
  string provars,procmds;
  void Do(t_sep_struct_field&r){Do(r.body);}
  void Do(t_target_item&r)override{
    r.def->Use(*this);
    auto L=def_info;
    auto&dtn=dev.top.nesteds;
    if(dtn.need_igrab){
      if(L.parent.size()){
        if(!qap_includes(dev.top.iarr,L.parent)){
          dev.top.iarr.push_back(L.parent);
        }
      }
      return;
    }
    bool is_interface=qap_includes(dev.top.iarr,L.name);
    if(dtn.need_grab){
      dtn.list.push_back(L.name);
      dtn.arr.push_back(&r);
      if(is_interface)return;
      dev.top.carr.push_back(L.name);
      dtn.pcarr.push_back(&r);
      return;
    }
    L.sep=r.sep0.value;
    if(is_interface!=interfaces_only)return;
    dev.push();
    dev.top.lexer=def_info;
    string out;string&out2=out;string before_head;
    dev.top.out+=L.sep+"\n";
    out+="struct "+L.name+(L.parent.empty()?"":":public "+L.parent)+"{\n";
    string parent_info=!L.parent.empty()?"PARENT("+L.parent+")":"";
    string owner=dev.arr.size()?dev.arr.back().lexer.name:"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    DoGrab(r);
    dev.top.out+=out+"\n";
    interface_autogen();
    Do(r.body.nested);
    out.clear();
    do{
      auto&arr=dev.top.nesteds.list;
      if(arr.empty())break;
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
      out2+="\n#define DEF_PRO_NESTED(F)\\\n"+join(out,"\n")+"\n";
    }while(false);
    out+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    out+="NAME("+L.name+")"+parent_info+owner_info;
    dev.top.out+=out+"\n";
    out.clear();
    struct t_visitor:t_fields_cmds_cppcode,t_cpp_code::i_strong_bayan::i_visitor,t_cpp_code::i_bayan::i_visitor{
      t_sep_struct_cmds*pcmds{};
      vector<t_sep_struct_field>*pfs{};
      string c;
      void Do(t_cpp_code::t_a&r){save_obj(r.wb.eater,c);}
      void Do(t_cpp_code::t_b&r){save_obj(r.e,c);}
      void Do(t_cpp_code::t_with_bayan&r){save_obj(r.eater,c);}
      void Do(t_cpp_code::t_without_bayan&r){save_obj(r.eater,c);}
      void Do(t_cpp_code::i_strong_bayan&r){r.Use(*this);}
      void Do(t_cpp_code::i_bayan&r){r.Use(*this);}
      virtual void Do(t_cmds&r){pcmds=r.cmds.get();if(r.cppcode)Do(*r.cppcode.get());}
      virtual void Do(t_true_fcc&r){pfs=&r.arr;pcmds=r.cmds?r.cmds.get():nullptr;if(r.cppcode)Do(*r.cppcode.get());}
      virtual void Do(t_cppcode&r){if(r.cppcode)Do(*r.cppcode->bayan.get());}
      void Do(const t_fields_cmds_cppcode&fcc){
        if(fcc.tfcc)Do(*fcc.tfcc.get());
        if(fcc.cmds)Do(*fcc.cmds.get());
        if(fcc.c)Do(*fcc.c.get());
      }
    };
    t_visitor v;
    if(r.body.fcc)v.Do(*r.body.fcc.get());
    provars.clear();
    cmd_id=-1;
    if(v.pfs)Do(*v.pfs);
    auto&body=dev.top.out;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("NAME",L.name);
      inp.add("PROVARS",provars);
      body+=drop_empty_lines(get_templ("VARS").eval(inp))+"\n";
    }
    if(!L.parent.empty())
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",L.name);
      body+=drop_empty_lines(get_templ("USE_IMPL").eval(inp))+"\n";
    }
    struct t_out{
      vector<i_target_item*> nested;
      string provars;
      string procmds;
      string cppcode;
    };
    struct t_target_item_out{
      string sep;
      string name;
      string parent;
      t_out out;
    };
    t_target_item_out c;
    if(r.body.fcc&&!is_interface)for(int iter=1;iter;iter--)
    {
      bool value_or_qst_or_const_found=false;
      if(v.pfs){
        auto&arr=*v.pfs;
        for(auto&it:arr){
          if(auto*p=t_struct_field::UberCast(it.body.get())){
            if(p->value||p->qst){value_or_qst_or_const_found=true;break;}
          }
          if(auto*p=t_const_field::UberCast(it.body.get())){
            value_or_qst_or_const_found=true;break;
          }
        }
      }
      bool vqcnb_mode=value_or_qst_or_const_found||(!v.pcmds&&v.pfs);
      auto f=[&](string&s,const char*pother){
        if(!v.pfs)return;
        auto&arr=*v.pfs;
        bool fail=true;
        for(int i=0;fail;i++){
          fail=false;
          for(auto&it:arr){
            if(auto*p=t_struct_field::UberCast(it.body.get()))if(p->name.value==s){s=pother+IToS(i);fail=true;break;}
          }
        }
      };
      string s="$";
      f(s,"$");
      string dev="dev";
      f(dev,"$dev");
      t_out&out=c.out;auto&c=out;
      for(int iter=1;iter;iter--)
      {
        {
          auto&arr=r.body.nested;
          out.nested.resize(arr.size());
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            auto&to=out.nested[i];
            to=ex.get();
          }
        }
        if(!r.body.fcc)break;
        /*if(v.pfs){
          provars.clear();
          cmd_id=-1;
          Do(*v.pfs);
          out.provars=provars;
        }*/
        if(v.pcmds)
        {
          procmds.clear();cmd_id=-1;
          Do(v.pcmds);
          out.procmds=procmds;
        }
        string sep;
        out.cppcode=v.c.size()?sep+v.c+"\n":"";
      }
      auto*pcmds=&c.procmds;
      if(vqcnb_mode&&v.pfs){
        QapAssert(c.procmds.empty());
        static string buf;pcmds=&buf;buf={};
        vector<string> cmds;
        auto&arr=*v.pfs;
        int i=-1;
        for(auto&it:arr){
          i++;
          auto*p=t_struct_field::UberCast(it.body.get());
          auto*pc=t_const_field::UberCast(it.body.get());
          const string*plexer=nullptr;
          if(pc)plexer=this->dev.get_sep_lex(pc->value);
          if(plexer){
            int gg=1;
          }
          if(p){
            field.cmdout.clear();
            field.as_cmd=true;
            cmd_id=i-1;
            Do(*p);// Do for Do
            field.as_cmd=false;
          }
          auto cmd=p?field.cmdout:plexer?string(pc->qst?"O":"M")+"+=go_auto($sep"+IToS(i)+");":"M+=go_const("+pc->value+");";
          t_struct_cmd sc;
          auto res=load_obj_full(sc,cmd);
          if(!res.ok){
            QapDebugMsg("t_struct_field::make_cmd return wrong code:\n"+res.msg);
          }
          procmds.clear();
          cmd_id=i-1;
          Do(sc);
          cmds.push_back(procmds);
        }
        buf=join(cmds,"\n");
      }
      vector<string> pcs=split(*pcmds,"\n");
      if(dev!="dev"){
        for(auto&ex:pcs){
          if(ex.find("dev")==string::npos)continue;
          auto a=split(ex,"dev");a[1]=a[0]+dev+a[1];QapPopFront(a);ex=join(a,"dev");
        }
      }
      t_templ_sys_v02::t_inp inp;
      inp.add("PROCMDS",join(pcs,"\n"));
      inp.add("SCOPE",s);
      inp.add("DEV",dev);
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
    if(bool need_attrs=true)for(int iter=1;iter;iter--){
      vector<string> oarr;
      if(!v.pfs)break;
      auto&arr=*v.pfs;
      for(auto&f:arr){
        auto*p=t_struct_field::UberCast(f.body.get());
        if(!p||!p->attr)continue;
        auto&attrs=p->attr.get()->arr;
        vector<string> ats;
        for(auto&a:attrs){
          string mem;
          bool ok=save_obj(a,mem);
          QapAssert(ok);
          ats.push_back(escape_cpp_string(mem));
        }
        string scvs="static const vector<string>";
        oarr.push_back("  "+scvs+"&"+p->name.value+"_attributes(){"+scvs+" a={"+join(ats,",")+"};return a;}");
      }
      body+=join(oarr,"\n")+"\n";
    }
    if(is_interface){
      QapAssert(L.parent.empty());
      auto&pcarr=dev.arr.back().nesteds.pcarr;
      vector<string> list;
      for(auto&ex:pcarr){
        def_info={};
        Do(ex->def);
        if(def_info.name=="t_var_expr"){
          int gg=1;
        }
        if(def_info.parent!=L.name)continue;
        list.push_back(def_info.name);
      }
      string out;
      {
        t_templ_sys_v02::t_inp inp;
        inp.add("I_BASE",L.name);
        inp.add("OWNER",owner);
        inp.add("OWNER_TYPEDEF_I_BASE",owner.empty()?"":"typedef "+owner+"::"+L.name+" "+L.name+";");
        inp.add("OWNER_TYPEDEF_U",owner.empty()?"":"typedef "+owner+"::U U;");
        inp.add("ADDLIST",join(viz_with_add(list),"\n"));
        inp.add("DO_LIST",join(viz_with_doo(list),"\n"));
        inp.add("COMMENT_DO_LIST",join(viz_with_cdo(list),"\n"));
        before_head+=get_templ("VISITOR").eval(inp);
      }
      {
        static t_target_item ti;
        static t_struct_def*psd=nullptr;
        if(!psd){
          ti.def=std::move(make_unique<t_struct_def>());
          psd=dynamic_cast<t_struct_def*>(ti.def.get());
        }
        psd->name.value=L.name;
      }
      string body2;
      {
        t_templ_sys_v02::t_inp inp;
        inp.add("I_BASE",L.name);
        body2+=get_templ("USE_BASE").eval(inp);
      }
      {
        auto&arr=list;
        string list,qist;
        for(int i=0;i<arr.size();i++)list+="      F("+arr[i]+");\n";
        for(int i=0;i<arr.size();i++)qist+="  F("+arr[i]+");\n";
        t_templ_sys_v02::t_inp inp;
        inp.add("NAME",L.name);
        inp.add("LIST",list);
        body2+=drop_empty_lines(get_templ("GO_BASE").eval(inp));
        vector<string> full_owner;
        for(auto&ex:dev.arr)if(ex.lexer.name.size())full_owner.push_back(ex.lexer.name);
        t_at_end ae={join(full_owner,"::"),L.name,qist};
        at_end.push_back(ae);
      }
      if(is_interface){
        body2+="\n"+v.c;
      }
      out+=body2;
      out=drop_empty_lines(out);
      //out+="\n"+string(owner.empty()?"":"  ")+"};";
      body+=drop_empty_lines(out);
    }
    if(!c.out.cppcode.empty()){
      //QapDebugMsg("[2014.02.12 14:14]:\nuse 't_static_visitor' instead of 'usercode inside lexem'.");
    }
    if(!c.out.cppcode.empty()){
      body+=c.out.cppcode;
    }
    body=std::move(before_head+out+body);
    body=drop_empty_lines(body);
    body+="\n};\n";
    body=drop_empty_lines(body);
    dev.arr.back().out+=move_block("\n"+body+"\n",owner.empty()?"":"  ");
    dev.pop();
  }
  vector<TAutoPtr<t_target_item>> ibuf;
  bool target_only=false;
  void Do(t_target_decl&r)override{
    if(target_only)return;
    dev.top.out+="  struct "+r.name+";";
  }
  void Do(t_target_using&r)override{if(!target_only)dev.add_sep_lex(r.s,r.lexer);}
  void Do(t_target&r){Do(r.arr);}
  template<class TYPE>
  void Do(TYPE*p){if(p)Do(*p);}
  template<class TYPE>
  void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(ex);}
  //template<class TYPE>
  //void Do(vector<TAutoPtr<TYPE>>&arr){for(auto&ex:arr)if(ex)Do(*ex.get());}
  template<class TYPE>
  void Do(TAutoPtr<TYPE>&r){if(r)Do(*r.get());}
  string main(const string&data){
    init();
    t_target tar;
    auto r=load_obj_full(tar,data);
    if(!r.ok){QapDebugMsg(r.msg);return {};}
    auto&dtn=dev.top.nesteds;
    target_only=true;
    dtn.need_igrab=true;
    Do(tar);
    dtn.need_igrab=false;
    dtn.need_grab=true;
    Do(tar);
    dtn.need_grab=false;
    target_only=false;
    interface_autogen();
    Do(tar);
    dev.top.out+=get_at_end();
    vector<i_target_item*> tarr;
    for(auto&ex:tar.arr)tarr.push_back(ex.get());
    auto listoftypes=get_list_of_types(tarr);
    string result=(
      dev.top.out+"\n"
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
    return drop_empty_lines(result);
  }
  void interface_autogen(){
    auto&dtn=dev.top.nesteds;
    for(auto&ex:dev.top.iarr){
      t_target_item*pni=nullptr;
      for(auto&it:dtn.arr){
        it->def->Use(*this);
        if(def_info.name!=ex)continue;
        pni=it;
        break;
      }
      if(!pni){
        auto u=make_unique<t_target_item>();
        pni=u.get();
        load_obj(*pni,ex+"{}");
        ibuf.push_back(std::move(u));
      };
      interfaces_only=true;
      target_only=true;
      Do(*pni);
      target_only=false;
      interfaces_only=false;
    }
  }
  bool interfaces_only=false;
  void DoGrab(t_target_item&r){
    target_only=true;
    dev.top.nesteds.need_igrab=true;
    Do(r.body.nested);
    dev.top.nesteds.need_igrab=false;
    dev.top.nesteds.need_grab=true;
    Do(r.body.nested);
    dev.top.nesteds.need_grab=false;
    target_only=false;
  }
};

#if(1)
struct t_class_def_fixer:
  t_templ_sys_v04,
  t_meta_lexer::i_target_item_visitor,
  t_meta_lexer::i_def_visitor
{
  #define ADD(F)typedef t_meta_lexer::F F;
    ADD(t_target_sep)\
    ADD(t_target_item)\
    ADD(t_target_decl)\
    ADD(t_target_using)\
    ADD(t_class_def)\
    ADD(t_struct_def)\
    ADD(i_target_item)\
      //
  #undef ADD
  template<class TYPE>
  void Do(TYPE*p){if(p)Do(*p);}
  template<class TYPE>
  void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(&ex);}
  template<class TYPE>
  void Do(vector<TAutoPtr<TYPE>>&arr){for(auto&ex:arr)if(ex)Do(ex.get());}
  template<class TYPE>
  void Do(TAutoPtr<TYPE>&r){if(r)Do(*r.get());}
  void Do(t_class_def&r){
    r.sep0.value="";
    r.sep1.value="";
    r.arrow_or_colon=":";
  }
  template<class TYPE>
  bool is_empty(TYPE&r){
    string out;
    save_obj(r,out);
    if(drop_empty_lines(out).empty())return true;
    return false;
  }
  void Do(t_meta_lexer::t_fields_cmds_cppcode::t_cmds&r){if(!is_empty(r.cppcode))r.cppcode=nullptr;}
  void Do(t_meta_lexer::t_fields_cmds_cppcode::t_true_fcc&r){if(!is_empty(r.cppcode))r.cppcode=nullptr;}
  void Do(t_meta_lexer::t_fields_cmds_cppcode::t_cppcode&r){if(!is_empty(r.cppcode))r.cppcode=nullptr;}
  void Do(const t_fields_cmds_cppcode&fcc){
    if(fcc.tfcc)Do(*fcc.tfcc.get());
    if(fcc.cmds)Do(*fcc.cmds.get());
    if(fcc.c)Do(*fcc.c.get());
  }
  void Do(t_struct_def&r){}
  void Do(i_target_item&r){r.Use(*this);}
  void Do(t_target_sep&r){}
  void Do(t_target_item&r){r.def->Use(*this);Do(r.body.nested);Do(r.body.fcc);}
  void Do(t_target_decl&r){}
  void Do(t_target_using&r){}
  bool cppcode_killer=true;
  string main(const string&data){
    t_target tar;
    auto fs=load_obj_full(/*Env,*/tar,data);
    if(!fs.ok){cerr<<fs.msg<<endl;return "fail";}
    if(tar.arr.empty()){return "!target\n\n"+fs.msg;}
    for(auto&ex:tar.arr){
      auto*p=ex.get();
      p->Use(*this);
    }
    string out;
    save_obj(tar,out);
    return out;
  }
};
#endif
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
  //string content=file_get_contents("LexemGenData.inl");
  //content=StrReplace(content,"\r","");
  //t_templ_sys_v03 templates_v03;
  //load_obj(/*Env,*/templates_v03,content);
  int gg=1;
  t_templ_sys_v04 v4;
  //v4.load(/*Env,*/templates_v03);
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
  if(bool nedd_class_def_fixer=false){
    t_class_def_fixer cdf;
    string out=cdf.main(file_get_contents(fn));
    file_put_contents(fn,out);
  }
  t_templ_sys_v05 v5;
  string str2=v5.main(inp);
  //string str=v4.main(inp);
  string out="// "+FToS(clock.MS())+" ms\n"+str2;
  std::cout<<out;
  gg=2;
}