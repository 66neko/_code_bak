// SRVDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CSRVDlg �Ի���
class CSRVDlg : public CDialog
{
// ����
public:
	CSRVDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SRV_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CStatic m_IPaddr;
	CEdit m_status;
	CListBox m_listbox;
public:
	afx_msg void OnBnClickedButton1();
public:
	static VOID Thread_srv(PVOID pvoid);
	static VOID Thread_pro(PVOID pvoid);
private:
	static CSRVDlg* m_thisdlg;
public:
	// �˿ںŶ�̬����
	u_short m_port;
};
