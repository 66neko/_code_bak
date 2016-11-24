#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>

using namespace std;

#define MAXN 1100

int c[MAXN][MAXN];
int n,q;

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=0;
}

int lowbit(int t)
{
	return t&(-t);
}

int sum(int x,int y)
{
	int s=0,i=1;
	while(x>0)
	{
		i=y;
		while(i>0)
		{
			s+=c[x][i];
			i-=lowbit(i);
		}
		x-=lowbit(x);
	}
	return s;	
}

void modify(int x,int y,int s)
{
	while(x<=n)
	{
		int i=y;
		while(i<=n)
		{
			c[x][i]+=s;
			i+=lowbit(i);
		}
		x+=lowbit(x);
	}	
}

void solve()
{
	int x1,y1,x2,y2;
	char a[20];
	scanf("%d%d",&n,&q);
	init();
	for(int i=1;i<=q;i++)
	{
		scanf("%s",a);
		if(a[0]=='C') 
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			modify(x1,y1,1);
			modify(x1,y2+1,1);
			modify(x2+1,y1,1);
			modify(x2+1,y2+1,1);
		}
		else
		{
			scanf("%d%d",&x1,&y1);
			printf("%d\n",sum(x1,y1)%2);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
		if(t) printf("\n");
	}
	return 0; 
}

 