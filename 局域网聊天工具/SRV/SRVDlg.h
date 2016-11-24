// SRVDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CSRVDlg 对话框
class CSRVDlg : public CDialog
{
// 构造
public:
	CSRVDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SRV_DIALOG };

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
	// 端口号动态分配
	u_short m_port;
};
