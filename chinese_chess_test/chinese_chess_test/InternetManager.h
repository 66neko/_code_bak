#include <Winsock2.h>
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <iostream>
using namespace  std;
#pragma comment(lib,"ws2_32.lib")
#pragma once

class InternetManager
{
public:
	InternetManager();
	~InternetManager();
public:
	bool Init(u_short _port);
	void Listen();
	void AcceptRedAndBlack();
	void SendMessageRed(char *sendbuff);
	void SendMessageBlack(char *sendbuff);
	void RecvMessageFormRed(char *recvbuff);
	void RecvMessageFormBlack(char *recvbuff);
	bool TranslateRecvClientToServer(char *str,int *_kx,int *_ky,int *_dx,int * _dy);
	bool TranslateSendClientToServer(char *str,int _kx,int _ky,int _dx,int _dy);
	bool TranslateSendServerToClient(char *str,int map[][9],int _player,int _state,int _feedback);
	bool TranslateRecvServerToClient(char *str,int map[][9],int *_player,int *_state,int *_feedback);
	//��ȡ���״̬ 0=���� 1=��ɫ������ 2=��ɫ������ 3=ȫ��������
	int GetPlayerState();
private:
	void SendMessage(SOCKET *_socket,char *sendbuff);
	void RecvMessage(SOCKET *_socket,char *recvbuff);
	bool Accept(SOCKET *_socket,SOCKADDR_IN *_addr);
	void CloseSocket(SOCKET *_socket);
public:
	SOCKET sockets;
private:
	SOCKADDR_IN addrClientRed;
	SOCKET socketClientRed;
	SOCKADDR_IN addrClientBlack;
	SOCKET socketClientBlack;
	//�������״̬
	int _redOnline;
	int _blackOnline;
};