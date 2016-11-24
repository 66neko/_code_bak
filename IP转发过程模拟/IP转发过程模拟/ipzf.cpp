//IP转发过程模拟
#include <iostream>
#include <cstring>
using namespace std;
struct luyoubiao//定义路由表结构体
{
	int wID;//网络前缀
	char wyanma[20];//掩码
	int wjiaofu;//交付类型 0：直接 1：间接
	char wIP[20];//下一跳IP地址
	int wMTU;;//下一个网络的MTU
	int duankou;//端口
};
struct sIP//定义ip包结构体
{
	int TTL;
	char tIP[20];//目的ip地址
	int l;//ip包长度
	int p;//片位移
	int f;//标志
};
luyoubiao lyb[222];
sIP ipb;
int main()
{
	memset(lyb,0,sizeof(lyb));
	memset(&ipb,0,sizeof(ipb));
	int flag = 0;
	int n=0;//路由表个数（不包括默认）
	//读取初始路由表 lyb[0]为默认地址
	//读取IP包 TTl，目的IP地址，长度
	if(ipb.TTL-1 == 0)
	{
		cout<<"丢弃IP包\n";
	}
	for(int i=1;i<=n;i++)
	{
		if(strcmp(ipb.tIP,lyb[i].wIP) == 0)
		{
			cout<<"下一跳地址："<<lyb[i].wIP<<endl;
			if(lyb[i].wjiaofu == 0)
			{
				cout<<"直接交付\n";
			}
			else
			{
				cout<<"间接交付\n";
			}
			flag = i;
			break;

		}
		if(i == n)
		{
			cout<<"下一跳地址："<<lyb[0].wIP<<endl;
			if(lyb[0].wjiaofu == 0)
			{
				cout<<"直接交付\n";
			}
			else
			{
				cout<<"间接交付\n";
			}
			flag = 0;
			break;
		}
	}

	if(ipb.l > lyb[flag].wMTU)
	{
		int len = ipb.l - 20;
		int pwy = 0;//片位移
		int ii = 0;//计数器
		while(len+20 > lyb[flag].wMTU)
		{
			ii++;
			len -= lyb[flag].wMTU - 20;
			cout<<"分片"<<ii<<"： 长度："<<lyb[flag].wMTU<<" 片位移："<<pwy<<" 标志：1 发送至端口："<<lyb[flag].duankou<<endl;
			pwy += lyb[flag].wMTU - 20;
		}
		cout<<"分片"<<ii+1<<"： 长度："<<len+20<<" 片位移："<<pwy<<" 标志：0 发送至端口："<<lyb[flag].duankou<<endl;
	}
	else
	{
		cout<<"不需要分片"<<endl<<"发送至端口"<<lyb[flag].duankou<<endl;;
	}
}