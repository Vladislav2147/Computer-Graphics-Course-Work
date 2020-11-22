#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "sphere_params.h"

// диалоговое окно ball_2Dialog

class ball_2Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(ball_2Dialog)
public:
	sphere_params sp;
public:
	ball_2Dialog(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~ball_2Dialog();
	virtual void OnFinalRelease();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int colorR = 0;
	int colorG = 0;
	int colorB = 0;
	CEdit con_A;
	CEdit con_f;
	CEdit con_F;
	CEdit con_R;
	CButton con_light_diff;
	CButton con_light_mir;
	CSliderCtrl slider_pos_R;
	CSliderCtrl slider_pos_fi;
	CSliderCtrl slider_pos_q;
	CEdit mon_pos_R;
	CEdit mon_pos_fi;
	CEdit mon_pos_q;
	CSliderCtrl slider_lig_R;
	CSliderCtrl slider_lig_fi;
	CSliderCtrl slider_lig_q;
	CEdit mon_lig_R;
	CEdit mon_lig_fi;
	CEdit mon_lig_q;
	CEdit color_R;
	CEdit color_G;
	CEdit color_B;
	afx_msg void OnBnClickedButton1();
	CButton btn_OK;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit21();
	afx_msg void OnEnChangeEdit22();
	afx_msg void OnEnChangeEdit23();
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider7(NMHDR *pNMHDR, LRESULT *pResult);
};
