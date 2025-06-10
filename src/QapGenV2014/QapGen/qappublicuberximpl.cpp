//-------------------------------------------//
#include "StdAfx.h"
//-------------------------------------------//
#include "MetaTypeGraber.inl"
#include "BinarySaver.inl"
#include "NewBinarySaver.inl"
#include "ProtoSaver.inl"
#include "Tools_yEd.inl"
#include "QapUberSaver.inl"
//-------------------------------------------//
//#include "QapMicro/QapHumus.inl"
//-------------------------------------------//

bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out)
{
  TQapMemoryStream Stream;
  bool ok=QapUberFullSaver(Env,std::move(Object),UberSaveDeviceBin(Stream));
  Out=Stream.IO.IO.mem;
  return ok;
}

bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp)
{
  TQapMemoryStream Stream;
  Stream.IO.IO.mem=Inp;
  bool ok=QapUberFullLoader(Env,std::move(Object),UberLoadDeviceBin(Stream));
  return ok;
}

bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source)
{
  string mem;
  {bool ok=QapPublicUberFullSaverBinMem(Env,std::move(Source),mem);
  QapAssert(ok);if(!ok)return ok;}
  {bool ok=QapPublicUberFullLoaderBinMem(Env,std::move(Dest),mem);
  QapAssert(ok);if(!ok)return ok;}
  return true;
}

bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullSaver(Env,std::move(Object),UberSaveDeviceBin(TQapFileStream(filename,false)));
}

bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullLoader(Env,std::move(Object),UberLoadDeviceBin(TQapFileStream(filename,true)));
}

bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename)
{
  return QapUberFullSaver(Env,std::move(Object),UberSaveDeviceProto(TQapFileStream(filename,false)));
}

string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object)
{
  TQapMemoryStream stream;
  QapUberFullSaver(Env,std::move(Object),UberSaveDeviceProto(stream));
  return stream.IO.IO.mem;
}