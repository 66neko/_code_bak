// SnakeADoc.cpp : CSnakeADoc ���ʵ��
//

#include "stdafx.h"
#include "SnakeA.h"

#include "SnakeADoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeADoc

IMPLEMENT_DYNCREATE(CSnakeADoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeADoc, CDocument)
END_MESSAGE_MAP()


// CSnakeADoc ����/����

CSnakeADoc::CSnakeADoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSnakeADoc::~CSnakeADoc()
{
}

BOOL CSnakeADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSnakeADoc ���л�

void CSnakeADoc::Serialize(CArchive& ar)
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


// CSnakeADoc ���

#ifdef _DEBUG
void CSnakeADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSnakeADoc ����
