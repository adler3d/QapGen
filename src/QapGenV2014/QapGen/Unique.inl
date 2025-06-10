/*class UniqueData{
public:
  typedef std::string data_t;
private:
  void operator=(const UniqueData&){QapAssert(0);};  //Ёкземпл€ры этого класса уникальны, копирование запрещенно.
  UniqueData(const UniqueData&){QapAssert(0);};      //Ёкземпл€ры этого класса уникальны, копирование запрещенно.
public:
#define MACRO_WEAK
#include "macro_scope.inl"
  MACRO_WEAK_PROC(on_init,(),()){DEF_LOG("add "+this->data);}
  MACRO_WEAK_PROC(on_free,(),()){DEF_LOG("del "+this->data);}
  MACRO_WEAK_PROC(on_move,(),()){DEF_LOG("mov "+this->data);}
#include "macro_scope.inl"
public:
 ~UniqueData(){if(*this){on_free();}}
  UniqueData(){}
  UniqueData(data_t&&data){this->data=data;on_init();}
  UniqueData(UniqueData&&_Right){oper_set(std::move(_Right));}
  void operator=(UniqueData&&_Right){oper_set(std::move(_Right));}
  void oper_set(UniqueData&&_Right){printf("mov %s[%p->%p]\n",_Right.data.c_str(),&_Right,this);data=std::move(_Right.data);_Right.data=data_t();}
public:
  data_t data;
  operator bool(){return !data.empty();}
};*/
class UniqueID{
private:
  static int GetID(){static int SysID=0;return ++SysID;}
private:
  void operator=(const UniqueID&){QapAssert(0);};  //Ёкземпл€ры этого класса уникальны, копирование запрещенно.
  UniqueID(const UniqueID&){QapAssert(0);};        //Ёкземпл€ры этого класса уникальны, копирование запрещенно.
public:
#define MACRO_WEAK
#include "macro_scope.inl"
  MACRO_WEAK_PROC(on_init,(),()){DEF_LOG("add "+IToS(this->id));}
  MACRO_WEAK_PROC(on_free,(),()){DEF_LOG("del "+IToS(this->id));}
  MACRO_WEAK_PROC(on_move,(int from,int to),(from,to)){DEF_LOG("mov "+IToS(from)+" -> "+IToS(to));}
#include "macro_scope.inl"                                                               
public:                                                                                
 ~UniqueID(){on_free();}
  UniqueID(){id=GetID();on_init();}
  UniqueID(UniqueID&&_Right){oper_set(std::move(_Right));}
  void operator=(UniqueID&&_Right){oper_set(std::move(_Right));}
  void oper_set(UniqueID&&_Right){on_move(_Right.id,id);}
public:
  int id;
  typedef UniqueID SelfClass;
  struct ProxySys$$
  {
    typedef TTypeStruct metatype;
    template<class QAP_RTTI>
    static metatype*GetRTTI(QAP_RTTI&RTTI)
    {
      string Name="UniqueID";
      TTypeStruct*Info=nullptr;
      if(RTTI.Register<SelfClass>(Info,Name)){
        return Info;
      }else{
        Info->SubType=nullptr;
        Info->OwnType=nullptr;
      }
      RTTI.OnRegEnd(Info);
      return Info;
    }
  };
};

//`
//`#define DEF_PRO_REG_TYPES_STRUCT(F)F(UniqueID)
//`//=====+++>>>>>TYPES(STRUCT)
//`#include "DefGenReg.inl"
//`//<<<<<+++=====TYPES(STRUCT)
//`