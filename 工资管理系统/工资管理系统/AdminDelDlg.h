#pragma once


// CAdminDelDlg �Ի���

class CAdminDelDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdminDelDlg)

public:
	CAdminDelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminDelDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
