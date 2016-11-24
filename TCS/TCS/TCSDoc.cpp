// TCSDoc.cpp : CTCSDoc 类的实现
//

#include "stdafx.h"
#include "TCS.h"

#include "TCSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCSDoc

IMPLEMENT_DYNCREATE(CTCSDoc, CDocument)

BEGIN_MESSAGE_MAP(CTCSDoc, CDocument)
END_MESSAGE_MAP()


// CTCSDoc 构造/析构

CTCSDoc::CTCSDoc()
{
	// TODO: 在此添加一次性构造代码

}

CTCSDoc::~CTCSDoc()
{
}

BOOL CTCSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTCSDoc 序列化

void CTCSDoc::Serialize(CArchive& ar)
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


// CTCSDoc 诊断

#ifdef _DEBUG
void CTCSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTCSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTCSDoc 命令
