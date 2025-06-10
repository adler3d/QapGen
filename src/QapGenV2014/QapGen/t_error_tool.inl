struct t_error_tool{
  struct t_subline{
    string cpp;
    string low;
    string error;
  public:
    static string toCpp(const string&raw){CppString cpp=raw;return cpp.data;}
    static int toCppLen(const string&raw){CppString cpp=raw;return cpp.data.size();}
    static string gen(size_t count,char c){string tmp;tmp.resize(count,c);return tmp;}
    static t_subline go(const string&line,size_t offset){
      t_subline out;
      QapAssert(line.size()<=1024);
      if(offset>=line.size()){
        out.error="offset<=line.size()";
        return out;
      }
      string target=CToS(line[offset]);
      int len=toCppLen(target);
      string top=toCpp(line.substr(0,offset));
      string low=gen(top.size(),'-')+gen(len,'^');
      top+=toCpp(line.substr(offset));
      out.cpp=top;
      out.low=low;
      return out;//"\""+top+"\" ...\n-"+low;
    }
  };

  struct t_line_info{
    size_t line_id;
    size_t curpos;
    bool ok;
    static t_line_info get(const string&mem,size_t pos){
      t_line_info out={0,0,false};
      out.go(mem,pos);
      return out;
    }
    void go(const string&mem,size_t pos){
      QapAssert(pos<mem.size());
      line_id=0;
      curpos=0;
      ok=true;
      for(int i=0;i<pos;i++){
        if(mem[i]=='\n'){line_id++;curpos=i+1;ok=true;}
      }
    }
  };

  static string get_codefrag(const string&code,size_t pos){
    auto subline_go=t_subline::go;
    auto go=[&subline_go,&pos](const t_line_info&info,const string&line,size_t offset,const string&sep)->string{
      auto sub=subline_go(line,offset);
      QapAssert(sub.error.empty());
      return "{\"line\":"+IToS(info.line_id)+",\"pos\":"+IToS(pos-info.curpos)+"}\n\""+sub.cpp+"\" "+sep+"\n-"+sub.low;
    };
    QapAssert(!code.empty());
    QapAssert(pos<code.size());
    auto info=t_line_info::get(code,pos);
    if(!info.ok){
      QapAssert(false);
    }
    int offset=pos-info.curpos;
    auto eol=code.find('\n',info.curpos);
    if(eol==string::npos){
      auto line=code.substr(info.curpos,string::npos);
      return go(info,line,offset,"EOD");
    }
    auto line=code.substr(info.curpos,eol-info.curpos+1);
    return go(info,line,offset,"...");
  }
};