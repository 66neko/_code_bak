#include<iostream>
using namespace std;
#pragma once

class ChessmanBase
{
public:
	ChessmanBase();
	~ChessmanBase();
public:
	bool alive;
	int position_x;
	int position_y;
	//color 1=red,-1=black;
	int color;
};

class Chessman:public ChessmanBase
{
public:
	Chessman(int type,int color,int position_x,int position_y);
	Chessman();
	~Chessman();
public:
	//_No 0表示空 1-兵/卒 2-炮 3-车 4-马 5-相/象 6-仕 7-帅/将
	//黑方用负数 红方用正数表示  即兵=1 卒=-1；
	int _type;
	bool _isKing;

};