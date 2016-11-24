// openglView.cpp : CopenglView 类的实现
//

#include "stdafx.h"
#include "opengl.h"

#include "openglDoc.h"
#include "openglView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CopenglView

IMPLEMENT_DYNCREATE(CopenglView, CView)

BEGIN_MESSAGE_MAP(CopenglView, CView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CopenglView 构造/析构

CopenglView::CopenglView()
{
	// TODO: 在此处添加构造代码

}

CopenglView::~CopenglView()
{
}

BOOL CopenglView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CopenglView 绘制

void CopenglView::OnDraw(CDC* /*pDC*/)
{
	CopenglDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	static int mark = 1;
	if (mark == 1)
	{
		//opengl.DisableOpenGL(&dc.m_hDC,&hRC);
		opengl.EnableOpenGL(&dc.m_hDC,&hRC);
		mark = 0;
	}
	opengl.ReadBitmap(&dc.m_hDC);
	opengl.DrawCube(&dc.m_hDC);
	SetTimer(0,25,NULL);
}


// CopenglView 诊断

#ifdef _DEBUG
void CopenglView::AssertValid() const
{
	CView::AssertValid();
}

void CopenglView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CopenglDoc* CopenglView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CopenglDoc)));
	return (CopenglDoc*)m_pDocument;
}
#endif //_DEBUG


// CopenglView 消息处理程序

void CopenglView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	opengl.ReadBitmap(&dc.m_hDC);
	opengl.DrawCube(&dc.m_hDC);
	CView::OnTimer(nIDEvent);
}

void CopenglView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	switch(nChar)
	{
	case VK_UP:
		yy += 0.1;
		break;
	case VK_DOWN:
		yy -= 0.1;
		break;
	case VK_LEFT:
		xx -= 0.1;
		
		str.Format("%f",xx);
		MessageBox(str);
		break;
	case VK_RIGHT:
		xx += 0.1;
		break;

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
