#pragma once
#include "afxwin.h"


// CChatDlg �Ի���

struct SOCK_M
{
	SOCKET *socket;
	CEdit *m_edirview;
	SOCKADDR_IN *sockaddr;
};

class CChatDlg : public CDialog
{
	DECLARE_DYNAMIC(CChatDlg)

public:
	CChatDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChatDlg();
	SOCKADDR_IN addrclient;
	static VOID Thread_recvform(PVOID pvoid);
	SOCKET sockclient;

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit m_chatview;
	CEdit m_chatedit;
	
public:
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnPaint();
	u_short m_port;
};
