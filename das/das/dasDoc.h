// dasDoc.h : CdasDoc ��Ľӿ�
//


#pragma once


class CdasDoc : public CDocument
{
protected: // �������л�����
	CdasDoc();
	DECLARE_DYNCREATE(CdasDoc)

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
	virtual ~CdasDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


