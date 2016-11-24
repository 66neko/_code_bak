#include "StdAfx.h"
#include "ADOEx.h"

CADOEx::CADOEx(void)
{
	CoInitialize(NULL);//��ʼ��Com�⣬�����������Ҫ��������������
	pMyConnect=NULL;//���Ǹ�����ָ�룬���ڶ���ָ������ݿ��԰ٶ�һ�£����������Ҳ������
	HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//������ָ��ʵ����
	if(FAILED(hr)) 
	{ 
		//cout<<"_ConnectionPtr����ָ��ʵ����ʧ��"<<endl;  
	} 
	_bstr_t strConnect="Driver={sqlserver};server=qiany;uid=;pwd=;database=GZ";  //SQLSERVER 
	//�������ӵ�SQL SERVER���ݿ�������ַ��������еĲ���Ҫ�Լ���
	//connecting to the database server now: 
	try{pMyConnect->Open(strConnect,"","",NULL);}//���ӵ����ݿ⣬Ҫ��׽�쳣
	catch (_com_error &e)
	{
		//cout<<e.ErrorMessage() <<endl; 
	}
	//���ӵ����ݿ�󣬿�ʼִ��SQL���

	if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset )))) 
	{ 
		//cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl; 
	}
}

CADOEx::~CADOEx(void)
{
}
void CADOEx::ExSQL(char *sSql)
{
	try
	{ 
		m_pRecordset->Open((_variant_t)sSql,pMyConnect.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);//�����ݿ⣬ִ��SQL���
	} 
	catch (_com_error &e) 
	{ 
		//cout << e.ErrorMessage()<<endl; 
	} 
}