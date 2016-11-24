// SnakeAView.h : CSnakeAView ��Ľӿ�
//


#pragma once
#include "Table.h"

class CSnakeAView : public CView
{
protected: // �������л�����
	CSnakeAView();
	DECLARE_DYNCREATE(CSnakeAView)

// ����
public:
	CSnakeADoc* GetDocument() const;

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
	virtual ~CSnakeAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	Table table; //Ϊview�����һ�����Ӷ���
	int direction; //�ߵ�ǰ�ƶ�����
public:
	afx_msg void OnBegin();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // SnakeAView.cpp �еĵ��԰汾
inline CSnakeADoc* CSnakeAView::GetDocument() const
   { return reinterpret_cast<CSnakeADoc*>(m_pDocument); }
#endif

