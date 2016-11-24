#include<iostream>
using namespace std;
int a[10][10];
int v[10];
int n;
int main()
{
	for (int i=1;i<=n;i++)
	{
		v[i] = a[1][i];
	}
	for(int i=1;;i++)
	{
		minn = 0;
		yes  = 0;
		for(int i=1;i<=n;i++)
		{
			if(v[i] && v[i] < minn)
			{
				minn = v[i];
				yes = 1;
			}
		}
		if(yes == 0) break;

	}
}