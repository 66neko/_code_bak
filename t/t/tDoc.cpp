// tDoc.cpp : CtDoc ���ʵ��
//

#include "stdafx.h"
#include "t.h"

#include "tDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtDoc

IMPLEMENT_DYNCREATE(CtDoc, CDocument)

BEGIN_MESSAGE_MAP(CtDoc, CDocument)
END_MESSAGE_MAP()


// CtDoc ����/����

CtDoc::CtDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CtDoc::~CtDoc()
{
}

BOOL CtDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CtDoc ���л�

void CtDoc::Serialize(CArchive& ar)
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


// CtDoc ���

#ifdef _DEBUG
void CtDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtDoc ����
