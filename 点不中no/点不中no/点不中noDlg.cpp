// �㲻��noDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�㲻��no.h"
#include "�㲻��noDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C�㲻��noDlg �Ի���




C�㲻��noDlg::C�㲻��noDlg(CWnd* pParent /*=NULL*/)
	: CDialog(C�㲻��noDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�㲻��noDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_P2, m_left);
	DDX_Control(pDX, IDC_P1, m_top);
	DDX_Control(pDX, IDC_P3, m_right);
	DDX_Control(pDX, IDC_P4, m_bottom);
	DDX_Control(pDX, IDCANCEL, m_no);
}

BEGIN_MESSAGE_MAP(C�㲻��noDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
//	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C�㲻��noDlg ��Ϣ�������

BOOL C�㲻��noDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�㲻��noDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�㲻��noDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�㲻��noDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//void C�㲻��noDlg::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

void C�㲻��noDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
