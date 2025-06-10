#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#include <d3d9.h>
//-------------------------------------------//
struct QapMat4:public D3DMATRIX
{
public:
	QapMat4(){}
	QapMat4(
     const float m00, const float m01, const float m02, const float m03,
		 const float m10, const float m11, const float m12, const float m13,
		 const float m20, const float m21, const float m22, const float m23,
		 const float m30, const float m31, const float m32, const float m33
  )
  {
    #define f(a,b){m[a][b]=m##a##b;}
    #define F(a){f(a,0);f(a,1);f(a,2);f(a,3);};
      F(0);F(1);F(2);F(3);
    #undef F
    #undef f
	}
public:
  friend QapMat4 operator+(const QapMat4&m,const QapMat4&n){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=m.m[i][j]+n.m[i][j]; return O;
  }
  friend QapMat4 operator-(const QapMat4&m,const QapMat4&n){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=m.m[i][j]-n.m[i][j]; return O;
  }
  friend QapMat4 operator-(const QapMat4&m){
	  QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=-m.m[i][j]; return O;
  }
  friend QapMat4 operator*(const QapMat4&m,const QapMat4&n){
	  #define rcDot4(r,c)(m.m[r][0]*n.m[0][c]+m.m[r][1]*n.m[1][c]+m.m[r][2]*n.m[2][c]+m.m[r][3]*n.m[3][c])
	  return QapMat4(
		  rcDot4(0,0),rcDot4(0,1),rcDot4(0,2),rcDot4(0,3),
		  rcDot4(1,0),rcDot4(1,1),rcDot4(1,2),rcDot4(1,3),
		  rcDot4(2,0),rcDot4(2,1),rcDot4(2,2),rcDot4(2,3),
		  rcDot4(3,0),rcDot4(3,1),rcDot4(3,2),rcDot4(3,3)
    );
	  #undef rcDot
  }
  friend QapMat4 operator*(const QapMat4 &m,float x){
    QapMat4 O; for(int i=0;i<4;i++)for(int j=0;j<4;j++)O.m[i][j]=x*m.m[i][j]; return O;
  }
};
//-------------------------------------------//
inline QapMat4 Transpose(const QapMat4&m)
{
	return QapMat4(
		m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
		m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
		m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
		m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
  );
}
//-------------------------------------------//
inline QapMat4 RotateZ(float angle)
{
  float c=cosf(angle),s=sinf(angle);
  return QapMat4(
    +c,+s,+0,+0,
    -s,+c,+0,+0,
    +0,+0,+1,+0,
    +0,+0,+0,+1
  );
}
//-------------------------------------------//
inline QapMat4 Translate(const float x,const float y,const float z)
{
  return QapMat4(
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    x,y,z,1
  );
}
//-------------------------------------------//
inline QapMat4 Scale(const float x,const float y,const float z)
{
  return QapMat4(
    x,0,0,0,
    0,y,0,0,
    0,0,z,0,
    0,0,0,1
  );
}
//-------------------------------------------//
inline QapMat4 Identity4()
{
	return QapMat4(
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  );
}
//-------------------------------------------//
//   {<|          30.01.2012           |>}   //
//-------------------------------------------//