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
      "_ №"
      "+-*/=|~!@#$%^&()[]{}<>.,:?;`"
      "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
      "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
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
std::string escape_cpp_string(const std::string& input,bool raw=false) {
  std::string escaped_string;
  for (char c : input) {
    switch (c) {
      case '"':
        escaped_string += "\\\"";
        break;
      case '\\':
        escaped_string += "\\\\";
        break;
      case '\n':
        escaped_string += "\\n";
        break;
      case '\t':
        escaped_string += "\\t";
        break;
      case '\r':
        escaped_string += "\\r";
        break;
      case '\0':
        escaped_string += "\\0";
        break;
      default:
        escaped_string += c;
        break;
    }
  }
  return raw?escaped_string:("\""+escaped_string+"\"");
}
string drop_empty_lines(const string&s){
  auto lines=split(s,"\n");
  vector<string> o;
  for(auto&ex:lines){if(ex.find_first_not_of(' ')==string::npos)continue;o.push_back(ex);}
  return join(o,"\n");
}
#include <string>
#include <cctype> // для std::isspace

void drop_empty_lines_v2(std::string&s) {
  size_t write_pos = 0;
  size_t read_pos = 0;
  const size_t len = s.size();

  while (read_pos < len) {
    // Найти начало текущей строки
    size_t line_start = read_pos;

    // Найти конец строки (символ '\n' или конец строки)
    size_t line_end = s.find('\n', read_pos);
    if (line_end == std::string::npos)
      line_end = len;

    // Проверить, есть ли в строке непустые символы (не пробелы)
    bool has_non_space = false;
    for (size_t i = line_start; i < line_end; ++i) {
      //if (!std::isspace(static_cast<unsigned char>(s[i]))) {
        if (s[i] != ' '){
        has_non_space = true;
        break;
      }
    }

    // Если строка не пустая, копируем её на позицию write_pos
    if (has_non_space) {
      // Если не первая строка, добавляем '\n' перед ней, если write_pos > 0
      if (write_pos != 0) {
        s[write_pos++] = '\n';
      }
      // Копируем символы строки
      for (size_t i = line_start; i < line_end; ++i) {
        s[write_pos++] = s[i];
      }
    }

    // Переходим к следующей строке
    read_pos = line_end + 1; // +1 пропускаем '\n'
  }

  // Обрезаем строку до нового размера
  s.resize(write_pos);
}

class BinString{
public:
  string data;
  BinString(){}
  BinString(const string&ref){oper_set(ref);}
public:
  void operator=(const string&ref){oper_set(ref);}
public:
  static string fullCppStr2RawStr(const string&cpp,bool can_be_empty=false){
    if(!can_be_empty){QapAssert(cpp.size()>2);}else{QapAssert(cpp.size()>=2);}
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
      auto m=mask[ex];
      if(ex=='\'')m=true;
      if((!m)||(prev=='\\'))
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