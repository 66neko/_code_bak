// TCSDoc.cpp : CTCSDoc ���ʵ��
//

#include "stdafx.h"
#include "TCS.h"

#include "TCSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCSDoc

IMPLEMENT_DYNCREATE(CTCSDoc, CDocument)

BEGIN_MESSAGE_MAP(CTCSDoc, CDocument)
END_MESSAGE_MAP()


// CTCSDoc ����/����

CTCSDoc::CTCSDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CTCSDoc::~CTCSDoc()
{
}

BOOL CTCSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CTCSDoc ���л�

void CTCSDoc::Serialize(CArchive& ar)
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


// CTCSDoc ���

#ifdef _DEBUG
void CTCSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTCSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTCSDoc ����
