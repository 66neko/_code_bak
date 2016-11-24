// AdminDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ʹ���ϵͳ.h"
#include "AdminDlg.h"
#include "AdminAddDlg.h"
#include "AdminEditDlg.h"
#include "AdminDelDlg.h"


// CAdminDlg �Ի���

IMPLEMENT_DYNAMIC(CAdminDlg, CDialog)

CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminDlg::IDD, pParent)
{

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADDUSER, &CAdminDlg::OnBnClickedButtonAdduser)
	ON_BN_CLICKED(IDC_BUTTON_EDITUSER, &CAdminDlg::OnBnClickedButtonEdituser)
	ON_BN_CLICKED(IDC_BUTTON_DELETEUSER, &CAdminDlg::OnBnClickedButtonDeleteuser)
END_MESSAGE_MAP()


// CAdminDlg ��Ϣ�������

//����Ա��
void CAdminDlg::OnBnClickedButtonAdduser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AdminAddDlg AAdd;
	AAdd.DoModal();
}

void CAdminDlg::OnBnClickedButtonEdituser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAdminEditDlg AEdit;
	AEdit.DoModal();
}

void CAdminDlg::OnBnClickedButtonDeleteuser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAdminDelDlg ADel;
	ADel.DoModal();
}
