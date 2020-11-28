//смотрел
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "ball_2.h"
#include "ChildView.h"
#include "MainFrm.h"
#include "imagelib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
sphere_params main;
CChildView::CChildView()
{
	
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Param, DialogMode)
	ON_COMMAND(ID_SAVE, SaveImage)
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{

	CRect Rect;
	this->GetClientRect(Rect);
	rw.SetRect(Rect.left, Rect.top, Rect.right, Rect.bottom);
	step = 30;

	CPaintDC dc(this); // контекст устройства для рисования
	main.PLight.RedimMatrix(3);
	main.PView.RedimMatrix(3);
	//получение настроек
	main=((CMainFrame*)GetParentFrame())->sp;
	//применение настроек
	sphere.MV_and_MW(main.OX,main.OY,rw,main.PView);
	sphere.DrawOXYZ(dc,main.OX,main.OY,main.OZ,main.PView,main.color_p,main.color_n);
	if (main.show_trajectory) 
	{
		sphere.DrawTraector(dc, main.main_R, main.tr_A, main.tr_F, main.tr_f, main.tr_density, main.PView, main.color_s);
	}
	sphere.SetPos(main.ball_pos);
	if(main.ball_light==false)
		sphere.DrawD(dc,main.ball_R,main.PView,main.PLight,main.color_b);
	else if(main.ball_light==true)
		sphere.DrawZ(dc,main.ball_R,main.PView,main.PLight,main.color_b);
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}
void CChildView::OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags)
{

	if(nChar==37){		//влево
		((CMainFrame*)GetParentFrame())->sp.PView(1)+=step;
		Invalidate();
	}
	else if(nChar==39){	//вправо
		((CMainFrame*)GetParentFrame())->sp.PView(1)-=step;
		Invalidate();
	}
	else if(nChar==38){	//вверх
		((CMainFrame*)GetParentFrame())->sp.PView(2)-=step;
		Invalidate();
	}
	else if(nChar==40){ //вниз
		((CMainFrame*)GetParentFrame())->sp.PView(2)+=step;
		Invalidate();
	}
	else if(nChar==65){	//A
		((CMainFrame*)GetParentFrame())->sp.PLight(1)-=step;
		Invalidate();
	}
	else if(nChar==68){	//D
		((CMainFrame*)GetParentFrame())->sp.PLight(1)+=step;
		Invalidate();
	}
	else if(nChar==87){	//W
		((CMainFrame*)GetParentFrame())->sp.PLight(2)-=step;
		Invalidate();
	}
	else if(nChar==83){ //S
		((CMainFrame*)GetParentFrame())->sp.PLight(2)+=step;
		Invalidate();
	}
	else if(nChar==79){	//O
		((CMainFrame*)GetParentFrame())->sp.ball_light=true;
		Invalidate();
	}
	else if(nChar==80){ //P
		((CMainFrame*)GetParentFrame())->sp.ball_light=false;
		Invalidate();
	}
	else if(nChar==32){	//пробел
		KillTimer(1);	//остановка таймера
		ball_2Dialog b3d(this);
		if(IDOK==b3d.DoModal()){
			if(((CMainFrame*)GetParentFrame())->sp.timer==true){
				SetTimer(1,((CMainFrame*)GetParentFrame())->sp.timer_interval,NULL);	//запуск таймера
			}
			else if(((CMainFrame*)GetParentFrame())->sp.timer==false){
				KillTimer(1);	//остановка таймера
			}
			Invalidate();
		}
	}
}
void CChildView::DialogMode(){
	KillTimer(1);
	((CMainFrame*)GetParentFrame())->sp.ball_pos = 1;
	ball_2Dialog b3d(this);
	if(IDOK==b3d.DoModal()){
		if(((CMainFrame*)GetParentFrame())->sp.timer==true){
			SetTimer(1,((CMainFrame*)GetParentFrame())->sp.timer_interval,NULL);	//запуск таймера
		}
		else if(((CMainFrame*)GetParentFrame())->sp.timer==false){
			KillTimer(1);	//остановка таймера
		}
		Invalidate();
	}
}
void CChildView::OnTimer(UINT_PTR id) 
{
	if(main.ball_pos < (int)2*pi/((pi/main.tr_density)*main.tr_F)-2)
		((CMainFrame*)GetParentFrame())->sp.ball_pos+=2;			
	else ((CMainFrame*)GetParentFrame())->sp.ball_pos = 1;
	Invalidate();
}
void CChildView::SaveImage()
{ // функция для сохранения рабочей области
	CFileDialog fileDialog(FALSE,NULL,"ball_2.bmp");	
	fileDialog.m_ofn.lpstrFilter = "bmp images\0*.bmp\0\0";
	int result = fileDialog.DoModal();	
	if (result==IDOK)	
	{ 
		if(ClientToBmp(m_hWnd,fileDialog.GetPathName().GetBuffer()) == 0)
			AfxMessageBox("Saved");
		else
			AfxMessageBox("Error");

	}
}