#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace rename("EOF","adoEOF")
//���ǵ����������ݿ�Ŀ��ļ�������ģ���������ַ����������Բ��䡣



//����MFC����ʹ���Լ��ķ�װʱ��Ҫ������漸�䵽stdafx.h
void main() 
{ 
	CoInitialize(NULL);//��ʼ��Com�⣬�����������Ҫ��������������
	_ConnectionPtr pMyConnect=NULL;//���Ǹ�����ָ�룬���ڶ���ָ������ݿ��԰ٶ�һ�£����������Ҳ������
	HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//������ָ��ʵ����
	if(FAILED(hr)) 
	{ 
		cout<<"_ConnectionPtr����ָ��ʵ����ʧ��"<<endl; 
		return; 
	} 
	_bstr_t strConnect="Driver={ MySQL ODBC 5.1 Driver };Server=118.193.210.169;Database=66vpn;";  //SQLSERVER 
	//�������ӵ�SQL SERVER���ݿ�������ַ��������еĲ���Ҫ�Լ���
	//connecting to the database server now: 
	try{pMyConnect->Open(strConnect,"root","liuyu666",NULL);}//���ӵ����ݿ⣬Ҫ��׽�쳣
	catch (_com_error &e)
	{
		cout<<"���Ӵ���"<<e.ErrorMessage() <<endl; 
	}
	cout<<"����"<<endl;
	//���ӵ����ݿ�󣬿�ʼִ��SQL���
	_RecordsetPtr m_pRecordset;//��¼������ָ�룬����ִ��SQL��䲢��¼��ѯ���
	if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset )))) 
	{ 
		cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl; 
		return; 
	}
	char sSql[]="SELECT* FROM EMP";//���������_variant_t�����ͣ�һ��COM�������ͣ�����_bstr_tҲ�ǣ�
	//char sSql[]="SELECT* FROM EMP WHERE ENAME='SMITH';" ���������ǲ�����blob����ѯ��������
	try
	{ 
		m_pRecordset->Open((_variant_t)sSql,pMyConnect.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);//�����ݿ⣬ִ��SQL���
	} 
	catch (_com_error &e) 
	{ 
		cout << e.ErrorMessage()<<endl; 
	} 

	//SQL���ִ����ϣ���ȡ��ѯ���
	try 
	{ 
		m_pRecordset->MoveFirst(); //��¼��ָ���ƶ�����ѯ�������ǰ��
		while(m_pRecordset->adoEOF==VARIANT_FALSE)  
		{ 
			//����Ͷ�ȡemp���еĹ�Ա������
			char *sName=(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value); 
			cout<<(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value)<<endl; 
			m_pRecordset->MoveNext();  
		} 
	} 
	catch (_com_error &e) 
	{ 
		cout<<e.ErrorMessage()<<endl; 
	}
	//��Ӽ�¼
	try 
	{ 
		if(!m_pRecordset->Supports(adAddNew))  
		{ 
			cout<<"��¼���ʧ��!"<<endl; 
				return; 
		} 
		m_pRecordset->AddNew();  
		m_pRecordset->Fields->GetItem(_variant_t("au_id"))->Value=_bstr_t("998-72-8882"); 
		m_pRecordset->Fields->GetItem(_variant_t("au_lname"))->Value=_bstr_t("��ޱ2"); 
		m_pRecordset->Fields->GetItem(_variant_t("au_fname"))->Value=_bstr_t("��ޱ2"); 
		m_pRecordset->Fields->GetItem(_variant_t("phone"))->Value=_bstr_t("��ޱ2"); 
		m_pRecordset->Update();  
	}//try 
	catch (_com_error &e) 
	{ 
		//cout<<e.ErrorMessage()!<<endl; 
	} 
}