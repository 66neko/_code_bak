#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;


struct Num
{
	Num* Next;
	int Value;
};
class List
{
public:
	List();
	void insert(int k);
	void output(int m,int n);
private:
	Num* Head;
	Num* Bot;
};

List::List()
{
	Num *p = new Num;
	p->Next = NULL;
	Head = p;
}

void List::insert(int k)
{
	Head->Value = 1;
	Num *p = Head;
	for (int i=2;i<=k;i++)
	{
		p->Next = new Num;
		p->Next->Value = i;
		p->Next->Next = NULL;
		p = p->Next;
	}
	p->Next = Head;
}

void List::output(int m,int n)
{
	{
		Num *p = Head;
		while(n != 1)
		{
			n--;
			int k = m - 2;
			while(k > 0)
			{
				k--;
				p = p->Next;
			}
			printf("%d\n",p->Next->Value);
			p->Next = p->Next->Next;
			p = p->Next;
		}
		cout<<p->Value<<endl;
	}
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		List a;
		a.insert(n);
		a.output(m,n);
	}
}