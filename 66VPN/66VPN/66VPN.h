// 66VPN.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy66VPNApp:
// �йش����ʵ�֣������ 66VPN.cpp
//

class CMy66VPNApp : public CWinApp
{
public:
	CMy66VPNApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy66VPNApp theApp;