// 00Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy00Dlg 对话框
class CMy00Dlg : public CDialog
{
// 构造
public:
	CMy00Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY00_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_1;
	CEdit m_2;
	CEdit m_3;
	afx_msg void OnBnClickedOk();
};
