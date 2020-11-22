//расчет координат шара и его прорисовка с учетом выбранной модели освещения
#pragma once
#include "cmatrix.h"
#include "lib.h"
#include "MyGDI.h"
class CSphere
{
	CMatrix MV,MW,S;	//матрицы пересчета между СК и координаты шара на траектории-спирали в разные моменты времени
	int current_pos;	//номер текущего положения шара
public:
	//расчет матриц пересчета из мировой в видовую и из видовой в оконную СК
	void MV_and_MW(double OX,double OY,CRect& RW,CMatrix& PView);

	//прорисовка осей координат
	void DrawOXYZ(CDC& dc,double OX,double OY,double OZ,CMatrix& PView,COLORREF color1,COLORREF color2);

	//прорисовка траектории
	void DrawTraector(CDC& dc,double Radius,double tr_A,double tr_F,double tr_f,double density, CMatrix& PView,COLORREF color1);

	//прорисовка шара при диффузионной модели освещения
	void DrawD(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color);

	//прорисовка шара при зеркальной модели освещения
	void DrawZ(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color);
	
	//смена положения шара на траектории
	void SetPos(int pos);

	//получение номера текущего положения шара на траектории
	int GetPos();
	CSphere(void);
	~CSphere(void);
};

