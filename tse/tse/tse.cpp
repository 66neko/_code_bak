// tse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "tse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
{
	CWnd *wnds = CWnd::FromHandle(hwnd);
	CString str;
	wnds->GetWindowText(str);
	printf("%s\n",str.GetBuffer());
	if (str == "ͨ��֤")
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

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		/*
		_tprintf(_T("init is ok\n"));
		CWnd *wnd = CWnd::FindWindow(NULL,"11��սƽ̨ - 1.1.5.6");
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
