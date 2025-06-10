struct TConservationMachine 
{
  typedef TServerPtrSpace TSpace;
  typedef TQapBinaryObject::TRawPtrs TRawPtrs;
  TSpace Space;
  TSpaceDependsTools Tools;
  TClientPtrVcbCounter ClientCounter;
  TClientPtrVisitor ClientVisitor;
  DependsSolver DS;
  TQapBinaryObject&qbo;
  TRawPtrs ptrs;
  TConservationMachine(IEnvRTTI&Env,TQapBinaryObject&qbo):
    Tools(Env,Space),ClientCounter(Env,Space),ClientVisitor(ClientCounter),DS(Env,ClientVisitor),qbo(qbo)
  {
    ptrs.Init(Env,qbo);
    Space.AddPointsFromSys();
    Space.AddPointsFromEnv(Env);
    Tools.BuildProxy();
    Tools.PrepareEx();
    Tools.MegaPass();
  }
  ~TConservationMachine()
  {
    Space.clear();
  }
  static void Check_EachItemsOfTheSpaceIsNoPassed(TServerPtrSpace&Space)
  {
    vector<int> bad_items;
    auto&arr=Space.Arr;
    if(arr.empty())return;
    arr[0].CheckNullptr();
    for(int i=1;i<arr.size();i++)
    {
      auto&item=arr[i];
      if(item.passed)
      {
        string itemname=item.name.empty()?"{id="+IToS(i)+"}":item.name;
        QapDebugMsg("bad item -'"+itemname+"'");
        bad_items.push_back(i);
      }
    }
    if(bad_items.empty())return;
    QapDebugMsg("bad_items.size() == "+IToS(bad_items.size()));
  }
  struct TPointsHolder
  {
    vector<EnvItem> Arr;
    void move(TSpace&From,TSpace&To)
    {
      QapAssert(From.size()==To.size());
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(From.CheckServSaveID(ex.ptr.ptr));
        QapAssert(To.IsAllowed(SaveID));
        auto&from=From[SaveID];
        auto&to=To[SaveID];
        QapAssert(from.id==to.id);
        QapAssert(to.ptr.IsNull()&&to.ptr_lnk.IsNull());
        From.Del(from);
        To.InsertTo(to.id,ex);
      }
      bool debug_flag=false;
      if(debug_flag)Arr.clear();
    }
    void on(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(!SaveID);
        QapAssert(Space.IsAllowed(ex.id));
        auto&item=Space[ex.id];
        QapAssert(item.ptr.IsNull()&&item.ptr_lnk.IsNull());
        Space.InsertTo(ex.id,ex);
        QapAssert(SaveID);
      }
    }
    void off_all_objects(TSpace&Space)const
    {
      //set object.SaveID to zero
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&item=Space[SaveID];
        EnvItem temp;
        temp.copy(item);
        QapAssert(item.id==ex.id);
        Space.Del(item);
        QapAssert(!SaveID);
        item.copy(temp);
      }
    }
    void off_all_envitems(TSpace&Space,bool assert_objects_enabled=false)const
    {
      //set envitems.ptr to zero
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(assert_objects_enabled==bool(SaveID));
        QapAssert(Space.IsAllowed(ex.id));
        auto&item=Space[ex.id];
        QapAssert(item.ptr.IsValid()&&item.ptr_lnk.IsValid());
        item.ptr.set_zero();
        item.ptr_lnk.set_zero();
      }
    }
    void off(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(SaveID);
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&item=Space[SaveID];
        QapAssert(item.id==ex.id);
        Space.Del(item);
      }
    }
    void insert_to_end(TSpace&Space)const
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        QapAssert(ex.ptr.IsValid());
        auto&SaveID=ex.ptr.ptr->SaveID;
        QapAssert(!SaveID);
        Space.Insert(ex);
      }
    }
  };
  struct TUserPointsHolder:TPointsHolder
  {
    void take(TSpace&Space)
    {
      auto&arr=Space.Arr;
      if(arr.empty())return;
      arr[0].CheckNullptr();
      for(int i=1;i<arr.size();i++)
      {
        auto&item=arr[i];
        if(item.passed)
        {
          int id=Arr.size();
          this->Arr.push_back(EnvItem());
          auto&back=this->Arr.back();
          back.copy(item);
          QapAssert(back.name.empty());
          back.name="userpoint["+IToS(id)+"]";
        }
      }
    }
  };
  struct TSyncPointsHolder:TPointsHolder
  {
    typedef TSyncPointsHolder SelfClass;
    void sync(TSpace&Space)
    {
      for(int i=0;i<Arr.size();i++)
      {
        auto&ex=Arr[i];
        auto&item=Space[ex.ptr.ptr->SaveID];
        Space.Swap(ex.id,item.id);
      }
    }
    void copy(const TPointsHolder&ref)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        Arr[i].copy(ref.Arr[i]);
      }
    }
    void copy_envitem_lnk(const TPointsHolder&ref,TSpace&Space)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        auto&ex=ref.Arr[i];
        auto&ax=ex.get_lnk(Space);
        Arr[i].copy(ax);
      }
    }
    void copy_envitem_lnk_and_keep_id(const TPointsHolder&ref,TSpace&Space)
    {
      this->Arr.resize(ref.Arr.size());
      for(int i=0;i<ref.Arr.size();i++)
      {
        auto&ex=ref.Arr[i];
        auto&ax=ex.get_lnk(Space);
        Arr[i].copy(ax).id=ex.id;
      }
    }
    void update_id(const TSpace&Space)
    {
      auto&arr=Arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        QapAssert(ex.ptr.IsValid());
        QapAssert(Space.CheckServSaveID(ex.ptr.ptr));
        auto&SaveID=ex.ptr.ptr->SaveID;
        auto&item=Space[SaveID];
        QapAssert(item.oper_eq(ex,true));
        ex.id=SaveID;
      }
    }
    void insert_and_sync(TSpace&Space,TSpace&SpaceForIt)
    {
      auto&UpA=*this;
      UpA.off(Space);
      UpA.insert_to_end(SpaceForIt);
      SelfClass UpB;
      UpB.copy(UpA);
      UpB.update_id(SpaceForIt);
      UpB.off_all_objects(SpaceForIt);
      UpA.on(Space);
      UpB.sync(Space);
    }
  };
  static int get_lnk_id(TSpace&Space,TType*pType)
  {
    auto&item=Space[pType->Self];
    auto*p=(DeclareType*)item.ptr_lnk.get();
    return p->Self.P.SaveID;
  };
  /*
    out.MiniSpace - туда складыватся используемые(по версии Space) метатипы из arr, а потом они(используемые) привзяываются к SpaceForMetaSpec.
    TakeUsedMetatypesAndLinkHimWithSpace == InitMetaSpec
  */
  static void InitMetaSpec(TQapBinaryObject::TMetaSpec&out,TSpaceDependsTools::TDeclareTypeArray&arr,TSpace&Space,TSpace&SpaceForMetaSpec)
  {
    auto&SpaceFMS=SpaceForMetaSpec;
    {
      int count=arr.size();
      out.reserve(count);
      SpaceFMS.reserve(1+count+count);
    }
    auto get=[&Space](TType*pType)->int
    {
      return get_lnk_id(Space,pType);
    };
    auto copy_count_from_lnk_for_cur=[&Space,&get](TType*pType)
    {
      auto&cur_item=Space[pType->Self];
      auto&lnk_item=Space[get(pType)];
      QapAssert(!cur_item.count);
      if(cur_item.count==lnk_item.count)return;
      cur_item.count=lnk_item.count;
    };
    auto pass=[&Space,&SpaceFMS,&get,&out](TType*pType)
    {
      auto&sys_item=Space[pType->Self];
      auto&def_item=Space[get(pType)];
      if(!def_item.count)return;
      out.push_back(EnvDefTypeStr());
      auto&back=out.back();
      back.Decl.Name=pType->GetFullName();
      QapAssert(sys_item.name.substr(0,5)=="Sys$$");
      QapAssert(def_item.name.substr(0,5)=="Def$$");
      SpaceFMS.AddExt(EnvAdapter::get(back.Decl.Decl.Self),nullptr,"Def$$<"+back.Decl.Name+">::GetRTTI()").ptr_lnk=def_item.ptr;
      SpaceFMS.AddExt(EnvAdapter::get(back.Impl.Self),nullptr,"Sys$$<"+back.Decl.Name+">::GetRTTI()").ptr_lnk=sys_item.ptr;
    };
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      copy_count_from_lnk_for_cur(ex.first);
      copy_count_from_lnk_for_cur(ex.second);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(ex.first);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      pass(ex.second);
    }
  }
  static void SyncTwoSpace_Stage1(TQapBinaryObject::TMetaSpec&Spec,TSpace&Space,TSpace&SpaceFMS)
  {
    auto do_swap=[&Space,&SpaceFMS](EnvDefEntryPoint&EP)
    {
      auto&item=SpaceFMS[EP.Self];
      auto&jtem=Space[item.ptr_lnk.ptr->SaveID];
      QapAssert(jtem.name==item.name);
      Space.Swap(jtem.id,item.id);
    };
    auto&arr=Spec;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      do_swap(ex.Decl.Decl);
      do_swap(ex.Impl);
    }
  }
  struct SpaceScopeBot
  {    
    typedef TConservationMachine TMachine;
    TMachine&machine;
    TSpace&Space;
    SpaceScopeBot(TMachine&machine,TSpace&Space):machine(machine),Space(Space){Init();}
   ~SpaceScopeBot(){Free();}
    void Init()
    {
      std::swap(machine.Space,Space);
    }
    static void CheckAssert(TMachine&machine){QapAssert(&machine.qbo.SpaceSize==machine.ptrs.SpaceSize.pValue);}
    static void Go(TMachine&machine,IUberSaveDevice&dev,TRawPtr&raw_ptr)
    {
      CheckAssert(machine);
      machine.qbo.SpaceSize=machine.Space.size();
      dev.DoSave(machine,machine.ptrs.SpaceSize);
      dev.DoSave(machine,raw_ptr);
    }
    static void Go(TMachine&machine,IUberLoadDevice&dev,TRawPtr&raw_ptr)
    {
      CheckAssert(machine);
      dev.DoLoad(machine,machine.ptrs.SpaceSize);
      machine.Space.resize(machine.qbo.SpaceSize);
      dev.DoLoad(machine,raw_ptr);
    }
    void Free()
    {
      std::swap(machine.Space,Space);
    }
  };
  #include "QapUberSaver_TConMachine_GP_Bots.inl"
  template<class TYPE>
  struct SelectGoooDevContext{typedef void type;};
  template<>
  struct SelectGoooDevContext<IUberSaveDevice>{typedef GP_BotContext_ST type;};
  template<>
  struct SelectGoooDevContext<IUberLoadDevice>{typedef GP_BotContext_LT type;};
  template<class IUberGoooDevice>
  bool Gooo(IUberGoooDevice&Dev,TRawPtr&raw_ptr)
  {
    typedef std::remove_reference<decltype(Dev)>::type IConcreteDevice;
    typedef SelectGoooDevContext<IConcreteDevice>::type TContext;
    typedef TContext::GP_BotA::SelfClass GP_BotA;
    typedef TContext::GP_BotB::SelfClass GP_BotB;
    typedef TContext::GP_BotC::SelfClass GP_BotC;
    typedef TContext::GP_BotD::SelfClass GP_BotD;
    //GP
    typedef SpaceScopeBot ScopeBot;
    auto&machine=*this;
    ptrs.Root=raw_ptr;
    //GP
    TContext context(machine,raw_ptr);
    //GP
    {
      GP_BotA gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.MetaSpec);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotB gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.FullDeclEnv);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotC gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.RootType);
    }  
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotD gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.Root);
    }
    return context.result;
  }
  bool Save(IUberSaveDevice&Dev,TRawPtr&raw_ptr)
  {
    //return Gooo(Dev,raw_ptr);
    typedef std::remove_reference<decltype(Dev)>::type IConcreteDevice;
    typedef SelectGoooDevContext<IConcreteDevice>::type TContext;
    typedef TContext::GP_BotA::SelfClass GP_BotA;
    typedef TContext::GP_BotB::SelfClass GP_BotB;
    typedef TContext::GP_BotC::SelfClass GP_BotC;
    typedef TContext::GP_BotD::SelfClass GP_BotD;
    //GP
    typedef SpaceScopeBot ScopeBot;
    auto&machine=*this;
    ptrs.Root=raw_ptr;
    //GP
    TContext context(machine,raw_ptr);
    //GP
    {
      GP_BotA gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.MetaSpec);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotB gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.FullDeclEnv);
    }
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotC gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.RootType);
    }  
    //GP
    if(!context.result)return false;
    //GP
    {
      GP_BotD gpbot(context);
      ScopeBot temp(machine,gpbot.get_space());
      ScopeBot::Go(machine,Dev,ptrs.Root);
    }
    return context.result;
  }
  bool Load(IUberLoadDevice&Dev,TRawPtr&raw_ptr)
  {
    return Gooo(Dev,raw_ptr);
  }
  bool Load_Old(IUberLoadDevice&Dev,TRawPtr&raw_ptr)
  {
    QapDebugMsg("no work.");return false;
    //ptrs.Root=raw_ptr;
    //auto&machine=*this;
    //
    //Dev.DoLoad(machine,ptrs.SpaceSize);
    //
    //Dev.DoLoad(machine,ptrs.MetaSpec);
    //
    //bool Result=false;
    //
    //Result=qbo.MetaSpec.ApplyTo(Tools);
    //
    //if(!Result){return false;}
    //{
    //  SpaceAdv.resize(qbo.SpaceSize);
    //  qbo.MetaSpec.InitSpaceAdv(SpaceAdv,Space);
    //
    //  std::swap(SpaceAdv,Space);
    //  Dev.DoLoad(machine,ptrs.DeclEnv);
    //  std::swap(SpaceAdv,Space);
    //
    //  DeclareEnvRTTI pff;
    //  pff.GrabFrom(Tools);
    //  Clean(Tools.DeclEnv.Arr);
    //  std::swap(pff.Arr,Tools.DeclEnv.Arr);
    //  Result=qbo.DeclEnv.ApplyTo(Tools,SpaceAdv);
    //  pff.RetAll(Tools);
    //  qbo.MetaSpec.FreeSpaceAdv(machine.SpaceAdv);
    //  SpaceAdv.clear();
    //  if(!Result)
    //  {
    //    Space.clear();
    //    return false;
    //  }
    //}
    //int limit=1+qbo.MetaSpec.Arr.size()+qbo.DeclEnv.Arr.size();
    //for(int i=0;i<Space.size();i++)
    //{
    //  auto&item=Space[i];
    //  item.count=i<limit?1:0;
    //}
    //Space.Repack();
    //Space.resize(qbo.SpaceSize);
    //Dev.DoLoad(machine,ptrs.RootType);
    //if(Result)Result=qbo.RootType.get()==raw_ptr.pType;
    //if(Result)
    //{
    //  Result=Dev.DoLoad(machine,ptrs.Root);
    //}
    //Space.clear();
    //return Result;
  }
  bool FullLoad(IUberLoadDevice&Dev,TRawPtr&raw_ptr)
  {
    return Dev.Load(*this,raw_ptr);
  }
  void FullSave(IUberSaveDevice&Dev,TRawPtr&raw_ptr)
  {
    //Setup(raw_ptr);
    return Dev.Save(*this,raw_ptr);
  }
};