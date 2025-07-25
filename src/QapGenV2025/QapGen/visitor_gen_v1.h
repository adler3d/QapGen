//#include "StdAfx.h"

#include "templ_lexer_v02.inl"

struct t_ic_dev{
  struct t_sep_lex{
    string sep;
    string lexer;
  };
  struct t_level{
    string name,full_name;
    vector<string> iarr;
    vector<string> carr;
    vector<t_sep_lex> sep_lexs;
  };
  vector<t_level> arr;
  t_level top;
  vector<int> ip;
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
  void push(const string&name,const string&full_name){
    if(top.name==name&&full_name==top.full_name){
      int fail=1;
      {ip.push_back(1);return;}
    }
    if(name.empty()){
      int fail=1;
    }
    //if(top.name==name&&full_name==top.name)
    arr.push_back(std::move(top));
    top.name=name;top.full_name=full_name;
    ip.push_back(0);
  }
  void pop(){
    if(ip.size()&&ip.back()){ip.pop_back();return;}
    top=std::move(arr.back());
    arr.pop_back();
    ip.pop_back();
  }
};
template<class TYPE>
static string vector_make_code(const vector<TYPE>&arr){
  string out;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    out+=ex->make_code();
  }
  return out;
}

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
  static string move_block(const string&source,const string&sep,bool drop_last_line_spaces=false){
    if(sep.empty())return source;
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    auto out=sep+join(arr,"\n"+sep);
    if(drop_last_line_spaces)for(int i=0;out.size()&&out.back()==' ';i++)out.pop_back();
    return out;
  }
  static vector<string> get_iarr(const vector<t_target_item*>&arr)
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
  static vector<string> get_iarr(const vector<i_target_item*>&arr)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*p=dynamic_cast<const t_target_item*>(ex);
      if(!p)continue;
      auto dc=p->def->make_code();
      if(dc.parent.empty())continue;
      bool flag=false;
      for(int j=0;j<out.size();j++)flag=flag||(dc.parent==out[j]);
      if(flag)continue;
      out.push_back(dc.parent);
    }
    return out;
  }
  static vector<string> get_child_list(const vector<i_target_item*>&arr,const string&parent,t_ic_dev&ic_dev)
  {
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto*p=dynamic_cast<const t_target_item*>(arr[i]);
      if(!p)continue;
      auto ex=p->def->make_code();
      if(ex.parent==parent){
        out.push_back(ex.name);
      }
    }
    return out;
  }
  static vector<string> get_child_list(const vector<t_target_item*>&arr,const string&parent,t_ic_dev&ic_dev)
  {
    vector<string> out;
    for(auto&p:arr){
      auto ex=p->make_code(ic_dev);
      if(ex.parent==parent){
        out.push_back(ex.name);
      }
    }
    return out;
  }
  static vector<string> get_nested_list(const vector<i_target_item*>&arr){
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      //auto&ex=*arr[i];
      auto*p=t_target_item::UberCast(arr[i]);
      if(!p)continue;
      out.push_back(p->def->make_code().name);
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
  string make_head_v2(
    const t_target_item&ti,
    const string&owner,
    const string&full_owner,
    //const vector<string>&nested_list,
    t_ic_dev&ic_dev,
    bool iclass
  ){
    string out;
    string target_code=get_target_code(ti,full_owner,ic_dev);
    auto c=ti.make_code(ic_dev);
    auto nested_list=get_nested_list(c.out.nested);
    string parent_part=!c.parent.empty()?":public "+c.parent:"";
    string parent_info=!c.parent.empty()?"PARENT("+c.parent+")":"";
    string owner_info=!owner.empty()?"OWNER("+owner+")":"";
    bool hasVirtual=false;
    for(int i=0;i<c.out.nested.size();i++){
      auto&ex=c.out.nested[i];
      auto*p=t_target_item::UberCast(ex);
      if(!p)continue;
      if(!p->make_code(ic_dev).parent.empty())hasVirtual=true;
    }
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
  string iclass_to_code(const string&name,const vector<string>&arr,const string&owner,const string&full_owner,const t_target_item*pti,t_ic_dev&ic_dev)
  {
    string out;
    {
      t_templ_sys_v02::t_inp inp;
      inp.add("I_BASE",name);
      inp.add("OWNER",owner);
      inp.add("OWNER_TYPEDEF_I_BASE",owner.empty()?"":"typedef "+owner+"::"+name+" "+name+";");
      inp.add("OWNER_TYPEDEF_U",owner.empty()?"":"typedef "+owner+"::U U;");
      inp.add("ADDLIST",join(viz_with_add(arr),"\n"));
      inp.add("DO_LIST",join(viz_with_doo(arr),"\n"));
      inp.add("COMMENT_DO_LIST",join(viz_with_cdo(arr),"\n"));
      out+=move_block(get_templ("VISITOR").eval(inp),owner.empty()?"":"  ",true);
    }
    {
      //t_ic_dev no_dev;
      static t_target_item ti;
      static t_struct_def*psd=nullptr;
      if(!psd){
        ti.def=std::move(make_unique<t_struct_def>());
        psd=dynamic_cast<t_struct_def*>(ti.def.get());
        //ti={};
        //load_obj(ti,"t{}");
        //psd=dynamic_cast<t_struct_def*>(ti.def.get());
      }
      psd->name.value=name;
      //load_obj(ti,"t{}");
      //auto*p=i_def_visitor::UberCast<t_struct_def>(ti.def.get());
      //p->name.value=name;
      out+=make_head_v2(pti?*pti:ti,owner,full_owner,ic_dev,true);
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
    if(pti){
      auto c=pti->make_code(ic_dev);
      if(!c.out.cppcode.empty()){
        //QapDebugMsg("[2025.06.18 13:19:44.748]:\nuse 't_static_visitor' instead of 'usercode inside lexem'.");
      }
      if(c.out.cppcode.empty()){
        out+="};";
      }else{
        body+=move_block(c.out.cppcode,owner.empty()?"":"  ");
        //body+="};";
      }
    }//else body+="};";
    out+=move_block(body,owner.empty()?"":"  ");
    out=drop_empty_lines(out);
    out+="\n"+string(owner.empty()?"":"  ")+"};";
    return drop_empty_lines(out);
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
    out+=make_head_v2(ex,owner,full_owner,ic_dev,false);
    auto c=ex.make_code(ic_dev);
    out=c.sep+"\n"+out;
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
    //if(!c.out.procmds.empty())
    if(ex.body.fcc)for(int iter=1;iter;iter--)
    {
      t_struct_body::t_cmd_fs_getter v;
      v.Do(*ex.body.fcc.get());
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
      //string sep="sep";
      //f(sep,"$sep");
      auto*pcmds=&c.out.procmds;
      if(vqcnb_mode&&v.pfs){
        QapAssert(c.out.procmds.empty());
        static string buf;pcmds=&buf;buf={};
        vector<string> cmds;
        auto&arr=*v.pfs;
        int i=-1;
        for(auto&it:arr){
          i++;
          auto*p=t_struct_field::UberCast(it.body.get());
          auto*pc=t_const_field::UberCast(it.body.get());
          const string*plexer=nullptr;
          if(pc)plexer=ic_dev.get_sep_lex(pc->value);
          if(plexer){
            int gg=1;
          }
          auto cmd=p?p->make_cmd(ic_dev):plexer?string(pc->qst?"O":"M")+"+=go_auto($sep"+IToS(i)+");":"M+=go_const("+pc->value+");";
          t_struct_cmd sc;
          auto res=load_obj_full(sc,cmd);
          if(!res.ok){
            QapDebugMsg("t_struct_field::make_cmd return wrong code:\n"+res.msg);
          }
          cmds.push_back(sc.make_code(i));
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
      t_struct_body::t_cmd_fs_getter v;
      v.Do(*ex.body.fcc.get());
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
    if(!c.out.cppcode.empty()){
      //QapDebugMsg("[2014.02.12 14:14]:\nuse 't_static_visitor' instead of 'usercode inside lexem'.");
    }
    if(!c.out.cppcode.empty()){
      body+=move_block(c.out.cppcode,owner.empty()?"":"  ");
    }
    out+=move_block(body,owner.empty()?"":"  ");
    out=drop_empty_lines(out);
    out+="\n"+string(owner.empty()?"":"  ")+"};";
    return drop_empty_lines(out);
  }
  string get_targets_code_orig(const vector<i_target_item*>&arr,t_ic_dev&ic_dev)
  {
    //auto c=ti.make_code(ic_dev);
    vector<string> out;
    auto&topiarr=ic_dev.top.iarr;
    topiarr=get_iarr(arr);
    auto iarr=topiarr;
    for(int i=0;i<iarr.size();i++){
      auto&ex=iarr[i];
      const t_target_item*pti=nullptr;
      for(auto&p:arr){auto*pt=dynamic_cast<const t_target_item*>(p);if(pt&&pt->def->make_code().name==ex)pti=pt;}
      auto list=get_child_list(arr,ex,ic_dev);
      string tmp=iclass_to_code(ex,list,"","",pti,ic_dev);
      out.push_back(tmp);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*pt=dynamic_cast<const t_target_item*>(ex);
      if(!pt)continue;
      auto name=pt->def->make_code().name;
      if(qap_includes(iarr,name))continue;
      ic_dev.top.carr.push_back(name);
    }
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      auto*pt=dynamic_cast<const t_target_item*>(ex);
      auto*pd=dynamic_cast<const t_target_decl*>(ex);
      auto*pu=dynamic_cast<const t_target_using*>(ex);
      if(pd){
        out.push_back("struct "+pd->name+";");
        continue;
      }
      if(pu){
        ic_dev.add_sep_lex(pu->s,pu->lexer);
        continue;
      }
      if(!pt)continue;
      bool found=qap_includes(iarr,pt->def->make_code().name);
      if(found)continue;
      //auto ex_name=pt->def->make_code().name;bool skip=false;
      //for(auto&p:arr){
      //  auto*pt=dynamic_cast<const t_target_item*>(p);
      //  if(!pt)continue;
      //  if(pt->def->make_code().name==ex_name){skip=true;break;}
      //}
      //if(skip)continue;
      string tmp=class_to_code(*pt,"","",ic_dev);
      out.push_back(tmp);
    }
    return join(out,"\n");
  }
  string get_target_code(const t_target_item&ti,const string&full_owner,t_ic_dev&ic_dev)
  {
    auto name=ti.def->make_code().name;
    auto full_name=(full_owner.empty()?"":full_owner+"::")+name;
    ic_dev.push(name,full_name);
    auto c=ti.make_code(ic_dev);
    vector<string> out;
    auto&topiarr=ic_dev.top.iarr;
    topiarr=get_iarr(c.out.nested);
    auto iarr=topiarr;
    for(int i=0;i<iarr.size();i++){
      auto&ex=iarr[i];
      //const t_target_item*pti=nullptr;
      //{if(name==ex)pti=p;}
      //struct t_visitor:public i_target_item_visitor{
      //  void Do(t_target_sep*p){}
      //  void Do(t_target_item*p){}
      //  void Do(t_target_decl*p){}
      //  void Do(t_target_using*p){}
      //};
      t_target_item*pti=nullptr;
      for(auto&it:c.out.nested)
        if(auto*p=t_target_item::UberCast(it))
          if(auto*pdef=t_struct_def::UberCast(p->def.get())){
            if(pdef->name.value==ex)pti=p;
          }
      //QapAssert(pti);
      auto list=get_child_list(c.out.nested,ex,ic_dev);
      string tmp=iclass_to_code(ex,list,name,full_name,pti,ic_dev);
      out.push_back(tmp);
    }
    for(int i=0;i<c.out.nested.size();i++){
      auto&ex=c.out.nested[i];
      auto*p=t_target_item::UberCast(ex);
      if(!p)continue;
      auto name=p->def->make_code().name;
      if(qap_includes(iarr,name))continue;
      ic_dev.top.carr.push_back(name);
    }
    for(int i=0;i<c.out.nested.size();i++){
      auto&ex=c.out.nested[i];
      auto*p=t_target_item::UberCast(ex);
      auto*pd=t_target_decl::UberCast(ex);
      auto*pu=t_target_using::UberCast(ex);
      if(pd){
        out.push_back("struct "+pd->name+";");
        continue;
      }
      if(pu){
        ic_dev.add_sep_lex(pu->s,pu->lexer);
        continue;
      }
      if(!p)continue;
      auto cname=p->def->make_code().name;
      if(qap_includes(iarr,cname))continue;
      string tmp=class_to_code(*p,name,full_name,ic_dev);
      out.push_back(tmp);
    }
    ic_dev.pop();
    return join(out,"\n");
  }
  static vector<string> get_list_of_types(const vector<i_target_item*>&arr)
  {
    vector<string> out;
    string line;
    for(int i=0;i<arr.size();i++){
      auto*p=dynamic_cast<const t_target_item*>(arr[i]);
      if(!p)continue;
      string item="F("+p->def->make_code().name+")";
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
    vector<i_target_item*> tarr;
    //for(auto&ex:tar.arr)tarr.push_back(&ex);
    for(auto&ex:tar.arr){
      //if(auto*p=dynamic_cast<t_target_item*>(ex.get())){
      //  tarr.push_back(p);
      //}
      tarr.push_back(ex.get());
    }
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
struct t_templ_sys_v05:t_templ_sys_v04,
  t_meta_lexer::i_target_item::i_visitor,
  t_meta_lexer::i_code::i_visitor,
  t_meta_lexer::i_code_with_sep::i_visitor,
  t_meta_lexer::i_type_item::i_visitor,
  t_meta_lexer::i_type_templ::i_visitor,
  t_meta_lexer::i_struct_cmd_xxxx::i_visitor,
  t_meta_lexer::i_struct_field::i_visitor,
  t_meta_lexer::i_struct_cmd_so::i_visitor,
  t_meta_lexer::i_cpp_code::i_visitor,
  t_meta_lexer::i_def::i_visitor
{
  #pragma region typedefs
  #define F(T)typedef t_meta_lexer::T T;
  F(i_code                        )\
  F(t_name_code                   )\
  F(t_num_code                    )\
  F(t_str_seq                     )\
  F(t_sep_str_seq                 )\
  F(t_str_code                    )\
  F(t_char_code                   )\
  F(t_sign_code                   )\
  F(i_code_with_sep               )\
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
  F(i_type_templ                  )\
  F(t_type_scope                  )\
  F(t_type_templ                  )\
  F(i_type_item                   )\
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
  F(i_struct_cmd_xxxx             )\
  F(t_struct_cmd_mode             )\
  F(t_sep_value                   )\
  F(t_attr                        )\
  F(i_struct_field                )\
  F(t_const_field                 )\
  F(t_struct_field_value          )\
  F(t_struct_field                )\
  F(t_sep_struct_field            )\
  F(t_templ_params                )\
  F(t_cmd_params                  )\
  F(t_cmd_param                   )\
  F(t_struct_cmd_anno             )\
  F(i_struct_cmd_so               )\
  F(t_struct_cmd_suffix           )\
  F(t_struct_cmd_optional         )\
  F(t_struct_cmd_opt_v2           )\
  F(t_struct_cmd                  )\
  F(t_sep_struct_cmd              )\
  F(t_struct_cmds                 )\
  F(t_sep_struct_cmds             )\
  F(i_cpp_code                    )\
  F(t_cpp_code_sep                )\
  F(t_cpp_code_main               )\
  F(t_cpp_code                    )\
  F(t_fields_cmds_cppcode         )\
  F(t_struct_body                 )\
  F(i_def                         )\
  F(t_class_def                   )\
  F(t_struct_def                  )\
  F(t_target_sep                  )\
  F(t_target_item                 )\
  F(t_target_decl                 )\
  F(t_target_using                )\
  F(t_target                      )\
  //
  #undef F
  #pragma endregion
  void Do(t_name_code&r)override{}
  void Do(t_num_code&r)override{}
  void Do(t_str_code&r)override{}
  void Do(t_char_code&r)override{}
  void Do(t_sign_code&r)override{}
  void Do(t_soft_brackets_code&r)override{}
  void Do(t_hard_brackets_code&r)override{}
  void Do(t_curly_brackets_code&r)override{}
  void Do(t_name_code_with_sep&r)override{}
  void Do(t_num_code_with_sep&r)override{}
  void Do(t_str_code_with_sep&r)override{}
  void Do(t_char_code_with_sep&r)override{}
  void Do(t_sign_code_with_sep&r)override{}
  void Do(t_soft_brackets_code_with_sep&r)override{}
  void Do(t_hard_brackets_code_with_sep&r)override{}
  void Do(t_curly_brackets_code_with_sep&r)override{}
  void Do(t_type_item_string&r)override{}
  void Do(t_type_item_char&r)override{}
  void Do(t_type_item_number&r)override{}
  void Do(t_type_item_type&r)override{}
  void Do(t_type_templ_angle&r)override{}
  void Do(t_type_templ_soft&r)override{}
  void Do(t_struct_cmd_mode&r)override{}
  void Do(t_struct_cmd_anno&r)override{}
  void Do(t_const_field&r)override{}
  void Do(t_struct_field&r)override{}
  void Do(t_struct_cmd_suffix&r)override{}
  void Do(t_struct_cmd_optional&r)override{}
  void Do(t_struct_cmd_opt_v2&r)override{}
  void Do(t_cpp_code_sep&r)override{}
  void Do(t_cpp_code_main&r)override{}
  void Do(t_class_def&r)override{}
  void Do(t_struct_def&r)override{}
  void Do(t_target_sep&r)override{}
  void Do(t_target_item&r)override{}
  void Do(t_target_decl&r)override{}
  void Do(t_target_using&r)override{}
  void Do(t_target&r){}
  string main(const string&s){
    t_target tar;
    auto r=load_obj_full(tar,s);
    if(!r.ok){QapDebugMsg(r.msg);return {};}
    Do(tar);
  }
};
*/
#if(0)
struct t_class_def_fixer:public t_templ_sys_v04,public t_meta_lexer::i_target_item_visitor,public t_meta_lexer::i_def_visitor{
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
  void Do(t_class_def&r){
    r.sep0.value="";
    r.sep1.value="";
    r.arrow_or_colon=":";
  }
  void Do(t_struct_def&r){}
  void Do(i_target_item&r){r.Use(*this);}
  void Do(t_target_sep&r){}
  void Do(t_target_item&r){r.def->Use(*this);Do(r.body.nested);}
  void Do(t_target_decl&r){}
  void Do(t_target_using&r){}
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
  /*if(bool nedd_class_def_fixer=false){
    t_class_def_fixer cdf;
    string out=cdf.main(file_get_contents(fn));
    file_put_contents(fn,out);
  }*/
  //t_templ_sys_v04 v5;
  //string str2=v5.main(inp);
  string str=v4.main(inp);
  string out="// "+FToS(clock.MS())+" ms\n"+str;
  std::cout<<out;
  gg=2;
}