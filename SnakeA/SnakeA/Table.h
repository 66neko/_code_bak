#pragma once
#include "Snake.h"
#include "time.h"
class Table
{
public:
	Table(void); //����
	~Table(void); //����
	void update(); //�����������
	void draw(CClientDC *dc); //�滭����
	void creatfood(void); //����ʳ��
	CSnake snake; //�߶���
	Cell outfood(); //���ʳ������
private:
	int map[MAPWIDTH][MAPHEIGHT]; //�������
	Cell food; //ʳ��
};
