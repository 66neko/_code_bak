// robohackdll.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "robohackdll.h"

// 用全局键盘钩子。要写一个DLL库。代码如下：
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

// 回调函数
LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	// 请在这里添加消息处理代码
	cout<<"按下键\n";
	if(((DWORD)lParam&0x40000000) && nCode == HC_ACTION && wParam == VK_SPACE)
	{
		
	}
	// 将事件传递到下一个钩子
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

// 安装钩子
extern "C" __declspec(dllexport) VOID InstallHook()
{
	g_hHook = SetWindowsHookEx(WH_KEYBOARD, HookProc,g_hInstDLL, 0);
	if(g_hHook != NULL)
	{
		cout<<"加载成功"<<endl;
	}
}

// 卸载钩子
extern "C" __declspec(dllexport) void KillHook()
{
	UnhookWindowsHookEx(g_hHook);
}

/* Copyrights (C) 2010 夺魂狼剑. All rights reserved. */ 
