#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace rename("EOF","adoEOF")

class CADOEx
{
	CADOEx();
	void ExSQL(char *sSql);
	_ConnectionPtr pMyConnect;//这是个对象指针，关于对象指针的内容可以百度一下，不过不理解也就算了
	_RecordsetPtr m_pRecordset;//记录集对象指针，用来执行SQL语句并记录查询结果
};