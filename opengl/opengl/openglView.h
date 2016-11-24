// openglView.h : CopenglView ��Ľӿ�
//
#include "gl.h"

#pragma once


class CopenglView : public CView
{
protected: // �������л�����
	CopenglView();
	DECLARE_DYNCREATE(CopenglView)

// ����
public:
	CopenglDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CopenglView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	gl opengl;
	HGLRC hRC;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // openglView.cpp �еĵ��԰汾
inline CopenglDoc* CopenglView::GetDocument() const
   { return reinterpret_cast<CopenglDoc*>(m_pDocument); }
#endif

