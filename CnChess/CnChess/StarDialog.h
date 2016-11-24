#pragma once
#include "afxwin.h"


// CStarDialog 对话框

class CStarDialog : public CDialog
{
	DECLARE_DYNAMIC(CStarDialog)

public:
	CStarDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStarDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_START };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_nameEdit;
	afx_msg void OnBnClickedOk();
	//个人添加
	CString _myName;
};
