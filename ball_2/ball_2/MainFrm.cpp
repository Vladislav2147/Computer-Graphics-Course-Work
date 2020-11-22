
// MainFrm.cpp : ���������� ������ CMainFrame
//

#include "stdafx.h"
#include "ball_2.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// ��������/����������� CMainFrame

CMainFrame::CMainFrame()
{
	// TODO: �������� ��� ������������� �����
	//������������� ��������
	sp.ball_light=false;
	sp.color_b = RGB(255,0,0);
	sp.color_s = RGB(100,60,60);
	sp.color_n = RGB(200,0,0);
	sp.color_p = RGB(0,200,0);
	sp.OX = sp.OY = sp.OZ = 250;
	sp.main_R = 100;
	sp.tr_A = 30;
	sp.tr_F = 3;
	sp.tr_f = .5;
	sp.tr_density = 360;
	sp.ball_R = 7;
	sp.PView.RedimMatrix(3);
	sp.PView(0)=10;sp.PView(1)=30;sp.PView(2)=60;
	sp.PLight.RedimMatrix(3);
	sp.PLight(0)=20;sp.PLight(1)=30;sp.PLight(2)=60;
	sp.timer=true;
	sp.timer_interval=100;
	sp.ball_pos=0;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ������� ������������� ��� ���������� ������� ������� �����
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�� ������� ������� ���� �������������\n");
		return -1;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// ����������� CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// ����������� ��������� CMainFrame

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// �������� ������ ���� �������������
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ��������� ������ � ������������� ��� ���������� �������
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// � ��������� ������ ����������� ��������� �� ���������
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
