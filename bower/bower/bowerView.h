// bowerView.h : CbowerView ��Ľӿ�
//


#pragma once


class CbowerView : public CHtmlView
{
protected: // �������л�����
	CbowerView();
	DECLARE_DYNCREATE(CbowerView)

// ����
public:
	CbowerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CbowerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // bowerView.cpp �еĵ��԰汾
inline CbowerDoc* CbowerView::GetDocument() const
   { return reinterpret_cast<CbowerDoc*>(m_pDocument); }
#endif

