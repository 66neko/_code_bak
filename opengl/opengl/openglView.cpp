// openglView.cpp : CopenglView ���ʵ��
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

// CopenglView ����/����

CopenglView::CopenglView()
{
	// TODO: �ڴ˴���ӹ������

}

CopenglView::~CopenglView()
{
}

BOOL CopenglView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CopenglView ����

void CopenglView::OnDraw(CDC* /*pDC*/)
{
	CopenglDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CopenglView ���

#ifdef _DEBUG
void CopenglView::AssertValid() const
{
	CView::AssertValid();
}

void CopenglView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CopenglDoc* CopenglView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CopenglDoc)));
	return (CopenglDoc*)m_pDocument;
}
#endif //_DEBUG


// CopenglView ��Ϣ�������

void CopenglView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	opengl.ReadBitmap(&dc.m_hDC);
	opengl.DrawCube(&dc.m_hDC);
	CView::OnTimer(nIDEvent);
}

void CopenglView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
