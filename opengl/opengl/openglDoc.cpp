// openglDoc.cpp : CopenglDoc ���ʵ��
//

#include "stdafx.h"
#include "opengl.h"

#include "openglDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CopenglDoc

IMPLEMENT_DYNCREATE(CopenglDoc, CDocument)

BEGIN_MESSAGE_MAP(CopenglDoc, CDocument)
END_MESSAGE_MAP()


// CopenglDoc ����/����

CopenglDoc::CopenglDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CopenglDoc::~CopenglDoc()
{
}

BOOL CopenglDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CopenglDoc ���л�

void CopenglDoc::Serialize(CArchive& ar)
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


// CopenglDoc ���

#ifdef _DEBUG
void CopenglDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CopenglDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CopenglDoc ����
