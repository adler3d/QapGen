#ifdef DEF_BUILD_MACRO
  #include "../Macro/part5.h"
#else
//=====>>>>>part5

template<class SYS_TYPE>
class Sys$${
public:
  static const bool is_proxy=detail::has_ProxySys$$<SYS_TYPE>::value;
  typedef typename detail::GetProxyMetaType<SYS_TYPE,is_proxy>::type metatype;
  typedef typename SYS_TYPE type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::Do(RTTI);
  }
  static string GetFullName()
  {
    static_assert(is_proxy,"not implemented");
    return detail::GetProxyRTTI<SYS_TYPE,is_proxy>::GetFullName();
  }
};

template<>
class Sys$$<void>{
public:
  static const bool is_proxy=detail::has_ProxySys$$<void>::value;
  typedef detail::GetProxyMetaType<void,is_proxy>::type metatype;
  typedef void type;
  template<class QAP_RTTI>
  static metatype*GetRTTI(QAP_RTTI&RTTI)
  {
    return nullptr;
  }
  static string GetFullName()
  {
    QapDebugMsg("WTF?");
    return "void";
  }
};

//<<<<<=====part5
#endif //DEF_BUILD_MICRO//