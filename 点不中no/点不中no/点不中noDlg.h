// �㲻��noDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C�㲻��noDlg �Ի���
class C�㲻��noDlg : public CDialog
{
// ����
public:
	C�㲻��noDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NO_DIALOG };

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
private:
	CStatic m_left;
	CStatic m_top;
	CStatic m_right;
	CStatic m_bottom;
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CButton m_no;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
