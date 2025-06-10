class QapD3DPresentParameters{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapD3DPresentParameters)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(D3DPRESENT_PARAMETERS,pp,SYS,Zero(pp),$)\
ADDEND()
//=====+>>>>>QapD3DPresentParameters
#include "QapGenStruct.inl"
//<<<<<+=====QapD3DPresentParameters
public:
  template<class TYPE>
  static TYPE&Zero(TYPE&inout)
  {
    ZeroMemory(&inout,sizeof(inout));
    return inout;
  }
  D3DPRESENT_PARAMETERS&SetToDef(HWND hWnd,bool VSync=true)
  {
    Zero(pp);
    TScreenMode SM=GetScreenMode();
    pp.BackBufferWidth=SM.W;
    pp.BackBufferHeight=SM.H;
    pp.BackBufferFormat=D3DFMT_X8R8G8B8;
    pp.BackBufferCount=1;
    pp.SwapEffect=D3DSWAPEFFECT_COPY;
    pp.PresentationInterval=VSync?D3DPRESENT_INTERVAL_ONE:D3DPRESENT_INTERVAL_IMMEDIATE;
    //pp.AutoDepthStencilFormat=D3DADSF_UNKNOW
    pp.hDeviceWindow=hWnd;
    pp.Windowed=true;
    pp.FullScreen_RefreshRateInHz=pp.Windowed?0:SM.Freq;
    return pp;
  }
};

class QapD3D9{
public:
#define DEF_PRO_POOR_DESIGN()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapD3D9)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(IDirect3D9*,pD3D,SYS,nullptr,$)\
ADDEND()
//=====+>>>>>QapD3D9
#include "QapGenStruct.inl"
//<<<<<+=====QapD3D9
public:
  QapD3D9(QapD3D9&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9(){Free();}
public:
  void oper_set(QapD3D9&&Ref){
    Free();
    this->pD3D=Ref.pD3D;
    Ref.pD3D=nullptr;
  }
public:
  void operator=(QapD3D9&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Init()
  {
    Free();
    pD3D=Direct3DCreate9(D3D_SDK_VERSION);
    if(!pD3D)
    {
      QapDebugMsg("Cannot create Direct3D9");
      return;
    }
  }
  void Free()
  {
    if(pD3D)pD3D->Release();
  }
};

class QapD3D9Resource{
public:
  virtual void OnLost()=0;
  virtual void OnReset()=0;
};

class QapD3D9ResourceList{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapD3D9ResourceList)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<QapD3D9Resource*>,Arr,SYS,vector<QapD3D9Resource*>(),$)\
ADDVAR(bool,Lost,SYS,false,$)\
ADDEND()
//=====+>>>>>QapD3D9ResourceList
#include "QapGenStruct.inl"
//<<<<<+=====QapD3D9ResourceList
public:
  QapD3D9ResourceList(QapD3D9ResourceList&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3D9ResourceList(){Free();}
public:
  void oper_set(QapD3D9ResourceList&&Ref){
    Free();
    {this->Arr=std::move(Ref.Arr);}
    {this->Lost=std::move(Ref.Lost);}
  }
public:
  void operator=(QapD3D9ResourceList&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Free()
  {
    Lost=false;
    QapAssert(Arr.empty());
  }
public:
  void OnLost()
  {
    Lost=true;
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnLost();   
    }
  }
  void OnReset()
  {
    Lost=false;
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      ex->OnReset();   
    }
  }
public:
  bool HasRes(QapD3D9Resource*pRes,int*pIndex=nullptr)
  {
    for(int i=0;i<Arr.size();i++)
    {
      auto&ex=Arr[i];
      if(ex!=pRes)continue;
      if(pIndex)*pIndex=i;
      return true;
    }
    if(pIndex)*pIndex=-1;
    return false;
  }
  void Reg(QapD3D9Resource*pRes)
  {
    QapAssert(bool(pRes));
    QapAssert(!HasRes(pRes));
    Arr.push_back(pRes);
  }
  void UnReg(QapD3D9Resource*pRes)
  {
    int i=-1;
    bool flag=HasRes(pRes,&i);
    if(!flag){
      QapAssert(flag);
      return;
    }
    std::swap(Arr[i],Arr.back());
    Arr.pop_back();
  }
};

class QapD3DDev9{
public:
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapD3DDev9)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapD3DPresentParameters,PresParams,SYS,QapD3DPresentParameters(),$)\
ADDVAR(IDirect3DDevice9*,pDev,SYS,nullptr,$)\
ADDVAR(QapD3D9ResourceList,Resources,SYS,QapD3D9ResourceList(),$)\
ADDEND()
//=====+>>>>>QapD3DDev9
#include "QapGenStruct.inl"
//<<<<<+=====QapD3DDev9
public:
  QapD3DDev9(QapD3DDev9&&Ref){
    DoReset();
    oper_set(std::move(Ref));
  }
  ~QapD3DDev9(){Free();}
public:
  void oper_set(QapD3DDev9&&Ref){
    Free();
    {this->PresParams=std::move(Ref.PresParams);}
    {this->pDev=std::move(Ref.pDev);Ref.pDev=nullptr;}
    {this->Resources=std::move(Ref.Resources);}
  }
public:
  void operator=(QapD3DDev9&&Ref){
    oper_set(std::move(Ref));
  }
public:
  void Init(HWND hWnd,QapD3D9&D3D)
  {
    QapAssert(D3D.pD3D);
    Free();
    D3D.pD3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&PresParams.pp,&pDev);
    if(!pDev)
    {
      QapDebugMsg("Cannot create Direct3DDevice9");
      return;
    }
  }
  void Free()
  {
    if(pDev)pDev->Release();
  }
public:
  void ResetStates()
  {
    pDev->SetRenderState(D3DRS_LIGHTING,false);
    pDev->SetRenderState(D3DRS_ZENABLE,false);
    pDev->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
    pDev->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
    pDev->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
    //pDev->SetSamplerState(0,D3DSAMP_ADDRESSU,D3DTADDRESS_CLAMP);
    //pDev->SetSamplerState(0,D3DSAMP_ADDRESSV,D3DTADDRESS_CLAMP);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSU,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_ADDRESSV,D3DTADDRESS_WRAP);
    pDev->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_LINEAR);
  }
public:
  bool BeginScene()
  {
    if(Resources.Lost){EndScene();return false;};
    pDev->BeginScene();
    ResetStates();
    return true;
    //Sys.pDev->BeginStateBlock();IDirect3DStateBlock9 *SB;Sys.pDev->EndStateBlock(&SB);
  }
  bool EndScene()
  {
    if(Resources.Lost){
      HRESULT hr=pDev->TestCooperativeLevel();
      if(hr!=D3DERR_DEVICENOTRESET)return false;
      pDev->Reset(&PresParams.pp);
      Resources.OnReset();
      return false;
    };
    pDev->EndScene(); 
    return !Resources.Lost;
  }
  bool Present(const RECT*pSource=nullptr,const RECT*pDest=nullptr)
  {
    if(!Resources.Lost)
    {
      Resources.Lost=D3DERR_DEVICELOST==pDev->Present(pSource,pDest,NULL,NULL);
      if(Resources.Lost)Resources.OnLost();
    }
    return !Resources.Lost;
  }
public:
  enum BlendType
  {
    BT_NONE,
    BT_SUB,
    BT_ADD,
  };
  enum AlphaType
  {
    AM_NONE,
    AM_GEQUAL_ONE,
    AM_NEQUAL_MAX,
  };
public:
  void Blend(BlendType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHABLENDENABLE,Mode!=BT_NONE);
    if(Mode==BT_NONE)return;
    if(Mode==BT_SUB)//DESTBLENDALPHA
    {
      pDev->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, 0 );
      pDev->SetTextureStageState(0, D3DTSS_COLOROP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_COLORARG2,D3DTA_DIFFUSE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
      pDev->SetTextureStageState(0, D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
      //pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      //pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
      pDev->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      return;
    }
    if(Mode==BT_ADD)
    {
      //pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      //pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
      pDev->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
      pDev->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
      return;
    }
  }
  void Alpha(AlphaType Mode)
  {
    pDev->SetRenderState(D3DRS_ALPHATESTENABLE,Mode!=AM_NONE);
    if(Mode==AM_NONE)return;
    if(Mode==AM_GEQUAL_ONE)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_GREATEREQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,1);
      return;
    }
    if(Mode==AM_NEQUAL_MAX)
    {
      pDev->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_NOTEQUAL);
      pDev->SetRenderState(D3DRS_ALPHAREF,255);
      return;
    }
  }
public:
  static void OrthoLH(D3DMATRIX&out,float w,float h,float zn,float zf)
  {
    QapMat4 mat=QapMat4(
        2.0/w,0,0,0,
        0,2.0/h,0,0,
        0,0,1/(zf-zn),0,
        0,0,-zn/(zf-zn),1
      );
    //mat=Transpose(mat);
    out=mat*Identity4();
  }
  void Set2D(vec2d CamPos=vec2d(0.0,0.0),real zoom=1.0,real ang=0.0,vec2i*pSize=nullptr)
  {
    auto&pp=PresParams.pp;
    vec2i v=pSize?*pSize:vec2i(pp.BackBufferWidth,pp.BackBufferHeight);
    QapMat4 matProj(Identity4());
    QapMat4 matView(Identity4());
    if((v.x%2)||(v.y%2))
    {
      //QapDebugMsg("pSize("+IToS(v.x)+"x"+IToS(v.y)+")");
      if(v.x%2)CamPos.x+=0.5f;
      if(v.y%2)CamPos.y+=0.5f;
    }
    QapMat4 matWorld(Translate(-CamPos.x,-CamPos.y,0)*Scale(zoom,zoom,1.0)*RotateZ(ang));
    OrthoLH(matProj,float(v.x),float(v.y),-1.0,1.0);
    pDev->SetTransform(D3DTS_PROJECTION,&matProj); 
    pDev->SetTransform(D3DTS_VIEW,&matView);
    pDev->SetTransform(D3DTS_WORLD,&matWorld);
  }
  void Clear2D(const QapColor&Color)
  {
    pDev->Clear(0,nullptr,D3DCLEAR_TARGET,Color,1.0f,0);
  }
};
/*
class qap_color{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(qap_color)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(char,a,SET,0,$)\
ADDVAR(char,r,SET,0,$)\
ADDVAR(char,g,SET,0,$)\
ADDVAR(char,b,SET,0,$)\
ADDEND()
//=====+>>>>>qap_color
#include "QapGenStruct.inl"
//<<<<<+=====qap_color
public:

};*/