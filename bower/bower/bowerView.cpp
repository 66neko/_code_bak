// bowerView.cpp : CbowerView ���ʵ��
//

#include "stdafx.h"
#include "bower.h"

#include "bowerDoc.h"
#include "bowerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbowerView

IMPLEMENT_DYNCREATE(CbowerView, CHtmlView)

BEGIN_MESSAGE_MAP(CbowerView, CHtmlView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

// CbowerView ����/����

CbowerView::CbowerView()
{
	// TODO: �ڴ˴���ӹ������

}

CbowerView::~CbowerView()
{
}

BOOL CbowerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CbowerView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.baidu.com"),NULL,NULL);
}


// CbowerView ��ӡ



// CbowerView ���

#ifdef _DEBUG
void CbowerView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CbowerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CbowerDoc* CbowerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbowerDoc)));
	return (CbowerDoc*)m_pDocument;
}
#endif //_DEBUG


// CbowerView ��Ϣ�������
