# include <iostream>
# include <cmath>
# include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int a = 12000;
	int num = 0;
	for(int i=0;i<10;i++)
	{
		num += a;
		num *= 1.03;
	}
	for(int i=0;i<10;i++)
	{
		num *= 1.03;
	}
	cout<<num<<endl;
}