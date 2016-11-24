// dasView.cpp : CdasView 类的实现
//

#include "stdafx.h"
#include "das.h"

#include "dasDoc.h"
#include "dasView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdasView

IMPLEMENT_DYNCREATE(CdasView, CView)

BEGIN_MESSAGE_MAP(CdasView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CdasView 构造/析构

CdasView::CdasView()
{
	// TODO: 在此处添加构造代码

}

CdasView::~CdasView()
{
}

BOOL CdasView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdasView 绘制

void CdasView::OnDraw(CDC* /*pDC*/)
{
	CdasDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdasView 打印

BOOL CdasView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdasView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdasView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CdasView 诊断

#ifdef _DEBUG
void CdasView::AssertValid() const
{
	CView::AssertValid();
}

void CdasView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdasDoc* CdasView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdasDoc)));
	return (CdasDoc*)m_pDocument;
}
#endif //_DEBUG


// CdasView 消息处理程序
