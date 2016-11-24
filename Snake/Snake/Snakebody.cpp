#include "StdAfx.h"
#include "Snakebody.h"



Snakebody::Snakebody(CClientDC *pDC)
{
	for (unsigned int i=1;i<=body.size();i++)
	{
		body.pop();
	}
	for (int i=1;i<=3;i++)
	{
		body.push(Cell(3,i+3));
		pDC->StretchBlt(3*10,(i+3)*10,10,10,pDC,0,0,10,10,BLACKNESS);

	}
}

Snakebody::~Snakebody(void)
{
}

bool Snakebody::move(int direction, CClientDC *pDC)
{
	switch(direction)
	{
	case UP:
		pDC->StretchBlt(body.front().x*10,body.front().y*10,10,10,pDC,0,0,10,10,WHITENESS);
		body.pop();
		body.push(Cell(body.back().x,body.back().y - 1));
		if(!cheak())
		{
			return false;
		}
		pDC->StretchBlt(body.back().x*10,body.back().y*10,10,10,pDC,0,0,10,10,BLACKNESS);
		break;
	case DOWN:
		pDC->StretchBlt(body.front().x*10,body.front().y*10,10,10,pDC,0,0,10,10,WHITENESS);
		body.pop();
		body.push(Cell(body.back().x,body.back().y + 1));
		if(!cheak())
		{
			return false;
		}
		pDC->StretchBlt(body.back().x*10,body.back().y*10,10,10,pDC,0,0,10,10,BLACKNESS);
		break;
	case LEFT:
		pDC->StretchBlt(body.front().x*10,body.front().y*10,10,10,pDC,0,0,10,10,WHITENESS);
		body.pop();
		body.push(Cell(body.back().x - 1,body.back().y));
		if(!cheak())
		{
			return false;
		}
		pDC->StretchBlt(body.back().x*10,body.back().y*10,10,10,pDC,0,0,10,10,BLACKNESS);
		break;
	case RIGHT:
		pDC->StretchBlt(body.front().x*10,body.front().y*10,10,10,pDC,0,0,10,10,WHITENESS);
		body.pop();
		body.push(Cell(body.back().x + 1,body.back().y));
		if(!cheak())
		{
			return false;
		}
		pDC->StretchBlt(body.back().x*10,body.back().y*10,10,10,pDC,0,0,10,10,BLACKNESS);
		break;
	}
	return true;
}

bool Snakebody::cheak()
{
	if(body.back().x < 0 || body.back().y < 0
		||body.back().x >=30 || body.back().y >= 30)
	{
		return false;
	}
	queue<Cell> q;
	q = body;
	for (unsigned int i=1;i<body.size();i++)
	{
		if (body.back().x == q.front().x && body.back().y == q.front().y)
		{
			return false;
		}
		else
		{
			q.pop();
		}
	}
	return true;
}

void Snakebody::add(Cell food,CClientDC *pDC)
{
	body.push(food);
}

Cell Snakebody::head()
{
	return body.back();
}

bool Snakebody::foodcheak(Cell food)
{
	queue<Cell> q;
	q = body;
	for (unsigned int i=1;i<=body.size();i++)
	{
		if (food.x == q.front().x && food.y == q.front().y)
		{
			return false;
		}
		else
		{
			q.pop();
		}
	}
	return true;
}

int Snakebody::snakesize()
{
	return body.size();
}