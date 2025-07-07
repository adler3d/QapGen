t_simple_stat_lex{
  t_lev03{
    string oper=any_str_from_vec(split("+,-,!,~",","))?;
    TAutoPtr<i_expr> expr;
  }
  t_lev05{
    t_oper{
      string value=any_str_from_vec(split("*,/,%",","));
    }
    t_item{
      t_oper oper;
      t_lev03 expr;
    }
    t_lev03 expr;
    vector<t_item> arr?;
  }
  t_lev06{
    t_oper{
      string value=any_str_from_vec(split("+,-",","));
    }
    t_item{
      t_oper oper;
      t_lev05 expr;
    }
    t_lev05 expr;
    vector<t_item> arr?;
  }
  t_lev07{
    t_oper{
      string value=any_str_from_vec(split("<<,>>",","));
    }
    t_item{
      t_oper oper;
      t_lev06 expr;
    }
    t_lev06 expr;
    vector<t_item> arr?;
  }
  t_lev08{
    t_oper{
      string value=any_str_from_vec(split("<,<=,>,>=",","));
    }
    t_item{
      t_oper oper;
      t_lev07 expr;
    }
    t_lev07 expr;
    vector<t_item> arr?;
  }
  t_lev09{
    t_oper{
      string value=any_str_from_vec(split("==,!=",","));
    }
    t_item{
      t_oper oper;
      t_lev08 expr;
    }
    t_lev08 expr;
    vector<t_item> arr?;
  }
  t_lev10{
    t_oper{
      string value=any_str_from_vec(split("&",","));
    }
    t_item{
      t_oper oper;
      t_lev09 expr;
    }
    t_lev09 expr;
    vector<t_item> arr?;
  }
  t_lev11{
    t_oper{
      string value=any_str_from_vec(split("^",","));
    }
    t_item{
      t_oper oper;
      t_lev10 expr;
    }
    t_lev10 expr;
    vector<t_item> arr?;
  }
  t_lev12{
    t_oper{
      string value=any_str_from_vec(split("|",","));
    }
    t_item{
      t_oper oper;
      t_lev11 expr;
    }
    t_lev11 expr;
    vector<t_item> arr?;
  }
  t_lev13{
    t_oper{
      string value=any_str_from_vec(split("&&",","));
    }
    t_item{
      t_oper oper;
      t_lev12 expr;
    }
    t_lev12 expr;
    vector<t_item> arr?;
  }
  t_lev14{
    t_oper{
      string value=any_str_from_vec(split("||",","));
    }
    t_item{
      t_oper oper;
      t_lev13 expr;
    }
    t_lev13 expr;
    vector<t_item> arr?;
  }
  t_string{
    "\""
    string value=str<vector<TAutoPtr<i_str_item>>>()?;
    "\""
  }
  t_int_expr:i_expr{
    t_zero:i_val{
      "0"
    }
    t_num:i_val{
      char first='1';
      string num;
      {
        M+=go_any_char(first,gen_dips("19"));
        O+=go_any(num,gen_dips("09"));
      }
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
  t_var_stat:i_stat{
    t_value{
      t_sep sep0?;
      "="
      t_sep sep1?;
      t_lev14 value;
    }
    t_type_impl:i_impl{
      t_type_expr type;
      t_sep sep0;
      t_name name;
      TAutoPtr<t_value> value?;
      t_sep sep1?;
    }
    t_auto_impl:i_impl{
      "auto"
      t_sep sep0;
      t_name name;
      TAutoPtr<t_value> value?;
      t_sep sep1?;
    }
    t_impl{
      TAutoPtr<i_impl> impl;
    }
    t_impl body;
    ";"
  }
  t_sep_stat:i_stat{
    t_sep sep;
  }
  t_command_block{
    "{"
    vector<TAutoPtr<i_stat>> arr?;
    "}"
  }
  t_block_stat:i_stat{
    t_command_block body;
  }
  t_expr_stat:i_stat{
    t_lev14 body;
    ";"
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
      char sign='+';
      {
        go_any_char(sign,"-+");
      }
    }
    t_exp{
      char e='e';
      TAutoPtr<t_sign> sign;
      string arr;
      {
        M+=go_any_char(e,"eE");
        O+=go_auto(sign);
        M+=go_any(arr,gen_dips("09"));
      }
    }
    t_num:i_val{
      char first='1';
      string num;
      {
        M+=go_any_char(first,gen_dips("19"));
        O+=go_any(num,gen_dips("09"));
      }
    }
    t_zero:i_val{
      "0"
    }
    t_impl{
      TAutoPtr<i_val> val;
      TAutoPtr<t_frac> frac;
      TAutoPtr<t_exp> exp?;
    }
    string value=str<t_impl>();
  }
  t_var_expr:i_expr{
    t_elem{
      "["
      t_sep sep0?;
      t_lev14 expr;
      t_sep sep1?;
      "]"
    }
    t_item{
      t_name name;
      vector<t_elem> arr?;
    }
    t_impl{
      vector<t_item> arr=vec(".");
    }
    t_impl body;
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
    t_dot:i_call{
      t_var_expr::t_impl body;
    }
    t_colon:i_call{
      vector<t_name> arr=bin_oper("::");
    }
    TAutoPtr<i_call> call;
    t_sep sep?;
    t_call_params params;
  }
  t_param{
    t_sep sep0?;
    string type=str<t_type_expr>();
    t_sep sep1;
    t_name name;
    t_sep sep2?;
  }
  t_params{
    "("
    vector<t_param> arr=vec(",")?;
    t_sep sep?;
    ")"
  }
  t_set_oper{
    t_var_expr::t_impl var;
    string oper=any_str_from_vec(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",","));
    t_lev14 expr;
  }
  t_set_oper_stat:i_stat{
    t_set_oper body;
    ";"
  }
  t_func_stat:i_stat{
    t_impl{
      string type=str<t_type_expr>();
      t_sep sep0;
      t_name name;
      t_sep sep1?;
      t_params params;
      t_sep sep2?;
      t_command_block body;
    }
    t_impl body;
  }
  t_oper_stat:i_stat{
    t_name type;
    t_sep sep0;
    "operator"
    t_sep sep1?;
    string oper=any_str_from_vec(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!",","));
    t_sep sep2?;
    t_params params;
    t_sep sep3?;
    t_command_block body;
  }
  t_ret_stat:i_stat{
    "return"
    t_sep sep0;
    t_lev14 body;
    t_sep sep1?;
    ";"
  }
  t_null_stat:i_stat{
    ";"
  }
  t_postfix_oper{
    t_var_expr::t_impl var;
    string oper=any_str_from_vec(split("++,--",","));
  }
  t_postfix_oper_stat:i_stat{
    t_postfix_oper body;
  }
  t_break_stat:i_stat{
    "break;"
  }
  t_continue_stat:i_stat{
    "continue;"
  }
  t_for_stat:i_stat{
    t_set:i_next{
      t_set_oper body;
    }
    t_postfix:i_next{
      t_postfix_oper body;
    }
    t_next{
      TAutoPtr<i_next> body;
    }
    "for"
    t_sep sep0?;
    "("
    t_sep sep1?;
    TAutoPtr<t_var_stat::t_impl> init?;
    t_sep sep2?;
    ";"
    t_sep sep3?;
    TAutoPtr<t_lev14> cond?;
    t_sep sep4?;
    ";"
    t_sep sep5?;
    TAutoPtr<t_next> next?;
    t_sep sep6?;
    ")"
    t_sep sep7?;
    TAutoPtr<i_stat> body;
  }
  t_if_stat:i_stat{
    t_else{
      t_sep sep0?;
      "else"
      t_sep sep1?;
      TAutoPtr<i_stat> body;
    }
    "if"
    t_sep sep0?;
    "("
    t_sep sep1?;
    t_lev14 cond;
    t_sep sep2?;
    ")"
    t_sep sep3?;
    TAutoPtr<i_stat> bef;
    TAutoPtr<t_else> aft?;
  }
  t_struct{
    t_field{
      t_sep sep0?;
      t_var_stat::t_type_impl body;
      ";"
      t_sep sep1?;
    }
    t_method{
      t_sep sep0?;
      t_func_stat::t_impl body;
      t_sep sep1?;
    }
    "struct"
    t_sep sep0;
    t_name name;
    t_sep sep1?;
    "{"
    vector<t_sep_struct> arr?;
    vector<t_field> fields?;
    vector<t_method> methods?;
    "}"
  }
  t_sep_struct{
    t_sep sep0?;
    t_struct body;
    t_sep sep1?;
  }
  t_struct_stat:i_stat{
    t_struct body;
  }
  t_template_stat:i_stat{
    t_param{
      t_type{
        "class"
      }
      t_sep sep0?;
      t_type type;
      t_sep sep1?;
      t_name name;
      t_sep sep2?;
    }
    t_params{
      "{"
      vector<t_param> arr=vec(",");
      "}"
    }
    t_func_body:i_body{
      t_func_stat::t_impl body;
    }
    t_oper_body:i_body{
      t_oper_stat body;
    }
    t_struct_body:i_body{
      t_struct body;
    }
    "template"
    t_sep sep0?;
    t_params params;
    t_sep sep1?;
    TAutoPtr<i_body> body;
  }
}