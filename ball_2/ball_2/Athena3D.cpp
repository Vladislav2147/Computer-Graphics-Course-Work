#include "StdAfx.h"
#include "CMATRIX.H"
#include "math.h"
#include "lib.h"

CMatrix Translate3D(double x,double y,double z){
	CMatrix m(4,4);
	m(0,0)=1;m(1,1)=1;m(2,2)=1;m(3,3)=1;
	m(0,3)=x;
	m(1,3)=y;
	m(2,3)=z;
	return m;
}
CMatrix Rotate3Dz(double fi){
	CMatrix m(4,4);
	double fi_r=fi*pi/180.0;
	m(0,0)=cos(fi_r);
	m(1,1)=cos(fi_r);
	m(2,2)=1;m(3,3)=1;
	m(0,1)=-sin(fi_r);
	m(1,0)=sin(fi_r);
	return m;
}
CMatrix Rotate3Dx(double fi){
	CMatrix m(4,4);
	double fi_r=fi*pi/180.0;
	m(1,1)=cos(fi_r);
	m(2,2)=cos(fi_r);
	m(0,0)=1;m(3,3)=1;
	m(1,2)=-sin(fi_r);
	m(2,1)=sin(fi_r);
	return m;
}
CMatrix Rotate3Dy(double fi){
	CMatrix m(4,4);
	double fi_r=fi*pi/180.0;
	m(0,0)=cos(fi_r);
	m(2,2)=cos(fi_r);
	m(1,1)=1;m(3,3)=1;
	m(0,2)=-sin(fi_r);
	m(2,0)=sin(fi_r);
	return m;
}
