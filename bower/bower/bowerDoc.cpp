// bowerDoc.cpp : CbowerDoc ���ʵ��
//

#include "stdafx.h"
#include "bower.h"

#include "bowerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbowerDoc

IMPLEMENT_DYNCREATE(CbowerDoc, CDocument)

BEGIN_MESSAGE_MAP(CbowerDoc, CDocument)
END_MESSAGE_MAP()


// CbowerDoc ����/����

CbowerDoc::CbowerDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CbowerDoc::~CbowerDoc()
{
}

BOOL CbowerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CbowerDoc ���л�

void CbowerDoc::Serialize(CArchive& ar)
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


// CbowerDoc ���

#ifdef _DEBUG
void CbowerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CbowerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CbowerDoc ����
