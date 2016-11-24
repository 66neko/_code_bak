// dasView.cpp : CdasView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CdasView ����/����

CdasView::CdasView()
{
	// TODO: �ڴ˴���ӹ������

}

CdasView::~CdasView()
{
}

BOOL CdasView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CdasView ����

void CdasView::OnDraw(CDC* /*pDC*/)
{
	CdasDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CdasView ��ӡ

BOOL CdasView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CdasView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CdasView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CdasView ���

#ifdef _DEBUG
void CdasView::AssertValid() const
{
	CView::AssertValid();
}

void CdasView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdasDoc* CdasView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdasDoc)));
	return (CdasDoc*)m_pDocument;
}
#endif //_DEBUG


// CdasView ��Ϣ�������
