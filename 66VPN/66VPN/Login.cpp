// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "66VPN.h"
#include "Login.h"
#include "Cmysql.h"
#include "66VPNDlg.h"

// CLogin �Ի���

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


// CLogin ��Ϣ�������

void CLogin::OnBnClickedButtionLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//::AfxMessageBox("1");
	CString uid,psw;
	edit_uid.GetWindowTextA(uid);
	edit_psw.GetWindowTextA(psw);
	if(uid.GetLength() == 0 || psw.GetLength() == 0)
	{
		::AfxMessageBox("�û������벻��Ϊ��");
		return;
	}
	Mysql mysql;
	
	if(!mysql.Link())
	{
		::AfxMessageBox("���ӷ�����ʧ�ܣ�");
		return;
	}
	if(mysql.CheckPassword(uid.GetBuffer(),psw.GetBuffer()))
	{
		mysql.Close();
		//::AfxMessageBox("��ȷ");
		EndDialog(1);
	//	CMy66VPNDlg dlg;  // ����������
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	}
	else
	{
		mysql.Close();
		::AfxMessageBox("�û������������");
	}
	//::AfxMessageBox("3");
}
