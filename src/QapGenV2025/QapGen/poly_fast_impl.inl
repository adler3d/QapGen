static vector<vector<t_lex*>> char2lexs;
if(char2lexs.empty()){
  char2lexs.resize(256);
  for(int i=0;i<256;i++){
    auto&out=char2lexs[i];
    for(auto&ex:lex)if(ex.m.mask[i])out.push_back(&ex);
  }
}
i_dev::t_result r=dev.get_char_lt();
if(!r.ok){scope.ok=false;return false;}
auto&arr=char2lexs[(uchar&)r.c];
if(arr.empty()){scope.ok=false;return false;}
for(auto&ex:arr)ex->func();