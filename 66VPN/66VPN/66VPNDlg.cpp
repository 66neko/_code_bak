// 66VPNDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "66VPN.h"
#include "66VPNDlg.h"
#include "Cvpn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy66VPNDlg 对话框




CMy66VPNDlg::CMy66VPNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy66VPNDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy66VPNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STATE, m_listbox);
	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_btm_con);
	DDX_Control(pDX, IDC_BUTTON_DISCONNECT, m_btm_discon);
	DDX_Control(pDX, IDC_COMBO_GAME, m_ComboBox);
}

BEGIN_MESSAGE_MAP(CMy66VPNDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CMy66VPNDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMy66VPNDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CMy66VPNDlg::OnBnClickedButtonDisconnect)
END_MESSAGE_MAP()


// CMy66VPNDlg 消息处理程序

BOOL CMy66VPNDlg::OnInitDialog()
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

void CMy66VPNDlg::OnPaint()
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
HCURSOR CMy66VPNDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy66VPNDlg::OnBnClickedButtonConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listbox.AddString("连接VPN中...");
	if(m_vpn.Connect("vpntest","123456","118.193.210.169"))
	{
		m_btm_con.EnableWindow(0);
		m_btm_discon.EnableWindow(1);
		m_listbox.AddString("连接成功");
		char m_IP[16];
		m_vpn.GetIP(m_IP);
		m_listbox.AddString(m_IP);
		CString str;
		m_ComboBox.GetWindowTextA(str);
		m_listbox.AddString(str);
	}
	else
	{
		m_listbox.AddString("连接失败");
	}
}

void CMy66VPNDlg::OnBnClickedButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_vpn.Close();
	OnOK();
}

void CMy66VPNDlg::OnBnClickedButtonDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listbox.AddString("断开连接中...");
	if(m_vpn.Close())
	{
		m_listbox.AddString("断开连接成功");
		m_btm_con.EnableWindow(1);
		m_btm_discon.EnableWindow(0);
	}
	else
	{
		m_listbox.AddString("断开连接出现错误，请重试");
	}
}