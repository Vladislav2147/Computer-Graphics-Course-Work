//трехмерные афинные преобразования
#pragma once
#include "STDAFX.H"
#include "CMATRIX.H"
#include "math.h"
#include "lib.h"
CMatrix Translate3D(double x,double y,double z);	//смещение
CMatrix Rotate3Dx(double fi);						//поворот вокруг оси ОХ
CMatrix Rotate3Dy(double fi);						//поворот вокруг оси ОY
CMatrix Rotate3Dz(double fi);						//поворот вокруг оси ОZ
