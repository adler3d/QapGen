t_templ_sys_v02{
  t_data:i_item{
    t_impl{
      vector<TAutoPtr<i_seq>> arr;
    }
    string body=str<t_impl>;
  }
  t_var:i_item{
    "^^^"
    string name=any(gen_dips("azAZ09")+"_$@");
    "^^^"
  }
  t_raw:i_seq{
    string body=any(dip_inv("^"));
  }
  t_caret:i_seq {
    t_impl{"^"}
    t_impl body=if_not_then<t_var>;
  }
  vector<TAutoPtr<i_item>> arr;
  struct t_inp
  {
    struct t_rec{
      string from;
      string to;
    };
    vector<t_rec> arr;
    void add(const string&from,const string&to){
      t_rec tmp={from,to};
      arr.push_back(std::move(tmp));
    }
    string lookup(const string&var)const{
      for(int i=0;i<arr.size();i++){
        auto&ex=arr[i];
        if(ex.from==var)return ex.to;
      }
      QapAssert(false);
      return "";
    }
  };
  class t_item_visitor:public i_item::i_visitor{
  public:
    class t_dev{
    public:
      string&out;
      const t_inp&inp;
    };
  public:
    t_dev&dev;
    t_item_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_data*p){dev.out+=p->body;}
    void Do(t_var*p){dev.out+=dev.inp.lookup(p->name);}
  };
  string eval(const t_inp&inp)const
  {
    string out;
    t_item_visitor::t_dev dev={out,inp};
    t_item_visitor V(dev);
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      QapAssert(ex);
      auto*p=ex.get();
      p->Use(V);
    }
    return out;
  }
}