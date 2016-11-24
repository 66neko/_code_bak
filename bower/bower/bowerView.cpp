// bowerView.cpp : CbowerView 类的实现
//

#include "stdafx.h"
#include "bower.h"

#include "bowerDoc.h"
#include "bowerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbowerView

IMPLEMENT_DYNCREATE(CbowerView, CHtmlView)

BEGIN_MESSAGE_MAP(CbowerView, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

// CbowerView 构造/析构

CbowerView::CbowerView()
{
	// TODO: 在此处添加构造代码

}

CbowerView::~CbowerView()
{
}

BOOL CbowerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CbowerView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.baidu.com"),NULL,NULL);
}


// CbowerView 打印



// CbowerView 诊断

#ifdef _DEBUG
void CbowerView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CbowerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CbowerDoc* CbowerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbowerDoc)));
	return (CbowerDoc*)m_pDocument;
}
#endif //_DEBUG


// CbowerView 消息处理程序
