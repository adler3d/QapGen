QapDSL to QapDSL v2.
вот смотри код на QapDSL:
{
i_sep{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_sep_seq:i_sep{
  string body;
  {
    go_any(body," \t\r\n");
  }
  string make_code()const{
    return body;
  }
}

t_c_comment:i_sep{
  string body;
  {
    go_const("/*");
    go_end(body,"*/");
  }
  string make_code()const{
    return "/*"+body+"*/";
  }
}

t_cpp_comment:i_sep{
  string body;
  {
    go_const("//");
    go_end(body,"\n");
  }
  string make_code()const{
    return "//"+body+"\n";
  }
}

t_sep{
  t_impl{
    vector<TAutoPtr<i_sep>> arr;
    {
      go_auto(arr);
    }
    string make_code()const{
      string out="";
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->make_code();
      }
      return out;
    }
  }
  string value;
  {
    go_str<t_impl>(value);
  }
  string make_code()const{return value;}
}

t_str:i_expr{
  t_str_item body;
  {
    go_auto(body);
  }
}

t_char:i_expr{
  t_char_item body;
  {
    go_auto(body);
  }
}
}
он превращается вот в такой код на QapDSL v2:{
i_sep{
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_sep_seq:i_sep{
  string body=any(" \t\r\n");
  string make_code()const{
    return body;
  }
}

t_c_comment:i_sep{
  "/*"
  string body=end("*/");
  string make_code()const{
    return "/*"+body+"*/";
  }
}

t_cpp_comment=>i_sep{
  "//"
  string body=end("\n");
  string make_code()const{
    return "//"+body+"\n";
  }
}

t_sep{
  t_impl{
    vector<TAutoPtr<i_sep>> arr;
    string make_code()const{
      string out="";
      for(int i=0;i<arr.size();i++){
        out+=arr[i]->make_code();
      }
      return out;
    }
  }
  string value=str<t_impl>();
  string make_code()const{return value;}
}

t_str:i_expr{
  t_str_item body;
}

t_char:i_expr{
  t_char_item body;
}
}
обрати внимание, что если make_code нет в оригинале, то он не появляется, а если есть то копируется без изменений.
напиши какие преобразования надо делать чтобы выполнить конвертацию(QapDSL -> QapDSL v2).
а теперь тебе надо будет проделать такую же конвертацию(QapDSL -> QapDSL v2) для моего json-парсера. сейчас я тебе его скину.
---
2025.06.25 11:10:21.039
QapDSL:
t_c_comment:i_sep{
  string body;
  {
    go_const("/*");
    go_end(body,"*/");
  }
  string make_code()const{
    return "/*"+body+"*/";
  }
}
QapDSL v2:
t_c_comment:i_sep{
  "/*"
  string body=end("*/");
  string make_code()const{
    return "/*"+body+"*/";
  }
}
видишь что стало с go_const?
вот ты должен поступить так же. а теперь посмотри что стало с go_end и поступить так же.