//下面的代码是一个实现C++连接MYSQL数据库的很好的例子
//这里用了建表，插入，检索，删表等常用功能
//我用VC++6.0生成，已经成功连接了。
//在VC++6.0中要想把做一下两步准备工作才可以。
//(1)Tools->Options->Directories->Include files中添加C:\Program Files\MySQL\MySQL Server 6.0\include
//(2)Tools->Options->Directories->Library files中添加C:\Program Files\MySQL\MySQL Server 6.0\lib\opt
//其实就是将头文件和库文件包含进来
//我觉得这个例子写的很好，再结合自己的试验，特地介绍给大家！

#include <winsock.h>
#include <iostream>
#include <string>
#include "mysql.h"
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")

//单步执行，不想单步执行就注释掉
//#define STEPBYSTEP

int main() {
	cout << "****************************************" << endl;

#ifdef STEPBYSTEP
	system("pause");
#endif

	//必备的一个数据结构
	MYSQL mydata;

	//初始化数据库
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "mysql_library_init() succeed" << endl;
	} else {
		cout << "mysql_library_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//初始化数据结构
	if (NULL != mysql_init(&mydata)) {
		cout << "mysql_init() succeed" << endl;
	} else {
		cout << "mysql_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//在连接数据库之前，设置额外的连接选项
	//可以设置的选项很多，这里设置字符集，否则无法处理中文
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	} else {
		cout << "mysql_options() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//连接数据库
	if (NULL
		!= mysql_real_connect(&mydata, "118.193.210.169", "root", "liuyu666", "66vpn",
		3306, NULL, 0))
		//这里的地址，用户名，密码，端口可以根据自己本地的情况更改
	{
		cout << "mysql_real_connect() succeed" << endl;
	} else {
		cout << "mysql_real_connect() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif
	//sql字符串
	string sqlstr;
	string uid = "admin",psw = "liuy8u666";
	sqlstr = "select 帐号,密码 from 帐号表 WHERE 帐号='"+uid+"' AND 密码 = '"+psw+"'";
	MYSQL_RES *result = NULL;
	if(mysql_query(&mydata,sqlstr.c_str())==false)
	{
		cout<<"帐号或密码错误"<<endl;
		result = mysql_store_result(&mydata);
		if(result->row_count == 1) cout<<"yes"<<endl;
	}
	else
	{
		cout<<"帐号或密码正确"<<endl;
	}
}