а ты можешь вот эту шаблоноту переделать так
чтобы она подерживала вызов go_auto не только
дл€ интэрфэйсов полиморфных нод, но и дл€
самих наследников этих интерфэйсов.
сейчас € вызываю вот такую фигную:
t_struct_field_value{
  ...
  TAutoPtr<t_i_expr_impl::t_call_expr> expr;
  ...
  bool go(i_dev&dev){
    ...
    M+=dev.go_auto(expr); // смотри вот проблемный вызов.
    ...
    return ok;
  }
};
сейчас компил€тор залеза€ внутрь вызова пишет мне:
error C2338: go_for_item<TYPE> is not implemented!
note: выполн€етс€ компил€ци€ ссылки на экземпл€р шаблон функции "bool go_for_item<TYPE>(i_dev &,const TYPE &,...)"
note: выполн€етс€ компил€ци€ ссылки на экземпл€р шаблон функции "bool i_dev::go_auto<std::unique_ptr<t_i_expr_impl::t_call_expr,std::default_delete<_Ty>>>(TYPE &)"

вот код шаблоноты:
struct i_dev{
  ...
  template<class TYPE>
  bool go_auto(TYPE&ref){
    return go_for_item(*this,ref);
  }
  ...
};

template<class TYPE>
static bool go_for_poly(i_dev&dev,TAutoPtr<TYPE>&ref){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=TYPE::t_poly_impl::go_lt(dev,ref);
  }
  if(dev.isSave()){
    ok=TYPE::t_poly_impl::go_st(dev,ref);
  }
  return ok;
}

template<class TYPE>
static bool go_for_item(i_dev&dev,const TYPE&ref,...){
  static_assert(false,"go_for_item<TYPE> is not implemented!");
  return false;
}

template<class T,T v>struct detail_test_value{static const bool value=true;};

template<typename,typename=std::void_t<>>
struct detail_has_poly_impl:std::false_type{};

template<typename T>
struct detail_has_poly_impl<T,std::void_t<typename T::t_poly_impl>>:std::true_type{};

template<class TYPE>struct get_go_lt_param_type{
  template<class U>
  static U func(bool(*)(i_dev&,TAutoPtr<U>&));
  typedef decltype(func(&TYPE::t_poly_impl::go_lt)) type;
};

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
    !std::is_polymorphic<TYPE>::value/*||detail_go_lt_param_is_not_the_same_as_TYPE<TYPE>::value*/
    ,
    void*
  >::type=nullptr
){
  TYPE tmp;
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isSave()){
    if(!ref){
      ok=false;
      return ok;
    }
    auto*p=ref.get();
    ok=p->go(dev);
    return ok;
  }
  ok=tmp.go(dev);
  if(!ok)return ok;
  ref=std::make_unique<TYPE>(std::move(tmp));
  return ok;
}

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TAutoPtr<TYPE>&ref,
  typename std::enable_if<
    detail_test_value<
      bool(*)(i_dev&,TAutoPtr<TYPE>&),
      &TYPE::t_poly_impl::go_lt
    >::value,
    void*
  >::type=nullptr,
  bool(*pFunc)(i_dev&,TAutoPtr<TYPE>&)=&TYPE::t_poly_impl::go_lt,
  typename std::enable_if<std::is_polymorphic<TYPE>::value,void*>::type=nullptr
){
  return go_for_poly(dev,ref);
}

namespace detail{
  template<class TYPE>struct isTAutoPtr{static const bool value=false;};
  template<class TYPE>struct isTAutoPtr<TAutoPtr<TYPE>>{static const bool value=true;};
};

template<class TYPE>
static bool go_for_item(
  i_dev&dev,
  TYPE&ref,
  bool(TYPE::*pFunc)(i_dev&)=&TYPE::go,
  typename std::enable_if<!detail::isTAutoPtr<TYPE>::value,void*>::type=nullptr
){
  return (ref.*pFunc)(dev);
}

template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TYPE&ref){return true;}
template<class TYPE>
bool CheckTAutoPtrIsNotEmpty(TAutoPtr<TYPE>&ref){return ref.get();}

template<class TYPE>
static bool internal_go_for_vec_lt(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;;i++){
    t_fallback subscope(dev,__FUNCTION__);
    bool&ok=subscope.ok;
    TYPE tmp;
    ok=go_for_item(dev,tmp);
    if(!ok)break;
    QapAssert(CheckTAutoPtrIsNotEmpty(tmp));
    arr.push_back(std::move(tmp));
  }
  ok=!arr.empty();
  return ok;
}

template<class TYPE>
static bool internal_go_for_vec_st(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  for(int i=0;i<arr.size();i++){
    auto&ex=arr[i];
    ok=go_for_item(dev,ex);
    if(!ok)break;
  }
  return ok;
}

template<class TYPE>
static bool go_for_arr_lt(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_lt(dev,arr);
}

template<class TYPE>
static bool go_for_arr_st(i_dev&dev,vector<TYPE>&arr){
  return internal_go_for_vec_st(dev,arr);
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(arr.empty()){ok=false;return ok;}
  string out_mem;
  {
    {
      t_save_dev tmp_dev(dev.getEnv(),out_mem);
      bool ok=internal_go_for_vec_st(tmp_dev,arr);
      QapAssert(ok);
    }
    vector<TYPE> tmp_arr;
    {
      t_load_dev tmp_dev(dev.getEnv(),out_mem);
      bool ok=internal_go_for_vec_lt(tmp_dev,tmp_arr);
      QapAssert(ok);
    }
    string bin_bef;
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(arr),bin_bef);
    string bin_aft;
    QapPublicUberFullSaverBinMem(dev.getEnv(),QapRawUberObject(tmp_arr),bin_aft);
    bool err=bin_bef!=bin_aft;
    if(err){
      string txt_bef=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(arr));
      string txt_aft=QapPublicUberFullSaverProtoToStr(dev.getEnv(),QapRawUberObject(tmp_arr));
      string msg=two_text_diff(txt_aft,txt_bef);
      QapDebugMsg("diff:\n"+msg);
      QapDebugMsg("before:\n"+txt_bef);
      QapDebugMsg("after:\n"+txt_aft);
      return false;
    }
    //QapAssert(bin_bef==bin_aft);
  }
  ok=dev.go_blob(out_mem,out_mem.size());
  return ok;
#endif
}

template<class TYPE>
static bool go_for_item(i_dev&dev,vector<TYPE>&arr){
  t_fallback scope(dev,__FUNCTION__);
  bool&ok=scope.ok;
  if(dev.isLoad()){
    ok=go_for_arr_lt(dev,arr);
  }
  if(dev.isSave()){
    ok=go_for_arr_st(dev,arr);
  }
  return ok;
}