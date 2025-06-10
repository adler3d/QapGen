#pragma once
class TSimpleBinarySaver:public IVisitorRTTI{
public:
  typedef TSimpleBinarySaver SelfClass;
public:
  struct t_dev{
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push(){
      stack.push_back(pValue);
    }
    void pop(){
      QapAssert(!stack.empty());
      pValue=stack.back();
      //QapAssert(stack.back()==pValue);
      stack.pop_back();
    }
  };
public:
  t_dev&dev;
  TSimpleBinarySaver(t_dev&dev):dev(dev){}
public:
  template<class TYPE>
  static string toStr(IEnvRTTI&Env,TYPE*p){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return IO.IO.mem;
  }
  static string toStrEx(TType*pType,void*pValue){
    TDataIO IO;
    SelfClass::t_dev dev={IO,pValue};
    SelfClass V(dev);
    pType->Use(V);
    return IO.IO.mem;
  }
  static void toIO(QapIO&IO,TRawPtr&ptr){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType){QapDebugMsg("no way");return;}
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      dev.push();
      dev.pValue=ex.getValue(dev.pValue);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Save(dev.IO,dev.pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    auto Count=VecAPI->GetCount(dev.pValue);
    {
      dev.push();
      dev.pValue=&Count;
      p->SizeType->Use(*this);
      dev.pop();
    }
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(dev.pValue,i);
      dev.push();
      dev.pValue=ptr;
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSelfPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeWeakPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("no way");
  }
};

class TSimpleBinaryLoader:public IVisitorRTTI{
public:
  typedef TSimpleBinaryLoader SelfClass;
public:
  struct t_dev{
    QapIO&IO;
    void*pValue;
    vector<void*> stack;
    void push(){
      stack.push_back(pValue);
    }
    void pop(){
      QapAssert(!stack.empty());
      pValue=stack.back();
      //QapAssert(stack.back()==pValue);
      stack.pop_back();
    }
  };
public:
  t_dev&dev;
  TSimpleBinaryLoader(t_dev&dev):dev(dev){}
public:
  template<class TYPE>
  static bool fromIO(IEnvRTTI&Env,TYPE*p,QapIO&IO){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromIOEx(IEnvRTTI&Env,const TRawPtr&ptr,QapIO&IO){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
  template<class TYPE>
  static bool fromStr(IEnvRTTI&Env,TYPE*p,const string&source){
    auto*pType=Sys$$<TYPE>::GetRTTI(Env);
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,p};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromStrEx(const string&source,TType*pType,void*pValue){
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,pValue};
    SelfClass V(dev);
    pType->Use(V);
    return true;
  }
  static bool fromStrEx(const string&source,TRawPtr&ptr){
    TDataIO IO;
    IO.IO.mem=source;
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
  static bool fromStrEx(QapIO&IO,TRawPtr&ptr){
    SelfClass::t_dev dev={IO,ptr.pValue};
    SelfClass V(dev);
    ptr.pType->Use(V);
    return true;
  }
public:
  void Do(TTypeStruct*p)
  {
    if(p->SubType){QapDebugMsg("no way");return;}
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      dev.push();
      dev.pValue=ex.getValue(dev.pValue);
      ex.Type->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeSys*p)
  {
    p->BinIO->Load(dev.IO,dev.pValue);
  }
  void Do(TTypeVector*p)
  {
    auto*VecAPI=p->VecAPI.get();
    int Count=0;
    {
      dev.push();
      dev.pValue=&Count;
      p->SizeType->Use(*this);
      dev.pop();
    }
    VecAPI->SetCount(dev.pValue,Count);
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(dev.pValue,i);
      dev.push();
      dev.pValue=ptr;
      elemType->Use(*this);
      dev.pop();
    }
  }
  void Do(TTypeArray*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeSelfPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeAutoPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeWeakPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeHardPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeVoidPtr*p)
  {
    QapDebugMsg("no way");
  }
  void Do(TTypeFieldPtr*p)
  {
    QapDebugMsg("no way");
  }
};

template<class TYPE>
static bool qap_simple_clone(IEnvRTTI&Env,TYPE&dest,TYPE&source)
{
  string mem=TSimpleBinarySaver::toStr(Env,&source);
  return TSimpleBinaryLoader::fromStr(Env,&dest,mem);
}

static bool qap_simple_clone_unsafe(TType*pType,void*pDest,void*pSource)
{
  string mem=TSimpleBinarySaver::toStrEx(pType,pSource);
  return TSimpleBinaryLoader::fromStrEx(mem,pType,pDest);
}