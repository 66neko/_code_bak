// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ʹ���ϵͳ.h"
#include "UserDlg.h"


// CUserDlg �Ի���

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


// CUserDlg ��Ϣ�������

void CUserDlg::OnBnClickedButtonEx()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::exit(0);
}
