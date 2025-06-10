#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include "QapType.h"
//-------------------------------------------//

#ifdef DEF_BUILD_MACRO
  #include "../Macro/QapVec.h"
#else
//=====>>>>>QapVec

const real Pi  =4.0*atan(1.0);// == pi
const real Pi2 =8.0*atan(1.0);// == pi*2
const real PiD2=2.0*atan(1.0);// == pi/2
const real PiD4=1.0*atan(1.0);// == pi/4
//-------------------------------------------//
template<typename TYPE>inline TYPE Lerp(const TYPE&A,const TYPE&B,const real&v){return A+(B-A)*v;}
template<class TYPE>inline TYPE Clamp(const TYPE&v,const TYPE&a,const TYPE&b){return max(a,min(v, b));}
//-------------------------------------------//
class vec2d{
public:
#define DEF_PRO_MANUAL_RESET()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec2d)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(real,x,SET,0.0,$)\
ADDVAR(real,y,SET,0.0,$)\
ADDEND()
//=====+>>>>>vec2d
#include "QapGenStruct.inl"
//<<<<<+=====vec2d
public:
  vec2d():x(0.0),y(0.0){}
  vec2d(const real&x,const real&y):x(x),y(y){}
  vec2d(const vec2d&v):x(v.x),y(v.y){}
  void operator=(const vec2d&v){x=v.x;y=v.y;}
  vec2d operator+()const{return *this;}
  vec2d operator-()const{return vec2d(-x,-y);}
  void operator+=(const vec2d&v){x+=v.x; y+=v.y;}
  void operator-=(const vec2d&v){x-=v.x; y-=v.y;}
  void operator*=(const real&f){x*=f;y*=f;}
  void operator/=(const real&f){x/=f;y/=f;}
public:
  vec2d Rot(const vec2d&OX)const{real M=OX.Mag();return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);}
  vec2d UnRot(const vec2d&OX)const{real M=OX.Mag();if(M==0.0f){return vec2d(0,0);};return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);}
  vec2d Ort()const{return vec2d(-y,x);}
  vec2d Norm()const{if((x==0)&&(y==0)){return vec2d(0,0);}return vec2d(x/this->Mag(),y/this->Mag());}
  vec2d SetMag(const real&val)const{return this->Norm()*val;}
  vec2d Mul(const vec2d&v)const{return vec2d(x*v.x,y*v.y);}
  vec2d Div(const vec2d&v)const{return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);}
  real GetAng()const{return atan2(y,x);}
  real Mag()const{return sqrt(x*x+y*y);}
  real SqrMag()const{return x*x+y*y;}
public:
  friend vec2d operator+(const vec2d&u,const vec2d&v){return vec2d(u.x+v.x,u.y+v.y);}
  friend vec2d operator-(const vec2d&u,const vec2d&v){return vec2d(u.x-v.x,u.y-v.y);}
  friend vec2d operator*(const vec2d&u,const real&v){return vec2d(u.x*v,u.y*v);}
  friend vec2d operator*(const real&u,const vec2d&v){return vec2d(u*v.x,u*v.y);}
  friend bool operator==(const vec2d&u,const vec2d&v){return (u.x==v.x)&&(u.y==v.y);}
  friend bool operator!=(const vec2d&u,const vec2d&v){return (u.x!=v.x)||(u.y!=v.y);}
public:
  //friend inline static vec2d Vec2dEx(const real&ang,const real&mag){return vec2d(cos(ang)*mag,sin(ang)*mag);}
public:
  friend inline static real dot(const vec2d&a,const vec2d&b){return a.x*b.x+a.y*b.y;}
  friend inline static real cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
public:
  #ifdef BOX2D_H
    operator b2Vec2()const{return b2Vec2(x,y);}
    vec2d(const b2Vec2& v):x(v.x),y(v.y){}
  #endif
};
//-------------------------------------------//
class QapColor{
public:
  typedef uchar byte;
public:
#define DEF_PRO_MANUAL_RESET()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapColor)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(uchar,b,DEF,$,$)\
ADDVAR(uchar,g,DEF,$,$)\
ADDVAR(uchar,r,DEF,$,$)\
ADDVAR(uchar,a,DEF,$,$)\
ADDEND()
//=====+>>>>>QapColor
#include "QapGenStruct.inl"
//<<<<<+=====QapColor
public:
  QapColor():b(255),g(255),r(255),a(255){}
  QapColor(byte A,byte R,byte G,byte B):a(A),r(R),g(G),b(B){}
  QapColor(byte R,byte G,byte B):a(255),r(R),g(G),b(B){}
  QapColor(const QapColor& v):a(v.a),r(v.r),g(v.g),b(v.b){}
public:
  QapColor&operator=(const QapColor&v){a=v.a;r=v.r;g=v.g;b=v.b;return *this;}
  QapColor operator+()const{return *this;}
public:
  QapColor&operator*=(const QapColor&v){
  #define F(r){r=Clamp(int(r)*int(v.r)/int(255),int(0),int(255));}
    F(a)F(r)F(g)F(b)
    #undef F
    return *this;
  }
  QapColor&operator+=(const QapColor&v){
  #define F(r){r=Clamp(int(r)+int(v.r),int(0),int(255));}
    F(a)F(r)F(g)F(b)
    #undef F
    return *this;
  }
  QapColor&operator-=(const QapColor&v){
  #define F(r){r=Clamp(int(r)-int(v.r),int(0),int(255));}
    F(a)F(r)F(g)F(b)
    #undef F
    return *this;
  }
  QapColor operator*(const QapColor&v)const{
    #define F(r)int(int(r)*int(v.r))/int(255)
    return QapColor(F(a),F(r),F(g),F(b));
    #undef F
  }
  QapColor operator+(const QapColor&v)const{
    #define F(r)Clamp(int(r)+int(v.r),int(0),int(255))
    return QapColor(F(a),F(r),F(g),F(b));
    #undef F
  }
  QapColor operator-(const QapColor&v)const{
    #define F(r)Clamp(int(r)-int(v.r),int(0),int(255))
    return QapColor(F(a),F(r),F(g),F(b));
    #undef F
  }
public:
  #define F(r){r=byte(Clamp(real(r)*f,0.0,255.0));}
    QapColor&operator*=(real f){F(b);F(g);F(r);return *this;}
    QapColor&operator/=(real r){real f=1.0/r;F(b);F(g);F(r);return *this;}
  #undef F
public:
  #ifdef _D3D9_H_
    QapColor(const D3DCOLOR& v){*((D3DCOLOR*)(void*)this)=v;}
    operator D3DCOLOR&()const{return *(DWORD*)this;};
  #endif
public:
  #ifdef BOX2D_H
    QapColor(const b2Color& v){a=255;r=int(v.r*255.0);g=int(v.g*255.0);b=int(v.b*255.0);}
  #endif
public:
  byte GetLuminance(){return int(int(r)+int(g)+int(b))/int(3);}
  inline static QapColor Mix(const QapColor&A,const QapColor&B,const real&t){
    real ct=Clamp(t,0.0,1.0);
    real tA=1.0-ct;
    real tB=ct;
    QapColor O;
    #define F(r){O.r=byte(Clamp(real(A.r)*tA+real(B.r)*tB,0.0,255.0));}
    F(b)F(g)F(r)F(a)
    #undef F
    return O;
  }
  inline static QapColor HalfMix(const QapColor&A,const QapColor&B)
  {
    QapColor O;
    #define F(r){O.r=(int(A.r)+int(B.r))>>1;}
    F(b)F(g)F(r)F(a)
    #undef F
    return O;
  }
};
//-------------------------------------------//
class vec4i{
public:
#define DEF_PRO_MANUAL_RESET()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec4i)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,DEF,$,$)\
ADDVAR(int,y,DEF,$,$)\
ADDVAR(int,z,DEF,$,$)\
ADDVAR(int,w,DEF,$,$)\
ADDEND()
//=====+>>>>>vec4i
#include "QapGenStruct.inl"
//<<<<<+=====vec4i
public:
  vec4i():x(0),y(0),z(0),w(0){}
  //vec4i(int b,int g,int r,int a):b(b),g(g),r(r),a(a){}
  vec4i(int x,int y,int z,int w):x(x),y(y),z(z),w(w){}
  vec4i(const QapColor&ref):x(ref.a),y(ref.r),z(ref.g),w(ref.b){}
  void operator+=(const vec4i&v){x+=v.x;y+=v.y;z+=v.z;w+=v.w;}
  vec4i operator*(const int&v){return vec4i(x*v,y*v,z*v,w*v);}
  vec4i operator/(const int&v){return vec4i(x/v,y/v,z/v,w/v);}
  void operator/=(const int&v){x/=v;y/=v;z/=v;w/=v;}
  void operator>>=(const int&v){x>>=v;y>>=v;z>>=v;w>>=v;}
  vec4i operator+(const vec4i&v){return vec4i(x+v.x,y+v.y,z+v.z,w+v.w);}
  //#define F(r)Clamp(int(r),int(0),int(255))
  //QapColor GetColor(){return QapColor(F(x),F(y),F(z),F(w));}
  //#undef F
  QapColor unsafe_but_fast_GetColor(){
    QapAssert(x>=0&&x<256);
    QapAssert(y>=0&&y<256);
    QapAssert(z>=0&&z<256);
    QapAssert(w>=0&&w<256);
    return QapColor(x,y,z,w);
  }
};
struct vec3f{
public:
  float x,y,z;
  vec3f():x(0),y(0),z(0){}
  vec3f(float x,float y,float z):x(x),y(y),z(z){}
};
//-------------------------------------------//
struct vec4f{
public:
  float b,g,r,a;
  //struct{float x,y,z,w;};
  vec4f():b(1.0),g(1.0),r(1.0),a(1.0){}
  vec4f(float b,float g,float r,float a):b(b),g(g),r(r),a(a){}
  vec4f(const QapColor&ref):b(ref.b/255.f),g(ref.g/255.f),r(ref.r/255.f),a(ref.a/255.f){}
  vec4f&operator+=(const vec4f&v){b+=v.b;g+=v.g;r+=v.r;a+=v.a;return *this;}
  friend vec4f operator*(const float&u,const vec4f&v){return vec4f(u*v.b,u*v.g,u*v.r,u*v.a);}
  friend vec4f operator+(const vec4f&u,const vec4f&v){return vec4f(u.b+v.b,u.g+v.g,u.r+v.r,u.a+v.a);}
  #define F(r)Clamp(int(r*255),int(0),int(255))
  QapColor GetColor(){return QapColor(F(a),F(r),F(g),F(b));}
  #undef F
};
//-------------------------------------------//
class vec2f{
public:
#define DEF_PRO_MANUAL_RESET()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec2f)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(float,x,SET,0.0f,$)\
ADDVAR(float,y,SET,0.0f,$)\
ADDEND()
//=====+>>>>>vec2f
#include "QapGenStruct.inl"
//<<<<<+=====vec2f
public:
  vec2f():x(0),y(0){}
  vec2f(const vec2d&v){x=v.x;y=v.y;}
  vec2f(float x,float y):x(x),y(y){};
  void set_zero(){x=0.0f;y=0.0f;}
public:
  friend vec2f operator*(const vec2f&u,const float&v){return vec2f(u.x*v,u.y*v);}
  friend vec2f operator*(const float&u,const vec2f&v){return vec2f(u*v.x,u*v.y);}
  friend vec2f operator+(const vec2f&u,const vec2f&v){return vec2f(u.x+v.x,u.y+v.y);}
  friend vec2f operator-(const vec2f&u,const vec2f&v){return vec2f(u.x-v.x,u.y-v.y);}
public:
  void operator+=(const vec2d&v){x+=v.x;y+=v.y;}
  void operator-=(const vec2d&v){x-=v.x;y-=v.y;}
public:
  friend vec2f operator*(float u,const vec2f&v){return vec2f(u*v.x,u*v.y);}
  operator vec2d()const{return vec2d(x,y);}
};
//-------------------------------------------//
class vec2i{
public:
#define DEF_PRO_MANUAL_RESET()
#define DEF_PRO_MANUAL_CONSTRUCTOR()
#define DEF_PRO_MANUAL_MOVE()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(vec2i)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,x,SET,0,$)\
ADDVAR(int,y,SET,0,$)\
ADDEND()
//=====+>>>>>vec2i
#include "QapGenStruct.inl"
//<<<<<+=====vec2i
public:
  vec2i():x(0),y(0){}
  vec2i(int x,int y):x(x),y(y){};
  friend vec2i operator*(int u,const vec2i&v){return vec2i(u*v.x,u*v.y);}
  friend vec2i operator*(const vec2i&v,int u){return vec2i(u*v.x,u*v.y);}
  friend vec2i operator/(const vec2i&v,int d){return vec2i(v.x/d,v.y/d);}
  friend vec2i operator+(const vec2i&u,const vec2i&v){return vec2i(u.x+v.x,u.y+v.y);}
  friend vec2i operator-(const vec2i&u,const vec2i&v){return vec2i(u.x-v.x,u.y-v.y);}
  void operator+=(const vec2i&v){x+=v.x; y+=v.y;}
  void operator-=(const vec2i&v){x-=v.x; y-=v.y;}
  vec2i Mul(const vec2i&v)const{return vec2i(x*v.x,y*v.y);}
  int SqrMag(){return x*x+y*y;}
  float Mag(){return sqrt(float(x*x+y*y));}
  vec2i abs(){return vec2i(std::abs(x),std::abs(y));}
  bool dist_less(const vec2i&point,int dist){return (point-*this).SqrMag()<dist*dist;}
  operator vec2d()const{return vec2d(x,y);}
  operator vec2f()const{return vec2f(x,y);}
  vec2i operator+()const{return vec2i(+x,+y);}
  vec2i operator-()const{return vec2i(-x,-y);}
  friend bool operator==(const vec2i&u,const vec2i&v){return (u.x==v.x)&&(u.y==v.y);}
  friend bool operator!=(const vec2i&u,const vec2i&v){return (u.x!=v.x)||(u.y!=v.y);}
};
//-------------------------------------------//
struct Dip2i{
public:
  int a,b;
  Dip2i(int a,int b):a(a),b(b){};
  void Take(int x){a=min(a,x);b=max(b,x);}
  Dip2i Norm()const{return Dip2i(min(a,b),max(a,b));}
  int Mag()const{return b-a;}
public:
  struct Transform{
    float x,s;
    Transform(float x,float s):x(x),s(s){}
    Transform(const Dip2i&from,const Dip2i&to){s=float(to.Norm().Mag())/float(from.Norm().Mag());x=to.a-from.a;}
    float operator*(int v){return x+v*s;}
  };
};
//-------------------------------------------//
struct rot2f
{
public:
	float s;
  float c;
	rot2f():s(0.0f),c(1.0f){}
	explicit rot2f(float ang){set(ang);}
  void set(float ang){s=sinf(ang);c=cosf(ang);}
	void set_ident(){s=0.0f;c=1.0f;}
	float GetAng()const{return std::atan2(s,c);}
	vec2f GetXAxis()const{return vec2f(+c,+s);}
	vec2f GetYAxis()const{return vec2f(-s,+c);}
public:
  friend vec2f operator*(const rot2f&q,const vec2d&v){return vec2f(q.c*v.x-q.s*v.y,q.s*v.x+q.c*v.y);}
};/*
class transform2f{
public:
	vec2f p;
	rot2f q;
	transform2f(){}
	transform2f(const vec2f&pos,const rot2f&rot):p(pos),q(rot){}
	void set_ident(){p.set_zero();q.set_ident();}
	void set(const vec2f&pos,float ang){p=pos;q.set(ang);}
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v)
  {
	  float x=(+T.q.c*v.x-T.q.s*v.y)+T.p.x;
	  float y=(+T.q.s*v.x+T.q.c*v.y)+T.p.y;
	  return vec2f(x,y);
  }
};*/

class QapMat22{
public:
	vec2f col1;
  vec2f col2;
public:
	QapMat22():col1(1,0),col2(0,1){}
	QapMat22(const vec2f&c1,const vec2f&c2)
	{
		col1=c1;
		col2=c2;
	}
	QapMat22(float a11,float a12,float a21,float a22)
	{
		col1.x=a11;col1.y=a21;
		col2.x=a12;col2.y=a22;
	}
	explicit QapMat22(float ang)
	{
		float c=cosf(ang);float s=sinf(ang);
		col1.x=c; col2.x=-s;
		col1.y=s; col2.y=+c;
	}
	void set(const vec2f&c1,const vec2f&c2)
	{
		col1=c1;
		col2=c2;
	}
	void set(float ang)
	{
		float c=cosf(ang);float s=sinf(ang);
		col1.x=c; col2.x=-s;
		col1.y=s; col2.y=+c;
	}
	void set_ident()
	{
		col1.x = 1.0f; col2.x = 0.0f;
		col1.y = 0.0f; col2.y = 1.0f;
	}
	void set_zero()
	{
		col1.x = 0.0f; col2.x = 0.0f;
		col1.y = 0.0f; col2.y = 0.0f;
	}
	float GetAngle()const
	{
		return atan2(col1.y, col1.x);
	}
};

class transform2f{
public:
	vec2f p;
  QapMat22 r;
public:
	transform2f(){}
	transform2f(const vec2f&p,const QapMat22&r):p(p),r(r){}
	explicit transform2f(const vec2f&p):p(p){}
	void set_ident()
	{
    p.set_zero();
    r.set_ident();
	}
	void set(const vec2d&p,float ang)
	{
		this->p=p;
		this->r.set(ang);
	}
	float getAng()const
	{
		return atan2(r.col1.y,r.col1.x);
	}
public:
  friend vec2f operator*(const transform2f&T,const vec2f&v)
  {
    float x=(+T.r.col1.x*v.x+T.r.col2.x*v.y)+T.p.x;
	  float y=(+T.r.col1.y*v.x+T.r.col2.y*v.y)+T.p.y;
	  return vec2f(x,y);
  }
};
//-------------------------------------------//
const vec2d vec2d_zero(0.0,0.0);
const vec2i vec2i_zero(0,0);
const vec2f vec2f_zero(0,0);
const rot2f rot2f_ident(0.0);
//-------------------------------------------//
typedef vector<QapColor> ColorArray;
typedef ColorArray* PColorArray;
typedef vector<vec2d> PointArray;
typedef PointArray* PPointArray;
typedef vector<int> IntArray;
typedef IntArray* PIntArray;
//-------------------------------------------//
inline transform2f MakeZoomTransform(const vec2d&zoom)
{
  transform2f tmp(vec2f_zero,QapMat22(vec2f(zoom.x,0.f),vec2f(0.f,zoom.y)));
  return tmp;
}
//-------------------------------------------//
union TLine{
    struct{vec2d A,B;};
    struct{real ax,ay,bx,by;};
public:
  TLine(){}
  TLine(const vec2d&A,const vec2d&B):A(A),B(B){}
  TLine(const real&ax,const real&ay,const real&bx,const real&by):ax(ax),ay(ay),bx(bx),by(by){}
};
//-------------------------------------------//
inline vec2d Vec2dEx(const real&ang,const real&mag){return vec2d(cos(ang)*mag,sin(ang)*mag);}
inline real vec2d_cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
inline int round(const real&val){return int(val>=0?val+0.5:val-0.5);}//{return int(val);}
//inline POINT VToP(const vec2d&v){POINT P={round(v.x),round(v.y)}; return P;}
inline vec2d PToV(const POINT&v){return vec2d(v.x,v.y);}
//-------------------------------------------//
#ifdef BOX2D_H
  ///для матрицы X=b2MulXf(A,B) свойственно следующее b2Mul(A,b2Mul(B,p))==b2Mul(X,p) где p - b2Vec2
  inline b2Transform b2MulXf(b2Transform const&A,b2Transform const&B){return b2Transform(b2Mul(B,A.position),b2Mul(B.R,A.R));}
  inline vec2d UnMul(b2Transform&A,vec2d&V){b2Vec2 &m=A.R.col1;real r=1.0/(m.x*m.x+m.y*m.y);return r*vec2d(b2MulT(A,V));}
  inline b2Mat22 MulMat22(const b2Mat22&A,float f){return b2Mat22(vec2d(A.col1)*f,vec2d(A.col2)*f);}
  inline real b2GetZoom(b2Transform&xf){return vec2d(xf.R.col1).Mag();};
  inline b2Transform MakeZoomTransform(const vec2d&Zoom){b2Transform tmp(b2Vec2_zero,b2Mat22(b2Vec2(Zoom.x,0.f),b2Vec2(0.f,Zoom.y)));return tmp;}
#endif

  //<<<<<=====QapVec
#endif //DEF_BUILD_MACRO//
//-------------------------------------------//
//   {<|          04.08.2014           |>}   //
//-------------------------------------------//