#include<iostream>
#include<ctime>
#include<cstdlib>
#include<queue>
#include"InternetManager.h"
#include"GameManager.h"
using namespace  std;
#pragma once

#define MAXTHREAD 10;



class MainServer :public InternetManager
{
public:
	MainServer();
	~MainServer();
public:
	void OnStart();
	void AcceptPlayer();
	static void Thread_game(void *_port);
private:
	int _maxThread;
	queue<u_short> _portQueue;
};

struct ThreadPara
{
	MainServer *_mainServer;
	u_short port;
};