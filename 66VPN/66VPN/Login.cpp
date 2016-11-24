// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "66VPN.h"
#include "Login.h"
#include "Cmysql.h"
#include "66VPNDlg.h"

// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialog)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UID, edit_uid);
	DDX_Control(pDX, IDC_PSW, edit_psw);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	ON_BN_CLICKED(IDC_BUTTION_LOGIN, &CLogin::OnBnClickedButtionLogin)
END_MESSAGE_MAP()


// CLogin 消息处理程序

void CLogin::OnBnClickedButtionLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	//::AfxMessageBox("1");
	CString uid,psw;
	edit_uid.GetWindowTextA(uid);
	edit_psw.GetWindowTextA(psw);
	if(uid.GetLength() == 0 || psw.GetLength() == 0)
	{
		::AfxMessageBox("用户名密码不能为空");
		return;
	}
	Mysql mysql;
	
	if(!mysql.Link())
	{
		::AfxMessageBox("连接服务器失败！");
		return;
	}
	if(mysql.CheckPassword(uid.GetBuffer(),psw.GetBuffer()))
	{
		mysql.Close();
		//::AfxMessageBox("正确");
		EndDialog(1);
	//	CMy66VPNDlg dlg;  // 启动主窗口
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	}
	else
	{
		mysql.Close();
		::AfxMessageBox("用户名或密码错误！");
	}
	//::AfxMessageBox("3");
}
