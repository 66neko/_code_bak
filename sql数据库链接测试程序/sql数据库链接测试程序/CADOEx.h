#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace rename("EOF","adoEOF")

class CADOEx
{
	CADOEx();
	void ExSQL(char *sSql);
	_ConnectionPtr pMyConnect;//���Ǹ�����ָ�룬���ڶ���ָ������ݿ��԰ٶ�һ�£����������Ҳ������
	_RecordsetPtr m_pRecordset;//��¼������ָ�룬����ִ��SQL��䲢��¼��ѯ���
};