t_i_expr_impl{

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
  string value;
  {
    M+=go_const("\"");
    O+=go_str<vector<TAutoPtr<i_str_item>>>(value);
    M+=go_const("\"");
  }
}
t_int_expr=>i_expr{
  t_zero=>i_val{
    {
      go_const("0");
    }
  }
  t_num=>i_val{
    char first;
    string num;
    {
      M+=go_any_char(first,gen_dips("19"));
      O+=go_any(num,gen_dips("09"));
    }
  }
  string value;
  {
    go_str<TAutoPtr<i_val>>(value);
  }
}
t_type_expr{
  t_params{
    string type;
    t_int_expr count;
    {
      go_const("{");
      go_str<t_type_expr>(type);
      go_const(",");
      go_auto(count);
      go_const("}");
    }
  }
  t_elem{
    t_name name;
    TAutoPtr<t_params> params;
    {
      M+=go_auto(name);
      O+=go_auto(params);
    }
  }
  t_item{
    t_sep sep0;
    t_sep sep1;
    t_elem body;
    {
      O+=go_auto(sep0);
      M+=go_const("::");
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  t_elem first;
  vector<t_item> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
}
t_char_expr=>i_expr{
  t_char_item body;
  {
    go_auto(body);
  }
}
t_bool_expr=>i_expr{
  string value;
  {
    go_any_str_from_vec(value,split("true,false",","));
  }
}
t_string_expr=>i_expr{
  t_string body;
  {
    go_auto(body);
  }
}
t_real_expr=>i_expr{
  t_frac{
    string arr;
    {
      go_const(".");
      go_any(arr,gen_dips("09"));
    }
  }
  t_sign{
    char sign;
    {
      go_any_char(sign,"-+");
    }
  }
  t_exp{
    char e;
    TAutoPtr<t_sign> sign;
    string arr;
    {
      M+=go_any_char(e,"eE");
      O+=go_auto(sign);
      M+=go_any(arr,gen_dips("09"));
    }
  }
  t_num=>i_val{
    char first;
    string num;
    {
      M+=go_any_char(first,gen_dips("19"));
      O+=go_any(num,gen_dips("09"));
    }
  }
  t_zero=>i_val{
    {
      go_const("0");
    }
  }
  t_impl{
    TAutoPtr<i_val> val;
    TAutoPtr<t_frac> frac;
    TAutoPtr<t_exp> exp;
    {
      M+=go_auto(val);
      M+=go_auto(frac);
      O+=go_auto(exp);
    }
  }
  string value;
  {
    M+=go_str<t_impl>(value);
  }
}
t_var_expr=>i_expr{
  t_elem{
    t_sep sep0;
    t_lev14 expr;
    t_sep sep1;
    {
      M+=go_const("[");
      O+=go_auto(sep0);
      M+=go_auto(expr);
      O+=go_auto(sep1);
      M+=go_const("]");
    }
  }
  t_item{
    t_name name;
    vector<t_elem> arr;
    {
      M+=go_auto(name);
      O+=go_auto(arr);
    }
  }
  t_impl{
    vector<t_item> arr;
    {
      go_vec(arr,".");
    }
  }
  t_impl body;
  {
    go_auto(body);
  }
}
t_block_expr=>i_expr{
  t_lev14 body;
  {
    go_const("(");
    go_auto(body);
    go_const(")");
  }
}
t_call_param{
  t_sep sep0;
  t_lev14 body;
  t_sep sep1;
  {
    O+=go_auto(sep0);
    M+=go_auto(body);
    O+=go_auto(sep1);
  }
}
t_call_params{
  t_sep sep;
  vector<t_call_param> arr;
  {
    M+=go_const("(");
    O+=go_auto(sep);
    O+=go_vec(arr,",");
    M+=go_const(")");
  }
}
t_call_expr=>i_expr{
  t_dot=>i_call{
    t_var_expr::t_impl body;
    {
      go_auto(body);
    }
  }
  t_colon=>i_call{
    vector<t_name> arr;
    {
      go_bin_oper(arr,"::");
    }
  }
  TAutoPtr<i_call> call;
  t_sep sep;
  t_call_params params;
  {
    M+=go_auto(call);
    O+=go_auto(sep);
    M+=go_auto(params);
  }
}
}

t_test20250618_atrr{
  t_foo{{}[::]}
  t_foo foo; [skip]
  t_sep sep; [optimize,inline,"sep",("sep"),[sep],{ sep , sep }]
  {
    go_auto(foo);
    go_auto(sep);
  }
}

t_test20250620_dev{
  t_foo{{}}
  t_bar{
    "more tests"
    "test"
    t_sep sep;
    "another test" /* yes ` ";" */ ;
    t_foo foo?;
    "nope";
  }
  string dev=any(";?'->=<`()/\\+")?;
  t_foo $dev0;
  t_bar $dev1;
  /*{
    go_any(dev,";?'->=<`()/\\+");
    go_auto($dev0);
    go_auto($dev1);
  }*/
}

i_code {
  virtual string make_code()const{QapDebugMsg("no way.");return "";};
}

t_name_code => i_code {
  string value;
  {
    M += go_str<t_name::t_impl>(value);
  }
  string make_code()const{return value;};
}

t_num_code=>i_code{
  t_number body;
  {
    M+=go_auto(body);
  }
  string make_code()const{return body.body;};
}

t_str_seq{
  vector<TAutoPtr<i_str_item>> arr;
  {
    M+=go_const("\"");
    O+=go_auto(arr);
    M+=go_const("\"");
  }
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
  t_sep sep;
  t_str_seq body;
  {
    go_auto(sep);
    go_auto(body);
  }
}

t_str_code=>i_code{
  t_str_seq first;
  vector<t_sep_str_seq> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
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

t_char_code=>i_code{
  TAutoPtr<i_char_item> body;
  {
    go_const("'");
    go_auto(body);
    go_const("'");
  }
  string get_code()const{
    return body->get_code();
  }
  string get_value()const{
    return body->get_value();
  }
  string make_code()const{return "'"+get_code()+"'";}
}

t_sign_code=>i_code{
  t_sign body;
  {
    go_auto(body);
  }
  string make_code()const{return CToS(body.body);}
}

i_code_with_sep{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_name_code_with_sep=>i_code_with_sep{
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

t_num_code_with_sep=>i_code_with_sep{
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

t_str_code_with_sep=>i_code_with_sep{
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

t_char_code_with_sep=>i_code_with_sep{
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

t_sign_code_with_sep=>i_code_with_sep{
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

t_soft_brackets_code_with_sep=>i_code_with_sep{
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

t_hard_brackets_code_with_sep=>i_code_with_sep{
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

t_curly_brackets_code_with_sep=>i_code_with_sep{
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
  {
    go_auto(arr);
  }
  string make_code()const{return vector_make_code(arr);};
}

t_soft_brackets_code=>i_code{
  t_sep sep0;
  TAutoPtr<t_code> body;
  t_sep sep1;
  {
    M+=go_const("(");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const(")");
  }
  string make_code()const{
    string v[3]={
      sep0.make_code(),
      body?body->make_code():"",
      sep1.make_code()
    };
    return "("+v[0]+v[1]+v[2]+")";
  };
}

t_hard_brackets_code=>i_code{
  t_sep sep0;
  TAutoPtr<t_code> body;
  t_sep sep1;
  {
    M+=go_const("[");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const("]");
  }
  string make_code()const{
    string v[3]={
      sep0.make_code(),
      body?body->make_code():"",
      sep1.make_code()
    };
    return "["+v[0]+v[1]+v[2]+"]";
  };
}

t_curly_brackets_code=>i_code{
  t_sep sep0;
  TAutoPtr<t_code> body;
  t_sep sep1;
  {
    M+=go_const("{");
    O+=go_auto(sep0);
    O+=go_auto(body);
    O+=go_auto(sep1);
    M+=go_const("}");
  }
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
  {
    go_const(";");
  }
}

t_value_item{
  TAutoPtr<i_code_with_sep> body;
  {
    go_minor<t_semicolon>(body);
  }
  string make_code()const{
    return body->make_code();
  }
}

t_value{
  t_sep sep;
  string body;
  {
    O+=go_auto(sep);
    M+=go_const("=");
    M+=go_str<vector<t_value_item>>(body);
  }
  string make_code()const
  {
    string out=body;
    //for(int i=0;i<arr.size();i++)out+=arr[i].make_code();
    return out;
  }
}

i_type_templ{
  virtual string make_code()const{QapDebugMsg("no way."); return "";};
}

t_type_scope{
  {
    go_const("::");
  }
  string make_code()const{
    return "::";
  }
}

t_type_templ{
  TAutoPtr<i_type_templ> body;
  {
    go_auto(body);
  }
}

i_type_item{
  virtual string make_code()const{QapDebugMsg("no way.");return "";};
}

t_type_item_string=>i_type_item{
  t_str_item body;
  {
    go_auto(body);
  }
  string make_code()const{
    return body.get_code();
  };
}

t_type_item_char=>i_type_item{
  t_char_item body;
  {
    go_auto(body);
  }
  string make_code()const{
    return body.get_code();
  };
}

t_type_item_number=>i_type_item{
  t_number body;
  {
    go_auto(body);
  }
  string make_code()const{
    return body.body;
  };
}

t_scope_type_item;
t_type_item_type=>i_type_item{
  TAutoPtr<t_type_scope> scope;
  t_name type;
  TAutoPtr<t_type_templ> param;
  vector<t_scope_type_item> arr;
  {
    O+=go_auto(scope);
    M+=go_auto(type);
    O+=go_auto(param);
    O+=go_auto(arr);
  }
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

t_scope_type_item{
  t_type_scope scope;
  t_type_item_type body;
  {
    go_auto(scope);
    go_auto(body);
  }
  string make_code()const{
    string out;
    out+=scope.make_code();
    out+=body.make_code();
    /*if(body){
      auto*p=body.get();
      out+=p->make_code();
    }*/
    return out;
  }
}

t_type_expr2{
  TAutoPtr<t_type_scope> scope;
  t_type_item_type body;
  {
    O+=go_auto(scope);
    M+=go_auto(body);
  }
  string make_code()const{
    string out;
    if(scope)out+=scope->make_code();
    out+=body.make_code();
    return out;
  }
}

t_type_templ_param{
  TAutoPtr<i_type_item> body;
  {
    go_auto(body);
  }
  string make_code()const{
    return body->make_code();
  };
}

t_sep_type_templ_param{
  t_type_templ_param body;
  {
    go_const(",");
    go_auto(body);
  }
  string make_code()const{
    string out;
    out+=",";
    out+=body.make_code();
    return out;
  };
}

t_type_templ_params{
  t_type_templ_param first;
  vector<t_sep_type_templ_param> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
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

t_type_templ_angle=>i_type_templ{
  TAutoPtr<t_type_templ_params> params;
  {
    M+=go_const("<");
    O+=go_auto(params);
    M+=go_const(">");
  }
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

t_type_templ_soft=>i_type_templ{
  TAutoPtr<t_type_templ_params> params;
  {
    M+=go_const("(");
    O+=go_auto(params);
    M+=go_const(")");
  }
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
t_struct_cmd_mode=>i_struct_cmd_xxxx{
  char body;
  t_sep sep0;
  t_sep sep1;
  {
    M+=go_any_char(body,"MO");
    O+=go_auto(sep0);
    M+=go_const("+=");
    O+=go_auto(sep1);
  }
  char get_mode()const{return body;}
}

t_sep_value{
  t_sep sep0;
  t_value_item value;
  t_sep sep1;
  {
    O+=go_auto(sep0);
    M+=go_auto(value);
    O+=go_auto(sep1);
  }
}

t_attr{
  vector<t_sep_value> arr;
  t_sep sep;
  {
    M+=go_const("[");
    O+=go_vec(arr,",");
    O+=go_auto(sep);
    M+=go_const("]");
  }
}
i_struct_field{
  virtual string make_code(int id,t_ic_dev&icdev)const{QapNoWay();return {};}
  virtual string make_cmd(t_ic_dev&icdev)const{QapNoWay();return {};}
}
t_const_field=>i_struct_field{
  string value;
  t_sep sep;
  TAutoPtr<t_semicolon> sc;
  {
    M+=go_str<t_str_item>(value);
    O+=go_auto(sep);
    O+=go_auto(sc);
  }
  string make_code(int id,t_ic_dev&icdev)const{return {};}
  string make_cmd(t_ic_dev&icdev)const{return "M+=go_const("+value+");";}
}
t_struct_field_value{
  "="
  t_sep sep?;
  t_i_expr_impl::i_expr expr;
}
t_struct_field=>i_struct_field{
  t_qst{string s;{go_any(s,"*?");}}
  TAutoPtr<i_struct_cmd_xxxx> mode;
  t_sep sepcm;
  TAutoPtr<t_i_expr_impl::t_type_expr> type;
  t_sep sep0;
  t_name name;
  TAutoPtr<t_struct_field_value> value;
  t_sep sep1;
  TAutoPtr<t_qst> qst;
  t_sep sep2;
  t_sep sep3;
  TAutoPtr<t_attr> attr;
  {
    O+=go_auto(mode);
    O+=go_auto(sepcm);
    M+=go_auto(type);
    M+=go_auto(sep0);
    M+=go_auto(name);
    O+=go_auto(value);
    O+=go_auto(sep1);
    O+=go_auto(qst);
    O+=go_auto(sep2);
    M+=go_const(";");
    O+=go_auto(sep3);
    O+=go_auto(attr);
  }
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
        if(icdev.need_tautoptr(b[0]))t="vector<TAutoPtr<"+b[0]+">>";
      }
    }
    if(icdev.need_tautoptr(t))t="TAutoPtr<"+t+">";
    if(bool need_vec=qst&&qst->s.find('*')!=string::npos)t="vector<"+t+">";
    out.push_back(t);
    out.push_back(name.get());
    out.push_back(mode);
    string value_mem;
    if(value)QapAssert(save_obj(*value.get(),value_mem));
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
    string out=CToS(!qst?(mode?mode->get_mode():'D'):m)+"=";
    string s;if(value)QapAssert(save_obj(*value.get(),s));
    string go=value?s:"auto";
    return out+="go_"+go;
  }
}

t_sep_struct_field{
  t_sep sep;
  i_struct_field body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
  string make_code(int id,t_ic_dev&icdev)const{
    return body->make_code(id,icdev);
  }
}

t_templ_params{
  string body;
  {
    go_const("<");
    go_str<TAutoPtr<t_type_templ_params>>(body);
    go_const(">");
  }
}

t_cmd_param;
t_cmd_params{
  vector<t_cmd_param> arr;
  {
    go_vec(arr,",");
  }
}

t_cmd_param{
  t_impl{
    vector<TAutoPtr<i_expr>> arr;
    {
      go_vec(arr,"+");
    }
  }
  t_expr_call:i_expr{
    t_name func;
    TAutoPtr<t_cmd_params> params;
    {
      go_auto(func);
      go_const("(");
      go_auto(params);
      go_const(")");
    }
  }
  t_expr_str:i_expr{
    string body;
    {
      go_str<t_str_seq>(body);
    }
  }
  t_expr_var:i_expr{
    t_this{
      {
        go_const("this->");
      }
    }
    t_impl{
      TAutoPtr<t_this> self;
      t_name name;
      {
        O+=go_auto(self);
        M+=go_auto(name);
      }
    }
    string body;
    {
      go_str<t_impl>(body);
    }
  }
  string body;
  {
    go_str<t_impl>(body);
  }
}
t_struct_cmd_anno=>i_struct_cmd_xxxx{
  string mode;
  t_sep sep;
  {
    go_any_str_from_vec(mode,split("@mandatory,@optional,@mand,@opti,@man,@opt,@ma,@op,@m,@o,m,o",","));
    go_auto(sep);
  }
  char get_mode()const{return mode.substr(0,2)=="@m"?'M':(mode[0]=='m'?'M':'D');}
}

i_struct_cmd_so{
  virtual char get_mode()const{QapDebugMsg("no way.");return 'D';}
}

t_struct_cmd_suffix=>i_struct_cmd_so{
  char value;
  {
    go_any_char(value,"?!");
  }
  char get_mode()const override{return value=='?'?'O':(value=='!'?'M':'D');}
}

t_struct_cmd_optional=>i_struct_cmd_so{
  string value;
  {
    go_const("[");
    go_any_str_from_vec(value,split("optional,mandatory",","));
    go_const("]");
  }
  char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
}

t_struct_cmd_opt_v2=>i_struct_cmd_so{
  t_sep sep;
  string value;
  {
    go_const(";"); mandatory;
    go_auto(sep) [optional];
    go_any_str_from_vec(value,split("optional,mandatory",","));
  }
  char get_mode()const override{return value=="optional"?'O':("mandatory"==value?'M':'D');}
}

t_struct_cmd{
  TAutoPtr<i_struct_cmd_xxxx> mode;
  t_name func;
  string templ_params;
  t_cmd_params params;
  t_sep sep0;
  TAutoPtr<i_struct_cmd_so> cmdso;
  t_sep sep1;
  {
    O+=go_auto(mode);
    M+=go_auto(func);
    O+=go_str<TAutoPtr<t_templ_params>>(templ_params);
    M+=go_const("(");
    M+=go_auto(params);
    M+=go_const(")");
    O+=go_auto(sep0);
    O+=go_auto(cmdso);
    O+=go_auto(sep1);
    M+=go_const(";");
  }
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
      out=vardecl+"    "+out+"+=dev."+func.get()+"("+param0+","+varname+");\n    if(!ok)return ok;\n";
      return out;
    }
    out="    "+out+"+=dev."+func.get()+templ_params+"("+join(params_code,",")+");\n    if(!ok)return ok;\n";
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
  t_sep sep;
  t_struct_cmd body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
  string make_code(int i){
    return body.make_code(i);
  }
}

t_struct_cmds{
  vector<t_sep_struct_cmd> arr;
  t_sep sep;
  {
    M+=go_const("{");
    O+=go_auto(arr);
    O+=go_auto(sep);
    M+=go_const("}");
  }
}

t_sep_struct_cmds{
  t_sep sep;
  t_struct_cmds body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
}

i_cpp_code{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_cpp_code_sep => i_cpp_code{
  t_sep sep;
  {
    go_auto(sep);
  }
  string make_code()const{
    return sep.make_code();
  }
}

t_cpp_code_main => i_cpp_code{
  TAutoPtr<i_code_with_sep> body;
  {
    go_auto(body);
  }
  string make_code()const{
    string out;
    auto*p=body.get();
    out=p->make_code();
    return out;
  }
}

t_cpp_code{
  t_bayan{{go_const("[::]");}}
  TAutoPtr<t_bayan> bayan;
  vector<TAutoPtr<i_cpp_code>> arr;
  {
    O+=go_auto(bayan);
    O+=go_auto(arr);
  }
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
  string make_code()const{
    string out;
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(ex);
      auto*p=ex.get();
      out+=p->make_code();
    }
    return out;
  }
}
// test

t_struct_body{
  vector<t_target_item> nested;
  t_sep sep0;
  vector<t_sep_struct_field> arr;
  TAutoPtr<t_sep_struct_cmds> cmds;
  t_sep sep1;
  TAutoPtr<t_cpp_code> cppcode;
  {
    M+=go_const("{");
    O+=go_auto(nested);
    O+=go_auto(sep0);
    O+=go_auto(arr);
    O+=go_auto(cmds);
    O+=go_auto(sep1);
    O+=go_auto(cppcode);
    M+=go_const("}");
  }
  struct t_target_item_out;
  struct t_out{
    vector<const t_target_item*> nested;
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
  t_out make_code(t_ic_dev&icdev)const{
    t_out out;
    {
      auto&arr=nested;
      out.nested.resize(arr.size());
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        auto&to=out.nested[i];
        to=&ex;
      }
    }
    {
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i,icdev));
      }
      out.provars=join(tmp,"");
    }
    if(cmds)
    {
      auto*pCmds=cmds.get();
      auto&arr=pCmds->body.arr;
      vector<string> tmp;
      for(int i=0;i<arr.size();i++){
        tmp.push_back(arr[i].make_code(i));
      }
      out.procmds=join(tmp,"");
    }
    string sep=sep0.value.empty()?sep1.value:sep0.value;
    out.cppcode=cppcode?sep+cppcode->make_code()+"\n":"";
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

t_class_def => i_def{
  t_name name;
  t_sep sep0;
  string arrow_or_colon;
  t_sep sep1;
  t_name parent;
  {
    M+=go_auto(name);
    O+=go_auto(sep0);
    M+=go_any_str_from_vec(arrow_or_colon,split("=>,:",","));
    O+=go_auto(sep1);
    M+=go_auto(parent);
  }
  t_out make_code(){
    t_out out;
    out.name=name.get();
    out.parent=parent.get();
    return out;
  }
}

t_struct_def => i_def{
  t_name name;
  {
    M+=go_auto(name);
  }
  t_out make_code(){
    t_out out;
    out.name=name.get();
    return out;
  }
}

t_target_item=>i_target_item{
  t_sep sep0;
  TAutoPtr<i_def> def;
  t_sep sep1;
  t_struct_body body;
  {
    O+=go_auto(sep0);
    M+=go_auto(def);
    O+=go_auto(sep1);
    M+=go_auto(body);
  }
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

t_target_decl=>i_target_item{
  t_sep sep0;
  string name;
  t_sep sep1;
  {
    O+=go_auto(sep0);
    M+=go_str<t_name>(name);
    O+=go_auto(sep1);
    M+=go_const(";");
  }
}

t_target{
  vector<TAutoPtr<i_target_item>> arr;
  {
    M+=go_auto(arr);
  }
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