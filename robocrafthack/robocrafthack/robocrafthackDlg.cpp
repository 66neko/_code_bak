// robocrafthackDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "robocrafthack.h"
#include "robocrafthackDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrobocrafthackDlg 对话框




CrobocrafthackDlg::CrobocrafthackDlg(CWnd* pParent /*=NULL*/)
: CDialog(CrobocrafthackDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hdll = LoadLibrary("keyboardMSGDLL.dll");
	InstallHook = (Dllfun)GetProcAddress(hdll,"InstallHook");
	KillHook = (Dllfun)GetProcAddress(hdll,"KillHook");
	flag = 0;
}

void CrobocrafthackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CrobocrafthackDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CrobocrafthackDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CrobocrafthackDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CrobocrafthackDlg 消息处理程序

BOOL CrobocrafthackDlg::OnInitDialog()
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

void CrobocrafthackDlg::OnPaint()
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
HCURSOR CrobocrafthackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CrobocrafthackDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//InstallHook();
	
	if(flag == 0)
	{
		ShellExecute(this->m_hWnd,"open","cmd.exe","/C netsh ipsec static set policy name=UDP assign=y",NULL,SW_HIDE);
		flag = 1;
	}
	else
	{
		ShellExecute(this->m_hWnd,"open","cmd.exe","/C netsh ipsec static set policy name=UDP assign=n",NULL,SW_HIDE);
		flag = 0;
	}
	
}

void CrobocrafthackDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	system("netsh ipsec static set policy name=UDP assign=n");
	OnCancel();
	
}
