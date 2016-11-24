#pragma once


// CAdminDelDlg 对话框

class CAdminDelDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminDelDlg)

public:
	CAdminDelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminDelDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_DELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
