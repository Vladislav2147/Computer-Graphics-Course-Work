//смотрел
// ChildView.h : интерфейс класса CChildView
//


#pragma once
#include "cmatrix.h"
#include "lib.h"
#include "MyGDI.h"
#include "Sphere.h"
#include "ball_2.h"
#include "Ball_2Dialog.h"

// окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
CRect rw;
	int step;
	double r,R;
	CSphere sphere;
// Операции
public:

// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	//движение при включенном таймере
	afx_msg void OnTimer(UINT_PTR id);

	//прорисока в зависимости от модели освещения
	afx_msg void OnPaint();

	//обработка нажатий клавиш
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags);

	//вызов диалога настроек
	afx_msg void DialogMode();

public:
	//сохранение картинкой
	afx_msg void CChildView::SaveImage();

	DECLARE_MESSAGE_MAP()
};

