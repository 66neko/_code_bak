#pragma once
#include "afxwin.h"


// CStarDialog �Ի���

class CStarDialog : public CDialog
{
	DECLARE_DYNAMIC(CStarDialog)

public:
	CStarDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStarDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_START };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_nameEdit;
	afx_msg void OnBnClickedOk();
	//�������
	CString _myName;
};
