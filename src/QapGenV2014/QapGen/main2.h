#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : adler3d@gmail.com    |>}   //
//   {<| site   : adler3d.narod.ru     |>}   //
//-------------------------------------------//

extern bool QapPublicUberFullSaverBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullLoaderBin(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern bool QapPublicUberFullSaverProto(IEnvRTTI&Env,IQapRawObject&&Object,const string&filename);
extern string QapPublicUberFullSaverProtoToStr(IEnvRTTI&Env,IQapRawObject&&Object);

extern bool QapPublicUberFullSaverBinMem(IEnvRTTI&Env,IQapRawObject&&Object,string&Out);
extern bool QapPublicUberFullLoaderBinMem(IEnvRTTI&Env,IQapRawObject&&Object,const string&Inp);
extern bool QapPublicUberFullCloneBinMem(IEnvRTTI&Env,IQapRawObject&&Dest,IQapRawObject&&Source);

inline int&get_QapClone_counter(){static int counter=0;return counter;}
inline real&QapClone_timer(){static real time=0;return time;}

template<class TYPE>
inline bool QapClone(IEnvRTTI&Env,TYPE&dest,TYPE&source){
  static auto&counter=get_QapClone_counter();counter++;
  QapClock clock;
  clock.Start();
  bool ok=QapPublicUberFullCloneBinMem(Env,QapRawUberObject(dest),QapRawUberObject(source));
  clock.Stop();
  QapClone_timer()+=clock.MS();
  return ok;
}

struct ICompileUnit;

struct ICompileUnitMan
{
  virtual void add(ICompileUnit*pUnit)=0;
  static ICompileUnitMan&get_man();
};

struct ICompileUnit{
  virtual const char*get_filename()const=0;
  virtual void RegAll(IEnvRTTI&Env)=0;
  virtual void Run(IEnvRTTI&Env)=0;
  ICompileUnit(){ICompileUnitMan::get_man().add(this);}
};

static string cur_date_str()
{
  time_t rawtime;
  tm*ptm;
  time(&rawtime);
  ptm=gmtime(&rawtime);
  char buff[128];
  sprintf(&buff[0],"%04u.%02u.%02u %02u:%02u:%02u\0",
    1900+ptm->tm_year,
    ptm->tm_mon+1,
    ptm->tm_mday,
    ptm->tm_hour,ptm->tm_min,ptm->tm_sec
  );
  return buff;
}

//-------------------------------------------//
//   {<|          03.06.2014           |>}   //
//-------------------------------------------//