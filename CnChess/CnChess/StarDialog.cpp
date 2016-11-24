// StarDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CnChess.h"
#include "StarDialog.h"


// CStarDialog �Ի���

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


// CStarDialog ��Ϣ�������

void CStarDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nameEdit.GetWindowTextA(_myName);
	if(_myName.GetLength() > 15)
	{
		this->MessageBox("�ǳ�̫����");
		return;
	}
	if(_myName.GetLength() == 0)
	{
		this->MessageBox("�ǳƲ���Ϊ�գ�");
		return;
	}
	OnOK();
}
