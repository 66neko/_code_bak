#include<iostream>
#include"MainClient.h"
using namespace std;


void main()
{
	char name[20];
	cout<<"输入名字:"<<endl;
	cin>>name;
	if(strlen(name)>16)
	{
		cout<<"名字过长。"<<endl;
	}
	MainClient client;
	client.OnStart(name);
}