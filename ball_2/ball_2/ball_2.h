
// ball_2.h : ������� ���� ��������� ��� ���������� ball_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Cball_2App:
// � ���������� ������� ������ ��. ball_2.cpp
//

class Cball_2App : public CWinApp
{
public:
	Cball_2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cball_2App theApp;
