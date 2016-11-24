#include "StdAfx.h"
#include "ADOEx.h"

CADOEx::CADOEx(void)
{
	CoInitialize(NULL);//初始化Com库，这个不懂不重要，你照做就是了
	pMyConnect=NULL;//这是个对象指针，关于对象指针的内容可以百度一下，不过不理解也就算了
	HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//将对象指针实例化
	if(FAILED(hr)) 
	{ 
		//cout<<"_ConnectionPtr对象指针实例化失败"<<endl;  
	} 
	_bstr_t strConnect="Driver={sqlserver};server=qiany;uid=;pwd=;database=GZ";  //SQLSERVER 
	//这是连接到SQL SERVER数据库的连接字符串，其中的参数要自己改
	//connecting to the database server now: 
	try{pMyConnect->Open(strConnect,"","",NULL);}//连接到数据库，要捕捉异常
	catch (_com_error &e)
	{
		//cout<<e.ErrorMessage() <<endl; 
	}
	//连接到数据库后，开始执行SQL语句

	if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset )))) 
	{ 
		//cout<<"记录集对象指针实例化失败！"<<endl; 
	}
}

CADOEx::~CADOEx(void)
{
}
void CADOEx::ExSQL(char *sSql)
{
	try
	{ 
		m_pRecordset->Open((_variant_t)sSql,pMyConnect.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);//打开数据库，执行SQL语句
	} 
	catch (_com_error &e) 
	{ 
		//cout << e.ErrorMessage()<<endl; 
	} 
}