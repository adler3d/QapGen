t_example0{
t_bool{string s=any_str_from_vec(split("true,false",","));}
t_root{t_bool b;}
}

// с возможностью парсить еще и числа
t_example1{
t_bool:i_value{string s=any_str_from_vec(split("true,false",","));}
t_num:i_value{string s=any(gen_dips("09"));}
t_root{TAutoPtr<i_value> value;}
}

// с массивам разделенными запятыми
t_example2{
t_bool:i_value{string s=any_str_from_vec(split("true,false",","));}
t_num:i_value{string s=any(gen_dips("09"));}
t_arr:i_value{
  t_num_arr_val:i_arr_val{t_num n;}
  t_bool_arr_val:i_arr_val{t_bool b;}
  vector<TAutoPtr<i_arr_val>> arr=vec(",");// используем i_arr_val вместо i_value чтобы избежать рекурсии.
}
t_root{TAutoPtr<i_value> value;}
}

// с опциональными префиксами
t_example3{
t_bool:i_value{string s=any_str_from_vec(split("true,false",","));}
t_num:i_value{string s=any(gen_dips("09"));}
t_arr:i_value{
  t_num_arr_val:i_arr_val{t_num n;}
  t_bool_arr_val:i_arr_val{t_bool b;}
  vector<TAutoPtr<i_arr_val>> arr=vec(",");
}
t_optional_test:i_value{t_opt{"optional_prefix "} "(" TAutoPtr<t_opt> prefix?; t_num num; ")"}
t_root{TAutoPtr<i_value> value;}
}

// с комментариями
t_example4{
t_bool:i_value{string s=any_str_from_vec(split("true,false",","));}
t_num:i_value{string s=any(gen_dips("09"));}
t_arr:i_value{
  t_num_arr_val:i_arr_val{t_num n;}
  t_bool_arr_val:i_arr_val{t_bool b;}
  vector<TAutoPtr<i_arr_val>> arr=vec(",");
}
t_optional_test:i_value{t_opt{"optional_prefix "} "(" TAutoPtr<t_opt> prefix?; t_num num; ")"}
t_your_comment:i_value{
  "/*"
  string body=end("*/");
}
t_root{TAutoPtr<i_value> value;}
}