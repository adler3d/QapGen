t_simple_calc{
  t_term{
    TAutoPtr<i_term> value;
    {
      go_auto(value);
    }
  }
  t_number=>i_term{
    t_ext{
      string v;
      {
        go_const(".");
        go_any(v,gen_dips("09"));
      }
    }
    t_impl{
      string bef;
      TAutoPtr<t_ext> ext;
      {
        M+=go_any(bef,gen_dips("09"));
        O+=go_auto(ext);
      }
    }
    string value;
    {
      go_str<t_impl>(value);
    }
  }
  t_divmul{
    t_elem{
      string oper;
      t_term expr;
      {
        go_any_str_from_vec(oper,split("/,*",","));
        go_auto(expr);
      }
    }
    t_term first;
    vector<t_elem> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }
  t_addsub{
    t_elem{
      string oper;
      t_divmul expr;
      {
        go_any_str_from_vec(oper,split("+,-",","));
        go_auto(expr);
      }
    }
    t_divmul first;
    vector<t_elem> arr;
    {
      M+=go_auto(first);
      O+=go_auto(arr);
    }
  }
  t_scope=>i_term{
    t_addsub value;
    {
      go_const("(");
      go_auto(value);
      go_const(")");
    }
  }
  t_addsub value;
  {
    go_auto(value);
  }
}