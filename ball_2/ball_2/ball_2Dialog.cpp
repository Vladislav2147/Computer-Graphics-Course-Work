// ball_2Dialog.cpp: файл реализации
//

#include "stdafx.h"
#include "ball_2.h"
#include "ball_2Dialog.h"
#include "afxdialogex.h"
#include "MAINFRM.H"
#include "windef.h"

// диалоговое окно ball_2Dialog
IMPLEMENT_DYNAMIC(ball_2Dialog, CDialogEx)

ball_2Dialog::ball_2Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(ball_2Dialog::IDD, pParent)
	, show_trajectory(FALSE)
{

	EnableAutomation();
	char* str=new char[5];
	sp.PLight.RedimMatrix(3);
	sp.PView.RedimMatrix(3);
	sphere_params main;
	main.PLight.RedimMatrix(3);
	main.PView.RedimMatrix(3);
	main=((CMainFrame*)pParent->GetParentFrame())->sp;
	sp=main;
}
ball_2Dialog::~ball_2Dialog()
{
}

void ball_2Dialog::OnFinalRelease()
{
	// Когда будет освобождена последняя ссылка на объект автоматизации,
	// вызывается OnFinalRelease. Базовый класс автоматически
	// удалит объект. Перед вызовом базового класса добавьте
	// дополнительную очистку, необходимую вашему объекту.

	CDialogEx::OnFinalRelease();
}

void ball_2Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, con_A);
	DDX_Control(pDX, IDC_EDIT2, con_f);
	DDX_Control(pDX, IDC_EDIT3, con_F);
	DDX_Control(pDX, IDC_EDIT4, con_R);
	DDX_Control(pDX, IDC_RADIO1, con_light_diff);
	DDX_Control(pDX, IDC_RADIO2, con_light_mir);
	DDX_Control(pDX, IDC_SLIDER2, slider_pos_R);
	DDX_Control(pDX, IDC_SLIDER3, slider_pos_fi);
	DDX_Control(pDX, IDC_SLIDER4, slider_pos_q);
	DDX_Control(pDX, IDC_EDIT5, mon_pos_R);
	DDX_Control(pDX, IDC_EDIT6, mon_pos_fi);
	DDX_Control(pDX, IDC_EDIT7, mon_pos_q);
	DDX_Control(pDX, IDC_SLIDER5, slider_lig_R);
	DDX_Control(pDX, IDC_SLIDER6, slider_lig_fi);
	DDX_Control(pDX, IDC_SLIDER7, slider_lig_q);
	DDX_Control(pDX, IDC_EDIT8, mon_lig_R);
	DDX_Control(pDX, IDC_EDIT9, mon_lig_fi);
	DDX_Control(pDX, IDC_EDIT10, mon_lig_q);
	DDX_Control(pDX, IDC_EDIT21, color_R);
	DDX_Control(pDX, IDC_EDIT22, color_G);
	DDX_Control(pDX, IDC_EDIT23, color_B);
	DDX_Control(pDX, IDOK, btn_OK);
	DDX_Control(pDX, IDC_CHECK1, show_trajectory_checkbox);
	DDX_Check(pDX, IDC_CHECK1, show_trajectory);
}


BEGIN_MESSAGE_MAP(ball_2Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &ball_2Dialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &ball_2Dialog::OnCheckChangedState)
	ON_BN_CLICKED(IDC_RADIO1, &ball_2Dialog::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &ball_2Dialog::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &ball_2Dialog::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &ball_2Dialog::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ball_2Dialog::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &ball_2Dialog::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &ball_2Dialog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT21, &ball_2Dialog::OnEnChangeEdit21)
	ON_EN_CHANGE(IDC_EDIT22, &ball_2Dialog::OnEnChangeEdit22)
	ON_EN_CHANGE(IDC_EDIT23, &ball_2Dialog::OnEnChangeEdit23)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &ball_2Dialog::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &ball_2Dialog::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &ball_2Dialog::OnNMCustomdrawSlider4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &ball_2Dialog::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER6, &ball_2Dialog::OnNMCustomdrawSlider6)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER7, &ball_2Dialog::OnNMCustomdrawSlider7)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(ball_2Dialog, CDialogEx)
END_DISPATCH_MAP()

// Примечание: мы добавили поддержку для IID_Iball_2Dialog, чтобы обеспечить безопасную с точки зрения типов привязку
//  из VBA. Этот IID должен соответствовать GUID, связанному с 
//  disp-интерфейсом в файле .IDL.

// {1927A466-5445-4046-9C65-B96442F283F2}
static const IID IID_Iball_2Dialog =
{ 0x1927A466, 0x5445, 0x4046, { 0x9C, 0x65, 0xB9, 0x64, 0x42, 0xF2, 0x83, 0xF2 } };

BEGIN_INTERFACE_MAP(ball_2Dialog, CDialogEx)
	INTERFACE_PART(ball_2Dialog, IID_Iball_2Dialog, Dispatch)
END_INTERFACE_MAP()


// обработчики сообщений ball_2Dialog


void ball_2Dialog::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	sp.color_b = RGB(colorR, colorG, colorB);
	((CMainFrame*)GetParent())->sp = sp;
	((CMainFrame*)GetParent())->sp.timer = true;
	CDialogEx::OnOK();
}

void ball_2Dialog::OnCheckChangedState()
{

	sp.show_trajectory = show_trajectory_checkbox.GetCheck() & BST_CHECKED;

	// TODO: добавьте свой код обработчика уведомлений
}

void ball_2Dialog::OnBnClickedRadio1()
{
	con_light_diff.SetCheck(1);
	con_light_mir.SetCheck(0);
	sp.ball_light=false;
	// TODO: добавьте свой код обработчика уведомлений
}


void ball_2Dialog::OnBnClickedRadio2()
{
	con_light_diff.SetCheck(0);
	con_light_mir.SetCheck(1);
	sp.ball_light=true;
	// TODO: добавьте свой код обработчика уведомлений
}


void ball_2Dialog::OnBnClickedButton1()
{
	EnableAutomation();
	char* str=new char[5];
	sp.PLight.RedimMatrix(3);
	sp.PView.RedimMatrix(3);
	sphere_params main;
	main.PLight.RedimMatrix(3);
	main.PView.RedimMatrix(3);
	main=((CMainFrame*)GetParent())->sp;
	sp=main;
	itoa(main.tr_A,str,10);
	con_A.SetWindowTextA(str);
	itoa(main.tr_f*10,str,10);
	con_f.SetWindowTextA(str);
	itoa(main.tr_F,str,10);
	con_F.SetWindowTextA(str);
	itoa(main.main_R,str,10);
	con_R.SetWindowTextA(str);
	show_trajectory_checkbox.SetCheck((int)sp.show_trajectory);
	//цвета
	colorR = GetRValue(main.color_b);
	colorG = GetGValue(main.color_b);
	colorB = GetBValue(main.color_b);
	itoa(colorR, str, 10);
	color_R.SetWindowTextA(str);
	itoa(colorG, str, 10);
	color_G.SetWindowTextA(str);
	itoa(colorB, str, 10);
	color_B.SetWindowTextA(str);


	if (main.ball_light) con_light_mir.SetCheck(1);
	else con_light_diff.SetCheck(1);
	//положение наблюдателя
	slider_pos_R.SetRange(10,main.OX);
	slider_pos_R.SetPos(main.PView(0));
	itoa(slider_pos_R.GetPos(),str,10);
	mon_pos_R.SetWindowTextA(str);
	slider_pos_fi.SetRange(0,360);
	slider_pos_fi.SetPos(main.PView(1));
	itoa(slider_pos_fi.GetPos(),str,10);
	mon_pos_fi.SetWindowTextA(str);
	slider_pos_q.SetRange(0,360);
	slider_pos_q.SetPos(main.PView(2));
	itoa(slider_pos_q.GetPos(),str,10);
	mon_pos_q.SetWindowTextA(str);
	//положение источника света
	slider_lig_R.SetRange(0,main.OX);
	slider_lig_R.SetPos(main.PLight(0));
	itoa(slider_lig_R.GetPos(),str,10);
	mon_lig_R.SetWindowTextA(str);
	slider_lig_fi.SetRange(0,360);
	slider_lig_fi.SetPos(main.PLight(1));
	itoa(slider_lig_fi.GetPos(),str,10);
	mon_lig_fi.SetWindowTextA(str);
	slider_lig_q.SetRange(0,360);
	slider_lig_q.SetPos(main.PLight(2));
	itoa(slider_lig_q.GetPos(),str,10);
	mon_lig_q.SetWindowTextA(str);
	// TODO: добавьте свой код обработчика уведомлений
}


void ball_2Dialog::OnEnChangeEdit1()
{
	int buf;
	char* str=new char[5];
	con_A.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		sp.tr_A = 1;
		con_A.SetWindowTextA("1");
	}
	else if (buf > 100)
	{
		sp.tr_A = 100;
		con_A.SetWindowTextA("100");
	}
	else sp.tr_A = buf;
}


void ball_2Dialog::OnEnChangeEdit2()
{
	int buf;
	char* str=new char[5];
	con_f.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		sp.tr_f = 0.1;
		con_f.SetWindowTextA("1");
	}
	else if (buf > 10)
	{
		sp.tr_f = 1;
		con_f.SetWindowTextA("10");
	}
	else
		sp.tr_f = (double)buf/10;
}


void ball_2Dialog::OnEnChangeEdit3()
{
	int buf;
	char* str=new char[5];
	con_F.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		sp.tr_F = 1;
		con_F.SetWindowTextA("1");
	}
	else if (buf > 9)
	{
		sp.tr_F = 9;
		con_F.SetWindowTextA("9");
	}
	else sp.tr_F = buf;
}


void ball_2Dialog::OnEnChangeEdit4()
{
	int buf;
	char* str=new char[5];
	con_R.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf <= 0)
	{
		sp.main_R = 1;
		con_R.SetWindowTextA("1");
	}
	else if (buf > 150)
	{
		sp.main_R = 150;
		con_R.SetWindowTextA("150");
	}
	else sp.main_R = buf;
}

void ball_2Dialog::OnEnChangeEdit21()
{
	int buf;
	char* str = new char[5];
	color_R.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		colorR = 0;
		color_R.SetWindowTextA("0");
	}
	else if (buf > 255)
	{
		colorR = 255;
		color_R.SetWindowTextA("255");
	}
	else colorR = buf;
}

void ball_2Dialog::OnEnChangeEdit22()
{
	int buf;
	char* str = new char[5];
	color_G.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		colorG = 0;
		color_G.SetWindowTextA("0");
	}
	else if (buf > 255)
	{
		colorG = 255;
		color_G.SetWindowTextA("255");
	}
	else colorG = buf;
}

void ball_2Dialog::OnEnChangeEdit23()
{
	int buf;
	char* str = new char[5];
	color_B.GetWindowTextA(str, 5);
	buf = atoi(str);
	if (buf < 0)
	{
		colorB = 0;
		color_B.SetWindowTextA("0");
	}
	else if (buf > 255)
	{
		colorB = 255;
		color_B.SetWindowTextA("255");
	}
	else colorB = buf;
}


void ball_2Dialog::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_pos_R.GetPos(),str,10);
	mon_pos_R.SetWindowTextA(str);
	sp.PView(0)=slider_pos_R.GetPos();
	*pResult = 0;
}


void ball_2Dialog::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_pos_fi.GetPos(),str,10);
	mon_pos_fi.SetWindowTextA(str);
	sp.PView(1)=slider_pos_fi.GetPos();
	*pResult = 0;
}


void ball_2Dialog::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_pos_q.GetPos(),str,10);
	mon_pos_q.SetWindowTextA(str);
	sp.PView(2)=slider_pos_q.GetPos();
	*pResult = 0;
}


void ball_2Dialog::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_lig_R.GetPos(),str,10);
	mon_lig_R.SetWindowTextA(str);
	sp.PLight(0)=slider_lig_R.GetPos();
	*pResult = 0;
}


void ball_2Dialog::OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_lig_fi.GetPos(),str,10);
	mon_lig_fi.SetWindowTextA(str);
	sp.PLight(1)=slider_lig_fi.GetPos();
	*pResult = 0;
}


void ball_2Dialog::OnNMCustomdrawSlider7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(slider_lig_q.GetPos(),str,10);
	mon_lig_q.SetWindowTextA(str);
	sp.PLight(2)=slider_lig_q.GetPos();
	*pResult = 0;
}
