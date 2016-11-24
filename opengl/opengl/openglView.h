// openglView.h : CopenglView 类的接口
//
#include "gl.h"

#pragma once


class CopenglView : public CView
{
protected: // 仅从序列化创建
	CopenglView();
	DECLARE_DYNCREATE(CopenglView)

// 属性
public:
	CopenglDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CopenglView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	gl opengl;
	HGLRC hRC;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // openglView.cpp 中的调试版本
inline CopenglDoc* CopenglView::GetDocument() const
   { return reinterpret_cast<CopenglDoc*>(m_pDocument); }
#endif

