// oplView.cpp : CoplView ���ʵ��
//

#include "stdafx.h"
#include "opl.h"

#include "oplDoc.h"
#include "oplView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CoplView

IMPLEMENT_DYNCREATE(CoplView, CView)

BEGIN_MESSAGE_MAP(CoplView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CoplView ����/����

CoplView::CoplView()
{
	// TODO: �ڴ˴���ӹ������
	begin = false;
}

CoplView::~CoplView()
{
}

BOOL CoplView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�

	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	CView::PreCreateWindow(cs);
	return true;
}

// CoplView ����

void CoplView::OnDraw(CDC* /*pDC*/)
{
	CoplDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	opengl.DisableOpenGL(&hRC);
	CClientDC dc(this);
	opengl.EnableOpenGL(&dc.m_hDC,&hRC);
	if (begin != true)
	{
		
		
		SetTimer(1,20,NULL);
		begin = true;
	}
	opengl.SetViewPort(this);
	opengl.SetLight();
	opengl.DrawL(&dc.m_hDC);
}


// CoplView ��ӡ

BOOL CoplView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CoplView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CoplView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CoplView ���

#ifdef _DEBUG
void CoplView::AssertValid() const
{
	CView::AssertValid();
}

void CoplView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CoplDoc* CoplView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CoplDoc)));
	return (CoplDoc*)m_pDocument;
}
#endif //_DEBUG


// CoplView ��Ϣ�������

void CoplView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//opengl.Angle();
	CClientDC dc(this);
	opengl.ChangeView(1);
	//opengl.DrawL(&dc.m_hDC);
	CView::OnTimer(nIDEvent);
}

//void CoplView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	opengl.ChangeView(UP);
//	CView::OnLButtonDown(nFlags, point);
//}
