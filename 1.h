#include "stdafx.h"
class Saolei
{
	public:
		int map[21][21];//��ͼ 
		int visit[21][21];//״̬ 
		int _time;//ʣ��ʱ�� 
		int _num;//ʣ���׵ĸ��� 
		 
	public:
		Saolei();//���캯�� 
		void insill();//��ʼ�� 
		bool click(int x,iny y);//��ť����� 
		void draw(CClientDC *pDC);//�滭���� 
};
