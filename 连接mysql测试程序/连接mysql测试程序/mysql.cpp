//����Ĵ�����һ��ʵ��C++����MYSQL���ݿ�ĺܺõ�����
//�������˽������룬������ɾ��ȳ��ù���
//����VC++6.0���ɣ��Ѿ��ɹ������ˡ�
//��VC++6.0��Ҫ�����һ������׼�������ſ��ԡ�
//(1)Tools->Options->Directories->Include files�����C:\Program Files\MySQL\MySQL Server 6.0\include
//(2)Tools->Options->Directories->Library files�����C:\Program Files\MySQL\MySQL Server 6.0\lib\opt
//��ʵ���ǽ�ͷ�ļ��Ϳ��ļ���������
//�Ҿ����������д�ĺܺã��ٽ���Լ������飬�صؽ��ܸ���ң�

#include <winsock.h>
#include <iostream>
#include <string>
#include "mysql.h"
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")

//����ִ�У����뵥��ִ�о�ע�͵�
//#define STEPBYSTEP

int main() {
	cout << "****************************************" << endl;

#ifdef STEPBYSTEP
	system("pause");
#endif

	//�ر���һ�����ݽṹ
	MYSQL mydata;

	//��ʼ�����ݿ�
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "mysql_library_init() succeed" << endl;
	} else {
		cout << "mysql_library_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//��ʼ�����ݽṹ
	if (NULL != mysql_init(&mydata)) {
		cout << "mysql_init() succeed" << endl;
	} else {
		cout << "mysql_init() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//���������ݿ�֮ǰ�����ö��������ѡ��
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	} else {
		cout << "mysql_options() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif

	//�������ݿ�
	if (NULL
		!= mysql_real_connect(&mydata, "118.193.210.169", "root", "liuyu666", "66vpn",
		3306, NULL, 0))
		//����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������
	{
		cout << "mysql_real_connect() succeed" << endl;
	} else {
		cout << "mysql_real_connect() failed" << endl;
		return -1;
	}

#ifdef STEPBYSTEP
	system("pause");
#endif
	//sql�ַ���
	string sqlstr;
	string uid = "admin",psw = "liuy8u666";
	sqlstr = "select �ʺ�,���� from �ʺű� WHERE �ʺ�='"+uid+"' AND ���� = '"+psw+"'";
	MYSQL_RES *result = NULL;
	if(mysql_query(&mydata,sqlstr.c_str())==false)
	{
		cout<<"�ʺŻ��������"<<endl;
		result = mysql_store_result(&mydata);
		if(result->row_count == 1) cout<<"yes"<<endl;
	}
	else
	{
		cout<<"�ʺŻ�������ȷ"<<endl;
	}
}