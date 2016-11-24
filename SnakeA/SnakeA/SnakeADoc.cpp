// SnakeADoc.cpp : CSnakeADoc 类的实现
//

#include "stdafx.h"
#include "SnakeA.h"

#include "SnakeADoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeADoc

IMPLEMENT_DYNCREATE(CSnakeADoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeADoc, CDocument)
END_MESSAGE_MAP()


// CSnakeADoc 构造/析构

CSnakeADoc::CSnakeADoc()
{
	// TODO: 在此添加一次性构造代码

}

CSnakeADoc::~CSnakeADoc()
{
}

BOOL CSnakeADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSnakeADoc 序列化

void CSnakeADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CSnakeADoc 诊断

#ifdef _DEBUG
void CSnakeADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSnakeADoc 命令
