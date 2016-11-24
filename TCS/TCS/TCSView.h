// TCSView.h : CTCSView 类的接口
//


#pragma once


class CTCSView : public CView
{
protected: // 仅从序列化创建
	CTCSView();
	DECLARE_DYNCREATE(CTCSView)

// 属性
public:
	CTCSDoc* GetDocument() const;

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
	virtual ~CTCSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TCSView.cpp 中的调试版本
inline CTCSDoc* CTCSView::GetDocument() const
   { return reinterpret_cast<CTCSDoc*>(m_pDocument); }
#endif

