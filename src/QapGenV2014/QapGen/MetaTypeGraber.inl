//#include "MetaTypeGraber.nil"
#pragma once
class TMetaTypeVisitor:public IVisitorRTTI{
public:
  class ICallBack:public IVisitorRTTI{
  public:
    virtual void Entry(TType*p)=0;
    virtual void Leave(TType*p)=0;
    virtual operator bool()const{return true;};
  };
  class ScopeCallBack{
  public:
    ICallBack&CB;
    TType*pType;
    template<class TYPE>
    ScopeCallBack(ICallBack&CB,TYPE*pType):CB(CB){CB.Entry(pType);CB.Do(pType);}
   ~ScopeCallBack(){CB.Leave(pType);}
  };
public:
  ICallBack&CB;
  void*pValue;
  typedef TMetaTypeVisitor SelfClass;
  TMetaTypeVisitor(ICallBack&CB,void*pValue):CB(CB),pValue(pValue){}
  TMetaTypeVisitor(TMetaTypeVisitor&owner,void*pValue):CB(owner.CB),pValue(pValue){}
public:
  void Do(TTypeStruct*p)
  {
    ScopeCallBack SCB(CB,p);if(!CB)return;
    if(p->SubType)
    {
      SelfClass next(*this,pValue);
      p->SubType->Use(next);
    }
    auto&arr=p->Members;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      SelfClass next(*this,(void*)(ex.Offset+int(pValue)));
      ex.Type->Use(next);
    }
  }
  void Do(TTypeSys*p)
  {
    ScopeCallBack SCB(CB,p);//if(!CB)return;
    //`p->BinIO->Save(io,pValue);
  }
  void Do(TTypeVector*p)
  {
    ScopeCallBack SCB(CB,p);if(!CB)return;
    auto*VecAPI=p->VecAPI.get();
    int Count=VecAPI->GetCount(pValue);
    TType*elemType=p->ElementType.get();
    for(int i=0;i<Count;i++){
      void*ptr=VecAPI->GetItem(pValue,i);
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  void Do(TTypeArray*p)
  {
    ScopeCallBack SCB(CB,p);if(!CB)return;
    int Count=p->Size;
    TType*elemType=p->ElementType.get();
    int elemSize=elemType->Info.Size;
    for(int i=0;i<Count;i++){
      void*ptr=&((uchar*)pValue)[elemSize*i];
      SelfClass next(*this,ptr);
      elemType->Use(next);
    }
  }
  virtual void Do(TTypeSelfPtr*p)
  {
    ScopeCallBack SCB(CB,p);//if(!CB)return;
  }
  virtual void Do(TTypeAutoPtr*p)
  {
    ScopeCallBack SCB(CB,p);if(!CB)return;
    if(!p->ElementType){
      QapAssert(p->ElementType);
      return;
    }
    TAutoPtr<void>&value=*(TAutoPtr<void>*)pValue;
    THardPtr<TType>&type=value.Product.pType;
    {
      SelfClass next(*this,&type);
      p->mType.Type->Use(next);
    }
    auto*ptr=value.get();
    if(ptr&&type)
    {
      SelfClass next(*this,ptr);
      type->Use(next);
    }
  }
  virtual void Do(TTypeWeakPtr*p)
  {
    ScopeCallBack SCB(CB,p);//if(!CB)return;
  }
  virtual void Do(TTypeHardPtr*p)
  {
    ScopeCallBack SCB(CB,p);//if(!CB)return;
  }
  virtual void Do(TTypeVoidPtr*p){
    ScopeCallBack SCB(CB,p);if(!CB)return;
    TVoidPtr&value=*(TVoidPtr*)pValue;
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    //QapDebugMsg("under construction");
  }
  virtual void Do(TTypeFieldPtr*p){
    ScopeCallBack SCB(CB,p);if(!CB)return;
    TFieldPtr&value=*(TFieldPtr*)pValue;
    TType*pmObjectType=p->mObject.Type.get();
    {
      SelfClass next(*this,&value.object);
      pmObjectType->Use(next);
    }
    TType*pmTypeType=p->mType.Type.get();
    {
      SelfClass next(*this,&value.type);
      pmTypeType->Use(next);
    }
    TType*pmIndexType=p->mIndex.Type.get();
    {
      SelfClass next(*this,&value.offset);
      pmIndexType->Use(next);
    }
  }
  virtual void Do(TTypeFactory*p)
  {
    QapDebugMsg("new way");
    ScopeCallBack SCB(CB,p);//if(!CB)return;
    IFactory&value=*(IFactory*)pValue;
    TType*SmartType=p->SmartType.get();
    {
      SelfClass next(*this,&value.Self);
      SmartType->Use(next);
    }
  }
public:
};

class TMetaTypeCounter:public TMetaTypeVisitor::ICallBack{
public:
  typedef TServerPtrSpace TSpace;
public:
  TSpace&Space;
  TMetaTypeCounter(TSpace&Space):Space(Space){}
public:
  void Entry(TType*p){}
  void Leave(TType*p){}
  operator bool()const{return true;};
public:
  void Do(TTypeStruct*p){
    Space[p->Self].count++;
  }
  void Do(TTypeSys*p){
    Space[p->Self].count++;
  }
  void Do(TTypeVector*p){
    Space[p->Self].count++;
  }
  void Do(TTypeArray*p){
    Space[p->Self].count++;
  }
  void Do(TTypeSelfPtr*p){
    Space[p->Self].count++;
  }
  void Do(TTypeAutoPtr*p){
    Space[p->Self].count++;
  }
  void Do(TTypeWeakPtr*p){
    Space[p->Self].count++;
  }
  void Do(TTypeHardPtr*p){
    Space[p->Self].count++;
  }
  void Do(TTypeVoidPtr*p){
    Space[p->Self].count++;
  }
  void Do(TTypeFieldPtr*p){
    Space[p->Self].count++;
  }
};

inline void MetaMarker(TServerPtrSpace&Space,TType*pType,void*Target)
{
  TMetaTypeCounter Counter(Space);
  TMetaTypeVisitor MTC(Counter,Target);
  pType->Use(MTC);
}