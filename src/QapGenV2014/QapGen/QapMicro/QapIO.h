#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#define SAY(MSG)//MACRO_ADD_LOG(MSG,lml_EVENT);
//-------------------------------------------//
class CrutchIO{
public:
  static bool FileExist(const string&FN)
  {
    std::fstream f;
    f.open(FN.c_str(),std::ios::in|std::ios::binary);
    return f.is_open();
  }
private:
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
public:
  int pos;
  string mem;
  CrutchIO():mem(""),pos(0){};
  bool LoadFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    //printf("f->size=%i\n",L);
    //printf("f->Chcount=%i\n",f._Chcount);
    f.close(); pos=0;
    SAY("'"+FN+"' : "+"["+IToS(L)+"]");
    return true;
  };
  bool SaveFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)return false;
    if(!mem.empty())f.write(&mem[0],mem.size());
    f.close(); pos=0; int L=mem.size();
    SAY("'"+FN+"' : "+"["+IToS(L)+"]");
    return true;
  };
  void read(char*c,int count)
  {
    for(int i=0;i<count;i++)c[i]=mem[pos++];//FIXME: тут можно юзать memcpy
  };
  void write(char*c,int count)
  {
    //mem.reserve(max(mem.capacity(),mem.size()+count));
    int n=mem.size();
    mem.resize(n+count);//Hint: resize гарантировано копирует содержимое.
    for(int i=0;i<count;i++)mem[n+i]=c[i];//FIXME: тут можно юзать memcpy
    pos+=count;
  };
};
//-------------------------------------------//
class QapPolyIO;
class QapIO{
public:
  QapIO(){}
public:
  virtual void SavePOD(void*p,int count)=0;
  virtual void LoadPOD(void*p,int count)=0;
  virtual bool TryLoad(int count)=0;
  virtual void Crash()=0;
  virtual bool IsCrashed()=0;
  virtual bool IsSizeIO()=0;
  virtual int GetSize()=0;
  virtual QapPolyIO MakeIO()=0;
  virtual void WriteTo(QapIO&ref)=0;
public:
  #define LIST(F)F(int)F(unsigned int)F(char)F(unsigned char)F(bool)F(int64)F(uint64)F(float)F(real)F(short)F(unsigned short)
  #define F(TYPE)void load(TYPE&ref){if(!TryLoad(sizeof(ref))){Crash();return;}LoadPOD(&ref,sizeof(ref));}
  LIST(F)
  #undef F
  #define F(TYPE)void save(TYPE&ref){SavePOD(&ref,sizeof(ref));}
  LIST(F)
  #undef F
  #undef LIST
  void load(std::string&ref)
  {
    int size=0;
    load(size);
    if(!size)return;
    if(!TryLoad(size)){Crash();return;}
    ref.resize(size);
    LoadPOD(&ref[0],size);
  }
  void save(std::string&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    SavePOD(&ref[0],size);
  }
  template<class TYPE>
  void load(std::vector<TYPE>&ref)
  {
    int size=0;
    load(size);
    if(!size)return;
    QapAssert(size>0);
    ref.resize(size);
    for(int i=0;i<size;i++){
      load(ref[i]);
    }
  }
  template<class TYPE>
  void save(std::vector<TYPE>&ref)
  {
    int size=ref.size();
    save(size);
    if(!size)return;
    for(int i=0;i<size;i++){
      save(ref[i]);
    }
  }
  void write_raw_string(string&s){if(s.empty())return;SavePOD((void*)&s[0],s.size());}
  template<int>
  struct weak_builder{
    static void buildSizeIO(QapPolyIO&ref){ref.impl=std::move(unique_ptr<QapIO>(new TSizeIO));}
    static void buildDataIO(QapPolyIO&ref){ref.impl=std::move(unique_ptr<QapIO>(new TDataIO));}
  };
};
//-------------------------------------------//
class QapPolyIO:public QapIO{
public:
  unique_ptr<QapIO> impl;
  QapPolyIO():QapIO(){}
  QapPolyIO(QapPolyIO&&ref):QapIO()
  {
    impl=std::move(ref.impl);
  }
  void SavePOD(void*p,int count)
  {
    auto*ptr=impl.get();
    ptr->SavePOD(p,count);
  }
  void LoadPOD(void*p,int count)
  {
    auto*ptr=impl.get();
    ptr->LoadPOD(p,count);
  }
  bool TryLoad(int count)
  {
    auto*ptr=impl.get();
    return ptr->TryLoad(count);
  }
  void Crash()
  {
    auto*ptr=impl.get();
    ptr->Crash();
  }
  bool IsCrashed()
  {
    auto*ptr=impl.get();
    return ptr->IsCrashed();
  }
  bool IsSizeIO()
  {
    auto*ptr=impl.get();
    return ptr->IsSizeIO();
  }
  int GetSize()
  {
    auto*ptr=impl.get();
    return ptr->GetSize();
  }
  QapPolyIO MakeIO()
  {
    auto*ptr=impl.get();
    return ptr->MakeIO();
  }
  void WriteTo(QapIO&ref)
  {
    auto*ptr=impl.get();
    return ptr->WriteTo(ref);
  }
};
class QapPolyScopeIO:public QapIO{
public:
  QapIO&owner;
  unique_ptr<QapIO> impl;
  QapPolyScopeIO(QapIO&owner):owner(owner),QapIO(){impl=std::move(owner.MakeIO().impl);}
  QapPolyScopeIO(QapPolyScopeIO&owner):owner(owner),QapIO(){impl=std::move(owner.MakeIO().impl);}
  QapPolyScopeIO(QapPolyIO&owner):owner(owner),QapIO(){impl=std::move(owner.MakeIO().impl);}
 ~QapPolyScopeIO()
  {
    auto*ptr=impl.get();
    ptr->WriteTo(owner);
  }
  void SavePOD(void*p,int count)
  {
    auto*ptr=impl.get();
    ptr->SavePOD(p,count);
  }
  void LoadPOD(void*p,int count)
  {
    auto*ptr=impl.get();
    ptr->LoadPOD(p,count);
  }
  bool TryLoad(int count)
  {
    auto*ptr=impl.get();
    return ptr->TryLoad(count);
  }
  void Crash()
  {
    auto*ptr=impl.get();
    ptr->Crash();
  }
  bool IsCrashed()
  {
    auto*ptr=impl.get();
    return ptr->IsCrashed();
  }
  bool IsSizeIO()
  {
    auto*ptr=impl.get();
    return ptr->IsSizeIO();
  }
  int GetSize()
  {
    auto*ptr=impl.get();
    return ptr->GetSize();
  }
  QapPolyIO MakeIO()
  {
    auto*ptr=impl.get();
    return ptr->MakeIO();
  }
  void WriteTo(QapIO&ref)
  {
    auto*ptr=impl.get();
    return ptr->WriteTo(ref);
  }
};
//-------------------------------------------//
class TDataIO:public QapIO{
public:
  CrutchIO IO;
  bool crashed;
  TDataIO():crashed(false),QapIO(){}
  //TDataIO(const TDataIO&)=delete;
  //TDataIO(TDataIO&)=delete;
  //TDataIO(TDataIO&&)=delete;
  //void operator=(const TDataIO&)=delete;
  //void operator=(TDataIO&)=delete;
  //void operator=(TDataIO&&)=delete;
public:
  void SavePOD(void*p,int count)
  {
    this->IO.write((char*)p,count);
  }
  void LoadPOD(void*p,int count)
  {
    int max_count=int(this->IO.mem.size())-int(this->IO.pos);
    if(count>max_count)
    {
      QapAssert(count<=max_count);
      return;
    }
    this->IO.read((char*)p,count);
  }
  bool TryLoad(int count)
  {
    auto max_size=int(IO.mem.size())-int(IO.pos);
    return (count>=0)&&(max_size>=count);
  }
  void Crash()
  {
    IO.pos=IO.mem.size();
    crashed=true;
  }
  bool IsCrashed()
  {
    return crashed;
  }
  bool IsSizeIO()
  {
    return false;
  }
  int GetSize()
  {
    return IO.mem.size();
  }
  void SaveTo(QapIO&Stream)
  {
    int size=IO.mem.size();
    Stream.SavePOD(&size,sizeof(size));
    if(!size)return;
    Stream.SavePOD(&IO.mem.front(),size);
  }
  void LoadFrom(QapIO&Stream)
  {
    int size;
    Stream.LoadPOD(&size,sizeof(size));
    if(!size)return;
    IO.mem.resize(size);
    Stream.LoadPOD(&IO.mem.front(),size);
  }
  QapPolyIO MakeIO()
  {
    QapPolyIO ref;
    weak_builder<0>::buildDataIO(ref);
    return std::move(ref);
  }
  void WriteTo(QapIO&ref)
  {
    ref.write_raw_string(IO.mem);
  }
};
//-------------------------------------------//
class TSizeIO:public QapIO{
public:
  int size;
  bool crashed;
public:
  TSizeIO():size(0),crashed(false),QapIO(){}
  void SavePOD(void*p,int count){size+=count;}
  void LoadPOD(void*p,int count){QapNoWay();Crash();}
  bool TryLoad(int count){QapNoWay();Crash();return false;}
  void Crash(){crashed=true;}
  bool IsCrashed(){return crashed;}
  bool IsSizeIO(){return true;}
  int GetSize()
  {
    return size;
  }
  QapPolyIO MakeIO()
  {
    QapPolyIO ref;
    weak_builder<0>::buildSizeIO(ref);
    return std::move(ref);
  }
  void WriteTo(QapIO&ref)
  {
    if(!ref.IsSizeIO()){QapNoWay();Crash();return;}
    ref.SavePOD(nullptr,size);
  }
};
//-------------------------------------------//
inline string file_get_contents(const string&fn){CrutchIO IO;IO.LoadFile(fn);return IO.mem;}
inline void file_put_contents(const string&fn,const string&data){CrutchIO IO;IO.mem=data;IO.SaveFile(fn);}
//-------------------------------------------//
#undef SAY
//-------------------------------------------//
//   {<|          17.10.2014           |>}   //
//-------------------------------------------//