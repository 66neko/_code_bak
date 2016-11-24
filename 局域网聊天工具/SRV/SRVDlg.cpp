// SRVDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SRV.h"
#include "SRVDlg.h"
#include "process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
SOCKADDR_IN *phostaddr = new SOCKADDR_IN;
CSRVDlg* CSRVDlg::m_thisdlg = 0;
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


// CSRVDlg �Ի���




CSRVDlg::CSRVDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSRVDlg::IDD, pParent)
, m_port(6000)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_thisdlg = this;
}

void CSRVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDR, m_IPaddr);
	DDX_Control(pDX, IDC_EDIT1, m_status);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}

BEGIN_MESSAGE_MAP(CSRVDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CSRVDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSRVDlg ��Ϣ�������

BOOL CSRVDlg::OnInitDialog()
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
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		MessageBox("��������ʼ��ʧ��");
		CDialog::OnOK();
	}
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) {
			WSACleanup( );
			MessageBox("��������ʼ��ʧ��");
			CDialog::OnOK(); 
	}
	char hostname[100] = "";
	gethostname(hostname,sizeof(hostname));
	hostent *pHostent = gethostbyname(hostname);
	SOCKADDR_IN hostaddr;
	
	
	for (int i=0;pHostent->h_addr_list[i];i++)
	{
		memcpy(&hostaddr.sin_addr,pHostent->h_addr_list[i],pHostent->h_length);
	}
	*phostaddr = hostaddr;
	phostaddr->sin_family = AF_INET;
	phostaddr->sin_port = htons(6000);
	CString str;
	str.Format("��������ip��ַΪ��%s",inet_ntoa(hostaddr.sin_addr));
	m_IPaddr.SetWindowTextA(str);
	str.Format("��������ʼ���ɹ�\r\n����������IP��ַΪ��\r\n%s\r\n",inet_ntoa(hostaddr.sin_addr));
	m_status.SetWindowTextA(str);
	m_listbox.AddString("�����û��б�");
	_beginthread(Thread_srv,0,NULL);
	_beginthread(Thread_pro,0,&m_listbox);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSRVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSRVDlg::OnPaint()
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
HCURSOR CSRVDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSRVDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	WSACleanup();
	::exit(0);
}

VOID CSRVDlg::Thread_srv(PVOID pvoid)
{
	SOCKET socksrv = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrsrv;
	addrsrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(6000);
	bind(socksrv,(sockaddr*)&addrsrv,sizeof(sockaddr));
	listen(socksrv,10);
	while(true)
	{
		SOCKADDR_IN addrclient;
		int len = sizeof(SOCKADDR);
		SOCKET sockclient = accept(socksrv,(sockaddr*)&addrclient,&len);
		char recvbuf;
		recv(sockclient,&recvbuf,1,0);
		if (recvbuf == 'c')
		{
			CString str;
			str.Format("%s",inet_ntoa(addrclient.sin_addr));
			m_thisdlg->m_listbox.AddString(str);
			m_thisdlg->m_port++;
			char portbuf[5];
			sprintf(portbuf,"%u",m_thisdlg->m_port);
			//m_thisdlg->MessageBox(portbuf);
			send(sockclient,portbuf,5,0);
		}
	}
}

VOID CSRVDlg::Thread_pro(PVOID pvoid)
{
	CListBox *p = (CListBox*)pvoid;
	SOCKET socksrv = socket(AF_INET,SOCK_DGRAM,0);
	bind(socksrv,(sockaddr*)phostaddr,sizeof(sockaddr));
	while(true)
	{
		SOCKADDR_IN addr;
		char recvbuf[200] = "",sendbuf[200];
		int len = sizeof(sockaddr);
		recvfrom(socksrv,recvbuf,200,0,(sockaddr*)&addr,&len);
		sprintf(sendbuf,"����IP��%s����Ϣ��\r\n%s",inet_ntoa(addr.sin_addr),recvbuf);
		CString str;
		m_thisdlg->m_status.GetWindowTextA(str);
		str.Format("%s\r\n���յ���Ϣ��%s\r\n",str.GetBuffer(0),recvbuf);
		m_thisdlg->m_status.SetWindowTextA(str);
		m_thisdlg->m_status.LineScroll(99999);
		for(int i=1;i<p->GetCount();i++)
		{
			
			p->GetText(i,str);
			char *buf = str.GetBuffer(0);
			addr.sin_addr.S_un.S_addr = inet_addr(buf);
			addr.sin_family = AF_INET;
			addr.sin_port = htons(6000+i);
			sendto(socksrv,sendbuf,200,0,(sockaddr*)&addr,sizeof(sockaddr));
		}
	}
	
}
