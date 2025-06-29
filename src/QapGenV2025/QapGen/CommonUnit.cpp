#define DEF_PRO_FULL
#include <bitset>
#include "FromQapEng.h"
//#include "QapMicro2/QapTools.h"
typedef unsigned char uchar;
#include "CppString.inl"
#define TAutoPtr unique_ptr
#include "detail.inl"
#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
typedef array<char,2> ARRAY2char;
typedef array<char,4> ARRAY4char;
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"
#include "visitor_gen.h"

#include <iostream>
#ifdef _WIN32
#include <shellapi.h>
int main()
{
  return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL);
}
namespace t_out_hpp{
//#include "out.hpp"
};
/*
  static i_foobarbaz*id2instance(int id){
    int i=0;
    #define ADD(U)if(i++==id)return new t_branch_lexem::U();
    LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
    #undef ADD
    return nullptr;
  }
*/
//#include "json_lexer.hpp"
//#include "main2.inl"
/*
  public:
    static i_foobarbaz*id2instance(int id){
      int i=0;
      #define ADD(U)if(i++==id)return new t_branch_lexem::U();
      LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
      #undef ADD
      return nullptr;
    }*/
void UberCast_bench2(){
  //vector<t_branch_lexem::i_foobarbaz*> arr;
  //for(int i=0;i<10000000;i++)arr.push_back(t_branch_lexem::id2instance(rand()%128));
  //vector<size_t> out;out.resize(arr.size());
  //QapClock c;
  //for(auto&ex:arr){
  //  auto*q=t_branch_lexem::t_foobarbaz_v53::UberCast(ex);
  //  size_t qw=size_t(q)*size_t(q);
  //  out.push_back(qw);
  //}
  //auto ms=c.MS();
  //cerr<<ms<<endl;
  //out.clear();
  //QapClock c2;
  //for(auto&ex:arr){
  //  auto*q=dynamic_cast<t_branch_lexem::t_foobarbaz_v53*>(ex);
  //  size_t qw=size_t(q)*size_t(q);
  //  out.push_back(qw);
  //}
  //auto ms2=c2.MS();
  //cerr<<ms2;
  // 19.85 sec -- 18.28 -- 18.98  // 701 �� (718�336 ����)
  // 12.94 sec -- 13.63           // 701 �� (717�824 ����)
  // 12.49 sec -- 11.17
  // 21.76 sec
  // 29.22+26.95+30.21+27.21 empty  28.3975
  // 30.45+35.17+33.54+32.95                         dycast 33.0275 // 4.63 sec // 36.17 ms/cast
  // 39.59+41.59+34.35+35.93+33.79+38.20+37.33+37.61 ubcast 37.29   // 8.90 sec // 69.54 ms/cast
}
/*
void UberCast_bench(){
  t_branch_lexem::i_case*ptr=new t_branch_lexem::t_hard();
  t_branch_lexem::i_case*wtr=new t_branch_lexem::t_soft();
  vector<t_branch_lexem::i_case*> arr;
  for(int i=0;i<10000000;i++)arr.push_back(rand()%2?ptr:wtr);
  vector<size_t> out;out.resize(arr.size());
  QapClock c;
  for(auto&ex:arr){
    auto*q=t_branch_lexem::t_hard::UberCast(ex);
    size_t qw=size_t(q)*size_t(q);
    out.push_back(qw);
  }
  auto ms=c.MS();
  out.clear();
  QapClock c2;
  for(auto&ex:arr){
    auto*q=dynamic_cast<t_branch_lexem::t_hard*>(ex);
    size_t qw=size_t(q)*size_t(q);
    out.push_back(qw);
  }
  auto ms2=c2.MS();
  cerr<<ms<<" "<<ms2;
}
*/
/*
#include <windows.h>
#include <winioctl.h>
#include <iostream>

#pragma pack(push, 1)
struct SENDCMDINPARAMS2 {
    DWORD  dwDriveNumber;
    BYTE   bDriveRegs[8];
    BYTE   bBufferSize;
    BYTE   bReserved[3];
    DWORD  dwReserved[4];
};

struct DRIVERSTATUS2 {
    BYTE  bDriverError;
    BYTE  bIDEStatus;
    BYTE  bReserved[2];
    DWORD dwReserved[2];
};

struct SENDCMDOUTPARAMS2 {
    DWORD          cBufferSize;
    DRIVERSTATUS   DriverStatus;
    BYTE           bBuffer[512];
};

struct IDSECTOR2 {
    USHORT  wGenConfig;
    USHORT  wNumCyls;
    USHORT  wReserved;
    USHORT  wNumHeads;
    USHORT  wBytesPerTrack;
    USHORT  wBytesPerSector;
    USHORT  wSectorsPerTrack;
    USHORT  wVendorUnique[3];
    CHAR    sSerialNumber[20];
    USHORT  wBufferType;
    USHORT  wBufferSize;
    USHORT  wECCSize;
    CHAR    sFirmwareRev[8];
    CHAR    sModelNumber[40];
    USHORT  wMoreVendorUnique;
    USHORT  wDoubleWordIO;
    USHORT  wCapabilities;
    USHORT  wReserved1;
    USHORT  wPIOTiming;
    USHORT  wDMATiming;
    USHORT  wBS;
    USHORT  wNumCurrentCyls;
    USHORT  wNumCurrentHeads;
    USHORT  wNumCurrentSectorsPerTrack;
    ULONG   ulCurrentSectorCapacity;
    USHORT  wMultSectorStuff;
    ULONG   ulTotalAddressableSectors;
    USHORT  wSingleWordDMA;
    USHORT  wMultiWordDMA;
    BYTE    bReserved[128];
};
#pragma pack(pop)
#include <Ntdddisk.h>
bool GetSmartTemperature(int driveNumber, BYTE& temperature) {
    HANDLE hDevice = CreateFileA(
        ("\\\\.\\PHYSICALDRIVE" + std::to_string(driveNumber)).c_str(),
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (hDevice == INVALID_HANDLE_VALUE) {
        std::cerr << "������ �������� �����\n";
        return false;
    }

    // ��������� ��� ������� SMART
    SENDCMDINPARAMS scip = {0};
    SENDCMDOUTPARAMS scap = {0};
    DWORD bytesReturned = 0;

    scip.bDriveNumber = driveNumber;
    scip.irDriveRegs.bCommandReg = 0xB0; // SMART_CMD
    scip.irDriveRegs.bFeaturesReg = 0xD0; // SMART_READ_ATTRIBUTES
    scip.irDriveRegs.bSectorCountReg = 1;    // Sector count
    scip.irDriveRegs.bSectorNumberReg = 1;    // Sector number
    //scip.bBufferSize=sizeof(scap);

    if (!DeviceIoControl(hDevice,
        SMART_RCV_DRIVE_DATA,
        &scip,
        sizeof(scip),
        &scap,
        sizeof(scap),
        &bytesReturned,
        NULL)) {
        std::cerr << "������ DeviceIoControl\n";
        CloseHandle(hDevice);
        return false;
    }

    CloseHandle(hDevice);

    // SMART ������ ���������� � offset 0x3E (62) ��� ���������
    BYTE* data = scap.bBuffer;

    // ������ ������� SMART �������� 12 ����, ���� ������� � ID 194 (�����������)
    for (int i = 0; i < 30; ++i) {
        BYTE id = data[i * 12];
        if (id == 194) {
            temperature = data[i * 12 + 5]; // ������� ����������� � ����� 5
            return true;
        }
    }

    std::cerr << "����������� �� �������\n";
    return false;
}

int main2() {
    BYTE temp = 0;
    int driveNumber = 0; // ����� �����, ������ 0 ��� ������� �����

    if (GetSmartTemperature(driveNumber, temp)) {
        std::cout << "����������� SSD: " << (int)temp << " �C\n";
    } else {
        std::cout << "�� ������� �������� ����������� SSD\n";
    }

    return 0;
}*/
/*
#include "XoshiroCpp.hpp"
void ssd_test(){
  using namespace XoshiroCpp;

  const std::uint64_t seed = 31456;

  Xoshiro256PlusPlus rng(seed);
  
  constexpr auto n=1024ui64*1024*1024*916;
  constexpr size_t pn=1024*1024;
  string converted;converted.reserve(pn*2);
  if(bool need_load=true){
    std::fstream f("D:\\test3.bin",std::ios::in|std::ios::binary);
    string s,sr;
    s.resize(pn);sr.resize(pn*2);
    auto*p=(unsigned long long*)s.data();
    auto*pr=(unsigned long long*)sr.data();
    QapClock c;
    for(size_t j=0;j<n/pn;j++){
      for(size_t i=0;i<pn/8;i++){
        p[i]=rng();
      }
      converted.clear();
      for (char c : s) {
          if (c == '\n') {
              converted.push_back('\r');
              converted.push_back('\n');
          } else {
              converted.push_back(c);
          }
      }
      sr.resize(converted.size());
      f.read((char*)pr,converted.size());
      if(f.fail())break;
      auto*pc=converted.data();
      auto*rr=sr.data();
      if(converted!=sr){
        for(int i=0;i<converted.size();i++){
          if(pc[i]!=rr[i]){
            auto a=pc[i];
            auto b=rr[i];
            auto prev_a=pc[i-1];
            auto prev_b=rr[i-1];
            auto next_a=pc[i+1];
            auto next_b=rr[i+1];
            //auto&aa=(unsigned char(&)[8])a;
            //auto&ab=(unsigned char(&)[8])b;
            string sa,sb;
            for(int i=0;i<64;i++){
              sa.push_back(a%2?'0':'1');a/=2;
              sb.push_back(b%2?'0':'1');b/=2;
            }
            static int fail_count=0;1024*4;
            if(fail_count--<0)
              QapDebugMsg("fail detected at j="+IToS(j)+" i="+IToS(i)+" a="+to_string(a)+" b="+to_string(b)+"\n"+sa+"\n"+sb);
          }
        }
        QapDebugMsg("fail detected");
      }
      if(j%1024==0){
        auto ms=c.MS();
        cerr<<"j="<<j<<" ms="<<ms<<" spd="<<(FToS((j+1)*pn/ms))<<endl;
      }
    }
    QapDebugMsg("all ok");
  }
  if(bool need_save=false){
    std::fstream f("D:\\test5.bin",std::ios::out|std::ios::trunc|std::ios::binary);
    string s;
    s.resize(pn);
    auto*p=(unsigned long long*)s.data();
    QapClock c;
    for(size_t j=0;j<n/pn;j++){
      for(size_t i=0;i<pn/8;i++){
        p[i]=rng();
      }
      f<<s;
      if(j%1024==0){
        auto ms=c.MS();
        cerr<<"j="<<j<<" ms="<<ms<<" spd="<<(FToS((j+1)*pn/ms))<<endl;
      }
      if(j>10)break;
    }
    f.close();
    auto ms=c.MS();
    QapDebugMsg(FToS2(ms)+" "+FToS(n/ms));
  }
}*/

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  //for(;;);
  //main2();
  //file_put_contents("test.bin",s);
  //TAutoPtr<t_json::i_value> json;
  //auto r=load_obj_full(json,"[1, 2, {\"a\":-10.5e2}]");
  //r.msg;
  UberCast_bench2();
  int argc=0;
  LPWSTR*argv=CommandLineToArgvW(GetCommandLineW(),&argc);
  string fn;if(argc>1)fn.resize(wcslen(argv[1]));
  if(fn.size())wcstombs(&fn[0],argv[1],wcslen(argv[1])+1);
  test_2025_06_10(fn);
  return 0;
}
#else
int main(int argc,char*argv[])
{
  string fn;
  if(argc>1)fn=argv[1];
  test_2025_06_10(fn);
  return 0;
}
#endif


//-----
#undef DEF_PRO_FULL