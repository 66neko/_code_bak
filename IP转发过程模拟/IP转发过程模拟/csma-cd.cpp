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
		cout<<"发送第"<<ii<<"个帧"<<endl;
		while(1)
		{
			srand((unsigned)time(NULL)); 
			f1 = rand()%9;
			f2 = rand()%9;
			if(f1<5)
			{
				cout<<"信道忙"<<endl;
			}
			else if(f2 < 4)
			{
				wait_time += rand()%k;
				cout<<"发生碰撞"<<endl;
				cout<<"等待时间："<<wait_time<<endl;
				k = k*2;
				if(k>32)
				{
					cout<<"发送失败"<<endl;
					break;
				}
			}
			else
			{
				cout<<"发送成功 \n               5秒后发送下一个帧"<<endl;
				break;
			}
			Sleep(1000);
		}
		Sleep(4000);
	}
}