// robocrafthackDlg.h : ͷ�ļ�
//

#pragma once

typedef void(*Dllfun)();
// CrobocrafthackDlg �Ի���
class CrobocrafthackDlg : public CDialog
{
// ����
public:
	CrobocrafthackDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ROBOCRAFTHACK_DIALOG };

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
	afx_msg void OnBnClickedOk();
	
	HINSTANCE hdll;
	Dllfun InstallHook,KillHook;
	
	afx_msg void OnBnClickedCancel();
	int flag;
};
