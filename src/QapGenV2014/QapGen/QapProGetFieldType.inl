#ifdef DEF_PRO_GET_FIELD_TYPE
  #define DEF_PRO_MACRO_BLANK(A)
  {
    #define DEF_PRO_RESULT(NAME)typedef NAME ResultType;;
    #define DEF_PRO_CLASS(NAME)typedef NAME ClassType;;
    DEF_PRO_GET_FIELD_TYPE(DEF_PRO_RESULT,DEF_PRO_CLASS,DEF_PRO_MACRO_BLANK);
    #undef DEF_PRO_CLASS
    #undef DEF_PRO_RESULT
    ;;;
    #define DEF_PRO_USE(FILED)typedef decltype(GET_FIELD(ClassType,FILED)) realtype;
    #define GET_FIELD(TYPE,NAME)(((TYPE*)nullptr)->*(&TYPE::NAME))
    DEF_PRO_GET_FIELD_TYPE(DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK,DEF_PRO_USE)
    #undef GET_FIELD
    #undef DEF_PRO_USE
    ;;;
    typedef std::remove_reference<realtype>::type fieldtype;
    ;;;
    #define DEF_PRO_RESULT(A)"\""#A"\" != \""
    #define DEF_PRO_CLASS(A)#A":"
    #define DEF_PRO_FIELD(A)":"#A"\""
    static_assert(std::is_same<ResultType,fieldtype>::value,
      DEF_PRO_GET_FIELD_TYPE(DEF_PRO_RESULT,DEF_PRO_CLASS,DEF_PRO_FIELD)
    );
    #undef DEF_PRO_FIELD
    #undef DEF_PRO_CLASS
    #undef DEF_PRO_RESULT
  }
  #undef DEF_PRO_MACRO_BLANK
  #undef DEF_PRO_GET_FIELD_TYPE
#endif //DEF_PRO_GET_FIELD_TYPE