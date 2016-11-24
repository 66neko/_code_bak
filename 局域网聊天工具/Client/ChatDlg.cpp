// ChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "ChatDlg.h"
#include "process.h"


// CChatDlg �Ի���

IMPLEMENT_DYNAMIC(CChatDlg, CDialog)

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
	, m_port(0)
{

}

CChatDlg::~CChatDlg()
{
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_chatview);
	DDX_Control(pDX, IDC_EDIT2, m_chatedit);
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CChatDlg::OnBnClickedOk)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CChatDlg ��Ϣ�������

void CChatDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	m_chatedit.GetWindowTextA(str);
	char *sendbuf = str.GetBuffer(0);
	sendto(sock,sendbuf,200,0,(sockaddr*)&addrclient,sizeof(sockaddr));
	m_chatedit.SetWindowTextA("");
	closesocket(sock);
	::SetFocus(m_chatedit.m_hWnd);
}

int CChatDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	sockclient = socket(AF_INET,SOCK_STREAM,0);
	if (-1 == connect(sockclient,(sockaddr*)&addrclient,sizeof(sockaddr)))
	{
		MessageBox("����ʧ��");
		::exit(0);
	}
	send(sockclient,"c",1,0);
	char portbuf[5];
	recv(sockclient,portbuf,5,0);
	m_port = (u_short)atoi(portbuf);
	CChatDlg *pvoid;
	pvoid = this;
	_beginthread(Thread_recvform,0,pvoid);
	return 0;
}

void CChatDlg::OnDestroy()
{
	::exit(0);
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}

void CChatDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::exit(0);
	CDialog::OnClose();
}

VOID CChatDlg::Thread_recvform(PVOID pvoid)
{
	CChatDlg *p = (CChatDlg*)pvoid;
	SOCKET sockclient = socket(AF_INET,SOCK_DGRAM,0);
	SOCKADDR_IN addrsrv,addr;
	addrsrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(p->m_port);
	bind(sockclient,(sockaddr*)&addrsrv,sizeof(sockaddr));
	int len = sizeof(sockaddr);
	char recvbuf[200] = "";
	while(true)
	{
		recvfrom(sockclient,recvbuf,200,0,(sockaddr*)&addr,&len);
		CString str;
		p->m_chatview.GetWindowTextA(str);
		str.Format("%s\r\n%s",str.GetBuffer(0),recvbuf);
		p->m_chatview.SetWindowTextA(str);
		p->m_chatview.LineScroll(p->m_chatview.GetLineCount()-9);
	}
}
void CChatDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	::SetFocus(m_chatedit.m_hWnd);
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}
