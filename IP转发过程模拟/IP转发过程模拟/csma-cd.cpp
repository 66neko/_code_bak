#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main()
{
	int f1,f2,k=2,wait_time = 0,ii = 0;
	while(1)
	{
		ii++;
		k = 2;
		wait_time = 0;
		cout<<"���͵�"<<ii<<"��֡"<<endl;
		while(1)
		{
			srand((unsigned)time(NULL)); 
			f1 = rand()%9;
			f2 = rand()%9;
			if(f1<5)
			{
				cout<<"�ŵ�æ"<<endl;
			}
			else if(f2 < 4)
			{
				wait_time += rand()%k;
				cout<<"������ײ"<<endl;
				cout<<"�ȴ�ʱ�䣺"<<wait_time<<endl;
				k = k*2;
				if(k>32)
				{
					cout<<"����ʧ��"<<endl;
					break;
				}
			}
			else
			{
				cout<<"���ͳɹ� \n               5�������һ��֡"<<endl;
				break;
			}
			Sleep(1000);
		}
		Sleep(4000);
	}
}