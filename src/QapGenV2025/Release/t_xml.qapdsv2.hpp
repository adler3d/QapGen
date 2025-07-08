t_xml_scope{
  t_name{
    char A=any_char(gen_dips("azAZ")+"_$@");
    string B=any(gen_dips("azAZ09")+"_$@-.:")?;
  }
  t_sep{
    string body=any(" \r\n");
  }
  t_comment:i_node{
    "<!--"
    string body=end("-->");
  }
  t_text:i_node{
    t_raw:i_elem{
      string text=any(dip_inv("<"));
    }
    string text=str<vector<TAutoPtr<i_elem>>>();
  }
  t_start:i_node{
    t_string:i_value{
      "\""
      string value=str<vector<TAutoPtr<i_str_item>>>()?;
      "\""
    }
    t_number:i_value{
      string value=any(gen_dips("09"));
    }
    t_attr{
      string sep0=str<t_sep>();
      string name=str<t_name>();
      string sep1=str<t_sep>()?;
      "="
      string sep2=str<t_sep>()?;
      TAutoPtr<i_value> value;
    }
    t_slash{
      "/"
    }
    "<"
    string sep0=str<t_sep>()?;
    string tag=str<t_name>();
    vector<t_attr> attrs?;
    string sep1=str<t_sep>()?;
    string slash=str<TAutoPtr<t_slash>>()?;
    ">"
  }
  t_end:i_node{
    "</"
    string tag=str<t_name>();
    ">"
  }
  t_content{
    vector<TAutoPtr<i_node>> arr;
  }
}