#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200010;

struct Node
{
    int num;
    long long sum;
}node[MAXN];

int F[MAXN];

int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}

struct Edge
{
    int a,b,c;
}edge[MAXN];

bool cmp(Edge a,Edge b)
{
    return a.c>b.c;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n-1;i++)
          scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        sort(edge,edge+n-1,cmp);

        for(int i=1;i<=n;i++)
        {
            node[i].num=1;
            node[i].sum=0;
            F[i]=-1;
        }

        for(int i=0;i<n-1;i++)
        {
            int a=edge[i].a;
            int b=edge[i].b;
            int t1=find(a);
            int t2=find(b);
            if(node[t1].sum+(long long)edge[i].c*node[t2].num<node[t2].sum+(long long)edge[i].c*node[t1].num)
            {
                F[t1]=t2;
                node[t2].num+=node[t1].num;
                node[t2].sum+=(long long)edge[i].c*node[t1].num;
            }
            else
            {
                F[t2]=t1;
                node[t1].num+=node[t2].num;
                node[t1].sum+=(long long)edge[i].c*node[t2].num;
            }
        }
        printf("%lld\n",node[find(1)].sum);

    }
    return 0;
}