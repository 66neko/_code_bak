// oplDoc.cpp : CoplDoc ���ʵ��
//

#include "stdafx.h"
#include "opl.h"

#include "oplDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CoplDoc

IMPLEMENT_DYNCREATE(CoplDoc, CDocument)

BEGIN_MESSAGE_MAP(CoplDoc, CDocument)
END_MESSAGE_MAP()


// CoplDoc ����/����

CoplDoc::CoplDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CoplDoc::~CoplDoc()
{
}

BOOL CoplDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CoplDoc ���л�

void CoplDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CoplDoc ���

#ifdef _DEBUG
void CoplDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CoplDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CoplDoc ����
