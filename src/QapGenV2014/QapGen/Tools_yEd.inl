struct detail_ToolsYED
{
  static inline bool IsLegalChar(const unsigned char&c)
  {
    return InDip<char>('a',c,'z')||InDip<char>('A',c,'Z')||InDip<char>('0',c,'9');
  }
  static string string2xml(const string&str)
  {
    string tmp;tmp.reserve(str.size()*3);
    for(int i=0;i<str.size();i++)
    {
      tmp+=IsLegalChar(str[i])?CToS(str[i]):"&#"+IToS(str[i])+";";
    }
    return std::move(tmp);
  }
  static string format_graph(const string&templ,const string&input)
  {
    return StrReplace(templ,"$$GRAPH_CODE$$",input);
  }
  static string GetNodeStr(const string&templ,const string&id,const string&name)
  {
    return StrReplace(StrReplace(templ,"$$LABEL$$",string2xml(name)),"$$ID$$",id);
  }
  static string GetEdgeStr(const string&templ,const string&source,const string&target)
  {
    return StrReplace(StrReplace(templ,"$$SOURCE$$",string2xml(source)),"$$TARGET$$",string2xml(target));
  }
  static string GetGroupStr(const string&templ,const string&id,const string&name,const string&graph)
  {
    return StrReplace(StrReplace(StrReplace(templ,"$$LABEL$$",string2xml(name)),"$$ID$$",id),"$$GRAPH$$",graph);
  }
};

class ToolsYED{
public:
  class TContent{
  public:
    #define DEF_PRO_AUTO_CONSTRUCTOR()
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TContent)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,filename,SET,"template.graphml",$)\
    ADDVAR(string,content,DEF,$,$)\
    ADDEND()
    //=====+>>>>>TContent
    #include "QapGenStruct.inl"
    //<<<<<+=====TContent
  public:
    void load()
    {
      CrutchIO IO;
      IO.LoadFile(filename);
      content=std::move(IO.mem);
    }
    void save()
    {
      CrutchIO IO;
      IO.mem=content;
      IO.SaveFile(filename);
    }
  };
  class TNode{
  public:
    #define DEF_PRO_AUTO_CONSTRUCTOR()
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TNode)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,name,DEF,$,$)\
    ADDVAR(int,parent,SET,-1,$)\
    ADDEND()
    //=====+>>>>>TNode
    #include "QapGenStruct.inl"
    //<<<<<+=====TNode
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(TContent)F(TNode)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ToolsYED)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TContent,output,SET,TContent(string("tree.graphml"),string("")),$)\
ADDVAR(TContent,graph_templ,SET,TContent(string("HQ/template.graphml"),string("")),$)\
ADDVAR(TContent,node_templ,SET,TContent(string("HQ/node.tml"),string("")),$)\
ADDVAR(TContent,edge_templ,SET,TContent(string("HQ/edge.tml"),string("")),$)\
ADDVAR(TContent,group_templ,SET,TContent(string("HQ/group.tml"),string("")),$)\
ADDVAR(vector<TNode>,nodes,DEF,$,$)\
ADDVAR(vector<vec2i>,edges,DEF,$,$)\
ADDEND()
//=====+>>>>>ToolsYED
#include "QapGenStruct.inl"
//<<<<<+=====ToolsYED
public:
  void clear()
  {
    nodes.clear();
    edges.clear();
  }
  string get_graph(vector<vector<int>>&childs,int id)
  {
    auto&graph_templ=this->graph_templ.content;
    auto&node_templ=this->node_templ.content;
    auto&group_templ=this->group_templ.content;
    auto&edge_templ=this->edge_templ.content;
    typedef detail_ToolsYED YED;
    auto&arr=childs[id];
    if(arr.empty())
    {
      return YED::GetNodeStr(node_templ,"n"+IToS(id),nodes[id].name);;
    }
    string graph;
    for(int i=0;i<arr.size();i++)
    {
      graph+=get_graph(childs,arr[i]);
    }
    string output=YED::GetGroupStr(group_templ,"n"+IToS(id),nodes[id].name,graph);
    return output;
  };
  void gen()
  {
    auto&output=this->output.content;
    auto&graph_templ=this->graph_templ.content;
    auto&node_templ=this->node_templ.content;
    auto&group_templ=this->group_templ.content;
    auto&edge_templ=this->edge_templ.content;
    auto add=[&output](const string&msg){output+=msg+"\n";};
    typedef detail_ToolsYED YED;
    vector<vector<int>> childs;
    childs.resize(nodes.size());
    for(int i=0;i<nodes.size();i++)
    {
      auto&it=nodes[i];
      if(it.parent<0)continue;
      childs[it.parent].push_back(i);
    }
    for(int i=0;i<nodes.size();i++)
    {
      auto&it=nodes[i];
      if(it.parent!=-1)continue;
      string graph=get_graph(childs,i);
      add(graph);
    }
    for(int i=0;i<edges.size();i++)
    {
      auto&it=edges[i];
      add(YED::GetEdgeStr(edge_templ,"n"+IToS(it.x),"n"+IToS(it.y)));
    }
    output=YED::format_graph(graph_templ,output);
  }
  void SetHQ()
  {
    graph_templ.filename="HQ/template.graphml";
    node_templ.filename="HQ/node.tml";
    group_templ.filename="HQ/group.tml";
    edge_templ.filename="HQ/edge.tml";
  }
  void SetLQ()
  {
    graph_templ.filename="LQ/template.graphml";
    node_templ.filename="LQ/node.tml";
    group_templ.filename="LQ/group.tml";
    edge_templ.filename="LQ/edge.tml";
  }
  void load()
  {
    graph_templ.load();
    node_templ.load();
    group_templ.load();
    edge_templ.load();
  }
  void save()
  {
    output.save();
  }
  int add_node(const string&name,int parent=-1)
  {
    int result=nodes.size();
    TNode tmp;
    tmp.name=name;
    tmp.parent=parent;
    nodes.push_back(std::move(tmp));
    return result;
  }
  void add_edge(int source,int target)
  {
    edges.push_back(vec2i(source,target));
  }
  int get_node_id(const string&node)
  {
    for(int i=0;i<nodes.size();i++)
    {
      if(nodes[i].name==node)return i;
    }
    return -1;
  }
  void ConvToParentTree()
  {
    auto old_edges=std::move(edges);//.clear();
    auto&arr=nodes;
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i].parent<0)continue;
      add_edge(arr[i].parent,i);
      arr[i].parent=-1;
    }
    for(int i=0;i<old_edges.size();i++)edges.push_back(std::move(old_edges[i]));
  }
};