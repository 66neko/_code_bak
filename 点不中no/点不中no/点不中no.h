// �㲻��no.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�㲻��noApp:
// �йش����ʵ�֣������ �㲻��no.cpp
//

class C�㲻��noApp : public CWinApp
{
public:
	C�㲻��noApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�㲻��noApp theApp;