// ���ʹ���ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMainDlgApp:
// �йش����ʵ�֣������ ���ʹ���ϵͳ.cpp
//

class CMainDlgApp : public CWinApp
{
public:
	CMainDlgApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMainDlgApp theApp;