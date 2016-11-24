// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "CnChess.h"
#include "ChildView.h"
#include "StarDialog.h"
#include "FindDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView():background(&client)
{
	_mouseSelect = 0;
	_state = 0;
	_findState = 0;
	char red1[30] = "png\\1.png";
	size_t len = strlen(red1) + 1;
	size_t converted = 0;
	Wfile[1]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[1], len, red1, _TRUNCATE);
	//this->imageRed[0] = Image(Wred1);

	strcpy_s(red1,30,"png\\0.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[0]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[0], len, red1, _TRUNCATE);
	
	strcpy_s(red1,30,"png\\2.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[2]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[2], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\3.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[3]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[3], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\4.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[4]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[4], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\5.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[5]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[5], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\6.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[6]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[6], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\7.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[7]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[7], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\8.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[8]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[8], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\9.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[9]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[9], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\10.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[10]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[10], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\11.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[11]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[11], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\12.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[12]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[12], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\13.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[13]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[13], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\14.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wfile[14]=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wfile[14], len, red1, _TRUNCATE);

	strcpy_s(red1,30,"png\\background.png");
	len = strlen(red1) + 1;
	converted = 0;
	Wback=(wchar_t*)malloc(len*sizeof(wchar_t));
	mbstowcs_s(&converted, Wback, len, red1, _TRUNCATE);

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_CREATE()
ON_WM_CREATE()
ON_COMMAND(ID_FIND, &CChildView::OnFind)
ON_WM_LBUTTONDOWN()
ON_WM_TIMER()
ON_COMMAND(ID_HUIQI, &CChildView::OnHuiqi)
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	//MessageBox(MyName.GetBuffer());
	/*
	if(_state == 0 && _findState == 0)
	{
		_state = 1;
		_findState = 1;
		CFindDialog m_dlg;
		m_dlg.SetMainClient(&client);
		m_dlg.DoModal();
		_findState = 0;
	}
	*/
	//this->InitChessboard();
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  �ڴ������ר�õĴ�������
	memset(&_sharing,0,sizeof(_sharing));
	memcpy(_sharing.map,client._game._chessboard.map,sizeof(_sharing.map));//��ʼ��
	CMenu *pMenu;
	pMenu = AfxGetMainWnd()->GetMenu();
	pMenu->EnableMenuItem(ID_HUIQI, MF_GRAYED);
	return 0;
}

void CChildView::OnFind()
{
	// TODO: �ڴ���������������
	//MessageBox("1");
	//draw
	//char to wchar
	//end
	
	//end
	if(_sharing._state == 1)
	{
		MessageBox("��Ϸ���ڽ��У�");
		return;
	}
	if(_sharing._state == 0 && _findState == 0)
	{
		
		_findState = 1;
		_sharing._findState = 0;
		CFindDialog m_dlg;
		m_dlg.SetMainClient(&this->background);
		m_dlg.DoModal();
		this->InitChessboard();
		SetTimer(2,200,NULL);
		_findState = 0;
		
	}
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(_sharing._state == 0 || _sharing._myColor*_sharing._player <= 0)
	{
		CWnd::OnLButtonDown(nFlags, point);
		return;
	}
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CPoint po = this->GetChessmanFromMouse(point);
	str.Format("X:%ld Y:%ld",po.x,po.y);
	if(this->_mouseSelect == 1)
	{
		_mouseSelect = 0;
		_sharing.dx = po.x;
		_sharing.dy = po.y;
		_sharing._doneChess = 1;
		//Sleep(1000);
		if(_sharing._feedback == 0)
		{
			this->InitChessboard();
		}
		
	}
	else if(_sharing.map[po.y][po.x]*_sharing._myColor > 0)
	{
		_sharing.kx = po.x;
		_sharing.ky = po.y;
		_mouseSelect = 1;
		
		//�����α߿�
		CClientDC *m_pDC = new CClientDC(this);
		CPen NewPen(PS_SOLID, 5, RGB(255,0,0));  
		m_pDC->SelectObject(&NewPen);  
		//m_pDC->SetROP2(R2_NOTXORPEN);  
		m_pDC->SelectStockObject(NULL_BRUSH); 
		if(_sharing._myColor == 1)
		{
			m_pDC->Rectangle((int)(28+po.x*46.75), (int)(488-po.y*48), (int)(68+po.x*46.75) ,(int)(528-po.y*48)); 
		}
		else
		{
			//m_pDC->Rectangle(28+(int)po.x*46.75, 56+(int)po.y*48, 68+(int)po.x*46.75 ,96+(int)po.y*48);  
			m_pDC->Rectangle((int)(28+po.x*46.75), (int)(56+po.y*48), (int)(68+po.x*46.75) ,(int)(96+po.y*48)); 
		}
		//m_pDC->SelectStockObject(NULL_BRUSH);     
		NewPen.DeleteObject();
		delete m_pDC;
	}
	//this->InitChessboard();
	CWnd::OnLButtonDown(nFlags, point);
}

// ���̽����ʼ������
void CChildView::InitChessboard(void)
{
	CClientDC *pDC = new CClientDC(this);
	CRect rect;
	this->GetWindowRect(&rect);
	Graphics graphics(pDC->m_hDC); // Create a GDI+ graphics object
	Image image(Wback); // Construct an image
	//graphics.DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight());
	graphics.DrawImage(&image, 0, 30, 470, 523);
	//delete pDC;
	//����
	//Image im(Wfile[1]);
	//graphics.DrawImage(&im, 48-20, 76+3*48-20, 40, 40);
	static Image _image0(Wfile[0]);
	static Image _image1(Wfile[1]);
	static Image _image2(Wfile[2]);
	static Image _image3(Wfile[3]);
	static Image _image4(Wfile[4]);
	static Image _image5(Wfile[5]);
	static Image _image6(Wfile[6]);
	static Image _image7(Wfile[7]);
	static Image _image8(Wfile[8]);
	static Image _image9(Wfile[9]);
	static Image _image10(Wfile[10]);
	static Image _image11(Wfile[11]);
	static Image _image12(Wfile[12]);
	static Image _image13(Wfile[13]);
	static Image _image14(Wfile[14]);
	static Image *_pImage[15] = {
		&_image0,
		&_image1,
		&_image2,
		&_image3,
		&_image4,
		&_image5,
		&_image6,
		&_image7,
		&_image8,
		&_image9,
		&_image10,
		&_image11,
		&_image12,
		&_image13,
		&_image14
	};
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(_sharing.map[i][j] != 0)
			{
				//Image _image(Wfile[_sharing.map[i][j]+7]);
				if(_sharing._myColor == 1)
				{
					graphics.DrawImage(_pImage[_sharing.map[i][j]+7], (int)(28+j*46.75), 488-i*48, 40, 40);
				}
				else
				{
					graphics.DrawImage(_pImage[_sharing.map[i][j]+7], (int)(28+j*46.75), 56+i*48, 40, 40);
				}
			}
		}
	}
	//��ӡ״̬
	CString strState;
	if(_sharing._state == 0)
	{
		strState += "��Ϸδ��ʼ������FINDѰ�Ҷ���~";
	}
	if(_sharing._feedback == 1 && _sharing._player != _sharing._myColor)
	{
		strState += "����ɹ���";
	}
	if(_sharing._feedback == 1 && _sharing._player == _sharing._myColor)
	{
		strState += "�ֵ������壡";
	}
	if(_sharing._feedback == 3 && _sharing._player != _sharing._myColor)
	{
		strState += "�Է�����ɹ���";
	}
	if(_sharing._feedback == 3 && _sharing._player == _sharing._myColor)
	{
		strState += "�����ɹ���";
	}
	if(_sharing._feedback == 2 && _sharing._myColor == _sharing._player)
	{
		strState += "�����ʧ�ܣ�";
	}
	rect = CRect(1,20,450,40);
	pDC->DrawText(strState,&rect, DT_SINGLELINE);
	//
	Sleep(1000);
	rect = CRect(10,0,450,20);
	CString str("�����ǳƣ�");
	str += _sharing.EnemyName;
	if(_sharing._player == 1)
	{
		str += "  ��ǰ���巽���췽";
	}
	else if(_sharing._player == -1)
	{
		str += "  ��ǰ���巽���ڷ�";
	}
	else
	{
		str += "   ��ȡ���巽����";
	}
	pDC->DrawText(str,&rect,DT_CENTER | DT_SINGLELINE);
	delete pDC;
}


// �������λ�û�������
CPoint CChildView::GetChessmanFromMouse(CPoint _point)
{
	CPoint chessmanPoint;
	chessmanPoint.x = (int)((_point.x - 28)/46.75);
	chessmanPoint.y = (_point.y - 56)/48;
	if(_sharing._myColor == 1)
	{
		chessmanPoint.y = 9 - chessmanPoint.y;
	}
	return chessmanPoint;
}

// ���ݷ�����Ϣִ�ж���
void CChildView::GetFeedBack(void)
{
	switch(_sharing._feedback)
	{
	case 0:
		break;
	case 1:
		Sleep(100);
		this->InitChessboard();
		_sharing._feedback = 0;
		break;
	case 2:
		break;
	case 3:
		if(_sharing._myColor == _sharing._player)
		{
			CMenu *pMenu;
			pMenu = AfxGetMainWnd()->GetMenu();
			pMenu->EnableMenuItem(ID_HUIQI, MF_GRAYED);
		}
		this->InitChessboard();
		_sharing._feedback = 0;
		break;
	case 4:
		break;
	case 5:
		
		_sharing._state = 0;
		_sharing._myColor = 0;
		_sharing._findState = 0;
		_sharing._feedback = 0;
		this->InitChessboard();
		KillTimer(2);
		MessageBox("�췽ʤ��");
		break;
	case 6:
		
		_sharing._state = 0;
		_sharing._myColor = 0;
		_sharing._findState = 0;
		_sharing._feedback = 0;
		this->InitChessboard();
		KillTimer(2);
		MessageBox("�ڷ�ʤ��");
		break;
	}
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent = 2)
	{
		if(_sharing._state == 2)
		{
			MessageBox("���ѵ���!");
			exit(0);
		}
		this->GetFeedBack();
	}
	CWnd::OnTimer(nIDEvent);
}

void CChildView::OnHuiqi()
{
	// TODO: �ڴ���������������
	
	_sharing.kx = -1;
	_sharing.ky = -1;
	_sharing.dx = -1;
	_sharing.dy = -1;
	_sharing._doneChess = 1;
}
