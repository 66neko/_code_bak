#include"ChessmanBase.h"

ChessmanBase::ChessmanBase()
{
	this->alive = 1;
	this->color = 0;
	this->position_x = 0;
	this->position_y = 0;
}

ChessmanBase::~ChessmanBase()
{
}

Chessman::Chessman(int type,int color,int position_x,int position_y)
{
	this->_type = type;
	if (type == 7)
		this->_isKing = true;
	else
		this->_isKing = false;
	this->color = color;
	this->position_x = position_x;
	this->position_y = position_y;
}

Chessman::Chessman()
{
	this->_type = 999;
	this->_isKing = false;
	this->color = 0;
	this->position_x = -1;
	this->position_y = -1;
}

Chessman::~Chessman()
{
}