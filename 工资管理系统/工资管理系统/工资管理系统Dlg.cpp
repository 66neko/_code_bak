// ���ʹ���ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ʹ���ϵͳ.h"
#include "���ʹ���ϵͳDlg.h"
#include "AdminDlg.h"
#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ʹ���ϵͳDlg �Ի���




C���ʹ���ϵͳDlg::C���ʹ���ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialog(C���ʹ���ϵͳDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ʹ���ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, C_ID);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, C_PASSWORD);
}

BEGIN_MESSAGE_MAP(C���ʹ���ϵͳDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_GUEST, &C���ʹ���ϵͳDlg::OnBnClickedButtonGuest)
	ON_BN_CLICKED(IDC_BUTTON_ADMIN, &C���ʹ���ϵͳDlg::OnBnClickedButtonAdmin)
END_MESSAGE_MAP()


// C���ʹ���ϵͳDlg ��Ϣ�������

BOOL C���ʹ���ϵͳDlg::OnInitDialog()
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

void C���ʹ���ϵͳDlg::OnPaint()
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
HCURSOR C���ʹ���ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Ա����¼
void C���ʹ���ϵͳDlg::OnBnClickedButtonGuest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//����Ա��¼
void C���ʹ���ϵͳDlg::OnBnClickedButtonAdmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
