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
	CSnake(void); //����
	~CSnake(void); //����
	bool move(Cell food); //�ߵ��ƶ� ����Ե�ʳ���򷵻��棬���򷵻ؼ�
	bool cheak(); //�����
	void eat(Cell food); //��ʳ��
	queue<Cell> outbody(); //������������
	bool compare(Cell cell); //�Ƚ�һ���Ƿ������ص�
	int direction; //�ߵķ���
	double time; //�ߵ��ƶ����ʱ��
private:
	
	queue<Cell> body; //�������
};
