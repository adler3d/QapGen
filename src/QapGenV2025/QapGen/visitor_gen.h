//#include "StdAfx.h"

struct t_meta_lexer;

#include "meta_lexer.inl"
#include "templ_lexer_v02.inl"

#include "templ_lexer_v03.inl"

extern void UberInfoBox(const string&caption,const string&text);

auto lex2str=[](auto&lex){
  string out;
  save_obj(lex,out);
  return out;
};

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
      auto*p=t_target_struct::UberCast(arr[i]);
      if(!p)continue;
      out.push_back(p->name.value);
    }
    return out;
  }
  static vector<string> get_iarr(const vector<i_target_item*>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*pc=t_target_struct::UberCast(arr[i]);
      if(!pc||!pc->parent)continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(pc->parent->parent.value==out[j]);
      if(flag)continue;
      out.push_back(pc->parent->parent.value);
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
  static string move_block(const string&source,int ds){
    if(!ds)return source;
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    for(auto&ex:arr){
      auto p=ex.find_first_not_of(' ');
      if(p==string::npos){ex.clear();continue;}
      ex=ex.substr(std::min(p,size_t(2u)));
    }
    auto out=join(arr,"\n");
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
    vector<string> childs;
    string get_impl()const{
      vector<string> v={
        //"template<int>\n",
        "void "+(full_owner.empty()?"":full_owner+"::")+base+"::t_poly_impl::load()\n",
        "{\n",
        "  #define F(TYPE)go_for<TYPE>();\n",
        list,
        "  #undef F\n",
        "  main();\n",
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
      auto*p=t_target_struct::UberCast(arr[i]);
      if(!p)continue;
      string&n=p->name.value;
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
    vector<t_meta_lexer::t_target_struct*> arr;
    vector<t_meta_lexer::t_target_struct*> piarr;
    vector<t_meta_lexer::t_target_struct*> pcarr;
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
  t_meta_lexer::t_target_struct::i_struct_impl::i_visitor
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
  F(t_sep_field                   )\
  F(t_semicolon_field             )\
  F(t_const_field                 )\
  F(t_struct_field_value          )\
  F(t_struct_field                )\
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
  F(t_target_struct               )\
  F(t_target_semicolon            )\
  F(t_target_sep                  )\
  F(t_target_using                )\
  F(t_target_typedef              )\
  F(t_target                      )\
  F(i_code           )\
  F(i_code_with_sep  )\
  F(i_type_item      )\
  F(i_type_templ     )\
  F(i_struct_cmd_xxxx)\
  F(i_struct_field   )\
  F(i_struct_cmd_so  )\
  F(i_cpp_code       )\
  F(i_target_item    )\
  //
  #undef F
  #define F(T)void Do(T&r){r.Use(*this);}
  F(i_struct_cmd_xxxx)
  F(i_struct_field   )
  F(i_struct_cmd_so  )
  F(i_target_item    )
  #undef F
  #pragma endregion
  void Do(t_struct_cmd_mode&r)override{}
  void Do(t_struct_cmd_anno&r)override{}
  void Do(t_struct_cmd_suffix&r)override{}
  void Do(t_struct_cmd_optional&r)override{}
  void Do(t_struct_cmd_opt_v2&r)override{}
  t_ic_dev_v2::t_lexer def_info;
  static bool find_smart_func(const string&func){
    static const vector<string> arr=split("go_any_str_from_vec|go_any_arr_char|go_any|go_any_char","|");
    for(int i=0;i<arr.size();i++)if(arr[i]==func)return true;
    return false;
  }
  int cmd_id=-1;
  struct t_lexer{
    string name;
    string fullparent;
    string fullname;
    string fullowner;
    vector<string> fields;
    vector<string> cmds;
    vector<string> childs;
    vector<t_struct_field> farr;
    bool is_interface=false;
    t_lexer(const t_lexer&)=delete;
    t_lexer&operator=(const t_lexer&)=delete;
    t_lexer(t_lexer&&)=default;
    t_lexer&operator=(t_lexer&&)=default;
  };
  vector<t_lexer> lexers;
  vector<string> lexer_fields;
  vector<string> lexer_cmds;
  bool cmds_grab=true;
  void Do(t_struct_cmd&r){
    if(cmds_grab){
      string cmdstr;
      save_obj(r,cmdstr);
      lexer_cmds.push_back(cmdstr);
    }
    cmd_id++;
    char m='D';//r.cmdso?r.cmdso->get_mode():'D';
    if(r.cmdso)QapDebugMsg("cmd_so is deprecated");
    QapAssert(r.cmdso||r.mode?bool(r.cmdso)!=bool(r.mode):true);
    auto*pm=t_struct_cmd_mode::UberCast(r.mode.get());
    string out=CToS(pm?pm->body:m);//CToS(r.mode?r.mode->get_mode():m);
    vector<string> params_code;
    {auto&arr=r.params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
    auto check=out!="O"?"    if(!ok)return ok;\n":"";
    out=out!="O"?"ok=":"";
    string func_name=r.func.value;
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
      out=vardecl+"    "+out+"dev."+r.func.value+"("+param0+","+varname+");\n"+check;
      procmds+=out;
    }else{
      procmds+="    "+out+"dev."+r.func.value+r.templ_params+"("+join(params_code,",")+");\n"+check;
    }
  }
  void Do(t_struct_cmds&r){for(auto&ex:r.arr)Do(ex);}
  void Do(t_sep_struct_cmd&r){Do(r.body);}
  void Do(t_sep_struct_cmds&r){Do(r.body);}
  void Do(t_semicolon_field&r)override{}
  void Do(t_const_field&r)override{
    if(field.find_qst){
      field.find_qst_result=false;
      if(r.qst)field.find_qst_result=true;
      return;
    }
    cmd_id++;
    const string*plexer=dev.get_sep_lex(r.value);
    if(field.as_cmd){
      QapNoWay();
      //if(!plexer){field.cmdout={};return;}else{QapNoWay();return;}
      //field.cmdout="M+=go_const("+r.value+");";
      return;
    }
    if(!plexer)return;
    fields_counter++;
    provars+="ADDVAR("+*plexer+",$sep"+IToS(cmd_id)+",DEF,$,$)\\\n";
    lexer_fields.push_back(*plexer+" $sep"+IToS(cmd_id)+";");
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
      //QapAssert(r.qst||r.mode?bool(r.qst)!=bool(r.mode):true);
      //QapAssert(!r.mode);
      //auto*pm=t_struct_cmd_mode::UberCast(r.mode.get());
      //string out=CToS(!r.qst?(r.mode?r.mode->get_mode():'D'):m)+"+=";
      string out=CToS(m)+"+=";
      string call,params;
      if(r.value){
        auto*pce=r.value->expr.get();//t_cppcore::t_call_expr::UberCast(value->expr.get());
        QapAssert(pce);
        QapAssert(save_obj(pce->var,call));
        auto*p=pce->params.get();
        if(!p)QapDebugMsg("call with name = '"+call+"' dont have params");
        if(p->arr.size()>=2)QapDebugMsg("look like you forget to remove var from params in field: "+lex2str(r));
        if(p->arr.size())save_obj(p->arr[0],params);
      }
      string go=r.value?call+"("+r.name.value+string(params.size()?","+params:"")+");":"auto("+r.name.value+");";
      field.cmdout+=out+"go_"+go;
      return;
    }
    fields_counter++;
    cmd_id++;
    vector<string> out;
    string mode="DEF";
    string type_mem;
    QapAssert(r.type&&save_obj(*r.type.get(),type_mem));
    auto t=type_mem;
    for(int i=0;t.size()&&t.back()==' ';i++)t.pop_back();
    if(bool vec_algo=true){
      auto a=split(t,"<");
      if(a.size()==2&&a[0]=="vector"){
        auto b=split(a[1],">");
        QapAssert(b.size()==2);
        //QapAssert(b[1]=="");
        if(dev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>";//+b[1];
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
    auto ts=join(out,",");
    string vs="$";
    provars+="ADDVAR("+ts+","+vs+")\\\n";
    lexer_fields.push_back(t+" "+r.name.value+";");
  }
  int fields_counter=0;
  string provars,procmds;
  void Do(t_target_struct&r)override{
    if(!t_target_struct::t_body_impl::UberCast(r.body.get())){
      QapAssert(t_target_struct::t_body_semicolon::UberCast(r.body.get()));
      if(!target_only)dev.top.out+="\nstruct "+r.name.value+";\n";
      return;
    }
    def_info.name=r.name.value;def_info.parent=r.parent?r.parent->parent.value:"";def_info.sep.clear();
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
    target_item_counter++;
    //L.sep=r.sep0.value;
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
    Do(r.body);
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
    out+="\n";
    out+="#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)";
    out+="NAME("+L.name+")"+parent_info+owner_info;
    dev.top.out+=out+"\n";
    out.clear();
    struct t_visitor:t_cpp_code::i_bayan_visitor,t_target_struct::i_struct_impl::i_visitor{
      t_struct_cmds*pcmds{};
      vector<TAutoPtr<i_struct_field>>*pfs{};
      string c;
      void Do(t_cpp_code::t_with_bayan&r)override{save_obj(r.eater,c);}
      void Do(t_cpp_code::t_without_bayan&r)override{save_obj(r.eater,c);}
      void Do(t_body_semicolon&r)override{}
      void Do(t_body_impl&r)override{if(r.cmds)pcmds=r.cmds.get();if(r.arr.size())pfs=&r.arr;if(r.c)r.c->bayan->Use(*this);}
      void Do(TAutoPtr<i_struct_impl>&r){if(r)r->Use(*this);}
    };
    t_visitor v;
    //v.pfs=&r.body.fcc->arr;
    //v.pcmds=r.body.fcc->cmds.get();
    //if(r.body.fcc->c)r.body.fcc->c->bayan->Use(v);
    QapAssert(r.body);
    v.Do(r.body);
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
    if(r.body&&!is_interface)for(int iter=1;iter;iter--)
    {
      bool value_or_qst_or_const_found=false;
      if(v.pfs){
        auto&arr=*v.pfs;
        for(auto&it:arr){
          if(auto*p=t_struct_field::UberCast(it.get())){
            if(p->value||p->qst){value_or_qst_or_const_found=true;break;}
          }
          if(auto*p=t_const_field::UberCast(it.get())){
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
            if(auto*p=t_struct_field::UberCast(it.get()))if(p->name.value==s){s=pother+IToS(i);fail=true;break;}
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
          auto*pb=t_target_struct::t_body_impl::UberCast(r.body.get());
          if(!pb)continue;
          auto&arr=pb->nested;
          out.nested.resize(arr.size());
          for(int i=0;i<arr.size();i++){
            auto&ex=arr[i];
            auto&to=out.nested[i];
            to=ex.get();
          }
        }
        //if(!r.body.fcc)break;
        //if(v.pcmds||v.pfs)QapAssert(bool(v.pcmds)!=bool(v.pfs));
        if(v.pcmds)
        {
          procmds.clear();cmd_id=-1;
          Do(v.pcmds);
          out.procmds=procmds;
        }
        string sep="\n  ";
        string cc=move_block(v.c,-2);
        out.cppcode=cc.size()?sep+cc+"\n":"";
        if(out.cppcode.find("inline")!=string::npos){
          int gg=1;
        }
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
          auto*p=t_struct_field::UberCast(it.get());
          auto*pc=t_const_field::UberCast(it.get());
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
        auto*p=t_struct_field::UberCast(f.get());
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
        //def_info={};
        //def_only=true;
        //Do(ex->def);
        //def_only=false;
        //if(ex.name.value=="t_var_expr"){
        //  int gg=1;
        //}
        if(!ex->parent||ex->parent->parent.value!=L.name)continue;
        list.push_back(ex->name.value);
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
        t_at_end ae={join(full_owner,"::"),L.name,qist,arr};
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
    string fullowner=get_fullpreowner();
    if(fullowner.size()){fullowner.pop_back();fullowner.pop_back();}
    string fullname=(fullowner.size()?fullowner+"::":"")+L.name;
    lexers.push_back({L.name,get_fullparent(),fullname,fullowner,std::move(lexer_fields),std::move(lexer_cmds),is_interface?at_end.back().childs:vector<string>{},{},is_interface});
    dev.pop();
  }
  string get_fullpreowner(){
    string fullname;
    for(size_t i=0;i<dev.arr.size();i++){
      auto&ex=dev.arr[i].lexer.name;
      if(!ex.empty())fullname+=ex+"::";
    }
    return fullname;
  }
  string get_fullparent(){
    auto&dtl=dev.top.lexer;
    if(dtl.name=="t_soft_brackets_code_with_sep"){
      int gg=1;
    }
    if(dtl.parent.empty())return {};
    auto&iarr=dev.arr.back().iarr;
    bool found=false;
    for(auto&ex:iarr){
      if(ex==dtl.parent)found=true;
    }
    if(!found)QapDebugMsg("lexer parent not found for "+dtl.name+":"+dtl.parent);
    auto fpo=get_fullpreowner();
    return fpo+dtl.parent;
    /*
    for(auto i=long long int(dev.arr.size())-1;i>=0;i--){
      auto&ex=dev.arr[i];
      string*pit=nullptr;
      for(auto&it:ex.carr){
        if(it!=dtl.parent)continue;
        pit=&it;
        break;
      }
      if(ex.lexer.name==dtl.parent)pit=&ex.lexer.name;
      if(!pit)continue;
      string fullname;
      for(long long int j=0;j<dev.arr.size()&&j!=i;j++){
        auto&ex=dev.arr[j].lexer.name;
        if(!ex.empty())fullname+=ex+"::";
      }
      fullname+=*pit;
      return fullname;
    }*/
    return {};
  }
  vector<TAutoPtr<t_target_struct>> ibuf;
  bool target_only=false;
  int target_item_counter=0;
  void Do(t_target_semicolon&r)override{}
  void Do(t_target_sep&r)override{
    auto&dtn=dev.top.nesteds;
    if(dtn.need_igrab||dtn.need_grab)return;
    if(!target_only)dev.top.out+=r.sep.value;
  }
  void Do(t_target_using&r)override{if(!target_only)dev.add_sep_lex(r.s,r.lexer);}
  void Do(t_target_typedef&r)override{
    if(target_only)return;
    string t;
    QapAssert(save_obj(r.type,t));
    dev.top.out+="typedef "+t+" "+r.name.value+";\n";
  }
  void Do(t_sep_field&r)override{}
  void Do(t_body_semicolon&r)override{}
  void Do(t_body_impl&r)override{Do(r.nested);}
  void Do(t_target&r){Do(r.arr);}
  void Do(t_target_struct::i_struct_impl&r){r.Use(*this);}
  template<class TYPE>
  void Do(TYPE*p){if(p)Do(*p);}
  template<class TYPE>
  void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(ex);}
  //template<class TYPE>
  //void Do(vector<TAutoPtr<TYPE>>&arr){for(auto&ex:arr)if(ex)Do(*ex.get());}
  template<class TYPE>
  void Do(TAutoPtr<TYPE>&r){if(r)Do(*r.get());}
  real parse_ms=0;
  void prepare_lexers_chached_fields(){
    for(auto&L:lexers){
      L.farr.reserve(L.fields.size());
      for(int i=0;i<L.fields.size();i++){
        auto&ex=L.fields[i];
        auto&b=qap_add_back(L.farr);
        QapAssert(load_obj(b,ex));
      }
    }
  }
  void collect_expected_chars(const t_cmd_param&param,string&out,bool vecofstr=false)const{
    typedef t_meta_lexer::t_cmd_param::t_expr_str t_expr_str;
    typedef t_meta_lexer::t_cmd_param::t_expr_call t_expr_call;
    typedef t_meta_lexer::t_cmd_param::t_impl t_impl;
    typedef t_meta_lexer::t_cmd_params t_cmd_params;
    t_meta_lexer::t_cmd_param::t_impl impl;
    load_obj(impl,param.body);
    for (auto& item_ptr : impl.arr) {
      if (!item_ptr) continue;
      if(auto expr_str=t_expr_str::UberCast(item_ptr.get())){
        QapAssert(!vecofstr);
        auto&s=expr_str->body;
        QapAssert(s.size()>=2);
        QapAssert(s[0]=='"');
        QapAssert(s.back()='"');
        auto raw=s.size()==2?"":BinString::fullCppStr2RawStr(s);
        out+=raw;
      }
      else if(auto expr_call=t_expr_call::UberCast(item_ptr.get())){
        if(expr_call->func.value=="split"){
          QapAssert(vecofstr);
          QapAssert(expr_call->params && expr_call->params->arr.size()==2);
          auto&p0=expr_call->params->arr[0];
          auto&p1=expr_call->params->arr[1];
          t_meta_lexer::t_cmd_param::t_impl impl0,impl1;
          QapAssert(load_obj(impl0,p0.body));
          QapAssert(load_obj(impl1,p1.body));
          QapAssert(impl0.arr.size()==1);
          QapAssert(impl1.arr.size()==1);
          auto*sp0=t_expr_str::UberCast(impl0.arr[0].get());
          auto*sp1=t_expr_str::UberCast(impl1.arr[0].get());
          QapAssert(sp0&&sp1);
          QapAssert(sp1->body.size());
          auto v=split(BinString::fullCppStr2RawStr(sp0->body),BinString::fullCppStr2RawStr(sp1->body));
          QapAssert(v.size());
          for(auto&ex:v){
            QapAssert(ex.size());
            out.push_back(ex[0]);
          }
          int gg=1;
        }
        if(expr_call->func.value=="gen_dips"){
          QapAssert(!vecofstr);
          QapAssert(expr_call->params && expr_call->params->arr.size()==1);
          auto& first_param = expr_call->params->arr[0];
          t_meta_lexer::t_cmd_param::t_impl impl;
          QapAssert(load_obj(impl,first_param.body));
          QapAssert(impl.arr.size()==1);
          if(auto*str_param=t_expr_str::UberCast(impl.arr[0].get())){
            auto s=gen_dips(BinString::fullCppStr2RawStr(str_param->body));;
            out+=s;
          }else QapNoWay();
          int gg=1;
        }
        if(expr_call->func.value=="dip_inv"){
          QapAssert(!vecofstr);
          QapAssert(expr_call->params && expr_call->params->arr.size()==1);
          auto& first_param = expr_call->params->arr[0];
          t_meta_lexer::t_cmd_param param;
          QapAssert(load_obj(param,first_param.body));
          string out2;
          collect_expected_chars(param,out2);
          out+=dip_inv(out2);
          int gg=1;
        }
        int gg=1;
      }else QapDebugMsg("Warning: look like variable passed as go_any second parameter, ignored");
      int gg_loop=1;
    }
  }
  const t_struct_field&find_field(const t_lexer&lexer,const std::string&name)const{
    for(auto&ex:lexer.farr){
      if(ex.name.value==name)return ex;
    }
    QapDebugMsg("can't find field '"+name+"' inside lexer '"+lexer.fullname+"'");
    return lexer.farr[0];
  }
  string lexer2vecofchar(const t_lexer&lexer)const{
    if(lexer.is_interface){
      return polylexer2vecofchar(lexer);
    }
    string out;
    for(auto&c:lexer.cmds){
      auto&fields=lexer.farr;
      t_struct_cmd cmd;
      QapAssert(load_obj(cmd,c));
      auto*p=t_struct_cmd_mode::UberCast(cmd.mode.get());
      //QapAssert(p);
      bool opt=p?p->body=='O':false;
      auto fn=cmd.func.value;
      if(fn=="go_const"){
        QapAssert(cmd.params.arr.size()==1);
        auto s=cmd.params.arr[0].body;
        QapAssert(s.size()>2);
        //TAutoPtr<vector<i_str_item>> si;//load_obj(si,s);
        auto bs=BinString::fullCppStr2RawStr(s);
        out.push_back(bs[0]);
        QapAssert(!opt);
        return out;
        int gg=1;
      }
      auto bad_type_checker=[](auto&lex,const string&type){
        string s=lex2str(*lex.get());
        return s.substr(0,type.size())==type;
      };
      if(fn=="go_any"||fn=="go_any_char"){
        QapAssert(cmd.params.arr.size()==2);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        if(fn=="go_any")QapAssert(bad_type_checker(f.type,"string"));
        if(fn=="go_any_char")QapAssert(bad_type_checker(f.type,"char"));
        auto p0=cmd.params.arr[0].body;
        auto p1=cmd.params.arr[1].body;// выражение типа gen_dips("09")+"str"+"other_str"
        t_cmd_param p1p;
        QapAssert(load_obj(p1p,p1));
        collect_expected_chars(p1p,out);
        if(opt)continue;
        return out;
      }
      if(fn=="go_any_str_from_vec"){
        QapAssert(cmd.params.arr.size()==2);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        QapAssert(bad_type_checker(f.type,"string"));
        auto p0=cmd.params.arr[0].body;
        auto p1=cmd.params.arr[1].body;// выражение типа split("0,9",",")
        t_cmd_param p1p;
        QapAssert(load_obj(p1p,p1));
        collect_expected_chars(p1p,out,true);
        if(opt)continue;
        return out;
      }
      if(fn=="go_end"){
        QapAssert(cmd.params.arr.size()==1);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        auto p0=cmd.params.arr[0].body;
        auto p1=cmd.params.arr[1].body;
        auto p1s=BinString::fullCppStr2RawStr(p1);
        if(p1s.size()==1)QapDebugMsg("use go_any(dip_inv("+p1+")) instead of go_end("+p1+")");
        QapDebugMsg("go_end with str - under construction");
      }
      typedef t_cppcore::t_varcall_expr::t_var t_var;
      auto tp2var=[](const auto&tp,t_var&out){
        auto*ptp=t_cppcore::t_varcall_expr::t_template_part::UberCast(tp.get());
        string s;save_obj(ptp->expr,s);
        QapAssert(load_obj(out,s));
      };
      struct t_for_autoptr_r{
        bool con=false;
        bool ret=false;
      };
      auto for_autoptr=[&](const t_var&var,const string&tpn)->t_for_autoptr_r{
        if(tpn!="TAutoPtr")return {};
        t_var inner_param;
        tp2var(var.tp,inner_param);
        auto inner_pn=inner_param.name.value;
        vector<string> ftn;
        if(inner_param.tp){
          auto*p=t_cppcore::t_varcall_expr::t_dd_part::UberCast(inner_param.tp.get());
          QapAssert(p);
          auto&arr=p->arr;
          for(auto&ex:arr){
            ftn.push_back(ex.name.value);
          }
        }
        string ln=inner_pn+(ftn.size()?"::":"")+join(ftn,"::");
        auto*pl_inner=find_lexer_by_name_but_relative(ln,lexer);
        QapAssert(pl_inner);
        auto nested_chars=lexer2vecofchar(*pl_inner);
        QapAssert(!nested_chars.empty());
        out+=nested_chars;
        if(!opt)return {false,true};
        return {true,false};
      };
      if(fn=="go_auto"){
        QapAssert(cmd.params.arr.size()==1);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        auto*pvc=t_cppcore::t_varcall_expr::UberCast(f.type.get());
        QapAssert(pvc);
        auto&v=pvc->var;
        if(v.name.value=="TAutoPtr"){
          auto r=for_autoptr(v,v.name.value);
          if(r.ret)return out;
          if(r.con)continue;
        }
        if(v.name.value=="vector"){
          QapAssert(v.tp);
          t_var template_param;
          tp2var(v.tp,template_param);
          auto tpn=template_param.name.value;
          QapAssert(tpn!="vector");
          auto r=for_autoptr(template_param,tpn);
          if(r.ret)return out;
          if(r.con)continue;
          auto*pl=find_lexer_by_name_but_relative(tpn,lexer);
          QapAssert(pl);
          out+=lexer2vecofchar(*pl);
          if(!opt)return out;
          continue;
        }
        auto*pl=find_lexer_by_name_but_relative(v.name.value,lexer);
        QapAssert(pl);
        out+=lexer2vecofchar(*pl);
        if(!opt)return out;
        continue;
      }
      if(fn=="go_str"||fn=="go_vec"){
        QapAssert(cmd.params.arr.size()==1);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        auto*pvc=t_cppcore::t_varcall_expr::UberCast(f.type.get());
        QapAssert(pvc);
        auto&v=pvc->var;
        if(fn=="go_str"&&v.name.value!="string")QapDebugMsg("go_str support only string type of field");
        QapAssert(cmd.templ_params.size());
        TAutoPtr<t_templ_params> tp;
        QapAssert(load_obj(tp,cmd.templ_params));
        QapAssert(tp->body.size());
        TAutoPtr<t_type_templ_params> ttp;
        QapAssert(load_obj(ttp,tp->body));
        QapAssert(ttp);
        QapAssert(ttp->first.body);
        auto*ptit=t_meta_lexer::t_type_item_type::UberCast(ttp->first.body.get());
        QapAssert(ptit);
        if(ptit->type.value=="vector"||ptit->type.value=="TAutoPtr"){
          QapAssert(ptit->param);
          auto*ptta=t_meta_lexer::t_type_templ_angle::UberCast(ptit->param->body.get());
          QapAssert(ptta);
          QapAssert(ptta->params);
          QapAssert(ptta->params->first.body);
          auto*ptit2=t_type_item_type::UberCast(ptta->params->first.body.get());
          QapAssert(ptit2);
          if(ptit2->param){
            QapAssert(ptit2->type.value=="TAutoPtr");
            auto*ptta=t_meta_lexer::t_type_templ_angle::UberCast(ptit->param->body.get());
            QapAssert(ptta);
            QapAssert(ptta->params);
            QapAssert(ptta->params->first.body);
            auto*ptit3=t_type_item_type::UberCast(ptta->params->first.body.get());
            QapAssert(!ptit3->param);
            auto*pl=find_lexer_by_name_but_relative(ptit3->type.value,lexer);
            QapAssert(pl);
            out+=lexer2vecofchar(*pl);
            if(opt)continue;
            return out;
          }
          auto*pl=find_lexer_by_name_but_relative(ptit2->type.value,lexer);
          QapAssert(pl);
          out+=lexer2vecofchar(*pl);
          if(opt)continue;
          return out;
        }
        QapAssert(!ptit->param);
        auto*pl=find_lexer_by_name_but_relative(ptit->type.value,lexer);
        QapAssert(pl);
        out+=lexer2vecofchar(*pl);
        if(opt)continue;
        return out;
      }
      if(fn=="go_minor"){
        QapAssert(cmd.params.arr.size()==1);
        auto&cpa0b=cmd.params.arr[0].body;
        auto&f=find_field(lexer,cpa0b);
        auto*pvc=t_cppcore::t_varcall_expr::UberCast(f.type.get());
        QapAssert(pvc);
        auto&v=pvc->var;
        if(v.name.value=="string")QapDebugMsg("go_diff dont support string type of field");
        struct t_for_autoptr_r2{
          bool con=false;
          bool ret=false;
          bool pass()const{return !con&&!ret;}
          string out;
        };
        auto for_autoptr2=[&](const t_var&var,const string&tpn)->t_for_autoptr_r2{
          if(tpn!="TAutoPtr")return {};
          t_var inner_param;
          tp2var(var.tp,inner_param);
          auto inner_pn=inner_param.name.value;
          auto*pl_inner=find_lexer_by_name_but_relative(inner_pn,lexer);
          QapAssert(pl_inner);
          auto nested_chars=lexer2vecofchar(*pl_inner);
          QapAssert(!nested_chars.empty());
          if(!opt)return {false,true,nested_chars};
          return {true,false,nested_chars};
        };
        string our;bool template_lexer=false;
        if(v.name.value=="TAutoPtr"){
          auto r=for_autoptr2(v,v.name.value);
          our+=r.out;
          template_lexer=true;
          //if(r.ret)return out;
          //if(r.con)continue;
        }
        if(v.name.value=="vector"){
          template_lexer=true;
          QapAssert(v.tp);
          t_var template_param;
          tp2var(v.tp,template_param);
          auto tpn=template_param.name.value;
          QapAssert(tpn!="vector");
          auto r=for_autoptr2(template_param,tpn);
          our+=r.out;
          if(r.pass()){
            auto*pl=find_lexer_by_name_but_relative(tpn,lexer);
            QapAssert(pl);
            our+=lexer2vecofchar(*pl);
            //if(!opt)return out;
            //continue;
          }
        }
        if(!template_lexer){
          auto*pl=find_lexer_by_name_but_relative(v.name.value,lexer);
          QapAssert(pl);
          our+=lexer2vecofchar(*pl);
        }
        out+=our;
        if(opt)continue;
        return out;
        // unreachable code now because of wrong hi-level semantic logic. minus is not acceptable in most complex cases
        auto minus=[](const string&our,const string&major){
          auto m=CharMask::fromStr(our,true);
          auto e=CharMask::fromStr(major,true);
          string out;
          for(size_t i=0;i<256;i++)if(!e.mask[i]&&m.mask[i])out.push_back(static_cast<char>(i));
          return out;
        };
        string major;
        //---
        QapAssert(cmd.templ_params.size());
        TAutoPtr<t_templ_params> tp;
        QapAssert(load_obj(tp,cmd.templ_params));
        QapAssert(tp->body.size());
        TAutoPtr<t_type_templ_params> ttp;
        QapAssert(load_obj(ttp,tp->body));
        QapAssert(ttp);
        QapAssert(ttp->first.body);
        auto*ptit=t_meta_lexer::t_type_item_type::UberCast(ttp->first.body.get());
        QapAssert(ptit);
        if(ptit->type.value=="vector"||ptit->type.value=="TAutoPtr"){
          QapAssert(ptit->param);
          auto*ptta=t_meta_lexer::t_type_templ_angle::UberCast(ptit->param->body.get());
          QapAssert(ptta);
          QapAssert(ptta->params);
          QapAssert(ptta->params->first.body);
          auto*ptit2=t_type_item_type::UberCast(ptta->params->first.body.get());
          QapAssert(ptit2);
          if(ptit2->param){
            QapAssert(ptit2->type.value=="TAutoPtr");
            auto*ptta=t_meta_lexer::t_type_templ_angle::UberCast(ptit->param->body.get());
            QapAssert(ptta);
            QapAssert(ptta->params);
            QapAssert(ptta->params->first.body);
            auto*ptit3=t_type_item_type::UberCast(ptta->params->first.body.get());
            QapAssert(!ptit3->param);
            auto*pl=find_lexer_by_name_but_relative(ptit3->type.value,lexer);
            QapAssert(pl);
            major+=lexer2vecofchar(*pl);
            out+=minus(our,major);
            if(opt)continue;
            return out;
          }
          auto*pl=find_lexer_by_name_but_relative(ptit2->type.value,lexer);
          QapAssert(pl);
          major+=lexer2vecofchar(*pl);
          out+=minus(our,major);
          if(opt)continue;
          return out;
        }
        QapAssert(!ptit->param);
        auto*pl=find_lexer_by_name_but_relative(ptit->type.value,lexer);
        QapAssert(pl);
        major+=lexer2vecofchar(*pl);
        out+=minus(our,major);
        if(opt)continue;
        return out;
      }
      QapDebugMsg("unsupported go_* method: "+fn);
      int gg_cmds=1;
    }
    return out;
  }
  string polylexer2vecofchar(const t_lexer&poly)const{
    string out;
    for(auto&ex:poly.childs){
      auto*plexer=find_lexer_by_name_but_relative(ex,poly);
      QapAssert(plexer);
      out+=lexer2vecofchar(*plexer);
    }
    return out;
  }
  string polylexer2fastimpl(const t_lexer&poly){
    string out;
    vector<string> lines;
    vector<CharMask> cases;
    vector<string> types;
    vector<string> sc;
    bool mega_fast=true;
    if(poly.name.find("i_type_templ")!=string::npos){
      int gg=1;
    }
    for(auto&ex:poly.childs){
      auto*plexer=find_lexer_by_name_but_relative(ex,poly);
      QapAssert(plexer);
      string voc=lexer2vecofchar(*plexer);
      auto m=CharMask::fromStr(voc,true);
      string u;
      for(size_t i=0;i<256;i++){
        if(m.mask[i])u.push_back((char)i);
      }
      std::string code=generate_gen_dips_code(u);
      lines.push_back("    F("+plexer->name+","+code+")");
      if(code[0]=='"'&&code.back()=='"'){
        auto c=BinString::fullCppStr2RawStr(code);
        //auto&b=qap_add_back(cases);
        CharMask m;
        if(c.size()>16)mega_fast=false;
        for(auto&ex:c){
          auto u=(uchar)ex;
          for(auto&ex:cases)if(ex.mask[u])mega_fast=false;
          m.mask[u]=true;
        }
        cases.push_back(std::move(m));
        sc.push_back(c);
        types.push_back(plexer->name);
      }else mega_fast=false;
      int gg=1;
    }
    t_templ_sys_v02::t_inp inp;
    if(mega_fast){
      vector<string> codes;int i=-1;
      for(auto&ex:cases){
        i++;
        auto&arr=sc[i];
        vector<string> pre;
        for(auto&c:arr){
          pre.push_back("    case '"+escape_char(c,false)+"'");
        }
        auto&t=types[i];
        //{t_struct_cmd_mode L;auto&ok=scope.ok;ok=dev.go_auto(L);if(ok)ref=make_unique<t_struct_cmd_mode>(std::move(L));return ok;}
        //codes.push_back(join(pre,":\n")+":{"+t+" L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<"+t+">(std::move(L));return;}");
        codes.push_back(join(pre,":\n")+":F("+t+");");
      }
      inp.add("CODE",join(codes,"\n"));
      inp.add("POLY",poly.fullname);
      out+=get_templ("POLY_IMPL_MEGA_FAST").eval(inp);
      return out;
    }
    inp.add("LIST",join(lines,",\n"));
    inp.add("POLY",poly.fullname);
    inp.add("N",IToS(lines.size()));
    out+=get_templ("POLY_IMPL_FAST").eval(inp);
    return out;
  }
  string poly_gen(){
    string out;
    prepare_lexers_chached_fields();
    for(auto&lexer:lexers){
      if(!lexer.is_interface)continue;
      out+=polylexer2fastimpl(lexer)+"\n";
      int gg_lexer=1;
    }
    return out;
  }

  struct t_lexer_node {
    t_lexer* lexer = nullptr;
    std::vector<t_lexer_node*> childs;
  };
  vector<t_lexer_node> lexers_nodes;

  void buildLexerTree(){
    std::unordered_map<std::string,t_lexer_node*> fn2ptr;
    auto&nodes=lexers_nodes;
    nodes.reserve(lexers.size());

    for (auto& lexer : lexers) {
      nodes.push_back({ &lexer, {} });
      fn2ptr[lexer.fullname]=&nodes.back();
    }

    for (size_t i = 0; i < lexers.size(); ++i) {
      const auto& owner = lexers[i].fullowner;
      if(owner.empty())continue;
      auto it = fn2ptr.find(owner);
      if (it != fn2ptr.end()) {
        it->second->childs.push_back(&nodes[i]);
      }
    }
  }

  const t_lexer_node*findByFullname(const t_lexer_node&node,const std::string&fullname)const {
    if(node.lexer->fullname==fullname){
      return &node;
    }
    for(auto&child:node.childs){
      if(auto*found=findByFullname(*child,fullname)){
        return found;
      }
    }
    return nullptr;
  }
  // –екурсивный поиск лексера с именем name внутри узла node
  const t_lexer_node* findByNameInside(const t_lexer_node* node, const std::string& name) const {
    if (!node) return nullptr;

    if (node->lexer->name == name) return node;

    for (const auto& child : node->childs) {
      if(child->lexer->name==name)return child;
    }
    return nullptr;
  }

  const t_lexer_node* findLexerByNameRelative(const std::string& name, const t_lexer& from) const {
    // 1. Ќайти корневой узел дл€ from.name
    const t_lexer_node* fromNode = nullptr;
    for (auto& n : lexers_nodes) {
      if (n.lexer->fullname == from.fullname) {
        fromNode=&n;
        break;
      }
    }

    // 2. ≈сли нашли fromNode Ч ищем внутри него
    if (fromNode) {
      if (auto* inside = findByNameInside(fromNode, name)) {
        return inside;
      }
    }

    // 3. ≈сли не нашли внутри, ищем по абсолютному пути (если есть)
    if (name.size() >= 2 && name[0] == ':' && name[1] == ':') {
      std::string absName = name.substr(2);
      for (auto& root : lexers_nodes) {
        if (auto* found = findByFullname(root, absName)) {
          return found;
        }
      }
      return nullptr;
    }

    // 4. ≈сли from.fullowner не пустой Ч ищем по составному имени
    if (!from.fullowner.empty()) {
      std::vector<std::string> fromParts = split(from.fullowner, "::");
      for (auto i = static_cast<long long int>(fromParts.size()) - 1; i >= 0; --i) {
        std::string prefix = fromParts[0];
        for (int j = 1; j <= i; ++j) {
          prefix += "::" + fromParts[j];
        }
        std::string candidateFullname = prefix + "::" + name;

        for (auto& n : lexers_nodes) {
          if (auto* p = findByFullname(n, candidateFullname)) {
            return p;
          }
        }
      }
    }

    // 5. », наконец, глобальный поиск по имени
    for (auto& root : lexers_nodes) {
      if (auto* found = findByFullname(root, name)) {
        return found;
      }
    }

    return nullptr;
  }

  t_lexer*find_lexer_by_name_but_relative(const string&name,const t_lexer&from)const{
    auto*pl=findLexerByNameRelative(name,from);
    if(!pl)QapDebugMsg("lexer not found name='"+name+"' from='"+from.fullname+"'");
    QapAssert(pl);
    return pl->lexer;
  }
  string main(const string&data,bool dontoptimize){
    init();
    t_target tar;QapClock clock;
    auto r=load_obj_full(tar,data);
    parse_ms=clock.MS();
    std::cerr<<"{\"parse_ms\":"<<parse_ms<<"}"<<endl;
    if(!r.ok){QapDebugMsg(r.msg);return {};}
    //return "";
    auto&dtn=dev.top.nesteds;
    target_only=true;
    dtn.need_igrab=true;
    Do(tar);
    auto msi=clock.MS();std::cerr<<"{\"need_igrab done in \":"<<(msi-parse_ms)<<"}"<<endl;
    dtn.need_igrab=false;
    dtn.need_grab=true;
    Do(tar);
    auto msc=clock.MS();std::cerr<<"{\"need_grab done in \":"<<(msc-msi)<<"}"<<endl;
    dtn.need_grab=false;
    target_only=false;
    interface_autogen();
    auto msa=clock.MS();std::cerr<<"{\"interface_autogen done in \":"<<(msa-msc)<<"}"<<endl;
    Do(tar);
    auto mst=clock.MS();std::cerr<<"{\"Do(tar) done in \":"<<(mst-msa)<<"}"<<endl;
    buildLexerTree();
    auto msb=clock.MS();std::cerr<<"{\"buildLexerTree done in \":"<<(msb-mst)<<"}"<<endl;
    //lexer_lookup_test();
    dev.top.out+="\n";
    if(bool polygen=!dontoptimize){dev.top.out+=poly_gen();}else dev.top.out+=get_at_end();
    auto msp=clock.MS();std::cerr<<"{\"poly_end done in \":"<<(msp-msb)<<"}"<<endl;
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
      t_target_struct*pni=nullptr;
      for(auto&it:dtn.arr){
        if(it->name.value!=ex)continue;
        pni=it;
        break;
      }
      if(!pni){
        auto u=make_unique<t_target_struct>();
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
  void DoGrab(t_target_struct&r){
    target_only=true;
    dev.top.nesteds.need_igrab=true;
    Do(r.body);
    dev.top.nesteds.need_igrab=false;
    dev.top.nesteds.need_grab=true;
    Do(r.body);
    dev.top.nesteds.need_grab=false;
    target_only=false;
  }
};

#if(1)
struct t_class_def_fixer:
  t_templ_sys_v04,
  t_meta_lexer::i_target_item_visitor,
  t_meta_lexer::t_target_struct::i_struct_impl::i_visitor
{
  #define ADD(F)typedef t_meta_lexer::F F;
    ADD(t_target_semicolon)\
    ADD(t_target_sep)\
    ADD(t_target_struct)\
    ADD(t_target_using)\
    ADD(t_target_typedef)\
    ADD(i_target_item)\
      //
  #undef ADD
  template<class TYPE>
  void Do(TYPE*p){if(p)Do(*p);}
  template<class TYPE>
  void Do(TYPE&r){r.Use(*this);}
  template<class TYPE>
  void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(&ex);}
  template<class TYPE>
  void Do(vector<TAutoPtr<TYPE>>&arr){for(auto&ex:arr)if(ex)Do(*ex.get());}
  template<class TYPE>
  void Do(TAutoPtr<TYPE>&r){if(r)Do(*r.get());}
  template<class TYPE>
  bool is_empty(TYPE&r){
    string out;
    save_obj(r,out);
    if(drop_empty_lines(out).empty())return true;
    return false;
  }
  void Do(t_body_semicolon&r)override{}
  void Do(t_body_impl&r)override{
    if(cppcode_killer){
      if(lex2str(r.c).find("inline static const string value=\"")==string::npos){
        r.c=nullptr;
      }
    }
    Do(r.nested);
  }
  void Do(t_target_semicolon&r)override{}
  void Do(t_target_sep&r)override{}
  void Do(t_target_struct::t_parent&r){if(r.arrow_or_colon.size())r.arrow_or_colon=":";}
  void Do(t_target_struct&r)override{Do(r.parent);Do(r.body);}
  void Do(t_target_using&r)override{}
  void Do(t_target_typedef&r)override{}
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

struct t_qapdls_v1_to_v2:
  t_templ_sys_v04,
  t_meta_lexer::i_target_item_visitor,
  t_meta_lexer::t_target_struct::i_struct_impl::i_visitor,
  t_meta_lexer::i_struct_cmd_xxxx::i_visitor
{
  #define ADD(F)typedef t_meta_lexer::F F;
    ADD(t_target_semicolon)\
    ADD(t_target_sep)\
    ADD(t_target_struct)\
    ADD(t_target_using)\
    ADD(t_target_typedef)\
    ADD(i_target_item)\
    ADD(t_struct_cmd_mode)\
    ADD(t_struct_cmd_anno)\
      //
  #undef ADD
  template<class TYPE>
  void Do(TYPE*p){if(p)Do(*p);}
  template<class TYPE>
  void Do(TYPE&r){r.Use(*this);}
  template<class TYPE>
  void Do(vector<TYPE>&arr){for(auto&ex:arr)Do(&ex);}
  template<class TYPE>
  void Do(vector<TAutoPtr<TYPE>>&arr){for(auto&ex:arr)if(ex)Do(*ex.get());}
  template<class TYPE>
  void Do(TAutoPtr<TYPE>&r){if(r)Do(*r.get());}
  //template<class TYPE>
  void Do(t_body_semicolon&r)override{}
  bool opt=false;
  void Do(t_struct_cmd_mode&r){opt=r.body=='O';}
  void Do(t_struct_cmd_anno&r){opt=r.mode[0]=='o';if(r.mode.size()>1)opt=r.mode[1]=='o';}
  t_struct_field&find_field(const vector<TAutoPtr<i_struct_field>>&arr,const std::string&name)const{
    for(auto&ex:arr){
      auto*pf=t_struct_field::UberCast(ex.get());
      QapAssert(pf);
      if(pf->name.value==name)return *pf;
    }
    QapDebugMsg("can't find field '"+name+"' inside lexer '"+lexers.back()+"'");
    static t_struct_field tmp;
    return tmp;
  }
  void Do(t_body_impl&r)override{
    Do(r.nested);
    if(!r.cmds)return;
    auto&arr=r.cmds->arr;
    vector<string> fields;
    for(auto&ex:arr){
      opt=false;
      if(ex.body.mode)Do(ex.body.mode.get());
      auto&f=ex.body.func.value;
      QapAssert(f.size()>3&&f.substr(0,3)=="go_");
      auto res=f.substr(3);
      auto&params=ex.body.params.arr;
      QapAssert(params.size());
      string pad;
      string pad2;
      for(int i=0;i<lexers.size();i++)pad+="  ";
      for(int i=1;i<lexers.size();i++)pad2+="  ";
      if(res=="const"){
        fields.push_back("\n"+pad+params[0].body+"\n"+pad2);
        continue;
      }
      auto&src=find_field(r.arr,params[0].body);
      if(res=="auto"){
        src.qst=nullptr;
        if(opt)load_obj(src.qst,"?");
        fields.push_back("\n"+pad+lex2str(src)+"\n"+pad2);
        continue;
      }
      vector<string> sparams;
      for(int i=1;i<params.size();i++){
        sparams.push_back(params[i].body);
      }
      fields.push_back("\n"+pad+lex2str(src.type)+""+src.name.value+"="+res+ex.body.templ_params+"("+join(sparams,",")+")"+string(opt?"?":"")+";\n"+pad2);
    }
    r.arr.clear();
    auto mem=join(fields,"");
    t_load_dev dev(mem);
    bool ok=dev.go_auto(r.arr);
    QapAssert(ok);
    r.cmds=nullptr;
  }
  void Do(t_target_semicolon&r)override{}
  void Do(t_target_sep&r)override{}
  void Do(t_target_struct::t_parent&r){if(r.arrow_or_colon.size())r.arrow_or_colon=":";}
  vector<string> lexers;
  void Do(t_target_struct&r)override{lexers.push_back(r.name.value);Do(r.parent);Do(r.body);lexers.pop_back();}
  void Do(t_target_using&r)override{}
  void Do(t_target_typedef&r)override{}
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

#include <iostream>

static void test_2025_06_10(/*IEnvRTTI&Env*/string fn,bool dontoptimize=false)
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
  if(bool need_v1_to_v2=false){
    t_qapdls_v1_to_v2 q12;
    string out=q12.main(file_get_contents(fn));
    file_put_contents(fn,drop_empty_lines(out));
    int gg=1;
  }
  t_templ_sys_v05 v5;
  string str2=v5.main(inp,dontoptimize);
  //string str=v4.main(inp);
  string out="// "+FToS(clock.MS())+" ms\n"+str2;
  std::cout<<out;
  std::cerr<<"{\"parse_ms\":"<<v5.parse_ms<<",\"total_ms\":"<<clock.MS()<<",\"lexers\":"<<v5.target_item_counter<<",\"fields\":"<<v5.fields_counter<<",\"g_unique_pool_ptr_counter\":"<<g_unique_pool_ptr_counter<<"}"<<endl;
  gg=2;
}