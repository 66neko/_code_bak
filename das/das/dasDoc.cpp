// dasDoc.cpp : CdasDoc ���ʵ��
//

#include "stdafx.h"
#include "das.h"

#include "dasDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdasDoc

IMPLEMENT_DYNCREATE(CdasDoc, CDocument)

BEGIN_MESSAGE_MAP(CdasDoc, CDocument)
END_MESSAGE_MAP()


// CdasDoc ����/����

CdasDoc::CdasDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CdasDoc::~CdasDoc()
{
}

BOOL CdasDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CdasDoc ���л�

void CdasDoc::Serialize(CArchive& ar)
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


// CdasDoc ���

#ifdef _DEBUG
void CdasDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdasDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdasDoc ����
