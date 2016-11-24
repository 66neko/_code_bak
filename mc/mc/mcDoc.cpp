// mcDoc.cpp : CmcDoc 类的实现
//

#include "stdafx.h"
#include "mc.h"

#include "mcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmcDoc

IMPLEMENT_DYNCREATE(CmcDoc, CDocument)

BEGIN_MESSAGE_MAP(CmcDoc, CDocument)
END_MESSAGE_MAP()


// CmcDoc 构造/析构

CmcDoc::CmcDoc()
{
	// TODO: 在此添加一次性构造代码

}

CmcDoc::~CmcDoc()
{
}

BOOL CmcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CmcDoc 序列化

void CmcDoc::Serialize(CArchive& ar)
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


// CmcDoc 诊断

#ifdef _DEBUG
void CmcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmcDoc 命令
