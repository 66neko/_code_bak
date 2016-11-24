#pragma once
#include <queue>
using namespace std;

#define MAPWIDTH 20
#define MAPHEIGHT 20
enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Cell
{
public:
	int x;
	int y;
	Cell(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	Cell()
	{
		x = 5;
		y = 5;
	}
};
class CSnake
{
public:
	CSnake(void); //构造
	~CSnake(void); //析构
	bool move(Cell food); //蛇的移动 如果吃到食物则返回真，否则返回假
	bool cheak(); //检测蛇
	void eat(Cell food); //吃食物
	queue<Cell> outbody(); //输出蛇身体队列
	bool compare(Cell cell); //比较一点是否与蛇重叠
	int direction; //蛇的方向
	double time; //蛇的移动间隔时间
private:
	
	queue<Cell> body; //蛇身队列
};
