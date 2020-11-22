//�������
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "cmatrix.h"
#include "lib.h"
#include "MyGDI.h"
#include "Sphere.h"
#include "ball_2.h"
#include "Ball_2Dialog.h"

// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:
CRect rw;
	int step;
	double r,R;
	CSphere sphere;
// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	//�������� ��� ���������� �������
	afx_msg void OnTimer(UINT_PTR id);

	//��������� � ����������� �� ������ ���������
	afx_msg void OnPaint();

	//��������� ������� ������
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags);

	//����� ������� ��������
	afx_msg void DialogMode();

public:
	//���������� ���������
	afx_msg void CChildView::SaveImage();

	DECLARE_MESSAGE_MAP()
};

