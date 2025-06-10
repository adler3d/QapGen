class GP_BotA_ST;
class GP_BotB_ST;
class GP_BotC_ST;
class GP_BotD_ST;

class GP_BotA_LT;
class GP_BotB_LT;
class GP_BotC_LT;
class GP_BotD_LT;

typedef TConservationMachine SelfClass;
typedef SelfClass::TRawPtr TRawPtr;
typedef SelfClass::TSyncPointsHolder TSyncPointsHolder;
typedef SelfClass::TUserPointsHolder TUserPointsHolder;
typedef SelfClass::TPointsHolder TPointsHolder;
typedef TServerPtrSpace TSpace;

class GP_BotContext_ST{
public:
  typedef GP_BotContext_ST SelfClass;
  typedef GP_BotA_ST GP_BotA;
  typedef GP_BotB_ST GP_BotB;
  typedef GP_BotC_ST GP_BotC;
  typedef GP_BotD_ST GP_BotD;
public:
  TConservationMachine&machine;
  TRawPtr&raw_ptr;
public:
  TSpace SpaceForMetaSpec;
  TSpace SpaceForFullDeclEnv;
  TSpace SpaceForRoot;
public:
  GP_BotContext_ST(TConservationMachine&machine,TRawPtr&raw_ptr):machine(machine),raw_ptr(raw_ptr){Init();}
  ~GP_BotContext_ST(){Free();}
public:
  bool result;
  TUserPointsHolder UserPoints;
public:
  void Init()
  {
    result=true;
  }
public:
  void Free()
  {
    auto&qbo=machine.qbo;
    SpaceForMetaSpec.hack_clear();
    {
      auto&arr=qbo.FullDeclEnv.ImplPtrs;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&item=SpaceForFullDeclEnv[ex.Impl.Self];
        SpaceForFullDeclEnv.Del(item,true);
      }
    }
    auto&Space=machine.Space;
    Space.clear();
    SpaceForFullDeclEnv.Arr.clear();
    SpaceForRoot.Arr.clear();
  }
};

class GP_Bot{
public:
  static void copy_envitem_lnk_to_envitem_id(TSpace&Dest,TSpace&Source,TSpace&LnkSource)
  {
    QapAssert(Dest.size()<=Source.size());
    auto&out_space=Dest;
    out_space.resize(Source.size());
    auto&arr=Source.Arr;
    for(int i=1;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&item=ex.get_lnk(LnkSource);
      QapAssert(out_space.IsAllowed(item.id));
      out_space[item.id].copy(item);
    }
  }
};

class GP_BotA_ST{
public:
  typedef GP_BotA_ST SelfClass;
  typedef GP_BotContext_ST TContext;
public:
  TContext&Context;
public:
  GP_BotA_ST(TContext&Context):Context(Context){Init();}
 ~GP_BotA_ST(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForMetaSpec;}
public:
  void Init()
  {
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //ST
    auto&UserPoints=this->Context.UserPoints;
    auto&DS=this->Context.machine.DS;
    auto&ptrs=this->Context.machine.ptrs;
    auto&qbo=this->Context.machine.qbo;
    auto&raw_ptr=this->Context.raw_ptr;
    auto&Tools=this->Context.machine.Tools;
    //ST
    {
      Check_EachItemsOfTheSpaceIsNoPassed(Space);
      Space.AddPointsFrom(raw_ptr);//user object passed 
      UserPoints.take(Space);
      DS.pass(Space,raw_ptr);
      DS.SolveDepends(Space);
      QapAssert(Space.CheckHidden());
    }
    //ST
    {
      InitMetaSpec(qbo.MetaSpec,Tools.DeclareTypeArray,Space,SpaceForMetaSpec);
      SpaceForMetaSpec.UpdatePointsTypeFrom(ptrs.MetaSpec);
    }
    //ST
    SyncTwoSpace_Stage1(qbo.MetaSpec,Space,SpaceForMetaSpec);
  }
  void Free()
  {
    //nothing
  }
};

class GP_BotB_ST:public GP_Bot{
public:
  typedef GP_BotB_ST SelfClass;
  typedef GP_BotContext_ST TContext;
public:
  TContext&Context;
public:
  GP_BotB_ST(TContext&Context):Context(Context){Init();}
 ~GP_BotB_ST(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForFullDeclEnv;}
public:
  void Init()
  {
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //ST
    auto&qbo=this->Context.machine.qbo;
    auto&Tools=this->Context.machine.Tools;
    auto&ptrs=this->Context.machine.ptrs;
    //ST
    qbo.FullDeclEnv.DeclEnv.GrabFrom(Tools.DeclEnv,Tools.Space,Tools.get_tdmt());
    qbo.FullDeclEnv.MakeImplPtrs();
    //ST
    copy_envitem_lnk_to_envitem_id(SpaceForFullDeclEnv,SpaceForMetaSpec,Space);
    Init_part2(Space,qbo.FullDeclEnv,SpaceForFullDeclEnv);
    //ST
    //qbo.FullDeclEnv.AddDeclToSpace(Space,SpaceForFullDeclEnv);
    qbo.FullDeclEnv.AddImplToSpace(Space,SpaceForFullDeclEnv);
    //ST
    string list[]={
      Space.GetListOfNoPassed(true),
      SpaceForMetaSpec.GetListOfNoPassed(true),
      SpaceForFullDeclEnv.GetListOfNoPassed(true),
      SpaceForRoot.GetListOfNoPassed(true),
    };
    SpaceForFullDeclEnv.UpdatePointsTypeFrom(ptrs.FullDeclEnv);
  }
  static void Init_part2(TSpace&Space,FullDeclareEnvRTTI&FullDeclEnv,TSpace&SpaceForFullDeclEnv)
  {
    TSyncPointsHolder buff;
    auto&arr=FullDeclEnv.ImplPtrs;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&decl=Space[ex.Decl->Self];
      buff.Arr.push_back(std::move(EnvItem().copy(decl)));
    }
    auto&out_space=SpaceForFullDeclEnv;
    buff.insert_and_sync(Space,out_space);
  }
  void Free()
  {
    //nothing
  }
};

class GP_BotC_ST:public GP_Bot{
public:
  typedef GP_BotC_ST SelfClass;
  typedef GP_BotContext_ST TContext;
public:
  TContext&Context;
public:
  GP_BotC_ST(TContext&Context):Context(Context){Init();}
 ~GP_BotC_ST(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForRoot;}
public:
  void Init()
  {    
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //ST
    auto&qbo=this->Context.machine.qbo;
    auto&UserPoints=this->Context.UserPoints;
    auto&raw_ptr=this->Context.raw_ptr;
    //ST
    Init_part1(Space,SpaceForMetaSpec,SpaceForRoot);
    Init_part2(Space,qbo.FullDeclEnv,SpaceForFullDeclEnv,SpaceForRoot);
    qbo.RootType=raw_ptr.pType;
  }
  static void Init_part1(TSpace&Space,TSpace&SpaceFMS,TSpace&SpaceForIt)
  {
    copy_envitem_lnk_to_envitem_id(SpaceForIt,SpaceFMS,Space);
  }
  static void Init_part2(TSpace&Space,FullDeclareEnvRTTI&FullDeclEnv,TSpace&SpaceFFDE,TSpace&SpaceForIt)
  {
    TSyncPointsHolder buff;
    SpaceForIt.reserve(SpaceForIt.size()+SpaceFFDE.size()*2);
    auto&out_space=SpaceForIt;
    auto&arr=FullDeclEnv.ImplPtrs;
    buff.Arr.reserve(2*arr.size());
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&decl=SpaceFFDE[ex.Decl->Self];
      buff.Arr.push_back(std::move(EnvItem().copy(decl)));
    }
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&impl=SpaceFFDE[ex.Impl.Self].get_lnk(Space);
      buff.Arr.push_back(std::move(EnvItem().copy(impl)));
    }
    buff.insert_and_sync(Space,SpaceForIt);
    QapAssert(SpaceForIt.IsValid());
  }
  void Free()
  {
    //nothing
  }
};

class GP_BotD_ST:public GP_Bot{
public:
  typedef GP_BotD_ST SelfClass;
  typedef GP_BotContext_ST TContext;
public:
  TContext&Context;
public:
  GP_BotD_ST(TContext&Context):Context(Context){Init();}
 ~GP_BotD_ST(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForRoot;}
public:
  void Init()
  {
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //ST
    auto&UserPoints=this->Context.UserPoints;
    //ST
    Init_part3(Space,UserPoints,SpaceForRoot);
  }
  void Free()
  {
    //nothing
  }
  static void Init_part3(TSpace&Space,TUserPointsHolder&Up,TSpace&SpaceForIt)
  {
    TSyncPointsHolder buff;
    std::swap(buff.Arr,Up.Arr);
    buff.insert_and_sync(Space,SpaceForIt);
    std::swap(buff.Arr,Up.Arr);
  }
};

//=====
//===============
//=====

class GP_BotContext_LT{
public:
  typedef GP_BotContext_LT SelfClass;
  typedef GP_BotA_LT GP_BotA;
  typedef GP_BotB_LT GP_BotB;
  typedef GP_BotC_LT GP_BotC;
  typedef GP_BotD_LT GP_BotD;
public:
  TConservationMachine&machine;
  TRawPtr&raw_ptr;
public:
  TSpace SpaceForMetaSpec;
  TSpace SpaceForFullDeclEnv;
  TSpace SpaceForRoot;
public:
  GP_BotContext_LT(TConservationMachine&machine,TRawPtr&raw_ptr):machine(machine),raw_ptr(raw_ptr){Init();}
  ~GP_BotContext_LT(){Free();}
public:
  bool result;
  TPointsHolder BuffForRoot;
public:
  void Init()
  {
    result=true;
  }
public:
  void Free()
  {
    auto&qbo=machine.qbo;
    SpaceForMetaSpec.hack_clear();
    {
      auto&arr=qbo.FullDeclEnv.ImplPtrs;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&decl=SpaceForFullDeclEnv[ex.Decl->Self];
        auto&impl=SpaceForFullDeclEnv[ex.Impl.Self];
        SpaceForFullDeclEnv.Del(decl,true);
        SpaceForFullDeclEnv.Del(impl,true);
      }
    }
    auto&Space=this->machine.Space;
    Space.clear();
    SpaceForFullDeclEnv.Arr.clear();
    BuffForRoot.off_all_envitems(SpaceForRoot);
    SpaceForRoot.clear();
  }
};

class GP_BotA_LT{
public:
  typedef GP_BotA_LT SelfClass;
  typedef GP_BotContext_LT TContext;
public:
  TContext&Context;
public:
  GP_BotA_LT(TContext&Context):Context(Context){Init();}
 ~GP_BotA_LT(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForMetaSpec;}
public:
  void Init()
  {
    //nothing
  }
  void Free()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    auto&qbo=this->Context.machine.qbo;
    auto&Tools=this->Context.machine.Tools;
    //LT
    result=LinkMetaSpec(qbo.MetaSpec,Tools.DeclareTypeArray,Space,SpaceForMetaSpec);
    if(!result)return;
    SyncTwoSpace_Stage1(qbo.MetaSpec,Space,SpaceForMetaSpec);
  }
  static bool LinkMetaSpec(TQapBinaryObject::TMetaSpec&input,TSpaceDependsTools::TDeclareTypeArray&arr,TSpace&Space,TSpace&SpaceForMetaSpec)
  {
    auto pass=[&Space,&SpaceForMetaSpec](TType*pType,const EnvDefTypeStr&def)->bool
    {
      auto&key=def.Decl.Name;
      if(key!=pType->GetFullName())return false;
      auto&impl_BLT=Space[pType->Self];
      auto&decl_BLT=impl_BLT.get_lnk(Space);
      auto&impl_LT=SpaceForMetaSpec[def.Impl.Self];
      auto&decl_LT=SpaceForMetaSpec[def.Decl.Decl.Self];
      impl_LT.ptr_lnk=impl_BLT.ptr;
      decl_LT.ptr_lnk=decl_BLT.ptr;
      impl_LT.name="Sys$$<"+key+">::GetRTTI()";
      decl_LT.name="Def$$<"+key+">::GetRTTI()";
      return true;
    };
    auto link_keyword=[&pass,&arr](const EnvDefTypeStr&def)->bool
    {
      auto&key=def.Decl.Name;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        if(pass(ex.first,def))return true;
        if(pass(ex.second,def))return true;
      }
      return false;
    };
    for(int j=0;j<input.size();j++)
    {
      auto&ex=input[j];
      auto&key=ex.Decl.Name;
      if(!link_keyword(ex))
      {
        CppString cpp;
        cpp=key;
        QapDebugMsg("\""+cpp.data+"\" - keyword not found");
        return false;
      }
    }
    return true;
  }
};

class GP_BotB_LT:public GP_Bot{
public:
  typedef GP_BotB_LT SelfClass;
  typedef GP_BotContext_LT TContext;
public:
  TContext&Context;
public:
  GP_BotB_LT(TContext&Context):Context(Context){Init();}
 ~GP_BotB_LT(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForFullDeclEnv;}
public:
  typedef TClientPtrSolver::TwoMetaType TwoMetaType;
public:
  void Init()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    copy_envitem_lnk_to_envitem_id(SpaceForFullDeclEnv,SpaceForMetaSpec,Space);
  }
  void Free()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    auto&qbo=this->Context.machine.qbo;
    auto&Tools=this->Context.machine.Tools;
    //LT
    if(true)
    {
      //LT
      TSpace SpaceLinked;
      TPointsHolder buff_FMS;
      //` {
      //`   SpaceMetaSpec->get_lnk(Space),
      //`   SpaceForForFullDeclEnv->get_lnk(Space),
      //`   SpaceForForFullDeclEnv
      //` }
      copy_envitem_lnk_to_envitem_id(SpaceLinked,SpaceForMetaSpec,Space); 
      {for(int i=1;i<SpaceLinked.size();i++)SpaceLinked[i].ptr_lnk=SpaceLinked[i].ptr;}
      {for(int i=1;i<SpaceForMetaSpec.size();i++)buff_FMS.Arr.push_back(std::move(EnvItem().copy(SpaceForMetaSpec[i])));}
      //LT
      TPointsHolder buff_BLT;
      TPointsHolder buff_LT;
      //LT
      result=LinkFullDeclEnv(qbo.FullDeclEnv,Tools,SpaceForFullDeclEnv);
      if(!result)
      {
        buff_FMS.off_all_envitems(SpaceLinked,true);
        SpaceLinked.clear();
        return;
      }
      //LT
      grab_from_implptrs_envitem_lnk_to_buff(qbo.FullDeclEnv.ImplPtrs,buff_BLT,Space,SpaceForFullDeclEnv);
      grab_from_implptrs_envitem_to_buff(qbo.FullDeclEnv.ImplPtrs,buff_LT,Space,SpaceForFullDeclEnv);
      //LT
      buff_BLT.off(Space);
      buff_LT.off(SpaceForFullDeclEnv);
      //LT
      buff_LT.insert_to_end(SpaceLinked);
      buff_BLT.insert_to_end(SpaceLinked);
      //LT
      make_linked(buff_LT,SpaceLinked);
      result=Testing(qbo.FullDeclEnv,TwoMetaType(Tools),SpaceLinked);
      //LT
      buff_FMS.off_all_envitems(SpaceLinked,true);
      SpaceLinked.clear();
      //LT
      buff_LT.on(SpaceForFullDeclEnv);
      buff_BLT.on(Space);
      //LT
      if(!result)
      {
        //SpaceForFullDeclEnv.
        return;
      }
      //LT
      TSyncPointsHolder buff_sync;
      buff_sync.copy_envitem_lnk_and_keep_id(buff_LT,Space);
      buff_sync.sync(Space);
      //LT
    }
    //LT
  }
  static void make_linked(TPointsHolder&buff,TSpace&Space)
  {
    auto&arr=buff.Arr;
    for(int i=0;i<arr.size();i++)
    {
      auto&item=arr[i];
      auto&jtem=item.get_lnk(Space);
      item.ptr_lnk.set_zero();
      jtem.ptr_lnk.set_zero();
      Space.make_linked(item,jtem);
    }
  }
  typedef FullDeclareEnvRTTI::TImplPtrs TImplPtrs;
  static void grab_from_implptrs_envitem_lnk_to_buff(TImplPtrs&ImplPtrs,TPointsHolder&buff,TSpace&Space,TSpace&SpaceFFDE)
  {
    auto&arr=ImplPtrs;
    buff.Arr.reserve(arr.size()*2);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&decl_LT=SpaceFFDE[ex.Decl->Self];
      auto&impl_LT=SpaceFFDE[ex.Impl.Self];
      auto&decl_BLT=decl_LT.get_lnk(Space);
      auto&impl_BLT=impl_LT.get_lnk(Space);
      buff.Arr.push_back(std::move(EnvItem().copy(decl_BLT)));
      buff.Arr.push_back(std::move(EnvItem().copy(impl_BLT)));
    }
  }
  typedef FullDeclareEnvRTTI::TImplPtrs TImplPtrs;
  static void grab_from_implptrs_envitem_to_buff(TImplPtrs&ImplPtrs,TPointsHolder&buff,TSpace&Space,TSpace&SpaceFFDE)
  {
    auto&arr=ImplPtrs;
    buff.Arr.reserve(arr.size()*2);
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto&decl_LT=SpaceFFDE[ex.Decl->Self];
      auto&impl_LT=SpaceFFDE[ex.Impl.Self];
      buff.Arr.push_back(std::move(EnvItem().copy(decl_LT)));
      buff.Arr.push_back(std::move(EnvItem().copy(impl_LT)));
    }
  }
  static bool Testing(FullDeclareEnvRTTI&input,TClientPtrSolver::TwoMetaType&tmt,TSpace&SpaceLinked)
  {
    DeclareDetail::IsEqualTo<TServerPtrSpace> V(SpaceLinked);
    auto get_ptr_as_DeclareType=[&tmt](EnvItem&item)->DeclareType*
    {
      bool flag=item.ptr.type->IsBasedOn(tmt.pDeclareType);
      if(flag)return (DeclareType*)item.ptr.get();
      QapDebugMsg(item.name+" - WTF?");
      return nullptr;
    };
    auto&arr=input.ImplPtrs;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pValue=ex.Decl.get();
      V.Result=false;
      V.pValue=pValue;
      auto&item=SpaceLinked[pValue->Self];
      if(item.ptr_lnk.IsValid())
      {
        auto&jtem=item.get_lnk(SpaceLinked);
        auto*p=get_ptr_as_DeclareType(jtem);
        item.ptr_lnk.set_zero();
        jtem.ptr_lnk.set_zero();
        V.Result=false;
        p->Use(V);
        if(V.Result)
        {
          bool f0=item.ptr_lnk.get()==jtem.ptr.get();
          bool f1=jtem.ptr_lnk.get()==item.ptr.get();
          QapAssert(f0&&f1);
        }
      }else{
        QapDebugMsg("WTF?");
      }
      if(!V.Result)
      {
        QapDebugMsg("bad type : \""+pValue->GetFullName()+"\"");
        break;
      }
    }
    return V.Result;
  }
  static bool LinkFullDeclEnv(FullDeclareEnvRTTI&input,TSpaceDependsTools&Tools,TSpace&SpaceForFullDeclEnv)
  {
    auto&Space=Tools.Space;
    auto&output=Tools.DeclEnv.Arr;
    QapClock clock;
    clock.Start();
    vector<string> out;
    for(int i=0;i<output.size();i++)
    {
      auto&ex=output[i];
      qap_add_back(out)=ex.get()->GetFullName();
    }
    clock.Stop();
    auto init_ms=clock.MS();
    clock.Start();
    vector<int> inp2out;
    vector<int> fails;
    //solve links
    {
      QapStrFinderFast f;
      std::swap(f.keywords,out);
      f.rebuild();
      auto&arr=input.ImplPtrs;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto fn=ex.Decl->GetFullName();
        auto res=f.find(fn);
        if(!res.ok){qap_add_back(fails)=i;continue;}
        qap_add_back(inp2out)=res.kw_id;
        //auto ra=qap_find_str(out,fn);
        //if(ra.empty()){qap_add_back(fails);continue;}
        //QapAssert(ra.size()==1);
        //qap_add_back(inp2out)=ra[0];
      }
      std::swap(f.keywords,out);
    }
    clock.Stop();
    real solve_ms=clock.MS();
    clock.Start();
    if(!fails.empty())
    {
      vector<string> err_list;
      for(int i=0;i<fails.size();i++){
        qap_add_back(err_list)=input.ImplPtrs[fails[i]].Decl->GetFullName();
      }
      QapDebugMsg(
        "loader could not find a native implementation for the types listed below:\n"+
        join(err_list,"\n")
      );
      return false;
    }
    auto link=[&Space,&SpaceForFullDeclEnv](DeclareType*pdType,const EnvDefTypePtr&def)->bool
    {
      auto fullname=def.Decl->GetFullName();
      auto&decl_BLT=Space[pdType->Self];
      auto&impl_BLT=decl_BLT.get_lnk(Space);
      auto&decl_LT=SpaceForFullDeclEnv[def.Decl->Self];
      auto&impl_LT=SpaceForFullDeclEnv[def.Impl.Self];
      impl_LT.ptr_lnk=impl_BLT.ptr;
      decl_LT.ptr_lnk=decl_BLT.ptr;
      impl_LT.name="Sys$$<"+fullname+">::GetRTTI()";
      decl_LT.name="Def$$<"+fullname+">::GetRTTI()";
      return true;
    };
    auto&arr=input.ImplPtrs;
    for(int i=0;i<inp2out.size();i++)
    {
      auto&def=input.ImplPtrs[i];
      auto*pdType=output[inp2out[i]].get();
      if(!link(pdType,def))
      {
        auto fn=def.Decl->GetFullName();
        CppString cpp;
        cpp=fn;
        QapDebugMsg("\""+cpp.data+"\" - type not found");
        return false;
      }
    }
    clock.Stop();
    static bool need_print=false;
    if(need_print)
    {
      file_put_contents("LinkFullDeclEnv_ms.txt",
        "init : "+FToS(init_ms)+"\n"
        "solve : "+FToS(solve_ms)+"\n"
        "link : "+FToS(clock.MS())+"\n"
      );
      qap_add_back(out)="//";
      for(int j=0;j<arr.size();j++)
      {
        auto&ex=arr[j];
        qap_add_back(out)=ex.Decl->GetFullName();
      }
      file_put_contents("LinkFullDeclEnv_full_list.txt",join(out,"\n"));
    }
    return true;
  }
};

class GP_BotC_LT:public GP_Bot{
public:
  typedef GP_BotC_LT SelfClass;
  typedef GP_BotContext_LT TContext;
public:
  TContext&Context;
public:
  GP_BotC_LT(TContext&Context):Context(Context){Init();}
 ~GP_BotC_LT(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForRoot;}
public:
  void Init()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    auto&qbo=this->Context.machine.qbo;
    //LT
    copy_envitem_lnk_to_envitem_id(SpaceForRoot,SpaceForMetaSpec,Space);
    TPointsHolder PH;
    GP_BotB_LT::grab_from_implptrs_envitem_to_buff(qbo.FullDeclEnv.ImplPtrs,PH,Space,SpaceForFullDeclEnv);
    TSyncPointsHolder buff_sync;
    buff_sync.copy_envitem_lnk(PH,Space);
    buff_sync.off(Space);
    SpaceForRoot.resize(SpaceForFullDeclEnv.size());
    buff_sync.on(SpaceForRoot);
    buff_sync.off_all_objects(SpaceForRoot);
    buff_sync.on(Space);
    //buff_sync.on
  }
  void Free()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    auto&qbo=this->Context.machine.qbo;
    auto&raw_ptr=this->Context.raw_ptr;
    //LT
    result=bool(qbo.RootType.get()==raw_ptr.pType);
  }
};

class GP_BotD_LT:public GP_Bot{
public:
  typedef GP_BotD_LT SelfClass;
  typedef GP_BotContext_LT TContext;
public:
  TContext&Context;
public:
  GP_BotD_LT(TContext&Context):Context(Context){Init();}
 ~GP_BotD_LT(){Free();}
public:
 TSpace&get_space(){return Context.SpaceForRoot;}
public:
  void Init()
  {
    auto&result=this->Context.result;
    auto&Space=this->Context.machine.Space;
    auto&SpaceForMetaSpec=this->Context.SpaceForMetaSpec;
    auto&SpaceForFullDeclEnv=this->Context.SpaceForFullDeclEnv;
    auto&SpaceForRoot=this->Context.SpaceForRoot;
    //LT
    auto&BuffForRoot=this->Context.BuffForRoot;
    //LT
    for(int i=1;i<SpaceForRoot.size();i++)
    {
      BuffForRoot.Arr.push_back(std::move(EnvItem().copy(SpaceForRoot[i])));
    }
  }
  void Free()
  {
    //nothing
  }
};