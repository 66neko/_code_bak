// ChildView.h : CChildView 类的接口
//


#pragma once


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 属性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	//状态 0=匹配未开始 1=正在匹配 2=正在游戏状态
	int _state;
	int _findState;
	BackGround background;
	//qizi
	//Image imageRed;
	wchar_t *Wfile[15];
	wchar_t *Wback;
	//end
	//检验鼠标点击状态 0=未选择棋子，1=已选择棋子
	int _mouseSelect;
	//客户端主体
	MainClient client;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFind();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// 棋盘界面初始化绘制
	void InitChessboard(void);
	// 根据鼠标位置或者棋子
	CPoint GetChessmanFromMouse(CPoint _point);
	// 根据反馈消息执行动作
	void GetFeedBack(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHuiqi();
};

