// CnChess.h : CnChess Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCnChessApp:
// �йش����ʵ�֣������ CnChess.cpp
//

class CCnChessApp : public CWinApp
{
public:
	CCnChessApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	int CCnChessApp::ExitInstance();
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	ULONG_PTR m_gdiplusToken;
};

extern CCnChessApp theApp;