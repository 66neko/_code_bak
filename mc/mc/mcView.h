// mcView.h : CmcView ��Ľӿ�
//


#pragma once


class CmcView : public CView
{
protected: // �������л�����
	CmcView();
	DECLARE_DYNCREATE(CmcView)

// ����
public:
	CmcDoc* GetDocument() const;

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
	virtual ~CmcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // mcView.cpp �еĵ��԰汾
inline CmcDoc* CmcView::GetDocument() const
   { return reinterpret_cast<CmcDoc*>(m_pDocument); }
#endif

