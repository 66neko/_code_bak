#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long Plus(long long x)
{
	
	return (x*(x-1))/2;
}
struct N
{
	long long a,b;
};
bool cmp(N a,N b)
{
	if(a.a<b.a)
		return true;
	if(a.a>b.a)
		return false;
	if(a.a == b.a)
		return a.b<b.b;
}
N k[110000];
int main()
{
	long long n;
	while(cin>>n)
	{
		
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld",&k[i].a,&k[i].b);
			k[i].b = Plus(k[i].b);
		}
		sort(k,k+n,cmp);
		//
		//for(int i=1;i<=n;i++)
		//	cout<<k[i].a<<" "<<k[i].b<<endl;
		//
		int p = 1,p1,p2;
		int num = 1;
		while(p<n)
		{
			p1 = p;
			p2 = p1 + 1;
			while(k[p2].a<k[p1].a+k[p1].b)
			{
				if(k[p2].a+k[p2].b<k[p1].a+k[p1].b)
				{
					num++;
					p = p2;
					break;
				}
				else
				{
					p2++;
				}
			}
			num++;
			p = p2;
		}
		cout<<num<<endl;
	}
}