#ifdef DEF_BUILD_MACRO
  #include "../Macro/ptr.h"
#else
//=====>>>>>ptr
#define DEF_LOG(MSG)//Out(MSG)
#define MACRO_OFF(CODE)
#include "Unique.inl"

template<typename TYPE>class TServerPtr;
class TProduct;
class TRTTIProduct;
class IAllocator;

template<typename TYPE>
class TClientPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TClientPtr<TYPE>&){QapAssert(0);};  
  TClientPtr<TYPE>(const TClientPtr<TYPE>&){QapAssert(0);};    
public:
  void init(){TServerPtr<TYPE>::init_client(this);};
  void free(){TServerPtr<TYPE>::free_client(this);};
  void oper_set(TServerPtr<TYPE>*p)
  {
    if(ptr)ptr->Off(this);if(p)p->On(this);
  };
  void oper_set(TClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if(ptr)ptr->Off(this);
    if(_Right){_Right.ptr->On(this);
    _Right.ptr->Off(&_Right);}
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  TClientPtr<TYPE>*next;
  TClientPtr<TYPE>*prev;
 ~TClientPtr(){free();}
  TClientPtr(){init();}
  TClientPtr(TServerPtr<TYPE>*p){init();oper_set(p);}
  TClientPtr(TClientPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
  void operator=(TServerPtr<TYPE>*p){oper_set(p);}
  void operator=(TClientPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  operator bool()const{return ptr;}
};

template<typename TYPE>
class THardClientPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const THardClientPtr<TYPE>&){QapAssert(0);};  
  THardClientPtr<TYPE>(const THardClientPtr<TYPE>&){QapAssert(0);};    
public:
  void init(){TServerPtr<TYPE>::init_client(this);};
  void free(){TServerPtr<TYPE>::free_client(this);};
  void oper_set(TServerPtr<TYPE>*p)
  {
    if(ptr)ptr->Off(this);if(p)p->On(this);
  };
  void oper_set(THardClientPtr<TYPE>&&_Right)
  {
    UID=std::move(_Right.UID);
    if(ptr)ptr->Off(this);
    if(_Right){_Right.ptr->On(this);
    _Right.ptr->Off(&_Right);}
  };
public:
  TServerPtr<TYPE>*ptr;
  UniqueID UID;
  THardClientPtr<TYPE>*next;
  THardClientPtr<TYPE>*prev;
 ~THardClientPtr(){free();}
  THardClientPtr(){init();}
  THardClientPtr(TServerPtr<TYPE>*p){init();oper_set(p);}
  THardClientPtr(THardClientPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
  void operator=(TServerPtr<TYPE>*p){oper_set(p);}
  void operator=(THardClientPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  operator bool()const{return ptr;}
};

template<typename TYPE>
class TServerPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TServerPtr<TYPE>&){QapAssert(0);}; //This class can not be copied
  TServerPtr(const TServerPtr<TYPE>&){QapAssert(0);};     //This class can not be copied
private:
  template<class U>
  static void unsafe_init_client(U*p){p->ptr=nullptr;p->next=nullptr;p->prev=nullptr;};
  template<class U>
  static void unsafe_free_client(U*p){if(p->ptr){p->ptr->Off(p);}};
public:
  static void init_client(TClientPtr<TYPE>*p){unsafe_init_client(p);};
  static void free_client(TClientPtr<TYPE>*p){unsafe_free_client(p);};
  static void init_client(THardClientPtr<TYPE>*p){unsafe_init_client(p);};
  static void free_client(THardClientPtr<TYPE>*p){unsafe_free_client(p);};
public:
  ptr_t*ptr;
  UniqueID UID;
  int SaveID;
  int RefCount;
  TClientPtr<TYPE> entry_point;
  int HardCount;
  THardClientPtr<TYPE> hard_point;
  ~TServerPtr(){if(entry_point||hard_point){serv_off();}free();}
  TServerPtr(){init();}
  TServerPtr(ptr_t*p){init();oper_set(p);}
  TServerPtr(TServerPtr<TYPE>&&_Right){init();oper_set(std::move(_Right));}
public:
  void operator=(ptr_t*p){oper_set(p);}
  void operator=(TServerPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
public:
  void oper_set(ptr_t*p){
    if(p==ptr)return;
    serv_off();serv_on(p);
  }
  void oper_set(TServerPtr<TYPE>&&_Right){
    serv_off();
    serv_on(_Right.ptr);
    _Right.ForEach(&_Right.entry_point,redirect(this));
    _Right.ForEach(&_Right.hard_point,redirect(this));
    _Right.serv_off();
    entry_point.UID=std::move(_Right.entry_point.UID);
    UID=std::move(_Right.UID);
  }
private:
  MACRO_OFF(static UniqueID GetUID(const std::string&name){static int Sys_UID=0;return std::move(UniqueID(name+IToS(++Sys_UID)));})
  void init(){ptr=nullptr;RefCount=0;HardCount=0;SaveID=0;}
  void free(){ptr=nullptr;}
  ptr_t*get()const{return ptr;}
  void serv_off()
  {
    QapAssert(!SaveID);
    if(hard_point)
    {
      QapAssert(1==HardCount);
      hard_point=nullptr;
    };
    if(entry_point)
    {
      ForEach(&entry_point,Unmount);
      ptr=nullptr;
      entry_point=nullptr;
    }
    QapAssert(!ptr);
  }
  void serv_on(ptr_t*p)
  {
    MACRO_OFF(if(!UID)UID=GetUID("server");)
    ptr=p;
    On(&entry_point);
    On(&hard_point);
  }
  static void unsafe_insert_me(TClientPtr<TYPE>*p){
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(TClientPtr<TYPE>*p){
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
  static void unsafe_insert_me(THardClientPtr<TYPE>*p){
    p->next->prev=p;
    p->prev->next=p;
  }
  static void unsafe_remove_me(THardClientPtr<TYPE>*p){
    p->next->prev=p->prev;
    p->prev->next=p->next;
  }
public:
  void On(TClientPtr<TYPE>*p){_On(p);}
  void Off(TClientPtr<TYPE>*p){_Off(p);}
  void On(THardClientPtr<TYPE>*p){_On(p);}
  void Off(THardClientPtr<TYPE>*p){_Off(p);}
private:
  template<class U,bool flag>struct Hidden;
  template<class U>
  struct Hidden<U,true>{
    static int&get_counter(TServerPtr<TYPE>*self){return self->RefCount;}
    static U&get_point(TServerPtr<TYPE>*self){return self->entry_point;}
  };
  template<class U>
  struct Hidden<U,false>{
    static int&get_counter(TServerPtr<TYPE>*self){return self->HardCount;}
    static U&get_point(TServerPtr<TYPE>*self){return self->hard_point;}
  };
  template<template<class> class T,class U>
  int&get_counter(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_counter(this);
  }
  template<template<class> class T,class U>
  T<U>&get_point(T<U>*)
  {
    return Hidden<T<U>,std::is_same<T<U>,TClientPtr<U>>::value>::get_point(this);
  }
  template<class U>
  void _On(U*p){
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(!p->ptr);
    p->ptr=this;
    if(p==&point){
      MACRO_OFF(if(!p->UID)p->UID=UniqueID(StrReplace(UID.data,"server","client")+"ep");)
      p->next=p;
      p->prev=p;
    }else{
      QapAssert(point);
      MACRO_OFF(if(!p->UID)p->UID=GetUID("client");)
      p->next=point.next;
      p->prev=&point;
      unsafe_insert_me(p);
      MACRO_OFF(printf("set %s=&%s\n",p->UID.data.c_str(),UID.data.c_str());)
    }
    counter++;
  }
  template<class U>
  void _Off(U*p){
    auto&point=get_point(p);
    auto&counter=get_counter(p);
    QapAssert(p);
    QapAssert(p->ptr);
    unsafe_remove_me(p);
    MACRO_OFF(printf("set %s=nullptr\n",p->UID.data.c_str());)
    p->ptr=nullptr;
    p->next=nullptr;
    p->prev=nullptr;
    counter--;
  }
public:
  operator bool()const{return ptr;};
private:
  static void Unmount(TClientPtr<TYPE>*&it){auto*next=it->next;*it=nullptr;it=next;}
  class redirect{
  public:
    TServerPtr<TYPE>*target;
    redirect(TServerPtr<TYPE>*target):target(target){}
    void operator()(TClientPtr<TYPE>*&it){
      auto*next=it->next;
      *it=target;
      it=next;
    }
    void operator()(THardClientPtr<TYPE>*&it){
      auto*next=it->next;
      *it=target;
      it=next;
    }
  };
  template<typename U,typename FUNCTOR>
  void ForEach(U*scope,FUNCTOR&func){
    auto&point=get_point(scope);
    if(!point)return;
	  U*it=point.next;
    while(it!=&point)func(it);
  }
};

//type-safe product
template<typename TYPE>
class UberInit{
public:
  TRTTIProduct Product;
public:
  template<class QAP_RTTI>
  UberInit(QAP_RTTI&RTTI){
    Product.pType=Sys$$<TYPE>::GetRTTI(RTTI);
    if(!Product.pType)
    {
      int breakpoint=true;
      QapAssert(Product.pType);
    }
  }
  UberInit(UberInit<TYPE>&&_Right)
  {
    QapDebugMsg("good!");
    this->Product=std::move(_Right.Product);
    int gg=0;
  }
  ~UberInit()
  {
    QapAssert(!Product.Memory.ptr);
    QapAssert(!Product.pType);
    Product.pType=nullptr;
  }
};

//Владеющий объектом указатель.
template<class TYPE>
class TAutoPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TAutoPtr<TYPE>&Ref){QapAssert(0);} //This class can not be copied
  TAutoPtr(const TAutoPtr<TYPE>&Ref){QapAssert(0);}       //This class can not be copied
public:
  TRTTIProduct Product;
  //~TAutoPtr(){Off();}
  #define NO_USED
  #define CREATE(PARAM)TAutoPtr(PARAM):Product()
  #define CREATE_U(PARAM)template<class U>CREATE(PARAM)
  CREATE(NO_USED){}
  CREATE(std::nullptr_t){oper_set(nullptr);}
  CREATE(TAutoPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  CREATE(UberInit<TYPE>&Ref){oper_set(Ref);}
  CREATE_U(TAutoPtr<U>&&_Right){oper_set<U>(std::move(_Right));}
  CREATE_U(UberInit<U>&Ref){oper_set<U>(Ref);}
  #undef CREATE_U
  #undef CREATE
  #undef NO_USED
public:
  template<class U,class QAP_RTTI>
  U*build(QAP_RTTI&RTTI)
  {
    IEnvRTTI&Env=RTTI;
    oper_set(UberInit<U>(Env));
    return (U*)get();
  }
  void*unsafe_build(TType*pType)
  {
    //bool flag=std::is_same<TYPE,void>::value;
    //QapAssert(flag);
    this->Off();
    Product.pType=pType;
    Product.Init();
    return get();
  }
public:
  void oper_set(const nullptr_t&){Off();}
  void oper_set(TAutoPtr<TYPE>&&_Right){this->Off();Product=std::move(_Right.Product);}
  void oper_set(UberInit<TYPE>&Ref){Off();On(Ref.Product);}
public:
  template<class U>
  void oper_set(TAutoPtr<U>&&_Right)
  {
    static_assert(std::is_base_of<TYPE,U>::value,"fail");
    this->Off();
    Product=std::move(_Right.Product);
  }
  template<class U>
  void oper_set(UberInit<U>&Ref){TryInit<U,std::is_base_of<TYPE,U>::value>::Do(this,&Ref);}
public:
  void operator=(const nullptr_t&){oper_set(nullptr);}
  void operator=(TAutoPtr<TYPE>&&_Right){oper_set(std::move(_Right));}
  void operator=(UberInit<TYPE>&Ref){oper_set(Ref);}
  template<class U>
  void operator=(UberInit<U>&Ref){oper_set<U>(Ref);}
private:
  void On(TRTTIProduct&A){
    QapAssert(!A);
    QapAssert(!Product);
    Product=std::move(A);
    Product.Init();
  }
  void Off(){
    if(!Product.Memory.ptr)return;
    Product.Free();
    Product.pType=nullptr;
  }
public:
  TYPE*get()const{return (TYPE*)Product.Memory.ptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return Product.Memory.ptr;}
public:
  template<class U,bool flag=true>
  struct TryInit{
    static void Do(TAutoPtr<TYPE>*Self,UberInit<U>*Ref){Self->Off();Self->On(Ref->Product);}
  };
  template<class U>struct TryInit<U,false>{static void Do(...){static_assert(false,"U is not based on TYPE");}};
};

//Публичный глобальный указатель на себя.
template<class TYPE>
class TSelfPtr{
public:
  typedef TYPE ptr_t;
private:
  void operator=(const TSelfPtr<TYPE>&Ref)=delete;//{QapAssert(0);} //This class can not be copied
  TSelfPtr(const TSelfPtr<TYPE>&Ref)=delete;//{QapAssert(0);}       //This class can not be copied
private:
  typename TServerPtr<TYPE>::ptr_t*get(){return (TServerPtr<TYPE>::ptr_t*)get(this);}
  static TYPE*get(TSelfPtr<TYPE>*ptr)
  {
    #define OFFSET_OF(NAME)int(&(((TYPE*)nullptr)->*(&TYPE::NAME)))
    static const int field_offset=OFFSET_OF(Self);
    #undef OFFSET_OF
    return (TYPE*)(void*)(int(ptr)-field_offset);
  }
public:
  TServerPtr<TYPE> P;
  TSelfPtr(){P=get();}
  ~TSelfPtr(){}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  TSelfPtr(TSelfPtr<TYPE>&&_Right){
    operator=(std::move(_Right));
  }
  void operator=(TSelfPtr<TYPE>&&_Right){
    if(&_Right==this)return;
    this->P=std::move(_Right.P);
    _Right.P=_Right.get();
    P.ptr=get();
  }
};

//Слабый следящий указатель.
template<class TYPE>
class TWeakPtr{
public:
  typedef TYPE ptr_t;
public:
  TClientPtr<TYPE> P;// OFFSET_OF(P)==0
  #define INIT()P()
  TWeakPtr():INIT(){}
  TWeakPtr(TWeakPtr<TYPE>&&Ref):INIT(){oper_set(std::move(Ref));}
  TWeakPtr(const TWeakPtr<TYPE>&Ref):INIT(){oper_set(Ref);}
  TWeakPtr(TYPE*A):INIT(){oper_set(A);}
  TWeakPtr(const nullptr_t&):INIT(){oper_set(nullptr);}
  template<class U>
  TWeakPtr(const UberInit<U>&Ref){static_assert(0,"epic fail");}
  template<class U>
  TWeakPtr(U*A):INIT(){oper_set<U>(A);}
  template<class U>
  TWeakPtr(const TWeakPtr<U>&Ref):INIT(){oper_set<U>(Ref);}
  #undef INIT
public:
  void oper_set(TWeakPtr<TYPE>&&Ref){
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
  void oper_set(const TWeakPtr<TYPE>&Ref){if(&Ref==this)return;P=Ref.P.ptr;}
  void oper_set(TYPE*A){
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&){P=nullptr;}
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const TWeakPtr<U>&Ref)
  {
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Weak(this,&Ref);
  }
public:
  void operator=(TWeakPtr<TYPE>&&ref){oper_set(std::move(ref));}
  void operator=(const TWeakPtr<TYPE>&Ref){oper_set(Ref);}
  void operator=(TYPE*A){oper_set(A);}
  void operator=(const nullptr_t&){oper_set(nullptr);}
  template<class U>
  void operator=(const UberInit<U>&Ref){static_assert(0,"epic fail");}
  template<class U>
  void operator=(U*A){oper_set<U>(A);}
  template<class U>
  void operator=(const TWeakPtr<U>&Ref){oper_set<U>(Ref);}
public:
  TYPE*get()const{return P?(TYPE*)P.ptr->ptr:nullptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...){static_assert(0,"under construction");}
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>{
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Weak(TWeakPtr<TYPE>*Self,const TWeakPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(TWeakPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
  };
};

//Сильный следящий указатель.
template<class TYPE>
class THardPtr{
public:
  typedef TYPE ptr_t;
public:
  THardClientPtr<TYPE> P;// OFFSET_OF(P)==0
  #define INIT()P()
  THardPtr():INIT(){}
  THardPtr(const THardPtr<TYPE>&Ref):INIT(){oper_set(Ref);}
  THardPtr(THardPtr<TYPE>&&Ref):INIT(){oper_set(std::move(Ref));}
  THardPtr(TYPE*A):INIT(){oper_set(A);}
  THardPtr(const nullptr_t&):INIT(){oper_set(nullptr);}
  template<class U>
  THardPtr(const UberInit<U>&Ref){static_assert(0,"from constant, you are sure?");}
  template<class U>
  THardPtr(U*A):INIT(){oper_set<U>(A);}
  template<class U>
  THardPtr(const THardPtr<U>&Ref):INIT(){oper_set<U>(Ref);}
  #undef INIT
public:
  void oper_set(const THardPtr<TYPE>&Ref){if(&Ref==this)return;P=Ref.P.ptr;}
  void oper_set(TYPE*A){
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<TYPE,true,true>::Do_Raw(this,A);
  }
  void oper_set(const nullptr_t&){P=nullptr;}
  template<class U>
  void oper_set(U*A)
  {
    static_assert(detail::has_self<TYPE>::value,"Oops!");
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Raw(this,A);
  }
  template<class U>
  void oper_set(const THardPtr<U>&Ref)
  {
    TryInit<
      U,
      std::is_base_of<TYPE,U>::value,
      std::is_base_of<U,TYPE>::value
    >::Do_Hrd(this,&Ref);
  }
  void oper_set(THardPtr<TYPE>&&Ref)
  {
    this->P=Ref?Ref.P.ptr:nullptr;
    Ref.P=nullptr;
  }
public:
  void operator=(THardPtr<TYPE>&&Ref){oper_set(std::move(Ref));}
  void operator=(const THardPtr<TYPE>&Ref){oper_set(Ref);}
  void operator=(TYPE*A){oper_set(A);}
  void operator=(const nullptr_t&){oper_set(nullptr);}
  template<class U>
  void operator=(const UberInit<U>&Ref){static_assert(0,"from constant, you are sure?");}
  template<class U>
  void operator=(U*A){oper_set<U>(A);}
  template<class U>
  void operator=(THardPtr<U>&Ref){oper_set<U>(Ref);}
public:
public:
  TYPE*get()const{return P?(TYPE*)P.ptr->ptr:nullptr;}
  TYPE*operator->()const{return get();}
  operator bool()const{return P;}
public:
  template<class U,bool dir,bool indir>
  struct TryInit
  {
    static void Do_Raw(...){static_assert(0,"under construction");}
    static void Do_Hrd(...){static_assert(0,"under construction");}
  };
  template<class U,bool indir>
  struct TryInit<U,true,indir>{
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      Self->P=Source?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,const THardPtr<U>*Source)
    {
      QapDebugMsg("bug detected");
      Self->P=*Source?Source->P.ptr:nullptr;
    }
  };
  template<class U>
  struct TryInit<U,false,true>
  {
    static void Do_Raw(THardPtr<TYPE>*Self,U*Source)
    {
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      static_assert(0,"nax");
      U*tmp=Source;
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=Source&&!skip?(TServerPtr<TYPE>*)&Source->Self.P:nullptr;
    }
    static void Do_Hrd(THardPtr<TYPE>*Self,THardPtr<U>*Source)
    {
      static_assert(0,"under construction");
      static_assert(std::is_polymorphic<TYPE>::value,"fail");
      static_assert(std::is_polymorphic<U>::value,"fail");
      U*tmp=Source->get();
      bool skip=tmp!=dynamic_cast<TYPE*>(tmp);
      Self->P=*Source&&!skip?&Source->P:nullptr;
    }
  };
};
#undef MACRO_OFF
#undef DEF_LOG
//<<<<<=====ptr
#endif //DEF_BUILD_MICRO//