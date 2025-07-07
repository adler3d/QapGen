t_asmcpplike2016{
  t_minus{
    "-"
  }
  t_num_impl{
    string minus=str<t_minus>()?;
    string num=any(gen_dips("09"));
  }
  t_num{
    string value=str<t_num_impl>();
  }
  t_char_param:i_param{
    t_char value;
  }
  t_str_param:i_param{
    t_str value;
  }
  t_num_param:i_param{
    t_num value;
  }
  t_ptr_reg_param:i_param{
    "ptr["
    string reg=str<t_name>();
    "]"
  }
  t_ptr_num_param:i_param{
    "ptr["
    string num=str<t_num>();
    "]"
  }
  t_name_param:i_param{
    t_ext{
      "[\""
      string field=str<t_name>();
      "\"]"
    }
    t_name name;
    vector<t_ext> arr?;
  }
  t_cmd_stat:i_stat{
    string cmd=str<t_name>();
    "("
    vector<TAutoPtr<i_param>> arr=vec(",")?;
    ");"
  }
  t_block_stat:i_stat{
    "{"
    vector<TAutoPtr<i_stat>> arr?;
    "}"
  }
  t_sep_stat:i_stat{
    string value=str<t_sep>();
  }
  t_proc_item:i_item{
    "{proc("
    t_str name;
    "){"
    string sep=str<t_sep>()?;
    vector<TAutoPtr<i_stat>> arr;
    "}}"
  }
  t_field{
    "FIELD("
    t_str type;
    ","
    t_str name;
    ");"
    string sep=str<t_sep>()?;
  }
  t_sep_item:i_item{
    string value=str<t_sep>();
  }
  t_struct_item:i_item{
    "{STRUCT("
    t_str name;
    "){"
    string sep=str<t_sep>()?;
    vector<t_field> arr;
    "}}"
  }
  "{"
  vector<TAutoPtr<i_item>> arr;
  "}"
}