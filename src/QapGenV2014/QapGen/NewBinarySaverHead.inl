struct IQapStream{
  virtual bool Load(){return false;}
  virtual bool Save(){return false;}
  virtual QapIO&GetContent()=0;
};

struct TQapFileStream:public IQapStream{
  TDataIO IO;
  string fn;
  bool readonly;
  TQapFileStream(const string&fn,bool readonly=true):fn(fn),readonly(readonly){}
  bool Load(){
    return IO.IO.LoadFile(fn);
  }
  bool Save(){
    if(readonly)
    {
      QapDebugMsg("yes?");
      return false;
    }
    return IO.IO.SaveFile(fn);
  }
  QapIO&GetContent(){return IO;};
};

struct TQapMemoryStream:public IQapStream{
  TDataIO IO;
  TQapMemoryStream(){}
  bool Load(){
    return true;
  }
  bool Save(){
    return true;
  }
  QapIO&GetContent(){return IO;};
};

struct TDataIOStream:public IQapStream{
  TDataIO&IO;
  TDataIOStream(TDataIO&IO):IO(IO){}
  bool Load(){return true;}
  bool Save(){return true;}
  QapIO&GetContent(){return IO;};
};

struct IQapRawObject{
  virtual TRawPtr&Get(IEnvRTTI&Env)=0;
};

struct TQapRawObject:public IQapRawObject{
  TRawPtr raw_ptr;
  TQapRawObject(const TRawPtr&ptr){raw_ptr=ptr;}
  TQapRawObject(TType*pType,void*pValue){raw_ptr.pType=pType;raw_ptr.pValue=pValue;}
  TRawPtr&Get(IEnvRTTI&Env){return raw_ptr;}
};

template<class TYPE>
struct TQapRawUberObject:public IQapRawObject{
  TRawPtr raw_ptr;
  TQapRawUberObject(TYPE&value)
  {
    raw_ptr.pType=nullptr;
    raw_ptr.pValue=&value;
  }
  TRawPtr&Get(IEnvRTTI&Env)
  {
    TType*pType=Sys$$<TYPE>::GetRTTI(Env);
    raw_ptr.pType=pType;
    return raw_ptr;
  }
};
template<class TYPE>
TQapRawUberObject<TYPE> QapRawUberObject(TYPE&value){
  TQapRawUberObject<TYPE> tmp(value);
  return std::move(tmp);
}

//bool QapUberLoad(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  if(!Stream.Load())return false;
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return true;
//}
//
//bool QapUberSave(IEnvRTTI&Env,IQapRawObject&&Object,IQapStream&&Stream)
//{
//  auto&Content=Stream.GetContent();
//  auto&raw_ptr=Object.GetObject(Env);
//  auto&pType=raw_ptr.pType;
//  auto&pValue=raw_ptr.pValue;
//  //begin
//
//  //end
//  return !Content.IO.mem.empty()&&Stream.Save();
//}