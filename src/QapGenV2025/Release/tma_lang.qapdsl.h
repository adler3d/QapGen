t_expr;
t_pascal_expr{
  TAutoPtr<t_expr> expr;
}

t_sql{
  t_sep_seq:i_sep{
    string body=any(" \t\r\n");
  }
  t_sql_block_comment:i_sep{
    "/*"
    string body=end("*/");
  }
  t_sql_line_comment:i_sep{
    "--"
    string body=any(dip_inv("\n"))?;
  }
  t_sep{
    //t_impl{
    //  vector<TAutoPtr<i_sep>> arr;
    //}
    //string value=str<t_impl>();
    vector<TAutoPtr<i_sep>> arr;
  }

  typedef array<char,2> ARRAY2char;
  typedef array<char,4> ARRAY4char;
  using " " as t_sep;

  t_str_raw:i_str_item{
    string body=any(dip_inv("'\\\n"));
  }
  t_str_hex:i_str_item{
    "\\x"
    ARRAY2char body=any_arr_char(gen_dips("09afAF"));
  }
  t_str_unicode:i_str_item{
    "\\u"
    ARRAY4char body=any_arr_char(gen_dips("09"));
  }
  t_str_escape:i_str_item{
    "\\"
    char body=any_char("tfbrn\\'\""+gen_dips("07"));
  }
  t_str_impl{
    t_one{"'" vector<TAutoPtr<i_str_item>> arr; "'"}
    vector<t_one> arr;
  }

  t_str_expr:i_expr{
    string value=str<t_str_impl>();
  }

  t_bool_expr:i_expr{
    string value=any_str_from_vec(split("true,false",","));
  }

  t_name{
    t_keyword{
      string value=any_str_from_vec(split("select,insert,update,delete,from,where,and,or,not,in,between,like,is,null,distinct,as,join,on,using,having,union,all,create,drop,table,index,view,trigger,procedure,function,case,else,end,cast,convert,set,values,into,exists,limit,offset,true,false,nullif,ifnull,single",",")); // without:group,inner,left,right,full,order,by,asc,desc,when,then,
    }
    t_impl{
      char A=any_char(gen_dips("azAZ")+"_");
      string B=any(gen_dips("azAZ09")+"_")?;
    }
    t_impl_ex{
      t_impl impl=diff<t_keyword>();
    }
    string value=str<t_impl_ex>();
  }

  t_lev01{
    string oper=any_str_from_vec(split("not,+,-",","))?;
    " "?
    TAutoPtr<i_expr> expr;
  }
  t_lev02{
    t_oper{string value=any_str_from_vec(split("*,/,%,div,mod",","));}
    t_item{" "? t_oper oper;" "?t_lev01 expr;}
    t_lev01 expr;
    vector<t_item> arr?;
  }
  t_lev03{
    t_oper{string value=any_str_from_vec(split("+,-",","));}
    t_item{" "? t_oper oper;" "?t_lev02 expr;}
    t_lev02 expr;
    vector<t_item> arr?;
  }
  t_lev04{
    t_oper{string value=any_str_from_vec(split("shl,shr",","));}
    t_item{" "? t_oper oper;" "?t_lev03 expr;}
    t_lev03 expr;
    vector<t_item> arr?;
  }
  t_lev05{
    t_oper{"||"[::]inline static const string value="||";}
    t_item{" "?t_oper oper;" "?t_lev04 expr;}
    t_lev04 expr;
    vector<t_item> arr?;
  }
  t_lev06{
    t_not{"not"}
    t_between:i_lev06_ext{
      TAutoPtr<t_not> neg?;
      " "?
      "between"
      " "?
      t_lev05 low;
      " "?
      "and"
      " "?
      t_lev05 high;
    }
    t_is_null:i_lev06_ext{
      " "?
      "is"
      " "?
      TAutoPtr<t_not> not?;
      " "?
      "null"
    }
    t_in_list:i_lev06_ext{
      " "?
      TAutoPtr<t_not> not?;
      " "?
      "in"
      " "?
      TAutoPtr<i_in_operand> operand;
    }
    t_oper{string value=any_str_from_vec(split("=,<>,<,>,<=,>=,like,in",","));}
    t_item{t_oper oper;" "?t_lev05 expr;" "?}
    t_lev05 expr;
    " "?
    vector<t_item> arr?;
    TAutoPtr<i_lev06_ext> ext?;
  }
  t_lev07{
    t_oper{"and"[::]inline static const string value="and";}
    t_item{" "?t_oper oper;" " t_lev06 expr;}
    t_lev06 expr;
    vector<t_item> arr?;
  }
  t_lev08{
    t_oper{"or"[::]inline static const string value="or";}
    t_item{" "?t_oper oper;" " t_lev07 expr;}
    t_lev07 expr;
    vector<t_item> arr?;
  }
  t_star_expr:i_expr{"*"}
  t_lev08_with_sep{" "?t_lev08 expr;" "?}
  t_block_expr:i_expr{
    "("
    " "?
    vector<t_lev08_with_sep> arr=vec(",");
    " "?
    ")"
  }
  t_varcall_expr:i_expr{
    t_item{"." " "? t_name name; " "?}
    t_name name;
    " "?
    vector<t_item> arr?;
    TAutoPtr<t_block_expr> params?;
  }
  t_when_branch{
    "when"
    " "?
    t_lev08 cond;
    " "?
    "then"
    " "?
    t_lev08 result;
    " "?
  }

  t_else_branch{
    "else"
    " "?
    t_lev08 result;
  }

  t_case_expr:i_expr{
    "case"
    " "?
    t_lev08 input?;
    " "?
    vector<t_when_branch> arr;
    TAutoPtr<t_else_branch> else_branch?;
    " "?
    "end"
  }

  t_as_alias{t_as_opt{"as"} TAutoPtr<t_as_opt> opt?; " "? t_name alias;}

  t_joined_table_part:i_table_expr{
    " "?
    string join_type=any_str_from_vec(split("inner join,left join,right join,full join,join",","));
    " "?
    t_name right;
    " "?
    TAutoPtr<t_as_alias> as?;
    " "?
    "on"
    " "?
    t_lev08 on_cond;
  }

  t_table_expr:i_table_expr{
    t_name name;
    " "?
    TAutoPtr<t_as_alias> as?;
    " "?
    vector<t_joined_table_part> arr?;
    " "?
  }

  t_subquery:i_table_expr{
    "("
    " "?
    TAutoPtr<i_data_stat> query;
    " "?
    ")"
    " "?
    TAutoPtr<t_as_alias> as?;
  }

  t_in_list:i_in_operand{
    "("
    " "?
    vector<t_lev08> arr=vec(",")?;
    " "?
    ")"
  }

  t_in_subquery:i_in_operand{
    t_subquery body;
  }

  t_frac_part{
    "."
    string digits=any(gen_dips("09"));
  }
  t_exp_part{
    char e=any_char("eE");
    string sign=any_str_from_vec(split("+,-",","))?;
    string digits=any(gen_dips("09"));
  }

  t_num_expr:i_expr{
    t_int_part:i_num_part{
      char first=any_char(gen_dips("19"));
      string rest=any(gen_dips("09"))?;
    }
    t_zero_part:i_num_part{"0"}
    t_impl2:i_impl{
      TAutoPtr<t_frac_part> frac;
      TAutoPtr<t_exp_part> exp?;
    }
    t_impl:i_impl{
      //string sign=any_str_from_vec(split("+,-","))?;
      TAutoPtr<i_num_part> int_part;
      TAutoPtr<t_frac_part> frac?;
      TAutoPtr<t_exp_part> exp?;
    }
    string value=str<TAutoPtr<i_impl>>();
  }

  t_nullif_func:i_expr{
    string kw=any_str_from_vec(split("nullif,ifnull",","));
    " "?
    "("
    " "?
    t_lev08 left;
    " "?
    ","
    " "?
    t_lev08 right;
    " "?
    ")"
    " "?
  }

  t_host_expr:i_expr{
    ":"
    " "?
    TAutoPtr<t_pascal_expr> expr;
    " "?
  }

  t_where_clause{
    "where"
    " "?
    t_lev08 cond;
  }

  t_column_item{
    " "?
    t_lev08 expr;
    " "?
    TAutoPtr<t_as_alias> as?;
    " "?
  }

  t_column_list{
    t_arr:i_clist_item{vector<t_column_item> arr=vec(",");}
    t_star:i_clist_item{"*"}
    TAutoPtr<i_clist_item> item;
  }

  t_group_by_clause{
    "group"
    " "?
    "by"
    " "?
    t_column_list cols;
  }

  t_having_clause{
    "having"
    " "?
    t_lev08 cond;
  }

  t_order_by_item{
    " "?
    t_varcall_expr expr;
    " "?
    string order=any_str_from_vec(split("asc,desc",","))?;
    " "?
  }

  t_order_by_clause{
    "order" " "? "by"
    " "?
    vector<t_order_by_item> arr=vec(",")?;
  }

  t_select_stat:i_data_stat{
    t_from{
      "from"
      " "?
      TAutoPtr<i_table_expr> table;
      " "?
    }
    string kw=any_str_from_vec(split("select,single",","));
    " "?
    string ad=any_str_from_vec(split("all,distinct",","))?;
    " "?
    t_column_list cols;
    " "?
    TAutoPtr<t_from> from?;
    TAutoPtr<t_where_clause> where?;
    " "?
    TAutoPtr<t_group_by_clause> group_by?;
    " "?
    TAutoPtr<t_having_clause> having?;
    " "?
    TAutoPtr<t_order_by_clause> order_by?;
  }

  t_subquery_expr:i_expr{
    "("
    " "?
    t_select_stat query;
    " "?
    ")"
    " "?
    TAutoPtr<t_as_alias> as?;
    " "?
  }

  t_union_part{
    " "?
    string op=any_str_from_vec(split("union,union all",","));
    " "?
    t_select_stat query;
  }

  t_union_stat:i_data_stat{
    t_select_stat first;
    vector<t_union_part> unions;
  }

  t_values_row{
    " "?
    "("
    " "?
    vector<t_lev08_with_sep> arr=vec(",");
    " "?
    ")"
    " "?
  }

  t_values_body:i_insert_body{
    "values"
    " "?
    vector<t_values_row> arr=vec(",")?;
  }

  t_select_body:i_insert_body{
    t_select_stat query;
  }

  t_insert_stat:i_data_stat{
    "insert"
    " "?
    "into"
    " "?
    t_varcall_expr table;
    " "?
    TAutoPtr<i_insert_body> body;
  }

  t_update_item{
    " "?
    t_name col;
    " "?
    "="
    " "?
    t_lev08 expr;
    " "?
  }

  t_update_stat:i_data_stat{
    "update"
    " "?
    t_name table;
    " "?
    "set"
    vector<t_update_item> arr=vec(",")?;
    TAutoPtr<t_where_clause> where?;
  }

  t_delete_stat:i_data_stat{
    "delete"
    " "?
    "from"
    " "?
    t_name table;
    " "?
    TAutoPtr<t_where_clause> where?;
  }

  t_sep_stat:i_data_stat{" "}
  t_semicolon_stat:i_data_stat{";"}

  t_script{
    vector<TAutoPtr<i_data_stat>> stats;
  }
}
//---
//2025.08.14 09:44:54.655
//t_true:i_expr{"true" " "?}
//t_false:i_expr{"false" " "?}
//t_nil:i_expr{"nil" " "?}
//t_null:i_expr{"null" " "?}
t_sep{
  t_comment:i_sep{"{" string s=any(dip_inv("}")); "}"}
  t_c_comment:i_sep{"//" string body=any(dip_inv("\n\r"));}
  t_raw_sep:i_sep{string s=any(" \r\n\t");}
  string value=str<vector<TAutoPtr<i_sep>>>();
}
typedef array<char,2> ARRAY2char;
typedef array<char,4> ARRAY4char;
using " " as t_sep;
t_name{
  t_keyword{
    string value=any_str_from_vec(split("begin,end,var,procedure,function,if,then,else,for,to,downto,do,while,repeat,until,case,of,const,type,array,record,program,div,mod,and,or,not,break,continue,shr,shl,xor",","));
  }
  t_impl{
    char A=any_char(gen_dips("azAZ")+"_");
    string B=any(gen_dips("azAZ09")+"_")?;
  }
  t_impl_ex{
    t_impl impl=diff<t_keyword>();
  }
  string value=str<t_impl_ex>();
}
t_name_with_sep{" "? t_name n; " "?}
t_string=>i_expr{
  t_raw=>i_item{string body=any(dip_inv("'\\\n"));}
  t_fix=>i_item{"\\" char body=any_char("'\"\\/bfnrt");}
  t_hex=>i_item{"\\u" ARRAY4char arr=any_arr_char(gen_dips("09afAF"));}
  "'"
  vector<TAutoPtr<i_item>> arr?;
  "'"
  " "?
}
t_number=>i_expr{
  t_minus{"-"}
  t_frac{"." string arr=any(gen_dips("09"));}
  t_sign{char sign=any_char("-+");}
  t_exp{
    char e=any_char("eE");
    TAutoPtr<t_sign> sign?;
    string arr=any(gen_dips("09"));
    
  }
  t_num=>i_int{
    char first=any_char(gen_dips("19"));
    string num=any(gen_dips("09"))?;
  }
  t_zero=>i_int{"0"}
  TAutoPtr<t_minus> minus?;
  TAutoPtr<i_int> val;
  TAutoPtr<t_frac> frac?;
  TAutoPtr<t_exp> exp?;
  " "?
}
t_sql_expr:i_expr{
  "("
  " "?
  TAutoPtr<t_sql::i_data_stat> data_stat;
  " "?
  ")"
  " "?
}

t_array_type:i_var_type{
  t_of{"of" " "? t_name type; " "?}
  "array"
  " "?
  TAutoPtr<t_of> of?;
}
t_var_type:i_var_type{t_name type; " "?}
t_var_decl{
  vector<t_name_with_sep> names=vec(",");
  ":"
  " "?
  TAutoPtr<i_var_type> type;
  ";"
  " "?
}
t_var:i_stat{
  "var"
  " "?
  vector<t_var_decl> arr;
  " "?
}
t_enum_decl{
  t_value{"=" " "? t_number num; " "?}
  t_elem{" "? t_name name; " "? TAutoPtr<t_value> value?;}
  t_name name;
  " "?
  "="
  " "?
  "("?
  vector<t_elem> type=vec(",");
  ")"
  " "?
  ";"
  " "?
}
t_type:i_stat{
  "type"
  " "?
  vector<t_enum_decl> arr;
  " "?
}
t_param_decl{
  t_item{" "? t_name name; " "?}
  t_const{"const" " "}
  t_defvalue{"=" " "? t_number num;}
  TAutoPtr<t_const> c?;
  vector<t_item> arr=vec(",");
  ":"
  " "?
  TAutoPtr<i_var_type> type;
  " "?
  TAutoPtr<t_defvalue> value?;
  " "?
}
t_params_decl{
  "("
  " "?
  vector<t_param_decl> arr=vec(";")?;
  " "?
  ")"
}

t_exit_stat:i_stat{"exit" " "? ";" " "?}
t_break_stat:i_stat{"break" " "? ";" " "?}
t_continue_stat:i_stat{"continue" " "? ";" " "?}

t_block_stat:i_stat{
  "begin"
  " "?
  vector<i_stat> arr;
  " "?
  "end"
  " "?
  ";"
  " "?
}
t_lev01{
  string oper=any_str_from_vec(split("not,^,@,new",","))?;
  " "?
  TAutoPtr<i_expr> expr;
}
t_lev02{
  t_oper{string value=any_str_from_vec(split("*,/,div,mod,and,shl,shr",","));}
  t_item{" "? t_oper oper;" "?t_lev01 expr;}
  t_lev01 expr;
  vector<t_item> arr?;
}
t_lev03{
  t_oper{string value=any_str_from_vec(split("+,-",","));}
  t_item{" "? t_oper oper;" "?t_lev02 expr;}
  t_lev02 expr;
  vector<t_item> arr?;
}
t_lev04{
  t_oper{string value=any_str_from_vec(split("=,<>,<,>,<=,>=,in,is,like",","));}
  t_item{" "? t_oper oper;" "?t_lev03 expr;}
  t_lev03 expr;
  vector<t_item> arr?;
}
t_lev05{
  t_oper{"xor"[::]inline static const string value="xor";}
  t_item{" "?t_oper oper;" "?t_lev04 expr;}
  t_lev04 expr;
  vector<t_item> arr?;
}
t_lev06{
  t_oper{"or"[::]inline static const string value="or";}
  t_item{" "?t_oper oper;" "?t_lev05 expr;}
  t_lev05 expr;
  vector<t_item> arr?;
}
/*
var pad2=num=>(num<10?"0"+num:""+num);
return(
`not,^,@,new
*,/,div,mod,and,shl,shr
+,-
=,<>,<,>,<=,>=,in,is,like
xor
or`.split("\r").join("").split("\n").map((ops,i)=>{
  var e="t_lev"+pad2(!i?1:i);
  var n="t_lev"+pad2(i+1);  
  if(!i){
    return `t_lev01{
  string oper=any_str_from_vec(split(`+JSON.stringify(ops)+`,","))?;
  " "?
  TAutoPtr<i_expr> expr;
}`;
  }
  var oa=ops.split(",");
  if(oa.length==1){
    return n+`{
  t_oper{"`+oa[0]+`"[::]inline static const string value="`+oa[0]+`";}
  t_item{" "?t_oper oper;" "?`+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
  }
  return n+`{
  t_oper{string value=any_str_from_vec(split("`+ops+`",","));}
  t_item{" "? t_oper oper;" "?`+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
}).join("\n"));
*/

t_expr{
  t_as{"as" " " t_name type; " "?}
  t_lev06 expr;
  " "?
  TAutoPtr<t_as> as?;
}

t_param{" "? t_expr expr; " "?}

t_sb_expr:i_expr{
  t_arr_elem:i_elem{"[" " "? vector<t_param> arr=vec(","); "]" " "?}
  t_dot_elem:i_elem{"." " "? t_name name; " "?}
  t_params_elem:i_elem{
    "("
    " "?
    vector<t_param> arr=vec(",")?;
    ")"
    " "?
  }
  "["
  " "?
  vector<t_param> arr=vec(",")?;
  "]"
  " "?
  vector<TAutoPtr<i_elem>> elems?;
}

t_if_stat:i_stat{
  t_else{"else" " "? TAutoPtr<i_stat> stat; " "?}
  "if"
  " "?
  t_expr expr;
  " "?
  "then"
  " "?
  TAutoPtr<i_stat> stat;
  TAutoPtr<t_else> estat?;
  " "?
}


/*
foo.bar();foo()();foo[0]();foo.bar[0].xx.baz[1,5][0]()()[0];
*/
t_varcall_expr:i_expr{
  t_deref_elem:i_elem{"^" " "?}
  t_arr_elem:i_elem{"[" " "? vector<t_param> arr=vec(","); "]" " "?}
  t_dot_elem:i_elem{"." " "? t_name name; " "?}
  t_params_elem:i_elem{
    "("
    " "?
    vector<t_param> arr=vec(",")?;
    ")"
    " "?
  }
  t_name name;
  " "?
  vector<TAutoPtr<i_elem>> arr?;
  " "?
}

t_assign_stat:i_stat{
  t_varcall_expr var;
  " "?
  ":="
  " "?
  t_expr expr;
  " "?
  ";"
  " "?
}

t_for_stat:i_stat{
  "for" " "?
  t_assign_stat from;
  " "?
  string dir=any_str_from_vec(split("to,downto",","));
  " "?
  t_expr expr;
  " "?
  "do"
  " "?
  TAutoPtr<i_stat> body;
}

t_block_expr:i_expr{
  "("
  " "?
  t_expr expr;
  " "?
  ")"
  " "?
  vector<TAutoPtr<t_varcall_expr::i_elem>> arr?;
  " "?
}

t_while_stat:i_stat{
  "while"
  " "?
  t_expr expr;
  " "?
  "do"
  " "?
  TAutoPtr<i_stat> stat;
  " "?
}

t_repeat_stat:i_stat{
  "repeat"
  " "?
  vector<TAutoPtr<i_stat>> arr;
  " "?
  "until"
  " "?
  t_expr expr;
  " "?
  ";"
  " "?
}

t_case_item{
  t_expr expr;
  " "?
  ":"
  " "?
  vector<TAutoPtr<i_stat>> arr;
  ";"
  " "?
}

t_case_stat:i_stat{
  "case"
  " "?
  t_expr expr;
  " "?
  "of"
  " "?
  vector<t_case_item> arr;
  " "?
  "end"
  " "?
  ";"
  " "?
}

t_const_decl{
  t_name name;
  " "?
  "="
  " "?
  t_expr expr;
  ";"
  " "?
}

t_const:i_stat{
  "const"
  " "
  vector<t_const_decl> arr;
  " "?
}
t_expr_stat:i_stat{
  t_expr expr;
  " "?
  ";"
  " "?
}
//t_sep_stat:i_stat{" "}
t_semicolon_stat:i_stat{";" " "?}
t_func_or_proc_stat:i_stat{
  t_ret_type{
    ":"
    " "?
    t_name name;
  }
  t_var_d:i_d{t_var d;" "?}
  t_const_d:i_d{t_const d;" "?}
  string kw=any_str_from_vec(split("function,procedure",","));
  " "
  t_name name;
  " "?
  TAutoPtr<t_params_decl> params?;
  " "?
  TAutoPtr<t_ret_type> type?;
  " "?
  ";"
  " "?
  vector<TAutoPtr<i_d>> darr?;
  " "?
  "begin"
  " "?
  vector<i_stat> arr?;
  " "?
  "end"
  " "?
  ";"
  " "?
}