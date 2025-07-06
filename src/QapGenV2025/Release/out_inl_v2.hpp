t_inl_file{
  t_lev03{
    string oper=any_str_from_vec(split("&,*,+,-,!,~",","))?;
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
  t_expr{
    t_lev14 body;
  }
  t_tmpl_lev03{
    string oper=any_str_from_vec(split("&,*,+,-,!,~",","))?;
    TAutoPtr<i_tmpl_expr> expr;
  }
  t_tmpl_lev05{
    t_oper{
      string value=any_str_from_vec(split("*,/,%",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev03 expr;
    }
    t_tmpl_lev03 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev06{
    t_oper{
      string value=any_str_from_vec(split("+,-",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev05 expr;
    }
    t_tmpl_lev05 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev09{
    t_oper{
      string value=any_str_from_vec(split("==,!=",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev06 expr;
    }
    t_tmpl_lev06 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev10{
    t_oper{
      string value=any_str_from_vec(split("&",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev09 expr;
    }
    t_tmpl_lev09 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev11{
    t_oper{
      string value=any_str_from_vec(split("^",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev10 expr;
    }
    t_tmpl_lev10 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev12{
    t_oper{
      string value=any_str_from_vec(split("|",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev11 expr;
    }
    t_tmpl_lev11 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev13{
    t_oper{
      string value=any_str_from_vec(split("&&",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev12 expr;
    }
    t_tmpl_lev12 expr;
    vector<t_item> arr?;
  }
  t_tmpl_lev14{
    t_oper{
      string value=any_str_from_vec(split("||",","));
    }
    t_item{
      t_oper oper;
      t_tmpl_lev13 expr;
    }
    t_tmpl_lev13 expr;
    vector<t_item> arr?;
  }
  t_tmpl_expr{
    t_tmpl_lev14 body;
  }
  t_concrete_param{
    t_sep sep0?;
    TAutoPtr<i_concrete_param_way> body;
    t_sep sep1?;
  }
  t_concrete_params{
    "<"
    vector<t_concrete_param> arr=vec(",")?;
    ">"
    t_sep sep?;
  }
  t_access_mod{
    string keyword=any_str_from_vec(split("public,protected,private",","));
  }
  t_access_mod_class_stat:i_class_stat{
    t_access_mod mod;
    t_sep sep?;
    ":"
  }
  t_raw_func_body{
    t_sep_item:i_item{
      t_sep sep;
    }
    t_s_item:i_item{
      string value=str<t_str_item::t_impl>();
    }
    t_c_item:i_item{
      string value=str<t_char_item::t_impl>();
    }
    t_code_item:i_item{
      string code=any(gen_dips("AZaz09")+"+-*?<>[](),.:;~!@#$_=%^&\\|");
    }
    t_div_item:i_item{
      "/"
    }
    t_block_item:i_item{
      TAutoPtr<t_raw_func_body> body;
    }
    "{"
    vector<TAutoPtr<i_item>> arr?;
    "}"
  }
  t_func_path{
    t_item{
      string value=str<t_name>();
      t_sep sep0?;
      "::"
      t_sep sep1?;
    }
    vector<t_item> arr;
  }
  t_const_with_sep{
    t_sep sep?;
    string keyword=any_str_from_vec(split("typename,const,unsigned",","));
  }
  t_keyword{
    string keyword=any_str_from_vec(split("friend,typename,extern,explicit,constexpr,virtual,const,static,inline,unsigned",","));
    t_sep sep?;
  }
  t_ptr{
    TAutoPtr<t_const_with_sep> cv?;
    t_sep sep?;
    "*"
  }
  t_ref{
    TAutoPtr<t_const_with_sep> cv?;
    t_sep sep?;
    string ref=any_str_from_vec(split("&&,&",","));
  }
  t_type_with_sep{
    t_sep sep?;
    string name=str<t_name>();
    TAutoPtr<t_concrete_params> concrete_params?;
  }
  t_scope_with_sep{
    t_sep sep?;
    "::"
  }
  t_scopes{
    t_item{
      t_scope_with_sep sws;
      t_type_with_sep body;
    }
    t_type_with_sep first;
    vector<t_item> arr?;
  }
  t_fv_class_stat:i_class_stat{
    t_type_expr{
      t_type_expr_with_sep_and_cv{
        vector<t_const_with_sep> cvs?;
        TAutoPtr<t_type_expr> body;
      }
      t_name_part{
        TAutoPtr<i_name_part> body;
      }
      t_arr_body{
        t_sep sep0?;
        "["
        t_sep sep1?;
        t_expr expr;
        t_sep sep2?;
        "]"
        t_sep sep3?;
      }
      t_raw_name_part:i_name_part{
        string name=str<t_name>();
      }
      t_brackets_name_part:i_name_part{
        t_amp{
          string body=any_str_from_vec(split("&,&&",","));
        }
        t_amp_part:i_part{
          t_amp body;
        }
        t_star_part:i_part{
          string stars=any("*");
          TAutoPtr<t_amp> amp?;
        }
        "("
        TAutoPtr<i_part> stamp_part;
        t_sep sep?;
        TAutoPtr<t_name_part> namepart?;
        ")"
        TAutoPtr<t_arr_body> arrbody?;
      }
      t_func_param_value{
        "="
        t_sep sep?;
        t_expr value;
      }
      t_func_param{
        t_sep sep0?;
        TAutoPtr<i_func_param> body;
        t_sep sep1?;
        TAutoPtr<t_func_param_value> value?;
        t_sep sep2?;
      }
      t_func_params{
        t_sep sep?;
        "("
        vector<t_func_param> arr=vec(",")?;
        ")"
      }
      t_pfunc{
        t_addr{
          t_type_expr_with_sep_and_cv type;
          "::"
        }
        t_type_expr_with_sep_and_cv type;
        "("
        t_addr addr?;
        "*"
        string name=str<t_name>()?;
        ")"
        t_func_params params;
      }
      t_pfunc_func_param:i_func_param{
        t_pfunc value;
      }
      t_var_args_func_param:i_func_param{
        "..."
      }
      t_type_func_param:i_func_param{
        t_const{
          "const"
          t_sep sep?;
        }
        t_type_expr_with_sep_and_cv type;
        t_sep sep?;
        TAutoPtr<t_const> cv?;
        TAutoPtr<t_name_part> namepart?;
      }
      t_expr_func_param:i_func_param{
        t_expr body=minor<t_type_func_param>();
      }
      t_fv_stat{
        t_impl_func_body:i_fv_body{
          t_sep sep?;
          t_raw_func_body body;
        }
        t_zero_func_body:i_fv_body{
          "=0;"
        }
        t_delete_func_body:i_fv_body{
          "=delete;"
        }
        t_func_fv_end:i_fv_end{
          TAutoPtr<t_func_params> params;
          TAutoPtr<t_const_with_sep> cv1?;
          t_sep sep1?;
          TAutoPtr<i_fv_body> body;
        }
        t_var_fv_end:i_fv_end{
          t_func_fv_item:i_fv_item{
            TAutoPtr<t_func_params> params;
            TAutoPtr<t_const_with_sep> cv1?;
          }
          t_var_fv_item:i_fv_item{
            TAutoPtr<t_arr_body> arrbody?;
            TAutoPtr<t_func_param_value> value?;
          }
          t_body{
            TAutoPtr<i_fv_item> body;
          }
          t_item{
            ","
            t_sep sep0?;
            TAutoPtr<t_const_with_sep> cv?;
            t_sep sep1?;
            string name=str<t_name>();
            t_sep sep2?;
            t_body body;
            t_sep sep3?;
          }
          TAutoPtr<t_body> body?;
          vector<t_item> arr?;
          ";"
        }
        t_sep sep_wa?;
        vector<t_keyword> keywords?;
        TAutoPtr<t_type_expr> type;
        TAutoPtr<t_const_with_sep> cv?;
        t_sep sep0?;
        TAutoPtr<t_func_path> path?;
        t_name_part name;
        t_sep sep1?;
        TAutoPtr<i_fv_end> way;
      }
      t_impl_typeexpr:i_typeexpr{
        t_global{
          "::"
        }
        TAutoPtr<t_global> global?;
        t_sep sep?;
        t_scopes scopes;
        vector<t_ptr> ptrs?;
        TAutoPtr<t_ref> ref?;
      }
      t_decl_typeexpr:i_typeexpr{
        "decltype"
        t_sep sep0?;
        "("
        t_sep sep1?;
        t_expr expr;
        t_sep sep2?;
        ")"
      }
      TAutoPtr<i_typeexpr> body;
    }
    t_type_expr::t_fv_stat body;
  }
  t_typedef_class_stat:i_class_stat{
    "typedef"
    t_sep sep?;
    t_fv_class_stat::t_type_expr::t_fv_stat body;
  }
  t_real{
    t_f{
      char body=any_char("fF");
    }
    string bef=any(gen_dips("09"));
    "."
    string aft=any(gen_dips("09"))?;
    TAutoPtr<t_f> ext?;
  }
  t_call_param{
    t_sep sep0?;
    t_expr expr;
    t_sep sep1?;
  }
  t_call_expr:i_expr{
    string func=str<t_name>();
    t_sep sep?;
    "("
    vector<t_call_param> arr=vec(",")?;
    ")"
  }
  t_block_expr:i_expr{
    "("
    t_sep sep0?;
    t_expr expr;
    t_sep sep1?;
    ")"
  }
  t_bool_expr:i_expr{
    string value=any_str_from_vec(split("false,true",","));
  }
  t_string_expr:i_expr{
    string value=str<t_str_item::t_impl>();
  }
  t_char_expr:i_expr{
    string value=str<t_char_item::t_impl>();
  }
  t_num_expr:i_expr{
    string value=any(gen_dips("09"));
  }
  t_real_expr:i_expr{
    string value=str<t_real>();
  }
  t_nullptr_expr:i_expr{
    "nullptr"
  }
  t_or_expr:i_expr{
    vector<t_name> arr=bin_oper("|");
  }
  t_hex_expr:i_expr{t_impl{
      "0"
      char x=any_char("xX");
      string value=any(gen_dips("09afAF"));
    }
    string value=str<t_impl>();
  }
  t_var_expr:i_expr{
    t_item{
      t_type_with_sep body;
      t_sep sep?;
      "::"
    }
    t_field{
      t_sep bef?;
      string name=str<t_name>();
      t_sep aft?;
    }
    t_impl{
      vector<t_item> items?;
      t_sep sep?;
      vector<t_field> arr=vec(".");
    }
    string name=str<t_impl>();
  }
  t_ctor_init_list{
    t_init_param{
      t_sep sep0?;
      string name=str<t_name>();
      "("
      vector<t_call_param> arr=vec(",")?;
      ")"
      t_sep sep1?;
    }
    ":"
    vector<t_init_param> params=vec(",");
    t_sep sep?;
  }
  t_zero_func_body:i_func_body{
    "=0;"
  }
  t_null_func_body:i_func_body{
    t_sep sep?;
    ";"
  }
  t_delete_func_body:i_func_body{
    "=delete;"
  }
  t_impl_func_body:i_func_body{
    t_sep sep?;
    TAutoPtr<t_ctor_init_list> init_list?;
    t_raw_func_body body;
  }
  t_dtor_class_stat:i_class_stat{
    TAutoPtr<t_func_path> path?;
    "~"
    t_sep sep0?;
    string name=str<t_name>();
    t_sep sep1?;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<i_func_body> body;
  }
  t_ctor_class_stat:i_class_stat{
    t_impl{
      t_explicit{
        "explicit"
        t_sep sep;
      }
      TAutoPtr<t_explicit> prefix?;
      TAutoPtr<t_func_path> path?;
      string name=str<t_name>();
      TAutoPtr<t_concrete_params> concrete_params?;
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<i_func_body> body;
    }
    t_impl body;
  }
  t_oper_cast_class_stat:i_class_stat{
    TAutoPtr<t_func_path> path?;
    "operator"
    t_sep sep0?;
    t_fv_class_stat::t_type_expr type;
    t_sep sep1?;
    t_fv_class_stat::t_type_expr::t_func_params params;
    TAutoPtr<t_const_with_sep> cv?;
    TAutoPtr<i_func_body> body;
  }
  t_common_oper_class_stat:i_class_stat{
    t_impl{
      vector<t_keyword> keywords?;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_const_with_sep> cv0?;
      t_sep sep0?;
      TAutoPtr<t_func_path> path?;
      "operator"
      t_sep sep1?;
      string oper=any_str_from_vec(split("=,+=,-=,*=,/=,%=,|=,&=,^=,<<=,>>=,||,&&,|,^,&,==,!=,<,<=,>,>=,<<,>>,+,-,*,/,%,++,--,~,!,(),[],->",","));
      t_fv_class_stat::t_type_expr::t_func_params params;
      TAutoPtr<t_const_with_sep> cv1?;
      TAutoPtr<i_func_body> body;
    }
    t_impl body;
  }
  t_parents{
    t_item{
      t_pub{
        t_access_mod mod;
        t_sep sep?;
      }
      t_sep sep?;
      TAutoPtr<t_pub> pub?;
      string name=str<t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv>();
    }
    ":"
    t_sep sep?;
    vector<t_item> arr=vec(",");
  }
  t_class_body{
    "{"
    vector<TAutoPtr<i_class_stat>> arr?;
    "}"
  }
  t_class{
    string keyword=any_str_from_vec(split("struct,class,union",","));
    t_sep sep0?;
    string name=str<t_name>()?;
    t_sep sep1?;
    TAutoPtr<t_parents> parents?;
    t_sep sep2?;
    TAutoPtr<t_class_body> body?;
    t_sep sep3?;
    ";"
  }
  t_namespace_class_stat:i_class_stat{
    "namespace"
    t_sep sep0?;
    string name=str<t_name>()?;
    t_sep sep1?;
    t_class_body body;
  }
  t_template_class_stat:i_class_stat{
    t_template_param{
      t_sep bef?;
      TAutoPtr<i_template_param> body;
      t_sep aft?;
    }
    t_common_oper_template_body:i_template_body{
      t_common_oper_class_stat::t_impl body;
    }
    t_ctor_template_body:i_template_body{
      t_ctor_class_stat::t_impl body;
    }
    t_func_template_body:i_template_body{
      vector<t_keyword> keywords?;
      t_fv_class_stat::t_type_expr type;
      TAutoPtr<t_const_with_sep> cv0?;
      t_sep sep0?;
      string func_name=str<t_name>();
      TAutoPtr<t_concrete_params> concrete_params?;
      t_sep sep1?;
      t_fv_class_stat::t_type_expr::t_func_params params;
      t_sep sep2?;
      TAutoPtr<t_const_with_sep> cv1?;
      TAutoPtr<i_func_body> body;
    }
    class_template_body:i_template_body{
      string keyword=any_str_from_vec(split("struct,class,union",","));
      t_sep sep0;
      string name=str<t_name>()?;
      t_sep sep1?;
      TAutoPtr<t_concrete_params> params?;
      TAutoPtr<t_parents> parents?;
      t_sep sep2?;
      TAutoPtr<t_class_body> body?;
      t_sep sep3?;
      ";"
    }
    t_name_template_param:i_template_param{
      t_unsgnd{
        "unsigned"
      }
      t_value{
        "="
        t_sep sep?;
        t_expr body;
      }
      string unsgnd0=str<t_unsgnd>()?;
      t_sep sep0?;
      string type=str<t_name>();
      t_sep sep1?;
      string unsgnd1=str<t_unsgnd>()?;
      t_sep sep2?;
      string name=str<t_name>()?;
      t_sep sep3?;
      TAutoPtr<t_value> value?;
    }
    t_head{
      "template"
      t_sep sep0?;
      "<"
      vector<t_template_param> params=vec(",")?;
      ">"
      t_sep sep1?;
    }
    t_type_template_param:i_template_param{
      TAutoPtr<t_head> head?;
      string type=any_str_from_vec(split("class,typename",","));
      t_sep sep?;
      string name=str<t_name>()?;
    }
    t_head head;
    TAutoPtr<i_template_body> body;
  }
  t_enum_class_stat:i_class_stat{
    t_value{
      "="
      t_sep sep0?;
      t_expr expr;
      t_sep sep1?;
    }
    t_item{
      t_sep sep0?;
      string name=str<t_name>();
      t_sep sep1?;
      TAutoPtr<t_value> value?;
    }
    t_comma_with_sep{
      ","
      t_sep sep?;
    }
    t_impl_body:i_body{
      "{"
      vector<t_item> arr=vec(",")?;
      TAutoPtr<t_comma_with_sep> comma?;
      "}"
    }
    t_empty_body:i_body{
      ";"
    }
    t_body{
      TAutoPtr<i_body> body;
    }
    "enum"
    t_sep sep0?;
    string name=str<t_name>()?;
    t_sep sep1?;
    t_body body?;
  }
  t_using_class_stat:i_class_stat{
    "using"
    t_sep sep?;
    t_fv_class_stat::t_type_expr type;
  }
  t_tmpl_call_param{
    t_sep sep0?;
    t_tmpl_expr expr;
    t_sep sep1?;
  }
  t_call_tmpl_expr:i_tmpl_expr{
    string func=str<t_name>();
    t_sep sep?;
    "("
    vector<t_tmpl_call_param> arr=vec(",")?;
    ")"
  }
  t_block_tmpl_expr:i_tmpl_expr{
    "("
    t_sep sep0?;
    t_tmpl_expr expr;
    t_sep sep1?;
    ")"
  }
  t_pfunc_concrete_param_way:i_concrete_param_way{
    t_fv_class_stat::t_type_expr::t_pfunc value;
  }
  t_type_concrete_param_way:i_concrete_param_way{
    t_fv_class_stat::t_type_expr::t_type_expr_with_sep_and_cv value;
  }
  t_expr_concrete_param_way:i_concrete_param_way{
    t_tmpl_expr value=minor<t_type_concrete_param_way>();
  }
  t_bool_tmpl_expr:i_tmpl_expr{
    string value=any_str_from_vec(split("false,true",","));
  }
  t_string_tmpl_expr:i_tmpl_expr{
    string value=str<t_str_item::t_impl>();
  }
  t_char_tmpl_expr:i_tmpl_expr{
    string value=str<t_char_item::t_impl>();
  }
  t_num_tmpl_expr:i_tmpl_expr{
    string value=any(gen_dips("09"));
  }
  t_real_tmpl_expr:i_tmpl_expr{
    string value=str<t_real>();
  }
  t_nullptr_tmpl_expr:i_tmpl_expr{
    "nullptr"
  }
  t_or_tmpl_expr:i_tmpl_expr{
    vector<t_name> arr=bin_oper("|");
  }
  t_hex_tmpl_expr:i_tmpl_expr{
    t_impl{
      "0"
      char x=any_char("xX");
      string value=any(gen_dips("09afAF"));
    }
    string value=str<t_impl>();
  }
  t_var_tmpl_expr:i_tmpl_expr{
    string name=str<t_fv_class_stat::t_type_expr>();
  }
  t_pragma_class_stat:i_class_stat{
    "#pragma"
    string body=end("\n");
  }
  t_include_class_stat:i_class_stat{
    "#include"
    string body=end("\n");
  }
  t_preproc_if_class_stat:i_class_stat{
    "#if"
    string body=end("\n");
  }
  t_preproc_else_class_stat:i_class_stat{
    "#else"
    string body=end("\n");
  }
  t_preproc_endif_class_stat:i_class_stat{
    "#endif"
    string body=end("\n");
  }
  t_define_class_stat:i_class_stat{
    "#define"
    string body=end("\n");
  }
  t_undef_class_stat:i_class_stat{
    "#undef"
    string body=end("\n");
  }
  t_sep_class_stat:i_class_stat{
    t_sep sep;
  }
  t_null_class_stat:i_class_stat{
    ";"
  }
  t_class_class_stat:i_class_stat{
    t_class body;
  }
  t_inl_file_stat{
    t_sep sep?;
    TAutoPtr<t_class> body;
  }
  vector<TAutoPtr<i_class_stat>> arr;
}