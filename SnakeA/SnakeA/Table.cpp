#include "StdAfx.h"
#include "Table.h"

Table::Table(void)
{
	snake = CSnake();
	food = Cell(5,5);
	memset(map,0,sizeof(map));
	update();
}

Table::~Table(void)
{
}

void Table::draw(CClientDC *dc)
{
	dc->MoveTo(10*MAPWIDTH+1,0);
	dc->LineTo(10*MAPWIDTH+1,10*MAPHEIGHT+1);
	dc->MoveTo(0,10*MAPHEIGHT+1);
	dc->LineTo(10*MAPWIDTH+1,10*MAPHEIGHT+1);
	dc->StretchBlt(0,0,200,200,dc,0,0,200,200,WHITENESS);
	for (int i=0;i<MAPWIDTH;i++)
		for (int j=0;j<MAPHEIGHT;j++)
		{
			if(map[i][j] != 0)
				dc->StretchBlt(10*i,10*j,10,10,dc,0,0,10,10,BLACKNESS);
		}
	CString str;
	str.Format("你的得分为:%d     ",snake.outbody().size() - 3);
	dc->TextOutA(10,210,str);
	return;
}

void Table::update()
{
	memset(map,0,sizeof(map));
	queue<Cell> body = snake.outbody();
	Cell food = this->food;
	while(body.size())
	{
		map[body.front().x][body.front().y] = 1;
		body.pop();
	}
	map[food.x][food.y] = 1;
}
void Table::creatfood()
{
	srand((unsigned)time(NULL));
	do
	{
		food.x = rand()%20;
		food.y = rand()%20;
	}
	while(!snake.compare(food));
	return;
}
Cell Table::outfood()
{
	return food;
}