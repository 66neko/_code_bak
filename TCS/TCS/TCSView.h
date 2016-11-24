// TCSView.h : CTCSView ��Ľӿ�
//


#pragma once


class CTCSView : public CView
{
protected: // �������л�����
	CTCSView();
	DECLARE_DYNCREATE(CTCSView)

// ����
public:
	CTCSDoc* GetDocument() const;

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
	virtual ~CTCSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TCSView.cpp �еĵ��԰汾
inline CTCSDoc* CTCSView::GetDocument() const
   { return reinterpret_cast<CTCSDoc*>(m_pDocument); }
#endif

