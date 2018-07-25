// SimpleCalcDlg.h : header file
//

#if !defined(AFX_SIMPLECALCDLG_H__37DD2C5E_5534_4FDA_8708_55042F7D3E0C__INCLUDED_)
#define AFX_SIMPLECALCDLG_H__37DD2C5E_5534_4FDA_8708_55042F7D3E0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg dialog

class CSimpleCalcDlg : public CDialog
{
// Construction
public:
	void ChangeSize();
	bool pSize;
	CRect pHalf;
	CRect pFull;
	void negasys(int num);
	int numsys(int num, int base);
	void inset(char* s);
	int history_i;
	CString history[100];
	void sum(char* s);
	void Change(char* s1, char* s2);
	int Precedence(char sign);
	CSimpleCalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleCalcDlg)
	enum { IDD = IDD_SIMPLECALC_DIALOG };
	CButton	m_more;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleCalcDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_iCalcMode;
	CString m_strOperation;
	CString m_strNum2;
	CString m_strNum1;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimpleCalcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton0();
	afx_msg void OnCleare();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	afx_msg void OnMul();
	afx_msg void OnDiv();
	afx_msg void OnEqual();
	afx_msg void OnKl();
	afx_msg void OnKr();
	afx_msg void OnMod();
	afx_msg void OnPow();
	afx_msg void OnBs();
	afx_msg void OnHistory();
	afx_msg void OnMore();
	afx_msg void OnSin();
	afx_msg void OnCos();
	afx_msg void OnTan();
	afx_msg void OnSqrt();
	afx_msg void OnPi();
	afx_msg void OnE();
	afx_msg void OnSkin();
	afx_msg void Onln();
	afx_msg void Onlg();
	afx_msg void Onexp();
	afx_msg void OnDiv1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	COLORREF color;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLECALCDLG_H__37DD2C5E_5534_4FDA_8708_55042F7D3E0C__INCLUDED_)
