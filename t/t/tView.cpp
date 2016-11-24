// tView.cpp : CtView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CtView ����/����

CtView::CtView()
{
	// TODO: �ڴ˴���ӹ������

}

CtView::~CtView()
{
}

BOOL CtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CtView ����

void CtView::OnDraw(CDC* /*pDC*/)
{
	CtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CtView ��ӡ

BOOL CtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CtView ���

#ifdef _DEBUG
void CtView::AssertValid() const
{
	CView::AssertValid();
}

void CtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtDoc* CtView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtDoc)));
	return (CtDoc*)m_pDocument;
}
#endif //_DEBUG


// CtView ��Ϣ�������

void CtView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nChar == 65)
	{
		keybd_event(65,0,KEYEVENTF_KEYUP,0);
		keybd_event(66,0,0,0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CtView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format("%d",nChar);
	MessageBox(str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
