#pragma once


// AdminAddDlg 对话框

class AdminAddDlg : public CDialog
{
	DECLARE_DYNAMIC(AdminAddDlg)

public:
	AdminAddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AdminAddDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
