#include "stdafx.h"
#pragma once


// CAdminDlg �Ի���

class CAdminDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdduser();
	afx_msg void OnBnClickedButtonEdituser();
	afx_msg void OnBnClickedButtonDeleteuser();
};
