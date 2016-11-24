#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace rename("EOF","adoEOF")
//这是导入连接数据库的库文件，必须的，而且这个字符串基本可以不变。



//对于MFC程序，使用自己的封装时需要添加下面几句到stdafx.h
void main() 
{ 
	CoInitialize(NULL);//初始化Com库，这个不懂不重要，你照做就是了
	_ConnectionPtr pMyConnect=NULL;//这是个对象指针，关于对象指针的内容可以百度一下，不过不理解也就算了
	HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//将对象指针实例化
	if(FAILED(hr)) 
	{ 
		cout<<"_ConnectionPtr对象指针实例化失败"<<endl; 
		return; 
	} 
	_bstr_t strConnect="Driver={ MySQL ODBC 5.1 Driver };Server=118.193.210.169;Database=66vpn;";  //SQLSERVER 
	//这是连接到SQL SERVER数据库的连接字符串，其中的参数要自己改
	//connecting to the database server now: 
	try{pMyConnect->Open(strConnect,"root","liuyu666",NULL);}//连接到数据库，要捕捉异常
	catch (_com_error &e)
	{
		cout<<"连接错误："<<e.ErrorMessage() <<endl; 
	}
	cout<<"连接"<<endl;
	//连接到数据库后，开始执行SQL语句
	_RecordsetPtr m_pRecordset;//记录集对象指针，用来执行SQL语句并记录查询结果
	if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset )))) 
	{ 
		cout<<"记录集对象指针实例化失败！"<<endl; 
		return; 
	}
	char sSql[]="SELECT* FROM EMP";//这里可以用_variant_t的类型（一种COM变量类型，如下_bstr_t也是）
	//char sSql[]="SELECT* FROM EMP WHERE ENAME='SMITH';" 报错，好像是不能用blob来查询！纠结中
	try
	{ 
		m_pRecordset->Open((_variant_t)sSql,pMyConnect.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);//打开数据库，执行SQL语句
	} 
	catch (_com_error &e) 
	{ 
		cout << e.ErrorMessage()<<endl; 
	} 

	//SQL语句执行完毕，读取查询结果
	try 
	{ 
		m_pRecordset->MoveFirst(); //记录集指针移动到查询结果集的前面
		while(m_pRecordset->adoEOF==VARIANT_FALSE)  
		{ 
			//这里就读取emp表中的雇员的名字
			char *sName=(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value); 
			cout<<(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value)<<endl; 
			m_pRecordset->MoveNext();  
		} 
	} 
	catch (_com_error &e) 
	{ 
		cout<<e.ErrorMessage()<<endl; 
	}
	//添加记录
	try 
	{ 
		if(!m_pRecordset->Supports(adAddNew))  
		{ 
			cout<<"记录添加失败!"<<endl; 
				return; 
		} 
		m_pRecordset->AddNew();  
		m_pRecordset->Fields->GetItem(_variant_t("au_id"))->Value=_bstr_t("998-72-8882"); 
		m_pRecordset->Fields->GetItem(_variant_t("au_lname"))->Value=_bstr_t("赵薇2"); 
		m_pRecordset->Fields->GetItem(_variant_t("au_fname"))->Value=_bstr_t("赵薇2"); 
		m_pRecordset->Fields->GetItem(_variant_t("phone"))->Value=_bstr_t("赵薇2"); 
		m_pRecordset->Update();  
	}//try 
	catch (_com_error &e) 
	{ 
		//cout<<e.ErrorMessage()!<<endl; 
	} 
}