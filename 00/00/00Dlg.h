// 00Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy00Dlg �Ի���
class CMy00Dlg : public CDialog
{
// ����
public:
	CMy00Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY00_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
