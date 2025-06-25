t_json{

t_true=>i_value{{go_const("true");}}
t_false=>i_value{{go_const("false");}}
t_null=>i_value{{go_const("null");}}

t_string=>i_value{
  t_raw=>i_item{string body;{go_any(body,dip_inv("\"\\\n"));}}
  t_fix=>i_item{char body='z';{go_const("\\");go_any_char(body,"\"\\/bfnrt");}}
  t_hex=>i_item{array(char,4) arr;{go_const("\\u");go_any_arr_char(arr,gen_dips("09afAF"));}}
  t_items{vector<TAutoPtr<i_item>> arr;{go_auto(arr);}}
  t_items body;
  {
    go_const("\"");
    go_auto(body);
    go_const("\"");
  }
}

t_number=>i_value{
  t_minus{{go_const("-");}}
  t_frac{
    string arr;
    {
      M+=go_const(".");
      M+=go_any(arr,gen_dips("09"));
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
  t_num=>i_int{
    char first='1';
    string num;
    {
      M+=go_any_char(first,gen_dips("19"));
      O+=go_any(num,gen_dips("09"));
    }
  }
  t_zero=>i_int{{go_const("0");}}
  TAutoPtr<t_minus> minus;
  TAutoPtr<i_int> val;
  TAutoPtr<t_frac> frac;
  TAutoPtr<t_exp> exp;
  {
    O+=go_auto(minus);
    M+=go_auto(val);
    O+=go_auto(frac);
    O+=go_auto(exp);
  }
}

t_sep{
  string body;
  {
    go_any(body," \t\r\n");
  }
}

t_empty_array=>i_value{
  t_sep sep;
  {
    M+=go_const("[");
    O+=go_auto(sep);
    M+=go_const("]");
  }
}

t_value{
  t_sep sep;
  TAutoPtr<i_value> body;
  {
    O+=go_auto(sep);
    M+=go_auto(body);
  }
}

t_comma_value{
  t_sep sep;
  t_value body;
  {
    O+=go_auto(sep);
    M+=go_const(",");
    M+=go_auto(body);
  }
}

t_array=>i_value{
  t_value first;
  vector<t_comma_value> arr;
  t_sep sep;
  {
    M+=go_const("[");
    M+=go_auto(first);
    O+=go_auto(arr);
    O+=go_auto(sep);
    M+=go_const("]");
  }
}

t_empty_object=>i_value{
  t_sep sep;
  {
    M+=go_const("{");
    O+=go_auto(sep);
    M+=go_const("}");
  }
}

t_pair{
  t_sep sep0;
  t_string key;
  t_sep sep1;
  t_value value;
  {
    O+=go_auto(sep0);
    M+=go_auto(key);
    O+=go_auto(sep1);
    M+=go_const(":");
    M+=go_auto(value);
  }
}

t_comma_pair{
  t_sep sep;
  t_pair body;
  {
    O+=go_auto(sep);
    M+=go_const(",");
    M+=go_auto(body);
  }
}

t_object=>i_value{
  t_pair first;
  vector<t_comma_pair> arr;
  t_sep sep;
  {
    M+=go_const("{");
    M+=go_auto(first);
    O+=go_auto(arr);
    O+=go_auto(sep);
    M+=go_const("}");
  }
}

}