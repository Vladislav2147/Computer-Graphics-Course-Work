//�������� �� �������������� ��������� ����� ���������� �� � ������ ��������
#pragma once
#include "stdafx.h"
#include "math.h"
#include "cmatrix.h"
#include "lib.h"
#include "Athena3D.h"

//��������� ������������ ��������
CMatrix VectorMult(CMatrix V1,CMatrix V2);			

//��������� ������������ ��������
double ScalarMult(CMatrix V1,CMatrix V2);			

//������� ���� ����� ���������
double cosViV2(CMatrix V1,CMatrix V2);				

//�������������� ��������� �� ����������� � ��������� �������
CMatrix SphereToCart(CMatrix DView);				

//�������������� ��������� �� ������� � ������� �������
CMatrix CreateViewCoord(double theta,double fi,double R);

//�������������� ��������� �� ������� � ������� ������� 
CMatrix SpaceToWindow(CRectD& rs, CRect& rw);

