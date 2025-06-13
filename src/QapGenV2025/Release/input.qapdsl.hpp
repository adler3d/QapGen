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