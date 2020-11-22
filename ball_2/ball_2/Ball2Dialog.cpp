// Ball3Dialog.cpp: файл реализации
//

#include "stdafx.h"
#include "ball_2.h"
#include "Ball2Dialog.h"
#include "afxdialogex.h"
#include "MAINFRM.H"

// диалоговое окно Ball3Dialog

IMPLEMENT_DYNAMIC(Ball3Dialog, CDialogEx)

	Ball3Dialog::Ball3Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ball3Dialog::IDD, pParent)
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

Ball3Dialog::~Ball3Dialog()
{
}

void Ball3Dialog::OnFinalRelease()
{
	// Когда будет освобождена последняя ссылка на объект автоматизации,
	// вызывается OnFinalRelease. Базовый класс автоматически
	// удалит объект. Перед вызовом базового класса добавьте
	// дополнительную очистку, необходимую вашему объекту.

	CDialogEx::OnFinalRelease();
}

void Ball3Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, color_positive);
	DDX_Control(pDX, IDC_PROGRESS2, color_negative);
	DDX_Control(pDX, IDC_PROGRESS3, color_spiral);
	DDX_Control(pDX, IDC_PROGRESS4, color_ball);
	DDX_Control(pDX, IDC_SLIDER1, OX_slider);
	DDX_Control(pDX, IDC_EDIT1, OX_text);
	DDX_Control(pDX, IDC_SLIDER2, OY_slider);
	DDX_Control(pDX, IDC_SLIDER3, OZ_slider);
	DDX_Control(pDX, IDC_EDIT2, OY_text);
	DDX_Control(pDX, IDC_EDIT3, OZ_text);
	DDX_Control(pDX, IDC_SLIDER4, spiral_R_slider);
	DDX_Control(pDX, IDC_SLIDER5, spiral_zstep_slider);
	DDX_Control(pDX, IDC_SLIDER6, spiral_znum_slider);
	DDX_Control(pDX, IDC_SLIDER7, spiral_density_slider);
	DDX_Control(pDX, IDC_EDIT4, spiral_R_text);
	DDX_Control(pDX, IDC_EDIT5, spiral_zstep_text);
	DDX_Control(pDX, IDC_EDIT6, spiral_znum_text);
	DDX_Control(pDX, IDC_EDIT7, spiral_density_text);
	DDX_Control(pDX, IDC_SLIDER8, ball_R_slider);
	DDX_Control(pDX, IDC_RADIO1, light_radio1);
	DDX_Control(pDX, IDC_RADIO2, light_rabio2);
	DDX_Control(pDX, IDC_SLIDER15, ball_pos_slider);
	DDX_Control(pDX, IDC_EDIT8, ball_R_text);
	DDX_Control(pDX, IDC_EDIT15, ball_pos_text);
	DDX_Control(pDX, IDC_SLIDER9, light_R_slider);
	DDX_Control(pDX, IDC_SLIDER10, light_fi_slider);
	DDX_Control(pDX, IDC_SLIDER11, light_q_slider);
	DDX_Control(pDX, IDC_EDIT9, light_R_text);
	DDX_Control(pDX, IDC_EDIT10, light_fi_text);
	DDX_Control(pDX, IDC_EDIT11, light_q_text);
	DDX_Control(pDX, IDC_SLIDER12, eye_R_slider);
	DDX_Control(pDX, IDC_SLIDER13, eye_fi_slider);
	DDX_Control(pDX, IDC_SLIDER14, eye_q_slider);
	DDX_Control(pDX, IDC_EDIT12, eye_R_text);
	DDX_Control(pDX, IDC_EDIT13, eye_fi_text);
	DDX_Control(pDX, IDC_EDIT14, eye_q_text);
	DDX_Control(pDX, IDC_CHECK1, timer_checkbox);
	DDX_Control(pDX, IDC_SLIDER16, timer_slider);
	DDX_Control(pDX, IDC_EDIT16, timer_text);
}


BEGIN_MESSAGE_MAP(Ball3Dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &Ball3Dialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &Ball3Dialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Ball3Dialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &Ball3Dialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Ball3Dialog::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Ball3Dialog::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Ball3Dialog::OnNMCustomdrawSlider2)
	ON_BN_CLICKED(IDC_BUTTON5, &Ball3Dialog::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT1, &Ball3Dialog::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Ball3Dialog::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &Ball3Dialog::OnEnChangeEdit3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &Ball3Dialog::OnNMCustomdrawSlider4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &Ball3Dialog::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &Ball3Dialog::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER6, &Ball3Dialog::OnNMCustomdrawSlider6)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER7, &Ball3Dialog::OnNMCustomdrawSlider7)
	ON_EN_CHANGE(IDC_EDIT4, &Ball3Dialog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &Ball3Dialog::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &Ball3Dialog::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &Ball3Dialog::OnEnChangeEdit7)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER8, &Ball3Dialog::OnNMCustomdrawSlider8)
	ON_EN_CHANGE(IDC_EDIT8, &Ball3Dialog::OnEnChangeEdit8)
	ON_BN_CLICKED(IDC_RADIO1, &Ball3Dialog::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Ball3Dialog::OnBnClickedRadio2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER16, &Ball3Dialog::OnNMCustomdrawSlider16)
	ON_EN_CHANGE(IDC_EDIT16, &Ball3Dialog::OnEnChangeEdit16)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER9, &Ball3Dialog::OnNMCustomdrawSlider9)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER15, &Ball3Dialog::OnNMCustomdrawSlider15)
	ON_EN_CHANGE(IDC_EDIT15, &Ball3Dialog::OnEnChangeEdit15)
	ON_EN_CHANGE(IDC_EDIT9, &Ball3Dialog::OnEnChangeEdit9)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER10, &Ball3Dialog::OnNMCustomdrawSlider10)
	ON_EN_CHANGE(IDC_EDIT10, &Ball3Dialog::OnEnChangeEdit10)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER11, &Ball3Dialog::OnNMCustomdrawSlider11)
	ON_EN_CHANGE(IDC_EDIT11, &Ball3Dialog::OnEnChangeEdit11)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER12, &Ball3Dialog::OnNMCustomdrawSlider12)
	ON_EN_CHANGE(IDC_EDIT12, &Ball3Dialog::OnEnChangeEdit12)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER13, &Ball3Dialog::OnNMCustomdrawSlider13)
	ON_EN_CHANGE(IDC_EDIT13, &Ball3Dialog::OnEnChangeEdit13)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER14, &Ball3Dialog::OnNMCustomdrawSlider14)
	ON_EN_CHANGE(IDC_EDIT14, &Ball3Dialog::OnEnChangeEdit14)
	ON_BN_CLICKED(IDC_CHECK1, &Ball3Dialog::OnBnClickedCheck1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Ball3Dialog, CDialogEx)
END_DISPATCH_MAP()

// Примечание: мы добавили поддержку для IID_IBall3Dialog, чтобы обеспечить безопасную с точки зрения типов привязку
//  из VBA. Этот IID должен соответствовать GUID, связанному с 
//  disp-интерфейсом в файле .IDL.

// {41FECAA9-EB8B-4B34-A229-4F372E45F583}
static const IID IID_IBall3Dialog =
{ 0x41FECAA9, 0xEB8B, 0x4B34, { 0xA2, 0x29, 0x4F, 0x37, 0x2E, 0x45, 0xF5, 0x83 } };

BEGIN_INTERFACE_MAP(Ball3Dialog, CDialogEx)
	INTERFACE_PART(Ball3Dialog, IID_IBall3Dialog, Dispatch)
END_INTERFACE_MAP()


// обработчики сообщений Ball3Dialog

void Ball3Dialog::OnBnClickedButton5()
{
	//загрузка настроек
	sphere_params main;
	main.PLight.RedimMatrix(3);
	main.PView.RedimMatrix(3);
	main=((CMainFrame*)GetParentFrame())->sp;
	char* str=new char[5];
	//цвета
	color_positive.SetBkColor(main.color_p);
	color_negative.SetBkColor(main.color_n);
	color_spiral.SetBkColor(main.color_s);
	color_ball.SetBkColor(main.color_b);
	//оси
	OX_slider.SetRange(10,1000);
	OX_slider.SetPos(main.OX);
	itoa(OX_slider.GetPos(),str,10);
	OX_text.SetWindowTextA(str);
	OY_slider.SetRange(10,1000);
	OY_slider.SetPos(main.OY);
	itoa(OY_slider.GetPos(),str,10);
	OY_text.SetWindowTextA(str);
	OZ_slider.SetRange(10,1000);
	OZ_slider.SetPos(main.OZ);
	itoa(OZ_slider.GetPos(),str,10);
	OZ_text.SetWindowTextA(str);
	//траектория
	spiral_R_slider.SetRange(10,main.OX);
	spiral_R_slider.SetPos(main.spiral_R);
	itoa(spiral_R_slider.GetPos(),str,10);
	spiral_R_text.SetWindowTextA(str);
	spiral_zstep_slider.SetRange(0,main.OZ/main.spiral_znum);
	spiral_zstep_slider.SetPos(main.spiral_zstep);
	itoa(spiral_zstep_slider.GetPos(),str,10);
	spiral_zstep_text.SetWindowTextA(str);
	spiral_znum_slider.SetRange(1,main.OZ/10);
	spiral_znum_slider.SetPos(main.spiral_znum);
	itoa(spiral_znum_slider.GetPos(),str,10);
	spiral_znum_text.SetWindowTextA(str);
	spiral_density_slider.SetRange(4,32);
	spiral_density_slider.SetPos(main.spiral_density);
	itoa(spiral_density_slider.GetPos(),str,10);
	spiral_density_text.SetWindowTextA(str);
	//шар
	ball_R_slider.SetRange(1,main.OX/10);
	ball_R_slider.SetPos(main.ball_R);
	itoa(ball_R_slider.GetPos(),str,10);
	ball_R_text.SetWindowTextA(str);
	ball_pos_slider.SetRange(0,main.spiral_znum*main.spiral_density*2-1);
	ball_pos_slider.SetPos(main.ball_pos);
	itoa(ball_pos_slider.GetPos(),str,10);
	ball_pos_text.SetWindowTextA(str);
	if(main.ball_light==false){
		light_radio1.SetCheck(1);
		light_rabio2.SetCheck(0);
	}
	else{
		light_rabio2.SetCheck(1);
		light_radio1.SetCheck(0);
	}
	//источник света
	light_R_slider.SetRange(0,main.OX);
	light_R_slider.SetPos(main.PLight(0));
	itoa(light_R_slider.GetPos(),str,10);
	light_R_text.SetWindowTextA(str);
	light_fi_slider.SetRange(0,360);
	light_fi_slider.SetPos(main.PLight(1));
	itoa(light_fi_slider.GetPos(),str,10);
	light_fi_text.SetWindowTextA(str);
	light_q_slider.SetRange(0,360);
	light_q_slider.SetPos(main.PLight(2));
	itoa(light_q_slider.GetPos(),str,10);
	light_q_text.SetWindowTextA(str);
	//наблюдатель
	eye_R_slider.SetRange(0,main.OX);
	eye_R_slider.SetPos(main.PView(0));
	itoa(eye_R_slider.GetPos(),str,10);
	eye_R_text.SetWindowTextA(str);
	eye_fi_slider.SetRange(0,main.OX);
	eye_fi_slider.SetPos(main.PView(1));
	itoa(eye_fi_slider.GetPos(),str,10);
	eye_fi_text.SetWindowTextA(str);
	eye_q_slider.SetRange(0,main.OX);
	eye_q_slider.SetPos(main.PView(2));
	itoa(eye_q_slider.GetPos(),str,10);
	eye_q_text.SetWindowTextA(str);
	//таймер
	if(main.timer==false)
		timer_checkbox.SetCheck(0);
	else if(main.timer==true)
		timer_checkbox.SetCheck(1);
	timer_slider.SetRange(100,10000);
	timer_slider.SetPos(main.timer_interval);
	itoa(timer_slider.GetPos(),str,10);
	timer_text.SetWindowTextA(str);
}

void Ball3Dialog::OnBnClickedOk()
{
	//отправка настроек
	((CMainFrame*)GetParent())->sp=sp;

	CDialogEx::OnOK();
}


void Ball3Dialog::OnBnClickedButton4()
{
	CColorDialog ccd;
	if(IDOK==ccd.DoModal()){
		sp.color_b=ccd.GetColor();
		color_ball.SetBkColor(ccd.GetColor());
		color_ball.SetPos(0);
	}
}


void Ball3Dialog::OnBnClickedButton3()
{
	CColorDialog ccd;
	if(IDOK==ccd.DoModal()){
		sp.color_s=ccd.GetColor();
		color_spiral.SetBkColor(ccd.GetColor());
		color_spiral.SetPos(0);
	}
}


void Ball3Dialog::OnBnClickedButton2()
{
	CColorDialog ccd;
	if(IDOK==ccd.DoModal()){
		sp.color_n=ccd.GetColor();
		color_negative.SetBkColor(ccd.GetColor());
		color_negative.SetPos(0);
	}
}


void Ball3Dialog::OnBnClickedButton1()
{
	CColorDialog ccd;
	if(IDOK==ccd.DoModal()){
		sp.color_p=ccd.GetColor();
		color_positive.SetBkColor(ccd.GetColor());
		color_positive.SetPos(0);
	}
}


void Ball3Dialog::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(OX_slider.GetPos(),str,10);
	OX_text.SetWindowTextA(str);
	sp.OX=OX_slider.GetPos();
	spiral_R_slider.SetRange(1,OX_slider.GetPos(),1);
	ball_R_slider.SetRange(1,OX_slider.GetPos()/10,1);
	light_R_slider.SetRange(0,OX_slider.GetPos(),1);
	eye_R_slider.SetRange(0,OX_slider.GetPos(),1);
	*pResult = 0;
}


void Ball3Dialog::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(OY_slider.GetPos(),str,10);
	OY_text.SetWindowTextA(str);
	sp.OY=OY_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit1()
{
	char* str=new char[5];
	OX_text.GetWindowTextA(str,5);
	OX_slider.SetPos(atoi(str));
	sp.OX=atoi(str);
}


void Ball3Dialog::OnEnChangeEdit2()
{
	char* str=new char[5];
	OY_text.GetWindowTextA(str,5);
	OY_slider.SetPos(atoi(str));
	sp.OY=atoi(str);
}


void Ball3Dialog::OnEnChangeEdit3()
{
	char* str=new char[5];
	OZ_text.GetWindowTextA(str,5);
	OZ_slider.SetPos(atoi(str));
	sp.OZ=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(spiral_R_slider.GetPos(),str,10);
	spiral_R_text.SetWindowTextA(str);
	sp.spiral_R=spiral_R_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(OZ_slider.GetPos(),str,10);
	OZ_text.SetWindowTextA(str);
	sp.OZ=OZ_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(spiral_zstep_slider.GetPos(),str,10);
	spiral_zstep_text.SetWindowTextA(str);
	sp.spiral_zstep=spiral_zstep_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(spiral_znum_slider.GetPos(),str,10);
	spiral_znum_text.SetWindowTextA(str);
	sp.spiral_znum=spiral_znum_slider.GetPos();

	ball_pos_slider.SetRange(0,sp.spiral_znum*sp.spiral_density,1);
	*pResult = 0;
}


void Ball3Dialog::OnNMCustomdrawSlider7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(spiral_density_slider.GetPos(),str,10);
	spiral_density_text.SetWindowTextA(str);
	sp.spiral_density=spiral_density_slider.GetPos();
	ball_pos_slider.SetRange(0,sp.spiral_znum*sp.spiral_density,1);
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit4()
{
	char* str=new char[5];
	spiral_R_text.GetWindowTextA(str,5);
	spiral_R_slider.SetPos(atoi(str));
	sp.spiral_R=atoi(str);
}


void Ball3Dialog::OnEnChangeEdit5()
{
	char* str=new char[5];
	spiral_zstep_text.GetWindowTextA(str,5);
	spiral_zstep_slider.SetPos(atoi(str));
	sp.spiral_zstep=atoi(str);
}


void Ball3Dialog::OnEnChangeEdit6()
{
	char* str=new char[5];
	spiral_znum_text.GetWindowTextA(str,5);
	spiral_znum_slider.SetPos(atoi(str));
	sp.spiral_znum=atoi(str);
}


void Ball3Dialog::OnEnChangeEdit7()
{
	char* str=new char[5];
	spiral_density_text.GetWindowTextA(str,5);
	spiral_density_slider.SetPos(atoi(str));
	sp.spiral_density=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(ball_R_slider.GetPos(),str,10);
	ball_R_text.SetWindowTextA(str);
	sp.ball_R=ball_R_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit8()
{
	char* str=new char[5];
	ball_R_text.GetWindowTextA(str,5);
	ball_R_slider.SetPos(atoi(str));
	sp.ball_R=atoi(str);
}


void Ball3Dialog::OnBnClickedRadio1()
{
	light_radio1.SetCheck(1);
	light_rabio2.SetCheck(0);
	sp.ball_light=false;
}


void Ball3Dialog::OnBnClickedRadio2()
{
	light_radio1.SetCheck(0);
	light_rabio2.SetCheck(1);
	sp.ball_light=true;
}


void Ball3Dialog::OnNMCustomdrawSlider16(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(timer_slider.GetPos(),str,10);
	timer_text.SetWindowTextA(str);
	sp.timer_interval=timer_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit16()
{
	char* str=new char[5];
	timer_text.GetWindowTextA(str,5);
	timer_slider.SetPos(atoi(str));
	sp.timer_interval=atoi(str);
}



void Ball3Dialog::OnNMCustomdrawSlider15(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(ball_pos_slider.GetPos(),str,10);
	ball_pos_text.SetWindowTextA(str);
	sp.ball_pos=ball_pos_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit15()
{
	char* str=new char[5];
	ball_pos_text.GetWindowTextA(str,5);
	ball_pos_slider.SetPos(atoi(str));
	sp.ball_pos=atoi(str);
}

void Ball3Dialog::OnNMCustomdrawSlider9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(light_R_slider.GetPos(),str,10);
	light_R_text.SetWindowTextA(str);
	sp.PLight(0)=light_R_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit9()
{
	char* str=new char[5];
	light_R_text.GetWindowTextA(str,5);
	light_R_slider.SetPos(atoi(str));
	sp.PLight(0)=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(light_fi_slider.GetPos(),str,10);
	light_fi_text.SetWindowTextA(str);
	sp.PLight(1)=light_fi_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit10()
{
	char* str=new char[5];
	light_fi_text.GetWindowTextA(str,5);
	light_fi_slider.SetPos(atoi(str));
	sp.PLight(1)=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider11(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(light_q_slider.GetPos(),str,10);
	light_q_text.SetWindowTextA(str);
	sp.PLight(2)=light_q_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit11()
{
	char* str=new char[5];
	light_q_text.GetWindowTextA(str,5);
	light_q_slider.SetPos(atoi(str));
	sp.PLight(2)=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider12(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(eye_R_slider.GetPos(),str,10);
	eye_R_text.SetWindowTextA(str);
	sp.PView(0)=eye_R_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit12()
{
	char* str=new char[5];
	eye_R_text.GetWindowTextA(str,5);
	eye_R_slider.SetPos(atoi(str));
	sp.PView(0)=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider13(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(eye_fi_slider.GetPos(),str,10);
	eye_fi_text.SetWindowTextA(str);
	sp.PView(1)=eye_fi_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit13()
{
	char* str=new char[5];
	eye_fi_text.GetWindowTextA(str,5);
	eye_fi_slider.SetPos(atoi(str));
	sp.PView(1)=atoi(str);
}


void Ball3Dialog::OnNMCustomdrawSlider14(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	char* str=new char[5];
	itoa(eye_q_slider.GetPos(),str,10);
	eye_q_text.SetWindowTextA(str);
	sp.PView(2)=eye_q_slider.GetPos();
	*pResult = 0;
}


void Ball3Dialog::OnEnChangeEdit14()
{
	char* str=new char[5];
	eye_q_text.GetWindowTextA(str,5);
	eye_q_slider.SetPos(atoi(str));
	sp.PView(2)=atoi(str);
}


void Ball3Dialog::OnBnClickedCheck1()
{
	if(sp.timer==true){
		timer_checkbox.SetCheck(0);
		sp.timer=false;
	}
	else{
		timer_checkbox.SetCheck(1);
		sp.timer=true;
	}
}
