// SnakeView.h : CSnakeView ��Ľӿ�
//
#include "Snakebody.h"

#pragma once


class CSnakeView : public CView
{
protected: // �������л�����
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView)

// ����
public:
	CSnakeDoc* GetDocument() const;

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
	virtual ~CSnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	Snakebody *p_snake;
	afx_msg void OnBegin();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int direction;
	Cell food;
public:
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	int num;
	int k_direction;
	int m_time;
};

#ifndef _DEBUG  // SnakeView.cpp �еĵ��԰汾
inline CSnakeDoc* CSnakeView::GetDocument() const
   { return reinterpret_cast<CSnakeDoc*>(m_pDocument); }
#endif

