// AdminEditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "工资管理系统.h"
#include "AdminEditDlg.h"


// CAdminEditDlg 对话框

IMPLEMENT_DYNAMIC(CAdminEditDlg, CDialog)

CAdminEditDlg::CAdminEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminEditDlg::IDD, pParent)
{

}

CAdminEditDlg::~CAdminEditDlg()
{
}

void CAdminEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminEditDlg, CDialog)
END_MESSAGE_MAP()


// CAdminEditDlg 消息处理程序
