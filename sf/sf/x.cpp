#include<stdio.h>
#define MAX 0xfffffff
#define max 105

int map[max][max],sign[max];
int main()
{
	int n,a,b,c,d,i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			sign[i]=0;
			for(j=1;j<=n;j++)
				map[i][j]=MAX;
		} 
		for(i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(d==1) map[a][b]=map[b][a]=0;
			else map[a][b]=map[b][a]=c;
		}
		int sum=0,min,u;
		for(i=1;i<=n;i++)
		{
			sign[1]=1;
			min=MAX;
			for(j=1;j<=n;j++)
				if(!sign[j]&&min>map[1][j])
				{
					min=map[1][j];
					u=j;
				}
				sign[u]=1;
				if(min!=MAX) sum+=min;
				for(j=1;j<=n;j++)
					if(map[u][j]<map[1][j])
						map[1][j]=map[u][j];
		}
		printf("%d\n",sum);
	}
	return 0;
}