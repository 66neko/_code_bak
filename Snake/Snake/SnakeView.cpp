// SnakeView.cpp : CSnakeView ���ʵ��
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"
#include "SnakeView.h"
#include "Snakebody.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeView

IMPLEMENT_DYNCREATE(CSnakeView, CView)

BEGIN_MESSAGE_MAP(CSnakeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BEGIN, &CSnakeView::OnBegin)
	ON_WM_TIMER()
	//	ON_WM_CHAR()
	//	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CSnakeView ����/����

CSnakeView::CSnakeView()
: direction(DOWN)
, num(0)
, k_direction(DOWN)
, m_time(500)
{
	// TODO: �ڴ˴���ӹ������
	food.x = 10;
	food.y = 10;

}

CSnakeView::~CSnakeView()
{
}

BOOL CSnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSnakeView ����

void CSnakeView::OnDraw(CDC* pDC)
{
	CSnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen(PS_SOLID,1,RGB(190,190,190));
	CPen *old_pen = pDC->SelectObject(&pen);
	pDC->MoveTo(0,300);
	pDC->LineTo(300,300);
	pDC->MoveTo(300,0);
	pDC->LineTo(300,300);
	pDC->SelectObject(old_pen);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSnakeView ��ӡ

BOOL CSnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSnakeView ���

#ifdef _DEBUG
void CSnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeDoc* CSnakeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeDoc)));
	return (CSnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CSnakeView ��Ϣ�������

void CSnakeView::OnBegin()
{
	// TODO: �ڴ���������������

	CClientDC dc(this);
	for (int i=0;i<30;i++)
	{
		for (int j=0;j<30;j++)
		{
			dc.StretchBlt(i*10,j*10,10,10,&dc,0,0,10,10,WHITENESS);
		}
	}
	//delete p_snake;
	Snakebody *snake = new Snakebody(&dc);
	p_snake = snake;
	direction = DOWN;
	k_direction = DOWN;
	m_time = 500;
	food.x = 10;
	food.y = 10;
	dc.StretchBlt(food.x*10,food.y*10,10,10,&dc,0,0,10,10,BLACKNESS);
	::KillTimer(this->m_hWnd,0);
	::SetTimer(this->m_hWnd,0,m_time,NULL);
}

void CSnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	direction = k_direction;
	CClientDC dc(this);
	switch(direction)
	{
	case UP:
		if (p_snake->head().x == food.x && p_snake->head().y-1 == food.y)
		{
			p_snake->add(food,&dc);
			food.x = 0;
			food.y = 0;
			::KillTimer(this->m_hWnd,0);
			m_time = m_time * 0.9;
			::SetTimer(this->m_hWnd,0,m_time,NULL);
			return;
		}
		break;
	case DOWN:
		if (p_snake->head().x == food.x && p_snake->head().y+1 == food.y)
		{
			p_snake->add(food,&dc);
			food.x = 0;
			food.y = 0;
			::KillTimer(this->m_hWnd,0);
			m_time = m_time * 0.9;
			::SetTimer(this->m_hWnd,0,m_time,NULL);
			return;
		}
		break;
	case LEFT:
		if (p_snake->head().x-1 == food.x && p_snake->head().y == food.y)
		{
			p_snake->add(food,&dc);
			food.x = 0;
			food.y = 0;
			::KillTimer(this->m_hWnd,0);
			m_time = m_time * 0.9;
			::SetTimer(this->m_hWnd,0,m_time,NULL);
			return;
		}

		break;
	case RIGHT:
		if (p_snake->head().x+1 == food.x && p_snake->head().y == food.y)
		{
			p_snake->add(food,&dc);
			food.x = 0;
			food.y = 0;
			::KillTimer(this->m_hWnd,0);
			m_time = m_time * 0.9;
			::SetTimer(this->m_hWnd,0,m_time,NULL);
			return;
		}
		break;
	}
	if(!p_snake->move(direction,&dc))
	{
		::KillTimer(this->m_hWnd,0);
		CString str;
		str.Format("Game Over!\n��ĵ÷�Ϊ��%d",p_snake->snakesize()-3);
		MessageBox(str);
	}
	if (food.x == 0 && food.y == 0)
	{
		do
		{
			srand((unsigned)time(NULL));
			food.x = rand() % 30;
			food.y = rand() % 30;
		}while(!p_snake->foodcheak(food));
		dc.StretchBlt(food.x*10,food.y*10,10,10,&dc,0,0,10,10,BLACKNESS);
	}
	CString str;
	str.Format("��ĵ÷�Ϊ:%d     ",p_snake->snakesize()-3);
	dc.TextOutA(0,301,str);
	str.Format("�ƶ��ٶ�Ϊ��%.3lf     ",1000.0/m_time);
	dc.TextOutA(0,316,str);
	CView::OnTimer(nIDEvent);
}



void CSnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
	case VK_UP:
		if(direction != DOWN) k_direction = UP;
		break;
	case VK_DOWN:
		if(direction != UP) k_direction = DOWN;
		break;
	case VK_LEFT:
		if(direction != RIGHT) k_direction = LEFT;
		break;
	case VK_RIGHT:
		if(direction != LEFT) k_direction = RIGHT;
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
