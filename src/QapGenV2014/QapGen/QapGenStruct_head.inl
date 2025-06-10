//`#include "QapGenStruct.inl"
//`multy pass source file
#ifdef DEF_PRO_VARIABLE
//`Настройка макросов окружения
  #define DEF_PRO_MACRO_BLANK(A)
  #define DEF_PRO_TOTEXT0(NAME)#NAME
  #define DEF_PRO_TOTEXT1(NAME)DEF_PRO_TOTEXT0(NAME)
  #define DEF_PRO_TOTEXT2(NAME)DEF_PRO_TOTEXT1(NAME)
//`Сценарий 1a: Используеться для автоматизации работы с полями сущности
  //==Declaration SelfClass,ParentClass,OwnerClass==//
  #define DEF_PRO_OWNER(NAME)public:typedef NAME OwnerClass;
  DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK,DEF_PRO_OWNER);
  #undef DEF_PRO_OWNER
  #define DEF_PRO_SELF(NAME)public:typedef NAME SelfClass;
  #define DEF_PRO_PARENT(NAME)public:typedef NAME ParentClass;
  DEF_PRO_STRUCT_INFO(DEF_PRO_SELF,DEF_PRO_PARENT,DEF_PRO_MACRO_BLANK);
  #undef DEF_PRO_PARENT
  #undef DEF_PRO_SELF
  #ifndef DEF_PRO_NO_NEXTOWNER
    #define DEF_PRO_SELF(NAME)public:typedef NAME NextOwnerClass;
    DEF_PRO_STRUCT_INFO(DEF_PRO_SELF,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK);
    #undef DEF_PRO_SELF
    #undef DEF_PRO_NO_NEXTOWNER
  #endif //DEF_PRO_NO_NEXTOWNER
  //==Declaration Members==//
  public:
    #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)TYPE NAME;;
    #include "QapDefProVar.inl"
    #undef DEF_PRO_ADDVAR
  //==Declaration DoReset==//
  #if !defined(DEF_PRO_MANUAL_RESET)
  //`Сценарий 1c: используеться для инициализации классса
    public:
    void DoReset();
  #else
    #undef DEF_PRO_MANUAL_RESET
  #endif //DEF_PRO_MANUAL_RESET
  //==Declaration Constructors==//
  //`высший сорт говнокода на мокросах
  #if !defined(DEF_PRO_MANUAL_CONSTRUCTOR)&&!defined(DEF_PRO_AUTO_COPY)
  public:
    #define DEF_PRO_CONSTRUCTOR(NAME)NAME(const NAME&)=delete;NAME();
    DEF_PRO_STRUCT_INFO(DEF_PRO_CONSTRUCTOR,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_CONSTRUCTOR
  #else
    #undef DEF_PRO_MANUAL_CONSTRUCTOR
  #endif //DEF_PRO_MANUAL_CONSTRUCTOR
  #if defined(DEF_PRO_AUTO_CONSTRUCTOR)
  public:
    typedef nullptr_t noused_t;
    #define DEF_PRO_USE(NAME)NAME
    DEF_PRO_STRUCT_INFO(DEF_PRO_USE,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_USE
    ;
    #define DEF_PRO_USE(NAME);
    DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_USE
    ;
    #undef DEF_PRO_AUTO_CONSTRUCTOR
  #endif //DEF_PRO_AUTO_CONSTRUCTOR
  //==Declaration Equal Operator==//
  #if defined(DEF_PRO_AUTO_EQUAL)
  public:
    #define DEF_PRO_NQUAL(NAME)bool operator!=(const NAME&_Right)const;
    #define DEF_PRO_EQUAL(NAME)bool operator==(const NAME&_Right)const
    DEF_PRO_STRUCT_INFO(DEF_PRO_NQUAL,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_EQUAL,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_NQUAL
    #undef DEF_PRO_EQUAL
    ;
    #undef DEF_PRO_AUTO_EQUAL
  #endif //DEF_PRO_AUTO_EQUAL
  //==Declaration Copy Constructor==//
  #if defined(DEF_PRO_AUTO_COPY)
  public:
    #define DEF_PRO_COPY(NAME)NAME(const NAME&_Right);
    #define DEF_PRO_OPER_SET(NAME)void operator=(const NAME&_Right)
    DEF_PRO_STRUCT_INFO(DEF_PRO_COPY,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_OPER_SET,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_OPER_SET
    #undef DEF_PRO_COPY
    ;
    #undef DEF_PRO_AUTO_COPY
  #endif //DEF_PRO_AUTO_COPY
  #if !defined(DEF_PRO_MANUAL_MOVE)
  public:
    #define DEF_PRO_MOVE(NAME)NAME(NAME&&_Right);
    #define DEF_PRO_OPER_SET(NAME)void operator=(NAME&&_Right)
    DEF_PRO_STRUCT_INFO(DEF_PRO_MOVE,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_OPER_SET,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_OPER_SET
    #undef DEF_PRO_MOVE
    ;
  #else
    #undef DEF_PRO_MANUAL_MOVE
  #endif //DEF_PRO_MANUAL_MOVE
  //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      typedef TTypeStruct metatype;
      template<class QAP_RTTI>
      static metatype*GetRTTI(QAP_RTTI&RTTI)
      ;
      static string GetFullName();
      static int GetFieldId(int FIELD_OFFSET);
      #ifdef DEF_PRO_NESTED
        #undef DEF_PRO_NESTED
      #endif //DEF_PRO_NESTED//
      struct GET_FIELD_ID{
        #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)static int NAME();
        #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)
        #include "QapDefProVar.inl"
        #undef DEF_PRO_ADDVAR
        #undef DEF_PRO_MODE_SYD
        #undef DEF_PRO_MODE_SYS
        #undef DEF_PRO_MODE_SET
        #undef DEF_PRO_MODE_DEF
        #undef DEF_PRO_ADDVAR
        #undef DEF_PRO_USE_IT
      };
    };
  public:
//`убиваем возмжно системные макросы
//`  #undef ADDSYS
//`  #undef ADDVEC
//`  #undef ADDLINK
//`  #undef ADDVAR
//`убиваем макросы окружения
  #undef DEF_PRO_MACRO_BLANK
  #undef DEF_PRO_TOTEXT2
  #undef DEF_PRO_TOTEXT1
  #undef DEF_PRO_TOTEXT0
//`убиваем макросы определённые пользователем
  #undef DEF_PRO_STRUCT_INFO
  #undef DEF_PRO_VARIABLE
#endif //DEF_PRO_VARIABLE//