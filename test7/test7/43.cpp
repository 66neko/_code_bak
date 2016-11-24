#include<iostream>
#include<process.h>
using namespace std;

int gcd(int a,int b)
{
	if(a < b)
		swap(a,b);
	if(a%b == 0)
		return b;
	return gcd(a,a%b);
}
void main()
{
	int x,y;
	while(cin>>x>>y)
	{
		cout<<gcd(x,y)<<endl;
	}
}