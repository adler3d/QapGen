// 5358.817100 ms
//===>>===i_expr_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_string)\
  ADD(t_number)\
  ADD(t_sql_expr)\
  ADD(t_sb_expr)\
  ADD(t_varcall_expr)\
  ADD(t_block_expr)\
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
//  void Do(t_string&r){}
//  void Do(t_number&r){}
//  void Do(t_sql_expr&r){}
//  void Do(t_sb_expr&r){}
//  void Do(t_varcall_expr&r){}
//  void Do(t_block_expr&r){}
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
      F(t_string);
      F(t_number);
      F(t_sql_expr);
      F(t_sb_expr);
      F(t_varcall_expr);
      F(t_block_expr);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_var_type_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_array_type)\
  ADD(t_var_type)\
ADDEND()
class i_var_type;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_var_type_visitor{
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
  static TYPE*UberCast(i_var_type*p){
    if(!p)return nullptr;Is<TYPE,i_var_type_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_var_type*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_var_type_visitor{
//  void Do(t_array_type&r){}
//  void Do(t_var_type&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_var_type_visitor
struct i_var_type{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_var_type)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_var_type
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_var_type
public:
  typedef i_var_type_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_var_type()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_array_type);
      F(t_var_type);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
//===>>===i_stat_visitor
#define DEF_PRO_BLANK()
#define LIST(ADDBEG,ADD,ADDEND)\
ADDBEG()\
  ADD(t_var)\
  ADD(t_type)\
  ADD(t_exit_stat)\
  ADD(t_break_stat)\
  ADD(t_continue_stat)\
  ADD(t_block_stat)\
  ADD(t_if_stat)\
  ADD(t_assign_stat)\
  ADD(t_for_stat)\
  ADD(t_while_stat)\
  ADD(t_repeat_stat)\
  ADD(t_case_stat)\
  ADD(t_const)\
  ADD(t_expr_stat)\
  ADD(t_semicolon_stat)\
  ADD(t_func_or_proc_stat)\
ADDEND()
class i_stat;
#define ADD(TYPE)class TYPE;
LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
#undef ADD
class i_stat_visitor{
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
  static TYPE*UberCast(i_stat*p){
    if(!p)return nullptr;Is<TYPE,i_stat_visitor> IS;p->Use(IS);return IS.ptr;
  }
  #else
  template<class TYPE>
  static TYPE*UberCast(i_stat*p){return dynamic_cast<TYPE*>(p);}
  #endif
};
//struct t_visitor:public i_stat_visitor{
//  void Do(t_var&r){}
//  void Do(t_type&r){}
//  void Do(t_exit_stat&r){}
//  void Do(t_break_stat&r){}
//  void Do(t_continue_stat&r){}
//  void Do(t_block_stat&r){}
//  void Do(t_if_stat&r){}
//  void Do(t_assign_stat&r){}
//  void Do(t_for_stat&r){}
//  void Do(t_while_stat&r){}
//  void Do(t_repeat_stat&r){}
//  void Do(t_case_stat&r){}
//  void Do(t_const&r){}
//  void Do(t_expr_stat&r){}
//  void Do(t_semicolon_stat&r){}
//  void Do(t_func_or_proc_stat&r){}
//};
#undef LIST
#undef DEF_PRO_BLANK
//===<<===i_stat_visitor
struct i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>i_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====i_stat
public:
  typedef i_stat_visitor i_visitor;
  virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
  virtual ~i_stat()=default;
public:
  virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
  struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
  {
    #include "QapLexPolyBeg.inl"
    void load();/*
    {
      F(t_var);
      F(t_type);
      F(t_exit_stat);
      F(t_break_stat);
      F(t_continue_stat);
      F(t_block_stat);
      F(t_if_stat);
      F(t_assign_stat);
      F(t_for_stat);
      F(t_while_stat);
      F(t_repeat_stat);
      F(t_case_stat);
      F(t_const);
      F(t_expr_stat);
      F(t_semicolon_stat);
      F(t_func_or_proc_stat);
      (void)count;(void)first_id;(void)out_arr;(void)this;
      main();
      return scope.ok;
    }*/
    #include "QapLexPolyEndNoTemplate.inl"
  };
};
struct t_expr;
struct t_pascal_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_pascal_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_expr>,expr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_pascal_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_pascal_expr
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_pascal_expr");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"TAutoPtr<t_expr>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_sql{
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
    typedef t_sql::i_sep i_sep;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)OWNER(t_sql)
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
    typedef t_sql::i_str_item i_str_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_str_item)OWNER(t_sql)
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
    typedef t_sql::i_expr i_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_expr)OWNER(t_sql)
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
    typedef t_sql::i_table_expr i_table_expr;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_table_expr)OWNER(t_sql)
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
    typedef t_sql::i_in_operand i_in_operand;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_in_operand)OWNER(t_sql)
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
    typedef t_sql::i_data_stat i_data_stat;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_data_stat)OWNER(t_sql)
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
    typedef t_sql::i_insert_body i_insert_body;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sql::U U;//typedef t_sql::U U;
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_insert_body)OWNER(t_sql)
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_seq)PARENT(i_sep)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_sep_seq");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(" \t\r\n");
      ok=dev.go_any(body,g_static_var_0);$(ok,",\" \\t\\r\\n\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sql_block_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_block_comment)PARENT(i_sep)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_sql_block_comment");
      auto&ok=$.ok;
      ok=dev.go_const("/*");$(ok,",\"/\"");
      if(!ok)return ok;
      ok=dev.go_end(body,"*/");$(ok,",\"*\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sql_line_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_line_comment)PARENT(i_sep)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_sql_line_comment");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_sep>>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sep
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_sep");
      auto&ok=$.ok;
      ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_sep>>,\"\\t\\n\\r -/\"");
      if(!ok)return ok;
      return ok;
    }
  };
  typedef array<char,2> ARRAY2char;
  typedef array<char,4> ARRAY4char;
  struct t_str_raw:public i_str_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_raw)PARENT(i_str_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_str_raw");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(dip_inv("'\\\n"));
      ok=dev.go_any(body,g_static_var_0);$(ok,",gen_dips(\"\\x00\\t\\x0B&([]\\xFF\")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_str_hex:public i_str_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_hex)PARENT(i_str_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_str_hex");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_unicode)PARENT(i_str_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_str_unicode");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_escape)PARENT(i_str_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_str_escape");
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
        t_fallback $(dev,"t_sql::t_str_impl::t_one");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_impl)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<t_one>,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_str_impl
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_str_impl
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_str_impl");
      auto&ok=$.ok;
      ok=dev.go_auto(arr);$(ok,"vector<t_one>,\"'\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_str_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_str_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_str_expr");
      auto&ok=$.ok;
      ok=dev.go_str<t_str_impl>(value);$(ok,"t_str_impl,\"'\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_bool_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_bool_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_bool_expr");
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
        t_fallback $(dev,"t_sql::t_name::t_keyword");
        auto&ok=$.ok;
        static const auto g_static_var_0=QapStrFinder::fromArr(split("select,insert,update,delete,from,where,and,or,not,in,between,like,is,null,distinct,as,join,on,using,having,union,all,create,drop,table,index,view,trigger,procedure,function,case,else,end,cast,convert,set,values,into,exists,limit,offset,true,false,nullif,ifnull,single",","));
        ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",gen_dips(\"afhjnpsw\")+\"l\"");
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
        t_fallback $(dev,"t_sql::t_name::t_impl");
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
        t_fallback $(dev,"t_sql::t_name::t_impl_ex");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_name
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_name
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_name");
      auto&ok=$.ok;
      ok=dev.go_str<t_impl_ex>(value);$(ok,"t_impl_ex,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_lev01{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev01)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev01");
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
        t_fallback $(dev,"t_sql::t_lev02::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev02::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev02)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev02");
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
        t_fallback $(dev,"t_sql::t_lev03::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev03::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev03)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev03");
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
        t_fallback $(dev,"t_sql::t_lev04::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev04::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev04)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev04");
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
        t_fallback $(dev,"t_sql::t_lev05::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev05::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev05)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev05");
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
        t_fallback $(dev,"t_sql::t_lev06::t_not");
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
    ADDVAR(TAutoPtr<t_not>,neg,DEF,$,$)\
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
        t_fallback $(dev,"t_sql::t_lev06::t_between");
        auto&ok=$.ok;
        {bool ok=dev.go_auto(neg);$(ok,"TAutoPtr<t_not>,\"n\"");}
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
        t_fallback $(dev,"t_sql::t_lev06::t_is_null");
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
        t_fallback $(dev,"t_sql::t_lev06::t_in_list");
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
        t_fallback $(dev,"t_sql::t_lev06::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev06::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev06");
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
        t_fallback $(dev,"t_sql::t_lev07::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev07::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev07)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev07");
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
        t_fallback $(dev,"t_sql::t_lev08::t_oper");
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
        t_fallback $(dev,"t_sql::t_lev08::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev08");
      auto&ok=$.ok;
      ok=dev.go_auto(expr);$(ok,"t_lev07,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r -/o\"");}
      return ok;
    }
  public:
  };
  struct t_star_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_star_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_star_expr");
      auto&ok=$.ok;
      ok=dev.go_const("*");$(ok,",\"*\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_lev08_with_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev08_with_sep)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_lev08_with_sep");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev08,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
  struct t_block_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_block_expr");
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
        t_fallback $(dev,"t_sql::t_varcall_expr::t_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_varcall_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_varcall_expr");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_when_branch)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_when_branch");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else_branch)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_else_branch");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_case_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_case_expr");
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
        t_fallback $(dev,"t_sql::t_as_alias::t_as_opt");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_as_alias)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_as_alias");
      auto&ok=$.ok;
      {bool ok=dev.go_auto(opt);$(ok,"TAutoPtr<t_as_opt>,\"a\"");}
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(alias);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_joined_table_part:public i_table_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_joined_table_part)PARENT(i_table_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_joined_table_part");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_table_expr)PARENT(i_table_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_table_expr");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_subquery)PARENT(i_table_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_subquery");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_in_list)PARENT(i_in_operand)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_in_list");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_in_subquery)PARENT(i_in_operand)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_in_subquery");
      auto&ok=$.ok;
      ok=dev.go_auto(body);$(ok,"t_subquery,\"(\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_frac_part{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac_part)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,digits,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_frac_part
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_frac_part
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_frac_part");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp_part)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_exp_part");
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
        t_fallback $(dev,"t_sql::t_num_expr::t_int_part");
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
        t_fallback $(dev,"t_sql::t_num_expr::t_zero_part");
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
        t_fallback $(dev,"t_sql::t_num_expr::t_impl2");
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
        t_fallback $(dev,"t_sql::t_num_expr::t_impl");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num_expr)PARENT(i_expr)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_num_expr");
      auto&ok=$.ok;
      ok=dev.go_str<TAutoPtr<i_impl>>(value);$(ok,"TAutoPtr<i_impl>,\".0123456789\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_nullif_func:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_nullif_func)PARENT(i_expr)OWNER(t_sql)
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
  ADDVAR(t_sep,$sep11,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_nullif_func
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_nullif_func
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_nullif_func");
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
      {bool ok=dev.go_auto($sep11);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
  struct t_host_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_host_expr)PARENT(i_expr)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<t_pascal_expr>,expr,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_host_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_host_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_host_expr");
      auto&ok=$.ok;
      ok=dev.go_const(":");$(ok,",\":\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(expr);$(ok,"TAutoPtr<t_pascal_expr>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
  struct t_where_clause{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_where_clause)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_where_clause");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_column_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_column_item");
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
        t_fallback $(dev,"t_sql::t_column_list::t_arr");
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
        t_fallback $(dev,"t_sql::t_column_list::t_star");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_column_list)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(TAutoPtr<i_clist_item>,item,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_column_list
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_column_list
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_column_list");
      auto&ok=$.ok;
      ok=dev.go_auto(item);$(ok,"TAutoPtr<i_clist_item>,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      return ok;
    }
  public:
  };
  struct t_group_by_clause{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_group_by_clause)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_group_by_clause");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_having_clause)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_having_clause");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_order_by_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_order_by_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_order_by_clause)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_order_by_clause");
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
  struct t_select_stat:public i_data_stat{
    struct t_from{
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_from)OWNER(t_select_stat)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(t_sep,$sep1,DEF,$,$)\
    ADDVAR(TAutoPtr<i_table_expr>,table,DEF,$,$)\
    ADDVAR(t_sep,$sep3,DEF,$,$)\
    ADDEND()
    //=====+>>>>>t_from
    #include "QapGenStructNoTemplate.inl"
    //<<<<<+=====t_from
    public:
      bool go(i_dev&dev){
        t_fallback $(dev,"t_sql::t_select_stat::t_from");
        auto&ok=$.ok;
        ok=dev.go_const("from");$(ok,",\"f\"");
        if(!ok)return ok;
        {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
        ok=dev.go_auto(table);$(ok,"TAutoPtr<i_table_expr>,gen_dips(\"\\t\\nAZaz\")+\"\\r (-/_\"");
        if(!ok)return ok;
        {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
        return ok;
      }
    };
  #define DEF_PRO_NESTED(F)\
    /*<DEF_PRO_NESTED>*/\
    F(t_from)\
    /*</DEF_PRO_NESTED>*/
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_select_stat)PARENT(i_data_stat)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,kw,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(string,ad,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(t_column_list,cols,DEF,$,$)\
  ADDVAR(t_sep,$sep5,DEF,$,$)\
  ADDVAR(TAutoPtr<t_from>,from,DEF,$,$)\
  ADDVAR(TAutoPtr<t_where_clause>,where,DEF,$,$)\
  ADDVAR(t_sep,$sep8,DEF,$,$)\
  ADDVAR(TAutoPtr<t_group_by_clause>,group_by,DEF,$,$)\
  ADDVAR(t_sep,$sep10,DEF,$,$)\
  ADDVAR(TAutoPtr<t_having_clause>,having,DEF,$,$)\
  ADDVAR(t_sep,$sep12,DEF,$,$)\
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
      t_fallback $(dev,"t_sql::t_select_stat");
      auto&ok=$.ok;
      static const auto g_static_var_0=QapStrFinder::fromArr(split("select,single",","));
      ok=dev.go_any_str_from_vec(kw,g_static_var_0);$(ok,",\"s\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      static const auto g_static_var_2=QapStrFinder::fromArr(split("all,distinct",","));
      {bool ok=dev.go_any_str_from_vec(ad,g_static_var_2);$(ok,",\"ad\"");}
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      ok=dev.go_auto(cols);$(ok,"t_column_list,gen_dips(\"\\t\\n'(*+-:AZaz\")+\"\\r _\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(from);$(ok,"TAutoPtr<t_from>,\"f\"");}
      {bool ok=dev.go_auto(where);$(ok,"TAutoPtr<t_where_clause>,\"w\"");}
      {bool ok=dev.go_auto($sep8);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(group_by);$(ok,"TAutoPtr<t_group_by_clause>,\"g\"");}
      {bool ok=dev.go_auto($sep10);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(having);$(ok,"TAutoPtr<t_having_clause>,\"h\"");}
      {bool ok=dev.go_auto($sep12);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_auto(order_by);$(ok,"TAutoPtr<t_order_by_clause>,\"o\"");}
      return ok;
    }
  public:
  };
  struct t_subquery_expr:public i_expr{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_subquery_expr)PARENT(i_expr)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_select_stat,query,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDVAR(t_sep,$sep5,DEF,$,$)\
  ADDVAR(TAutoPtr<t_as_alias>,as,DEF,$,$)\
  ADDVAR(t_sep,$sep7,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_subquery_expr
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_subquery_expr
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_subquery_expr");
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
      {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      return ok;
    }
  };
  struct t_union_part{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_union_part)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_union_part");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_union_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_union_stat");
      auto&ok=$.ok;
      ok=dev.go_auto(first);$(ok,"t_select_stat,\"s\"");
      if(!ok)return ok;
      ok=dev.go_auto(unions);$(ok,"vector<t_union_part>,\"\\t\\n\\r -/u\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_values_row{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_values_row)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_values_row");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_values_body)PARENT(i_insert_body)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_values_body");
      auto&ok=$.ok;
      ok=dev.go_const("values");$(ok,",\"v\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r -/\"");}
      {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_values_row>,\"\\t\\n\\r (-/\"");}
      return ok;
    }
  };
  struct t_select_body:public i_insert_body{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_select_body)PARENT(i_insert_body)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_select_body");
      auto&ok=$.ok;
      ok=dev.go_auto(query);$(ok,"t_select_stat,\"s\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_insert_stat:public i_data_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_insert_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_insert_stat");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_update_item)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_update_item");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_update_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_update_stat");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_delete_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_delete_stat");
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
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_sep_stat");
      auto&ok=$.ok;
      ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r -/\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_semicolon_stat:public i_data_stat{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon_stat)PARENT(i_data_stat)OWNER(t_sql)
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
      t_fallback $(dev,"t_sql::t_semicolon_stat");
      auto&ok=$.ok;
      ok=dev.go_const(";");$(ok,",\";\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_script{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_script)OWNER(t_sql)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(vector<TAutoPtr<i_data_stat>>,stats,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_script
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_script
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sql::t_script");
      auto&ok=$.ok;
      ok=dev.go_auto(stats);$(ok,"vector<TAutoPtr<i_data_stat>>,\"\\t\\n\\r -/;disu\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_sep_seq          )\
  F(t_sql_block_comment)\
  F(t_sql_line_comment )\
  F(t_sep              )\
  F(t_str_raw          )\
  F(t_str_hex          )\
  F(t_str_unicode      )\
  F(t_str_escape       )\
  F(t_str_impl         )\
  F(t_str_expr         )\
  F(t_bool_expr        )\
  F(t_name             )\
  F(t_lev01            )\
  F(t_lev02            )\
  F(t_lev03            )\
  F(t_lev04            )\
  F(t_lev05            )\
  F(t_lev06            )\
  F(t_lev07            )\
  F(t_lev08            )\
  F(t_star_expr        )\
  F(t_lev08_with_sep   )\
  F(t_block_expr       )\
  F(t_varcall_expr     )\
  F(t_when_branch      )\
  F(t_else_branch      )\
  F(t_case_expr        )\
  F(t_as_alias         )\
  F(t_joined_table_part)\
  F(t_table_expr       )\
  F(t_subquery         )\
  F(t_in_list          )\
  F(t_in_subquery      )\
  F(t_frac_part        )\
  F(t_exp_part         )\
  F(t_num_expr         )\
  F(t_nullif_func      )\
  F(t_host_expr        )\
  F(t_where_clause     )\
  F(t_column_item      )\
  F(t_column_list      )\
  F(t_group_by_clause  )\
  F(t_having_clause    )\
  F(t_order_by_item    )\
  F(t_order_by_clause  )\
  F(t_select_stat      )\
  F(t_subquery_expr    )\
  F(t_union_part       )\
  F(t_union_stat       )\
  F(t_values_row       )\
  F(t_values_body      )\
  F(t_select_body      )\
  F(t_insert_stat      )\
  F(t_update_item      )\
  F(t_update_stat      )\
  F(t_delete_stat      )\
  F(t_sep_stat         )\
  F(t_semicolon_stat   )\
  F(t_script           )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()
//=====+>>>>>t_sql
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sql
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sql");
    auto&ok=$.ok;
    return ok;
  }
public:
};
//---
//2025.08.14 09:44:54.655
//t_true:i_expr{"true" " "?}
//t_false:i_expr{"false" " "?}
//t_nil:i_expr{"nil" " "?}
//t_null:i_expr{"null" " "?}
struct t_sep{
  //===>>===i_sep_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_comment)\
    ADD(t_c_comment)\
    ADD(t_raw_sep)\
  ADDEND()
  class i_sep;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_sep_visitor{
  public:
    typedef t_sep::i_sep i_sep;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sep::U U;//typedef t_sep::U U;
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
  //  void Do(t_comment&r){}
  //  void Do(t_c_comment&r){}
  //  void Do(t_raw_sep&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_sep_visitor
  struct i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_sep)OWNER(t_sep)
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
        F(t_comment);
        F(t_c_comment);
        F(t_raw_sep);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_comment)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,s,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_comment
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_comment
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sep::t_comment");
      auto&ok=$.ok;
      ok=dev.go_const("{");$(ok,",\"{\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(dip_inv("}"));
      ok=dev.go_any(s,g_static_var_1);$(ok,",gen_dips(\"\\x00|~\\xFF\")");
      if(!ok)return ok;
      ok=dev.go_const("}");$(ok,",\"}\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_c_comment:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_c_comment)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_c_comment
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_c_comment
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sep::t_c_comment");
      auto&ok=$.ok;
      ok=dev.go_const("//");$(ok,",\"/\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(dip_inv("\n\r"));
      ok=dev.go_any(body,g_static_var_1);$(ok,",gen_dips(\"\\x00\\t\\x0B\\x0C\\x0E\\xFF\")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_raw_sep:public i_sep{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw_sep)PARENT(i_sep)OWNER(t_sep)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,s,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw_sep
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw_sep
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sep::t_raw_sep");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(" \r\n\t");
      ok=dev.go_any(s,g_static_var_0);$(ok,",\"\\t\\n\\r \"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_comment  )\
  F(t_c_comment)\
  F(t_raw_sep  )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,value,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sep");
    auto&ok=$.ok;
    ok=dev.go_str<vector<TAutoPtr<i_sep>>>(value);$(ok,"vector<TAutoPtr<i_sep>>,\"\\t\\n\\r /{\"");
    if(!ok)return ok;
    return ok;
  }
public:
};
typedef array<char,2> ARRAY2char;
typedef array<char,4> ARRAY4char;
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("begin,end,var,procedure,function,if,then,else,for,to,downto,do,while,repeat,until,case,of,const,type,array,record,program,div,mod,and,or,not,break,continue,shr,shl,xor",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",gen_dips(\"afmprx\")+\"i\"");
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
struct t_name_with_sep{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_name_with_sep)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_name,n,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_name_with_sep
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_name_with_sep
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_name_with_sep");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(n);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_string:public i_expr{
  //===>>===i_item_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_raw)\
    ADD(t_fix)\
    ADD(t_hex)\
  ADDEND()
  class i_item;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_item_visitor{
  public:
    typedef t_string::i_item i_item;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_string::U U;//typedef t_string::U U;
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
    static TYPE*UberCast(i_item*p){
      if(!p)return nullptr;Is<TYPE,i_item_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_item*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_item_visitor{
  //  void Do(t_raw&r){}
  //  void Do(t_fix&r){}
  //  void Do(t_hex&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_item_visitor
  struct i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_item)OWNER(t_string)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_item
  public:
    typedef i_item_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_item()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_raw);
        F(t_fix);
        F(t_hex);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_raw:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_raw)PARENT(i_item)OWNER(t_string)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_raw
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_raw
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_string::t_raw");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(dip_inv("'\\\n"));
      ok=dev.go_any(body,g_static_var_0);$(ok,",gen_dips(\"\\x00\\t\\x0B&([]\\xFF\")");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_fix:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_fix)PARENT(i_item)OWNER(t_string)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,body,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_fix
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_fix
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_string::t_fix");
      auto&ok=$.ok;
      ok=dev.go_const("\\");$(ok,",\"\\\\\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr("'\"\\/bfnrt");
      ok=dev.go_any_char(body,g_static_var_1);$(ok,",\"'\\\"\\\\/bfnrt\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_hex:public i_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_hex)PARENT(i_item)OWNER(t_string)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(ARRAY4char,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_hex
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_hex
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_string::t_hex");
      auto&ok=$.ok;
      ok=dev.go_const("\\u");$(ok,",\"\\\\\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09afAF"));
      ok=dev.go_any_arr_char(arr,g_static_var_1);$(ok,",gen_dips(\"09AFaf\")");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_raw)\
  F(t_fix)\
  F(t_hex)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_string)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<i_item>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_string
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_string
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_string");
    auto&ok=$.ok;
    ok=dev.go_const("'");$(ok,",\"'\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_item>>,gen_dips(\"\\x00\\t\\x0B&(\\xFF\")");}
    ok=dev.go_const("'");$(ok,",\"'\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
struct t_number:public i_expr{
  //===>>===i_int_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_num)\
    ADD(t_zero)\
  ADDEND()
  class i_int;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_int_visitor{
  public:
    typedef t_number::i_int i_int;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_number::U U;//typedef t_number::U U;
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
    static TYPE*UberCast(i_int*p){
      if(!p)return nullptr;Is<TYPE,i_int_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_int*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_int_visitor{
  //  void Do(t_num&r){}
  //  void Do(t_zero&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_int_visitor
  struct i_int{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_int)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_int
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_int
  public:
    typedef i_int_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_int()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_num);
        F(t_zero);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_minus{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_minus)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_minus
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_minus
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_minus");
      auto&ok=$.ok;
      ok=dev.go_const("-");$(ok,",\"-\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_frac{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_frac)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(string,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_frac
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_frac
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_frac");
      auto&ok=$.ok;
      ok=dev.go_const(".");$(ok,",\".\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(arr,g_static_var_1);$(ok,",\"0123456789\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_sign{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sign)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,sign,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_sign
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_sign
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_sign");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr("-+");
      ok=dev.go_any_char(sign,g_static_var_0);$(ok,",\"-+\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_exp{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exp)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,e,DEF,$,$)\
  ADDVAR(TAutoPtr<t_sign>,sign,DEF,$,$)\
  ADDVAR(string,arr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_exp
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_exp
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_exp");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr("eE");
      ok=dev.go_any_char(e,g_static_var_0);$(ok,",\"eE\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto(sign);$(ok,"TAutoPtr<t_sign>,\"+-\"");}
      static const auto g_static_var_2=CharMask::fromStr(gen_dips("09"));
      ok=dev.go_any(arr,g_static_var_2);$(ok,",\"0123456789\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_num:public i_int{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_num)PARENT(i_int)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(char,first,DEF,$,$)\
  ADDVAR(string,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_num
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_num
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_num");
      auto&ok=$.ok;
      static const auto g_static_var_0=CharMask::fromStr(gen_dips("19"));
      ok=dev.go_any_char(first,g_static_var_0);$(ok,",\"123456789\"");
      if(!ok)return ok;
      static const auto g_static_var_1=CharMask::fromStr(gen_dips("09"));
      {bool ok=dev.go_any(num,g_static_var_1);$(ok,",\"0123456789\"");}
      return ok;
    }
  };
  struct t_zero:public i_int{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_zero)PARENT(i_int)OWNER(t_number)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_zero
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_zero
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_number::t_zero");
      auto&ok=$.ok;
      ok=dev.go_const("0");$(ok,",\"0\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_minus)\
  F(t_frac )\
  F(t_sign )\
  F(t_exp  )\
  F(t_num  )\
  F(t_zero )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_number)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_minus>,minus,DEF,$,$)\
ADDVAR(TAutoPtr<i_int>,val,DEF,$,$)\
ADDVAR(TAutoPtr<t_frac>,frac,DEF,$,$)\
ADDVAR(TAutoPtr<t_exp>,exp,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDEND()
//=====+>>>>>t_number
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_number
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_number");
    auto&ok=$.ok;
    {bool ok=dev.go_auto(minus);$(ok,"TAutoPtr<t_minus>,\"-\"");}
    ok=dev.go_auto(val);$(ok,"TAutoPtr<i_int>,\"0123456789\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(frac);$(ok,"TAutoPtr<t_frac>,\".\"");}
    {bool ok=dev.go_auto(exp);$(ok,"TAutoPtr<t_exp>,\"Ee\"");}
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
struct t_sql_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sql_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_sql::i_data_stat>,data_stat,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sql_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sql_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sql_expr");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(data_stat);$(ok,"TAutoPtr<t_sql::i_data_stat>,\"\\t\\n\\r -/;disu\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_array_type:public i_var_type{
  struct t_of{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_of)OWNER(t_array_type)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_of
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_of
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_array_type::t_of");
      auto&ok=$.ok;
      ok=dev.go_const("of");$(ok,",\"o\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(type);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_of)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_array_type)PARENT(i_var_type)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_of>,of,DEF,$,$)\
ADDEND()
//=====+>>>>>t_array_type
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_array_type
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_array_type");
    auto&ok=$.ok;
    ok=dev.go_const("array");$(ok,",\"a\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(of);$(ok,"TAutoPtr<t_of>,\"o\"");}
    return ok;
  }
public:
};
struct t_var_type:public i_var_type{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_type)PARENT(i_var_type)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,type,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDEND()
//=====+>>>>>t_var_type
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_var_type
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_var_type");
    auto&ok=$.ok;
    ok=dev.go_auto(type);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_var_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<t_name_with_sep>,names,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDVAR(TAutoPtr<i_var_type>,type,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDEND()
//=====+>>>>>t_var_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_var_decl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_var_decl");
    auto&ok=$.ok;
    ok=dev.go_vec(names,",");$(ok,"vector<t_name_with_sep>,gen_dips(\"\\t\\nAZa{\")+\"\\r /_\"");
    if(!ok)return ok;
    ok=dev.go_const(":");$(ok,",\":\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(type);$(ok,"TAutoPtr<i_var_type>,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_var:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_var_decl>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_var
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_var
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_var");
    auto&ok=$.ok;
    ok=dev.go_const("var");$(ok,",\"v\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<t_var_decl>,gen_dips(\"\\t\\nAZa{\")+\"\\r /_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_enum_decl{
  struct t_value{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_value)OWNER(t_enum_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_number,num,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_value
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_value
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_enum_decl::t_value");
      auto&ok=$.ok;
      ok=dev.go_const("=");$(ok,",\"=\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(num);$(ok,"t_number,\"-0123456789\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_elem)OWNER(t_enum_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(TAutoPtr<t_value>,value,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_elem
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_enum_decl::t_elem");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      {bool ok=dev.go_auto(value);$(ok,"TAutoPtr<t_value>,\"=\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_value)\
  F(t_elem )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_enum_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<t_elem>,type,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDEND()
//=====+>>>>>t_enum_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_enum_decl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_enum_decl");
    auto&ok=$.ok;
    ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("=");$(ok,",\"=\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    ok=dev.go_vec(type,",");$(ok,"vector<t_elem>,gen_dips(\"\\t\\nAZa{\")+\"\\r /_\"");
    if(!ok)return ok;
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
struct t_type:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_type)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_enum_decl>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_type
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_type
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_type");
    auto&ok=$.ok;
    ok=dev.go_const("type");$(ok,",\"t\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<t_enum_decl>,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_param_decl{
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_param_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_param_decl::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_const{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const)OWNER(t_param_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_const
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_param_decl::t_const");
      auto&ok=$.ok;
      ok=dev.go_const("const");$(ok,",\"c\"");
      if(!ok)return ok;
      ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_defvalue{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_defvalue)OWNER(t_param_decl)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_number,num,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_defvalue
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_defvalue
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_param_decl::t_defvalue");
      auto&ok=$.ok;
      ok=dev.go_const("=");$(ok,",\"=\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(num);$(ok,"t_number,\"-0123456789\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_item    )\
  F(t_const   )\
  F(t_defvalue)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<t_const>,c,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(TAutoPtr<i_var_type>,type,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<t_defvalue>,value,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDEND()
//=====+>>>>>t_param_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_param_decl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_param_decl");
    auto&ok=$.ok;
    {bool ok=dev.go_auto(c);$(ok,"TAutoPtr<t_const>,\"c\"");}
    ok=dev.go_vec(arr,",");$(ok,"vector<t_item>,gen_dips(\"\\t\\nAZa{\")+\"\\r /_\"");
    if(!ok)return ok;
    ok=dev.go_const(":");$(ok,",\":\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(type);$(ok,"TAutoPtr<i_var_type>,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(value);$(ok,"TAutoPtr<t_defvalue>,\"=\"");}
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
struct t_params_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_param_decl>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_params_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_params_decl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_params_decl");
    auto&ok=$.ok;
    ok=dev.go_const("(");$(ok,",\"(\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_vec(arr,";");$(ok,"vector<t_param_decl>,gen_dips(\"\\t\\nAZa{\")+\"\\r /_\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_exit_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_exit_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_exit_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_exit_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_exit_stat");
    auto&ok=$.ok;
    ok=dev.go_const("exit");$(ok,",\"e\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_break_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_break_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_break_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_break_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_break_stat");
    auto&ok=$.ok;
    ok=dev.go_const("break");$(ok,",\"b\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_continue_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_continue_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_continue_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_continue_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_continue_stat");
    auto&ok=$.ok;
    ok=dev.go_const("continue");$(ok,",\"c\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_block_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDEND()
//=====+>>>>>t_block_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_block_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_block_stat");
    auto&ok=$.ok;
    ok=dev.go_const("begin");$(ok,",\"b\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_stat>>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("end");$(ok,",\"e\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
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
    static const auto g_static_var_0=QapStrFinder::fromArr(split("not,^,@,new",","));
    {bool ok=dev.go_any_str_from_vec(oper,g_static_var_0);$(ok,",\"@^n\"");}
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"TAutoPtr<i_expr>,gen_dips(\"'(09A[az\")+\"-_\"");
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("*,/,div,mod,and,shl,shr",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"*/dmass\"");
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
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"*/adms\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev01,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
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
    ok=dev.go_auto(expr);$(ok,"t_lev01,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r */adms{\"");}
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
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"+-\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev02,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
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
    ok=dev.go_auto(expr);$(ok,"t_lev02,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r +-/{\"");}
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
      static const auto g_static_var_0=QapStrFinder::fromArr(split("=,<>,<,>,<=,>=,in,is,like",","));
      ok=dev.go_any_str_from_vec(value,g_static_var_0);$(ok,",\"=<<><>iil\"");
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
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"<=>il\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev03,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
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
    ok=dev.go_auto(expr);$(ok,"t_lev03,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r /<=>il{\"");}
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
      ok=dev.go_const("xor");$(ok,",\"x\"");
      if(!ok)return ok;
      return ok;
    }
    inline static const string value="xor";
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
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"x\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev04,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
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
    ok=dev.go_auto(expr);$(ok,"t_lev04,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r /x{\"");}
    return ok;
  }
public:
};
struct t_lev06{
  struct t_oper{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_oper)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>t_oper
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_oper
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_oper");
      auto&ok=$.ok;
      ok=dev.go_const("or");$(ok,",\"o\"");
      if(!ok)return ok;
      return ok;
    }
    inline static const string value="or";
  };
  struct t_item{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_item)OWNER(t_lev06)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep0,DEF,$,$)\
  ADDVAR(t_oper,oper,DEF,$,$)\
  ADDVAR(t_sep,$sep2,DEF,$,$)\
  ADDVAR(t_lev05,expr,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_item
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_item
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_lev06::t_item");
      auto&ok=$.ok;
      {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(oper);$(ok,"t_oper,\"o\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(expr);$(ok,"t_lev05,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
      if(!ok)return ok;
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_oper)\
  F(t_item)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_lev06)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev05,expr,DEF,$,$)\
ADDVAR(vector<t_item>,arr,DEF,$,$)\
ADDEND()
//=====+>>>>>t_lev06
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_lev06
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_lev06");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev05,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(arr);$(ok,"vector<t_item>,\"\\t\\n\\r /o{\"");}
    return ok;
  }
public:
};
/*
var pad2=num=>(num<10?"0"+num:""+num);
return(
`not,^,@,new
*,/,div,mod,and,shl,shr
+,-
=,<>,<,>,<=,>=,in,is,like
xor
or`.split("\r").join("").split("\n").map((ops,i)=>{
  var e="t_lev"+pad2(!i?1:i);
  var n="t_lev"+pad2(i+1);  
  if(!i){
    return `t_lev01{
  string oper=any_str_from_vec(split(`+JSON.stringify(ops)+`,","))?;
  " "?
  TAutoPtr<i_expr> expr;
}`;
  }
  var oa=ops.split(",");
  if(oa.length==1){
    return n+`{
  t_oper{"`+oa[0]+`"[::]inline static const string value="`+oa[0]+`";}
  t_item{" "?t_oper oper;" "?`+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
  }
  return n+`{
  t_oper{string value=any_str_from_vec(split("`+ops+`",","));}
  t_item{" "? t_oper oper;" "?`+e+` expr;}
  `+e+` expr;
  vector<t_item> arr?;
}`;
}).join("\n"));
*/
struct t_expr{
  struct t_as{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_as)OWNER(t_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,type,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_as
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_as
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_expr::t_as");
      auto&ok=$.ok;
      ok=dev.go_const("as");$(ok,",\"a\"");
      if(!ok)return ok;
      ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");
      if(!ok)return ok;
      ok=dev.go_auto(type);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_as)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_lev06,expr,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(TAutoPtr<t_as>,as,DEF,$,$)\
ADDEND()
//=====+>>>>>t_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_expr
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_expr");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_lev06,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(as);$(ok,"TAutoPtr<t_as>,\"a\"");}
    return ok;
  }
public:
};
struct t_param{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_param)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep0,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep2,DEF,$,$)\
ADDEND()
//=====+>>>>>t_param
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_param
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_param");
    auto&ok=$.ok;
    {bool ok=dev.go_auto($sep0);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep2);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_sb_expr:public i_expr{
  //===>>===i_elem_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_arr_elem)\
    ADD(t_dot_elem)\
    ADD(t_params_elem)\
  ADDEND()
  class i_elem;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_elem_visitor{
  public:
    typedef t_sb_expr::i_elem i_elem;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_sb_expr::U U;//typedef t_sb_expr::U U;
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
    static TYPE*UberCast(i_elem*p){
      if(!p)return nullptr;Is<TYPE,i_elem_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_elem*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_elem_visitor{
  //  void Do(t_arr_elem&r){}
  //  void Do(t_dot_elem&r){}
  //  void Do(t_params_elem&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_elem_visitor
  struct i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_elem)OWNER(t_sb_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_elem
  public:
    typedef i_elem_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_elem()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_arr_elem);
        F(t_dot_elem);
        F(t_params_elem);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_arr_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_elem)PARENT(i_elem)OWNER(t_sb_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_arr_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_arr_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sb_expr::t_arr_elem");
      auto&ok=$.ok;
      ok=dev.go_const("[");$(ok,",\"[\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_vec(arr,",");$(ok,"vector<t_param>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
      if(!ok)return ok;
      ok=dev.go_const("]");$(ok,",\"]\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_dot_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dot_elem)PARENT(i_elem)OWNER(t_sb_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_dot_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_dot_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sb_expr::t_dot_elem");
      auto&ok=$.ok;
      ok=dev.go_const(".");$(ok,",\".\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_params_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params_elem)PARENT(i_elem)OWNER(t_sb_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_params_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_params_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_sb_expr::t_params_elem");
      auto&ok=$.ok;
      ok=dev.go_const("(");$(ok,",\"(\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_param>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");}
      ok=dev.go_const(")");$(ok,",\")\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_arr_elem   )\
  F(t_dot_elem   )\
  F(t_params_elem)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_sb_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_param>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep4,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_elem>>,elems,DEF,$,$)\
ADDEND()
//=====+>>>>>t_sb_expr
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_sb_expr
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_sb_expr");
    auto&ok=$.ok;
    ok=dev.go_const("[");$(ok,",\"[\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_param>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");}
    ok=dev.go_const("]");$(ok,",\"]\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(elems);$(ok,"vector<TAutoPtr<i_elem>>,\"(.[\"");}
    return ok;
  }
public:
};
struct t_if_stat:public i_stat{
  struct t_else{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_else)OWNER(t_if_stat)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(TAutoPtr<i_stat>,stat,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_else
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_else
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_if_stat::t_else");
      auto&ok=$.ok;
      ok=dev.go_const("else");$(ok,",\"e\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(stat);$(ok,"TAutoPtr<i_stat>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_else)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_if_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<i_stat>,stat,DEF,$,$)\
ADDVAR(TAutoPtr<t_else>,estat,DEF,$,$)\
ADDVAR(t_sep,$sep8,DEF,$,$)\
ADDEND()
//=====+>>>>>t_if_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_if_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_if_stat");
    auto&ok=$.ok;
    ok=dev.go_const("if");$(ok,",\"i\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("then");$(ok,",\"t\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(stat);$(ok,"TAutoPtr<i_stat>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto(estat);$(ok,"TAutoPtr<t_else>,\"e\"");}
    {bool ok=dev.go_auto($sep8);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
/*
foo.bar();foo()();foo[0]();foo.bar[0].xx.baz[1,5][0]()()[0];
*/
struct t_varcall_expr:public i_expr{
  //===>>===i_elem_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_deref_elem)\
    ADD(t_arr_elem)\
    ADD(t_dot_elem)\
    ADD(t_params_elem)\
  ADDEND()
  class i_elem;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_elem_visitor{
  public:
    typedef t_varcall_expr::i_elem i_elem;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_varcall_expr::U U;//typedef t_varcall_expr::U U;
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
    static TYPE*UberCast(i_elem*p){
      if(!p)return nullptr;Is<TYPE,i_elem_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_elem*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_elem_visitor{
  //  void Do(t_deref_elem&r){}
  //  void Do(t_arr_elem&r){}
  //  void Do(t_dot_elem&r){}
  //  void Do(t_params_elem&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_elem_visitor
  struct i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_elem)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_elem
  public:
    typedef i_elem_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_elem()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_deref_elem);
        F(t_arr_elem);
        F(t_dot_elem);
        F(t_params_elem);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_deref_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_deref_elem)PARENT(i_elem)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_deref_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_deref_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_varcall_expr::t_deref_elem");
      auto&ok=$.ok;
      ok=dev.go_const("^");$(ok,",\"^\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_arr_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_arr_elem)PARENT(i_elem)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_arr_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_arr_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_varcall_expr::t_arr_elem");
      auto&ok=$.ok;
      ok=dev.go_const("[");$(ok,",\"[\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_vec(arr,",");$(ok,"vector<t_param>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
      if(!ok)return ok;
      ok=dev.go_const("]");$(ok,",\"]\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_dot_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_dot_elem)PARENT(i_elem)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDVAR(t_sep,$sep3,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_dot_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_dot_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_varcall_expr::t_dot_elem");
      auto&ok=$.ok;
      ok=dev.go_const(".");$(ok,",\".\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_params_elem:public i_elem{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_params_elem)PARENT(i_elem)OWNER(t_varcall_expr)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(vector<t_param>,arr,DEF,$,$)\
  ADDVAR(t_sep,$sep4,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_params_elem
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_params_elem
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_varcall_expr::t_params_elem");
      auto&ok=$.ok;
      ok=dev.go_const("(");$(ok,",\"(\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      {bool ok=dev.go_vec(arr,",");$(ok,"vector<t_param>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");}
      ok=dev.go_const(")");$(ok,",\")\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep4);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_deref_elem )\
  F(t_arr_elem   )\
  F(t_dot_elem   )\
  F(t_params_elem)\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_varcall_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_elem>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
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
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_elem>>,\"(.[^\"");}
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
struct t_assign_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_assign_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_varcall_expr,var,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDEND()
//=====+>>>>>t_assign_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_assign_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_assign_stat");
    auto&ok=$.ok;
    ok=dev.go_auto(var);$(ok,"t_varcall_expr,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(":=");$(ok,",\":\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_for_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_for_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_assign_stat,from,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(string,dir,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDVAR(TAutoPtr<i_stat>,body,DEF,$,$)\
ADDEND()
//=====+>>>>>t_for_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_for_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_for_stat");
    auto&ok=$.ok;
    ok=dev.go_const("for");$(ok,",\"f\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(from);$(ok,"t_assign_stat,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    static const auto g_static_var_4=QapStrFinder::fromArr(split("to,downto",","));
    ok=dev.go_any_str_from_vec(dir,g_static_var_4);$(ok,",\"td\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("do");$(ok,",\"d\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(body);$(ok,"TAutoPtr<i_stat>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    return ok;
  }
};
struct t_block_expr:public i_expr{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_block_expr)PARENT(i_expr)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(vector<TAutoPtr<t_varcall_expr::i_elem>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
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
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(")");$(ok,",\")\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<t_varcall_expr::i_elem>>,\"(.[^\"");}
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_while_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_while_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<i_stat>,stat,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDEND()
//=====+>>>>>t_while_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_while_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_while_stat");
    auto&ok=$.ok;
    ok=dev.go_const("while");$(ok,",\"w\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("do");$(ok,",\"d\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(stat);$(ok,"TAutoPtr<i_stat>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_repeat_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_repeat_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDEND()
//=====+>>>>>t_repeat_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_repeat_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_repeat_stat");
    auto&ok=$.ok;
    ok=dev.go_const("repeat");$(ok,",\"r\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_stat>>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("until");$(ok,",\"u\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_case_item{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_case_item)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_case_item
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_case_item
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_case_item");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(":");$(ok,",\":\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_stat>>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");
    if(!ok)return ok;
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_case_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_case_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(vector<t_case_item>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDVAR(t_sep,$sep11,DEF,$,$)\
ADDEND()
//=====+>>>>>t_case_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_case_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_case_stat");
    auto&ok=$.ok;
    ok=dev.go_const("case");$(ok,",\"c\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("of");$(ok,",\"o\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(arr);$(ok,"vector<t_case_item>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("end");$(ok,",\"e\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep11);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_const_decl{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_decl)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep6,DEF,$,$)\
ADDEND()
//=====+>>>>>t_const_decl
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_const_decl
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_const_decl");
    auto&ok=$.ok;
    ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("=");$(ok,",\"=\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep6);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_const:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(vector<t_const_decl>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_const
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_const
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_const");
    auto&ok=$.ok;
    ok=dev.go_const("const");$(ok,",\"c\"");
    if(!ok)return ok;
    ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");
    if(!ok)return ok;
    ok=dev.go_auto(arr);$(ok,"vector<t_const_decl>,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_expr_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_expr_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_expr,expr,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDEND()
//=====+>>>>>t_expr_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_expr_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_expr_stat");
    auto&ok=$.ok;
    ok=dev.go_auto(expr);$(ok,"t_expr,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
//t_sep_stat:i_stat{" "}
struct t_semicolon_stat:public i_stat{
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_semicolon_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(t_sep,$sep1,DEF,$,$)\
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
    {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
};
struct t_func_or_proc_stat:public i_stat{
  //===>>===i_d_visitor
  #define DEF_PRO_BLANK()
  #define LIST(ADDBEG,ADD,ADDEND)\
  ADDBEG()\
    ADD(t_var_d)\
    ADD(t_const_d)\
  ADDEND()
  class i_d;
  #define ADD(TYPE)class TYPE;
  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  #undef ADD
  class i_d_visitor{
  public:
    typedef t_func_or_proc_stat::i_d i_d;
  public:
    #define ADD(TYPE)virtual void Do(TYPE&r)=0;
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
  public:
    #define ADD(U)typedef t_func_or_proc_stat::U U;//typedef t_func_or_proc_stat::U U;
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
    static TYPE*UberCast(i_d*p){
      if(!p)return nullptr;Is<TYPE,i_d_visitor> IS;p->Use(IS);return IS.ptr;
    }
    #else
    template<class TYPE>
    static TYPE*UberCast(i_d*p){return dynamic_cast<TYPE*>(p);}
    #endif
  };
  //struct t_visitor:public i_d_visitor{
  //  void Do(t_var_d&r){}
  //  void Do(t_const_d&r){}
  //};
  #undef LIST
  #undef DEF_PRO_BLANK
  //===<<===i_d_visitor
  struct i_d{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(i_d)OWNER(t_func_or_proc_stat)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDEND()
  //=====+>>>>>i_d
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====i_d
  public:
    typedef i_d_visitor i_visitor;
    virtual void Use(i_visitor&A){QapDebugMsg("no way.");/*A.Do(*this);*/}
    virtual ~i_d()=default;
  public:
    virtual bool go(i_dev&dev){QapDebugMsg("no way.");return false;};
    struct t_poly_impl:public t_poly_tool::go_poly<SelfClass>
    {
      #include "QapLexPolyBeg.inl"
      void load();/*
      {
        F(t_var_d);
        F(t_const_d);
        (void)count;(void)first_id;(void)out_arr;(void)this;
        main();
        return scope.ok;
      }*/
      #include "QapLexPolyEndNoTemplate.inl"
    };
  };
  struct t_ret_type{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_ret_type)OWNER(t_func_or_proc_stat)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDVAR(t_name,name,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_ret_type
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_ret_type
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_func_or_proc_stat::t_ret_type");
      auto&ok=$.ok;
      ok=dev.go_const(":");$(ok,",\":\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
      if(!ok)return ok;
      return ok;
    }
  };
  struct t_var_d:public i_d{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_var_d)PARENT(i_d)OWNER(t_func_or_proc_stat)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_var,d,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_var_d
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_var_d
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_func_or_proc_stat::t_var_d");
      auto&ok=$.ok;
      ok=dev.go_auto(d);$(ok,"t_var,\"v\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
  struct t_const_d:public i_d{
  #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_const_d)PARENT(i_d)OWNER(t_func_or_proc_stat)
  #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
  ADDBEG()\
  ADDVAR(t_const,d,DEF,$,$)\
  ADDVAR(t_sep,$sep1,DEF,$,$)\
  ADDEND()
  //=====+>>>>>t_const_d
  #include "QapGenStructNoTemplate.inl"
  //<<<<<+=====t_const_d
  public:
    void Use(i_visitor&A){A.Do(*this);}
    static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
  public:
    bool go(i_dev&dev){
      t_fallback $(dev,"t_func_or_proc_stat::t_const_d");
      auto&ok=$.ok;
      ok=dev.go_auto(d);$(ok,"t_const,\"c\"");
      if(!ok)return ok;
      {bool ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
      return ok;
    }
  };
#define DEF_PRO_NESTED(F)\
  /*<DEF_PRO_NESTED>*/\
  F(t_ret_type)\
  F(t_var_d   )\
  F(t_const_d )\
  /*</DEF_PRO_NESTED>*/
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_func_or_proc_stat)PARENT(i_stat)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,kw,DEF,$,$)\
ADDVAR(t_sep,$sep1,DEF,$,$)\
ADDVAR(t_name,name,DEF,$,$)\
ADDVAR(t_sep,$sep3,DEF,$,$)\
ADDVAR(TAutoPtr<t_params_decl>,params,DEF,$,$)\
ADDVAR(t_sep,$sep5,DEF,$,$)\
ADDVAR(TAutoPtr<t_ret_type>,type,DEF,$,$)\
ADDVAR(t_sep,$sep7,DEF,$,$)\
ADDVAR(t_sep,$sep9,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_d>>,darr,DEF,$,$)\
ADDVAR(t_sep,$sep11,DEF,$,$)\
ADDVAR(t_sep,$sep13,DEF,$,$)\
ADDVAR(vector<TAutoPtr<i_stat>>,arr,DEF,$,$)\
ADDVAR(t_sep,$sep15,DEF,$,$)\
ADDVAR(t_sep,$sep17,DEF,$,$)\
ADDVAR(t_sep,$sep19,DEF,$,$)\
ADDEND()
//=====+>>>>>t_func_or_proc_stat
#include "QapGenStructNoTemplate.inl"
//<<<<<+=====t_func_or_proc_stat
public:
  void Use(i_visitor&A){A.Do(*this);}
  static SelfClass*UberCast(ParentClass*ptr){return i_visitor::UberCast<SelfClass>(ptr);}
public:
  bool go(i_dev&dev){
    t_fallback $(dev,"t_func_or_proc_stat");
    auto&ok=$.ok;
    static const auto g_static_var_0=QapStrFinder::fromArr(split("function,procedure",","));
    ok=dev.go_any_str_from_vec(kw,g_static_var_0);$(ok,",\"fp\"");
    if(!ok)return ok;
    ok=dev.go_auto($sep1);$(ok,"t_sep,\"\\t\\n\\r /{\"");
    if(!ok)return ok;
    ok=dev.go_auto(name);$(ok,"t_name,gen_dips(\"AZaz\")+\"_\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep3);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(params);$(ok,"TAutoPtr<t_params_decl>,\"(\"");}
    {bool ok=dev.go_auto($sep5);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(type);$(ok,"TAutoPtr<t_ret_type>,\":\"");}
    {bool ok=dev.go_auto($sep7);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep9);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(darr);$(ok,"vector<TAutoPtr<i_d>>,\"cv\"");}
    {bool ok=dev.go_auto($sep11);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("begin");$(ok,",\"b\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep13);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    {bool ok=dev.go_auto(arr);$(ok,"vector<TAutoPtr<i_stat>>,gen_dips(\"\\t\\n'(/9@[^_a{\")+\"\\r -;\"");}
    {bool ok=dev.go_auto($sep15);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const("end");$(ok,",\"e\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep17);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    ok=dev.go_const(";");$(ok,",\";\"");
    if(!ok)return ok;
    {bool ok=dev.go_auto($sep19);$(ok,"t_sep,\"\\t\\n\\r /{\"");}
    return ok;
  }
public:
};
void i_expr::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,6> lex={
    F(t_string,"'"),
    F(t_number,"-0123456789"),
    F(t_sql_expr,"("),
    F(t_sb_expr,"["),
    F(t_varcall_expr,gen_dips("AZaz")+"_"),
    F(t_block_expr,"(")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_var_type::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,2> lex={
    F(t_array_type,"a"),
    F(t_var_type,gen_dips("AZaz")+"_")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void i_stat::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,16> lex={
    F(t_var,"v"),
    F(t_type,"t"),
    F(t_exit_stat,"e"),
    F(t_break_stat,"b"),
    F(t_continue_stat,"c"),
    F(t_block_stat,"b"),
    F(t_if_stat,"i"),
    F(t_assign_stat,gen_dips("AZaz")+"_"),
    F(t_for_stat,"f"),
    F(t_while_stat,"w"),
    F(t_repeat_stat,"r"),
    F(t_case_stat,"c"),
    F(t_const,"c"),
    F(t_expr_stat,gen_dips("\t\n'(/9@[^_a{")+"\r -"),
    F(t_semicolon_stat,";"),
    F(t_func_or_proc_stat,"fp")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void t_sql::i_sep::t_poly_impl::load()
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
void t_sql::i_str_item::t_poly_impl::load()
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
void t_sql::i_expr::t_poly_impl::load()
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
void t_sql::i_table_expr::t_poly_impl::load()
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
void t_sql::i_in_operand::t_poly_impl::load()
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
void t_sql::i_data_stat::t_poly_impl::load()
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
void t_sql::i_insert_body::t_poly_impl::load()
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
void t_sql::t_lev06::i_lev06_ext::t_poly_impl::load()
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
void t_sql::t_num_expr::i_num_part::t_poly_impl::load()
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
void t_sql::t_num_expr::i_impl::t_poly_impl::load()
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
void t_sql::t_column_list::i_clist_item::t_poly_impl::load()
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
void t_sep::i_sep::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '{':F(t_comment);
    case '/':F(t_c_comment);
    case '\t':
    case '\n':
    case '\r':
    case ' ':F(t_raw_sep);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_string::i_item::t_poly_impl::load()
{
  #define F(TYPE,MASK)t_lex{#TYPE,[](t_poly_impl*self){self->go_for<TYPE>();},CharMask::fromStr(MASK,true)}
  static std::array<t_lex,3> lex={
    F(t_raw,gen_dips("\x00\t\x0B&([]\xFF")),
    F(t_fix,"\\"),
    F(t_hex,"\\")
  };
  #undef F
  #include "poly_fast_impl.inl"
  main(&lex);
  return;
}
void t_number::i_int::t_poly_impl::load()
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
    case '9':F(t_num);
    case '0':F(t_zero);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_sb_expr::i_elem::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '[':F(t_arr_elem);
    case '.':F(t_dot_elem);
    case '(':F(t_params_elem);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_varcall_expr::i_elem::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case '^':F(t_deref_elem);
    case '[':F(t_arr_elem);
    case '.':F(t_dot_elem);
    case '(':F(t_params_elem);
    default:{scope.ok=false;return;}
  }
  #undef F
}
void t_func_or_proc_stat::i_d::t_poly_impl::load()
{
  i_dev::t_result r=dev.get_char_lt();
  if(!r.ok){scope.ok=false;return;}
  #define F(T){T L;scope.ok=dev.go_auto(L);if(scope.ok)ref=make_unique<T>(std::move(L));return;}
  switch(r.c){
    case 'v':F(t_var_d);
    case 'c':F(t_const_d);
    default:{scope.ok=false;return;}
  }
  #undef F
}
/*
//list of types:
F(t_expr)F(t_pascal_expr)F(t_sql)F(t_sep)F(t_name)F(t_name_with_sep)F(t_string)
F(t_number)F(t_sql_expr)F(t_array_type)F(t_var_type)F(t_var_decl)F(t_var)
F(t_enum_decl)F(t_type)F(t_param_decl)F(t_params_decl)F(t_exit_stat)
F(t_break_stat)F(t_continue_stat)F(t_block_stat)F(t_lev01)F(t_lev02)F(t_lev03)
F(t_lev04)F(t_lev05)F(t_lev06)F(t_expr)F(t_param)F(t_sb_expr)F(t_if_stat)
F(t_varcall_expr)F(t_assign_stat)F(t_for_stat)F(t_block_expr)F(t_while_stat)
F(t_repeat_stat)F(t_case_item)F(t_case_stat)F(t_const_decl)F(t_const)
F(t_expr_stat)F(t_semicolon_stat)F(t_func_or_proc_stat)
//app:
adler3d.github.io/test2013/
//code:
return decodeURIComponent(POST['data'].split("\n").join(""));
//data:
t%5fexpr%3b%0at%5fpascal%5fexpr%7b%0a%20%20TAutoPtr%3ct%5fexpr%3e%20expr%3b%0a%7
d%0a%0at%5fsql%7b%0a%20%20t%5fsep%5fseq%3ai%5fsep%7b%0a%20%20%20%20string%20body
%3dany%28%22%20%5ct%5cr%5cn%22%29%3b%0a%20%20%7d%0a%20%20t%5fsql%5fblock%5fcomme
nt%3ai%5fsep%7b%0a%20%20%20%20%22%2f%2a%22%0a%20%20%20%20string%20body%3dend%28%
22%2a%2f%22%29%3b%0a%20%20%7d%0a%20%20t%5fsql%5fline%5fcomment%3ai%5fsep%7b%0a%2
0%20%20%20%22%2d%2d%22%0a%20%20%20%20string%20body%3dany%28dip%5finv%28%22%5cn%2
2%29%29%3f%3b%0a%20%20%7d%0a%20%20t%5fsep%7b%0a%20%20%20%20%2f%2ft%5fimpl%7b%0a%
20%20%20%20%2f%2f%20%20vector%3cTAutoPtr%3ci%5fsep%3e%3e%20arr%3b%0a%20%20%20%20
%2f%2f%7d%0a%20%20%20%20%2f%2fstring%20value%3dstr%3ct%5fimpl%3e%28%29%3b%0a%20%
20%20%20vector%3cTAutoPtr%3ci%5fsep%3e%3e%20arr%3b%0a%20%20%7d%0a%0a%20%20typede
f%20array%3cchar%2c2%3e%20ARRAY2char%3b%0a%20%20typedef%20array%3cchar%2c4%3e%20
ARRAY4char%3b%0a%20%20using%20%22%20%22%20as%20t%5fsep%3b%0a%0a%20%20t%5fstr%5fr
aw%3ai%5fstr%5fitem%7b%0a%20%20%20%20string%20body%3dany%28dip%5finv%28%22%27%5c
%5c%5cn%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fstr%5fhex%3ai%5fstr%5fitem%7b%0a%20%
20%20%20%22%5c%5cx%22%0a%20%20%20%20ARRAY2char%20body%3dany%5farr%5fchar%28gen%5
fdips%28%2209afAF%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fstr%5funicode%3ai%5fstr%5f
item%7b%0a%20%20%20%20%22%5c%5cu%22%0a%20%20%20%20ARRAY4char%20body%3dany%5farr%
5fchar%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fstr%5fescape%3ai
%5fstr%5fitem%7b%0a%20%20%20%20%22%5c%5c%22%0a%20%20%20%20char%20body%3dany%5fch
ar%28%22tfbrn%5c%5c%27%5c%22%22%2bgen%5fdips%28%2207%22%29%29%3b%0a%20%20%7d%0a%
20%20t%5fstr%5fimpl%7b%0a%20%20%20%20t%5fone%7b%22%27%22%20vector%3cTAutoPtr%3ci
%5fstr%5fitem%3e%3e%20arr%3b%20%22%27%22%7d%0a%20%20%20%20vector%3ct%5fone%3e%20
arr%3b%0a%20%20%7d%0a%0a%20%20t%5fstr%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20string%
20value%3dstr%3ct%5fstr%5fimpl%3e%28%29%3b%0a%20%20%7d%0a%0a%20%20t%5fbool%5fexp
r%3ai%5fexpr%7b%0a%20%20%20%20string%20value%3dany%5fstr%5ffrom%5fvec%28split%28
%22true%2cfalse%22%2c%22%2c%22%29%29%3b%0a%20%20%7d%0a%0a%20%20t%5fname%7b%0a%20
%20%20%20t%5fkeyword%7b%0a%20%20%20%20%20%20string%20value%3dany%5fstr%5ffrom%5f
vec%28split%28%22select%2cinsert%2cupdate%2cdelete%2cfrom%2cwhere%2cand%2cor%2cn
ot%2cin%2cbetween%2clike%2cis%2cnull%2cdistinct%2cas%2cjoin%2con%2cusing%2chavin
g%2cunion%2call%2ccreate%2cdrop%2ctable%2cindex%2cview%2ctrigger%2cprocedure%2cf
unction%2ccase%2celse%2cend%2ccast%2cconvert%2cset%2cvalues%2cinto%2cexists%2cli
mit%2coffset%2ctrue%2cfalse%2cnullif%2cifnull%2csingle%22%2c%22%2c%22%29%29%3b%2
0%2f%2f%20without%3agroup%2cinner%2cleft%2cright%2cfull%2corder%2cby%2casc%2cdes
c%2cwhen%2cthen%2c%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%7b%0a%20%20%20%20%20
%20char%20A%3dany%5fchar%28gen%5fdips%28%22azAZ%22%29%2b%22%5f%22%29%3b%0a%20%20
%20%20%20%20string%20B%3dany%28gen%5fdips%28%22azAZ09%22%29%2b%22%5f%22%29%3f%3b
%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%5fex%7b%0a%20%20%20%20%20%20t%5fimpl%2
0impl%3ddiff%3ct%5fkeyword%3e%28%29%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20
value%3dstr%3ct%5fimpl%5fex%3e%28%29%3b%0a%20%20%7d%0a%0a%20%20t%5flev01%7b%0a%2
0%20%20%20string%20oper%3dany%5fstr%5ffrom%5fvec%28split%28%22not%2c%2b%2c%2d%22
%2c%22%2c%22%29%29%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ci%5
fexpr%3e%20expr%3b%0a%20%20%7d%0a%20%20t%5flev02%7b%0a%20%20%20%20t%5foper%7bstr
ing%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%2a%2c%2f%2c%25%2cdiv%2cmod%22
%2c%22%2c%22%29%29%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20oper
%3b%22%20%22%3ft%5flev01%20expr%3b%7d%0a%20%20%20%20t%5flev01%20expr%3b%0a%20%20
%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev03%7b%0a%20%20
%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2c%2d%
22%2c%22%2c%22%29%29%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20op
er%3b%22%20%22%3ft%5flev02%20expr%3b%7d%0a%20%20%20%20t%5flev02%20expr%3b%0a%20%
20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev04%7b%0a%20%
20%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22shl%2csh
r%22%2c%22%2c%22%29%29%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20
oper%3b%22%20%22%3ft%5flev03%20expr%3b%7d%0a%20%20%20%20t%5flev03%20expr%3b%0a%2
0%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev05%7b%0a%2
0%20%20%20t%5foper%7b%22%7c%7c%22%5b%3a%3a%5dinline%20static%20const%20string%20
value%3d%22%7c%7c%22%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%22%3ft%5foper%20oper%
3b%22%20%22%3ft%5flev04%20expr%3b%7d%0a%20%20%20%20t%5flev04%20expr%3b%0a%20%20%
20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5flev06%7b%0a%20%20%
20%20t%5fnot%7b%22not%22%7d%0a%20%20%20%20t%5fbetween%3ai%5flev06%5fext%7b%0a%20
%20%20%20%20%20TAutoPtr%3ct%5fnot%3e%20neg%3f%3b%0a%20%20%20%20%20%20%22%20%22%3
f%0a%20%20%20%20%20%20%22between%22%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20
%20%20%20t%5flev05%20low%3b%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%20%2
0%22and%22%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%20%20t%5flev05%20high
%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fis%5fnull%3ai%5flev06%5fext%7b%0a%20%20%
20%20%20%20%22%20%22%3f%0a%20%20%20%20%20%20%22is%22%0a%20%20%20%20%20%20%22%20%
22%3f%0a%20%20%20%20%20%20TAutoPtr%3ct%5fnot%3e%20not%3f%3b%0a%20%20%20%20%20%20
%22%20%22%3f%0a%20%20%20%20%20%20%22null%22%0a%20%20%20%20%7d%0a%20%20%20%20t%5f
in%5flist%3ai%5flev06%5fext%7b%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%2
0%20TAutoPtr%3ct%5fnot%3e%20not%3f%3b%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%
20%20%20%20%22in%22%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%20%20TAutoPt
r%3ci%5fin%5foperand%3e%20operand%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5foper%7b
string%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%3d%2c%3c%3e%2c%3c%2c%3e%2c
%3c%3d%2c%3e%3d%2clike%2cin%22%2c%22%2c%22%29%29%3b%7d%0a%20%20%20%20t%5fitem%7b
t%5foper%20oper%3b%22%20%22%3ft%5flev05%20expr%3b%22%20%22%3f%7d%0a%20%20%20%20t
%5flev05%20expr%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3ct%5fitem%3e
%20arr%3f%3b%0a%20%20%20%20TAutoPtr%3ci%5flev06%5fext%3e%20ext%3f%3b%0a%20%20%7d
%0a%20%20t%5flev07%7b%0a%20%20%20%20t%5foper%7b%22and%22%5b%3a%3a%5dinline%20sta
tic%20const%20string%20value%3d%22and%22%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%2
2%3ft%5foper%20oper%3b%22%20%22%20t%5flev06%20expr%3b%7d%0a%20%20%20%20t%5flev06
%20expr%3b%0a%20%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%
5flev08%7b%0a%20%20%20%20t%5foper%7b%22or%22%5b%3a%3a%5dinline%20static%20const%
20string%20value%3d%22or%22%3b%7d%0a%20%20%20%20t%5fitem%7b%22%20%22%3ft%5foper%
20oper%3b%22%20%22%20t%5flev07%20expr%3b%7d%0a%20%20%20%20t%5flev07%20expr%3b%0a
%20%20%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%20%20%7d%0a%20%20t%5fstar%5fexpr
%3ai%5fexpr%7b%22%2a%22%7d%0a%20%20t%5flev08%5fwith%5fsep%7b%22%20%22%3ft%5flev0
8%20expr%3b%22%20%22%3f%7d%0a%20%20t%5fblock%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20
%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3ct%5flev08%5fwith%5fs
ep%3e%20arr%3dvec%28%22%2c%22%29%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22
%29%22%0a%20%20%7d%0a%20%20t%5fvarcall%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5fit
em%7b%22%2e%22%20%22%20%22%3f%20t%5fname%20name%3b%20%22%20%22%3f%7d%0a%20%20%20
%20t%5fname%20name%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3ct%5fitem
%3e%20arr%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fblock%5fexpr%3e%20params%3f%3b%0a%2
0%20%7d%0a%20%20t%5fwhen%5fbranch%7b%0a%20%20%20%20%22when%22%0a%20%20%20%20%22%
20%22%3f%0a%20%20%20%20t%5flev08%20cond%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%2
0%20%22then%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5flev08%20result%3b%0a
%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%0a%20%20t%5felse%5fbranch%7b%0a%20%20%20
%20%22else%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5flev08%20result%3b%0a%
20%20%7d%0a%0a%20%20t%5fcase%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20%22case%22%0a%20
%20%20%20%22%20%22%3f%0a%20%20%20%20t%5flev08%20input%3f%3b%0a%20%20%20%20%22%20
%22%3f%0a%20%20%20%20vector%3ct%5fwhen%5fbranch%3e%20arr%3b%0a%20%20%20%20TAutoP
tr%3ct%5felse%5fbranch%3e%20else%5fbranch%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20
%20%20%20%22end%22%0a%20%20%7d%0a%0a%20%20t%5fas%5falias%7bt%5fas%5fopt%7b%22as%
22%7d%20TAutoPtr%3ct%5fas%5fopt%3e%20opt%3f%3b%20%22%20%22%3f%20t%5fname%20alias
%3b%7d%0a%0a%20%20t%5fjoined%5ftable%5fpart%3ai%5ftable%5fexpr%7b%0a%20%20%20%20
%22%20%22%3f%0a%20%20%20%20string%20join%5ftype%3dany%5fstr%5ffrom%5fvec%28split
%28%22inner%20join%2cleft%20join%2cright%20join%2cfull%20join%2cjoin%22%2c%22%2c
%22%29%29%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fname%20right%3b%0a%20%
20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ct%5fas%5falias%3e%20as%3f%3b%0a%20
%20%20%20%22%20%22%3f%0a%20%20%20%20%22on%22%0a%20%20%20%20%22%20%22%3f%0a%20%20
%20%20t%5flev08%20on%5fcond%3b%0a%20%20%7d%0a%0a%20%20t%5ftable%5fexpr%3ai%5ftab
le%5fexpr%7b%0a%20%20%20%20t%5fname%20name%3b%0a%20%20%20%20%22%20%22%3f%0a%20%2
0%20%20TAutoPtr%3ct%5fas%5falias%3e%20as%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%
20%20%20vector%3ct%5fjoined%5ftable%5fpart%3e%20arr%3f%3b%0a%20%20%20%20%22%20%2
2%3f%0a%20%20%7d%0a%0a%20%20t%5fsubquery%3ai%5ftable%5fexpr%7b%0a%20%20%20%20%22
%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ci%5fdata%5fstat%3e%20
query%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%29%22%0a%20%20%20%20%22%20
%22%3f%0a%20%20%20%20TAutoPtr%3ct%5fas%5falias%3e%20as%3f%3b%0a%20%20%7d%0a%0a%2
0%20t%5fin%5flist%3ai%5fin%5foperand%7b%0a%20%20%20%20%22%28%22%0a%20%20%20%20%2
2%20%22%3f%0a%20%20%20%20vector%3ct%5flev08%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%
0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%29%22%0a%20%20%7d%0a%0a%20%20t%5fin
%5fsubquery%3ai%5fin%5foperand%7b%0a%20%20%20%20t%5fsubquery%20body%3b%0a%20%20%
7d%0a%0a%20%20t%5ffrac%5fpart%7b%0a%20%20%20%20%22%2e%22%0a%20%20%20%20string%20
digits%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fexp%5fpart
%7b%0a%20%20%20%20char%20e%3dany%5fchar%28%22eE%22%29%3b%0a%20%20%20%20string%20
sign%3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3f%3b%
0a%20%20%20%20string%20digits%3dany%28gen%5fdips%28%2209%22%29%29%3b%0a%20%20%7d
%0a%0a%20%20t%5fnum%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20t%5fint%5fpart%3ai%5fnum%
5fpart%7b%0a%20%20%20%20%20%20char%20first%3dany%5fchar%28gen%5fdips%28%2219%22%
29%29%3b%0a%20%20%20%20%20%20string%20rest%3dany%28gen%5fdips%28%2209%22%29%29%3
f%3b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fzero%5fpart%3ai%5fnum%5fpart%7b%220%22%
7d%0a%20%20%20%20t%5fimpl2%3ai%5fimpl%7b%0a%20%20%20%20%20%20TAutoPtr%3ct%5ffrac
%5fpart%3e%20frac%3b%0a%20%20%20%20%20%20TAutoPtr%3ct%5fexp%5fpart%3e%20exp%3f%3
b%0a%20%20%20%20%7d%0a%20%20%20%20t%5fimpl%3ai%5fimpl%7b%0a%20%20%20%20%20%20%2f
%2fstring%20sign%3dany%5fstr%5ffrom%5fvec%28split%28%22%2b%2c%2d%22%2c%22%29%29%
3f%3b%0a%20%20%20%20%20%20TAutoPtr%3ci%5fnum%5fpart%3e%20int%5fpart%3b%0a%20%20%
20%20%20%20TAutoPtr%3ct%5ffrac%5fpart%3e%20frac%3f%3b%0a%20%20%20%20%20%20TAutoP
tr%3ct%5fexp%5fpart%3e%20exp%3f%3b%0a%20%20%20%20%7d%0a%20%20%20%20string%20valu
e%3dstr%3cTAutoPtr%3ci%5fimpl%3e%3e%28%29%3b%0a%20%20%7d%0a%0a%20%20t%5fnullif%5
ffunc%3ai%5fexpr%7b%0a%20%20%20%20string%20kw%3dany%5fstr%5ffrom%5fvec%28split%2
8%22nullif%2cifnull%22%2c%22%2c%22%29%29%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%
20%20%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5flev08%20left%3b%0a%2
0%20%20%20%22%20%22%3f%0a%20%20%20%20%22%2c%22%0a%20%20%20%20%22%20%22%3f%0a%20%
20%20%20t%5flev08%20right%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%29%22%
0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%0a%20%20t%5fhost%5fexpr%3ai%5fexpr%7b%
0a%20%20%20%20%22%3a%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ct%5f
pascal%5fexpr%3e%20expr%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%0a%20%20t%5
fwhere%5fclause%7b%0a%20%20%20%20%22where%22%0a%20%20%20%20%22%20%22%3f%0a%20%20
%20%20t%5flev08%20cond%3b%0a%20%20%7d%0a%0a%20%20t%5fcolumn%5fitem%7b%0a%20%20%2
0%20%22%20%22%3f%0a%20%20%20%20t%5flev08%20expr%3b%0a%20%20%20%20%22%20%22%3f%0a
%20%20%20%20TAutoPtr%3ct%5fas%5falias%3e%20as%3f%3b%0a%20%20%20%20%22%20%22%3f%0
a%20%20%7d%0a%0a%20%20t%5fcolumn%5flist%7b%0a%20%20%20%20t%5farr%3ai%5fclist%5fi
tem%7bvector%3ct%5fcolumn%5fitem%3e%20arr%3dvec%28%22%2c%22%29%3b%7d%0a%20%20%20
%20t%5fstar%3ai%5fclist%5fitem%7b%22%2a%22%7d%0a%20%20%20%20TAutoPtr%3ci%5fclist
%5fitem%3e%20item%3b%0a%20%20%7d%0a%0a%20%20t%5fgroup%5fby%5fclause%7b%0a%20%20%
20%20%22group%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22by%22%0a%20%20%20%2
0%22%20%22%3f%0a%20%20%20%20t%5fcolumn%5flist%20cols%3b%0a%20%20%7d%0a%0a%20%20t
%5fhaving%5fclause%7b%0a%20%20%20%20%22having%22%0a%20%20%20%20%22%20%22%3f%0a%2
0%20%20%20t%5flev08%20cond%3b%0a%20%20%7d%0a%0a%20%20t%5forder%5fby%5fitem%7b%0a
%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fvarcall%5fexpr%20expr%3b%0a%20%20%20%
20%22%20%22%3f%0a%20%20%20%20string%20order%3dany%5fstr%5ffrom%5fvec%28split%28%
22asc%2cdesc%22%2c%22%2c%22%29%29%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0
a%0a%20%20t%5forder%5fby%5fclause%7b%0a%20%20%20%20%22order%22%20%22%20%22%3f%20
%22by%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3ct%5forder%5fby%5fitem
%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%7d%0a%0a%20%20t%5fselect%5fstat%3a
i%5fdata%5fstat%7b%0a%20%20%20%20t%5ffrom%7b%0a%20%20%20%20%20%20%22from%22%0a%2
0%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%20%20TAutoPtr%3ci%5ftable%5fexpr%3e%
20table%3b%0a%20%20%20%20%20%20%22%20%22%3f%0a%20%20%20%20%7d%0a%20%20%20%20stri
ng%20kw%3dany%5fstr%5ffrom%5fvec%28split%28%22select%2csingle%22%2c%22%2c%22%29%
29%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20string%20ad%3dany%5fstr%5ffrom%5f
vec%28split%28%22all%2cdistinct%22%2c%22%2c%22%29%29%3f%3b%0a%20%20%20%20%22%20%
22%3f%0a%20%20%20%20t%5fcolumn%5flist%20cols%3b%0a%20%20%20%20%22%20%22%3f%0a%20
%20%20%20TAutoPtr%3ct%5ffrom%3e%20from%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fwhere%
5fclause%3e%20where%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAutoPtr%3ct%
5fgroup%5fby%5fclause%3e%20group%5fby%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%
20%20TAutoPtr%3ct%5fhaving%5fclause%3e%20having%3f%3b%0a%20%20%20%20%22%20%22%3f
%0a%20%20%20%20TAutoPtr%3ct%5forder%5fby%5fclause%3e%20order%5fby%3f%3b%0a%20%20
%7d%0a%0a%20%20t%5fsubquery%5fexpr%3ai%5fexpr%7b%0a%20%20%20%20%22%28%22%0a%20%2
0%20%20%22%20%22%3f%0a%20%20%20%20t%5fselect%5fstat%20query%3b%0a%20%20%20%20%22
%20%22%3f%0a%20%20%20%20%22%29%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20TAuto
Ptr%3ct%5fas%5falias%3e%20as%3f%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%0a%
20%20t%5funion%5fpart%7b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20string%20op%3d
any%5fstr%5ffrom%5fvec%28split%28%22union%2cunion%20all%22%2c%22%2c%22%29%29%3b%
0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fselect%5fstat%20query%3b%0a%20%20%7
d%0a%0a%20%20t%5funion%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%20%20t%5fselect%5fst
at%20first%3b%0a%20%20%20%20vector%3ct%5funion%5fpart%3e%20unions%3b%0a%20%20%7d
%0a%0a%20%20t%5fvalues%5frow%7b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%28%
22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vector%3ct%5flev08%5fwith%5fsep%3e%2
0arr%3dvec%28%22%2c%22%29%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%29%22%
0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%0a%20%20t%5fvalues%5fbody%3ai%5finsert
%5fbody%7b%0a%20%20%20%20%22values%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20v
ector%3ct%5fvalues%5frow%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%7d%0a%0a%2
0%20t%5fselect%5fbody%3ai%5finsert%5fbody%7b%0a%20%20%20%20t%5fselect%5fstat%20q
uery%3b%0a%20%20%7d%0a%0a%20%20t%5finsert%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%2
0%20%22insert%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22into%22%0a%20%20%20
%20%22%20%22%3f%0a%20%20%20%20t%5fvarcall%5fexpr%20table%3b%0a%20%20%20%20%22%20
%22%3f%0a%20%20%20%20TAutoPtr%3ci%5finsert%5fbody%3e%20body%3b%0a%20%20%7d%0a%0a
%20%20t%5fupdate%5fitem%7b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fname%20c
ol%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22%3d%22%0a%20%20%20%20%22%20%22
%3f%0a%20%20%20%20t%5flev08%20expr%3b%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%
0a%20%20t%5fupdate%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%20%20%22update%22%0a%20%
20%20%20%22%20%22%3f%0a%20%20%20%20t%5fname%20table%3b%0a%20%20%20%20%22%20%22%3
f%0a%20%20%20%20%22set%22%0a%20%20%20%20vector%3ct%5fupdate%5fitem%3e%20arr%3dve
c%28%22%2c%22%29%3f%3b%0a%20%20%20%20TAutoPtr%3ct%5fwhere%5fclause%3e%20where%3f
%3b%0a%20%20%7d%0a%0a%20%20t%5fdelete%5fstat%3ai%5fdata%5fstat%7b%0a%20%20%20%20
%22delete%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20%22from%22%0a%20%20%20%20%
22%20%22%3f%0a%20%20%20%20t%5fname%20table%3b%0a%20%20%20%20%22%20%22%3f%0a%20%2
0%20%20TAutoPtr%3ct%5fwhere%5fclause%3e%20where%3f%3b%0a%20%20%7d%0a%0a%20%20t%5
fsep%5fstat%3ai%5fdata%5fstat%7b%22%20%22%7d%0a%20%20t%5fsemicolon%5fstat%3ai%5f
data%5fstat%7b%22%3b%22%7d%0a%0a%20%20t%5fscript%7b%0a%20%20%20%20vector%3cTAuto
Ptr%3ci%5fdata%5fstat%3e%3e%20stats%3b%0a%20%20%7d%0a%7d%0a%2f%2f%2d%2d%2d%0a%2f
%2f2025%2e08%2e14%2009%3a44%3a54%2e655%0a%2f%2ft%5ftrue%3ai%5fexpr%7b%22true%22%
20%22%20%22%3f%7d%0a%2f%2ft%5ffalse%3ai%5fexpr%7b%22false%22%20%22%20%22%3f%7d%0
a%2f%2ft%5fnil%3ai%5fexpr%7b%22nil%22%20%22%20%22%3f%7d%0a%2f%2ft%5fnull%3ai%5fe
xpr%7b%22null%22%20%22%20%22%3f%7d%0at%5fsep%7b%0a%20%20t%5fcomment%3ai%5fsep%7b
%22%7b%22%20string%20s%3dany%28dip%5finv%28%22%7d%22%29%29%3b%20%22%7d%22%7d%0a%
20%20t%5fc%5fcomment%3ai%5fsep%7b%22%2f%2f%22%20string%20body%3dany%28dip%5finv%
28%22%5cn%5cr%22%29%29%3b%7d%0a%20%20t%5fraw%5fsep%3ai%5fsep%7bstring%20s%3dany%
28%22%20%5cr%5cn%5ct%22%29%3b%7d%0a%20%20string%20value%3dstr%3cvector%3cTAutoPt
r%3ci%5fsep%3e%3e%3e%28%29%3b%0a%7d%0atypedef%20array%3cchar%2c2%3e%20ARRAY2char
%3b%0atypedef%20array%3cchar%2c4%3e%20ARRAY4char%3b%0ausing%20%22%20%22%20as%20t
%5fsep%3b%0at%5fname%7b%0a%20%20t%5fkeyword%7b%0a%20%20%20%20string%20value%3dan
y%5fstr%5ffrom%5fvec%28split%28%22begin%2cend%2cvar%2cprocedure%2cfunction%2cif%
2cthen%2celse%2cfor%2cto%2cdownto%2cdo%2cwhile%2crepeat%2cuntil%2ccase%2cof%2cco
nst%2ctype%2carray%2crecord%2cprogram%2cdiv%2cmod%2cand%2cor%2cnot%2cbreak%2ccon
tinue%2cshr%2cshl%2cxor%22%2c%22%2c%22%29%29%3b%0a%20%20%7d%0a%20%20t%5fimpl%7b%
0a%20%20%20%20char%20A%3dany%5fchar%28gen%5fdips%28%22azAZ%22%29%2b%22%5f%22%29%
3b%0a%20%20%20%20string%20B%3dany%28gen%5fdips%28%22azAZ09%22%29%2b%22%5f%22%29%
3f%3b%0a%20%20%7d%0a%20%20t%5fimpl%5fex%7b%0a%20%20%20%20t%5fimpl%20impl%3ddiff%
3ct%5fkeyword%3e%28%29%3b%0a%20%20%7d%0a%20%20string%20value%3dstr%3ct%5fimpl%5f
ex%3e%28%29%3b%0a%7d%0at%5fname%5fwith%5fsep%7b%22%20%22%3f%20t%5fname%20n%3b%20
%22%20%22%3f%7d%0at%5fstring%3d%3ei%5fexpr%7b%0a%20%20t%5fraw%3d%3ei%5fitem%7bst
ring%20body%3dany%28dip%5finv%28%22%27%5c%5c%5cn%22%29%29%3b%7d%0a%20%20t%5ffix%
3d%3ei%5fitem%7b%22%5c%5c%22%20char%20body%3dany%5fchar%28%22%27%5c%22%5c%5c%2fb
fnrt%22%29%3b%7d%0a%20%20t%5fhex%3d%3ei%5fitem%7b%22%5c%5cu%22%20ARRAY4char%20ar
r%3dany%5farr%5fchar%28gen%5fdips%28%2209afAF%22%29%29%3b%7d%0a%20%20%22%27%22%0
a%20%20vector%3cTAutoPtr%3ci%5fitem%3e%3e%20arr%3f%3b%0a%20%20%22%27%22%0a%20%20
%22%20%22%3f%0a%7d%0at%5fnumber%3d%3ei%5fexpr%7b%0a%20%20t%5fminus%7b%22%2d%22%7
d%0a%20%20t%5ffrac%7b%22%2e%22%20string%20arr%3dany%28gen%5fdips%28%2209%22%29%2
9%3b%7d%0a%20%20t%5fsign%7bchar%20sign%3dany%5fchar%28%22%2d%2b%22%29%3b%7d%0a%2
0%20t%5fexp%7b%0a%20%20%20%20char%20e%3dany%5fchar%28%22eE%22%29%3b%0a%20%20%20%
20TAutoPtr%3ct%5fsign%3e%20sign%3f%3b%0a%20%20%20%20string%20arr%3dany%28gen%5fd
ips%28%2209%22%29%29%3b%0a%20%20%20%20%0a%20%20%7d%0a%20%20t%5fnum%3d%3ei%5fint%
7b%0a%20%20%20%20char%20first%3dany%5fchar%28gen%5fdips%28%2219%22%29%29%3b%0a%2
0%20%20%20string%20num%3dany%28gen%5fdips%28%2209%22%29%29%3f%3b%0a%20%20%7d%0a%
20%20t%5fzero%3d%3ei%5fint%7b%220%22%7d%0a%20%20TAutoPtr%3ct%5fminus%3e%20minus%
3f%3b%0a%20%20TAutoPtr%3ci%5fint%3e%20val%3b%0a%20%20TAutoPtr%3ct%5ffrac%3e%20fr
ac%3f%3b%0a%20%20TAutoPtr%3ct%5fexp%3e%20exp%3f%3b%0a%20%20%22%20%22%3f%0a%7d%0a
t%5fsql%5fexpr%3ai%5fexpr%7b%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a%20%20TAut
oPtr%3ct%5fsql%3a%3ai%5fdata%5fstat%3e%20data%5fstat%3b%0a%20%20%22%20%22%3f%0a%
20%20%22%29%22%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5farray%5ftype%3ai%5fvar%5ftype
%7b%0a%20%20t%5fof%7b%22of%22%20%22%20%22%3f%20t%5fname%20type%3b%20%22%20%22%3f
%7d%0a%20%20%22array%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fof%3e%20of%3
f%3b%0a%7d%0at%5fvar%5ftype%3ai%5fvar%5ftype%7bt%5fname%20type%3b%20%22%20%22%3f
%7d%0at%5fvar%5fdecl%7b%0a%20%20vector%3ct%5fname%5fwith%5fsep%3e%20names%3dvec%
28%22%2c%22%29%3b%0a%20%20%22%3a%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5f
var%5ftype%3e%20type%3b%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%7d%0at%5fvar%3
ai%5fstat%7b%0a%20%20%22var%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ct%5fvar%5fd
ecl%3e%20arr%3b%0a%20%20%22%20%22%3f%0a%7d%0at%5fenum%5fdecl%7b%0a%20%20t%5fvalu
e%7b%22%3d%22%20%22%20%22%3f%20t%5fnumber%20num%3b%20%22%20%22%3f%7d%0a%20%20t%5
felem%7b%22%20%22%3f%20t%5fname%20name%3b%20%22%20%22%3f%20TAutoPtr%3ct%5fvalue%
3e%20value%3f%3b%7d%0a%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20%22%
3d%22%0a%20%20%22%20%22%3f%0a%20%20%22%28%22%3f%0a%20%20vector%3ct%5felem%3e%20t
ype%3dvec%28%22%2c%22%29%3b%0a%20%20%22%29%22%0a%20%20%22%20%22%3f%0a%20%20%22%3
b%22%0a%20%20%22%20%22%3f%0a%7d%0at%5ftype%3ai%5fstat%7b%0a%20%20%22type%22%0a%2
0%20%22%20%22%3f%0a%20%20vector%3ct%5fenum%5fdecl%3e%20arr%3b%0a%20%20%22%20%22%
3f%0a%7d%0at%5fparam%5fdecl%7b%0a%20%20t%5fitem%7b%22%20%22%3f%20t%5fname%20name
%3b%20%22%20%22%3f%7d%0a%20%20t%5fconst%7b%22const%22%20%22%20%22%7d%0a%20%20t%5
fdefvalue%7b%22%3d%22%20%22%20%22%3f%20t%5fnumber%20num%3b%7d%0a%20%20TAutoPtr%3
ct%5fconst%3e%20c%3f%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3dvec%28%22%2c%22%29%
3b%0a%20%20%22%3a%22%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fvar%5ftype%3e%2
0type%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5fdefvalue%3e%20value%3f%3b%0
a%20%20%22%20%22%3f%0a%7d%0at%5fparams%5fdecl%7b%0a%20%20%22%28%22%0a%20%20%22%2
0%22%3f%0a%20%20vector%3ct%5fparam%5fdecl%3e%20arr%3dvec%28%22%3b%22%29%3f%3b%0a
%20%20%22%20%22%3f%0a%20%20%22%29%22%0a%7d%0a%0at%5fexit%5fstat%3ai%5fstat%7b%22
exit%22%20%22%20%22%3f%20%22%3b%22%20%22%20%22%3f%7d%0at%5fbreak%5fstat%3ai%5fst
at%7b%22break%22%20%22%20%22%3f%20%22%3b%22%20%22%20%22%3f%7d%0at%5fcontinue%5fs
tat%3ai%5fstat%7b%22continue%22%20%22%20%22%3f%20%22%3b%22%20%22%20%22%3f%7d%0a%
0at%5fblock%5fstat%3ai%5fstat%7b%0a%20%20%22begin%22%0a%20%20%22%20%22%3f%0a%20%
20vector%3ci%5fstat%3e%20arr%3b%0a%20%20%22%20%22%3f%0a%20%20%22end%22%0a%20%20%
22%20%22%3f%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%7d%0at%5flev01%7b%0a%20%20
string%20oper%3dany%5fstr%5ffrom%5fvec%28split%28%22not%2c%5e%2c%40%2cnew%22%2c%
22%2c%22%29%29%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fexpr%3e%20expr%
3b%0a%7d%0at%5flev02%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fv
ec%28split%28%22%2a%2c%2f%2cdiv%2cmod%2cand%2cshl%2cshr%22%2c%22%2c%22%29%29%3b%
7d%0a%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20oper%3b%22%20%22%3ft%5flev01%20e
xpr%3b%7d%0a%20%20t%5flev01%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0
a%7d%0at%5flev03%7b%0a%20%20t%5foper%7bstring%20value%3dany%5fstr%5ffrom%5fvec%2
8split%28%22%2b%2c%2d%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fitem%7b%22%20%22%3f
%20t%5foper%20oper%3b%22%20%22%3ft%5flev02%20expr%3b%7d%0a%20%20t%5flev02%20expr
%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev04%7b%0a%20%20t%5fop
er%7bstring%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%3d%2c%3c%3e%2c%3c%2c%
3e%2c%3c%3d%2c%3e%3d%2cin%2cis%2clike%22%2c%22%2c%22%29%29%3b%7d%0a%20%20t%5fite
m%7b%22%20%22%3f%20t%5foper%20oper%3b%22%20%22%3ft%5flev03%20expr%3b%7d%0a%20%20
t%5flev03%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0at%5flev05%7
b%0a%20%20t%5foper%7b%22xor%22%5b%3a%3a%5dinline%20static%20const%20string%20val
ue%3d%22xor%22%3b%7d%0a%20%20t%5fitem%7b%22%20%22%3ft%5foper%20oper%3b%22%20%22%
3ft%5flev04%20expr%3b%7d%0a%20%20t%5flev04%20expr%3b%0a%20%20vector%3ct%5fitem%3
e%20arr%3f%3b%0a%7d%0at%5flev06%7b%0a%20%20t%5foper%7b%22or%22%5b%3a%3a%5dinline
%20static%20const%20string%20value%3d%22or%22%3b%7d%0a%20%20t%5fitem%7b%22%20%22
%3ft%5foper%20oper%3b%22%20%22%3ft%5flev05%20expr%3b%7d%0a%20%20t%5flev05%20expr
%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f%3b%0a%7d%0a%2f%2a%0avar%20pad2%3dnum%3
d%3e%28num%3c10%3f%220%22%2bnum%3a%22%22%2bnum%29%3b%0areturn%28%0a%60not%2c%5e%
2c%40%2cnew%0a%2a%2c%2f%2cdiv%2cmod%2cand%2cshl%2cshr%0a%2b%2c%2d%0a%3d%2c%3c%3e
%2c%3c%2c%3e%2c%3c%3d%2c%3e%3d%2cin%2cis%2clike%0axor%0aor%60%2esplit%28%22%5cr%
22%29%2ejoin%28%22%22%29%2esplit%28%22%5cn%22%29%2emap%28%28ops%2ci%29%3d%3e%7b%
0a%20%20var%20e%3d%22t%5flev%22%2bpad2%28%21i%3f1%3ai%29%3b%0a%20%20var%20n%3d%2
2t%5flev%22%2bpad2%28i%2b1%29%3b%20%20%0a%20%20if%28%21i%29%7b%0a%20%20%20%20ret
urn%20%60t%5flev01%7b%0a%20%20string%20oper%3dany%5fstr%5ffrom%5fvec%28split%28%
60%2bJSON%2estringify%28ops%29%2b%60%2c%22%2c%22%29%29%3f%3b%0a%20%20%22%20%22%3
f%0a%20%20TAutoPtr%3ci%5fexpr%3e%20expr%3b%0a%7d%60%3b%0a%20%20%7d%0a%20%20var%2
0oa%3dops%2esplit%28%22%2c%22%29%3b%0a%20%20if%28oa%2elength%3d%3d1%29%7b%0a%20%
20%20%20return%20n%2b%60%7b%0a%20%20t%5foper%7b%22%60%2boa%5b0%5d%2b%60%22%5b%3a
%3a%5dinline%20static%20const%20string%20value%3d%22%60%2boa%5b0%5d%2b%60%22%3b%
7d%0a%20%20t%5fitem%7b%22%20%22%3ft%5foper%20oper%3b%22%20%22%3f%60%2be%2b%60%20
expr%3b%7d%0a%20%20%60%2be%2b%60%20expr%3b%0a%20%20vector%3ct%5fitem%3e%20arr%3f
%3b%0a%7d%60%3b%0a%20%20%7d%0a%20%20return%20n%2b%60%7b%0a%20%20t%5foper%7bstrin
g%20value%3dany%5fstr%5ffrom%5fvec%28split%28%22%60%2bops%2b%60%22%2c%22%2c%22%2
9%29%3b%7d%0a%20%20t%5fitem%7b%22%20%22%3f%20t%5foper%20oper%3b%22%20%22%3f%60%2
be%2b%60%20expr%3b%7d%0a%20%20%60%2be%2b%60%20expr%3b%0a%20%20vector%3ct%5fitem%
3e%20arr%3f%3b%0a%7d%60%3b%0a%7d%29%2ejoin%28%22%5cn%22%29%29%3b%0a%2a%2f%0a%0at
%5fexpr%7b%0a%20%20t%5fas%7b%22as%22%20%22%20%22%20t%5fname%20type%3b%20%22%20%2
2%3f%7d%0a%20%20t%5flev06%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5f
as%3e%20as%3f%3b%0a%7d%0a%0at%5fparam%7b%22%20%22%3f%20t%5fexpr%20expr%3b%20%22%
20%22%3f%7d%0a%0at%5fsb%5fexpr%3ai%5fexpr%7b%0a%20%20t%5farr%5felem%3ai%5felem%7
b%22%5b%22%20%22%20%22%3f%20vector%3ct%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3b%
20%22%5d%22%20%22%20%22%3f%7d%0a%20%20t%5fdot%5felem%3ai%5felem%7b%22%2e%22%20%2
2%20%22%3f%20t%5fname%20name%3b%20%22%20%22%3f%7d%0a%20%20t%5fparams%5felem%3ai%
5felem%7b%0a%20%20%20%20%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20vecto
r%3ct%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%20%20%22%29%22%0a%20%
20%20%20%22%20%22%3f%0a%20%20%7d%0a%20%20%22%5b%22%0a%20%20%22%20%22%3f%0a%20%20
vector%3ct%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%22%5d%22%0a%20%2
0%22%20%22%3f%0a%20%20vector%3cTAutoPtr%3ci%5felem%3e%3e%20elems%3f%3b%0a%7d%0a%
0at%5fif%5fstat%3ai%5fstat%7b%0a%20%20t%5felse%7b%22else%22%20%22%20%22%3f%20TAu
toPtr%3ci%5fstat%3e%20stat%3b%20%22%20%22%3f%7d%0a%20%20%22if%22%0a%20%20%22%20%
22%3f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22then%22%0a%20%2
0%22%20%22%3f%0a%20%20TAutoPtr%3ci%5fstat%3e%20stat%3b%0a%20%20TAutoPtr%3ct%5fel
se%3e%20estat%3f%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0a%0a%2f%2a%0afoo%2ebar%28%29%
3bfoo%28%29%28%29%3bfoo%5b0%5d%28%29%3bfoo%2ebar%5b0%5d%2exx%2ebaz%5b1%2c5%5d%5b
0%5d%28%29%28%29%5b0%5d%3b%0a%2a%2f%0at%5fvarcall%5fexpr%3ai%5fexpr%7b%0a%20%20t
%5fderef%5felem%3ai%5felem%7b%22%5e%22%20%22%20%22%3f%7d%0a%20%20t%5farr%5felem%
3ai%5felem%7b%22%5b%22%20%22%20%22%3f%20vector%3ct%5fparam%3e%20arr%3dvec%28%22%
2c%22%29%3b%20%22%5d%22%20%22%20%22%3f%7d%0a%20%20t%5fdot%5felem%3ai%5felem%7b%2
2%2e%22%20%22%20%22%3f%20t%5fname%20name%3b%20%22%20%22%3f%7d%0a%20%20t%5fparams
%5felem%3ai%5felem%7b%0a%20%20%20%20%22%28%22%0a%20%20%20%20%22%20%22%3f%0a%20%2
0%20%20vector%3ct%5fparam%3e%20arr%3dvec%28%22%2c%22%29%3f%3b%0a%20%20%20%20%22%
29%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%7d%0a%20%20t%5fname%20name%3b%0a%20%20
%22%20%22%3f%0a%20%20vector%3cTAutoPtr%3ci%5felem%3e%3e%20arr%3f%3b%0a%20%20%22%
20%22%3f%0a%7d%0a%0at%5fassign%5fstat%3ai%5fstat%7b%0a%20%20t%5fvarcall%5fexpr%2
0var%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3a%3d%22%0a%20%20%22%20%22%3f%0a%20%20t
%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a
%7d%0a%0at%5ffor%5fstat%3ai%5fstat%7b%0a%20%20%22for%22%20%22%20%22%3f%0a%20%20t
%5fassign%5fstat%20from%3b%0a%20%20%22%20%22%3f%0a%20%20string%20dir%3dany%5fstr
%5ffrom%5fvec%28split%28%22to%2cdownto%22%2c%22%2c%22%29%29%3b%0a%20%20%22%20%22
%3f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22do%22%0a%20%20%22
%20%22%3f%0a%20%20TAutoPtr%3ci%5fstat%3e%20body%3b%0a%7d%0a%0at%5fblock%5fexpr%3
ai%5fexpr%7b%0a%20%20%22%28%22%0a%20%20%22%20%22%3f%0a%20%20t%5fexpr%20expr%3b%0
a%20%20%22%20%22%3f%0a%20%20%22%29%22%0a%20%20%22%20%22%3f%0a%20%20vector%3cTAut
oPtr%3ct%5fvarcall%5fexpr%3a%3ai%5felem%3e%3e%20arr%3f%3b%0a%20%20%22%20%22%3f%0
a%7d%0a%0at%5fwhile%5fstat%3ai%5fstat%7b%0a%20%20%22while%22%0a%20%20%22%20%22%3
f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22do%22%0a%20%20%22%2
0%22%3f%0a%20%20TAutoPtr%3ci%5fstat%3e%20stat%3b%0a%20%20%22%20%22%3f%0a%7d%0a%0
at%5frepeat%5fstat%3ai%5fstat%7b%0a%20%20%22repeat%22%0a%20%20%22%20%22%3f%0a%20
%20vector%3cTAutoPtr%3ci%5fstat%3e%3e%20arr%3b%0a%20%20%22%20%22%3f%0a%20%20%22u
ntil%22%0a%20%20%22%20%22%3f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%
20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%7d%0a%0at%5fcase%5fitem%7b%0a%20%20t%5fex
pr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3a%22%0a%20%20%22%20%22%3f%0a%20%2
0vector%3cTAutoPtr%3ci%5fstat%3e%3e%20arr%3b%0a%20%20%22%3b%22%0a%20%20%22%20%22
%3f%0a%7d%0a%0at%5fcase%5fstat%3ai%5fstat%7b%0a%20%20%22case%22%0a%20%20%22%20%2
2%3f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%22%3f%0a%20%20%22of%22%0a%20%20%2
2%20%22%3f%0a%20%20vector%3ct%5fcase%5fitem%3e%20arr%3b%0a%20%20%22%20%22%3f%0a%
20%20%22end%22%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%7d
%0a%0at%5fconst%5fdecl%7b%0a%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%
20%22%3d%22%0a%20%20%22%20%22%3f%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%3b%22%0a
%20%20%22%20%22%3f%0a%7d%0a%0at%5fconst%3ai%5fstat%7b%0a%20%20%22const%22%0a%20%
20%22%20%22%0a%20%20vector%3ct%5fconst%5fdecl%3e%20arr%3b%0a%20%20%22%20%22%3f%0
a%7d%0at%5fexpr%5fstat%3ai%5fstat%7b%0a%20%20t%5fexpr%20expr%3b%0a%20%20%22%20%2
2%3f%0a%20%20%22%3b%22%0a%20%20%22%20%22%3f%0a%7d%0a%2f%2ft%5fsep%5fstat%3ai%5fs
tat%7b%22%20%22%7d%0at%5fsemicolon%5fstat%3ai%5fstat%7b%22%3b%22%20%22%20%22%3f%
7d%0at%5ffunc%5for%5fproc%5fstat%3ai%5fstat%7b%0a%20%20t%5fret%5ftype%7b%0a%20%2
0%20%20%22%3a%22%0a%20%20%20%20%22%20%22%3f%0a%20%20%20%20t%5fname%20name%3b%0a%
20%20%7d%0a%20%20t%5fvar%5fd%3ai%5fd%7bt%5fvar%20d%3b%22%20%22%3f%7d%0a%20%20t%5
fconst%5fd%3ai%5fd%7bt%5fconst%20d%3b%22%20%22%3f%7d%0a%20%20string%20kw%3dany%5
fstr%5ffrom%5fvec%28split%28%22function%2cprocedure%22%2c%22%2c%22%29%29%3b%0a%2
0%20%22%20%22%0a%20%20t%5fname%20name%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3
ct%5fparams%5fdecl%3e%20params%3f%3b%0a%20%20%22%20%22%3f%0a%20%20TAutoPtr%3ct%5
fret%5ftype%3e%20type%3f%3b%0a%20%20%22%20%22%3f%0a%20%20%22%3b%22%0a%20%20%22%2
0%22%3f%0a%20%20vector%3cTAutoPtr%3ci%5fd%3e%3e%20darr%3f%3b%0a%20%20%22%20%22%3
f%0a%20%20%22begin%22%0a%20%20%22%20%22%3f%0a%20%20vector%3ci%5fstat%3e%20arr%3f
%3b%0a%20%20%22%20%22%3f%0a%20%20%22end%22%0a%20%20%22%20%22%3f%0a%20%20%22%3b%2
2%0a%20%20%22%20%22%3f%0a%7d
*/