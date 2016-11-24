// AdminAddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "工资管理系统.h"
#include "AdminAddDlg.h"


// AdminAddDlg 对话框

IMPLEMENT_DYNAMIC(AdminAddDlg, CDialog)

AdminAddDlg::AdminAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AdminAddDlg::IDD, pParent)
{

}

AdminAddDlg::~AdminAddDlg()
{
}

void AdminAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminAddDlg, CDialog)
END_MESSAGE_MAP()


// AdminAddDlg 消息处理程序
