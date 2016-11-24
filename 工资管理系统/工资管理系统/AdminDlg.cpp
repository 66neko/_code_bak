// AdminDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "工资管理系统.h"
#include "AdminDlg.h"
#include "AdminAddDlg.h"
#include "AdminEditDlg.h"
#include "AdminDelDlg.h"


// CAdminDlg 对话框

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


// CAdminDlg 消息处理程序

//新增员工
void CAdminDlg::OnBnClickedButtonAdduser()
{
	// TODO: 在此添加控件通知处理程序代码
	AdminAddDlg AAdd;
	AAdd.DoModal();
}

void CAdminDlg::OnBnClickedButtonEdituser()
{
	// TODO: 在此添加控件通知处理程序代码
	CAdminEditDlg AEdit;
	AEdit.DoModal();
}

void CAdminDlg::OnBnClickedButtonDeleteuser()
{
	// TODO: 在此添加控件通知处理程序代码
	CAdminDelDlg ADel;
	ADel.DoModal();
}
