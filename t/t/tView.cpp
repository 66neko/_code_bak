// tView.cpp : CtView 类的实现
//

#include "stdafx.h"
#include "t.h"

#include "tDoc.h"
#include "tView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtView

IMPLEMENT_DYNCREATE(CtView, CView)

BEGIN_MESSAGE_MAP(CtView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CtView 构造/析构

CtView::CtView()
{
	// TODO: 在此处添加构造代码

}

CtView::~CtView()
{
}

BOOL CtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtView 绘制

void CtView::OnDraw(CDC* /*pDC*/)
{
	CtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CtView 打印

BOOL CtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CtView 诊断

#ifdef _DEBUG
void CtView::AssertValid() const
{
	CView::AssertValid();
}

void CtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtDoc* CtView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtDoc)));
	return (CtDoc*)m_pDocument;
}
#endif //_DEBUG


// CtView 消息处理程序

void CtView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == 65)
	{
		keybd_event(65,0,KEYEVENTF_KEYUP,0);
		keybd_event(66,0,0,0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CtView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format("%d",nChar);
	MessageBox(str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
