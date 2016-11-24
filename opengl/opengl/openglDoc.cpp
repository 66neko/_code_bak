// openglDoc.cpp : CopenglDoc 类的实现
//

#include "stdafx.h"
#include "opengl.h"

#include "openglDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CopenglDoc

IMPLEMENT_DYNCREATE(CopenglDoc, CDocument)

BEGIN_MESSAGE_MAP(CopenglDoc, CDocument)
END_MESSAGE_MAP()


// CopenglDoc 构造/析构

CopenglDoc::CopenglDoc()
{
	// TODO: 在此添加一次性构造代码

}

CopenglDoc::~CopenglDoc()
{
}

BOOL CopenglDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CopenglDoc 序列化

void CopenglDoc::Serialize(CArchive& ar)
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


// CopenglDoc 诊断

#ifdef _DEBUG
void CopenglDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CopenglDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CopenglDoc 命令
