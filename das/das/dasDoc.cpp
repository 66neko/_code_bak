// dasDoc.cpp : CdasDoc 类的实现
//

#include "stdafx.h"
#include "das.h"

#include "dasDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdasDoc

IMPLEMENT_DYNCREATE(CdasDoc, CDocument)

BEGIN_MESSAGE_MAP(CdasDoc, CDocument)
END_MESSAGE_MAP()


// CdasDoc 构造/析构

CdasDoc::CdasDoc()
{
	// TODO: 在此添加一次性构造代码

}

CdasDoc::~CdasDoc()
{
}

BOOL CdasDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CdasDoc 序列化

void CdasDoc::Serialize(CArchive& ar)
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


// CdasDoc 诊断

#ifdef _DEBUG
void CdasDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdasDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdasDoc 命令
