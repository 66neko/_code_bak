// robocrafthack.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CrobocrafthackApp:
// �йش����ʵ�֣������ robocrafthack.cpp
//

class CrobocrafthackApp : public CWinApp
{
public:
	CrobocrafthackApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CrobocrafthackApp theApp;