// SnakeView.h : CSnakeView 类的接口
//
#include "Snakebody.h"

#pragma once


class CSnakeView : public CView
{
protected: // 仅从序列化创建
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView)

// 属性
public:
	CSnakeDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // SnakeView.cpp 中的调试版本
inline CSnakeDoc* CSnakeView::GetDocument() const
   { return reinterpret_cast<CSnakeDoc*>(m_pDocument); }
#endif

