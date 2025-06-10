#if defined(MACRO_WEAK)
  #define MACRO_WEAK_PROC(NAME,HEAD,PARAM)void NAME##HEAD{weak_##NAME<0>##PARAM;};;;template<int>void weak_##NAME##HEAD
  #define MACRO_WEAK_FUNC(TYPE,NAME,HEAD,PARAM)TYPE NAME##HEAD{return weak_##NAME<0>##PARAM;};;;template<int>TYPE weak_##NAME##HEAD
  #define MACRO_WEAK_OFF
  #define MACRO_WEAK_GOTO_EXIT
  #undef MACRO_WEAK
#endif //MACRO_WEAK

#if defined(MACRO_WEAK_OFF)&&!defined(MACRO_WEAK_GOTO_EXIT)
  #undef MACRO_WEAK_FUNC
  #undef MACRO_WEAK_PROC
  #define MACRO_WEAK_GOTO_EXIT
  #undef MACRO_WEAK_OFF
#endif //MACRO_WEAK_OFF

#if !defined(MACRO_WEAK_GOTO_EXIT)
  static_assert(0,"\"MACRO_WEAK_GOTO_EXIT\" - no defined");
#else
  #undef MACRO_WEAK_GOTO_EXIT
#endif //MACRO_WEAK_GOTO_EXIT