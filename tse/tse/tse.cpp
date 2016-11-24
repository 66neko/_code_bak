// tse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
{
	CWnd *wnds = CWnd::FromHandle(hwnd);
	CString str;
	wnds->GetWindowText(str);
	printf("%s\n",str.GetBuffer());
	if (str == "通行证")
	{
		wnds->SetWindowTextA("132");
		printf("yes\n");
		return 0;
	}
	return TRUE;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此处为应用程序的行为编写代码。
		/*
		_tprintf(_T("init is ok\n"));
		CWnd *wnd = CWnd::FindWindow(NULL,"11对战平台 - 1.1.5.6");
		CString str;
		wnd->GetWindowText(str);
		printf("%s\n",str.GetBuffer());
		wnd->SetWindowPos(&CWnd::wndTop,0,0,0,0,SWP_NOSIZE);
		::EnumChildWindows(wnd->m_hWnd,EnumChildProc,0);
		*/
		while(true)keybd_event(65,0,0,0);
	}

	return nRetCode;
}
