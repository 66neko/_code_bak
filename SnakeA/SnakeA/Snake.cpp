#include "StdAfx.h"
#include "Snake.h"

CSnake::CSnake(void)
{
	this->direction = DOWN;
	this->time = 500.0;
	while(body.size())
	{
		body.pop();
	}
	for (int i=1;i<=3;i++)
	{
		body.push(Cell(3,3+i));
	}
}

CSnake::~CSnake(void)
{
}

bool CSnake::cheak()
{
	switch (direction)
	{
	case UP:
		return compare(Cell(body.back().x,body.back().y-1));
		break;
	case DOWN:
		return compare(Cell(body.back().x,body.back().y+1));
		break;
	case LEFT:
		return compare(Cell(body.back().x-1,body.back().y));
		break;
	case RIGHT:
		return compare(Cell(body.back().x+1,body.back().y));
		break;
	default:
		return false;
		break;
	}
}

bool CSnake::compare(Cell cell)
{
	if (cell.x < 0 || cell.x >= MAPWIDTH || cell.y < 0 || cell.y >= MAPHEIGHT)
	{
		return false;
	}
	queue<Cell> k = body;
	while (k.size())
	{
		if(cell.x == k.front().x && cell.y == k.front().y)
			return false;
		k.pop();
	}
	return true;
}

bool CSnake::move(Cell food)
{
	if (!cheak()) 
	{
		return false;
	}
	switch (direction)
	{
	case UP:
		if(food.x == body.back().x && food.y == body.back().y-1) 
		{
			eat(food);
			return true;
		}
		body.pop();
		body.push(Cell(body.back().x,body.back().y-1));
		break;
	case DOWN:
		if(food.x == body.back().x && food.y == body.back().y+1) 
		{
			eat(food);
			return true;
		}
		body.pop();
		body.push(Cell(body.back().x,body.back().y+1));
		break;
	case LEFT:
		if(food.x == body.back().x-1 && food.y == body.back().y) 
		{
			eat(food);
			return true;
		}
		body.pop();
		body.push(Cell(body.back().x-1,body.back().y));
		break;
	case RIGHT:
		if(food.x == body.back().x+1 && food.y == body.back().y) 
		{
			eat(food);
			return true;
		}
		body.pop();
		body.push(Cell(body.back().x+1,body.back().y));
		break;
	}
	return false;
}
void CSnake::eat(Cell food)
{
	body.push(food);
	time *= 0.9;
	return;
}

queue<Cell> CSnake::outbody()
{
	return body;
}