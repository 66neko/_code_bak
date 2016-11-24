// bowerDoc.cpp : CbowerDoc 类的实现
//

#include "stdafx.h"
#include "bower.h"

#include "bowerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbowerDoc

IMPLEMENT_DYNCREATE(CbowerDoc, CDocument)

BEGIN_MESSAGE_MAP(CbowerDoc, CDocument)
END_MESSAGE_MAP()


// CbowerDoc 构造/析构

CbowerDoc::CbowerDoc()
{
	// TODO: 在此添加一次性构造代码

}

CbowerDoc::~CbowerDoc()
{
}

BOOL CbowerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CbowerDoc 序列化

void CbowerDoc::Serialize(CArchive& ar)
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


// CbowerDoc 诊断

#ifdef _DEBUG
void CbowerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CbowerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CbowerDoc 命令
