#include<iostream>
#include<cmath>
#include"ChessmanBase.h"
using namespace std;
#pragma once

#define CHESSMAN_COLOR_RED 1
#define CHESSMAN_COLOR_BLACK -1
#define CHESSMAN_TYPE_BIN 1
#define CHESSMAN_TYPE_ZU 1
#define CHESSMAN_TYPE_PAO 2
#define CHESSMAN_TYPE_JU 3
#define CHESSMAN_TYPE_MA 4
#define CHESSMAN_TYPE_XIANG 5
#define CHESSMAN_TYPE_SHI 6
#define CHESSMAN_TYPE_SHUAI 7
#define CHESSMAN_TYPE_JIANG 7
class ChessBoard
{
public:
	int map[10][9];
public:
	ChessBoard();
	~ChessBoard();
public:
	bool Init();
	void Debug_Print();
	void Update();
	bool Debug_Move(int _kx,int _ky,int _dx,int _dy);
	bool CheakMoveRule(int _type,int _kx,int _ky,int _dx,int _dy);
	//����Ƿ�ʤ�� retrun 0=ʤ��δ�� 1=�췽ʤ -1=�ڷ�ʤ��
	int GetVictory();
	//����
	bool BackChessman();
private:
	Chessman *GetChessmanFromABS(int _kx,int _ky);
	
	bool CheakChessmanFromMap(Chessman *_chessman,int x,int y);
	void UpdateBase(Chessman *_chessman);
	void InitChessmanBase(Chessman *&_chessman,int type,int color,int _pos_x,int _pos_y);
	
private:
	//������ 0=���ܻ��� 1=ֻ��Ҫ�޸�1������A  2=��Ҫ�޸���������A and B.
	int _backFlag;
	int _backRound;
	//���ӱ��
	Chessman *_backRedA,*_backRedB,*_backBlackA,*_backBlackB;
	//���建����
	Chessman _backChessmanRedA,_backChessmanRedB,_backChessmanBlackA,_backChessmanBlackB;
	//��ɫ����
	Chessman *chessman_red_bin1,*chessman_red_bin2,*chessman_red_bin3,*chessman_red_bin4,*chessman_red_bin5,
			 *chessman_red_pao1,*chessman_red_pao2,
			 *chessman_red_ju1,*chessman_red_ju2,
			 *chessman_red_ma1,*chessman_red_ma2,
			 *chessman_red_xiang1,*chessman_red_xiang2,
			 *chessman_red_shi1,*chessman_red_shi2,
			 *chessman_red_shuai;
	//��ɫ����
	Chessman *chessman_black_zu1,*chessman_black_zu2,*chessman_black_zu3,*chessman_black_zu4,*chessman_black_zu5,
			 *chessman_black_pao1,*chessman_black_pao2,
			 *chessman_black_ju1,*chessman_black_ju2,
			 *chessman_black_ma1,*chessman_black_ma2,
			 *chessman_black_xiang1,*chessman_black_xiang2,
			 *chessman_black_shi1,*chessman_black_shi2,
			 *chessman_black_jiang;
};