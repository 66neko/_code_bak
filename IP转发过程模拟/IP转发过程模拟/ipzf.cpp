//IPת������ģ��
#include <iostream>
#include <cstring>
using namespace std;
struct luyoubiao//����·�ɱ�ṹ��
{
	int wID;//����ǰ׺
	char wyanma[20];//����
	int wjiaofu;//�������� 0��ֱ�� 1�����
	char wIP[20];//��һ��IP��ַ
	int wMTU;;//��һ�������MTU
	int duankou;//�˿�
};
struct sIP//����ip���ṹ��
{
	int TTL;
	char tIP[20];//Ŀ��ip��ַ
	int l;//ip������
	int p;//Ƭλ��
	int f;//��־
};
luyoubiao lyb[222];
sIP ipb;
int main()
{
	memset(lyb,0,sizeof(lyb));
	memset(&ipb,0,sizeof(ipb));
	int flag = 0;
	int n=0;//·�ɱ������������Ĭ�ϣ�
	//��ȡ��ʼ·�ɱ� lyb[0]ΪĬ�ϵ�ַ
	//��ȡIP�� TTl��Ŀ��IP��ַ������
	if(ipb.TTL-1 == 0)
	{
		cout<<"����IP��\n";
	}
	for(int i=1;i<=n;i++)
	{
		if(strcmp(ipb.tIP,lyb[i].wIP) == 0)
		{
			cout<<"��һ����ַ��"<<lyb[i].wIP<<endl;
			if(lyb[i].wjiaofu == 0)
			{
				cout<<"ֱ�ӽ���\n";
			}
			else
			{
				cout<<"��ӽ���\n";
			}
			flag = i;
			break;

		}
		if(i == n)
		{
			cout<<"��һ����ַ��"<<lyb[0].wIP<<endl;
			if(lyb[0].wjiaofu == 0)
			{
				cout<<"ֱ�ӽ���\n";
			}
			else
			{
				cout<<"��ӽ���\n";
			}
			flag = 0;
			break;
		}
	}

	if(ipb.l > lyb[flag].wMTU)
	{
		int len = ipb.l - 20;
		int pwy = 0;//Ƭλ��
		int ii = 0;//������
		while(len+20 > lyb[flag].wMTU)
		{
			ii++;
			len -= lyb[flag].wMTU - 20;
			cout<<"��Ƭ"<<ii<<"�� ���ȣ�"<<lyb[flag].wMTU<<" Ƭλ�ƣ�"<<pwy<<" ��־��1 �������˿ڣ�"<<lyb[flag].duankou<<endl;
			pwy += lyb[flag].wMTU - 20;
		}
		cout<<"��Ƭ"<<ii+1<<"�� ���ȣ�"<<len+20<<" Ƭλ�ƣ�"<<pwy<<" ��־��0 �������˿ڣ�"<<lyb[flag].duankou<<endl;
	}
	else
	{
		cout<<"����Ҫ��Ƭ"<<endl<<"�������˿�"<<lyb[flag].duankou<<endl;;
	}
}