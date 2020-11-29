//операции по преобразованию координат между различными СК и другие операции
#pragma once
#include "stdafx.h"
#include "math.h"
#include "cmatrix.h"
#include "lib.h"
#include "Athena3D.h"

//векторное произведение векторов
CMatrix VectorMult(CMatrix V1,CMatrix V2);			

//скалярное произведение векторов
double ScalarMult(CMatrix V1,CMatrix V2);			

//косинус угла между векторами
double cosViV2(CMatrix V1,CMatrix V2);				

//преобразование координат из сферической в декартову систему
CMatrix SphereToCart(CMatrix DView);				

//преобразование координат из мировой в видовую систему
CMatrix CreateViewCoord(double theta,double fi,double R);

//преобразование координат из видовой в оконную систему 
CMatrix SpaceToWindow(CRectD& rs, CRect& rw);

