#undef F
static bool go_lt(i_dev&dev,TAutoPtr<SelfClass>&ref)
{
  typedef t_poly_tool::t_out_rec<SelfClass> t_out_rec;
  vector<t_out_rec> out_arr;
  static int out_arr_size=0;
  out_arr.reserve(out_arr_size);
  t_fallback scope(dev,__FUNCTION__);
  int count=0;
  int first_id=-1;
  auto&Env=dev.getEnv();
  static const string strbasetype=Sys$$<SelfClass>::GetRTTI(Env)->GetFullName();
  t_poly_tool::go_poly<SelfClass> solver_impl={
    out_arr,dev,ref,scope,count,first_id,strbasetype,Env
  };
  t_poly_impl&solver=(t_poly_impl&)solver_impl;
  solver.load<0>();
  out_arr_size=out_arr.size();
  return scope.ok;
}
static bool go_st(i_dev&dev,TAutoPtr<SelfClass>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(!std::is_polymorphic<SelfClass>::value)if(!ref){
    return false;
  }
  if(!ref)return false;
  QapAssert(ref);
  auto*p=ref.get();
  ok=p->go(dev);
  return ok;
}