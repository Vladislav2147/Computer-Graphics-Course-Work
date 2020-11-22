#include "StdAfx.h"
#include "Athena2D.h"

CMatrix Translate2D(double x,double y){
	CMatrix m(3,3);
	m(0,0)=1;m(1,1)=1;m(2,2)=1;
	m(0,2)=x;
	m(1,2)=y;
	return m;
}
CMatrix Rotate2D(double fi){
	CMatrix m(3,3);
	double fi_r=fi*pi/180.0;
	m(0,0)=cos(fi_r);
	m(1,1)=cos(fi_r);
	m(2,2)=1;
	m(0,1)=-sin(fi_r);
	m(1,0)=sin(fi_r);
	return m;
}