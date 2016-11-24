#include<iostream>
#include"ChessBoard.h"
#include"InternetManager.h"
using namespace std;
#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();
public:
	ChessBoard _chessboard;
	//下棋方法，若_kx>=10则跳过(pass).若_kx<0则悔棋(back).
	bool PlayingChess(int _kx,int _ky,int _dx,int _dy);
	bool GetGameState();
	void GameBegin(u_short _port);
	void GameProcess();
private:
	//_player表示当前可以移动棋子的棋手 1=红色，-1=黑色，默认红色先走。
	int _player;
	//游戏进行状态 1=正在进行 0=游戏结束
	int _state;
	void SwitchPlayer();
	InternetManager _netManager;
};