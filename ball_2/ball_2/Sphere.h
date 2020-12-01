//������ ��������� ���� � ��� ���������� � ������ ��������� ������ ���������
#pragma once
#include "cmatrix.h"
#include "lib.h"
#include "MyGDI.h"
class CSphere
{
	CMatrix MV,MW,S;	//������� ��������� ����� �� � ���������� ���� �� ����������-������� � ������ ������� �������
	int current_pos;	//����� �������� ��������� ����
public:
	//������ ������ ��������� �� ������� � ������� � �� ������� � ������� ��
	void MV_and_MW(double OX,double OY,CRect& RW,CMatrix& PView);

	//���������� ���� ���������
	void DrawOXYZ(CDC& dc,double OX,double OY,double OZ,CMatrix& PView,COLORREF color1,COLORREF color2);

	//���������� ����������
	void DrawTraector(CDC& dc, double Radius, double tr_A, double tr_F, double tr_f, double density, CMatrix& PView, COLORREF color, bool show_trajectory);

	//���������� ���� ��� ������������ ������ ���������
	void DrawD(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color);

	//���������� ���� ��� ���������� ������ ���������
	void DrawZ(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color);
	
	//����� ��������� ���� �� ����������
	void SetPos(int pos);

	//��������� ������ �������� ��������� ���� �� ����������
	int GetPos();
	CSphere(void);
	~CSphere(void);
};

