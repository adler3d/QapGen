t_xml_scope{
  t_name{
    char A;
    string B;
    {
      M+=go_any_char(A,gen_dips("azAZ")+"_$@");
      O+=go_any(B,gen_dips("azAZ09")+"_$@-.:");
    }
  }
  t_sep{
    string body;
    {
      go_any(body," \r\n");
    }
  }
  t_comment=>i_node{
    string body;
    {
      go_const("<!--");
      go_end(body,"-->");
    }
  }
  t_text=>i_node{
    t_raw=>i_elem{
      string text;
      {
        go_any(text,dip_inv("<"));
      }
    }
    string text;
    {
      go_str<vector<TAutoPtr<i_elem>>>(text);
    }
  }
  t_start=>i_node{
    t_string=>i_value{
      string value;
      {
        M+=go_const("\"");
        O+=go_str<vector<TAutoPtr<i_str_item>>>(value);
        M+=go_const("\"");
      }
    }
    t_number=>i_value{
      string value;
      {
        go_any(value,gen_dips("09"));
      }
    }
    t_attr{
      string sep0;
      string name;
      string sep1;
      string sep2;
      TAutoPtr<i_value> value;
      {
        M+=go_str<t_sep>(sep0);
        M+=go_str<t_name>(name);
        O+=go_str<t_sep>(sep1);
        M+=go_const("=");
        O+=go_str<t_sep>(sep2);
        M+=go_auto(value);
      }
    }
    t_slash{{go_const("/");}}
    string sep0;
    string tag;
    vector<t_attr> attrs;
    string sep1;
    string slash;
    {
      M+=go_const("<");
      O+=go_str<t_sep>(sep0);
      M+=go_str<t_name>(tag);
      O+=go_auto(attrs);
      O+=go_str<t_sep>(sep1);
      O+=go_str<TAutoPtr<t_slash>>(slash);
      M+=go_const(">");
    }
  }
  t_end=>i_node{
    string tag;
    {
      go_const("</");
      go_str<t_name>(tag);
      go_const(">");
    }
  }
  t_content{
    vector<TAutoPtr<i_node>> arr;
    {
      go_auto(arr);
    }
  }
}