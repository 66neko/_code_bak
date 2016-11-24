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
	//��ʼ�����ݽṹ
	if (NULL != mysql_init(&mydata)) {
		cout << "mysql_init() succeed" << endl;
	} else {
		cout << "mysql_init() failed" << endl;
		return;
	}
	//���������ݿ�֮ǰ�����ö��������ѡ��
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������
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
            //����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������
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
	sqlstr = "select �ʺ�,���� from �ʺű� WHERE �ʺ�='"+uid+"' AND ���� = '"+psw+"'";
	if(mysql_query(&mydata,sqlstr.c_str())==false)
	{
		result = mysql_store_result(&mydata);
		if(result->row_count == 1)
		{
			cout<<"�ʺ�������ȷ"<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout<<"��ȡʧ��"<<endl;
		return false;
	}
}
void Mysql::Close()
{
	mysql_free_result(result);
    mysql_close(&mydata);
	return;
}