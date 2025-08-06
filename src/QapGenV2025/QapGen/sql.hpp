// 3468.465900 ms
//===>>===i_sep_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_sep_seq)\
  ADD(t_sql_block_comment)\
  ADD(t_sql_line_comment)\
ADDEND()
class i_sep;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_sep_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_sep*p){
    if(!p)return nullptr;Is<TYPE,i_sep_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_sep*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_sep_visitor{
//  void Do(t_sep_seq&r){}
//  void Do(t_sql_block_comment&r){}
//  void Do(t_sql_line_comment&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_sep_visitor
struct i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_sep
public:
  typedef i_sep_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_sep()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_sep_seq);
      F(t_sql_block_comment);
      F(t_sql_line_comment);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_str_item_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_str_raw)\
  ADD(t_str_hex)\
  ADD(t_str_unicode)\
  ADD(t_str_escape)\
ADDEND()
class i_str_item;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_str_item_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_str_item*p){
    if(!p)return nullptr;Is<TYPE,i_str_item_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_str_item*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_str_item_visitor{
//  void Do(t_str_raw&r){}
//  void Do(t_str_hex&r){}
//  void Do(t_str_unicode&r){}
//  void Do(t_str_escape&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_str_item_visitor
struct i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_str_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_str_item
public:
  typedef i_str_item_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_str_item()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_str_raw);
      F(t_str_hex);
      F(t_str_unicode);
      F(t_str_escape);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_expr_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_str_expr)\
  ADD(t_bool_expr)\
  ADD(t_star_expr)\
  ADD(t_block_expr)\
  ADD(t_varcall_expr)\
  ADD(t_case_expr)\
  ADD(t_num_expr)\
  ADD(t_nullif_func)\
  ADD(t_host_expr)\
  ADD(t_subquery_expr)\
ADDEND()
class i_expr;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_expr_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_expr*p){
    if(!p)return nullptr;Is<TYPE,i_expr_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_expr*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_expr_visitor{
//  void Do(t_str_expr&r){}
//  void Do(t_bool_expr&r){}
//  void Do(t_star_expr&r){}
//  void Do(t_block_expr&r){}
//  void Do(t_varcall_expr&r){}
//  void Do(t_case_expr&r){}
//  void Do(t_num_expr&r){}
//  void Do(t_nullif_func&r){}
//  void Do(t_host_expr&r){}
//  void Do(t_subquery_expr&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_expr_visitor
struct i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_expr
public:
  typedef i_expr_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_expr()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_str_expr);
      F(t_bool_expr);
      F(t_star_expr);
      F(t_block_expr);
      F(t_varcall_expr);
      F(t_case_expr);
      F(t_num_expr);
      F(t_nullif_func);
      F(t_host_expr);
      F(t_subquery_expr);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_table_expr_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_joined_table_part)\
  ADD(t_table_expr)\
  ADD(t_subquery)\
ADDEND()
class i_table_expr;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_table_expr_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_table_expr*p){
    if(!p)return nullptr;Is<TYPE,i_table_expr_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_table_expr*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_table_expr_visitor{
//  void Do(t_joined_table_part&r){}
//  void Do(t_table_expr&r){}
//  void Do(t_subquery&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_table_expr_visitor
struct i_table_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_table_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_table_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_table_expr
public:
  typedef i_table_expr_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_table_expr()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_joined_table_part);
      F(t_table_expr);
      F(t_subquery);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_in_operand_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_in_list)\
  ADD(t_in_subquery)\
ADDEND()
class i_in_operand;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_in_operand_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_in_operand*p){
    if(!p)return nullptr;Is<TYPE,i_in_operand_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_in_operand*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_in_operand_visitor{
//  void Do(t_in_list&r){}
//  void Do(t_in_subquery&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_in_operand_visitor
struct i_in_operand{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_in_operand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_in_operand
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_in_operand
public:
  typedef i_in_operand_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_in_operand()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_in_list);
      F(t_in_subquery);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_data_stat_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_select_stat)\
  ADD(t_union_stat)\
  ADD(t_insert_stat)\
  ADD(t_update_stat)\
  ADD(t_delete_stat)\
  ADD(t_sep_stat)\
  ADD(t_semicolon_stat)\
ADDEND()
class i_data_stat;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_data_stat_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_data_stat*p){
    if(!p)return nullptr;Is<TYPE,i_data_stat_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_data_stat*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_data_stat_visitor{
//  void Do(t_select_stat&r){}
//  void Do(t_union_stat&r){}
//  void Do(t_insert_stat&r){}
//  void Do(t_update_stat&r){}
//  void Do(t_delete_stat&r){}
//  void Do(t_sep_stat&r){}
//  void Do(t_semicolon_stat&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_data_stat_visitor
struct i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_data_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_data_stat
public:
  typedef i_data_stat_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_data_stat()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_select_stat);
      F(t_union_stat);
      F(t_insert_stat);
      F(t_update_stat);
      F(t_delete_stat);
      F(t_sep_stat);
      F(t_semicolon_stat);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_insert_body_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_values_body)\
  ADD(t_select_body)\
ADDEND()
class i_insert_body;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_insert_body_visitor{
public:
public:
  #define ADD(TYPE)virtual void Do(TYPE&r)=0;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #define ADD(U)//typedef ::U U;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
public:
  #ifdef QAP_FAST_UBERCAST
  template<class TYPE,class Visitor>
  struct Is:public Visitor{
    TYPE*ptr{};
  public:
    #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  };
  template<class TYPE>
  static TYPE*UberCast(i_insert_body*p){
    if(!p)return nullptr;Is<TYPE,i_insert_body_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_insert_body*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_insert_body_visitor{
//  void Do(t_values_body&r){}
//  void Do(t_select_body&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_insert_body_visitor
struct i_insert_body{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_insert_body)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_insert_body
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_insert_body
public:
  typedef i_insert_body_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_insert_body()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_values_body);
      F(t_select_body);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
struct t_sep_seq:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_seq)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_seq
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_seq
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sep_seq");
    auto&ok=$.ok;
    static const auto g_static_var_0=CharMask::fromStr(" \t\r\n");
    ok=dev.go_any(body,g_static_var_0);$(ok,",\" \\t\\r\\n\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sql_block_comment:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_block_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sql_block_comment
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sql_block_comment
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sql_block_comment");
    auto&ok=$.ok;
    ok=dev.go_const("/*");$(ok,",\"/\"");
    if(!ok)return ok;
    ok=dev.go_end(body,"*/");$(ok,",\"*\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sql_line_comment:public i_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_line_comment)PARENT(i_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sql_line_comment
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sql_line_comment
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sql_line_comment");
    auto&ok=$.ok;
    ok=dev.go_const("--");$(ok,",\"-\"");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(dip_inv("\n"));
    {bool ok=dev.go_any(body,g_static_var_1);$(ok,",gen_dips(\"\\x00\\t\\x0B\\xFF\")");}
    return ok;
  }
};
struct t_sep{
  //t_impl{
  //  vector<TAutoPtr<i_sep>> arr;
  //}
  //string value=str<t_impl>();
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_sep>>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sep");
    auto&ok=$.ok;
    ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_sep>>,\"\\t\\n\\r -/\"");
    if(!ok)return ok;
    return ok;
  }
};
typedef array<char,2> ARRAY2char;
typedef array<char,4> ARRAY4char;
struct t_str_raw:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_raw)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_raw
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_raw
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_raw");
    auto&ok=$.ok;
    static const auto g_static_var_0=CharMask::fromStr(dip_inv("'\\\n"));
    ok=dev.go_any(body,g_static_var_0);$(ok,",gen_dips(\"\\x00\\t\\x0B&([]\\xFF\")");
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_hex:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_hex)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(ARRAY2char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_hex
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_hex
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_hex");
    auto&ok=$.ok;
    ok=dev.go_const("\\x");$(ok,",\"\\\\\"");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
    ok=dev.go_any_arr_char(body,g_static_var_1);$(ok,",gen_dips(\"09AFaf\")");
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_unicode:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_unicode)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(ARRAY4char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_unicode
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_unicode
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_unicode");
    auto&ok=$.ok;
    ok=dev.go_const("\\u");$(ok,",\"\\\\\"");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
    ok=dev.go_any_arr_char(body,g_static_var_1);$(ok,",\"0123456789\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_escape:public i_str_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_escape)PARENT(i_str_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_escape
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_escape
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_escape");
    auto&ok=$.ok;
    ok=dev.go_const("\\");$(ok,",\"\\\\\"");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr("tfbrn\\'\""+gen_dips("07"));
    ok=dev.go_any_char(body,g_static_var_1);$(ok,",gen_dips(\"07\")+\"\\\"'\\\\bfnrt\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_str_impl{
  struct t_one{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_one)OWNER(t_str_impl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_str_item>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_one
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_one
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_str_impl::t_one");
      auto&ok=$.ok;
      ok=dev.go_const("'");$(ok,",\"'\"");
      if(!ok)return ok;
      ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_str_item>>,gen_dips(\"\\x00\\t\\x0B&(\\xFF\")");
      if(!ok)return ok;
      ok=dev.go_const("'");$(ok,",\"'\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_one)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_impl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_one>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_impl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_impl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_impl");
    auto&ok=$.ok;
    ok=dev.go_auto(arr);$(ok,"vector<t_one>,\"'\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_str_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_str_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_str_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_str_expr");
    auto&ok=$.ok;
    ok=dev.go_str<t_str_impl>(value);$(ok,"t_str_impl,\"'\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_bool_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_bool_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_bool_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_bool_expr");
    auto&ok=$.ok;
    static const auto g_static_var_0=QapStrFinder::fromArr(split("true,false",","));
    ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"tf\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_name{
  struct t_keyword{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_keyword)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_keyword
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_keyword
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_name::t_keyword");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("select,insert,update,delete,from,where,and,or,not,in,between,like,is,null,distinct,as,join,inner,left,right,full,on,using,group,having,order,by,asc,desc,union,all,create,drop,table,index,view,trigger,procedure,function,case,when,then,else,end,cast,convert,set,values,into,exists,limit,offset,true,false,nullif,ifnull,single",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",gen_dips(\"ajnprw\")+\"l\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,A,DEF,$,$)\
  ADDVAR(string,B,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_name::t_impl");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("azAZ")+"_");
      ok=dev.go_any_char(A,g_static_var_0);$(ok,",gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("azAZ09")+"_");
      {bool ok=dev.go_any(B,g_static_var_1);$(ok,",gen_dips(\"09AZaz\")+\"_\"");}
      return ok;
    }
  };
  struct t_impl_ex{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl_ex)OWNER(t_name)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_impl,impl,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl_ex
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl_ex
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_name::t_impl_ex");
      auto&ok=$.ok;
      ok=dev.go_diff<t_keyword>(impl);$(ok,"diff<t_keyword>!t_impl,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_keyword)\
  F(t_impl   )\
  F(t_impl_ex)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_name
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_name");
    auto&ok=$.ok;
    ok=dev.go_str<t_impl_ex>(value);$(ok,"t_impl_ex,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_lev01{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev01)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,oper,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<i_expr>,expr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev01
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev01
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev01");
    auto&ok=$.ok;
    static const auto g_static_var_0=QapStrFinder::fromArr(split("not,+,-",","));
    {bool ok=dev.go_any_str_from_vec(oper,g_static_var_0);$(ok,",\"n+-\"");}
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(expr);$(ok,"TAutoPtr<i_expr>,gen_dips(\"'(0:AZaz\")+\"*._\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_lev02{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev02::t_oper");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,%,div,mod",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"*/%dm\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev02)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev01,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev02::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"%*/dm\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev01,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev02)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev01,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev02
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev02
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev02");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev01,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r %*-/dm\"");}
    return ok;
  }
public:
};
struct t_lev03{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev03::t_oper");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("+,-",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"+-\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev03)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev02,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev03::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"+-\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev02,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev02,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev03
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev03
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev03");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev02,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r +-/\"");}
    return ok;
  }
public:
};
struct t_lev04{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev04)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev04::t_oper");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("shl,shr",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"ss\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev04)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev03,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev04::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"s\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev03,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev04)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev03,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev04
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev04
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev04");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev03,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r -/s\"");}
    return ok;
  }
public:
};
struct t_lev05{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev05)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev05::t_oper");
      auto&ok=$.ok;
      ok=dev.go_const("||");$(ok,",\"|\"");
      if(!ok)return ok;
      return ok;
    }
    inline static const string value="||";
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev05)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev04,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev05::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"|\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev04,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev04,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev05
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev05
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev05");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev04,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r -/|\"");}
    return ok;
  }
public:
};
struct t_lev06{
  //===>>===i_lev06_ext_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_between)\
    ADD(t_is_null)\
    ADD(t_in_list)\
  ADDEND()
  class i_lev06_ext;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_lev06_ext_visitor{
  public:
    typedef t_lev06::i_lev06_ext i_lev06_ext;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_lev06::U U;//typedef t_lev06::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_lev06_ext*p){
      if(!p)return nullptr;Is<TYPE,i_lev06_ext_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_lev06_ext*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_lev06_ext_visitor{
  //  void Do(t_between&r){}
  //  void Do(t_is_null&r){}
  //  void Do(t_in_list&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_lev06_ext_visitor
  struct i_lev06_ext{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_lev06_ext)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_lev06_ext
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_lev06_ext
  public:
    typedef i_lev06_ext_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_lev06_ext()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_between);
        F(t_is_null);
        F(t_in_list);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_not{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_not)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_not
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_not
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_not");
      auto&ok=$.ok;
      ok=dev.go_const("not");$(ok,",\"n\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_between:public i_lev06_ext{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_between)PARENT(i_lev06_ext)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_not>,not,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(t_lev05,low,DEF,$,$)\
  ADDVAR(t_sep,$sep5,DEF,$,$)\
  ADDVAR(t_sep,$sep7,DEF,$,$)\
  ADDVAR(t_lev05,high,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_between
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_between
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_between");
      auto&ok=$.ok;
      {bool ok=dev.go_auto(not);$(ok,"TAutoPtr<t_not>,\"n\"");}
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_const("between");$(ok,",\"b\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(low);$(ok,"t_lev05,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_const("and");$(ok,",\"a\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(high);$(ok,"t_lev05,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_is_null:public i_lev06_ext{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_is_null)PARENT(i_lev06_ext)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_not>,not,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_is_null
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_is_null
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_is_null");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_const("is");$(ok,",\"i\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(not);$(ok,"TAutoPtr<t_not>,\"n\"");}
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_const("null");$(ok,",\"n\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_in_list:public i_lev06_ext{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_in_list)PARENT(i_lev06_ext)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(TAutoPtr<t_not>,not,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDVAR(TAutoPtr<i_in_operand>,operand,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_in_list
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_in_list
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_in_list");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(not);$(ok,"TAutoPtr<t_not>,\"n\"");}
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_const("in");$(ok,",\"i\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(operand);$(ok,"TAutoPtr<i_in_operand>,\"(\"");
      if(!ok)return ok;
      return ok;
    }
  };
  /*
  t_in_select:i_lev06_ext{ - да ну нафин, я лучше запихаю селект в i_expr, а то я задалбался с ним возится.
    " "?
    "in"
    " "?
    "("
    " "?
    t_select_stat query;
    " "?
    ")"
  }*/
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_oper");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("=,<>,<,>,<=,>=,like,in",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"=<<><>li\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_lev05,expr,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_item");
      auto&ok=$.ok;
      ok=dev.go_auto(oper);$(ok,"t_oper,\"<=>il\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev05,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_not    )\
  F(t_between)\
  F(t_is_null)\
  F(t_in_list)\
  F(t_oper   )\
  F(t_item   )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev05,expr,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDVAR(TAutoPtr<i_lev06_ext>,ext,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev06
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev06
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev06");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev05,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"<=>il\"");}
    {bool ok=dev.go_auto(ext);$(ok,"TAutoPtr<i_lev06_ext>,\"\\t\\n\\r -/bin\"");}
    return ok;
  }
public:
};
struct t_lev07{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev07)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev07::t_oper");
      auto&ok=$.ok;
      ok=dev.go_const("and");$(ok,",\"a\"");
      if(!ok)return ok;
      return ok;
    }
    inline static const string value="and";
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev07)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev06,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev07::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"a\"");
      if(!ok)return ok;
      ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");
      if(!ok)return ok;
      ok=dev.go_auto(expr);$(ok,"t_lev06,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev06,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev07
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev07
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev07");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev06,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r -/a\"");}
    return ok;
  }
public:
};
struct t_lev08{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev08)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev08::t_oper");
      auto&ok=$.ok;
      ok=dev.go_const("or");$(ok,",\"o\"");
      if(!ok)return ok;
      return ok;
    }
    inline static const string value="or";
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev08)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev07,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev08::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"o\"");
      if(!ok)return ok;
      ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");
      if(!ok)return ok;
      ok=dev.go_auto(expr);$(ok,"t_lev07,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev07,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev08
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev08
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev08");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev07,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r -/o\"");}
    return ok;
  }
public:
};
/*
t_call_param{
  " "?
  t_lev08 expr;
  " "?
}
t_call_params{
  "("
  " "?
  vector<t_call_param> arr=vec(",");
  " "?
  ")"
}*/
struct t_star_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_star_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_star_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_star_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_star_expr");
    auto&ok=$.ok;
    ok=dev.go_const("*");$(ok,",\"*\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_lev08_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_lev08,expr,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev08_with_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev08_with_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev08_with_sep");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(expr);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_block_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_lev08_with_sep>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_block_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_block_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_block_expr");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_vec(arr,",");$(ok,"vector<t_lev08_with_sep>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_varcall_expr:public i_expr{
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_varcall_expr::t_item");
      auto&ok=$.ok;
      ok=dev.go_const(".");$(ok,",\".\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_varcall_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDVAR(TAutoPtr<t_block_expr>,params,DEF,$,$)\
ADDEND()
//=====+>>>>>t_varcall_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_varcall_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_varcall_expr");
    auto&ok=$.ok;
    ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\".\"");}
    {bool ok=dev.go_auto(params);$(ok,"TAutoPtr<t_block_expr>,\"(\"");}
    return ok;
  }
public:
};
struct t_when_branch{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_when_branch)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_lev08,cond,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_lev08,result,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDEND()
//=====+>>>>>t_when_branch
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_when_branch
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_when_branch");
    auto&ok=$.ok;
    ok=dev.go_const("when");$(ok,",\"w\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(cond);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("then");$(ok,",\"t\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(result);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_else_branch{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else_branch)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_lev08,result,DEF,$,$)\
ADDEND()
//=====+>>>>>t_else_branch
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_else_branch
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_else_branch");
    auto&ok=$.ok;
    ok=dev.go_const("else");$(ok,",\"e\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(result);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_case_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_case_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_lev08,input,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<t_when_branch>,arr,DEF,$,$)\
ADDVAR(TAutoPtr<t_else_branch>,else_branch,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_case_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_case_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_case_expr");
    auto&ok=$.ok;
    ok=dev.go_const("case");$(ok,",\"c\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(input);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(arr);$(ok,"vector<t_when_branch>,\"w\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(else_branch);$(ok,"TAutoPtr<t_else_branch>,\"e\"");}
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("end");$(ok,",\"e\"");
    if(!ok)return ok;
    return ok;
  }
};
/*
t_func:i_expr{
  t_name func;
  //string func=any_str_from_vec(split("count,sum,min,max,avg",","));
  " "?
  t_block_expr expr;
}*/
struct t_as_alias{
  struct t_as_opt{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_as_opt)OWNER(t_as_alias)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_as_opt
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_as_opt
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_as_alias::t_as_opt");
      auto&ok=$.ok;
      ok=dev.go_const("as");$(ok,",\"a\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_as_opt)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_as_alias)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_as_opt>,opt,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,alias,DEF,$,$)\
ADDEND()
//=====+>>>>>t_as_alias
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_as_alias
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_as_alias");
    auto&ok=$.ok;
    {bool ok=dev.go_auto(opt);$(ok,"TAutoPtr<t_as_opt>,\"a\"");}
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(alias);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_joined_table_part:public i_table_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_joined_table_part)PARENT(i_table_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(string,join_type,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(t_name,right,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDVAR(t_lev08,on_cond,DEF,$,$)\
ADDEND()
//=====+>>>>>t_joined_table_part
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_joined_table_part
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_joined_table_part");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    static const auto g_static_var_1=QapStrFinder::fromArr(split("inner join,left join,right join,full join,join",","));
    ok=dev.go_any_str_from_vec(join_type,g_static_var_1);$(ok,",\"ilrfj\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(right);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as_alias>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("on");$(ok,",\"o\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep8);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(on_cond);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_table_expr:public i_table_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_table_expr)PARENT(i_table_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<t_joined_table_part>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDEND()
//=====+>>>>>t_table_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_table_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_table_expr");
    auto&ok=$.ok;
    ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as_alias>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_joined_table_part>,\"\\t\\n\\r -/fijlr\"");}
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_subquery:public i_table_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_subquery)PARENT(i_table_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<i_data_stat>,query,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
ADDEND()
//=====+>>>>>t_subquery
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_subquery
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_subquery");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(query);$(ok,"TAutoPtr<i_data_stat>,\"\\t\\n\\r -/;disu\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as_alias>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    return ok;
  }
};
struct t_in_list:public i_in_operand{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_in_list)PARENT(i_in_operand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_lev08>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_in_list
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_in_list
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_in_list");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_lev08>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_in_subquery:public i_in_operand{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_in_subquery)PARENT(i_in_operand)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_subquery,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_in_subquery
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_in_subquery
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_in_subquery");
    auto&ok=$.ok;
    ok=dev.go_auto(body);$(ok,"t_subquery,\"(\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_frac_part{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac_part)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,digits,DEF,$,$)\
ADDEND()
//=====+>>>>>t_frac_part
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_frac_part
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_frac_part");
    auto&ok=$.ok;
    ok=dev.go_const(".");$(ok,",\".\"");
    if(!ok)return ok;
    static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
    ok=dev.go_any(digits,g_static_var_1);$(ok,",\"0123456789\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_exp_part{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp_part)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,e,DEF,$,$)\
ADDVAR(string,sign,DEF,$,$)\
ADDVAR(string,digits,DEF,$,$)\
ADDEND()
//=====+>>>>>t_exp_part
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_exp_part
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_exp_part");
    auto&ok=$.ok;
    static const auto g_static_var_0=CharMask::fromStr("eE");
    ok=dev.go_any_char(e,g_static_var_0);$(ok,",\"eE\"");
    if(!ok)return ok;
    static const auto g_static_var_1=QapStrFinder::fromArr(split("+,-",","));
    {bool ok=dev.go_any_str_from_vec(sign,g_static_var_1);$(ok,",\"+-\"");}
    static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
    ok=dev.go_any(digits,g_static_var_2);$(ok,",\"0123456789\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_num_expr:public i_expr{
  //===>>===i_num_part_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_int_part)\
    ADD(t_zero_part)\
  ADDEND()
  class i_num_part;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_num_part_visitor{
  public:
    typedef t_num_expr::i_num_part i_num_part;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_num_expr::U U;//typedef t_num_expr::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_num_part*p){
      if(!p)return nullptr;Is<TYPE,i_num_part_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_num_part*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_num_part_visitor{
  //  void Do(t_int_part&r){}
  //  void Do(t_zero_part&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_num_part_visitor
  struct i_num_part{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_num_part)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_num_part
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_num_part
  public:
    typedef i_num_part_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_num_part()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_int_part);
        F(t_zero_part);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  //===>>===i_impl_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_impl2)\
    ADD(t_impl)\
  ADDEND()
  class i_impl;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_impl_visitor{
  public:
    typedef t_num_expr::i_impl i_impl;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_num_expr::U U;//typedef t_num_expr::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_impl*p){
      if(!p)return nullptr;Is<TYPE,i_impl_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_impl*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_impl_visitor{
  //  void Do(t_impl2&r){}
  //  void Do(t_impl&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_impl_visitor
  struct i_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_impl)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_impl
  public:
    typedef i_impl_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_impl()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_impl2);
        F(t_impl);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_int_part:public i_num_part{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_int_part)PARENT(i_num_part)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,first,DEF,$,$)\
  ADDVAR(string,rest,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_int_part
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_int_part
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_num_expr::t_int_part");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("19"));
      ok=dev.go_any_char(first,g_static_var_0);$(ok,",\"123456789\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      {bool ok=dev.go_any(rest,g_static_var_1);$(ok,",\"0123456789\"");}
      return ok;
    }
  };
  struct t_zero_part:public i_num_part{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero_part)PARENT(i_num_part)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_zero_part
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_zero_part
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_num_expr::t_zero_part");
      auto&ok=$.ok;
      ok=dev.go_const("0");$(ok,",\"0\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_impl2:public i_impl{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl2)PARENT(i_impl)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<t_frac_part>,frac,DEF,$,$)\
  ADDVAR(TAutoPtr<t_exp_part>,exp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl2
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl2
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_num_expr::t_impl2");
      auto&ok=$.ok;
      ok=dev.go_auto(frac);$(ok,"TAutoPtr<t_frac_part>,\".\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto(exp);$(ok,"TAutoPtr<t_exp_part>,\"Ee\"");}
      return ok;
    }
  };
  struct t_impl:public i_impl{
      //string sign=any_str_from_vec(split("+,-","))?;
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_impl)PARENT(i_impl)OWNER(t_num_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_num_part>,int_part,DEF,$,$)\
  ADDVAR(TAutoPtr<t_frac_part>,frac,DEF,$,$)\
  ADDVAR(TAutoPtr<t_exp_part>,exp,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_impl
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_num_expr::t_impl");
      auto&ok=$.ok;
      ok=dev.go_auto(int_part);$(ok,"TAutoPtr<i_num_part>,\"0123456789\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto(frac);$(ok,"TAutoPtr<t_frac_part>,\".\"");}
      {bool ok=dev.go_auto(exp);$(ok,"TAutoPtr<t_exp_part>,\"Ee\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_int_part )\
  F(t_zero_part)\
  F(t_impl2    )\
  F(t_impl     )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_num_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_num_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_num_expr");
    auto&ok=$.ok;
    ok=dev.go_str<TAutoPtr<i_impl>>(value);$(ok,"TAutoPtr<i_impl>,\".0123456789\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_nullif_func:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullif_func)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,kw,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_lev08,left,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_lev08,right,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDEND()
//=====+>>>>>t_nullif_func
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_nullif_func
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_nullif_func");
    auto&ok=$.ok;
    static const auto g_static_var_0=QapStrFinder::fromArr(split("nullif,ifnull",","));
    ok=dev.go_any_str_from_vec(kw,g_static_var_0);$(ok,",\"in\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(left);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(",");$(ok,",\",\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(right);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_host_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_host_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,var,DEF,$,$)\
ADDEND()
//=====+>>>>>t_host_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_host_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_host_expr");
    auto&ok=$.ok;
    ok=dev.go_const(":");$(ok,",\":\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(var);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_where_clause{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_where_clause)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_lev08,cond,DEF,$,$)\
ADDEND()
//=====+>>>>>t_where_clause
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_where_clause
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_where_clause");
    auto&ok=$.ok;
    ok=dev.go_const("where");$(ok,",\"w\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(cond);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_column_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_column_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_lev08,expr,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDEND()
//=====+>>>>>t_column_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_column_item
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_column_item");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(expr);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as_alias>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_column_list{
  //===>>===i_clist_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_arr)\
    ADD(t_star)\
  ADDEND()
  class i_clist_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_clist_item_visitor{
  public:
    typedef t_column_list::i_clist_item i_clist_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_column_list::U U;//typedef t_column_list::U U;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #ifdef QAP_FAST_UBERCAST
    template<class TYPE,class Visitor>
    struct Is:public Visitor{
      TYPE*ptr{};
    public:
      #define ADD(U)void Do(U&r){ptr=std::is_same<U,TYPE>::value?(TYPE*)&r:nullptr;}
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
    };
    template<class TYPE>
    static TYPE*UberCast(i_clist_item*p){
      if(!p)return nullptr;Is<TYPE,i_clist_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_clist_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_clist_item_visitor{
  //  void Do(t_arr&r){}
  //  void Do(t_star&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_clist_item_visitor
  struct i_clist_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_clist_item)OWNER(t_column_list)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_clist_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_clist_item
  public:
    typedef i_clist_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_clist_item()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_arr);
        F(t_star);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_arr:public i_clist_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr)PARENT(i_clist_item)OWNER(t_column_list)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_column_item>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_arr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_arr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_column_list::t_arr");
      auto&ok=$.ok;
      ok=dev.go_vec(arr,",");$(ok,"vector<t_column_item>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_star:public i_clist_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_star)PARENT(i_clist_item)OWNER(t_column_list)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_star
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_star
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_column_list::t_star");
      auto&ok=$.ok;
      ok=dev.go_const("*");$(ok,",\"*\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_arr )\
  F(t_star)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_column_list)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<i_clist_item>,item,DEF,$,$)\
ADDEND()
//=====+>>>>>t_column_list
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_column_list
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_column_list");
    auto&ok=$.ok;
    ok=dev.go_auto(item);$(ok,"TAutoPtr<i_clist_item>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
struct t_group_by_clause{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_group_by_clause)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_column_list,cols,DEF,$,$)\
ADDEND()
//=====+>>>>>t_group_by_clause
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_group_by_clause
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_group_by_clause");
    auto&ok=$.ok;
    ok=dev.go_const("group");$(ok,",\"g\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("by");$(ok,",\"b\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(cols);$(ok,"t_column_list,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_having_clause{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_having_clause)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_lev08,cond,DEF,$,$)\
ADDEND()
//=====+>>>>>t_having_clause
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_having_clause
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_having_clause");
    auto&ok=$.ok;
    ok=dev.go_const("having");$(ok,",\"h\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(cond);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_order_by_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_order_by_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_varcall_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(string,order,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDEND()
//=====+>>>>>t_order_by_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_order_by_item
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_order_by_item");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(expr);$(ok,"t_varcall_expr,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    static const auto g_static_var_3=QapStrFinder::fromArr(split("asc,desc",","));
    {bool ok=dev.go_any_str_from_vec(order,g_static_var_3);$(ok,",\"ad\"");}
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_order_by_clause{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_order_by_clause)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<t_order_by_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_order_by_clause
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_order_by_clause
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_order_by_clause");
    auto&ok=$.ok;
    ok=dev.go_const("order");$(ok,",\"o\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("by");$(ok,",\"b\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_order_by_item>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    return ok;
  }
};
struct t_distinct_kw{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_distinct_kw)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_distinct_kw
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_distinct_kw
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_distinct_kw");
    auto&ok=$.ok;
    ok=dev.go_const("distinct");$(ok,",\"d\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_select_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_select_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_distinct_kw>,distinct,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_column_list,cols,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(TAutoPtr<i_table_expr>,table,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDVAR(TAutoPtr<t_where_clause>,where,DEF,$,$)\
ADDVAR(t_sep,$sep11,DEF,$,$)\
ADDVAR(TAutoPtr<t_group_by_clause>,group_by,DEF,$,$)\
ADDVAR(t_sep,$sep13,DEF,$,$)\
ADDVAR(TAutoPtr<t_having_clause>,having,DEF,$,$)\
ADDVAR(t_sep,$sep15,DEF,$,$)\
ADDVAR(TAutoPtr<t_order_by_clause>,order_by,DEF,$,$)\
ADDEND()
//=====+>>>>>t_select_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_select_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_select_stat");
    auto&ok=$.ok;
    ok=dev.go_const("select");$(ok,",\"s\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(distinct);$(ok,"TAutoPtr<t_distinct_kw>,\"d\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(cols);$(ok,"t_column_list,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("from");$(ok,",\"f\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(table);$(ok,"TAutoPtr<i_table_expr>,gen_dips(\"\\t\\nAZaz\")+\"\\r (-/_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(where);$(ok,"TAutoPtr<t_where_clause>,\"w\"");}
    {bool ok=dev.go_auto($sep11);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(group_by);$(ok,"TAutoPtr<t_group_by_clause>,\"g\"");}
    {bool ok=dev.go_auto($sep13);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(having);$(ok,"TAutoPtr<t_having_clause>,\"h\"");}
    {bool ok=dev.go_auto($sep15);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(order_by);$(ok,"TAutoPtr<t_order_by_clause>,\"o\"");}
    return ok;
  }
};
struct t_subquery_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_subquery_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_select_stat,query,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
ADDEND()
//=====+>>>>>t_subquery_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_subquery_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_subquery_expr");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(query);$(ok,"t_select_stat,\"s\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as_alias>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    return ok;
  }
};
struct t_union_part{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_union_part)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(string,op,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(t_select_stat,query,DEF,$,$)\
ADDEND()
//=====+>>>>>t_union_part
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_union_part
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_union_part");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    static const auto g_static_var_1=QapStrFinder::fromArr(split("union,union all",","));
    ok=dev.go_any_str_from_vec(op,g_static_var_1);$(ok,",\"uu\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(query);$(ok,"t_select_stat,\"s\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_union_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_union_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_select_stat,first,DEF,$,$)\
ADDVAR(vector<t_union_part>,unions,DEF,$,$)\
ADDEND()
//=====+>>>>>t_union_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_union_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_union_stat");
    auto&ok=$.ok;
    ok=dev.go_auto(first);$(ok,"t_select_stat,\"s\"");
    if(!ok)return ok;
    ok=dev.go_auto(unions);$(ok,"vector<t_union_part>,\"\\t\\n\\r -/u\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_values_row{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_values_row)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(vector<t_lev08_with_sep>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_values_row
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_values_row
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_values_row");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_vec(arr,",");$(ok,"vector<t_lev08_with_sep>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_values_body:public i_insert_body{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_values_body)PARENT(i_insert_body)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_values_row>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_values_body
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_values_body
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_values_body");
    auto&ok=$.ok;
    ok=dev.go_const("values");$(ok,",\"v\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_values_row>,\"\\t\\n\\r (-/\"");}
    return ok;
  }
};
struct t_select_body:public i_insert_body{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_select_body)PARENT(i_insert_body)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_select_stat,query,DEF,$,$)\
ADDEND()
//=====+>>>>>t_select_body
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_select_body
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_select_body");
    auto&ok=$.ok;
    ok=dev.go_auto(query);$(ok,"t_select_stat,\"s\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_insert_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_insert_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_varcall_expr,table,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<i_insert_body>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_insert_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_insert_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_insert_stat");
    auto&ok=$.ok;
    ok=dev.go_const("insert");$(ok,",\"i\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("into");$(ok,",\"i\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(table);$(ok,"t_varcall_expr,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(body);$(ok,"TAutoPtr<i_insert_body>,\"sv\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_update_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_update_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_name,col,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(t_lev08,expr,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_update_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_update_item
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_update_item");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(col);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("=");$(ok,",\"=\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(expr);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    return ok;
  }
};
struct t_update_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_update_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,table,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<t_update_item>,arr,DEF,$,$)\
ADDVAR(TAutoPtr<t_where_clause>,where,DEF,$,$)\
ADDEND()
//=====+>>>>>t_update_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_update_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_update_stat");
    auto&ok=$.ok;
    ok=dev.go_const("update");$(ok,",\"u\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(table);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("set");$(ok,",\"s\"");
    if(!ok)return ok;
    {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_update_item>,gen_dips(\"\\t\\nAZaz\")+\"\\r -/_\"");}
    {bool ok=dev.go_auto(where);$(ok,"TAutoPtr<t_where_clause>,\"w\"");}
    return ok;
  }
};
struct t_delete_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_name,table,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<t_where_clause>,where,DEF,$,$)\
ADDEND()
//=====+>>>>>t_delete_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_delete_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_delete_stat");
    auto&ok=$.ok;
    ok=dev.go_const("delete");$(ok,",\"d\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_const("from");$(ok,",\"f\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    ok=dev.go_auto(table);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
    {bool ok=dev.go_auto(where);$(ok,"TAutoPtr<t_where_clause>,\"w\"");}
    return ok;
  }
};
struct t_sep_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sep_stat");
    auto&ok=$.ok;
    ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_semicolon_stat:public i_data_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon_stat)PARENT(i_data_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_semicolon_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_semicolon_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_semicolon_stat");
    auto&ok=$.ok;
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sql_script{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_script)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_data_stat>>,stats,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sql_script
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sql_script
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sql_script");
    auto&ok=$.ok;
    ok=dev.go_auto(stats);$(ok,"vector<TAutoPtr<i_data_stat>>,\"\\t\\n\\r -/;disu\"");
    if(!ok)return ok;
    return ok;
  }
};
void i_sep::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '\t':
    case '\n':
    case '\r':
    case ' ':F(t_sep_seq);
    case '/':F(t_sql_block_comment);
    case '-':F(t_sql_line_comment);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void i_str_item::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,4> lex={
    F(t_str_raw,gen_dips("\x00\t\x0B&([]\xFF")),
    F(t_str_hex,"\\"),
    F(t_str_unicode,"\\"),
    F(t_str_escape,"\\")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_expr::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,10> lex={
    F(t_str_expr,"'"),
    F(t_bool_expr,"ft"),
    F(t_star_expr,"*"),
    F(t_block_expr,"("),
    F(t_varcall_expr,gen_dips("AZaz")+"_"),
    F(t_case_expr,"c"),
    F(t_num_expr,".0123456789"),
    F(t_nullif_func,"in"),
    F(t_host_expr,":"),
    F(t_subquery_expr,"(")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_table_expr::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,3> lex={
    F(t_joined_table_part,"\t\n\r -/fijlr"),
    F(t_table_expr,gen_dips("AZaz")+"_"),
    F(t_subquery,"(")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_in_operand::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,2> lex={
    F(t_in_list,"("),
    F(t_in_subquery,"(")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_data_stat::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,7> lex={
    F(t_select_stat,"s"),
    F(t_union_stat,"s"),
    F(t_insert_stat,"i"),
    F(t_update_stat,"u"),
    F(t_delete_stat,"d"),
    F(t_sep_stat,"\t\n\r -/"),
    F(t_semicolon_stat,";")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_insert_body::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case 'v':F(t_values_body);
    case 's':F(t_select_body);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_lev06::i_lev06_ext::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,3> lex={
    F(t_between,"\t\n\r -/bn"),
    F(t_is_null,"\t\n\r -/i"),
    F(t_in_list,"\t\n\r -/in")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void t_num_expr::i_num_part::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':F(t_int_part);
    case '0':F(t_zero_part);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_num_expr::i_impl::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '.':F(t_impl2);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':F(t_impl);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_column_list::i_clist_item::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,2> lex={
    F(t_arr,gen_dips("\t\n'(*+-:AZaz")+"\r _"),
    F(t_star,"*")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
/*
//list of types:
F(t_sep_seq)F(t_sql_block_comment)F(t_sql_line_comment)F(t_sep)F(t_str_raw)
F(t_str_hex)F(t_str_unicode)F(t_str_escape)F(t_str_impl)F(t_str_expr)
F(t_bool_expr)F(t_name)F(t_lev01)F(t_lev02)F(t_lev03)F(t_lev04)F(t_lev05)
F(t_lev06)F(t_lev07)F(t_lev08)F(t_star_expr)F(t_lev08_with_sep)F(t_block_expr)
F(t_varcall_expr)F(t_when_branch)F(t_else_branch)F(t_case_expr)F(t_as_alias)
F(t_joined_table_part)F(t_table_expr)F(t_subquery)F(t_in_list)F(t_in_subquery)
F(t_frac_part)F(t_exp_part)F(t_num_expr)F(t_nullif_func)F(t_host_expr)
F(t_where_clause)F(t_column_item)F(t_column_list)F(t_group_by_clause)
F(t_having_clause)F(t_order_by_item)F(t_order_by_clause)F(t_distinct_kw)
F(t_select_stat)F(t_subquery_expr)F(t_union_part)F(t_union_stat)F(t_values_row)
F(t_values_body)F(t_select_body)F(t_insert_stat)F(t_update_item)
F(t_update_stat)F(t_delete_stat)F(t_sep_stat)F(t_semicolon_stat)F(t_sql_script)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
%0at%5fsep%5fseq%3ai%5fsep%7b%0a%20%20string%20body%3dany%28%22%20%5ct%5cr%5cn%2
2%29%3b%0a%7d%0at%5fsql%5fblock%5fcomment%3ai%5fsep%7b%0a%20%20%22%2f%2a%22%0a%2
0%20string%20body%3dend%28%22%2a%2f%22%29%3b%0a%7d%0at%5fsql%5fline%5fcomment%3a
i%5fsep%7b%0a%20%20%22%2d%2d%22%0a%20%20string%20body%3dany%28dip%5finv%28%22%5c
n%22%29%29%3f%3b%0a%7d%0at%5fsep%7b%0a%20%20%2f%2ft%5fimpl%7b%0a%20%20%2f%2f%20%
20vector%3cTAutoPtr%3ci%5fsep%3e%3e%20arr%3b%0a%20%20%2f%2f%7d%0a%20%20%2f%2fstr
ing%20value%3dstr%3ct%5fimpl%3e%28%29%3b%0a%20%20vector%3cTAutoPtr%3ci%5fsep%3e%
3e%20arr%3b%0a%7d%0a%0atypedef%20array%3cchar%2c2%3e%20ARRAY2char%3b%0atypedef%2
0array%3cchar%2c4%3e%20ARRAY4char%3b%0ausing%20%22%20%22%20as%20t%5fsep%3b%0a%0a
t%5fstr%5fraw%3ai%5fstr%5fitem%7b%0a%20%20string%20body%3dany%28dip%5finv%28%22%
27%5c%5c%5cn%22%29%29%3b%0a%7d%0at%5fstr%5fhex%3ai%5fstr%5fitem%7b%0a%20%20%22%5
c%5cx%22%0a%20%20ARRAY2char%20body%3dany%5farr%5fchar%28gen%5fdips%28%2209afAF%2
2%29%29%3b%0a%7d%0at%5fstr%5funicode%3ai%5fstr%5fitem%7b%0a%20%20%22%5c%5cu%22%0
a%20%20ARRAY4char%20body%3dany%5farr%5fchar%28gen%5fdips%28%2209%22%29%29%3b%0a%
7d%0at%5fstr%5fescape%3ai%5fstr%5fitem%7b%0a%20%20%22%5c%5c%22%0a%20%20char%20bo
dy%3dany%5fchar%28%22tfbrn%5c%5c%27%5c%22%22%2bgen%5fdips%28%2207%22%29%29%3b%0a
%7d%0at%5fstr%5fimpl%7b%0a%20%20t%5fone%7b%22%27%22%20vector%3cTAutoPtr%3ci%5fst
r%5fitem%3e%3e%20arr%3b%20%22%27%22%7d%0a%20%20vector%3ct%5fone%3e%20arr%3b%0a%7
d%0a%0at%5fstr%5fexpr%3ai%5fexpr%7b%0a%20%20string%20value%3dstr%3ct%5fstr%5fimp
l%3e%28%29%3b%0a%7d%0a%0at%5fbool%5fexpr%3ai%5fexpr%7b%0a%20%20string%20value%3d
any%5fstr%5ffrom%5fvec%28split%28%22true%2cfalse%22%2c%22%2c%22%29%29%3b%0a%7d%0
a%0at%5fname%7b%0a%20%20t%5fkeyword%7b%0a%20%20%20%20string%20value%3dany%5fstr%
5ffrom%5fvec%28split%28%22select%2cinsert%2cupdate%2cdelete%2cfrom%2cwhere%2cand
%2cor%2cnot%2cin%2cbetween%2clike%2cis%2cnull%2cdistinct%2cas%2cjoin%2cinner%2cl
eft%2cright%2cfull%2con%2cusing%2cgroup%2chaving%2corder%2cby%2casc%2cdesc%2cuni
on%2call%2ccreate%2cdrop%2ctable%2cindex%2cview%2ctrigger%2cprocedure%2cfunction
%2ccase%2cwhen%2cthen%2celse%2cend%2ccast%2cconvert%2cset%2cvalues%2cinto%2cexis
ts%2climit%2coffset%2ctrue%2cfalse%2cnullif%2cifnull%2csingle%22%2c%22%2c%22%29%
29%3b%0a%20%20%7d%0a%20%20t%5fimpl%7b%0a%20%20%20%20char%20A%3dany%5fchar%28gen%
5fdips%28%22azAZ%22%29%2b%22%5f%22%29%3b%0a%20%20%20%20string%20B%3dany%28gen%5f
dips%28%22azAZ09%22%29%2b%22%5f%22%29%3f%3b%0a%20%20%7d%0a%20%20t%5fimpl%5fex%7b
%0a%20%20%20%20t%5fimpl%20impl%3ddiff%3ct%5fkeyword%3e%28%29%3b%0a%20%20%7d%0a%2
0%20string%20value%3dstr%3ct%5fimpl%5fex%3e%28%29%3b%0a%7d%0a%0at%5flev01%7b%0a%
20%20string%20oper%3dany%5fstr%5ffrom%5fvec%28split%28%22not%2c%2b%2c%2d%22%2c%2
2%2c%22%29%29%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fexpr%3e%20expr%3
b%0a%7d%0at%5flev02%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fve
c%28split%28%22%2a%2c%2f%2c%25%2cdiv%2cmod%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%
5fitem%7b%22%20%22%3f%20t%5foper%20oper%3b%22%20%22%3ft%5flev01%20expr%3b%7d%0a%
20%20t%5flev01%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5fle
v03%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%
2b%2c%2d%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%2
0oper%3b%22%20%22%3ft%5flev02%20expr%3b%7d%0a%20%20t%5flev02%20expr%3b%0a%20%20v
ector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev04%7b%0a%20%20t%5foper%7bstring%2
0value%3dany%5fstr%5ffrom%5fvec%28split%28%22shl%2cshr%22%2c%22%2c%22%29%29%3b%7
d%0a%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20oper%3b%22%20%22%3ft%5flev03%20ex
pr%3b%7d%0a%20%20t%5flev03%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a
%7d%0at%5flev05%7b%0a%20%20t%5foper%7b%22%7c%7c%22%5b%3a%3a%5dinline%20static%20
const%20string%20value%3d%22%7c%7c%22%3b%7d%0a%20%20t%5fitem%7b%22%20%22%3ft%5fo
per%20oper%3b%22%20%22%3ft%5flev04%20expr%3b%7d%0a%20%20t%5flev04%20expr%3b%0a%2
0%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev06%7b%0a%20%20t%5fnot%7b%22n
ot%22%7d%0a%20%20t%5fbetween%3ai%5flev06%5fext%7b%0a%20%20%20%20TAutoPtr%3ct%5fn
ot%3e%20not%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22between%22%0a%20%2
0%20%20%22%20%22%3f%0a%20%20%20%20t%5flev05%20low%3b%0a%20%20%20%20%22%20%22%3f%
0a%20%20%20%20%22and%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5flev05%20hig
h%3b%0a%20%20%7d%0a%20%20t%5fis%5fnull%3ai%5flev06%5fext%7b%0a%20%20%20%20%22%20
%22%3f%0a%20%20%20%20%22is%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%
3ct%5fnot%3e%20not%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22null%22%0a%
20%20%7d%0a%20%20t%5fin%5flist%3ai%5flev06%5fext%7b%0a%20%20%20%20%22%20%22%3f%0
a%20%20%20%20TAutoPtr%3ct%5fnot%3e%20not%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%
20%20%20%22in%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ci%5fin%5fop
erand%3e%20operand%3b%0a%20%20%7d%0a%20%20%2f%2a%0a%20%20t%5fin%5fselect%3ai%5fl
ev06%5fext%7b%20%2d%20%e4%e0%20%ed%f3%20%ed%e0%f4%e8%ed%2c%20%ff%20%eb%f3%f7%f8%
e5%20%e7%e0%ef%e8%f5%e0%fe%20%f1%e5%eb%e5%ea%f2%20%e2%20i%5fexpr%2c%20%e0%20%f2%
ee%20%ff%20%e7%e0%e4%e0%eb%e1%e0%eb%f1%ff%20%f1%20%ed%e8%ec%20%e2%ee%e7%e8%f2%f1
%ff%2e%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22in%22%0a%20%20%20%20%22%20%22
%3f%0a%20%20%20%20%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fselect%
5fstat%20query%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%29%22%0a%20%20%7d
%2a%2f%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%
3d%2c%3c%3e%2c%3c%2c%3e%2c%3c%3d%2c%3e%3d%2clike%2cin%22%2c%22%2c%22%29%29%3b%7d
%0a%20%20t%5fitem%7bt%5foper%20oper%3b%22%20%22%3ft%5flev05%20expr%3b%22%20%22%3
f%7d%0a%20%20t%5flev05%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fitem%
3e%20arr%3f%3b%0a%20%20TAutoPtr%3ci%5flev06%5fext%3e%20ext%3f%3b%0a%0a%20%20%2f%
2f%20%2d%2d%2d%20IN%20%28%f1%ef%e8%f1%ee%ea%29%20%2d%2d%2d%0a%20%20%2f%2ft%5fin%
5flist%7b%20%2d%20%ed%e5%20%ed%f3%e6%e5%ed%2c%20%f2%2e%ea%20%f1%ea%ee%e1%ea%e8%2
0%e2%20i%5fexpr%20%fd%f2%ee%20%ef%f0%ee%e6%f3%fe%f2%2e%0a%20%20%2f%2f%20%20%22%2
0%22%3f%0a%20%20%2f%2f%20%20%22in%22%0a%20%20%2f%2f%20%20%22%20%22%3f%0a%20%20%2
f%2f%20%20%22%28%22%0a%20%20%2f%2f%20%20%22%20%22%3f%0a%20%20%2f%2f%20%20t%5flev
05%20first%3b%0a%20%20%2f%2f%20%20vector%3ct%5flev05%3e%20rest%3dvec%28%22%2c%22
%29%3f%3b%0a%20%20%2f%2f%20%20%22%20%22%3f%0a%20%20%2f%2f%20%20%22%29%22%0a%20%2
0%2f%2f%7d%0a%7d%0at%5flev07%7b%0a%20%20t%5foper%7b%22and%22%5b%3a%3a%5dinline%2
0static%20const%20string%20value%3d%22and%22%3b%7d%0a%20%20t%5fitem%7b%22%20%22%
3ft%5foper%20oper%3b%22%20%22%20t%5flev06%20expr%3b%7d%0a%20%20t%5flev06%20expr%
3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev08%7b%0a%20%20t%5fope
r%7b%22or%22%5b%3a%3a%5dinline%20static%20const%20string%20value%3d%22or%22%3b%7
d%0a%20%20t%5fitem%7b%22%20%22%3ft%5foper%20oper%3b%22%20%22%20t%5flev07%20expr%
3b%7d%0a%20%20t%5flev07%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d
%0a%2f%2a%0at%5fcall%5fparam%7b%0a%20%20%22%20%22%3f%0a%20%20t%5flev08%20expr%3b
%0a%20%20%22%20%22%3f%0a%7d%0at%5fcall%5fparams%7b%0a%20%20%22%28%22%0a%20%20%22
%20%22%3f%0a%20%20vector%3ct%5fcall%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3b%0a%
20%20%22%20%22%3f%0a%20%20%22%29%22%0a%7d%2a%2f%0at%5fstar%5fexpr%3ai%5fexpr%7b%
22%2a%22%7d%0at%5flev08%5fwith%5fsep%7b%22%20%22%3ft%5flev08%20expr%3b%22%20%22%
3f%7d%0at%5fblock%5fexpr%3ai%5fexpr%7b%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a
%20%20vector%3ct%5flev08%5fwith%5fsep%3e%20arr%3dvec%28%22%2c%22%29%3b%0a%20%20%
22%20%22%3f%0a%20%20%22%29%22%0a%7d%0at%5fvarcall%5fexpr%3ai%5fexpr%7b%0a%20%20t
%5fitem%7b%22%2e%22%20%22%20%22%3f%20t%5fname%20name%3b%20%22%20%22%3f%7d%0a%20%
20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fitem%3e%20arr%3f%
3b%0a%20%20TAutoPtr%3ct%5fblock%5fexpr%3e%20params%3f%3b%0a%7d%0at%5fwhen%5fbran
ch%7b%0a%20%20%22when%22%0a%20%20%22%20%22%3f%0a%20%20t%5flev08%20cond%3b%0a%20%
20%22%20%22%3f%0a%20%20%22then%22%0a%20%20%22%20%22%3f%0a%20%20t%5flev08%20resul
t%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5felse%5fbranch%7b%0a%20%20%22else%22%0a%
20%20%22%20%22%3f%0a%20%20t%5flev08%20result%3b%0a%7d%0a%0at%5fcase%5fexpr%3ai%5
fexpr%7b%0a%20%20%22case%22%0a%20%20%22%20%22%3f%0a%20%20t%5flev08%20input%3f%3b
%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fwhen%5fbranch%3e%20arr%3b%0a%20%20TAu
toPtr%3ct%5felse%5fbranch%3e%20else%5fbranch%3f%3b%0a%20%20%22%20%22%3f%0a%20%20
%22end%22%0a%7d%0a%2f%2a%0at%5ffunc%3ai%5fexpr%7b%0a%20%20t%5fname%20func%3b%0a%
20%20%2f%2fstring%20func%3dany%5fstr%5ffrom%5fvec%28split%28%22count%2csum%2cmin
%2cmax%2cavg%22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22%3f%0a%20%20t%5fblock%5fex
pr%20expr%3b%0a%7d%2a%2f%0a%0at%5fas%5falias%7bt%5fas%5fopt%7b%22as%22%7d%20TAut
oPtr%3ct%5fas%5fopt%3e%20opt%3f%3b%20%22%20%22%3f%20t%5fname%20alias%3b%7d%0a%0a
t%5fjoined%5ftable%5fpart%3ai%5ftable%5fexpr%7b%0a%20%20%22%20%22%3f%0a%20%20str
ing%20join%5ftype%3dany%5fstr%5ffrom%5fvec%28split%28%22inner%20join%2cleft%20jo
in%2cright%20join%2cfull%20join%2cjoin%22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22
%3f%0a%20%20t%5fname%20right%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fas%5
falias%3e%20as%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22on%22%0a%20%20%22%20%22%3f%
0a%20%20t%5flev08%20on%5fcond%3b%0a%7d%0a%0at%5ftable%5fexpr%3ai%5ftable%5fexpr%
7b%0a%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fas%5fa
lias%3e%20as%3f%3b%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fjoined%5ftable%5fpa
rt%3e%20arr%3f%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fsubquery%3ai%5ftable%5fexp
r%7b%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fdata%5fstat%3
e%20query%3b%0a%20%20%22%20%22%3f%0a%20%20%22%29%22%0a%20%20%22%20%22%3f%0a%20%2
0TAutoPtr%3ct%5fas%5falias%3e%20as%3f%3b%0a%7d%0a%0at%5fin%5flist%3ai%5fin%5fope
rand%7b%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5flev08%3e%20a
rr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%29%22%0a%7d%0a%0a
t%5fin%5fsubquery%3ai%5fin%5foperand%7b%0a%20%20t%5fsubquery%20body%3b%0a%7d%0a%
0at%5ffrac%5fpart%7b%0a%20%20%22%2e%22%0a%20%20string%20digits%3dany%28gen%5fdip
s%28%2209%22%29%29%3b%0a%7d%0at%5fexp%5fpart%7b%0a%20%20char%20e%3dany%5fchar%28
%22eE%22%29%3b%0a%20%20string%20sign%3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2
c%2d%22%2c%22%2c%22%29%29%3f%3b%0a%20%20string%20digits%3dany%28gen%5fdips%28%22
09%22%29%29%3b%0a%7d%0a%0at%5fnum%5fexpr%3ai%5fexpr%7b%0a%20%20t%5fint%5fpart%3a
i%5fnum%5fpart%7b%0a%20%20%20%20char%20first%3dany%5fchar%28gen%5fdips%28%2219%2
2%29%29%3b%0a%20%20%20%20string%20rest%3dany%28gen%5fdips%28%2209%22%29%29%3f%3b
%0a%20%20%7d%0a%20%20t%5fzero%5fpart%3ai%5fnum%5fpart%7b%220%22%7d%0a%20%20t%5fi
mpl2%3ai%5fimpl%7b%0a%20%20%20%20TAutoPtr%3ct%5ffrac%5fpart%3e%20frac%3b%0a%20%2
0%20%20TAutoPtr%3ct%5fexp%5fpart%3e%20exp%3f%3b%0a%20%20%7d%0a%20%20t%5fimpl%3ai
%5fimpl%7b%0a%20%20%20%20%2f%2fstring%20sign%3dany%5fstr%5ffrom%5fvec%28split%28
%22%2b%2c%2d%22%2c%22%29%29%3f%3b%0a%20%20%20%20TAutoPtr%3ci%5fnum%5fpart%3e%20i
nt%5fpart%3b%0a%20%20%20%20TAutoPtr%3ct%5ffrac%5fpart%3e%20frac%3f%3b%0a%20%20%2
0%20TAutoPtr%3ct%5fexp%5fpart%3e%20exp%3f%3b%0a%20%20%7d%0a%20%20string%20value%
3dstr%3cTAutoPtr%3ci%5fimpl%3e%3e%28%29%3b%0a%7d%0a%0at%5fnullif%5ffunc%3ai%5fex
pr%7b%0a%20%20string%20kw%3dany%5fstr%5ffrom%5fvec%28split%28%22nullif%2cifnull%
22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22%3f%0a%20%20%22%28%22%0a%20%20%22%20%22
%3f%0a%20%20t%5flev08%20left%3b%0a%20%20%22%20%22%3f%0a%20%20%22%2c%22%0a%20%20%
22%20%22%3f%0a%20%20t%5flev08%20right%3b%0a%20%20%22%20%22%3f%0a%20%20%22%29%22%
0a%7d%0a%0at%5fhost%5fexpr%3ai%5fexpr%7b%0a%20%20%22%3a%22%0a%20%20%22%20%22%3f%
0a%20%20t%5fname%20var%3b%2f%2f%20TODO%3a%20replace%20with%20any%20pascal%20expr
%0a%7d%0a%0at%5fwhere%5fclause%7b%0a%20%20%22where%22%0a%20%20%22%20%22%3f%0a%20
%20t%5flev08%20cond%3b%0a%7d%0a%0at%5fcolumn%5fitem%7b%0a%20%20%22%20%22%3f%0a%2
0%20t%5flev08%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fas%5falias%3
e%20as%3f%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fcolumn%5flist%7b%0a%20%20t%5far
r%3ai%5fclist%5fitem%7bvector%3ct%5fcolumn%5fitem%3e%20arr%3dvec%28%22%2c%22%29%
3b%7d%0a%20%20t%5fstar%3ai%5fclist%5fitem%7b%22%2a%22%7d%0a%20%20TAutoPtr%3ci%5f
clist%5fitem%3e%20item%3b%0a%7d%0a%0at%5fgroup%5fby%5fclause%7b%0a%20%20%22group
%22%0a%20%20%22%20%22%3f%0a%20%20%22by%22%0a%20%20%22%20%22%3f%0a%20%20t%5fcolum
n%5flist%20cols%3b%0a%7d%0a%0at%5fhaving%5fclause%7b%0a%20%20%22having%22%0a%20%
20%22%20%22%3f%0a%20%20t%5flev08%20cond%3b%0a%7d%0a%0at%5forder%5fby%5fitem%7b%0
a%20%20%22%20%22%3f%0a%20%20t%5fvarcall%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a
%20%20string%20order%3dany%5fstr%5ffrom%5fvec%28split%28%22asc%2cdesc%22%2c%22%2
c%22%29%29%3f%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5forder%5fby%5fclause%7b%0a%2
0%20%22order%22%20%22%20%22%3f%20%22by%22%0a%20%20%22%20%22%3f%0a%20%20vector%3c
t%5forder%5fby%5fitem%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%7d%0at%5fdistinct%5
fkw%7b%22distinct%22%7d%0a%0at%5fselect%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%22s
elect%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fdistinct%5fkw%3e%20distinct
%3f%3b%0a%20%20%22%20%22%3f%0a%20%20t%5fcolumn%5flist%20cols%3b%0a%20%20%22%20%2
2%3f%0a%20%20%22from%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5ftable%5fexpr
%3e%20table%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fwhere%5fclause%3e%20w
here%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fgroup%5fby%5fclause%3e%20
group%5fby%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fhaving%5fclause%3e%
20having%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5forder%5fby%5fclause%3
e%20order%5fby%3f%3b%0a%7d%0a%0at%5fsubquery%5fexpr%3ai%5fexpr%7b%0a%20%20%22%28
%22%0a%20%20%22%20%22%3f%0a%20%20t%5fselect%5fstat%20query%3b%0a%20%20%22%20%22%
3f%0a%20%20%22%29%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fas%5falias%3e%2
0as%3f%3b%0a%7d%0a%0at%5funion%5fpart%7b%0a%20%20%22%20%22%3f%0a%20%20string%20o
p%3dany%5fstr%5ffrom%5fvec%28split%28%22union%2cunion%20all%22%2c%22%2c%22%29%29
%3b%0a%20%20%22%20%22%3f%0a%20%20t%5fselect%5fstat%20query%3b%0a%7d%0a%0at%5funi
on%5fstat%3ai%5fdata%5fstat%7b%0a%20%20t%5fselect%5fstat%20first%3b%0a%20%20vect
or%3ct%5funion%5fpart%3e%20unions%3b%0a%7d%0a%0at%5fvalues%5frow%7b%0a%20%20%22%
20%22%3f%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5flev08%5fwit
h%5fsep%3e%20arr%3dvec%28%22%2c%22%29%3b%0a%20%20%22%20%22%3f%0a%20%20%22%29%22%
0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fvalues%5fbody%3ai%5finsert%5fbody%7b%0a%20%2
0%22values%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fvalues%5frow%3e%20arr%3d
vec%28%22%2c%22%29%3f%3b%0a%7d%0a%0at%5fselect%5fbody%3ai%5finsert%5fbody%7b%0a%
20%20t%5fselect%5fstat%20query%3b%0a%7d%0a%0at%5finsert%5fstat%3ai%5fdata%5fstat
%7b%0a%20%20%22insert%22%0a%20%20%22%20%22%3f%0a%20%20%22into%22%0a%20%20%22%20%
22%3f%0a%20%20t%5fvarcall%5fexpr%20table%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPt
r%3ci%5finsert%5fbody%3e%20body%3b%0a%7d%0a%0at%5fupdate%5fitem%7b%0a%20%20%22%2
0%22%3f%0a%20%20t%5fname%20col%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3d%22%0a%20%2
0%22%20%22%3f%0a%20%20t%5flev08%20expr%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fup
date%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%22update%22%0a%20%20%22%20%22%3f%0a%20
%20t%5fname%20table%3b%0a%20%20%22%20%22%3f%0a%20%20%22set%22%0a%20%20vector%3ct
%5fupdate%5fitem%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20TAutoPtr%3ct%5fwher
e%5fclause%3e%20where%3f%3b%0a%7d%0a%0at%5fdelete%5fstat%3ai%5fdata%5fstat%7b%0a
%20%20%22delete%22%0a%20%20%22%20%22%3f%0a%20%20%22from%22%0a%20%20%22%20%22%3f%
0a%20%20t%5fname%20table%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fwhere%5f
clause%3e%20where%3f%3b%0a%7d%0a%0at%5fsep%5fstat%3ai%5fdata%5fstat%7b%22%20%22%
7d%0at%5fsemicolon%5fstat%3ai%5fdata%5fstat%7b%22%3b%22%7d%0a%0at%5fsql%5fscript
%7b%0a%20%20vector%3cTAutoPtr%3ci%5fdata%5fstat%3e%3e%20stats%3b%0a%7d
*/