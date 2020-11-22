
// ball_2.h : главный файл заголовка для приложения ball_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Cball_2App:
// О реализации данного класса см. ball_2.cpp
//

class Cball_2App : public CWinApp
{
public:
	Cball_2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cball_2App theApp;
