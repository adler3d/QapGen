t_asmcpplike2016{
  t_minus{{go_const("-");}}
  t_num_impl{string minus;string num;{O+=go_str<t_minus>(minus);M+=go_any(num,gen_dips("09"));}}
  t_num{string value;{go_str<t_num_impl>(value);}}
  t_char_param=>i_param{t_char value;{go_auto(value);}}
  t_str_param=>i_param{t_str value;{go_auto(value);}}
  t_num_param=>i_param{t_num value;{go_auto(value);}}
  t_ptr_reg_param=>i_param{
    string reg;{go_const("ptr[");go_str<t_name>(reg);go_const("]");}
  }
  t_ptr_num_param=>i_param{
    string num;{go_const("ptr[");go_str<t_num>(num);go_const("]");}
  }
  t_name_param=>i_param{
    t_ext{string field;{go_const("[\"");go_str<t_name>(field);go_const("\"]");}}
    t_name name;
    vector<t_ext> arr;
    {
      M+=go_auto(name);
      O+=go_auto(arr);
    }
  }

  t_cmd_stat=>i_stat{
    string cmd;
    vector<TAutoPtr<i_param>> arr;
    {
      M+=go_str<t_name>(cmd);
      M+=go_const("(");
      O+=go_vec(arr,",");
      M+=go_const(");");
    }
  }

  t_block_stat=>i_stat{
    vector<TAutoPtr<i_stat>> arr;
    {
      M+=go_const("{");
      O+=go_auto(arr);
      M+=go_const("}");
    }
  }

  t_sep_stat=>i_stat{string value;{go_str<t_sep>(value);}}

  t_proc_item=>i_item{
    t_str name;
    string sep;
    vector<TAutoPtr<i_stat>> arr;
    {
      M+=go_const("{proc(");
      M+=go_auto(name);
      M+=go_const("){");
      O+=go_str<t_sep>(sep);
      M+=go_auto(arr);
      M+=go_const("}}");
    }
  }

  t_field{
    t_str type;
    t_str name;
    string sep;
    {
      M+=go_const("FIELD(");
      M+=go_auto(type);
      M+=go_const(",");
      M+=go_auto(name);
      M+=go_const(");");
      O+=go_str<t_sep>(sep);
    }
  }

  t_sep_item=>i_item{string value;{go_str<t_sep>(value);}}

  t_struct_item=>i_item{
    t_str name;
    string sep;
    vector<t_field> arr;
    {
      M+=go_const("{STRUCT(");
      M+=go_auto(name);
      M+=go_const("){");
      O+=go_str<t_sep>(sep);
      M+=go_auto(arr);
      M+=go_const("}}");
    }
  }
  vector<TAutoPtr<i_item>> arr;
  {go_const("{");go_auto(arr);go_const("}");}
}