#include<iostream>
#include"ChessBoard.h"
#include"ClientSocket.h"
using namespace std;
#pragma once

class ClientManager
{
public:
	ClientManager();
	~ClientManager();
public:
	ChessBoard _chessboard;
	bool Start(char *color,u_short _port);
	void GameProcess();
private:
	//_player��ʾ��ǰ�����ƶ����ӵ����� 1=��ɫ��-1=��ɫ��Ĭ�Ϻ�ɫ���ߡ�
	int _player;
	//��Ϸ����״̬ 1=���ڽ��� 0=��Ϸ����
	int _state;
	//������ɫ ����=_player
	int _myColor;
	ClientSocket _clientSocket;
};