// 66VPNDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "cvpn.h"


// CMy66VPNDlg �Ի���
class CMy66VPNDlg : public CDialog
{
// ����
public:
	CMy66VPNDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY66VPN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
