// 工资管理系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "工资管理系统.h"
#include "工资管理系统Dlg.h"
#include "AdminDlg.h"
#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C工资管理系统Dlg 对话框




C工资管理系统Dlg::C工资管理系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C工资管理系统Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C工资管理系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, C_ID);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, C_PASSWORD);
}

BEGIN_MESSAGE_MAP(C工资管理系统Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_GUEST, &C工资管理系统Dlg::OnBnClickedButtonGuest)
	ON_BN_CLICKED(IDC_BUTTON_ADMIN, &C工资管理系统Dlg::OnBnClickedButtonAdmin)
END_MESSAGE_MAP()


// C工资管理系统Dlg 消息处理程序

BOOL C工资管理系统Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C工资管理系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C工资管理系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//员工登录
void C工资管理系统Dlg::OnBnClickedButtonGuest()
{
	// TODO: 在此添加控件通知处理程序代码
	char A_id[20],A_password[20];
	C_ID.GetWindowTextA(A_id,C_ID.GetWindowTextLengthA()+1);
	C_PASSWORD.GetWindowTextA(A_password,C_PASSWORD.GetWindowTextLengthA()+1);
	//
	//
	if(1)
	{
		CUserDlg C_USERDLG;
		C_USERDLG.DoModal();
	}
}

//管理员登录
void C工资管理系统Dlg::OnBnClickedButtonAdmin()
{
	// TODO: 在此添加控件通知处理程序代码
	char A_id[20],A_password[20];
	C_ID.GetWindowTextA(A_id,C_ID.GetWindowTextLengthA()+1);
	C_PASSWORD.GetWindowTextA(A_password,C_PASSWORD.GetWindowTextLengthA()+1);
	//
	//
	if(1)
	{
		CAdminDlg C_ADMINDLG;
		C_ADMINDLG.DoModal();
		//C_ADMINDLG.ShowWindow(SW_SHOW);
		//::Sleep(100000);
	}
}
