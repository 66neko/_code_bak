#include<iostream>
#include<cstring>
using namespace std;

char s1[400001],s2[101];

char* strQQQ(char* ss1,char* ss2)
{
	char *p = new char[strlen(ss1)];
	int l = strlen(ss2);
	while(l--)
	{
		ss2++;
		*p = *ss2;
		if(*p == *ss1)
			return ss2;
	}
	return NULL;
}

int main()
{
	while(cin>>s2>>s1)
	{
		int num = 0;
		char *p;
		p = s1;
		int l = strlen(s1);
		int l2 = strlen(s2);
		while(1)
		{
			p = strQQQ(p,s2);
			if(!p)
				break;
			p += 1;// l2 - 1;
			num++;
		}
		cout<<num<<endl;
	}
}