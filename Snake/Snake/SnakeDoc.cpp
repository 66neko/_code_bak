// SnakeDoc.cpp : CSnakeDoc 类的实现
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeDoc

IMPLEMENT_DYNCREATE(CSnakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeDoc, CDocument)
END_MESSAGE_MAP()


// CSnakeDoc 构造/析构

CSnakeDoc::CSnakeDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSnakeDoc::~CSnakeDoc()
{
}

BOOL CSnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSnakeDoc 序列化

void CSnakeDoc::Serialize(CArchive& ar)
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


// CSnakeDoc 诊断

#ifdef _DEBUG
void CSnakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSnakeDoc 命令
