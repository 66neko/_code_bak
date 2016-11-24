// 点不中noDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "点不中no.h"
#include "点不中noDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// C点不中noDlg 对话框




C点不中noDlg::C点不中noDlg(CWnd* pParent /*=NULL*/)
	: CDialog(C点不中noDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C点不中noDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_P2, m_left);
	DDX_Control(pDX, IDC_P1, m_top);
	DDX_Control(pDX, IDC_P3, m_right);
	DDX_Control(pDX, IDC_P4, m_bottom);
	DDX_Control(pDX, IDCANCEL, m_no);
}

BEGIN_MESSAGE_MAP(C点不中noDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
//	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C点不中noDlg 消息处理程序

BOOL C点不中noDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	/**************************
	CRect rect,ex_rect;
	m_bottom.GetWindowRect(ex_rect);
	rect.bottom = ex_rect.bottom;
	m_top.GetWindowRect(ex_rect);
	rect.top = ex_rect.top;
	m_left.GetWindowRect(ex_rect);
	rect.left = ex_rect.left;
	m_right.GetWindowRect(ex_rect);
	rect.right = ex_rect.right;
	this->SetWindowPos(NULL,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,SWP_NOMOVE|SWP_NOZORDER);
	***************************/
	::SetTimer(this->m_hWnd,0,1,NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C点不中noDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C点不中noDlg::OnPaint()
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
HCURSOR C点不中noDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//void C点不中noDlg::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CString str;
//	str.Format("%d",point.x);
//	//MessageBox(str);
//	CRect rect;
//	CRect m_rect;
//	this->GetWindowRect(m_rect);
//	m_no.GetWindowRect(rect);
//	POINT p;
//	//CClientDC dc(0);
//	::GetCursorPos(&p);
//	//dc.StretchBlt(p.x,p.y,rect.right-rect.left,rect.bottom-rect.bottom,&dc,0,0,100,100,BLACKNESS);
//	HDC dc = ::GetDC(0);
//	TextOut(dc,p.x,p.y,"",5);
//	TextOut(dc,rect.left,rect.top,"",5);
//	TextOut(dc,rect.right,rect.top,"",5);
//	TextOut(dc,rect.left,rect.bottom,"",5);
//	TextOut(dc,rect.right,rect.bottom,"",5);
//	if(p.x >= rect.left
//		&& p.x <= rect.right
//		&& p.y >= rect.top
//		&& p.y <= rect.bottom)
//	{
//		::SetCursorPos(rect.left - 1,rect.top - 1);
//	}
//	CDialog::OnMouseMove(nFlags, point);
//}

void C点不中noDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	CRect m_rect;
	this->GetWindowRect(m_rect);
	m_no.GetWindowRect(rect);
	POINT p;
	::GetCursorPos(&p);
	if(p.x >= rect.left
		&& p.x <= rect.right
		&& p.y >= rect.top
		&& p.y <= rect.bottom)
	{
		//::SetCursorPos(rect.left - 1,rect.top - 1);
		m_no.Detach();
	}
	CDialog::OnTimer(nIDEvent);
}
