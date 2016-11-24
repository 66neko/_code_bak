#pragma once
using namespace std;

class Mysql
{
public:

	Mysql();
	~Mysql(){}
	bool Link();
	bool CheckPassword(string uid,string psw);
	void Close();
private:
	MYSQL mydata;
	MYSQL_RES *result;
};