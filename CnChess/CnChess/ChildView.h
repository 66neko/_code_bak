// ChildView.h : CChildView ��Ľӿ�
//


#pragma once


// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	//״̬ 0=ƥ��δ��ʼ 1=����ƥ�� 2=������Ϸ״̬
	int _state;
	int _findState;
	BackGround background;
	//qizi
	//Image imageRed;
	wchar_t *Wfile[15];
	wchar_t *Wback;
	//end
	//���������״̬ 0=δѡ�����ӣ�1=��ѡ������
	int _mouseSelect;
	//�ͻ�������
	MainClient client;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFind();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// ���̽����ʼ������
	void InitChessboard(void);
	// �������λ�û�������
	CPoint GetChessmanFromMouse(CPoint _point);
	// ���ݷ�����Ϣִ�ж���
	void GetFeedBack(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHuiqi();
};

