#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 

int x2,y2; 
int ans = 0;
int dre_x[5] = {0,-1,1,0,0}; 
int dre_y[5] = {0,0,0,-1,1};
int map[12][12];
int visit[12][12];
class Point
{
public:
	int x;
	int y;
	Point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	~Point ()
	{
	}
private:
protected:

};
queue<Point> que;

void BFS()
{
	while (!que.empty())
	{
		if (que.front().x == x2 && que.front().y == y2)
		{
			ans = 1;
			return;
		}
		for (int i=1;i<=4;i++)
		{
			if (visit[que.front().x+dre_x[i]][que.front().y+dre_y[i]] == 0 && map[que.front().x+dre_x[i]][que.front().y+dre_y[i]] == 1)
			{
				visit[que.front().x+dre_x[i]][que.front().y+dre_y[i]] = 1;
				que.push(Point(que.front().x+dre_x[i],que.front().y+dre_y[i]));
			}
		}
		que.pop();
	}
}

void DFS(int  x,int y)
{
	if (x == x2 && y == y2)
	{
		ans =  1;
		return;
	}
	for (int i=1;i<=4;i++)
	{
		if (visit[x+dre_x[i]][y+dre_y[i]] == 0 && map[x+dre_x[i]][y+dre_y[i]] == 1)
		{
			visit[x+dre_x[i]][y+dre_y[i]] = 1;
			DFS(x+dre_x[i],y+dre_y[i]);
		}
	}
}

int main()
{
	memset(map,0,sizeof(map));
	memset(visit,0,sizeof(visit));
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
		{
			cin>>map[j][i];
		}
	cin>>x2>>y2;
	//DFS(1,1);
	que.push(Point(1,1));
	BFS();
	Point p(1,1);
	cout<<ans<<endl;
}