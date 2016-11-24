// FindDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CnChess.h"
#include "FindDialog.h"


// CFindDialog �Ի���

IMPLEMENT_DYNAMIC(CFindDialog, CDialog)

CFindDialog::CFindDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDialog::IDD, pParent)
{
	flag = 0;
}

CFindDialog::~CFindDialog()
{
}

void CFindDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TIME, m_time);
}


BEGIN_MESSAGE_MAP(CFindDialog, CDialog)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CFindDialog ��Ϣ�������

int CFindDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(1,1000,NULL);
	// TODO:  �ڴ������ר�õĴ�������
	p_back->OnStart();
	if(_sharing._findState == 1)
	{
		flag = 1;
	}
	
	return 0;
}

void CFindDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent == 1)
	{
		if(_sharing._findState == 1)
		{
			flag = 1;
		}
		if(_sharing._findState == 2)
		{
			KillTimer(1);
			MessageBox("Ѱ�Ҷ���ʧ�ܣ������ԣ�");
			
			OnOK();
		}
		CString str;
		m_time.GetWindowTextA(str);
		int a = atoi(str.GetBuffer());
		char s[10] = "";
		_itoa_s(a+1,s,10,10);
		m_time.SetWindowTextA(s);
		if(flag == 1)
		{
			CMenu *pMenu;
			pMenu = AfxGetMainWnd()->GetMenu();
			pMenu->EnableMenuItem(ID_HUIQI, MF_ENABLED);
			KillTimer(1);
			OnOK();
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CFindDialog::SetMainClient(BackGround *_pBack)
{
	this->p_back = _pBack;
	return;
}