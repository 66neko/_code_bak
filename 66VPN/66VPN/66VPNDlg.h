// 66VPNDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "cvpn.h"


// CMy66VPNDlg 对话框
class CMy66VPNDlg : public CDialog
{
// 构造
public:
	CMy66VPNDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY66VPN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonExit();
	Cvpn m_vpn;
private:
	CButton m_btm_con;
public:
	CButton m_btm_discon;
	afx_msg void OnBnClickedButtonDisconnect();
	CComboBox m_ComboBox;
};
