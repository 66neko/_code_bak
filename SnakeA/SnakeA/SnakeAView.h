// SnakeAView.h : CSnakeAView 类的接口
//


#pragma once
#include "Table.h"

class CSnakeAView : public CView
{
protected: // 仅从序列化创建
	CSnakeAView();
	DECLARE_DYNCREATE(CSnakeAView)

// 属性
public:
	CSnakeADoc* GetDocument() const;

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
	virtual ~CSnakeAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	Table table; //为view类添加一个桌子对象
	int direction; //蛇当前移动方向
public:
	afx_msg void OnBegin();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // SnakeAView.cpp 中的调试版本
inline CSnakeADoc* CSnakeAView::GetDocument() const
   { return reinterpret_cast<CSnakeADoc*>(m_pDocument); }
#endif

