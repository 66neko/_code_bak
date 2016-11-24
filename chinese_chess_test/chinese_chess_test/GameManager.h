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
	//���巽������_kx>=10������(pass).��_kx<0�����(back).
	bool PlayingChess(int _kx,int _ky,int _dx,int _dy);
	bool GetGameState();
	void GameBegin(u_short _port);
	void GameProcess();
private:
	//_player��ʾ��ǰ�����ƶ����ӵ����� 1=��ɫ��-1=��ɫ��Ĭ�Ϻ�ɫ���ߡ�
	int _player;
	//��Ϸ����״̬ 1=���ڽ��� 0=��Ϸ����
	int _state;
	void SwitchPlayer();
	InternetManager _netManager;
};