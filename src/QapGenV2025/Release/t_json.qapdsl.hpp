t_json{

  t_true=>i_value{"true"}
  t_false=>i_value{"false"}
  t_null=>i_value{"null"}
  typedef array<char,4> ARRAY4char;
  t_string=>i_value{
    t_raw=>i_item{string body=any(dip_inv("\"\\\n"));}
    t_fix=>i_item{"\\" char body=any_char("\"\\/bfnrt");}
    t_hex=>i_item{"\\u" ARRAY4char arr=any_arr_char(gen_dips("09afAF"));}
    t_items{vector<TAutoPtr<i_item>> arr;}
    "\""
    t_items body;
    "\""
  }

  t_number=>i_value{
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
  }

  t_sep{
    string body=any(" \t\r\n");
  }
  using " " as t_sep;

  t_value{
    TAutoPtr<i_value> body;
    " "?
  }

  t_comma_value{
    ","
    " "?
    t_value body;
    //" "?
  }

  t_array=>i_value{
    "["
    " "?
    t_value first?;
    vector<t_comma_value> arr?;
    "]"
    " "?
  }

  t_pair{
    t_string key;
    " "?
    ":"
    " "?
    t_value value;
  }

  t_comma_pair{
    ","
    " "?
    t_pair body;
  }

  t_object=>i_value{
    "{"
    " "?
    t_pair first?;
    vector<t_comma_pair> arr?;
    " "?
    "}"
    " "?
  }

}
