// dasView.h : CdasView ��Ľӿ�
//


#pragma once


class CdasView : public CView
{
protected: // �������л�����
	CdasView();
	DECLARE_DYNCREATE(CdasView)

// ����
public:
	CdasDoc* GetDocument() const;

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
	virtual ~CdasView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // dasView.cpp �еĵ��԰汾
inline CdasDoc* CdasView::GetDocument() const
   { return reinterpret_cast<CdasDoc*>(m_pDocument); }
#endif

