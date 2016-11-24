#pragma once
#include "Snake.h"
#include "time.h"
class Table
{
public:
	Table(void); //构造
	~Table(void); //析构
	void update(); //更新桌面矩阵
	void draw(CClientDC *dc); //绘画桌面
	void creatfood(void); //创造食物
	CSnake snake; //蛇对象
	Cell outfood(); //输出食物坐标
private:
	int map[MAPWIDTH][MAPHEIGHT]; //桌面矩阵
	Cell food; //食物
};
