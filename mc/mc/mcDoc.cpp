// mcDoc.cpp : CmcDoc ���ʵ��
//

#include "stdafx.h"
#include "mc.h"

#include "mcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmcDoc

IMPLEMENT_DYNCREATE(CmcDoc, CDocument)

BEGIN_MESSAGE_MAP(CmcDoc, CDocument)
END_MESSAGE_MAP()


// CmcDoc ����/����

CmcDoc::CmcDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CmcDoc::~CmcDoc()
{
}

BOOL CmcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CmcDoc ���л�

void CmcDoc::Serialize(CArchive& ar)
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


// CmcDoc ���

#ifdef _DEBUG
void CmcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmcDoc ����
