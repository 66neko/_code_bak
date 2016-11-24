#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"ClientSocket.h"
#include"ClientManager.h"
using namespace  std;
#pragma once

class MainClient :public ClientSocket
{
public:
	MainClient();
	~MainClient();
public:
	bool OnStart(char *_name);
	bool ConnectServer();
	ClientManager _game;
private:
	char name[20];
	char enemyName[20];
};
