// oplDoc.h : CoplDoc ��Ľӿ�
//


#pragma once


class CoplDoc : public CDocument
{
protected: // �������л�����
	CoplDoc();
	DECLARE_DYNCREATE(CoplDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CoplDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


