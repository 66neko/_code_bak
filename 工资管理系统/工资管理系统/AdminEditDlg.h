#pragma once


// CAdminEditDlg �Ի���

class CAdminEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminEditDlg)

public:
	CAdminEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminEditDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
