// TCSView.cpp : CTCSView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTCSView ����/����

CTCSView::CTCSView()
{
	// TODO: �ڴ˴���ӹ������

}

CTCSView::~CTCSView()
{
}

BOOL CTCSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTCSView ����

void CTCSView::OnDraw(CDC* /*pDC*/)
{
	CTCSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTCSView ��ӡ

BOOL CTCSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTCSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTCSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CTCSView ���

#ifdef _DEBUG
void CTCSView::AssertValid() const
{
	CView::AssertValid();
}

void CTCSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTCSDoc* CTCSView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTCSDoc)));
	return (CTCSDoc*)m_pDocument;
}
#endif //_DEBUG


// CTCSView ��Ϣ�������
