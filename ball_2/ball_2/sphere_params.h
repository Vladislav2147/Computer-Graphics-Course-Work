#pragma once
#include "CMATRIX.H"
struct sphere_params{
	COLORREF color_p,color_n,color_s,color_b;				//�����
	int OX,OY,OZ;											//��������� ���� ���������
	int main_R,tr_A, tr_density;					//��������� ����������
	double tr_F, tr_f;										//������� ���������
	int ball_R;												//������ ����
	bool ball_light;										//������ ���������
	CMatrix PView,PLight;									//��������� ��������� ��������� � �����������
	bool timer; int timer_interval;							//�������� ������
	int ball_pos;											//��������� ���� �� ����������
};