// SnakeAView.cpp : CSnakeAView 类的实现
//

#include "stdafx.h"
#include "SnakeA.h"

#include "SnakeADoc.h"
#include "SnakeAView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeAView

IMPLEMENT_DYNCREATE(CSnakeAView, CView)

BEGIN_MESSAGE_MAP(CSnakeAView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BEGIN, &CSnakeAView::OnBegin)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSnakeAView 构造/析构

CSnakeAView::CSnakeAView()
{
	// TODO: 在此处添加构造代码
	table = Table();
}

CSnakeAView::~CSnakeAView()
{
}

BOOL CSnakeAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CSnakeAView 绘制

void CSnakeAView::OnDraw(CDC* /*pDC*/)
{
	CSnakeADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	table.draw(&dc);
}


// CSnakeAView 打印

BOOL CSnakeAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSnakeAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSnakeAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSnakeAView 诊断

#ifdef _DEBUG
void CSnakeAView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeADoc* CSnakeAView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeADoc)));
	return (CSnakeADoc*)m_pDocument;
}
#endif //_DEBUG


// CSnakeAView 消息处理程序

void CSnakeAView::OnBegin()
{
	// TODO: 在此添加命令处理程序代码
	direction = DOWN;
	table = Table();
	CClientDC dc(this);
	table.draw(&dc);
	SetTimer(0,(UINT)table.snake.time,NULL);
}

void CSnakeAView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	table.snake.direction;
	switch(nChar)
	{
	case VK_UP:
		if (table.snake.direction != DOWN)direction = UP;
		break;
	case VK_DOWN:
		if (table.snake.direction != UP)direction = DOWN;
		break;
	case VK_LEFT:
		if (table.snake.direction != RIGHT)direction = LEFT;
		break;
	case VK_RIGHT:
		if (table.snake.direction != LEFT)direction = RIGHT;
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSnakeAView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(nIDEvent);
	table.snake.direction = direction;
	if (!table.snake.cheak())
	{
		MessageBox("Game Over");
		return;
	}
	if(table.snake.move(table.outfood()))
		table.creatfood();
	table.update();
	CClientDC dc(this);
	table.draw(&dc);
	SetTimer(0,(UINT)table.snake.time,NULL);
	CView::OnTimer(nIDEvent);
}
