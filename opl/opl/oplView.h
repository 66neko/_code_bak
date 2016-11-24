// oplView.h : CoplView ��Ľӿ�
//


#pragma once
#include "OpenGL.h"

class CoplView : public CView
{
protected: // �������л�����
	CoplView();
	DECLARE_DYNCREATE(CoplView)

// ����
public:
	CoplDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CoplView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	COpenGL opengl;
	bool begin;
	HGLRC hRC;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // oplView.cpp �еĵ��԰汾
inline CoplDoc* CoplView::GetDocument() const
   { return reinterpret_cast<CoplDoc*>(m_pDocument); }
#endif

