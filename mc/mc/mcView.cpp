// mcView.cpp : CmcView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmcView ����/����

CmcView::CmcView()
{
	// TODO: �ڴ˴���ӹ������

}

CmcView::~CmcView()
{
}

BOOL CmcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmcView ����

void CmcView::OnDraw(CDC* /*pDC*/)
{
	CmcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmcView ��ӡ

BOOL CmcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CmcView ���

#ifdef _DEBUG
void CmcView::AssertValid() const
{
	CView::AssertValid();
}

void CmcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmcDoc* CmcView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmcDoc)));
	return (CmcDoc*)m_pDocument;
}
#endif //_DEBUG


// CmcView ��Ϣ�������
