//двухмерные афинные преобразования
#pragma once
#include "STDAFX.H"
#include "CMATRIX.H"
#include "math.h"
#include "lib.h"
CMatrix Translate2D(double x,double y);	//смещение
CMatrix Rotate2D(double fi);			//поворот
