// SnakeDoc.h : CSnakeDoc ��Ľӿ�
//


#pragma once


class CSnakeDoc : public CDocument
{
protected: // �������л�����
	CSnakeDoc();
	DECLARE_DYNCREATE(CSnakeDoc)

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
	virtual ~CSnakeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


