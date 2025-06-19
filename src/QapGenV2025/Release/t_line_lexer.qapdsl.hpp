i_sep {
  virtual string make_code()const{QapDebugMsg("no way.");return "";}
}

t_sep_seq:i_sep {
  string body;
  {
    go_any(body," \t\r\n");
  }
  string make_code()const{
    return body;
  }
}

t_c_comment:i_sep {
  string body;
  {
    go_const("/*");
    go_end(body,"*/");
  }
  string make_code()const{
    return "/*"+body+"*/";
  }
}

t_cpp_comment:i_sep {
  string body;
  {
    go_const("//");
    go_end(body,"\n");
  }
  string make_code()const{
    return "//"+body+"\n";
  }
}

t_sep {
  t_impl {
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

t_str:i_expr {
  t_str_item body;
  {
    go_auto(body);
  }
}

t_char:i_expr {
  t_char_item body;
  {
    go_auto(body);
  }
}

t_num:i_expr {
  t_number body;
  {
    go_auto(body);
  }
}

t_name {
  t_keyword {
    string value;
    {
      go_any_str_from_vec(value,split("false,true,nullptr,this,struct,class,for,if,while,do,const,constexpr,else,operator,auto,continue,break,return,goto,virtual,override,public,private,protected,friend,template,typedef,using,namespace,decltype",","));
    }
  }
  t_impl {
    char A;
    string B;
    {
      M+=go_any_char(A,gen_dips("azAZ")+"_$@");
      O+=go_any(B,gen_dips("azAZ09")+"_$@");
    }
    string get()const{return CToS(A)+B;}
  }
  t_impl_ex {
    t_impl impl;
    {
      go_diff<t_keyword>(impl);
    }
  }
  string value;
  {
    go_str<t_impl_ex>(value);
  }
  string get()const{return value;}
}

t_id:i_expr {
  t_name body;
  {
    go_auto(body);
  }
}

t_sign:i_expr {
  char body;
  {
    go_any_char(body,"~|&=<>!:?;,.+-*/%^");
  }
}

t_soft_brackets:i_expr {
  vector<TAutoPtr<i_expr>> arr;
  {
    M+=go_const("(");
    O+=go_auto(arr);
    M+=go_const(")");
  }
}

t_hard_brackets:i_expr {
  vector<TAutoPtr<i_expr>> arr;
  {
    M+=go_const("[");
    O+=go_auto(arr);
    M+=go_const("]");
  }
}

t_curly_brackets:i_expr {
  vector<TAutoPtr<i_expr>> arr;
  {
    M+=go_const("{");
    O+=go_auto(arr);
    M+=go_const("}");
  }
}

t_param {
  t_sep sep;
  vector<TAutoPtr<i_expr>> body;
  {
    M+=go_auto(sep);
    M+=go_auto(body);
  }
}

t_line {
  t_name cmd;
  vector<t_param> params;
  {
    M+=go_auto(cmd);
    O+=go_auto(params);
  }
  vector<string> get_raw_params(/*IEnvRTTI&Env*/){
    vector<string> out;
    for(int i=0;i<params.size();i++){
      auto&ex=params[i];
      string mem;
      bool ok=save_obj(/*Env,*/ex.body,mem);
      QapAssert(ok);
      out.push_back(mem);
    }
    return std::move(out);
  }
}