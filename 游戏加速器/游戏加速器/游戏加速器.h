// ��Ϸ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVPNApp:
// �йش����ʵ�֣������ ��Ϸ������.cpp
//

class CVPNApp : public CWinApp
{
public:
	CVPNApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVPNApp theApp;