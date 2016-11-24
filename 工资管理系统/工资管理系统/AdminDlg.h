#include "stdafx.h"
#pragma once


// CAdminDlg 对话框

class CAdminDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdduser();
	afx_msg void OnBnClickedButtonEdituser();
	afx_msg void OnBnClickedButtonDeleteuser();
};
