//`Регистрируем POD типы
#ifdef DEF_PRO_REG_TYPES_POD
  #define RegType(TYPE)\
  template<>\
  class Sys$$<TYPE>{\
  public:\
    typedef TTypeSys metatype;\
    typedef TYPE type;\
    template<class QAP_RTTI>\
    static metatype*GetRTTI(QAP_RTTI&RTTI){\
      metatype*Info=nullptr;\
      string Name=#TYPE;\
      if(RTTI.Register<type>(Info,Name))return Info;\
      Info->BinIO=THeadBinIO<type>::Get();\
      Info->TxtIO=THeadCppIO<type>::Get();\
      Info->Info.Size=sizeof(type);\
      RTTI.OnRegEnd(Info);\
      return Info;\
    };\
    static string GetFullName()\
    {\
      return #TYPE;\
    }\
  };;
  DEF_PRO_REG_TYPES_POD(RegType);
  #undef RegType
  #undef DEF_PRO_REG_TYPES_POD
#endif //DEF_PRO_REG_TYPES_POD//