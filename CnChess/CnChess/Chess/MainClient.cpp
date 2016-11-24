#include "stdafx.h"
#include"MainClient.h"

MainClient::MainClient()
{
	memset(name,0,sizeof(name));
	memset(enemyName,0,sizeof(enemyName));
}

MainClient::~MainClient()
{
}

bool MainClient::OnStart(char *_name)
{
	if(strlen(_name) > 16)
	{
		return false;
	}
	strcpy_s(this->name,20,_name);
	Init(6666);
	if(this->ConnectServer())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MainClient::ConnectServer()
{
	cout<<"匹配对手中....."<<endl;
	if(connect(socketclient,(SOCKADDR*)&addrsrv,sizeof(SOCKADDR)) == -1)
	{
		_sharing._findState = 2;
		printf("连接失败！\n");
		return false;
	}
	if(send(socketclient,name,strlen(name)+1,0) == SOCKET_ERROR)
	{
		_sharing._findState = 2;
		cout<<"网络连接中断"<<endl;
		closesocket(socketclient);
		return false;
	}
	char recvbuff[30] = "";
	if(recv(socketclient,recvbuff,30,0) <= 0)
	{
		_sharing._findState = 2;
		cout<<"网络连接中断"<<endl;
		closesocket(socketclient);
		return false;
	}
	//解码数据
	char _myColor;
	u_short port;
	char _strPort[5] = "";
	_myColor = recvbuff[0];
	_strPort[0] = recvbuff[1];
	_strPort[1] = recvbuff[2];
	_strPort[2] = recvbuff[3];
	_strPort[3] = recvbuff[4];
	_strPort[4] = '\0';
	port = (u_short)atoi(_strPort);
	strcpy_s(enemyName,20,&recvbuff[5]);
	strcpy_s(_sharing.EnemyName,20,&recvbuff[5]);
	//end
	if(_myColor == 'R')
	{
		_sharing._myColor = 1;
		//MessageBox(0,"1",NULL,0);
	}
	else
	{
		_sharing._myColor = -1;
		//MessageBox(0,"-1",NULL,0);
	}
	
	//游戏开始
	cout<<"寻找到游戏对手,即将开始游戏"<<endl;
	_sharing._findState = 1;
	_sharing._state = 1;
	while(!_game.Start(&_myColor,port))
	{
		Sleep(500);
	}
	_game.GameProcess();
	return true;
}