// mcDoc.h : CmcDoc ��Ľӿ�
//


#pragma once


class CmcDoc : public CDocument
{
protected: // �������л�����
	CmcDoc();
	DECLARE_DYNCREATE(CmcDoc)

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
	virtual ~CmcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


