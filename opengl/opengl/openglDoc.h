// openglDoc.h : CopenglDoc ��Ľӿ�
//


#pragma once


class CopenglDoc : public CDocument
{
protected: // �������л�����
	CopenglDoc();
	DECLARE_DYNCREATE(CopenglDoc)

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
	virtual ~CopenglDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


