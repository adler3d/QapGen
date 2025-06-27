t_cppcore{

t_lev03{
  string oper;
  TAutoPtr<i_expr> expr;
  {
    O+=go_any_str_from_vec(oper,split("+,-,!,~",","));
    M+=go_auto(expr);
  }
}
t_lev05{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("*,/,%",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev03 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev03 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev06{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("+,-",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev05 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev05 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev07{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("<<,>>",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev06 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev06 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev08{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("<,<=,>,>=",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev07 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev07 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev09{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("==,!=",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev08 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev08 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev10{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("&",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev09 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev09 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev11{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("^",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev10 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev10 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev12{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("|",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev11 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev11 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev13{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("&&",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev12 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev12 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_lev14{
  t_oper{
    string value;
    {
      go_any_str_from_vec(value,split("||",","));
    }
  }
  t_item{
    t_oper oper;
    t_lev13 expr;
    {
      go_auto(oper);
      go_auto(expr);
    }
  }
  t_lev13 expr;
  vector<t_item> arr;
  {
    M+=go_auto(expr);
    O+=go_auto(arr);
  }
}
t_string{
  "\""
  string value=str<vector<TAutoPtr<i_str_item>>>()?;
  "\""
}

t_int_expr:i_expr{
  t_zero:i_val{"0"}
  t_num:i_val{
    char first=any_char(gen_dips("19"));
    string num=any(gen_dips("09"))?;
  }
  string value=str<TAutoPtr<i_val>>();
}

t_type_expr{
  t_params{
    "{"
    string type=str<t_type_expr>();
    ","
    t_int_expr count;
    "}"
  }
  t_elem{
    t_name name;
    TAutoPtr<t_params> params?;
  }
  t_item{
    t_sep sep0?;
    "::"
    t_sep sep1?;
    t_elem body;
  }
  t_elem first;
  vector<t_item> arr?;
}

t_char_expr:i_expr{
  t_char_item body;
}

t_bool_expr:i_expr{
  string value=any_str_from_vec(split("true,false",","));
}

t_string_expr:i_expr{
  t_string body;
}

t_real_expr:i_expr{
  t_frac{
    "."
    string arr=any(gen_dips("09"));
  }
  t_sign{
    char sign=any_char("-+");
  }
  t_exp{
    char e=any_char("eE");
    TAutoPtr<t_sign> sign?;
    string arr=any(gen_dips("09"));
  }
  t_num:i_val{
    char first=any_char(gen_dips("19"));
    string num=any(gen_dips("09"))?;
  }
  t_zero:i_val{"0"}
  t_impl{
    TAutoPtr<i_val> val;
    TAutoPtr<t_frac> frac;
    TAutoPtr<t_exp> exp?;
  }
  string value=str<t_impl>();
}

t_var_expr:i_expr{
  t_sb_expr{
    "["
    t_sep sep0?;
    t_lev14 expr;
    t_sep sep1?;
    "]"
  }
  t_dd_part:i_part{
    t_elem{
      t_sep sep0?;
      "::"
      t_sep sep1?;
      t_name name;
    }
    vector<t_elem> arr;
  }
  t_template_part:i_part{
    t_sep sepB?;
    "<"
    t_sep sep0?;
    TAutoPtr<i_expr> expr;
    t_sep sep1?;
    ">"
    TAutoPtr<t_dd_part> ddp?;
  }
  t_arr{
    t_sep sep?;
    vector<t_sb_expr> arr;
  }
  t_item{
    "."
    t_sep sep0?;
    t_name name;
    t_arr arr?;
  }
  t_name name;
  TAutoPtr<i_part> tp?;
  TAutoPtr<t_arr> arr?;
  vector<t_item> items?;
}

t_block_expr:i_expr{
  "("
  t_lev14 body;
  ")"
}

t_call_param{
  t_sep sep0?;
  t_lev14 body;
  t_sep sep1?;
}

t_call_params{
  "("
  t_sep sep?;
  vector<t_call_param> arr=vec(",")?;
  ")"
}

t_call_expr:i_expr{
  t_var_expr call;
  t_sep sep?;
  t_call_params params;
}

}

using " " as t_sep;

t_test20250618_atrr{
  t_foo{{}[::]}
  t_foo foo; [skip]
  t_sep sep; [optimize,"sep",("sep"),sep[x]]
  {
    go_auto(foo);
    go_auto(sep);
  }
}

//t_test20250620_dev{
//  t_foo{{}}
//  t_bar{
//    "more tests"
//    "test"
//    t_sep sep;
//    "another test" /* yes ` ";" */ ;
//    t_foo foo?;
//    "nope";
//  }
//  string dev=any(";?'->=<`()/\\+")?;
//  t_foo $dev0;
//  t_bar $dev1;
//  /*{
//    go_any(dev,";?'->=<`()/\\+");
//    go_auto($dev0);
//    go_auto($dev1);
//  }*/
//}
t_meta_lexer{

i_code {
  virtual string make_code()const{QapDebugMsg("no way.");return "";};
}

t_name_code:i_code{
  string value=str<t_name::t_impl>();
  string make_code()const{return value;}
}

t_num_code:i_code{
  t_number body;
  string make_code()const{return body.body;}
}

t_str_seq{
  "\""
  vector<TAutoPtr<i_str_item>> arr?;
  "\""
  string get_code()const{
    string out;
    for(int i=0;i<arr.size();i++){
      out+=arr[i]->get_code();
    }
    return out;
  }
  string get_value()const{
    string out;
    for(int i=0;i<arr.size();i++){
      out+=arr[i]->get_value();
    }
    return out;
  }
  string make_code()const{return "\""+get_code()+"\"";}
}

t_sep_str_seq{
  " "
  t_str_seq body;
}

t_str_code:i_code{
  t_str_seq first;
  vector<t_sep_str_seq> arr?;
  string make_code()const{
    string out=first.get_code();
    if(!arr.empty())
    {
      for(int i=0;i<arr.size();i++)out+=arr[i].body.get_code();
      int gg=1;
    }
    return "\""+out+"\"";
  }
}

t_char_code:i_code{
  "'"
  TAutoPtr<i_char_item> body;
  "'"
  string get_code()const{return body->get_code();}
  string get_value()const{return body->get_value();}
  string make_code()const{return "'"+get_code()+"'";}
}

t_sign_code:i_code{
  t_sign body;
  string make_code()const{return CToS(body.body);}
}

i_code_with_sep{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_name_code_with_sep:i_code_with_sep{
  t_name_code body;
  t_sep sep;
  {
    M+=go_auto(body);
    O+=go_auto(sep);
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
}

t_num_code_with_sep:i_code_with_sep{
  t_num_code body;
  t_sep sep;
  {
    M+=go_auto(body);
    O+=go_auto(sep);
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
}

t_str_code_with_sep:i_code_with_sep{
  t_str_code body;
  t_sep sep;
  {
    M+=go_auto(body);
    O+=go_auto(sep);
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
}

t_char_code_with_sep:i_code_with_sep{
  t_char_code body;
  t_sep sep;
  {
    M+=go_auto(body);
    O+=go_auto(sep);
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
}

t_sign_code_with_sep:i_code_with_sep{
  t_sign_code body;
  t_sep sep;
  {
    M+=go_auto(body);
    O+=go_auto(sep);
  }
  string make_code()const{
    return body.make_code()+sep.make_code();
  }
}

t_soft_brackets_code_with_sep:i_code_with_sep{
  t_sep sep0;
  vector<TAutoPtr<i_code_with_sep>> body;
  t_sep sep1;
  {
    M+=go_const("(");
    O+=go_auto(sep0);
    O+=go_auto(body);
    M+=go_const(")");
    O+=go_auto(sep1);
  }
  string make_code()const{
    string v[]={
      sep0.make_code(),
      vector_make_code(body),
      sep1.make_code(),
    };
    return "("+v[0]+v[1]+")"+v[2];
  }
}

t_hard_brackets_code_with_sep:i_code_with_sep{
  t_sep sep0;
  vector<TAutoPtr<i_code_with_sep>> body;
  t_sep sep1;
  {
    M+=go_const("[");
    O+=go_auto(sep0);
    O+=go_auto(body);
    M+=go_const("]");
    O+=go_auto(sep1);
  }
  string make_code()const{
    string v[]={
      sep0.make_code(),
      vector_make_code(body),
      sep1.make_code(),
    };
    return "["+v[0]+v[1]+"]"+v[2];
  }
}

t_curly_brackets_code_with_sep:i_code_with_sep{
  t_sep sep0;
  vector<TAutoPtr<i_code_with_sep>> body;
  t_sep sep1;
  {
    M+=go_const("{");
    O+=go_auto(sep0);
    O+=go_auto(body);
    M+=go_const("}");
    O+=go_auto(sep1);
  }
  string make_code()const{
    string v[]={
      sep0.make_code(),
      vector_make_code(body),
      sep1.make_code(),
    };
    return "{"+v[0]+v[1]+"}"+v[2];
  }
}

//real_source_data:
/*
t_name_code
t_num_code
t_str_code
t_char_code
t_sign_code
t_soft_brackets_code
t_hard_brackets_code
t_curly_brackets_code
@@@public:
  string make_code()const{return body.make_code()+sep.make_code();}
*/

//real_source_code:
/*
var mk=POST['data'].split("@@@")[1];
var gen=function(lex,mk){
  return lex+"_with_sep=>i_code_with_sep{"+lex+" body;t_sep sep;{M+=go_auto(body);O+=go_auto(sep);}"+mk+"\n}";
}
var out=[];
var arr=POST['data'].split("\n@@@")[0].split("\r").join("").split("\n");
for(var i=0;i<arr.length;i++){
  out.push(gen(arr[i],mk));
}
return out.join("\n");
*/
t_code{
  vector<TAutoPtr<i_code>> arr;
  string make_code()const{return vector_make_code(arr);};
}

t_soft_brackets_code:i_code{
  "("
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  ")"
  string make_code()const{
    string v[3]={
      sep0.make_code(),
      body?body->make_code():"",
      sep1.make_code()
    };
    return "("+v[0]+v[1]+v[2]+")";
  };
}

t_hard_brackets_code:i_code{
  "["
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  "]"
  string make_code()const{
    string v[3]={
      sep0.make_code(),
      body?body->make_code():"",
      sep1.make_code()
    };
    return "["+v[0]+v[1]+v[2]+"]";
  };
}

t_curly_brackets_code:i_code{
  "{"
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  "}"
  string make_code()const{
    string v[3]={
      sep0.make_code(),
      body?body->make_code():"",
      sep1.make_code()
    };
    return "{"+v[0]+v[1]+v[2]+"}";
  };
}

t_semicolon{
  ";"
}

t_value_item{
  string body=str<TAutoPtr<t_cppcore::i_expr>>();
  string make_code()const{
    return body;
  }
}

t_value{
  " "?
  "="
  string body=str<TAutoPtr<t_cppcore::i_expr>>();
  string make_code()const{
    string out=body;
    //for(int i=0;i<arr.size();i++)out+=arr[i].make_code();
    return out;
  }
}

i_type_templ{
  virtual string make_code()const{QapDebugMsg("no way."); return "";};
}

t_type_scope{
  "::"
  string make_code()const{
    return "::";
  }
}

t_type_templ{
  TAutoPtr<i_type_templ> body;
}

i_type_item{
  virtual string make_code()const{QapDebugMsg("no way.");return "";};
}

t_type_item_string:i_type_item{
  t_str_item body;
  string make_code()const{
    return body.get_code();
  };
}

t_type_item_char:i_type_item{
  t_char_item body;
  string make_code()const{
    return body.get_code();
  };
}

t_type_item_number:i_type_item{
  t_number body;
  string make_code()const{
    return body.body;
  };
}

t_type_item_type;

t_scope_type_item{
  t_type_scope scope;
  TAutoPtr<t_type_item_type> body;
  template<class TYPE>
  static string weak_body_make_code(const TAutoPtr<TYPE>&ref){
    return ref->make_code();
  }
  string make_code()const{
    string out;
    out+=scope.make_code();
    out+=weak_body_make_code(body);
    return out;
  }
}

t_type_item_type:i_type_item {
  TAutoPtr<t_type_scope> scope?;
  t_name type;
  TAutoPtr<t_type_templ> param?;
  vector<t_scope_type_item> arr?;

  template<class TYPE>
  static string weak_arr_make_code(const vector<TYPE>&arr){
    string out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out+=ex.make_code();
    }
    return out;
  }
  string make_code()const{
    string out;
    if(scope)out+=scope->make_code();
    out+=type.get();
    if(param){
      auto*p=param.get();
      auto*pParam=p->body.get();
      QapAssert(pParam);
      out+=pParam->make_code();
    }
    out+=weak_arr_make_code(this->arr);
    return out;
  }
}

t_type_expr2{
  TAutoPtr<t_type_scope> scope?;
  t_type_item_type body;
  string make_code()const{
    string out;
    if(scope)out+=scope->make_code();
    out+=body.make_code();
    return out;
  }
}

t_type_templ_param{
  TAutoPtr<i_type_item> body;
  string make_code()const{
    return body->make_code();
  }
}

t_sep_type_templ_param{
  ","
  t_type_templ_param body;
  string make_code()const{
    string out;
    out+=",";
    out+=body.make_code();
    return out;
  }
}

t_type_templ_params{
  t_type_templ_param first;
  vector<t_sep_type_templ_param> arr?;
  string make_code()const{
    string out;
    out+=first.make_code();
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      out+=ex.make_code();
    }
    return out;
  };
}

t_type_templ_angle:i_type_templ{
  "<"
  TAutoPtr<t_type_templ_params> params?;
  ">"
  string make_code()const{
    string out;
    out+="<";
    if(params){
      auto*p=params.get();
      out+=p->make_code();
    }
    out+=">";
    return out;
  };
}

t_type_templ_soft:i_type_templ{
  "("
  TAutoPtr<t_type_templ_params> params?;
  ")"
  string make_code()const{
    string out;
    out+="(";
    if(params){
      auto*p=params.get();
      out+=p->make_code();
    }
    out+=")";
    return out;
  };
}

i_struct_cmd_xxxx{
  virtual char get_mode()const{QapDebugMsg("no way.");return 'D';}
}

t_struct_cmd_mode:i_struct_cmd_xxxx{
  char body=any_char("DMO");
  " "?
  "+="
  " "?
  char get_mode()const{return body;}
}

t_sep_value{
  " "?
  t_value_item value;
  " "?
}

t_attr{
  "["
  vector<t_sep_value> arr=vec(",")?;
  " "?
  "]"
}
i_struct_field{
  virtual string make_code(int id,t_ic_dev&icdev)const{QapNoWay();return {};}
  virtual string make_cmd(t_ic_dev&icdev)const{QapNoWay();return {};}
}
t_const_field:i_struct_field{
  t_qst{"?"}
  t_c_item:i_sc_item{t_char_item body;}
  t_s_item:i_sc_item{t_str_item body;}
  string value=str<TAutoPtr<i_sc_item>>();
  " "?
  TAutoPtr<t_qst> qst?;
  " "?
  TAutoPtr<t_semicolon> sc?;
  string make_code(int id,t_ic_dev&icdev)const{
    const string*plexer=icdev.get_sep_lex(value);
    if(!plexer)return {};
    return "ADDVAR("+*plexer+",$sep"+IToS(id)+",DEF,$,$)\\\n";
  }
  string make_cmd(t_ic_dev&icdev)const{return "M+=go_const("+value+");";}
}

t_struct_field_value {
  " "?
  "=";
  " "?
  TAutoPtr<t_cppcore::t_call_expr> expr;
}
t_struct_field:i_struct_field{
  t_qst{string s;{go_any(s,"*?");}}
  TAutoPtr<i_struct_cmd_xxxx> mode?;
  " "?
  TAutoPtr<t_cppcore::i_expr> type;
  " "
  t_name name;
  TAutoPtr<t_struct_field_value> value?;
  " "?
  TAutoPtr<t_qst> qst?;
  " "?
  ";"
  " "?
  TAutoPtr<t_attr> attr?;
  string make_code(int id,t_ic_dev&icdev)const{
    vector<string> out;
    string mode="DEF";//value?"SET":"DEF";
    //out.push_back(IToS(id));
    string type_mem;
    QapAssert(type&&save_obj(*type.get(),type_mem));
    auto t=type_mem;
    if(bool vec_algo=true){
      auto a=split(t,"<");
      if(a.size()==2&&a[0]=="vector"){
        auto b=split(a[1],">");
        QapAssert(b.size()==2);
        QapAssert(b[1]=="");
        if(icdev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>"+b[1];
      }
    }
    if(icdev.need_tautoptr(t))t="TAutoPtr<"+t+">";
    if(bool need_vec=qst&&qst->s.find('*')!=string::npos)t="vector<"+t+">";
    out.push_back(t);
    out.push_back(name.value);
    out.push_back(mode);
    string value_mem="$";
    //if(value)QapAssert(save_obj(*value.get(),value_mem));
    out.push_back(!value?"$":value_mem);
    string s;
    //if(attr){
    //  bool ok=save_obj(*attr.get(),s);
    //  QapAssert(ok);
    //}
    return "ADDVAR("+join(out,",")+","+(s.empty()?"$":s)+")\\\n";
  }
  string make_cmd(t_ic_dev&icdev)const{
    char m=qst?(qst->s.find('?')==string::npos?'M':'O'):'D';
    QapAssert(qst||mode?bool(qst)!=bool(mode):true);
    string out=CToS(!qst?(mode?mode->get_mode():'D'):m)+"+=";
    string call,params;
    if(value){
      auto*pce=value->expr.get();//t_cppcore::t_call_expr::UberCast(value->expr.get());
      QapAssert(pce);
      QapAssert(save_obj(pce->call,call));
      QapAssert(pce->params.arr.empty()||save_obj(pce->params.arr,params));
    }
    string go=value?call+"("+name.value+string(params.size()?","+params:"")+");":"auto("+name.value+");";
    return out+="go_"+go;
  }
}

t_sep_struct_field{
  " "?
  i_struct_field body;
  string make_code(int id,t_ic_dev&icdev)const{
    return body->make_code(id,icdev);
  }
}

t_templ_params{
  "<"
  string body=str<TAutoPtr<t_type_templ_params>>();
  ">"
}

t_cmd_param;
t_cmd_params{
  vector<t_cmd_param> arr=vec(",");
}

t_cmd_param{
  t_impl{
    vector<TAutoPtr<i_cmd_param_expr>> arr=vec("+");
  }
  t_expr_call:i_cmd_param_expr{
    t_name func;
    "("
    TAutoPtr<t_cmd_params> params;
    ")"
  }
  t_expr_str:i_cmd_param_expr{
    string body=str<t_str_seq>();
  }
  t_expr_var:i_cmd_param_expr{
    t_this{"this->"}
    t_impl{
      TAutoPtr<t_this> self?;
      t_name name;
    }
    string body=str<t_impl>();
  }
  string body=str<t_impl>();
}
t_struct_cmd_anno:i_struct_cmd_xxxx{
  string mode=any_str_from_vec(split("@mandatory,@optional,@mand,@opti,@man,@opt,@ma,@op,@m,@o,m,o",","));
  " ";
  char get_mode()const{return mode.substr(0,2)=="@m"?'M':(mode[0]=='m'?'M':'D');}
}

i_struct_cmd_so{
  virtual char get_mode()const{QapDebugMsg("no way.");return 'D';}
}

t_struct_cmd_suffix:i_struct_cmd_so{
  char value=any_char("?!");
  char get_mode()const override{return value=='?'?'O':(value=='!'?'M':'D');}
}

t_struct_cmd_optional:i_struct_cmd_so{
  "["
  string value=any_str_from_vec(split("optional,mandatory",","));
  "]"
  char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
}

t_struct_cmd_opt_v2:i_struct_cmd_so{
  ";"
  " "?
  string value=any_str_from_vec(split("optional,mandatory",","));
  char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
}

t_struct_cmd{
  TAutoPtr<i_struct_cmd_xxxx> mode?;
  t_name func;
  " "?
  string templ_params=str<TAutoPtr<t_templ_params>>()?;
  "("
  t_cmd_params params;
  ")"
  " "?
  TAutoPtr<i_struct_cmd_so> cmdso?;
  " "?
  ";"
  static bool find(const string&func){
    static const vector<string> arr=split("go_any_str_from_vec|go_any_arr_char|go_any|go_any_char","|");
    for(int i=0;i<arr.size();i++)if(arr[i]==func)return true;
    return false;
  }
  string make_code(int i){
    if(mode&&t_struct_cmd_anno::UberCast(mode.get())){
      int gg=1;
    }
    char m=cmdso?cmdso->get_mode():'D';
    QapAssert(cmdso||mode?bool(cmdso)!=bool(mode):true);
    string out=CToS(mode?mode->get_mode():m);
    vector<string> params_code;
    {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
    auto check=out!="O"?"    if(!ok)return ok;\n":"";
    out=out!="O"?"ok=":"";
    string func_name=func.get();
    bool smart_func=find(func_name);
    if(smart_func)
    {
      QapAssert(params.arr.size()==2);
      const auto&param0=params.arr[0].body;
       const auto&param1=params.arr[1].body;
      auto get_param1=[&func_name,&param1]()->string{
        if(func_name=="go_any_str_from_vec")return "QapStrFinder::fromArr("+param1+")";
        return "CharMask::fromStr("+param1+")";
      };
      string varname="g_static_var_"+IToS(i);
      string vardecl="    static const auto "+varname+"="+get_param1()+";\n";
      out=vardecl+"    "+out+"dev."+func.get()+"("+param0+","+varname+");\n"+check;
      return out;
    }
    out="    "+out+"dev."+func.get()+templ_params+"("+join(params_code,",")+");\n"+check;
    return out;
  }
  string make_code_gp(){
    char m=cmdso?cmdso->get_mode():'D';
    QapAssert(cmdso||mode?bool(cmdso)!=bool(mode):true);
    string out=CToS(mode?mode->get_mode():m);
    vector<string> params_code;
    {auto&arr=params.arr;for(int i=0;i<arr.size();i++)params_code.push_back(arr[i].body);}
    out="    "+out+"+=dev."+func.get()+templ_params+"("+join(params_code,",")+");\n    if(!ok)return ok;\n";
    return out;
  }
}

t_sep_struct_cmd{
  " "?
  t_struct_cmd body;
  string make_code(int i){
    return body.make_code(i);
  }
}

t_struct_cmds{
  "{"
  vector<t_sep_struct_cmd> arr?;
  " "?
  "}"
}

t_sep_struct_cmds{
  " "?
  t_struct_cmds body;
}

i_cpp_code{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_cpp_code_sep:i_cpp_code{
  t_sep sep;
  string make_code()const{
    return sep.make_code();
  }
}

t_cpp_code_main:i_cpp_code{
  TAutoPtr<i_code_with_sep> body;
  string make_code()const{
    string out;
    auto*p=body.get();
    out=p->make_code();
    return out;
  }
}

t_cpp_code{
  t_bayan{"[::]"}
  t_fields:i_major{t_sep_struct_field f;}
  t_cmds:i_major{t_sep_struct_cmds c;}
  t_atr:i_major{TAutoPtr<t_attr> attr;}
  t_eater{vector<TAutoPtr<i_cpp_code>> arr;}
  t_with_bayan:i_bayan{
    t_bayan bayan;
    t_eater eater?;
  }
  t_without_bayan:i_bayan{
    t_eater eater=minor<TAutoPtr<i_major>>();
  }
  t_a:i_strong_bayan{
    t_with_bayan wb;
  }
  t_b:i_strong_bayan{
    t_eater e=minor<t_with_bayan>();
  }
  TAutoPtr<i_bayan> bayan;
  static string align(const string&source){
    auto arr=split(source,"\n");
    if(arr.empty())return source;
    auto get=[](const string&line)->int{
      if(line=="public:")return -2;
      for(int i=0;i<line.size();i++)if(line[i]!=' ')return i;
      return -1;
    };
    int count=-1;
    for(int i=0;i<arr.size();i++){
      auto m=get(arr[i]);
      if(m<0)continue;
      if(count<0){count=m;continue;}
      count=std::min<int>(m,count);
    }
    if(count<0)return source;
    vector<string> out;
    for(int i=0;i<arr.size();i++){
      auto m=get(arr[i]);
      auto s=m<0?arr[i]:"  "+arr[i].substr(count);
      if(m==-1)s.clear();
      out.push_back(s);
    }
    return join(out,"\n");
  }
  //struct t_visitor:/*i_cpp_code::i_visitor,i_major::i_visitor,*/i_bayan::i_visitor{
  //  const t_cpp_code&c;
  //  t_visitor(const t_cpp_code&c):c(c){}
  //  void Do(t_cpp_code*p){}
  //  void Do(t_fields*p){}
  //  void Do(t_cmds*p){}
  //  void Do(t_eater*p){}
  //  void Do(t_with_bayan*p){}
  //  void Do(t_without_bayan*p){p->wb.bayan}
  //};
  string make_code()const{
    string out;
    //t_visitor v{*this};
    //bayan->Use(v);
    //for(int i=0;i<arr.size();i++){
    //  auto&ex=arr[i];
    //  QapAssert(ex);
    //  auto*p=ex.get();
    //  out+=p->make_code();
    //}
    if(bayan)save_obj(*bayan.get(),out);
    return out;
  }
}
// test

t_fields_cmds_cppcode{
  t_true_fcc{
    vector<t_sep_struct_field> arr;
    TAutoPtr<t_sep_struct_cmds> cmds?;
    TAutoPtr<t_cpp_code::i_strong_bayan> cppcode?;
  }
  t_cmds{
    TAutoPtr<t_sep_struct_cmds> cmds;
    TAutoPtr<t_cpp_code::i_strong_bayan> cppcode?;
  }
  t_cppcode{
    TAutoPtr<t_cpp_code> cppcode;
  }
  TAutoPtr<t_true_fcc> tfcc?;
  TAutoPtr<t_cmds> cmds?;
  TAutoPtr<t_cppcode> c?;
}

t_struct_body{
  "{"
  vector<TAutoPtr<i_target_item>> nested?;
  t_sep sep0?;
  TAutoPtr<t_fields_cmds_cppcode> fcc;
  t_sep sep1?;
  "}"
  struct t_target_item_out;
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
  //template<int>
  //static t_target_item_out weak_make_code(const t_target_item&ref,t_ic_dev&icdev);
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
  struct t_cmd_fs_getter:t_visitor{
    using t_visitor::Do;
    void Do(t_cppcode&r)override{}
  };
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
    {
      auto&arr=nested;
      out.nested.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&to=out.nested[i];
        to=ex.get();
      }
    }
    if(!fcc)return out;
    t_visitor v;
    v.Do(*fcc.get());
    if(v.pfs){
      auto&arr=*v.pfs;
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i,icdev));
      }
      out.provars=join(tmp,"");
    }
    if(v.pcmds)
    {
      auto&arr=v.pcmds->body.arr;
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i));
      }
      out.procmds=join(tmp,"");
    }
    string sep=sep0.value.empty()?sep1.value:sep0.value;
    out.cppcode=v.c.size()?sep+v.c+"\n":"";
    return out;
  }
}
i_def{
  struct t_out{
    string name;
    string parent;
  };
  virtual t_out make_code(){QapDebugMsg("no way.");return *(t_out*)nullptr;}
}

t_class_def:i_def{
  t_name name;
  t_sep sep0?;
  string arrow_or_colon=any_str_from_vec(split("=>,:",","));
  t_sep sep1?;
  t_name parent;
  t_out make_code(){
    t_out out;
    out.name=name.get();
    out.parent=parent.get();
    return out;
  }
}

t_struct_def:i_def{
  t_name name;
  t_out make_code(){
    t_out out;
    out.name=name.get();
    return out;
  }
}
t_target_sep:i_target_item{" "}
t_target_item:i_target_item{
  t_sep sep0?;
  TAutoPtr<i_def> def;
  t_sep sep1?;
  t_struct_body body;
  typedef t_struct_body::t_target_item_out t_out;
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
    out.sep=sep0.value;
    {
      auto tmp=def->make_code();
      out.name=tmp.name;
      out.parent=tmp.parent;
    }
    auto tmp=body.make_code(icdev);
    out.out=std::move(tmp);
    return out;
  }
}

t_target_decl:i_target_item{
  " "?
  string name=str<t_name>();
  " "?
  ";"
}

t_target_using:i_target_item{
  t_str_ap:i_qa{
    "'"
    string body=str<TAutoPtr<i_char_item>>();
    "'"
  }
  t_str_qu:i_qa{
    "\""
    string body=str<vector<TAutoPtr<i_str_item>>>();
    "\""
  }
  " "?
  "using"
  " "
  string s=str<TAutoPtr<i_qa>>();
  " "
  "as"
  " "
  string lexer=str<t_name>();
  " "?
  ";"
}

t_target{
  vector<TAutoPtr<i_target_item>> arr;
  vector<t_target_item::t_out> make_code(t_ic_dev&icdev){
    vector<t_target_item::t_out> out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(auto*p=dynamic_cast<t_target_item*>(ex.get())){
        out.push_back(p->make_code(icdev));
      }
    }
    return out;
  }
}
}
//