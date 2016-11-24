// TCSView.cpp : CTCSView 类的实现
//

#include "stdafx.h"
#include "TCS.h"

#include "TCSDoc.h"
#include "TCSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCSView

IMPLEMENT_DYNCREATE(CTCSView, CView)

BEGIN_MESSAGE_MAP(CTCSView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTCSView 构造/析构

CTCSView::CTCSView()
{
	// TODO: 在此处添加构造代码

}

CTCSView::~CTCSView()
{
}

BOOL CTCSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTCSView 绘制

void CTCSView::OnDraw(CDC* /*pDC*/)
{
	CTCSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTCSView 打印

BOOL CTCSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTCSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTCSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTCSView 诊断

#ifdef _DEBUG
void CTCSView::AssertValid() const
{
	CView::AssertValid();
}

void CTCSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTCSDoc* CTCSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTCSDoc)));
	return (CTCSDoc*)m_pDocument;
}
#endif //_DEBUG


// CTCSView 消息处理程序
