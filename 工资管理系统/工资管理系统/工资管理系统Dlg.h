// ���ʹ���ϵͳDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C���ʹ���ϵͳDlg �Ի���
class C���ʹ���ϵͳDlg : public CDialog
{
// ����
public:
	C���ʹ���ϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit C_ID;
	CEdit C_PASSWORD;
	afx_msg void OnBnClickedButtonGuest();
	afx_msg void OnBnClickedButtonAdmin();
};
