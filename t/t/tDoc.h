// tDoc.h : CtDoc ��Ľӿ�
//


#pragma once


class CtDoc : public CDocument
{
protected: // �������л�����
	CtDoc();
	DECLARE_DYNCREATE(CtDoc)

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
	virtual ~CtDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


