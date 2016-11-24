#include <iostream>
#include <windows.h>

void main()
{
	HWND hwnd;
	hwnd = FindWindow(NULL,"1 - ¼ÇÊÂ±¾");
	char str[1000];
	GetWindowText(hwnd,str,100);
	std::cout<<str;
	SetCursorPos(0,0);
}