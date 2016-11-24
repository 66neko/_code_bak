#pragma once
#include "afxwin.h"


// CFindDialog 对话框

class CFindDialog : public CDialog
{
	DECLARE_DYNAMIC(CFindDialog)

public:
	CFindDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFindDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_FIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_time;
	BackGround *p_back;
	void SetMainClient(BackGround *_pBack);
	int flag;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
