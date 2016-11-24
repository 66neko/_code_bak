#include<iostream>
#include<cstring>
using namespace std;

int map[31][31];
int k;
int v[33];
int n,m,mm;

int min_num;

void DFS(int x,int y,int num)
{
	if(x == mm)
	{
		min_num = min(num,min_num);
	}
	for(int i=1;i<n;i++)
	{
		if(v[i])
		{
			v[i] = 0;
			DFS(x+1,i,num + map[y][i]);
			v[i] = 1;
		}
	}
}

int main()
{
	while(cin>>n,n)
	{
		mm = 0;
		min_num = 99999;
		memset(map,0,sizeof(map));
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>map[i][j];
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>k;
			if(!v[k])
			{
				mm++; 
				v[k] = 1;
			}
		}
		DFS(0,0,0);
		cout<<min_num<<endl;
	}
}