#include<iostream>
#include"MainClient.h"
using namespace std;


void main()
{
	char name[20];
	cout<<"��������:"<<endl;
	cin>>name;
	if(strlen(name)>16)
	{
		cout<<"���ֹ�����"<<endl;
	}
	MainClient client;
	client.OnStart(name);
}