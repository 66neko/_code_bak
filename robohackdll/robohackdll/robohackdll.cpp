// robohackdll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "robohackdll.h"

// ��ȫ�ּ��̹��ӡ�Ҫдһ��DLL�⡣�������£�
#include <iostream>
#include <windows.h>
using namespace std;
#pragma data_seg("HookData")
HHOOK g_hHook = NULL;
HINSTANCE g_hInstDLL = NULL;
#pragma data_seg()

#pragma comment(linker,"/SECTION:HookData,RWS")

BOOL APIENTRY DllMain(HINSTANCE hInstDLL,DWORD fdwReason, 
					  LPVOID lpvReserved)
{
	g_hInstDLL = hInstDLL;
	return TRUE;
}

// �ص�����
LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	// �������������Ϣ�������
	cout<<"���¼�\n";
	if(((DWORD)lParam&0x40000000) && nCode == HC_ACTION && wParam == VK_SPACE)
	{
		
	}
	// ���¼����ݵ���һ������
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

// ��װ����
extern "C" __declspec(dllexport) VOID InstallHook()
{
	g_hHook = SetWindowsHookEx(WH_KEYBOARD, HookProc,g_hInstDLL, 0);
	if(g_hHook != NULL)
	{
		cout<<"���سɹ�"<<endl;
	}
}

// ж�ع���
extern "C" __declspec(dllexport) void KillHook()
{
	UnhookWindowsHookEx(g_hHook);
}

/* Copyrights (C) 2010 ����ǽ�. All rights reserved. */ 
