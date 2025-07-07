t_simple_stat_lex{
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
      char first='1';
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
  t_var_stat=>i_stat{
    t_value{
      t_sep sep0;
      t_sep sep1;
      t_lev14 value;
      {
        O+=go_auto(sep0);
        M+=go_const("=");
        O+=go_auto(sep1);
        M+=go_auto(value);
      }
    }
    t_type_impl=>i_impl{
      t_type_expr type;
      t_sep sep0;
      t_name name;
      TAutoPtr<t_value> value;
      t_sep sep1;
      {
        M+=go_auto(type);
        M+=go_auto(sep0);
        M+=go_auto(name);
        O+=go_auto(value);
        O+=go_auto(sep1);
      }
    }
    t_auto_impl=>i_impl{
      t_sep sep0;
      t_name name;
      TAutoPtr<t_value> value;
      t_sep sep1;
      {
        M+=go_const("auto");
        M+=go_auto(sep0);
        M+=go_auto(name);
        O+=go_auto(value);
        O+=go_auto(sep1);
      }
    }
    t_impl{
      TAutoPtr<i_impl> impl;
      {
        go_auto(impl);
      }
    }
    t_impl body;
    {
      go_auto(body);
      go_const(";");
    }
  }
  t_sep_stat=>i_stat{
    t_sep sep;
    {
      go_auto(sep);
    }
  }
  t_command_block{
    vector<TAutoPtr<i_stat>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }
  t_block_stat=>i_stat{
    t_command_block body;
    {
      go_auto(body);
    }
  }
  t_expr_stat=>i_stat{
    t_lev14 body;
    {
      go_auto(body);
      go_const(";");
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
    t_num=>i_val{
      char first='1';
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
  t_param{
    t_sep sep0;
    string type;
    t_sep sep1;
    t_name name;
    t_sep sep2;
    {
      O+=go_auto(sep0);
      M+=go_str<t_type_expr>(type);
      M+=go_auto(sep1);
      M+=go_auto(name);
      O+=go_auto(sep2);
    }
  }
  t_params{
    vector<t_param> arr;
    t_sep sep;
    {
      M+=go_const("(");
      O+=go_vec(arr,",");
      O+=go_auto(sep);
      M+=go_const(")");
    }
  }
  t_set_oper{
    t_var_expr::t_impl var;
    string oper;
    t_lev14 expr;
    {
      go_auto(var);
      go_any_str_from_vec(oper,split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=",","));
      go_auto(expr);
    }
  }
  t_set_oper_stat=>i_stat{
    t_set_oper body;
    {
      go_auto(body);
      go_const(";");
    }
  }
  t_func_stat=>i_stat{
    t_impl{
      string type;
      t_sep sep0;
      t_name name;
      t_sep sep1;
      t_params params;
      t_sep sep2;
      t_command_block body;
      {
        M+=go_str<t_type_expr>(type);
        M+=go_auto(sep0);
        M+=go_auto(name);
        O+=go_auto(sep1);
        M+=go_auto(params);
        O+=go_auto(sep2);
        M+=go_auto(body);
      }
    }
    t_impl body;
    {
      go_auto(body);
    }
  }
  t_oper_stat=>i_stat{
    t_name type;
    t_sep sep0;
    t_sep sep1;
    string oper;
    t_sep sep2;
    t_params params;
    t_sep sep3;
    t_command_block body;
    {
      M+=go_auto(type);
      M+=go_auto(sep0);
      M+=go_const("operator");
      O+=go_auto(sep1);
      M+=go_any_str_from_vec(oper,split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!",","));
      O+=go_auto(sep2);
      M+=go_auto(params);
      O+=go_auto(sep3);
      M+=go_auto(body);
    }
  }
  t_ret_stat=>i_stat{
    t_sep sep0;
    t_lev14 body;
    t_sep sep1;
    {
      M+=go_const("return");
      M+=go_auto(sep0);
      M+=go_auto(body);
      O+=go_auto(sep1);
      M+=go_const(";");
    }
  }
  t_null_stat=>i_stat{
    {
      go_const(";");
    }
  }
  t_postfix_oper{
    t_var_expr::t_impl var;
    string oper;
    {
      go_auto(var);
      go_any_str_from_vec(oper,split("++,--",","));
    }
  }
  t_postfix_oper_stat=>i_stat{
    t_postfix_oper body;
    {
      go_auto(body);
    }
  }
  t_break_stat=>i_stat{
    {
      go_const("break;");
    }
  }
  t_continue_stat=>i_stat{
    {
      go_const("continue;");
    }
  }
  t_for_stat=>i_stat{
    t_set=>i_next{
      t_set_oper body;
      {
        go_auto(body);
      }
    }
    t_postfix=>i_next{
      t_postfix_oper body;
      {
        go_auto(body);
      }
    }
    t_next{
      TAutoPtr<i_next> body;
      {
        go_auto(body);
      }
    }
    t_sep sep0;
    t_sep sep1;
    TAutoPtr<t_var_stat::t_impl> init;
    t_sep sep2;
    t_sep sep3;
    TAutoPtr<t_lev14> cond;
    t_sep sep4;
    t_sep sep5;
    TAutoPtr<t_next> next;
    t_sep sep6;
    t_sep sep7;
    TAutoPtr<i_stat> body;
    {
      M+=go_const("for");
      O+=go_auto(sep0);
      M+=go_const("(");
      O+=go_auto(sep1);
      O+=go_auto(init);
      O+=go_auto(sep2);
      M+=go_const(";");
      O+=go_auto(sep3);
      O+=go_auto(cond);
      O+=go_auto(sep4);
      M+=go_const(";");
      O+=go_auto(sep5);
      O+=go_auto(next);
      O+=go_auto(sep6);
      M+=go_const(")");
      O+=go_auto(sep7);
      M+=go_auto(body);
    }
  }
  t_if_stat=>i_stat{
    t_else{
      t_sep sep0;
      t_sep sep1;
      TAutoPtr<i_stat> body;
      {
        O+=go_auto(sep0);
        M+=go_const("else");
        O+=go_auto(sep1);
        M+=go_auto(body);
      }
    }
    t_sep sep0;
    t_sep sep1;
    t_lev14 cond;
    t_sep sep2;
    t_sep sep3;
    TAutoPtr<i_stat> bef;
    TAutoPtr<t_else> aft;
    {
      M+=go_const("if");
      O+=go_auto(sep0);
      M+=go_const("(");
      O+=go_auto(sep1);
      M+=go_auto(cond);
      O+=go_auto(sep2);
      M+=go_const(")");
      O+=go_auto(sep3);
      M+=go_auto(bef);
      O+=go_auto(aft);
    }
  }
  t_struct{
    t_field{
      t_sep sep0;
      t_var_stat::t_type_impl body;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_auto(body);
        M+=go_const(";");
        O+=go_auto(sep1);
      }
    }
    t_method{
      t_sep sep0;
      t_func_stat::t_impl body;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_auto(body);
        O+=go_auto(sep1);
      }
    }
    t_sep sep0;
    t_name name;
    t_sep sep1;
    vector<t_sep_struct> arr;
    vector<t_field> fields;
    vector<t_method> methods;
    {
      M+=go_const("struct");
      M+=go_auto(sep0);
      M+=go_auto(name);
      O+=go_auto(sep1);
      M+=go_const("{");
      O+=go_auto(arr);
      O+=go_auto(fields);
      O+=go_auto(methods);
      M+=go_const("}");
    }
  }
  t_sep_struct{
    t_sep sep0;
    t_struct body;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(body);
      O+=go_auto(sep1);
    }
  }
  t_struct_stat=>i_stat{
    t_struct body;
    {
      go_auto(body);
    }
  }
  t_template_stat=>i_stat{
    t_param{
      t_type{
        {
          go_const("class");
        }
      }
      t_sep sep0;
      t_type type;
      t_sep sep1;
      t_name name;
      t_sep sep2;
      {
        O+=go_auto(sep0);
        M+=go_auto(type);
        O+=go_auto(sep1);
        M+=go_auto(name);
        O+=go_auto(sep2);
      }
    }
    t_params{
      vector<t_param> arr;
      {
        go_const("{");
        go_vec(arr,",");
        go_const("}");
      }
    }
    t_func_body=>i_body{
      t_func_stat::t_impl body;
      {
        go_auto(body);
      }
    }
    t_oper_body=>i_body{
      t_oper_stat body;
      {
        go_auto(body);
      }
    }
    t_struct_body=>i_body{
      t_struct body;
      {
        go_auto(body);
      }
    }
    t_sep sep0;
    t_params params;
    t_sep sep1;
    TAutoPtr<i_body> body;
    {
      M+=go_const("template");
      O+=go_auto(sep0);
      M+=go_auto(params);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  {
    go_const("");
  }
}