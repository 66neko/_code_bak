// bowerView.h : CbowerView 类的接口
//


#pragma once


class CbowerView : public CHtmlView
{
protected: // 仅从序列化创建
	CbowerView();
	DECLARE_DYNCREATE(CbowerView)

// 属性
public:
	CbowerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CbowerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // bowerView.cpp 中的调试版本
inline CbowerDoc* CbowerView::GetDocument() const
   { return reinterpret_cast<CbowerDoc*>(m_pDocument); }
#endif

