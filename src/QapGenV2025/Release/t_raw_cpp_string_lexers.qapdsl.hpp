t_number{
  string body=any(gen_dips("09"));
}

i_str_item{
  virtual string get_code()const{ QapDebugMsg("no way."); return ""; }
  virtual string get_value()const{ QapDebugMsg("no way."); return ""; }
}

t_str_item_raw=>i_str_item{
  string body=any(dip_inv("\"\\\n"));
  string get_code()const{return body;}
  string get_value()const{return body;}
}

t_str_item_hex=>i_str_item{
  "\\x"
  array(char,2) body=any_arr_char(gen_dips("09afAF"));
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    return CToS(n);
  }
}

t_str_item_num=>i_str_item{
  "\\u"
  array(char,2) body=any_arr_char(gen_dips("09"));
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    return CToS(n);
  }
}
t_str_item_fix=>i_str_item{
  "\\"
  char body=any_char("tfbrn\\\"\'"+gen_dips("07"));
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=get_code();
    BinString str=code;
    return str.data;
  }
}

t_str_item{
  t_impl{
    "\""
    vector<TAutoPtr<i_str_item>> arr;
    "\""
    string get_code()const{
      string out;
      for(int i=0;i<arr.size();i++) out+=arr[i]->get_code();
      return out;
    }
    string get_value()const{
      string out;
      for(int i=0;i<arr.size();i++) out+=arr[i]->get_value();
      return out;
    }
  }
  string value=str<t_impl>();
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl");return "";}
}

i_char_item{
  virtual string get_code()const{QapDebugMsg("no way.");return "";}
  virtual string get_value()const{QapDebugMsg("no way.");return "";}
}

t_char_item_raw=>i_char_item{
  string body=any(dip_inv("'\\\n"));
  string get_code()const{return body;}
  string get_value()const{return body;}
}

t_char_item_hex=>i_char_item{
  "\\x"
  array(char,2) body=any_arr_char(gen_dips("09afAF"));
  string get_code()const{return "\\x"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=HToI_raw(code);
    return CToS(n);
  }
}

t_char_item_num=>i_char_item{
  "\\u"
  array(char,4) body=any_arr_char(gen_dips("09"));
  string get_code()const{return "\\u"+CToS(body[0])+CToS(body[1]);}
  string get_value()const{
    string code;
    code.push_back(body[0]);
    code.push_back(body[1]);
    auto n=SToI(code);
    return CToS(n);
  }
}

t_char_item_fix=>i_char_item{
  "\\"
  char body=any_char("tfbrn\\\"\'"+gen_dips("07"));
  string get_code()const{return "\\"+CToS(body);}
  string get_value()const{
    string code=get_code();
    BinString str=code;
    return str.data;
  }
}
t_char_item{
  t_impl{
    "'"
    TAutoPtr<i_char_item> body;
    "'"
    string get_code()const{return "'"+body->get_code()+"'";}
    string get_value()const{return body->get_value();}
  }
  string value=str<t_impl>();
  string get_code()const{return value;}
  string get_value()const{QapDebugMsg("no impl"); return "";}
}
