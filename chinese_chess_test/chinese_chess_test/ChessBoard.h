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
	//检查是否胜利 retrun 0=胜负未分 1=红方胜 -1=黑方胜。
	int GetVictory();
	//悔棋
	bool BackChessman();
private:
	Chessman *GetChessmanFromABS(int _kx,int _ky);
	
	bool CheakChessmanFromMap(Chessman *_chessman,int x,int y);
	void UpdateBase(Chessman *_chessman);
	void InitChessmanBase(Chessman *&_chessman,int type,int color,int _pos_x,int _pos_y);
	
private:
	//悔棋标记 0=不能悔棋 1=只需要修改1颗棋子A  2=需要修改两颗棋子A and B.
	int _backFlag;
	int _backRound;
	//棋子标记
	Chessman *_backRedA,*_backRedB,*_backBlackA,*_backBlackB;
	//悔棋缓冲区
	Chessman _backChessmanRedA,_backChessmanRedB,_backChessmanBlackA,_backChessmanBlackB;
	//红色棋子
	Chessman *chessman_red_bin1,*chessman_red_bin2,*chessman_red_bin3,*chessman_red_bin4,*chessman_red_bin5,
			 *chessman_red_pao1,*chessman_red_pao2,
			 *chessman_red_ju1,*chessman_red_ju2,
			 *chessman_red_ma1,*chessman_red_ma2,
			 *chessman_red_xiang1,*chessman_red_xiang2,
			 *chessman_red_shi1,*chessman_red_shi2,
			 *chessman_red_shuai;
	//黑色棋子
	Chessman *chessman_black_zu1,*chessman_black_zu2,*chessman_black_zu3,*chessman_black_zu4,*chessman_black_zu5,
			 *chessman_black_pao1,*chessman_black_pao2,
			 *chessman_black_ju1,*chessman_black_ju2,
			 *chessman_black_ma1,*chessman_black_ma2,
			 *chessman_black_xiang1,*chessman_black_xiang2,
			 *chessman_black_shi1,*chessman_black_shi2,
			 *chessman_black_jiang;
};