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
	//_No 0��ʾ�� 1-��/�� 2-�� 3-�� 4-�� 5-��/�� 6-�� 7-˧/��
	//�ڷ��ø��� �췽��������ʾ  ����=1 ��=-1��
	int _type;
	bool _isKing;

};