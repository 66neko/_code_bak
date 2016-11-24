#include "stdafx.h"
#include "Cmysql.h"

Mysql::Mysql()
{
	result = NULL;
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "mysql_library_init() succeed" << endl;
	} else {
		cout << "mysql_library_init() failed" << endl;
		return;
	}
	//初始化数据结构
	if (NULL != mysql_init(&mydata)) {
		cout << "mysql_init() succeed" << endl;
	} else {
		cout << "mysql_init() failed" << endl;
		return;
	}
	//在连接数据库之前，设置额外的连接选项
	//可以设置的选项很多，这里设置字符集，否则无法处理中文
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	} else {
		cout << "mysql_options() failed" << endl;
		return;
	}

}
bool Mysql::Link()
{
	if (NULL
            != mysql_real_connect(&mydata, "118.193.210.169", "root", "liuyu666", "66vpn",
                    3306, NULL, 0))
            //这里的地址，用户名，密码，端口可以根据自己本地的情况更改
            {
        cout << "mysql_real_connect() succeed" << endl;
		return true;
    } else {
        cout << "mysql_real_connect() failed" << endl;
        return false;
    }

}
bool Mysql::CheckPassword(string uid, string psw)
{
	string sqlstr;
	sqlstr = "select 帐号,密码 from 帐号表 WHERE 帐号='"+uid+"' AND 密码 = '"+psw+"'";
	if(mysql_query(&mydata,sqlstr.c_str())==false)
	{
		result = mysql_store_result(&mydata);
		if(result->row_count == 1)
		{
			cout<<"帐号密码正确"<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout<<"获取失败"<<endl;
		return false;
	}
}
void Mysql::Close()
{
	mysql_free_result(result);
    mysql_close(&mydata);
	return;
}