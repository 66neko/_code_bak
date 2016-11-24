#include "stdafx.h"
class Saolei
{
	public:
		int map[21][21];//地图 
		int visit[21][21];//状态 
		int _time;//剩余时间 
		int _num;//剩余雷的个数 
		 
	public:
		Saolei();//构造函数 
		void insill();//初始化 
		bool click(int x,iny y);//按钮被点击 
		void draw(CClientDC *pDC);//绘画窗口 
};
