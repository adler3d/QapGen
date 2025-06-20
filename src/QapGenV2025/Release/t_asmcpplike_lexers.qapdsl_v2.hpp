t_asmcpplike2016 {

  t_sign {
    char value=any("+-");
  }

  t_offset_impl {
    string sign=str<t_sign>;
    string num=any(gen_dips("09"));
  }

  t_num_impl {
    string sign=str<t_sign>;
    string num=any(gen_dips("09"));
  }

  t_num {
    string value=str<t_num_impl>;
  }

  t_char_param: i_param {
    t_char value;
  }

  t_str_param: i_param {
    t_str value;
  }

  t_num_param: i_param {
    t_num value;
  }

  t_arg {
    string value=any_str_from_vec(split("dest,src,a,b", ","));
  }

  t_ptr_reg_soft_param: i_param {
    "ptr("
    string arg=str<t_arg>;
    ")"
  }

  t_ptr_reg_raw_param: i_param {
    "ptr[reg["
    string reg=str<t_arg>;
    "]+raw["
    string raw=str<t_arg>;
    "]]"
  }

  t_reg_param: i_param {
    "reg["
    string arg=str<t_arg>;
    "]"
  }

  t_ptr_raw_param: i_param {
    "reg[raw["
    string arg=str<t_arg>;
    "]]"
  }

  t_mem_param: i_param {
    "mem["
    string arg=str<t_arg>;
    "]"
  }

  t_raw_param: i_param {
    "raw["
    string arg=str<t_arg>;
    "]"
  }

  t_ptr_reg_offset_param: i_param {
    "ptr["
    string reg=str<t_name>;
    string offset=str<t_offset_impl>;
    "]"
  }

  t_ptr_reg_param: i_param {
    "ptr["
    string reg=str<t_name>;
    "]"
  }

  t_ptr_num_param: i_param {
    "ptr["
    string num=str<t_num>;
    "]"
  }

  t_name_param: i_param {
    t_ext {
      "[\""
      string field=str<t_name>;
      "\"]"
    }
    t_name name;
    vector<t_ext> arr?;
  }

  t_cmd_stat: i_stat {
    string cmd=str<t_name>;
    "("
    vector<TAutoPtr<i_param>> arr?;
    ");"
  }

  t_block_stat: i_stat {
    "{"
    vector<TAutoPtr<i_stat>> arr?;
    "}"
  }

  t_sep_stat: i_stat {
    string value=str<t_sep>;
  }

  t_proc_item: i_item {
    "{proc("
    t_str name;
    "){"
    string sep=str<t_sep>?;
    vector<TAutoPtr<i_stat>> arr?;
    "}}"
  }

  t_field {
    "FIELD("
    t_str type;
    ","
    t_str name;
    ");"
    string sep=str<t_sep>?;
  }

  t_sep_item: i_item {
    string value=str<t_sep>;
  }

  t_struct_item: i_item {
    "{STRUCT("
    t_str name;
    "){"
    string sep=str<t_sep>?;
    vector<t_field> arr?;
    "}}"
  }

  "{"
  vector<TAutoPtr<i_item>> arr?;
  "}"
}
