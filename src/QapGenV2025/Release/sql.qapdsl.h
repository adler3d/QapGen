
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
    string value=any_str_from_vec(split("select,insert,update,delete,from,where,and,or,not,in,between,like,is,null,distinct,as,join,inner,left,right,full,on,using,group,having,order,by,asc,desc,union,all,create,drop,table,index,view,trigger,procedure,function,case,when,then,else,end,cast,convert,set,values,into,exists,limit,offset,true,false,nullif,ifnull,single",","));
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
    TAutoPtr<t_not> not?;
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
  /*
  t_in_select:i_lev06_ext{ - да ну нафин, я лучше запихаю селект в i_expr, а то я задалбался с ним возится.
    " "?
    "in"
    " "?
    "("
    " "?
    t_select_stat query;
    " "?
    ")"
  }*/
  t_oper{string value=any_str_from_vec(split("=,<>,<,>,<=,>=,like,in",","));}
  t_item{t_oper oper;" "?t_lev05 expr;" "?}
  t_lev05 expr;
  " "?
  vector<t_item> arr?;
  TAutoPtr<i_lev06_ext> ext?;

  // --- IN (список) ---
  //t_in_list{ - не нужен, т.к скобки в i_expr это прожуют.
  //  " "?
  //  "in"
  //  " "?
  //  "("
  //  " "?
  //  t_lev05 first;
  //  vector<t_lev05> rest=vec(",")?;
  //  " "?
  //  ")"
  //}
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
/*
t_call_param{
  " "?
  t_lev08 expr;
  " "?
}
t_call_params{
  "("
  " "?
  vector<t_call_param> arr=vec(",");
  " "?
  ")"
}*/
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
/*
t_func:i_expr{
  t_name func;
  //string func=any_str_from_vec(split("count,sum,min,max,avg",","));
  " "?
  t_block_expr expr;
}*/

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
}

t_host_expr:i_expr{
  ":"
  " "?
  t_name var;// TODO: replace with any pascal expr
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
t_distinct_kw{"distinct"}

t_select_stat:i_data_stat{
  "select"
  " "?
  TAutoPtr<t_distinct_kw> distinct?;
  " "?
  t_column_list cols;
  " "?
  "from"
  " "?
  TAutoPtr<i_table_expr> table;
  " "?
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

t_sql_script{
  vector<TAutoPtr<i_data_stat>> stats;
}