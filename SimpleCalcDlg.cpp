// SimpleCalcDlg.cpp : implementation file
//


#include "stdafx.h"
#include "SimpleCalc.h"
#include "SimpleCalcDlg.h"

#ifdef _DEBUG
#include <stack>
#include <iostream>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg dialog

CSimpleCalcDlg::CSimpleCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimpleCalcDlg::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(CSimpleCalcDlg)
	m_radio = -1;
	history_i = 0;
	pSize = false;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimpleCalcDlg)
	DDX_Control(pDX, IDC_MORE, m_more);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimpleCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CSimpleCalcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON0, OnButton0)
	ON_BN_CLICKED(IDC_CLEARE, OnCleare)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SUB, OnSub)
	ON_BN_CLICKED(IDC_MUL, OnMul)
	ON_BN_CLICKED(IDC_DIV, OnDiv)
	ON_BN_CLICKED(IDC_EQUAL, OnEqual)
	ON_BN_CLICKED(IDC_KL, OnKl)
	ON_BN_CLICKED(IDC_KR, OnKr)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_POW, OnPow)
	ON_BN_CLICKED(IDC_BS, OnBs)
	ON_BN_CLICKED(IDC_HISTORY, OnHistory)
	ON_BN_CLICKED(IDC_MORE, OnMore)
	ON_BN_CLICKED(IDC_SIN, OnSin)
	ON_BN_CLICKED(IDC_COS, OnCos)
	ON_BN_CLICKED(IDC_TAN, OnTan)
	ON_BN_CLICKED(IDC_SQRT, OnSqrt)
	ON_BN_CLICKED(IDC_PI, OnPi)
	ON_BN_CLICKED(IDC_E, OnE)
	ON_BN_CLICKED(IDC_SKIN, OnSkin)
	ON_BN_CLICKED(IDC_ln, Onln)
	ON_BN_CLICKED(IDC_lg, Onlg)
	ON_BN_CLICKED(IDC_exp, Onexp)
	ON_BN_CLICKED(IDC_Div1, OnDiv1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg message handlers

BOOL CSimpleCalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//*************************   BGM   *************************************
	/*TCHAR szDirectory[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, szDirectory);
	CString sndPath;
	sndPath.Format("%s\\sound\\1.wav", szDirectory);   //绝对路径
	//PlaySound(sndPath, NULL, SND_FILENAME | SND_ASYNC);*/
	PlaySound("1.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); 
	//*************************************************************************
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_strNum1.Empty();
	m_strNum2.Empty();
	m_strOperation.Empty();

	////////////////////////////定义窗口大小////////////////////////////////////
	GetWindowRect(&pFull);
	pHalf = pFull;
	CRect rc;
	m_more.GetWindowRect(&rc);
	pHalf.bottom = rc.bottom + 180;
	ChangeSize();
	///////////////////////////////////////////////////////////////////////////

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleCalcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleCalcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//***********************************数字区****************************************
void CSimpleCalcDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "1";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "2";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "3";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "4";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "5";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "6";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "7";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "8";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "9";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

void CSimpleCalcDlg::OnButton0() 
{
	// TODO: Add your control notification handler code here
	m_strNum1 += "0";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}
//***********************************************************************************

//******************************清除***********************************
void CSimpleCalcDlg::OnCleare() 
{
	// TODO: Add your control notification handler code here
	m_strNum1.Empty();
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************退格***********************************
void CSimpleCalcDlg::OnBs() 
{
	// TODO: Add your control notification handler code here
	m_strNum1.Delete(m_strNum1.GetLength()-1);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************加法***********************************
void CSimpleCalcDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	//
	
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "+";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0+";
	else
		m_strNum1 += "+";
	
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************减法***********************************
void CSimpleCalcDlg::OnSub() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "-";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0-";
	else
		m_strNum1 += "-";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************乘法***********************************
void CSimpleCalcDlg::OnMul() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "*";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0*";
	else
		m_strNum1 += "*";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************除法***********************************
void CSimpleCalcDlg::OnDiv() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "/";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0/";
	else
		m_strNum1 += "/";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************左括号***********************************
void CSimpleCalcDlg::OnKl() 
{
	// TODO: Add your control notification handler code here
	if(!(m_strNum1.Right(1) >= '0' && m_strNum1.Right(1) <= '9'))
	{
		m_strNum1 += "(";
		GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
	}
}

//******************************右括号***********************************
void CSimpleCalcDlg::OnKr() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) >= '0' && m_strNum1.Right(1) <= '9')
	{
		m_strNum1 += ")";
		GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
	}
}

//******************************取模***********************************
void CSimpleCalcDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "%";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0%";
	else
		m_strNum1 += "%";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************次方***********************************
void CSimpleCalcDlg::OnPow() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.Right(1) == '+' || m_strNum1.Right(1) == '-' || m_strNum1.Right(1) == '*' || m_strNum1.Right(1) == '/' || m_strNum1.Right(1) == '^' || m_strNum1.Right(1) == '%')
	{
		m_strNum1.Delete(m_strNum1.GetLength()-1);
		m_strNum1 += "^";
	}
	else if(m_strNum1.Right(1) == '(' || !m_strNum1.GetLength())
		m_strNum1 += "0^";
	else
		m_strNum1 += "^";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************处理优先级***********************************
int CSimpleCalcDlg::Precedence(char sign)
{
	switch (sign)
        {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        case '^':
        case '%':
                return 3;
        case '(':
        case ')':
        default:
                return 0;
        }
}

//******************************逆波兰式***********************************
void CSimpleCalcDlg::Change(char *s1, char *s2)
{
		stack<char> T;
        int i = 0, j = 0;
        char ch;
        //SetNull(&T);
        T.push('@');
        ch = s1[i];
        while (ch != '\0')
        {
                if (ch == ' ')
                {
                        ch = s1[++i];
                }
                else if (ch == '(')
                {
                        T.push(ch);
                        ch = s1[++i];
                }
                else if (ch == ')')
                {
                        while (T.top() != '(')
                        {
                                s2[j++] = T.top();
                                T.pop();
                        }
                        T.pop();
                        ch = s1[++i];
                }
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
                {
                        char w = T.top();
                        while (Precedence(w) >= Precedence(ch))
                        {
                                s2[j++] = w;
                                T.pop();
                                w = T.top();
                        }
                        T.push(ch);
                        ch = s1[++i];
                }
                else
                {
                        while ((ch >= '0' && ch <= '9') || ch == '.')
                        {
                                s2[j++] = ch;
                                ch = s1[++i];
                        }
                        s2[j++] = ' ';
                }
        }
        ch = T.top();
        T.pop();
        while (ch != '@')
        {
                s2[j++] = ch;
                ch = T.top();
                T.pop();
        }
        s2[j++] = '\0';
}

//******************************等于***********************************
void CSimpleCalcDlg::OnEqual() 
{
	// TODO: Add your control notification handler code here
	if(m_strNum1.GetLength())
	{

		char m_1[100], m_2[100];
		strcpy(m_1,m_strNum1);
		//******************处理符号后不加数字（错误输入）的运算*************************
		int len = strlen(m_1), len_i = len, len_j = len;
		if(m_1[len-1] == '+' || m_1[len-1] == '-' || m_1[len-1] == '*' || m_1[len-1] == '/' || m_1[len-1] == '^' || m_1[len-1] == '%')
		{
		
			while(m_1[len_i-2] >= '0' && m_1[len_i-2] <= '9' && len_i-2 != -1)
				len_i--;
			len_i--;
			while(len_i != len-1)
			{
				m_1[len_j++] = m_1[len_i++];
			}
			m_1[len_j] = '\0';
		}
		m_strNum1.Format("%s", m_1);
		//******************处理负数的运算*************************
		for(int i=0; i<strlen(m_1); i++)					
		{
				if(i == 0 && m_1[i] == '-')
						inset(m_1);
				if((m_1[i] == '(' && m_1[i+1] == '-'))
						inset(&m_1[i+1]);
		}
		//*********************************************************
		Change(m_1, m_2);
		sum(m_2);
	}
}

//*********************负数前加0******************************
void CSimpleCalcDlg::inset(char *s)
{
	int i;
        int l = strlen(s);
        s[l+1]='\0';
        for(i=l; i; i--)
                s[i] = s[i-1];
        s[i] = '0';
}

//*********************求结果**********************************
void CSimpleCalcDlg::sum(char *s)
{
		stack<int> T;
        int i = 0, j = 0, f = 0;
        char ch;
        ch = s[i];
        while (ch != '\0')
        {
                if (ch == ' ')
                {
                        ch = s[++i];
                }
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
                {
                        int w = T.top();
                        T.pop();
                        int q = T.top();
                        T.pop();
                        switch(ch)
                        {
                        case '+':
                                T.push(q+w);break;
                        case '-':
                                T.push(q-w);break;
                        case '*':
                                T.push(q*w);break;
                        case '/':
								if(w == 0)
								{
									f = 1;
									break;
								}
                                T.push(q/w);break;
                        case '%':
                                T.push(q%w);break;
                        case '^':
                                T.push(pow(q, w));break;
                        }
                        
                        ch = s[++i];
                }
                else
                {
                        int k = 0;
                        char qq[20];
                        while ((ch >= '0' && ch <= '9') || ch == '.')
                        {
                                qq[k++] = ch;
                                ch = s[++i];
                        }
                        qq[k++] = '\0';
                        T.push(atoi(qq));
                }
        }
		
		CString str;
		if(f)
			str += "Can not divide by zero";			//被除数不能为零
		else
		{
			str.Format(_T("%s\r\n%d"), m_strNum1, T.top());
			history[history_i++].Format(_T("%s=%d\r\n"), m_strNum1, T.top());
		}
        GetDlgItem(IDC_RESULT)->SetWindowText(str);

		GetDlgItem(IDC_TENZ)->SetWindowText(history[history_i-1]);
		//将结果记录到下一次的运算中
		m_strNum1.Empty();
		m_strNum1.Format("%d", T.top());

		//////////////二进制转换///////////////
		if(T.top() >= 0)
				numsys(T.top(), 2);    //递归法
		else
				negasys(-T.top());
		GetDlgItem(IDC_ERZ)->SetWindowText(m_strNum2);
		m_strNum2.Empty();
		
}

////*************************历史显示 **********************************
void CSimpleCalcDlg::OnHistory() 
{
	// TODO: Add your control notification handler code here
	CString str = "";
	for(int i=0; i<history_i; i++)
		str += history[i];
	MessageBox(str);
	/*for(int i=history_i-1; i>=0; i--)
	{
		CString ID = MessageBox(history[i], "history", MB_OKCANCEL);		//点击OK依次输出上一次的运算记录
		if(IDOK != ID)								//如果没有点击OK则不继续输出上一次的记录
			break;
	}*/
}

//************************键盘控制****************************************

BOOL CSimpleCalcDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN) 
	{
		switch(pMsg->wParam)
		{
		case 48:
			if(::GetKeyState(VK_SHIFT)<0)
				OnKr();			//右括号
			else
				OnButton0();//0
			return TRUE;
		case 96: 
			OnButton0();//0
			return TRUE;
		case 49:
		case 97: 
			OnButton1();//1
			return TRUE;
		case 50:
		case 98: 
			OnButton2();//2
			return TRUE;
		case 51:
		case 99: 
			OnButton3();//3
			return TRUE;
		case 52:
		case 100: 
			OnButton4();//4
			return TRUE;
		case 53:
			if(::GetKeyState(VK_SHIFT)<0)
				OnMod();			//取模
			else
				OnButton5();//5
			return TRUE;
		case 101: 
			OnButton5();//5
			return TRUE;
		case 54:
			if(::GetKeyState(VK_SHIFT)<0)
				OnPow();			//  ^
			else
				OnButton6();//6
			return TRUE;
		case 102: 
			OnButton6();//6
			return TRUE;
		case 55:
		case 103: 
			OnButton7();//7
			return TRUE;
		case 104: 
			OnButton8();//8
			return TRUE;
		case 56:
			if(::GetKeyState(VK_SHIFT)<0)
				OnMul();			//  *
			else
				OnButton8();//8
			return TRUE;
		case 105:
			OnButton9();//9
			return TRUE;
		case 57: 
			if(::GetKeyState(VK_SHIFT)<0)
				OnKl();			//左括号
			else
				OnButton9();//9
			return TRUE;
		case 106: 
			OnMul();// *
			return TRUE;
		case 107: 
			OnAdd();// +
			return TRUE;
		case 109: 
		case 189: 
			OnSub();// -
			return TRUE;
		case 111: 
		case 191:
			OnDiv();// /
			return TRUE;
		case 8:
			OnBs();// Backspace
			return TRUE;
		case 13:
			OnEqual();// enter
			return TRUE;
		case 187:
			if(::GetKeyState(VK_SHIFT)<0)
				OnAdd();			//左括号
			else
				OnEqual();// = 
			return TRUE;
		case 27:		  //esc 改为清除键
			OnCleare();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

//***************************处理正数的进制转换*****************************
int CSimpleCalcDlg::numsys(int num, int base)
{
        if ( !num )
                return 0;
        else
        {
                numsys(num / base, base);
                m_strNum2 += (num % base)+'0';
                return 1;
        }
		
}

//***************************处理负数的进制转换*****************************
void CSimpleCalcDlg::negasys(int num)
{
		int i = 32 ;
		char b[33];
        num = ~num+1;
        while(i--)
        {
                int d;
                d = num&1;
                b[i] = d+'0';
                num>>=1;
        }
		b[32] = '\0';
		m_strNum2.Format("%s", b);
}

//***************************改变窗口大小*****************************
void CSimpleCalcDlg::ChangeSize()
{
	CRect rc;
	CString str;
	if(pSize)
	{
		str = "less(&L)";
		rc = pFull;
		GetDlgItem(IDC_ADD)->EnableWindow(0);
		GetDlgItem(IDC_SUB)->EnableWindow(0);
		GetDlgItem(IDC_MUL)->EnableWindow(0);
		GetDlgItem(IDC_DIV)->EnableWindow(0);
		GetDlgItem(IDC_EQUAL)->EnableWindow(0);
		GetDlgItem(IDC_POW)->EnableWindow(0);
		GetDlgItem(IDC_MOD)->EnableWindow(0);
	}
	else
	{
		str = "more(&M)";
		rc = pHalf;
		GetDlgItem(IDC_ADD)->EnableWindow(1);
		GetDlgItem(IDC_SUB)->EnableWindow(1);
		GetDlgItem(IDC_MUL)->EnableWindow(1);
		GetDlgItem(IDC_DIV)->EnableWindow(1);
		GetDlgItem(IDC_EQUAL)->EnableWindow(1);
		GetDlgItem(IDC_POW)->EnableWindow(1);
		GetDlgItem(IDC_MOD)->EnableWindow(1);
	}
	SetWindowPos(NULL, 0, 0, rc.Width(), rc.Height(), SWP_NOMOVE);
	m_more.SetWindowText(str);
	pSize = !pSize;
}

void CSimpleCalcDlg::OnMore() 
{
	// TODO: Add your control notification handler code here
	ChangeSize();
}
//*********************************************************************

//******************************* sin *******************************
void CSimpleCalcDlg::OnSin() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = sin(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* cos *******************************
void CSimpleCalcDlg::OnCos() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = cos(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* tan *******************************
void CSimpleCalcDlg::OnTan() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = tan(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* sqrt *******************************
void CSimpleCalcDlg::OnSqrt() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = sqrt(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* 1/x *******************************
void CSimpleCalcDlg::OnDiv1()
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = 1/num;
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* ln *******************************
void CSimpleCalcDlg::Onln() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = log(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//******************************* lg *******************************
void CSimpleCalcDlg::Onlg() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = log10(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//****************************   exp   ****************************
void CSimpleCalcDlg::Onexp() 
{
	// TODO: Add your control notification handler code here
	double num;
	num = atof(m_strNum1.GetBuffer(0)); 
	num = exp(num);
	m_strNum1.Empty();
	m_strNum1.Format("%lf", num);
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//***************************   pai   *****************************
void CSimpleCalcDlg::OnPi() 
{
	// TODO: Add your control notification handler code here
	m_strNum1.Empty();
	m_strNum1 += "3.14159265358";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//***************************    e    *****************************
void CSimpleCalcDlg::OnE() 
{
	// TODO: Add your control notification handler code here
	m_strNum1.Empty();
	m_strNum1 += "2.71828182845";
	GetDlgItem(IDC_RESULT)->SetWindowText(m_strNum1);
}

//*******************************皮肤*******************************
void CSimpleCalcDlg::OnSkin() 
{
	// TODO: Add your control notification handler code here
	Invalidate(TRUE); 
	srand(time(0));
	int a = rand()%255;
	int b = rand()%255;
	int c = rand()%255;
	color = RGB(a, b, c);
	CRect   rc;
	GetClientRect( &rc );// ?????
	CPaintDC dc(this);
	dc.FillSolidRect(&rc, color);   // ???????	
}

