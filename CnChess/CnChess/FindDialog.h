#pragma once
#include "afxwin.h"


// CFindDialog �Ի���

class CFindDialog : public CDialog
{
	DECLARE_DYNAMIC(CFindDialog)

public:
	CFindDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_FIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_time;
	BackGround *p_back;
	void SetMainClient(BackGround *_pBack);
	int flag;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
