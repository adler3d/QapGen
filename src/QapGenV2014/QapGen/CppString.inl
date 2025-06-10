class CppString{
public:
  string data;
  CppString(){}
  CppString(const string&ref){oper_set(ref);}
public:
  void operator=(const string&ref){oper_set(ref);}
public:
  static string toCode(uchar ch){
    string tmp=CToH_raw(ch);
    //string out="\"\"\\x"+tmp+"\"\"";
    string out="\\x"+tmp;
    return out;
  };
  static const CharMask&getMask()
  {
    static CharMask mask(
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "0123456789"
      "_ ¹"
      "+-*/=|~!@#$%^&()[]{}<>.,:?;`"
      "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß"
      "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"
    );
    return mask;
  }
  void oper_set(const string&ref)
  {
    int linestart=0;
    const CharMask&mask=CppString::getMask();
    data.clear();
    data.reserve(ref.size());
    struct Hidden{
      string&data;
      string line;
      int line_count;
      Hidden(string&data):data(data){line_count=0;}
      ~Hidden()
      {
        if(!line.empty())next();
        if(line.size()<=64)return;
        string beg="BEGIN()\n";
        string end="END()\n";
        data=beg+data+end;
      }
      void next(){
        static const int c8k=2<<12;
        line_count++;
        //data+="F(\"";
        data+=line;
        //data+="\")";
        //data+="\n";
        line.clear();
        if(!(line_count%c8k))
        {
          QapDebugMsg("big line");
          data+="END()\nBEGIN()\n";
        }
      }
      void check(){
        const int linesize=line.size();
        if(linesize>80)next();
      }
    } HD(data);
    string&line=HD.line;
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      HD.check();
      //line+=toCode(ex);
      //continue;
      if(!mask[ex])
      {
        //if(ex=='\"'){
        //  line+="\\\"";
        //}else if(ex=='\''){
        //  line+="\\\'";
        //}else if(ex=='\n'){
        //  line+="\\n";HD.next();
        //}else if(ex=='\r'){
        //  line+="\\r";
        //}else if(ex=='\\'){
        //  line+="\\\\";
        //}else{
        //  line+=toCode(ex);
        //};
        #define F(A,B)if(ex==A){line+=B;continue;}
        F('\\',"\\\\")
        F('\"',"\\\"")
        F('\'',"\\\'")
        F('\n',"\\n")
        F('\r',"\\r")
        F('\t',"\\t")
        F('\b',"\\b")
        F('\f',"\\f")
        F('\0',"\\0")
        F('\1',"\\1")
        F('\2',"\\2")
        F('\3',"\\3")
        F('\4',"\\4")
        F('\5',"\\5")
        F('\6',"\\6")
        F('\7',"\\7")
        #undef F
          line+=toCode(ex);
      }else{
        line.push_back(ex);
      }
    }
  }
public:
  static bool IsValidCppChar(char c)
  {
    const CharMask&mask=CppString::getMask();
    unsigned char uc=*(unsigned char*)(void*)&c;
    return mask.mask[uc];
  }
};
class BinString{
public:
  string data;
  BinString(){}
  BinString(const string&ref){oper_set(ref);}
public:
  void operator=(const string&ref){oper_set(ref);}
public:
  static string fullCppStr2RawStr(const string&cpp){
    QapAssert(cpp.size()>2);
    QapAssert(cpp.front()=='"');
    QapAssert(cpp.back()=='"');
    BinString bin=cpp.substr(1,cpp.size()-2);
    return bin.data;
  }
  static string toCode(uchar ch){
    string tmp=CToH_raw(ch);
    string out="'\\x"+tmp+"'";
    //string out="\\x"+tmp;
    return out;
  };
  void oper_set(const string&ref)
  {
    int linestart=0;
    const CharMask&mask=CppString::getMask();
    data.clear();
    data.reserve(ref.size());
    uchar prev=0;
    for(int i=0;i<ref.size();i++)
    {
      uchar ex=ref[i];
      if((!mask[ex])||(prev=='\\'))
      {
        #define F(A,B){if((prev==B[0])&&(ex==B[1])){data.push_back(A);prev=0;continue;}}
        F('\\',"\\\\")
        F('\"',"\\\"")
        F('\'',"\\\'")
        F('\n',"\\n")
        F('\r',"\\r")
        F('\t',"\\t")
        F('\b',"\\b")
        F('\f',"\\f")
        F('\0',"\\0")
        F('\1',"\\1")
        F('\2',"\\2")
        F('\3',"\\3")
        F('\4',"\\4")
        F('\5',"\\5")
        F('\6',"\\6")
        F('\7',"\\7")
        #undef F
        if((prev!='\\')&&ex=='\\'){prev=ex;continue;}
        QapDebugMsg("bad char("+toCode(ex)+") = \'"+CToS(ex)+"\'");
        return;
      }else{
        data.push_back(ex);
      }
      prev=ex;
    }
  }
};