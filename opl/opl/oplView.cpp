// oplView.cpp : CoplView 类的实现
//

#include "stdafx.h"
#include "opl.h"

#include "oplDoc.h"
#include "oplView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CoplView

IMPLEMENT_DYNCREATE(CoplView, CView)

BEGIN_MESSAGE_MAP(CoplView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CoplView 构造/析构

CoplView::CoplView()
{
	// TODO: 在此处添加构造代码
	begin = false;
}

CoplView::~CoplView()
{
}

BOOL CoplView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改

	//  CREATESTRUCT cs 来修改窗口类或样式
	CView::PreCreateWindow(cs);
	return true;
}

// CoplView 绘制

void CoplView::OnDraw(CDC* /*pDC*/)
{
	CoplDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	opengl.DisableOpenGL(&hRC);
	CClientDC dc(this);
	opengl.EnableOpenGL(&dc.m_hDC,&hRC);
	if (begin != true)
	{
		
		
		SetTimer(1,20,NULL);
		begin = true;
	}
	opengl.SetViewPort(this);
	opengl.SetLight();
	opengl.DrawL(&dc.m_hDC);
}


// CoplView 打印

BOOL CoplView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CoplView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CoplView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CoplView 诊断

#ifdef _DEBUG
void CoplView::AssertValid() const
{
	CView::AssertValid();
}

void CoplView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CoplDoc* CoplView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CoplDoc)));
	return (CoplDoc*)m_pDocument;
}
#endif //_DEBUG


// CoplView 消息处理程序

void CoplView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//opengl.Angle();
	CClientDC dc(this);
	opengl.ChangeView(1);
	//opengl.DrawL(&dc.m_hDC);
	CView::OnTimer(nIDEvent);
}

//void CoplView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	opengl.ChangeView(UP);
//	CView::OnLButtonDown(nFlags, point);
//}
