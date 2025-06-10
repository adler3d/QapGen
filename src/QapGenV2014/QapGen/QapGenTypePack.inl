#ifdef DEF_PRO_METATYPE_LIST
//`Настройка макросов окружения
  #define DEF_PRO_ADDBEG()
  #define DEF_PRO_ADDEND()
  #define DEF_PRO_MACRO_BLANK(A)
//`Сценарий 1a:
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  #define DEF_PRO_SELF(NAME)public:typedef NAME SelfClass;
  #define DEF_PRO_PARENT(NAME)public:typedef NAME ParentClass;static_assert(0,"ParentClass - bad idea!");
  #define DEF_PRO_OWNER(NAME)//public:typedef Sys_##NAME OwnerClass;
  DEF_PRO_STRUCT_INFO(DEF_PRO_SELF,DEF_PRO_PARENT,DEF_PRO_OWNER);
  #undef DEF_PRO_OWNER
  #undef DEF_PRO_PARENT
  #undef DEF_PRO_SELF
  //==Declaration Members==//
  public:
    #define DEF_PRO_ADDTYPE(TYPE)TType*p##TYPE;;
    DEF_PRO_METATYPE_LIST(DEF_PRO_ADDBEG,DEF_PRO_ADDTYPE,DEF_PRO_ADDEND);
    #undef DEF_PRO_ADDTYPE
  //==Declaration DoReset==//
    void DoReset()
    {
      #define DEF_PRO_ADDTYPE(TYPE)this->p##TYPE=nullptr;;
      DEF_PRO_METATYPE_LIST(DEF_PRO_ADDBEG,DEF_PRO_ADDTYPE,DEF_PRO_ADDEND);
      #undef DEF_PRO_ADDTYPE
    }
  //==Declaration Constructors==//
    #define DEF_PRO_CONSTRUCTOR(NAME)NAME(const SelfClass&ref){DoReset();oper_set(ref);}
    DEF_PRO_STRUCT_INFO(DEF_PRO_CONSTRUCTOR,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_CONSTRUCTOR
    #define DEF_PRO_CONSTRUCTOR(NAME)NAME(){DoReset();}
    DEF_PRO_STRUCT_INFO(DEF_PRO_CONSTRUCTOR,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_CONSTRUCTOR
    #define DEF_PRO_CONSTRUCTOR(NAME)NAME(IEnvRTTI&Env){DoReset();prepare(Env);}
    DEF_PRO_STRUCT_INFO(DEF_PRO_CONSTRUCTOR,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_CONSTRUCTOR
    #define DEF_PRO_CONSTRUCTOR(NAME)template<class TYPE>NAME(const TYPE&ref){DoReset();oper_set(ref);}
    DEF_PRO_STRUCT_INFO(DEF_PRO_CONSTRUCTOR,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_CONSTRUCTOR
  //==Declaration prepare==//
  template<class QAP_RTTI>
  void prepare(QAP_RTTI&Env)
  {
    #define DEF_PRO_ADDTYPE(TYPE)this->p##TYPE=Sys$$<TYPE>::GetRTTI((IEnvRTTI&)Env);
    DEF_PRO_METATYPE_LIST(DEF_PRO_ADDBEG,DEF_PRO_ADDTYPE,DEF_PRO_ADDEND);
    #undef DEF_PRO_ADDTYPE
  }
  //==Declaration oper_set==//
  void oper_set(const SelfClass&ref)
  {
    #define DEF_PRO_ADDTYPE(TYPE)this->p##TYPE=ref.p##TYPE;;
    DEF_PRO_METATYPE_LIST(DEF_PRO_ADDBEG,DEF_PRO_ADDTYPE,DEF_PRO_ADDEND);
    #undef DEF_PRO_ADDTYPE
  }
  template<class TYPE>
  void oper_set(const TYPE&ref)
  {
    #define DEF_PRO_ADDTYPE(TYPE)TEST(TYPE);;this->p##TYPE=ref.p##TYPE;;
    #define GET_TYPE(FIELD)std::remove_reference<decltype(FIELD)>::type
    #define TEST(FIELD)static_assert(std::is_same<GET_TYPE(this->p##FIELD),GET_TYPE(ref.p##FIELD)>::value,"no way");;
    DEF_PRO_METATYPE_LIST(DEF_PRO_ADDBEG,DEF_PRO_ADDTYPE,DEF_PRO_ADDEND);
    #undef TEST
    #undef GET_TYPE
    #undef DEF_PRO_ADDTYPE
  }
  void operator=(const SelfClass&ref){oper_set(ref);}
//`убиваем макросы определённые пользователем
  #undef DEF_PRO_MACRO_BLANK
  #undef DEF_PRO_ADDEND
  #undef DEF_PRO_ADDBEG
  #undef DEF_PRO_STRUCT_INFO
  #undef DEF_PRO_METATYPE_LIST
#endif //DEF_PRO_METATYPE_LIST//