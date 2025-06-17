t_debug2{
  t_char_code=>i_code{
    i_char_item body;
    {
      go_const("'");
      go_auto(body);
      go_const("'");
    }
  }

  t_sign_code=>i_code{
    t_sign body;
    {
      go_auto(body);
    }
  }

  t_code{
    vector<i_code> arr;
    {
      go_auto(arr);
    }
  }
}
t_debug{
  t_class_def=>i_def{
    t_name name;
    t_name parent;
    {
      M+=go_auto(name);
      M+=go_const("=>");
      M+=go_auto(parent);
    }
  }
  t_struct_def=>i_def{
    t_name name;
    {
      M+=go_auto(name);
    }
  }
}
t_bar:i_b{}
t_baz:i_b{}
t_z{i_b b;{go_auto(b);}}
t_lol_test{
  t_more_levels{
    i_b{string nope;{go_any(nope,"nope");}}
    i_b fail_expected;
    {go_auto(fail_expected);}
  }
  t_more_levels ml;
  {go_auto(ml);}
}
t_lol_test2{
  t_more_levels{
    i_b fail_expected;
    {go_auto(fail_expected);}
  }
  t_more_levels ml;
  {go_auto(ml);}
}
t_foo{}
t_test20250613{
  t_fozy=>i_yyy{{go_const("Y");}}
  t_bazz=>i_yyy{{go_const("Z");}}
  t_fooa=>i_xxx{{go_const("A");}}
  t_barb=>i_xxx{{go_const("B");}}
  t_baz=>i_xxx{
    t_foo1=>i_xxx1{{go_const("foo");}}
    t_bar1=>i_xxx1{{go_const("bar");}}
    t_baz1=>i_xxx1{
      t_foo2=>i_xxx2{{go_const("foo2");}}
      t_bar2=>i_xxx2{{go_const("bar2");}}
      {go_const("baz");}
    }
    TAutoPtr<i_xxx1> x;
    {
      go_auto(x);
    }
  }
  TAutoPtr<i_xxx> x;
  TAutoPtr<i_yyy> y;
  {
    go_auto(x);
  }
}