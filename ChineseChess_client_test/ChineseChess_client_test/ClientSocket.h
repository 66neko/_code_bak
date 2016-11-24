#include <Winsock2.h>
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <iostream>
using namespace  std;
#pragma comment(lib,"ws2_32.lib")
#pragma once


class ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();
public:
	void Init(u_short _port);
	bool Connect(char *_color);
	bool TranslateRecvClientToServer(char *str,int *_kx,int *_ky,int *_dx,int * _dy);
	bool TranslateSendClientToServer(char *str,int _kx,int _ky,int _dx,int _dy);
	bool TranslateSendServerToClient(char *str,int map[][9],int _player,int _state,int _feedback);
	bool TranslateRecvServerToClient(char *str,int map[][9],int *_player,int *_state,int *_feedback);
	void SendMessage(char *sendbuff);
	void RecvMessage(char *recvbuff);
	void CloseSocket();
	//��ȡ�������״̬
	int GetPlayerState();
public:
	SOCKET socketclient;
	SOCKADDR_IN addrsrv;
private:
	
	
	//����״̬ 0 = ���� 1=����
	int _online;
};