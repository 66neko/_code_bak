// TCSDoc.h : CTCSDoc ��Ľӿ�
//


#pragma once


class CTCSDoc : public CDocument
{
protected: // �������л�����
	CTCSDoc();
	DECLARE_DYNCREATE(CTCSDoc)

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
	virtual ~CTCSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


