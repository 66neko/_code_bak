#pragma once


// CAdminEditDlg 对话框

class CAdminEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminEditDlg)

public:
	CAdminEditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminEditDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
