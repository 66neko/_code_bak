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
	//_player表示当前可以移动棋子的棋手 1=红色，-1=黑色，默认红色先走。
	int _player;
	//游戏进行状态 1=正在进行 0=游戏结束
	int _state;
	//自身颜色 规则=_player
	int _myColor;
	ClientSocket _clientSocket;
};