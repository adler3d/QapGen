t_inl_file{
  t_lev03{
    string oper;
    TAutoPtr<i_expr> expr;
    {
      O+=go_any_str_from_vec(oper,split("&,*,+,-,!,~",","));
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
  t_expr{t_lev14 body;{go_auto(body);}}
  t_tmpl_lev03{
    string oper;
    TAutoPtr<i_tmpl_expr> expr;
    {
      O+=go_any_str_from_vec(oper,split("&,*,+,-,!,~",","));
      M+=go_auto(expr);
    }
  }
  t_tmpl_lev05{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("*,/,%",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev03 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev03 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev06{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("+,-",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev05 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev05 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev09{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("==,!=",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev06 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev06 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev10{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("&",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev09 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev09 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev11{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("^",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev10 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev10 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev12{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("|",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev11 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev11 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev13{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("&&",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev12 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev12 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_lev14{
    t_oper{
      string value;
      {
        go_any_str_from_vec(value,split("||",","));
      }
    }
    t_item{
      t_oper oper;
      t_tmpl_lev13 expr;
      {
        go_auto(oper);
        go_auto(expr);
      }
    }
    t_tmpl_lev13 expr;
    vector<t_item> arr;
    {
      M+=go_auto(expr);
      O+=go_auto(arr);
    }
  }
  t_tmpl_expr{t_tmpl_lev14 body;{go_auto(body);}}
  t_concrete_param{
    t_sep sep0;
    TAutoPtr<i_concrete_param_way> body;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(body);
      O+=go_auto(sep1);
    }
  }
  t_concrete_params{
    vector<t_concrete_param> arr;
    t_sep sep;
    {
      M+=go_const("<");
      O+=go_vec(arr,",");
      M+=go_const(">");
      O+=go_auto(sep);
    }
  }
  t_access_mod{string keyword;{go_any_str_from_vec(keyword,split("public,protected,private",","));}}
  t_access_mod_class_stat=>i_class_stat{
    t_access_mod mod;
    t_sep sep;
    {
      M+=go_auto(mod);
      O+=go_auto(sep);
      M+=go_const(":");
    }
  }
  t_raw_func_body{
    t_sep_item=>i_item{t_sep sep;{go_auto(sep);}}
    t_s_item=>i_item{string value;{go_str<t_str_item::t_impl>(value);}}
    t_c_item=>i_item{string value;{go_str<t_char_item::t_impl>(value);}}
    t_code_item=>i_item{string code;{go_any(code,gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");}}
    t_div_item=>i_item{{go_const("/");}}
    t_block_item=>i_item{TAutoPtr<t_raw_func_body> body;{go_auto(body);}}
    t_sep sep;
    vector<TAutoPtr<i_item>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }
  t_func_path{
    t_item{
        string value;
      t_sep sep0;
      t_sep sep1;
      {
        M+=go_str<t_name>(value);
        O+=go_auto(sep0);
        M+=go_const("::");
        O+=go_auto(sep1);
      }
    }
    vector<t_item> arr;
    {
      go_auto(arr);
    }
  }
  t_const_with_sep{t_sep sep;string keyword;{O+=go_auto(sep);M+=go_any_str_from_vec(keyword,split("typename,const,unsigned",","));}}
  t_keyword{
    string keyword;
    t_sep sep;
    {
      M+=go_any_str_from_vec(keyword,split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
      O+=go_auto(sep);
    }
  }
  t_ptr{
    TAutoPtr<t_const_with_sep> cv;
    t_sep sep;
    {
      O+=go_auto(cv);
      O+=go_auto(sep);
      M+=go_const("*");
    }
  }
  t_ref{
    TAutoPtr<t_const_with_sep> cv;
    t_sep sep;
    string ref;
    {
      O+=go_auto(cv);
      O+=go_auto(sep);
      M+=go_any_str_from_vec(ref,split("&&,&",","));
    }
  }
  t_type_with_sep{
    t_sep sep;
    string name;
    TAutoPtr<t_concrete_params> concrete_params;
    {
      O+=go_auto(sep);
      M+=go_str<t_name>(name);
      O+=go_auto(concrete_params);
    }
  }
  t_scope_with_sep{t_sep sep;{O+=go_auto(sep);M+=go_const("::");}}
  t_scopes{
    t_item{t_scope_with_sep sws;t_type_with_sep body;{go_auto(sws);go_auto(body);}}
    t_type_with_sep first;
    vector<t_item> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }
  t_fv_class_stat=>i_class_stat{
    t_type_expr{
      t_type_expr_with_sep_and_cv{
        vector<t_const_with_sep> cvs;
        TAutoPtr<t_type_expr> body;
        {
          O+=go_auto(cvs);
          M+=go_auto(body);
        }
      }
      t_name_part{TAutoPtr<i_name_part> body;{go_auto(body);}}
      t_arr_body{
        t_sep sep0;
        t_sep sep1;
        t_expr expr;
        t_sep sep2;
        t_sep sep3;
        {
          O+=go_auto(sep0);
          M+=go_const("[");
          O+=go_auto(sep1);
          M+=go_auto(expr);
          O+=go_auto(sep2);
          M+=go_const("]");
          O+=go_auto(sep3);
        }
      }
      t_raw_name_part=>i_name_part{string name;{go_str<t_name>(name);}}
      t_brackets_name_part=>i_name_part{
        t_amp{string body;{go_any_str_from_vec(body,split("&,&&",","));}}
        t_amp_part=>i_part{t_amp body;{go_auto(body);}}
        t_star_part=>i_part{string stars;TAutoPtr<t_amp> amp;{M+=go_any(stars,"*");O+=go_auto(amp);}}
        TAutoPtr<i_part> stamp_part;
        t_sep sep;
        TAutoPtr<t_name_part> namepart;
        TAutoPtr<t_arr_body> arrbody;
        {
          M+=go_const("(");
          M+=go_auto(stamp_part);
          O+=go_auto(sep);
          O+=go_auto(namepart);
          M+=go_const(")");
          O+=go_auto(arrbody);
        }
      }
      t_func_param_value{
        t_sep sep;
        t_expr value;
        {
          M+=go_const("=");
          O+=go_auto(sep);
          M+=go_auto(value);
        }
      }
      t_func_param{
        t_sep sep0;
        TAutoPtr<i_func_param> body;
        t_sep sep1;
        TAutoPtr<t_func_param_value> value;
        t_sep sep2;
        {
          O+=go_auto(sep0);
          M+=go_auto(body);
          O+=go_auto(sep1);
          O+=go_auto(value);
          O+=go_auto(sep2);
        }
      }
      t_func_params{
        t_sep sep;
        vector<t_func_param> arr;
        {
          O+=go_auto(sep);
          M+=go_const("(");
          O+=go_vec(arr,",");
          M+=go_const(")");
        }
      }
      t_pfunc{
        t_addr{
          t_type_expr_with_sep_and_cv type;
          {
            M+=go_auto(type);
            M+=go_const("::");
          }
        }
        t_type_expr_with_sep_and_cv type;
        t_addr addr;
        string name;
        t_func_params params;
        {
          M+=go_auto(type);
          M+=go_const("(");
          O+=go_auto(addr);
          M+=go_const("*");
          O+=go_str<t_name>(name);
          M+=go_const(")");
          M+=go_auto(params);
        }
      }
      t_pfunc_func_param=>i_func_param{t_pfunc value;{go_auto(value);}}
      t_var_args_func_param=>i_func_param{{go_const("...");}}
      t_type_func_param=>i_func_param{
        t_const{t_sep sep;{M+=go_const("const");O+=go_auto(sep);}}
        t_type_expr_with_sep_and_cv type;
        t_sep sep;
        TAutoPtr<t_const> cv;
        TAutoPtr<t_name_part> namepart;
        {
          M+=go_auto(type);
          O+=go_auto(sep);
          O+=go_auto(cv);
          O+=go_auto(namepart);
        }
      }
      t_expr_func_param=>i_func_param{t_expr body;{go_minor<t_type_func_param>(body);}}
      t_fv_stat{
        t_impl_func_body=>i_fv_body{t_sep sep;t_raw_func_body body;{O+=go_auto(sep);M+=go_auto(body);}}
        t_zero_func_body=>i_fv_body{{go_const("=0;");}}
        t_delete_func_body=>i_fv_body{{go_const("=delete;");}}
        t_func_fv_end=>i_fv_end{
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1;
          t_sep sep1;
          TAutoPtr<i_fv_body> body;
          {
            M+=go_auto(params);
            O+=go_auto(cv1);
            O+=go_auto(sep1);
            M+=go_auto(body);
          }
        }
        t_var_fv_end=>i_fv_end{
          t_func_fv_item=>i_fv_item{
            TAutoPtr<t_func_params> params;
            TAutoPtr<t_const_with_sep> cv1;
            {
              M+=go_auto(params);
              O+=go_auto(cv1);
            }
          }
          t_var_fv_item=>i_fv_item{
            TAutoPtr<t_arr_body> arrbody;
            TAutoPtr<t_func_param_value> value;
            {
              O+=go_auto(arrbody);
              O+=go_auto(value);
            }
          }
          t_body{TAutoPtr<i_fv_item> body;{go_auto(body);}}
          t_item{
            t_sep sep0;
            TAutoPtr<t_const_with_sep> cv;
            t_sep sep1;
            string name;
            t_sep sep2;
            t_body body;
            t_sep sep3;
            {
              M+=go_const(",");
              O+=go_auto(sep0);
              O+=go_auto(cv);
              O+=go_auto(sep1);
              M+=go_str<t_name>(name);
              O+=go_auto(sep2);
              M+=go_auto(body);
              O+=go_auto(sep3);
            }
          }
          TAutoPtr<t_body> body;
          vector<t_item> arr;
          {
            O+=go_auto(body);
            O+=go_auto(arr);
            M+=go_const(";");
          }
        }
        t_sep sep_wa;
        vector<t_keyword> keywords;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv;
        t_sep sep0;
        TAutoPtr<t_func_path> path;
        t_name_part name;
        t_sep sep1;
        TAutoPtr<i_fv_end> way;
        {
          O+=go_auto(sep_wa);
          O+=go_auto(keywords);
          M+=go_auto(type);
          O+=go_auto(cv);
          O+=go_auto(sep0);
          O+=go_auto(path);
          M+=go_auto(name);
          O+=go_auto(sep1);
          M+=go_auto(way);
        }
      }
      t_impl_typeexpr=>i_typeexpr{
        t_global{{M+=go_const("::");}}
        TAutoPtr<t_global> global;
        t_sep sep;
        t_scopes scopes;
        vector<t_ptr> ptrs;
        TAutoPtr<t_ref> ref;
        {
          O+=go_auto(global);
          O+=go_auto(sep);
          M+=go_auto(scopes);
          O+=go_auto(ptrs);
          O+=go_auto(ref);
        }
      }
      t_decl_typeexpr=>i_typeexpr{
        t_sep sep0;
        t_sep sep1;
        t_expr expr;
        t_sep sep2;
        {
          M+=go_const("decltype");
          O+=go_auto(sep0);
          M+=go_const("(");
          O+=go_auto(sep1);
          M+=go_auto(expr);
          O+=go_auto(sep2);
          M+=go_const(")");
        }
      }
      TAutoPtr<i_typeexpr> body;
      {
        go_auto(body);
      }
    }
    t_type_expr::t_fv_stat body;
    {go_auto(body);}
  }
  t_typedef_class_stat=>i_class_stat{
    t_sep sep;
    t_fv_class_stat::t_type_expr::t_fv_stat body;
    {
      M+=go_const("typedef");
      O+=go_auto(sep);
      M+=go_auto(body);
    }
  }
  t_real{
    t_f{char body;{go_any_char(body,"fF");}}
    string bef;
    string aft;
    TAutoPtr<t_f> ext;
    {
      M+=go_any(bef,gen_dips("09"));
      M+=go_const(".");
      O+=go_any(aft,gen_dips("09"));
      O+=go_auto(ext);
    }
  }
  t_call_param{
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(expr);
      O+=go_auto(sep1);
    }
  }
  t_call_expr=>i_expr{
    string func;
    t_sep sep;
    vector<t_call_param> arr;
    {
      M+=go_str<t_name>(func);
      O+=go_auto(sep);
      M+=go_const("(");
      O+=go_vec(arr,",");
      M+=go_const(")");
    }
  }
  t_block_expr=>i_expr{
    t_sep sep0;
    t_expr expr;
    t_sep sep1;
    {
      M+=go_const("(");
      O+=go_auto(sep0);
      M+=go_auto(expr);
      O+=go_auto(sep1);
      M+=go_const(")");
    }
  }
  t_bool_expr=>i_expr{string value;{go_any_str_from_vec(value,split("false,true",","));}}
  t_string_expr=>i_expr{string value;{go_str<t_str_item::t_impl>(value);}}
  t_char_expr=>i_expr{string value;{go_str<t_char_item::t_impl>(value);}}
  t_num_expr=>i_expr{string value;{go_any(value,gen_dips("09"));}}
  t_real_expr=>i_expr{string value;{go_str<t_real>(value);}}
  t_nullptr_expr=>i_expr{{go_const("nullptr");}}
  t_or_expr=>i_expr{vector<t_name> arr;{go_bin_oper(arr,"|");}}
  t_hex_expr=>i_expr{t_impl{char x;string value;{go_const("0");go_any_char(x,"xX");go_any(value,gen_dips("09afAF"));}}string value;{go_str<t_impl>(value);}}
  t_var_expr=>i_expr{
    t_item{
      t_type_with_sep body;
      t_sep sep;
      {
        M+=go_auto(body);
        O+=go_auto(sep);
        M+=go_const("::");
      }
    }
    t_field{t_sep bef;string name;t_sep aft;{O+=go_auto(bef);M+=go_str<t_name>(name);O+=go_auto(aft);}}
    t_impl{
      vector<t_item> items;
      t_sep sep;
      vector<t_field> arr;
      {
        O+=go_auto(items);
        O+=go_auto(sep);
        M+=go_vec(arr,".");
      }
    }
    string name;{go_str<t_impl>(name);}
  }
  t_ctor_init_list{
    t_init_param{
      t_sep sep0;
      string name;
      vector<t_call_param> arr;
      t_sep sep1;
      {
        O+=go_auto(sep0);
        M+=go_str<t_name>(name);
        M+=go_const("(");
        O+=go_vec(arr,",");
        M+=go_const(")");
        O+=go_auto(sep1);
      }
    }
    vector<t_init_param> params;
    t_sep sep;
    {
      M+=go_const(":");
      M+=go_vec(params,",");
      O+=go_auto(sep);
    }
  }
  t_zero_func_body=>i_func_body{{go_const("=0;");}}
  t_null_func_body=>i_func_body{t_sep sep;{O+=go_auto(sep);M+=go_const(";");}}
  t_delete_func_body=>i_func_body{{go_const("=delete;");}}
  t_impl_func_body=>i_func_body{
    t_sep sep;
    TAutoPtr<t_ctor_init_list> init_list;
    t_raw_func_body body;
    {
      O+=go_auto(sep);
      O+=go_auto(init_list);
      M+=go_auto(body);
    }
  }
  t_dtor_class_stat=>i_class_stat{
    t_sep sep0;
    TAutoPtr<t_func_path> path;
    string name;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<i_func_body> body;
    {
      O+=go_auto(path);
      M+=go_const("~");
      O+=go_auto(sep0);
      M+=go_str<t_name>(name);
      O+=go_auto(sep1);
      M+=go_auto(params);
      M+=go_auto(body);
    }
  }
  t_ctor_class_stat=>i_class_stat{
    t_impl{
      t_explicit{t_sep sep;{M+=go_const("explicit");M+=go_auto(sep);}}
      TAutoPtr<t_explicit> prefix;
      TAutoPtr<t_func_path> path;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> concrete_params;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<i_func_body> body;
      {
        O+=go_auto(prefix);
        O+=go_auto(path);
        M+=go_str<t_name>(name);
        O+=go_auto(concrete_params);
        M+=go_auto(params);
        M+=go_auto(body);
      }
    }
    t_impl body;{go_auto(body);}
  }
  t_oper_cast_class_stat=>i_class_stat{
    TAutoPtr<t_func_path> path;
    t_sep sep0;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_const_with_sep> cv;
    TAutoPtr<i_func_body> body;
    {
      O+=go_auto(path);
      M+=go_const("operator");
      O+=go_auto(sep0);
      M+=go_auto(type);
      O+=go_auto(sep1);
      M+=go_auto(params);
      O+=go_auto(cv);
      M+=go_auto(body);
    }
  }
  t_common_oper_class_stat=>i_class_stat{
    t_impl{
      vector<t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_const_with_sep> cv0;
      t_sep sep0;
      TAutoPtr<t_func_path> path;
      t_sep sep1;
      string oper;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      {
        O+=go_auto(keywords);
        M+=go_auto(type);
        O+=go_auto(cv0);
        O+=go_auto(sep0);
        O+=go_auto(path);
        M+=go_const("operator");
        O+=go_auto(sep1);
        M+=go_any_str_from_vec(oper,split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
        M+=go_auto(params);
        O+=go_auto(cv1);
        M+=go_auto(body);
      }
    }
    t_impl body;{go_auto(body);}
  }
  t_parents{
    t_item{
      t_pub{t_access_mod mod;t_sep sep;{M+=go_auto(mod);O+=go_auto(sep);}}
      t_sep sep;
      TAutoPtr<t_pub> pub;
      string name;
      {
        O+=go_auto(sep);
        O+=go_auto(pub);
        M+=go_str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>(name);
      }
    }
    t_sep sep;
    vector<t_item> arr;
    {
      M+=go_const(":");
      O+=go_auto(sep);
      M+=go_vec(arr,",");
    }
  }
  t_class_body{
    vector<TAutoPtr<i_class_stat>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }
  t_class{
    string keyword;
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<t_parents> parents;
    t_sep sep2;
    TAutoPtr<t_class_body> body;
    t_sep sep3;
    {
      M+=go_any_str_from_vec(keyword,split("struct,class,union",","));
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      O+=go_auto(parents);
      O+=go_auto(sep2);
      O+=go_auto(body);
      O+=go_auto(sep3);
      M+=go_const(";");
    }
  }
  t_namespace_class_stat=>i_class_stat{
    t_sep sep0;
    string name;
    t_sep sep1;
    t_class_body body;
    {
      M+=go_const("namespace");
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  t_template_class_stat=>i_class_stat{
    t_template_param{
      t_sep bef;
      TAutoPtr<i_template_param> body;
      t_sep aft;
      {
        O+=go_auto(bef);
        M+=go_auto(body);
        O+=go_auto(aft);
      }
    }
    t_common_oper_template_body=>i_template_body{t_common_oper_class_stat::t_impl body;{go_auto(body);}}
    t_ctor_template_body=>i_template_body{t_ctor_class_stat::t_impl body;{go_auto(body);}}
    t_func_template_body=>i_template_body{
      vector<t_keyword> keywords;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_const_with_sep> cv0;
      t_sep sep0;
      string func_name;
      TAutoPtr<t_concrete_params> concrete_params;
      t_sep sep1;
      t_fv_class_stat::t_type_expr::t_func_params params;
      t_sep sep2;
      TAutoPtr<t_const_with_sep> cv1;
      TAutoPtr<i_func_body> body;
      {
        O+=go_auto(keywords);
        M+=go_auto(type);
        O+=go_auto(cv0);
        O+=go_auto(sep0);
        M+=go_str<t_name>(func_name);
        O+=go_auto(concrete_params);
        O+=go_auto(sep1);
        M+=go_auto(params);
        O+=go_auto(sep2);
        O+=go_auto(cv1);
        M+=go_auto(body);
      }
    }
    class_template_body=>i_template_body{
      string keyword;
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_concrete_params> params;
      TAutoPtr<t_parents> parents;
      t_sep sep2;
      TAutoPtr<t_class_body> body;
      t_sep sep3;
      {
        M+=go_any_str_from_vec(keyword,split("struct,class,union",","));
        M+=go_auto(sep0);
        O+=go_str<t_name>(name);
        O+=go_auto(sep1);
        O+=go_auto(params);
        O+=go_auto(parents);
        O+=go_auto(sep2);
        O+=go_auto(body);
        O+=go_auto(sep3);
        M+=go_const(";");
      }
    }
    t_name_template_param=>i_template_param{
      t_unsgnd{t_sep sep;{M+=go_const("unsigned");}}
      t_value{
        t_expr body;
        t_sep sep;
        {
          M+=go_const("=");
          O+=go_auto(sep);
          M+=go_auto(body);
        }
      }
      string unsgnd0;
      t_sep sep0;
      string type;
      t_sep sep1;
      string unsgnd1;
      t_sep sep2;
      string name;
      t_sep sep3;
      TAutoPtr<t_value> value;
      {
        O+=go_str<t_unsgnd>(unsgnd0);
        O+=go_auto(sep0);
        M+=go_str<t_name>(type);
        O+=go_auto(sep1);
        O+=go_str<t_unsgnd>(unsgnd1);
        O+=go_auto(sep2);
        O+=go_str<t_name>(name);
        O+=go_auto(sep3);
        O+=go_auto(value);
      }
    }
    t_head{
      t_sep sep0;
      vector<t_template_param> params;
      t_sep sep1;
      {
        M+=go_const("template");
        O+=go_auto(sep0);
        M+=go_const("<");
        O+=go_vec(params,",");
        M+=go_const(">");
        O+=go_auto(sep1);
      }
    }
    t_type_template_param=>i_template_param{
      TAutoPtr<t_head> head;
      string type;
      t_sep sep;
      string name;
      {
        O+=go_auto(head);
        M+=go_any_str_from_vec(type,split("class,typename",","));
        O+=go_auto(sep);
        O+=go_str<t_name>(name);
      }
    }
    t_head head;
    TAutoPtr<i_template_body> body;
    {
      M+=go_auto(head);
      M+=go_auto(body);
    }
  }
  t_enum_class_stat=>i_class_stat{
    t_value{
      t_sep sep0;
      t_expr expr;
      t_sep sep1;
      {
        M+=go_const("=");
        O+=go_auto(sep0);
        M+=go_auto(expr);
        O+=go_auto(sep1);
      }
    }
    t_item{
      t_sep sep0;
      string name;
      t_sep sep1;
      TAutoPtr<t_value> value;
      {
        O+=go_auto(sep0);
        M+=go_str<t_name>(name);
        O+=go_auto(sep1);
        O+=go_auto(value);
      }
    }
    t_comma_with_sep{t_sep sep;{M+=go_const(",");O+=go_auto(sep);}}
    t_impl_body=>i_body{
      vector<t_item> arr;
      TAutoPtr<t_comma_with_sep> comma;
      {
        M+=go_const("{");
        O+=go_vec(arr,",");
        O+=go_auto(comma);
        M+=go_const("}");
      }
    }
    t_empty_body=>i_body{{go_const(";");}}
    t_body{TAutoPtr<i_body> body;{go_auto(body);}}
    t_sep sep0;
    string name;
    t_sep sep1;
    t_body body;
    {
      M+=go_const("enum");
      O+=go_auto(sep0);
      O+=go_str<t_name>(name);
      O+=go_auto(sep1);
      O+=go_auto(body);
    }
  }
  t_using_class_stat=>i_class_stat{
    t_sep sep;
    t_fv_class_stat::t_type_expr type;
    {
      M+=go_const("using");
      O+=go_auto(sep);
      M+=go_auto(type);
    }
  }
  t_tmpl_call_param{
    t_sep sep0;
    t_tmpl_expr expr;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      M+=go_auto(expr);
      O+=go_auto(sep1);
    }
  }
  t_call_tmpl_expr=>i_tmpl_expr{
    string func;
    t_sep sep;
    vector<t_tmpl_call_param> arr;
    {
      M+=go_str<t_name>(func);
      O+=go_auto(sep);
      M+=go_const("(");
      O+=go_vec(arr,",");
      M+=go_const(")");
    }
  }
  t_block_tmpl_expr=>i_tmpl_expr{
    t_sep sep0;
    t_tmpl_expr expr;
    t_sep sep1;
    {
      M+=go_const("(");
      O+=go_auto(sep0);
      M+=go_auto(expr);
      O+=go_auto(sep1);
      M+=go_const(")");
    }
  }
  t_pfunc_concrete_param_way=>i_concrete_param_way{t_fv_class_stat::t_type_expr::t_pfunc value;{go_auto(value);}}
  t_type_concrete_param_way=>i_concrete_param_way{t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv value;{go_auto(value);}}
  t_expr_concrete_param_way=>i_concrete_param_way{t_tmpl_expr value;{go_minor<t_type_concrete_param_way>(value);}}
  t_bool_tmpl_expr=>i_tmpl_expr{string value;{go_any_str_from_vec(value,split("false,true",","));}}
  t_string_tmpl_expr=>i_tmpl_expr{string value;{go_str<t_str_item::t_impl>(value);}}
  t_char_tmpl_expr=>i_tmpl_expr{string value;{go_str<t_char_item::t_impl>(value);}}
  t_num_tmpl_expr=>i_tmpl_expr{string value;{go_any(value,gen_dips("09"));}}
  t_real_tmpl_expr=>i_tmpl_expr{string value;{go_str<t_real>(value);}}
  t_nullptr_tmpl_expr=>i_tmpl_expr{{go_const("nullptr");}}
  t_or_tmpl_expr=>i_tmpl_expr{vector<t_name> arr;{go_bin_oper(arr,"|");}}
  t_hex_tmpl_expr=>i_tmpl_expr{
    t_impl{char x;string value;{go_const("0");go_any_char(x,"xX");go_any(value,gen_dips("09afAF"));}}string value;
    {go_str<t_impl>(value);}
  }
  t_var_tmpl_expr=>i_tmpl_expr{string name;{go_str<t_fv_class_stat::t_type_expr>(name);}}
  t_pragma_class_stat=>i_class_stat{string body;{go_const("#pragma");go_end(body,"\n");}}
  t_include_class_stat=>i_class_stat{string body;{go_const("#include");go_end(body,"\n");}}
  t_preproc_if_class_stat=>i_class_stat{string body;{go_const("#if");go_end(body,"\n");}}
  t_preproc_else_class_stat=>i_class_stat{string body;{go_const("#else");go_end(body,"\n");}}
  t_preproc_endif_class_stat=>i_class_stat{string body;{go_const("#endif");go_end(body,"\n");}}
  t_define_class_stat=>i_class_stat{string body;{go_const("#define");go_end(body,"\n");}}
  t_undef_class_stat=>i_class_stat{string body;{go_const("#undef");go_end(body,"\n");}}
  t_sep_class_stat=>i_class_stat{t_sep sep;{go_auto(sep);}}
  t_null_class_stat=>i_class_stat{{go_const(";");}}
  t_class_class_stat=>i_class_stat{t_class body;{go_auto(body);}}
  t_inl_file_stat{
    t_sep sep;
    TAutoPtr<t_class> body;
    {
      O+=go_auto(sep);
      M+=go_auto(body);
    }
  }
  vector<TAutoPtr<i_class_stat>> arr;
  {
    go_auto(arr);
  }
}