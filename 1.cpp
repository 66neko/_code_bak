#include "1.h"
#include<time.h>
void Saolei::insill()
{
	memset(map,0,sizeof(map));
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=20;i++)
	{
		int x=rand();
		int y=rand();
		if(map[x][y] == -1)
		{
			i--;
			continue;
		}
		map[x][y] = -1;
		{
			map[x-1][y] ++;
			map[x][y] ++;
			map[x][y] ++;
			map[x][y] ++;
			map[x][y] ++;
			map[x][y] ++;
			map[x][y] ++;
		}
	} 
	//rand()
}
bool Saolei::click(int x,iny y)
{
	if(visit[x][y] == 1)
	{
		return true;
	}
	if(map[x][y] == -1)
	{
		return false;
	}
	else
	{
		visit[x][y] = 1;
		return true;
	} 
}
