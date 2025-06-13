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
  //==Declaration Members==//
  public:
    #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)TYPE NAME;;
    #include "QapDefProVar.inl"
    #undef DEF_PRO_ADDVAR
  //==Declaration DoReset==//
  #if !defined(DEF_PRO_MANUAL_RESET)
  //`Сценарий 1c: используеться для инициализации классса
    public:
    void DoReset()
    {
      {
        #define DEF_PRO_USE(ParentClass)detail::TryDoReset<SelfClass>(this);
        DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
        #undef DEF_PRO_USE
      }
      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)(this->NAME)=(VALUE);
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)detail::FieldTryDoReset(this->NAME);
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)detail::FieldTryDoReset(this->NAME);
      //`#define DEF_PRO_MODE_MOV(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)
      #include "QapDefProVar.inl"
      #undef DEF_PRO_MODE_
      //`#undef DEF_PRO_MODE_MOV
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
    }
  #else
    #undef DEF_PRO_MANUAL_RESET
  #endif //DEF_PRO_MANUAL_RESET
  //==Declaration Constructors==//
  //`высший сорт говнокода на мокросах
  #if !defined(DEF_PRO_MANUAL_CONSTRUCTOR)&&!defined(DEF_PRO_AUTO_COPY)
  public:
    #define DEF_PRO_CONSTRUCTOR(NAME)NAME(const NAME&)=delete;NAME(){DoReset();};
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
    (
      #define DEF_PRO_USE(NAME)NAME&&_UberParent,
      DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK)
      #undef DEF_PRO_USE

      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)TYPE&&NAME,
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_CONSTRUCTOR() defined");
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_CONSTRUCTOR() defined");
      #define DEF_PRO_MODE_(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)
      #include "QapDefProVar.inl"
      #undef DEF_PRO_MODE_
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
    //`,
      noused_t=nullptr
    )
    #define DEF_PRO_USE(NAME):NAME(std::move(_UberParent))
    DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_USE
    {
      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)this->NAME=std::move(NAME);;
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_CONSTRUCTOR() defined");
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_CONSTRUCTOR() defined");
      #define DEF_PRO_MODE_(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)
      #include "QapDefProVar.inl"
      #undef DEF_PRO_MODE_
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
    }
    #undef DEF_PRO_AUTO_CONSTRUCTOR
  #endif //DEF_PRO_AUTO_CONSTRUCTOR
  //==Declaration Equal Operator==//
  #if defined(DEF_PRO_AUTO_EQUAL)
  public:
    #define DEF_PRO_NQUAL(NAME)bool operator!=(const NAME&_Right)const{return !SelfClass::operator==(_Right);}
    #define DEF_PRO_EQUAL(NAME)bool operator==(const NAME&_Right)const
    DEF_PRO_STRUCT_INFO(DEF_PRO_NQUAL,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_EQUAL,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_NQUAL
    #undef DEF_PRO_EQUAL
    {
      #define DEF_PRO_NORAML_ASSERT(ParentClass)struct hidden{static void foo(ParentClass(*)=(SelfClass*)nullptr){}};
      #define DEF_PRO_STATIC_ASSERT(ParentClass)//static_assert(std::is_base_of<ParentClass,SelfClass>::value,"is_base_of - fail");
      #define DEF_PRO_USE(ParentClass)DEF_PRO_NORAML_ASSERT(ParentClass);DEF_PRO_STATIC_ASSERT(ParentClass);
      DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
      #undef DEF_PRO_USE
      #undef DEF_PRO_STATIC_ASSERT
      #undef DEF_PRO_NORAML_ASSERT
      if(&_Right==this)return true;
      {
        #define DEF_PRO_USE(NAME)if(!NAME::operator==(_Right))return false;
        DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
        #undef DEF_PRO_USE
      }
      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)if(this->NAME!=_Right.NAME)return false;;
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_EQUAL() defined");
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_EQUAL() defined");
      #include "QapDefProVar.inl"
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
      return true;
    }
    #undef DEF_PRO_AUTO_EQUAL
  #endif //DEF_PRO_AUTO_EQUAL
  //==Declaration Copy Constructor==//
  #if defined(DEF_PRO_AUTO_COPY)
  public:
    #define DEF_PRO_COPY(NAME)NAME(const NAME&_Right){operator=(_Right);};NAME(){DoReset();};
    #define DEF_PRO_OPER_SET(NAME)void operator=(const NAME&_Right)
    DEF_PRO_STRUCT_INFO(DEF_PRO_COPY,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_OPER_SET,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_OPER_SET
    #undef DEF_PRO_COPY
    {
      #define DEF_PRO_NORAML_ASSERT(ParentClass)struct hidden{static void foo(ParentClass(*)=(SelfClass*)nullptr){}};
      #define DEF_PRO_STATIC_ASSERT(ParentClass)//static_assert(std::is_base_of<ParentClass,SelfClass>::value,"is_base_of - fail");
      #define DEF_PRO_USE(ParentClass)DEF_PRO_NORAML_ASSERT(ParentClass);DEF_PRO_STATIC_ASSERT(ParentClass);
      DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
      #undef DEF_PRO_USE
      #undef DEF_PRO_STATIC_ASSERT
      #undef DEF_PRO_NORAML_ASSERT
      if(&_Right==this)return;
      {
        #define DEF_PRO_USE(NAME)NAME::operator=(_Right);
        DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
        #undef DEF_PRO_USE
      }
      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)this->NAME=_Right.NAME;;
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_COPY() defined");
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_AUTO_COPY() defined");
      #include "QapDefProVar.inl"
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
    }
    #undef DEF_PRO_AUTO_COPY
  #endif //DEF_PRO_AUTO_COPY
  #if !defined(DEF_PRO_MANUAL_MOVE)
  public:
    #define DEF_PRO_MOVE(NAME)NAME(NAME&&_Right){operator=(std::move(_Right));}
    #define DEF_PRO_OPER_SET(NAME)void operator=(NAME&&_Right)
    DEF_PRO_STRUCT_INFO(DEF_PRO_MOVE,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    DEF_PRO_STRUCT_INFO(DEF_PRO_OPER_SET,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
    #undef DEF_PRO_OPER_SET
    #undef DEF_PRO_MOVE
    {
      #define DEF_PRO_NORAML_ASSERT(ParentClass)struct hidden{static void foo(ParentClass(*)=(SelfClass*)nullptr){}};
      #define DEF_PRO_STATIC_ASSERT(ParentClass)//static_assert(std::is_base_of<ParentClass,SelfClass>::value,"is_base_of - fail");
      #define DEF_PRO_USE(ParentClass)DEF_PRO_NORAML_ASSERT(ParentClass);DEF_PRO_STATIC_ASSERT(ParentClass);
      DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
      #undef DEF_PRO_USE
      #undef DEF_PRO_STATIC_ASSERT
      #undef DEF_PRO_NORAML_ASSERT
      if(&_Right==this)return;
      {
        #define DEF_PRO_USE(NAME)NAME::operator=(std::move(_Right));
        DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_USE,DEF_PRO_MACRO_BLANK);
        #undef DEF_PRO_USE
      }
      #define DEF_PRO_USE(A)A
      #define DEF_CLASS_NAME()DEF_PRO_STRUCT_INFO(DEF_PRO_USE,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK)
      #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)this->NAME=std::move(_Right.NAME);;
      #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
      #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(DEF_CLASS_NAME())"::"DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_MANUAL_MOVE() not defined");
      #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)static_assert(0,"bad field - \""DEF_PRO_TOTEXT2(DEF_CLASS_NAME())"::"DEF_PRO_TOTEXT2(NAME)"\". DEF_PRO_MANUAL_MOVE() not defined");
      #include "QapDefProVar.inl"
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_MODE_SYD
      #undef DEF_PRO_MODE_SYS
      #undef DEF_PRO_MODE_SET
      #undef DEF_PRO_MODE_DEF
      #undef DEF_PRO_ADDVAR
      #undef DEF_PRO_USE_IT
      #undef DEF_CLASS_NAME
      #undef DEF_PRO_USE
    }
  #else
    #undef DEF_PRO_MANUAL_MOVE
  #endif //DEF_PRO_MANUAL_MOVE
  //==Declaration GetRTTI==//
  public:
    struct ProxySys$$
    {
      /*typedef TTypeStruct metatype;
      static metatype*GetRTTI(IEnvRTTI&RTTI)
      {
        static const string Name=DEF_PRO_STRUCT_INFO(DEF_PRO_TOTEXT2,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK);;;
        TTypeStruct*Info=nullptr;
        if(RTTI.Register<SelfClass>(Info,Name)){
          return Info;
        }else{
          #define DEF_PRO_ON(NAME)_ON
          #define DEF_PRO_USE(NAME)NAME
          #define DEF_PRO_MODE()nullptr
          #define DEF_PRO_COMBINE(A,B)A##B
          #define DEF_PRO_COMBINE1(A,B)DEF_PRO_COMBINE(A,B)
          #define DEF_PRO_COMBINE2(A,B)DEF_PRO_COMBINE1(A,B)
          #define DEF_PRO_MODE_ON()Sys$$<ParentClass>::GetRTTI(RTTI)
            Info->SubType=DEF_PRO_COMBINE2(DEF_PRO_MODE,DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_ON,DEF_PRO_MACRO_BLANK))();
          #undef DEF_PRO_MODE_ON
          #define DEF_PRO_MODE_ON()Sys$$<OwnerClass>::GetRTTI(RTTI)
            Info->OwnType=DEF_PRO_COMBINE2(DEF_PRO_MODE,DEF_PRO_STRUCT_INFO(DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK,DEF_PRO_ON))();
          #undef DEF_PRO_MODE_ON
          #undef DEF_PRO_COMBINE2
          #undef DEF_PRO_COMBINE1
          #undef DEF_PRO_COMBINE
          #undef DEF_PRO_MODE
          #undef DEF_PRO_USE
          #undef DEF_PRO_ON
          #ifdef DEF_PRO_POOR_DESIGN
            Info->extInfo.PoorDesign=true;
            #undef DEF_PRO_POOR_DESIGN
          #endif //DEF_PRO_POOR_DESIGN
        }
        #define OFFSET_OF(NAME)int(&(((SelfClass*)nullptr)->*(&SelfClass::NAME)))
        #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)Info->AddMember##MODE(Sys$$<TYPE>::GetRTTI(RTTI),DEF_PRO_TOTEXT2(NAME),OFFSET_OF(NAME),#MODE,#VALUE);;
        #define DEF_PRO_ADDVAR(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_MODE_##MODE(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_DEF(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_SET(TYPE,NAME,MODE,VALUE,RESERVED)DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)
        #define DEF_PRO_MODE_SYS(TYPE,NAME,MODE,VALUE,RESERVED)Info->AddMember##MODE(0,nullptr,DEF_PRO_TOTEXT2(NAME),OFFSET_OF(NAME),#MODE);;
        #define DEF_PRO_MODE_SYD(TYPE,NAME,MODE,VALUE,RESERVED)Info->AddMember##MODE(0,nullptr,DEF_PRO_TOTEXT2(NAME),OFFSET_OF(NAME),#MODE);;
        #include "QapDefProVar.inl"
        #undef DEF_PRO_ADDVAR
        #undef DEF_PRO_MODE_SYD
        #undef DEF_PRO_MODE_SYS
        #undef DEF_PRO_MODE_SET
        #undef DEF_PRO_MODE_DEF
        #undef DEF_PRO_ADDVAR
        #undef DEF_PRO_USE_IT
        #undef OFFSET_OF
        {
          RTTI.OnRegEnd(Info);
        }
        {
          #ifdef DEF_PRO_NESTED
            #define DEF_PRO_NESTED_REG(TYPE)Info->AddNested(Sys$$<TYPE>::GetRTTI(RTTI));;
            DEF_PRO_NESTED(DEF_PRO_NESTED_REG);
            #undef DEF_PRO_NESTED_REG
            #undef DEF_PRO_NESTED
          #endif //DEF_PRO_NESTED//
        }
        Info->SelfTesting();
        return Info;
      }*/
      #ifdef DEF_PRO_NESTED
        #undef DEF_PRO_NESTED
      #endif //DEF_PRO_NESTED//
      static string GetFullName()
      {
        return DEF_PRO_STRUCT_INFO(DEF_PRO_TOTEXT2,DEF_PRO_MACRO_BLANK,DEF_PRO_MACRO_BLANK);;;
      }
      #ifdef DEF_PRO_FIELD_ID
        /*
        static int GetFieldId(int FIELD_OFFSET)
        {
          int Sys$$__field_id=0;
          #define OFFSET_OF(NAME)int(&(((SelfClass*)nullptr)->*(&SelfClass::NAME)))
          #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED){if(OFFSET_OF(NAME)==FIELD_OFFSET)return Sys$$__field_id;}Sys$$__field_id++;;
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
          #undef OFFSET_OF
          return -1;
        }
        struct GET_FIELD_ID{
          #define OFFSET_OF(NAME)int(&(((SelfClass*)nullptr)->*(&SelfClass::NAME)))
          #define DEF_PRO_USE_IT(TYPE,NAME,MODE,VALUE,RESERVED)static int NAME(){static const int id=GetFieldId(OFFSET_OF(NAME));return id;};;
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
          #undef OFFSET_OF
        };
        */
        #undef DEF_PRO_FIELD_ID
      #endif //DEF_PRO_FIELD_ID
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