#pragma once


// AdminAddDlg �Ի���

class AdminAddDlg : public CDialog
{
	DECLARE_DYNAMIC(AdminAddDlg)

public:
	AdminAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AdminAddDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
