#pragma once

enum Driection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snakebody
{
public:
	Snakebody(CClientDC *pDC);
	~Snakebody(void);
public:
	bool move(int direction,CClientDC *pDC);
	void add(Cell food,CClientDC *pDC);
	Cell head();
	bool foodcheak(Cell food);
	int snakesize();
private:
	queue<Cell> body;
	bool cheak();
};
