// StarDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CnChess.h"
#include "StarDialog.h"


// CStarDialog 对话框

IMPLEMENT_DYNAMIC(CStarDialog, CDialog)

CStarDialog::CStarDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CStarDialog::IDD, pParent)
{

}

CStarDialog::~CStarDialog()
{
}

void CStarDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_nameEdit);
	CString m_strName;
	DDX_Text(pDX, IDC_EDIT_ID, m_strName); 
	DDV_MaxChars(pDX, m_strName, 14);
}


BEGIN_MESSAGE_MAP(CStarDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CStarDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CStarDialog 消息处理程序

void CStarDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nameEdit.GetWindowTextA(_myName);
	if(_myName.GetLength() > 15)
	{
		this->MessageBox("昵称太长！");
		return;
	}
	if(_myName.GetLength() == 0)
	{
		this->MessageBox("昵称不能为空！");
		return;
	}
	OnOK();
}
