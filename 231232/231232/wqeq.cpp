/*
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,m,t,c,tp;
int map[2][12][12];
int visit[2][12][12];
int dre_x[5] = {0,-1,1,0,0};
int dre_y[5] = {0,0,0,-1,1};
int ans;
int xc,yc,zc;
int xp,yp,zp;
int no_map;

class Point
{
public:
	int x;
	int y;
	int z;
	Point(int x,int y,int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

queue<Point> que[300];

void BFS()
{
	while(!que[tp].empty())
	{
		que[tp+1] = queue<Point>();
		while(!que[tp].empty())
		{
			int x = que[tp].front().x;
			int y = que[tp].front().y;
			int z = que[tp].front().z;
			no_map = z;
			if(x == xp && y == yp && z == zp)
			{
				if ( tp<= t)
				{
					ans = 1;
					return;
				}
			}
			for(int i=1;i<=4;i++)
			{
				if(map[no_map][x+dre_x[i]][y+dre_y[i]] == 2 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
				{
					visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
					no_map? no_map = 0:no_map = 1;
					if(map[no_map][x+dre_x[i]][y+dre_y[i]] == 1 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
					{
						visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
						que[tp+1].push(Point(x+dre_x[i],y+dre_y[i],no_map));
					}
					//else
					{
						no_map? no_map = 0:no_map = 1;
					}
				}
				else
				{
					if(map[no_map][x+dre_x[i]][y+dre_y[i]] != 0 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
					{
						visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
						que[tp+1].push(Point(x+dre_x[i],y+dre_y[i],no_map));
					}
				}
			}
			que[tp].pop();
		}
		tp++;
	}
}

/*
void DFS(int x,int y)
{
	tp++;
	if(x == xp && y == yp && no_map == zp)
	{
		//cout<<tp<<endl;
		if ( tp<= t)
		{
			ans = 1;
			//cout<<tp<<endl;
			return;
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(map[no_map][x+dre_x[i]][y+dre_y[i]] == 2 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
		{
			visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
			no_map? no_map = 0:no_map = 1;
			if(map[no_map][x+dre_x[i]][y+dre_y[i]] != 0 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
			{
				visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
				DFS(x+dre_x[i],y+dre_y[i]);
				visit[no_map][x+dre_x[i]][y+dre_y[i]] = 0;
			}
			//else
			{
				no_map? no_map = 0:no_map = 1;
			}
		}
		else
		{
			if(map[no_map][x+dre_x[i]][y+dre_y[i]] != 0 && visit[no_map][x+dre_x[i]][y+dre_y[i]] == 0)
			{
				visit[no_map][x+dre_x[i]][y+dre_y[i]] = 1;
				DFS(x+dre_x[i],y+dre_y[i]);
				visit[no_map][x+dre_x[i]][y+dre_y[i]] = 0;
			}
		}
	}
	tp--;
}
*/
/*
int main()

//void A()
{
	char k;
	no_map = 0;
	cin>>c;
	while(c--)
	{
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		no_map = 0;
		ans = 0;
		tp = 0;
		cin>>n>>m>>t;
		for (int h=0;h<=1;h++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
				{
					cin>>k;
					switch (k)
					{
					case '*':
						map[h][j][i] = 0;
						break;
					case '.':
						map[h][j][i] = 1;
						break;
					case '#':
						map[h][j][i] = 2;
						break;
					case 'S':
						xc = j;
						yc = i;
						no_map = h;
						zc = h;
						map[h][j][i] = 1;
						break;
					case 'P':
						xp = j;
						yp = i;
						zp = h;
						map[h][j][i] = 1;
						break;
					}
				}
				que[0] = queue<Point>();
				que[0].push(Point(xc,yc,zc));
				BFS();
				//DFS(xc,yc);
				if(ans)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
	}
}

*/