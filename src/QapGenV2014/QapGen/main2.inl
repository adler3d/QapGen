struct TCompileUnitMan:public ICompileUnitMan
{
  vector<ICompileUnit*> arr;
  void add(ICompileUnit*pUnit){arr.push_back(pUnit);}
  static TCompileUnitMan&get_man()
  {
    static TCompileUnitMan comp_unit_man;
    return comp_unit_man;
  }
  static void reg_and_run_all(IEnvRTTI&Env)
  {
    auto&man=get_man();
    auto&arr=man.arr;
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i];
      string fn=ex->get_filename();
      ex->RegAll(Env);
    }
    for(int i=0;i<arr.size();i++)
    {
      auto*ex=arr[i];
      string fn=ex->get_filename();
      ex->Run(Env);
    }
  }
};

ICompileUnitMan&ICompileUnitMan::get_man()
{
  return TCompileUnitMan::get_man();
}