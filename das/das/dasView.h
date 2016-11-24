// dasView.h : CdasView 类的接口
//


#pragma once


class CdasView : public CView
{
protected: // 仅从序列化创建
	CdasView();
	DECLARE_DYNCREATE(CdasView)

// 属性
public:
	CdasDoc* GetDocument() const;

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
	virtual ~CdasView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // dasView.cpp 中的调试版本
inline CdasDoc* CdasView::GetDocument() const
   { return reinterpret_cast<CdasDoc*>(m_pDocument); }
#endif

