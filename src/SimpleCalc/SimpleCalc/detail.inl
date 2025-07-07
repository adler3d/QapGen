namespace detail {
  struct yes_type{char padding[1];};
  struct no_type{char padding[8];};
	// select
	template<bool condition,typename true_t,typename false_t>struct select;
	template<typename true_t,typename false_t>struct select<true,true_t,false_t>{typedef true_t type;};
	template<typename true_t,typename false_t>struct select<false,true_t,false_t>{typedef false_t type;};
  // test
  template<class U,U x>struct test;
  //template<typename T>
  //struct has_DoReset{
  //  template<class U>
  //  static yes_type check(
  //    U*,
  //    test<void(U::*)(void),&U::DoReset>(*)=NULL
  //  );
  //  template<class U>
  //  static no_type check(...);
  //  static const bool value=sizeof(check<T>(0))==sizeof(yes_type);
  //};
  //template<typename T>
  //struct has_PostDoReset{
  //  template<class U>
  //  static yes_type check(
  //    U*,
  //    test<void(U::*)(void),&U::has_PostDoReset>(*)=NULL
  //  );
  //  template<class U>
  //  static no_type check(...);
  //  static const bool value=sizeof(check<T>(0))==sizeof(yes_type);
  //};
  //template<typename PARAM,typename TYPE,bool flag>struct Reset{static void Do(PARAM*,TYPE&);};
  //template<typename PARAM,typename TYPE>
  //struct Reset<PARAM,TYPE,false>{
  //  static void Do(PARAM*Param,TYPE&Ref){/*nothing*/}
  //};
  //template<typename PARAM,typename TYPE>
  //struct Reset<PARAM,TYPE,true>{
  //  static void Do(PARAM*Param,TYPE&Ref){Ref.DoReset(Param);}
  //};
  template<class TYPE>
  static void TryDoReset(void*){}
  template<class TYPE>
  static void TryDoReset(TYPE*Self,void(TYPE::ParentClass::*pDoReset)()=&TYPE::ParentClass::DoReset)
  {
    (Self->*pDoReset)();
  }
  /*
  template<typename T>
  struct has_self{
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      detail::test<void(*)(),&U::SysHasSelf>(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };*/
  /*template<typename T>
  struct has_self{
    __if_not_exists(T::Self){
      static const bool value=false;
    }
    __if_exists(T::Self){
      static const bool value=true;
      __if_exists(TSelfPtr){
          typedef decltype((*(T*)nullptr).Self) t_self_type;
          static_assert(
            std::is_same<TSelfPtr<T>,decltype((*(T*)nullptr).Self)>::value
            ||
            std::is_base_of<t_self_type::ptr_t,T>::value
            ,
            "must!"
          );
      }
    }
  };
  */
  template<typename T>
  struct has_ParentClass{
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ParentClass(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  /*template<class TYPE,bool flag=has_ParentClass<TYPE>::value>
  struct GetParentClassOf{
    typedef void type;
    static TType*GetRTTI(...){return nullptr;};
  };
  template<class TYPE>
  struct GetParentClassOf<TYPE,true>{
    typedef typename TYPE::ParentClass type;
    template<class QAP_RTTI>
    static TType*GetRTTI(QAP_RTTI&RTTI){
      return Sys$$<type>::GetRTTI(RTTI);
    };
  };*/
  template<typename T>
  struct has_ProxySys$$
  {
    template<class U>
    static no_type check(...);
    template<class U>
    static yes_type check(
      U*,
      typename U::ProxySys$$(*)=nullptr
    );
    static const bool value=sizeof(check<T>(nullptr))==sizeof(yes_type);
  };
  template<class TYPE>
  static void FieldTryDoReset(TYPE&p,...){}
  template<class TYPE,size_t SIZE>static void FieldTryDoReset(array<TYPE,SIZE>&arr){for(int i=0;i<SIZE;i++)FieldTryDoReset(arr[i]);}

  #define F(TYPE)static void FieldTryDoReset(TYPE&ref){ref=0;};;
  F(unsigned short)F(short)F(bool)F(int)F(size_t)F(float)F(double)F(char)F(uchar)
  #undef F

  template<typename TYPE,bool is_proxy>struct GetProxyMetaType;
  /*template<typename TYPE>
  struct GetProxyMetaType<TYPE,false>
  {
    typedef TType type;
  };*/
  template<typename TYPE>
  struct GetProxyMetaType<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
  };
  template<typename TYPE,bool is_proxy>
  struct GetProxyRTTI;
  template<typename TYPE>
  struct GetProxyRTTI<TYPE,true>
  {
    typedef typename TYPE::ProxySys$$::metatype type;
    template<class QAP_RTTI>
    static type*Do(QAP_RTTI&RTTI){return TYPE::ProxySys$$::GetRTTI(RTTI);}
    static string GetFullName(){return std::move(TYPE::ProxySys$$::GetFullName());}
  };


          //std::is_abstract<REG_TYPE>::value
          //std::alignment_of<REG_TYPE>::value;
  template<class TYPE,bool flag=std::is_abstract<TYPE>::value>
  struct QapAlignOf{
    struct proqap{
      TYPE f0;
      char f1;
      TYPE f2;
    };
    static const int value=sizeof(proqap)-2*sizeof(TYPE);
    
  };
  template<class TYPE>
  struct GetTemplParam
  {
    typedef void type;
  };
  template<template<class> class TEMPL,class TYPE>
  struct GetTemplParam<TEMPL<TYPE>>
  {
    typedef TYPE type;
  };
  /*
  template<class TYPE>
  class HasGetClassMetaSpecInfo{
  public:
    template<class T,T v>...
  public:
    template<class U>
    static yes_type test(
      U*,
      string(*)()=&U::GetClassMetaSpecInfo
    );
    template<class U>
    static no_type test(...);
    static const bool value=sizeof(test<TYPE>(0))==sizeof(yes_type);
  };*/
  /*
  template<class TYPE>
  struct TGetSpecInfoTool{
    __if_exists(TYPE::GetClassMetaSpecInfo){
      static string GetSpecInfo(){return TYPE::GetClassMetaSpecInfo();}
    }__if_not_exists(TYPE::GetClassMetaSpecInfo){
      static string GetSpecInfo(){return "";}
    }
  };*/
  /*
  template<class TYPE>
  static string GetSpecInfo(){return TGetSpecInfoTool<TYPE>::GetSpecInfo();}
  */

  //template<string(*A)()>struct GetSpecInfoTester{};
  //template<class TYPE>
  //static string GetSpecInfo(void(*)=nullptr,...){return "";}
  //template<class TYPE>
  //static string GetSpecInfo(void*,GetSpecInfoTester<&TYPE::GetClassMetaSpecInfo>(*)=nullptr)
  //{
  //  return TYPE::GetClassMetaSpecInfo();
  //}
  
  //template<class TYPE>
  //string GetSpecInfo(typename std::enable_if<!HasGetClassMetaSpecInfo<TYPE>::value,void>::type(*)=nullptr){
  //  return "";
  //}
  //template<class TYPE>
  // string GetSpecInfo(typename std::enable_if<HasGetClassMetaSpecInfo<TYPE>::value,void>::type(*)=nullptr){
  //  return TYPE::GetClassMetaSpecInfo();
  //}

  //template<class TYPE>
  //struct QapAlignOf<TYPE,true>{
  //  static const int value=4;
  //  static_assert(std::alignment_of<TYPE>::value==value,"WTF?");
  //};
};



