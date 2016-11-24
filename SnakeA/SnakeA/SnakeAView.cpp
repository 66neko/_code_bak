// SnakeAView.cpp : CSnakeAView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BEGIN, &CSnakeAView::OnBegin)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSnakeAView ����/����

CSnakeAView::CSnakeAView()
{
	// TODO: �ڴ˴���ӹ������
	table = Table();
}

CSnakeAView::~CSnakeAView()
{
}

BOOL CSnakeAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CSnakeAView ����

void CSnakeAView::OnDraw(CDC* /*pDC*/)
{
	CSnakeADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);
	table.draw(&dc);
}


// CSnakeAView ��ӡ

BOOL CSnakeAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSnakeAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSnakeAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSnakeAView ���

#ifdef _DEBUG
void CSnakeAView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeADoc* CSnakeAView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeADoc)));
	return (CSnakeADoc*)m_pDocument;
}
#endif //_DEBUG


// CSnakeAView ��Ϣ�������

void CSnakeAView::OnBegin()
{
	// TODO: �ڴ���������������
	direction = DOWN;
	table = Table();
	CClientDC dc(this);
	table.draw(&dc);
	SetTimer(0,(UINT)table.snake.time,NULL);
}

void CSnakeAView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
