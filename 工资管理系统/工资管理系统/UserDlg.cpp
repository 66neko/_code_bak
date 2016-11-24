// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "工资管理系统.h"
#include "UserDlg.h"


// CUserDlg 对话框

IMPLEMENT_DYNAMIC(CUserDlg, CDialog)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_EX, &CUserDlg::OnBnClickedButtonEx)
END_MESSAGE_MAP()


// CUserDlg 消息处理程序

void CUserDlg::OnBnClickedButtonEx()
{
	// TODO: 在此添加控件通知处理程序代码
	::exit(0);
}
