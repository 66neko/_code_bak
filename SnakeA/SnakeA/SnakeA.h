// SnakeA.h : SnakeA Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSnakeAApp:
// �йش����ʵ�֣������ SnakeA.cpp
//

class CSnakeAApp : public CWinApp
{
public:
	CSnakeAApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSnakeAApp theApp;