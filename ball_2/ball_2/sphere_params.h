#pragma once
#include "CMATRIX.H"
struct sphere_params{
	COLORREF color_p,color_n,color_s,color_b;				//цвета
	int OX,OY,OZ;											//параметры осей координат
	int main_R,tr_A, tr_density;					//параматры траектории
	double tr_F, tr_f;										//частота колебаний
	int ball_R;												//радиус шара
	bool ball_light;										//модель освещения
	CMatrix PView,PLight;									//положения источника освещения и наблюдателя
	bool timer; int timer_interval;							//эмитация полета
	int ball_pos;											//положение шара на траектории
};