// bowerDoc.h : CbowerDoc ��Ľӿ�
//


#pragma once


class CbowerDoc : public CDocument
{
protected: // �������л�����
	CbowerDoc();
	DECLARE_DYNCREATE(CbowerDoc)

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
	virtual ~CbowerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


