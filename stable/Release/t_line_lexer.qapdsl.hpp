
/*
t_soft_brackets:i_expr{
  "("
  vector<TAutoPtr<i_expr>> arr?;
  ")"
}

t_hard_brackets:i_expr{
  "["
  vector<TAutoPtr<i_expr>> arr?;
  "]"
}

t_curly_brackets:i_expr{
  "{"
  vector<TAutoPtr<i_expr>> arr?;
  "}"
}

t_param{
  t_sep sep;
  vector<TAutoPtr<i_expr>> body;
}

t_line{
  t_name cmd;
  vector<t_param> params?;
  vector<string> get_raw_params(){
    vector<string> out;
    for(int i=0;i<params.size();i++){
      auto&ex=params[i];
      string mem;
      bool ok=save_obj(ex.body,mem);
      QapAssert(ok);
      out.push_back(mem);
    }
    return std::move(out);
  }
}
*/