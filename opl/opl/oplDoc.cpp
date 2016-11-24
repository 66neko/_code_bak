// oplDoc.cpp : CoplDoc 类的实现
//

#include "stdafx.h"
#include "opl.h"

#include "oplDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CoplDoc

IMPLEMENT_DYNCREATE(CoplDoc, CDocument)

BEGIN_MESSAGE_MAP(CoplDoc, CDocument)
END_MESSAGE_MAP()


// CoplDoc 构造/析构

CoplDoc::CoplDoc()
{
	// TODO: 在此添加一次性构造代码

}

CoplDoc::~CoplDoc()
{
}

BOOL CoplDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CoplDoc 序列化

void CoplDoc::Serialize(CArchive& ar)
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


// CoplDoc 诊断

#ifdef _DEBUG
void CoplDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CoplDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CoplDoc 命令
