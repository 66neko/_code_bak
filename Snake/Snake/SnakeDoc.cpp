// SnakeDoc.cpp : CSnakeDoc ���ʵ��
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeDoc

IMPLEMENT_DYNCREATE(CSnakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeDoc, CDocument)
END_MESSAGE_MAP()


// CSnakeDoc ����/����

CSnakeDoc::CSnakeDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSnakeDoc::~CSnakeDoc()
{
}

BOOL CSnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSnakeDoc ���л�

void CSnakeDoc::Serialize(CArchive& ar)
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


// CSnakeDoc ���

#ifdef _DEBUG
void CSnakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSnakeDoc ����
