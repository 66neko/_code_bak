#include <iostream>
#include <cstring>
using namespace std;

int n,m,k,p;
int map[1002][1002];
int visit[1002][1002];
int dre_x[5] = {0,-1,1,0,0};
int dre_y[5] = {0,0,0,-1,1};
int xp,yp;
int xs,ys;
int ans;
int zz;
void DFS(int x,int y,int d)
{
	if (x == xp && y == yp)
	{
		ans = 1;
		return;
	}
	for(int i=1;i<=4;i++)
	{
		if(map[x+dre_x[i]][y+dre_y[i]] == 0 && visit[x+dre_x[i]][y+dre_y[i]] == 0)
		{
			
			if(i != d && zz<= 2)
			{
				zz++;
				visit[x+dre_x[i]][y+dre_y[i]] = 1;
				DFS(x+dre_x[i],y+dre_y[i],i);
				visit[x+dre_x[i]][y+dre_y[i]] = 0;
				zz--;
			}
			if(i == d)
			{
				visit[x+dre_x[i]][y+dre_y[i]] = 1;
				DFS(x+dre_x[i],y+dre_y[i],i);
				visit[x+dre_x[i]][y+dre_y[i]] = 0;
			}
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		memset(map,-1,sizeof(map));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>map[i][j];
		cin>>p;
		while(p--)
		{
			memset(visit,0,sizeof(visit));
			ans = 0;
			cin>>xs>>ys>>xp>>yp;
			zz = -1;
			if(map[xs][ys] == map[xp][yp] && map[xs][ys] != 0)
				DFS(xs,ys,-1);
			else
				ans = 0;
			if(ans)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}