// tDoc.cpp : CtDoc 类的实现
//

#include "stdafx.h"
#include "t.h"

#include "tDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtDoc

IMPLEMENT_DYNCREATE(CtDoc, CDocument)

BEGIN_MESSAGE_MAP(CtDoc, CDocument)
END_MESSAGE_MAP()


// CtDoc 构造/析构

CtDoc::CtDoc()
{
	// TODO: 在此添加一次性构造代码

}

CtDoc::~CtDoc()
{
}

BOOL CtDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CtDoc 序列化

void CtDoc::Serialize(CArchive& ar)
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


// CtDoc 诊断

#ifdef _DEBUG
void CtDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtDoc 命令
