// mcView.cpp : CmcView 类的实现
//

#include "stdafx.h"
#include "mc.h"

#include "mcDoc.h"
#include "mcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmcView

IMPLEMENT_DYNCREATE(CmcView, CView)

BEGIN_MESSAGE_MAP(CmcView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmcView 构造/析构

CmcView::CmcView()
{
	// TODO: 在此处添加构造代码

}

CmcView::~CmcView()
{
}

BOOL CmcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmcView 绘制

void CmcView::OnDraw(CDC* /*pDC*/)
{
	CmcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CmcView 打印

BOOL CmcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmcView 诊断

#ifdef _DEBUG
void CmcView::AssertValid() const
{
	CView::AssertValid();
}

void CmcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmcDoc* CmcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmcDoc)));
	return (CmcDoc*)m_pDocument;
}
#endif //_DEBUG


// CmcView 消息处理程序
