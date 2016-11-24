// 66VPNDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "66VPN.h"
#include "66VPNDlg.h"
#include "Cvpn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy66VPNDlg �Ի���




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


// CMy66VPNDlg ��Ϣ�������

BOOL CMy66VPNDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy66VPNDlg::OnPaint()
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
HCURSOR CMy66VPNDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy66VPNDlg::OnBnClickedButtonConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_listbox.AddString("����VPN��...");
	if(m_vpn.Connect("vpntest","123456","118.193.210.169"))
	{
		m_btm_con.EnableWindow(0);
		m_btm_discon.EnableWindow(1);
		m_listbox.AddString("���ӳɹ�");
		char m_IP[16];
		m_vpn.GetIP(m_IP);
		m_listbox.AddString(m_IP);
		CString str;
		m_ComboBox.GetWindowTextA(str);
		m_listbox.AddString(str);
	}
	else
	{
		m_listbox.AddString("����ʧ��");
	}
}

void CMy66VPNDlg::OnBnClickedButtonExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_vpn.Close();
	OnOK();
}

void CMy66VPNDlg::OnBnClickedButtonDisconnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_listbox.AddString("�Ͽ�������...");
	if(m_vpn.Close())
	{
		m_listbox.AddString("�Ͽ����ӳɹ�");
		m_btm_con.EnableWindow(1);
		m_btm_discon.EnableWindow(0);
	}
	else
	{
		m_listbox.AddString("�Ͽ����ӳ��ִ���������");
	}
}