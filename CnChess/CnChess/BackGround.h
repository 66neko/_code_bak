#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"Chess/ClientSocket.h"
#include"Chess/ClientManager.h"
using namespace  std;
#pragma once

class BackGround
{
public:
	BackGround(MainClient *p);
	~BackGround();
public:
	void OnStart();
	static void Thread_BackGround(void *p);
private:
	MainClient *pclient;
};