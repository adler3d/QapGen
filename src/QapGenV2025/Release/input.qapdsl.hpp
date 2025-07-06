t_parent_fullname_reslove_algo_test_20250701{
  //t_parent_holder{t_foo:i_base{}}
  t_other{
    //t_bar:t_parent_holder::i_base{}
  }
}

t_using_test_20250628{
  t_sep{" "}
  using " " as t_sep;
  t_foo;
  t_foo{
    t_bar{t_baz{}}
    t_bar b;
    " "
    t_bar c?;
    t_bar d?;
    " "?
  }
  t_foo foo;
}

t_number{
  string body=any(gen_dips("09"));
}

typedef array<char,2> ARRAY2char;
typedef array<char,4> ARRAY4char;

t_str_item_raw=>i_str_item{
  string body=any(dip_inv("\"\\\n"));
}

t_str_item_hex=>i_str_item{
  "\\x"
  ARRAY2char body=any_arr_char(gen_dips("09afAF"));
}

t_str_item_num=>i_str_item{
  "\\u"
  ARRAY2char body=any_arr_char(gen_dips("09"));
}
t_str_item_fix=>i_str_item{
  "\\"
  char body=any_char("tfbrn\\\"\'"+gen_dips("07"));
}

t_str_item{
  t_impl{
    "\""
    vector<TAutoPtr<i_str_item>> arr;
    "\""
  }
  string value=str<t_impl>();
}

t_char_item_raw=>i_char_item{
  string body=any(dip_inv("'\\\n"));
}

t_char_item_hex=>i_char_item{
  "\\x"
  ARRAY2char body=any_arr_char(gen_dips("09afAF"));
}

t_char_item_num=>i_char_item{
  "\\u"
  ARRAY4char body=any_arr_char(gen_dips("09"));
}

t_char_item_fix=>i_char_item{
  "\\"
  char body=any_char("tfbrn\\\"\'"+gen_dips("07"));
}

t_char_item{
  t_impl{
    "'"
    TAutoPtr<i_char_item> body;
    "'"
  }
  string value=str<t_impl>();
}

t_sep_seq:i_sep{
  string body=any(" \t\r\n");
}

t_c_comment:i_sep{
  "/*"
  string body=end("*/");
}

t_cpp_comment=>i_sep{
  "//"
  string body=any(dip_inv("\n"))?;
}

t_sep{
  t_impl{
    vector<TAutoPtr<i_sep>> arr;
  }
  string value=str<t_impl>();
}

t_name{
  t_keyword{
    string value=any_str_from_vec(split("new,delete,default,consteval,false,true,nullptr,this,struct,class,for,if,while,do,const,constexpr,else,operator,auto,continue,break,return,goto,virtual,override,public,private,protected,friend,template,typedef,using,namespace,decltype",","));
  }
  t_impl{
    char A=any_char(gen_dips("azAZ")+"_$@");
    string B=any(gen_dips("azAZ09")+"_$@")?;
  }
  t_impl_ex{
    t_impl impl=minor<t_keyword>();
  }
  string value=str<t_impl_ex>();
}

t_str:i_simple_expr{
  t_str_item body;
}

t_char:i_simple_expr{
  t_char_item body;
}

t_num:i_simple_expr{
  t_number body;
}

t_id:i_simple_expr{
  t_name body;
}

t_sign:i_simple_expr{
  char body=any_char("~|&=<>!:?;,.+-*/%^");
}

t_cppcore{

t_lev03{
  string oper=any_str_from_vec(split("+,-,!,~",","))?;
  TAutoPtr<i_expr> expr;
}
t_lev05{
  t_oper{string value=any_str_from_vec(split("*,/,%",","));}
  t_item{t_oper oper;t_lev03 expr;}
  t_lev03 expr;
  vector<t_item> arr?;
}
t_lev06{
  t_oper{string value=any_str_from_vec(split("+,-",","));}
  t_item{t_oper oper;t_lev05 expr;}
  t_lev05 expr;
  vector<t_item> arr?;
}
t_lev07{
  t_oper{string value=any_str_from_vec(split("<<,>>",","));}
  t_item{t_oper oper;t_lev06 expr;}
  t_lev06 expr;
  vector<t_item> arr?;
}
t_lev08{
  t_oper{string value=any_str_from_vec(split("<,<=,>,>=",","));}
  t_item{t_oper oper;t_lev07 expr;}
  t_lev07 expr;
  vector<t_item> arr?;
}
t_lev09{
  t_oper{string value=any_str_from_vec(split("==,!=",","));}
  t_item{t_oper oper;t_lev08 expr;}
  t_lev08 expr;
  vector<t_item> arr?;
}
t_lev10{
  t_oper{"&" inline static const string value="&";}
  t_item{t_oper oper; t_lev09 expr;}
  t_lev09 expr;
  vector<t_item> arr?;
}
t_lev11{
  t_oper{"^" inline static const string value="^";}
  t_item{t_oper oper; t_lev10 expr;}
  t_lev10 expr;
  vector<t_item> arr?;
}
t_lev12{
  t_oper{"|" inline static const string value="|";}
  t_item{t_oper oper; t_lev11 expr;}
  t_lev11 expr;
  vector<t_item> arr?;
}
t_lev13{
  t_oper{"&&" inline static const string value="&&";}
  t_item{t_oper oper; t_lev12 expr;}
  t_lev12 expr;
  vector<t_item> arr?;
}
t_lev14{
  t_oper{"||" inline static const string value="||";}
  t_item{t_oper oper; t_lev13 expr;}
  t_lev13 expr;
  vector<t_item> arr?;
}
/*
var pad2=num=>(num<10?"0"+num:""+num);
return(
`+,-,!,~
*,/,%
+,-
<<,>>
<,<=,>,>=
==,!=
&
^
|
&&
||`.split("\r").join("").split("\n").map((ops,i)=>{
  var e="t_lev"+pad2(i==1?3:i+3);
  var n="t_lev"+pad2(i+4);
  if(!i){
    return `t_lev03{
  string oper=any_str_from_vec(split(`+JSON.stringify(ops)+`,","))?;
  TAutoPtr<i_expr> expr;
}`;
  }
  var oa=ops.split(",");
  if(oa.length==1){
    return n+`{
  t_oper{"`+oa[0]+`" inline static const string value="`+oa[0]+`";}
  t_item{t_oper oper; `+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
  }
  return n+`{
  t_oper{string value=any_str_from_vec(split("`+ops+`",","));}
  t_item{t_oper oper;`+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
}).join("\n"));
*/
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

t_varcall_expr:i_expr{
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
    "<"
    t_sep sep0?;
    vector<t_lev14> expr=vec(",");
    t_sep sep1?;
    ">"
    TAutoPtr<t_dd_part> ddp?;
  }
  t_arr{
    t_sep sep?;
    vector<t_sb_expr> arr;
  }
  t_item{
    t_sep sepB?;
    "."
    t_sep sep0?;
    t_name name;
    t_arr arr?;
  }
  t_var{
    t_name name;
    t_sep sep0?;
    TAutoPtr<i_part> tp?;
    TAutoPtr<t_arr> arr?;
    vector<t_item> items?;
  }
  t_var var;
  t_sep sep?;
  TAutoPtr<t_call_params> params?;
}

t_block_expr:i_expr{
  "("
  t_lev14 body;
  ")"
}

/*
t_call_expr:i_expr{
  t_var_expr call;
  t_sep sep?;
  t_call_params params;
}*/

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

t_name_code:i_code{
  string value=str<t_name::t_impl>();
}

t_num_code:i_code{
  t_number body;
}

t_str_seq{
  "\""
  vector<TAutoPtr<i_str_item>> arr?;
  "\""
  }

t_sep_str_seq{
  " "
  t_str_seq body;
}

t_str_code:i_code{
  t_str_seq first;
  vector<t_sep_str_seq> arr?;
}

t_char_code:i_code{
  "'"
  TAutoPtr<i_char_item> body;
  "'"
}

t_sign_code:i_code{
  t_sign body;
}

t_name_code_with_sep=>i_code_with_sep{t_name_code body;t_sep sep?;}
t_num_code_with_sep=>i_code_with_sep{t_num_code body;t_sep sep?;}
t_str_code_with_sep=>i_code_with_sep{t_str_code body;t_sep sep?;}
t_char_code_with_sep=>i_code_with_sep{t_char_code body;t_sep sep?;}
t_sign_code_with_sep=>i_code_with_sep{t_sign_code body;t_sep sep?;}
t_soft_brackets_code_with_sep=>i_code_with_sep{
  "(" " "? vector<TAutoPtr<i_code_with_sep>> body?; ")" " "?
}
t_hard_brackets_code_with_sep=>i_code_with_sep{
  "[" " "? vector<TAutoPtr<i_code_with_sep>> body?; "]" " "?
}
t_curly_brackets_code_with_sep=>i_code_with_sep{
  "{" " "? vector<TAutoPtr<i_code_with_sep>> body?; "}" " "?
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
@@@
*/

//real_source_code:
/*
var mk=POST['data'].split("@@@")[1];
var gen=function(lex,mk){
  if(lex.includes("brackets")){
    var json=JSON.stringify;
    var m={soft:["(",")"],hard:["[","]"],curly:["{","}"]}
    for(var k in m)if(lex.includes(k))return [
      lex+"_with_sep=>i_code_with_sep{",
      "  "+json(m[k][0])+' " "? vector<TAutoPtr<i_code_with_sep>> body?; '+json(m[k][1])+' " "?',
      "}"
    ].join("\n");
  }
  return lex+"_with_sep=>i_code_with_sep{"+lex+" body;t_sep sep?;}";
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
}

t_soft_brackets_code:i_code{
  "("
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  ")"
}

t_hard_brackets_code:i_code{
  "["
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  "]"
}

t_curly_brackets_code:i_code{
  "{"
  t_sep sep0?;
  TAutoPtr<t_code> body?;
  t_sep sep1?;
  "}"
}

t_semicolon{
  ";"
}

t_value_item{
  string body=str<TAutoPtr<t_cppcore::i_expr>>();
}

t_value{
  " "?
  "="
  string body=str<TAutoPtr<t_cppcore::i_expr>>();
}

t_type_scope{
  "::"
}

t_type_templ{
  TAutoPtr<i_type_templ> body;
}

t_type_item_string:i_type_item{
  t_str_item body;
}

t_type_item_char:i_type_item{
  t_char_item body;
}

t_type_item_number:i_type_item{
  t_number body;
}

t_type_item_type;

t_scope_type_item{
  t_type_scope scope;
  TAutoPtr<t_type_item_type> body;
}

t_type_item_type:i_type_item {
  TAutoPtr<t_type_scope> scope?;
  t_name type;
  TAutoPtr<t_type_templ> param?;
  vector<t_scope_type_item> arr?;
}

t_type_expr2{
  TAutoPtr<t_type_scope> scope?;
  t_type_item_type body;
}

t_type_templ_param{
  TAutoPtr<i_type_item> body;
}

t_sep_type_templ_param{
  ","
  t_type_templ_param body;
}

t_type_templ_params{
  t_type_templ_param first;
  vector<t_sep_type_templ_param> arr?;
}

t_type_templ_angle:i_type_templ{
  "<"
  TAutoPtr<t_type_templ_params> params?;
  ">"
}

t_type_templ_soft:i_type_templ{
  "("
  TAutoPtr<t_type_templ_params> params?;
  ")"
}

t_struct_cmd_mode:i_struct_cmd_xxxx{
  char body=any_char("DMO");
  " "?
  "+="
  " "?
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

t_sep_field:i_struct_field{" "?}
t_semicolon_field:i_struct_field{TAutoPtr<t_semicolon> sc;}

t_const_field:i_struct_field{
  t_qst{"?"}
  t_c_item:i_sc_item{t_char_item body;}
  t_s_item:i_sc_item{t_str_item body;}
  string value=str<TAutoPtr<i_sc_item>>();
  " "?
  TAutoPtr<t_qst> qst?;
  " "?
  TAutoPtr<t_semicolon> sc?;
  " "?
}

t_struct_field_value {
  " "?
  "=";
  " "?
  TAutoPtr<t_cppcore::t_varcall_expr> expr;
}
  
t_qst{string s;{go_any(s,"*?");}}

t_struct_field:i_struct_field{
  TAutoPtr<t_cppcore::i_expr> type;
  " "?
  t_name name;
  TAutoPtr<t_struct_field_value> value?;
  " "?
  TAutoPtr<t_qst> qst?;
  " "?
  ";"
  " "?
  TAutoPtr<t_attr> attr?;
  " "?
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
  " "
}

t_struct_cmd_suffix:i_struct_cmd_so{
  char value=any_char("?!");
}

t_struct_cmd_optional:i_struct_cmd_so{
  "["
  string value=any_str_from_vec(split("optional,mandatory",","));
  "]"
}

t_struct_cmd_opt_v2:i_struct_cmd_so{
  ";"
  " "?
  string value=any_str_from_vec(split("optional,mandatory",","));
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
}

t_sep_struct_cmd{
  " "?
  t_struct_cmd body;
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


t_cpp_code_sep:i_cpp_code{
  t_sep sep;
}

t_cpp_code_main:i_cpp_code{
  TAutoPtr<i_code_with_sep> body;
}

t_cpp_code{
  t_bayan{"[::]"}
  t_fields:i_major{t_struct_field f;}
  t_cmds:i_major{t_struct_cmds c;}
  t_atr:i_major{TAutoPtr<t_attr> attr;}
  t_eater{vector<TAutoPtr<i_cpp_code>> arr;}
  t_with_bayan:i_bayan{
    t_bayan bayan;
    t_eater eater?;
  }
  t_minor_eater{t_eater eater=minor<TAutoPtr<i_major>>();}
  t_without_bayan:i_bayan{
    t_minor_eater eater=minor<t_with_bayan>();
  }
  " "?
  TAutoPtr<i_bayan> bayan;
}

t_target_struct:i_target_item{
  t_keyword{string kw=any_str_from_vec(split("struct,class",","));" "?}
  t_body_semicolon:i_struct_impl{";"}
  t_body_impl:i_struct_impl{
    "{"
    vector<TAutoPtr<i_target_item>> nested?;
    " "?
    vector<TAutoPtr<i_struct_field>> arr?;
    " "?
    TAutoPtr<t_struct_cmds> cmds?;
    " "?
    TAutoPtr<t_cpp_code> c?;
    " "?
    "}"
  }
  t_parent{
    string arrow_or_colon=any_str_from_vec(split("=>,:",","));
    " "?
    t_name parent;
  }
  TAutoPtr<t_keyword> kw?;
  t_name name;
  " "?
  TAutoPtr<t_parent> parent?;
  " "?
  TAutoPtr<i_struct_impl> body;
}

t_target_semicolon:i_target_item{vector<t_semicolon> arr;}
t_target_sep:i_target_item{t_sep sep;}

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

t_target_typedef:i_target_item{
  "typedef"
  " "
  t_cppcore::t_varcall_expr::t_var type;
  " "?
  t_name name;
  " "?
  ";"
}

t_target{
  vector<TAutoPtr<i_target_item>> arr;
}
}
//