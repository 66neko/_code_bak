#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	//red
	chessman_red_bin1 = NULL;
	chessman_red_bin2 = NULL;
	chessman_red_bin3 = NULL;
	chessman_red_bin4 = NULL;
	chessman_red_bin5 = NULL;
	chessman_red_pao1 = NULL;
	chessman_red_pao2 = NULL;
	chessman_red_ju1 = NULL;
	chessman_red_ju2 = NULL;
	chessman_red_ma1 = NULL;
	chessman_red_ma2 = NULL;
	chessman_red_xiang1 = NULL;
	chessman_red_xiang2 = NULL;
	chessman_red_shi1 = NULL;
	chessman_red_shi2 = NULL;
	chessman_red_shuai = NULL;
	//black
	chessman_black_zu1 = NULL;
	chessman_black_zu2 = NULL;
	chessman_black_zu3 = NULL;
	chessman_black_zu4 = NULL;
	chessman_black_zu5 = NULL;
	chessman_black_pao1 = NULL;
	chessman_black_pao2 = NULL;
	chessman_black_ju1 = NULL;
	chessman_black_ju2 = NULL;
	chessman_black_ma1 = NULL;
	chessman_black_ma2 = NULL;
	chessman_black_xiang1 = NULL;
	chessman_black_xiang2 = NULL;
	chessman_black_shi1 = NULL;
	chessman_black_shi2 = NULL;
	chessman_black_jiang = NULL;

	//»ÚÆåÏà¹Ø
	_backFlag = 0;
	_backRound = 0;
	_backChessmanRedA = Chessman();
	_backChessmanRedB = Chessman();
	_backChessmanBlackA = Chessman();
	_backChessmanBlackB = Chessman();
	_backRedA = NULL;
	_backRedB = NULL;
	_backBlackA = NULL;
	_backBlackB = NULL;

	this->Init();
}
ChessBoard::~ChessBoard()
{
}
bool ChessBoard::Init()
{
	memset(this->map,0,sizeof(this->map));
	/*
	int map_p[10][9] = {3,4,5,6,7,6,5,4,3,
		   0,0,0,0,0,0,0,0,0,
		   0,2,0,0,0,0,0,2,0,
		   1,0,1,0,1,0,1,0,1,
		   0,0,0,0,0,0,0,0,0,
		   0,0,0,0,0,0,0,0,0,
		   -1,0,-1,0,-1,0,-1,0,-1,
		   0,-2,0,0,0,0,0,-2,0,
		   0,0,0,0,0,0,0,0,0,
		   -3,-4,-5,-6,-7,-6,-5,-4,-3
		  };
	memcpy(this->map,map_p,sizeof(map_p));
	*/
	//red
	InitChessmanBase(chessman_red_bin1,CHESSMAN_TYPE_BIN,CHESSMAN_COLOR_RED,0,3);
	InitChessmanBase(chessman_red_bin2,CHESSMAN_TYPE_BIN,CHESSMAN_COLOR_RED,2,3);
	InitChessmanBase(chessman_red_bin3,CHESSMAN_TYPE_BIN,CHESSMAN_COLOR_RED,4,3);
	InitChessmanBase(chessman_red_bin4,CHESSMAN_TYPE_BIN,CHESSMAN_COLOR_RED,6,3);
	InitChessmanBase(chessman_red_bin5,CHESSMAN_TYPE_BIN,CHESSMAN_COLOR_RED,8,3);
	InitChessmanBase(chessman_red_pao1,CHESSMAN_TYPE_PAO,CHESSMAN_COLOR_RED,1,2);
	InitChessmanBase(chessman_red_pao2,CHESSMAN_TYPE_PAO,CHESSMAN_COLOR_RED,7,2);
	InitChessmanBase(chessman_red_ju1,CHESSMAN_TYPE_JU,CHESSMAN_COLOR_RED,0,0);
	InitChessmanBase(chessman_red_ju2,CHESSMAN_TYPE_JU,CHESSMAN_COLOR_RED,8,0);
	InitChessmanBase(chessman_red_ma1,CHESSMAN_TYPE_MA,CHESSMAN_COLOR_RED,1,0);
	InitChessmanBase(chessman_red_ma2,CHESSMAN_TYPE_MA,CHESSMAN_COLOR_RED,7,0);
	InitChessmanBase(chessman_red_xiang1,CHESSMAN_TYPE_XIANG,CHESSMAN_COLOR_RED,2,0);
	InitChessmanBase(chessman_red_xiang2,CHESSMAN_TYPE_XIANG,CHESSMAN_COLOR_RED,6,0);
	InitChessmanBase(chessman_red_shi1,CHESSMAN_TYPE_SHI,CHESSMAN_COLOR_RED,3,0);
	InitChessmanBase(chessman_red_shi2,CHESSMAN_TYPE_SHI,CHESSMAN_COLOR_RED,5,0);
	InitChessmanBase(chessman_red_shuai,CHESSMAN_TYPE_SHUAI,CHESSMAN_COLOR_RED,4,0);
	//black
	InitChessmanBase(chessman_black_zu1,CHESSMAN_TYPE_ZU,CHESSMAN_COLOR_BLACK,0,6);
	InitChessmanBase(chessman_black_zu2,CHESSMAN_TYPE_ZU,CHESSMAN_COLOR_BLACK,2,6);
	InitChessmanBase(chessman_black_zu3,CHESSMAN_TYPE_ZU,CHESSMAN_COLOR_BLACK,4,6);
	InitChessmanBase(chessman_black_zu4,CHESSMAN_TYPE_ZU,CHESSMAN_COLOR_BLACK,6,6);
	InitChessmanBase(chessman_black_zu5,CHESSMAN_TYPE_ZU,CHESSMAN_COLOR_BLACK,8,6);
	InitChessmanBase(chessman_black_pao1,CHESSMAN_TYPE_PAO,CHESSMAN_COLOR_BLACK,1,7);
	InitChessmanBase(chessman_black_pao2,CHESSMAN_TYPE_PAO,CHESSMAN_COLOR_BLACK,7,7);
	InitChessmanBase(chessman_black_ju1,CHESSMAN_TYPE_JU,CHESSMAN_COLOR_BLACK,0,9);
	InitChessmanBase(chessman_black_ju2,CHESSMAN_TYPE_JU,CHESSMAN_COLOR_BLACK,8,9);
	InitChessmanBase(chessman_black_ma1,CHESSMAN_TYPE_MA,CHESSMAN_COLOR_BLACK,1,9);
	InitChessmanBase(chessman_black_ma2,CHESSMAN_TYPE_MA,CHESSMAN_COLOR_BLACK,7,9);
	InitChessmanBase(chessman_black_xiang1,CHESSMAN_TYPE_XIANG,CHESSMAN_COLOR_BLACK,2,9);
	InitChessmanBase(chessman_black_xiang2,CHESSMAN_TYPE_XIANG,CHESSMAN_COLOR_BLACK,6,9);
	InitChessmanBase(chessman_black_shi1,CHESSMAN_TYPE_SHI,CHESSMAN_COLOR_BLACK,3,9);
	InitChessmanBase(chessman_black_shi2,CHESSMAN_TYPE_SHI,CHESSMAN_COLOR_BLACK,5,9);
	InitChessmanBase(chessman_black_jiang,CHESSMAN_TYPE_JIANG,CHESSMAN_COLOR_BLACK,4,9);
	Update();
	return true;
}

void ChessBoard::Update()
{
	memset(map,0,sizeof(map));
	UpdateBase(chessman_red_bin1);
	UpdateBase(chessman_red_bin2);
	UpdateBase(chessman_red_bin3);
	UpdateBase(chessman_red_bin4);
	UpdateBase(chessman_red_bin5);
	UpdateBase(chessman_red_pao1);
	UpdateBase(chessman_red_pao2);
	UpdateBase(chessman_red_ju1);
	UpdateBase(chessman_red_ju2);
	UpdateBase(chessman_red_ma1);
	UpdateBase(chessman_red_ma2);
	UpdateBase(chessman_red_xiang1);
	UpdateBase(chessman_red_xiang2);
	UpdateBase(chessman_red_shi1);
	UpdateBase(chessman_red_shi2);
	UpdateBase(chessman_red_shuai);
	UpdateBase(chessman_black_zu1);
	UpdateBase(chessman_black_zu2);
	UpdateBase(chessman_black_zu3);
	UpdateBase(chessman_black_zu4);
	UpdateBase(chessman_black_zu5);
	UpdateBase(chessman_black_pao1);
	UpdateBase(chessman_black_pao2);
	UpdateBase(chessman_black_ju1);
	UpdateBase(chessman_black_ju2);
	UpdateBase(chessman_black_ma1);
	UpdateBase(chessman_black_ma2);
	UpdateBase(chessman_black_xiang1);
	UpdateBase(chessman_black_xiang2);
	UpdateBase(chessman_black_shi1);
	UpdateBase(chessman_black_shi2);
	UpdateBase(chessman_black_jiang);
}


void ChessBoard::InitChessmanBase(Chessman *&_chessman,int _Type,int _Color,int _pos_x,int _pos_y)
{
	if(_chessman != NULL)
	{
		delete _chessman;
	}
	_chessman = new Chessman(_Type,_Color,_pos_x,_pos_y);
}

void ChessBoard::UpdateBase(Chessman *_chessman)
{
	if(_chessman != NULL)
	{
		if(_chessman->alive == true)
		{
			if(map[_chessman->position_y][_chessman->position_x] == 0)
			{
				map[_chessman->position_y][_chessman->position_x] = _chessman->_type*_chessman->color;
			}
		}
	}
}


void ChessBoard::Debug_Print()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<this->map[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}

bool ChessBoard::Debug_Move(int _kx, int _ky, int _dx,int _dy)
{
	Chessman *_chessman = NULL;
	_chessman = this->GetChessmanFromABS(_kx,_ky);
	if(_chessman == NULL)
	{
		return false;
	}
	//cout<<"type:"<<_chessman->_type<<" color:"<<_chessman->color<<" x:"<<_chessman->position_x<<endl;
	if(map[_dy][_dx]*_chessman->color > 0)
	{
		return false;
	}
	if(CheakMoveRule(_chessman->_type,_kx,_ky,_dx,_dy))
	{
		if(map[_dy][_dx]*_chessman->color == 0)
		{
			//»ÚÆå¼ÇÂ¼
			if(_backRound < 2)
			{
				_backRound++;
			}
			if(_backRound == 2)
			{
				_backFlag = 1;
			}
			if(_chessman->color == 1)
			{
				_backRedA = _chessman;
				_backChessmanRedA = Chessman(*_chessman);
				_backRedB = NULL;
			}
			else if(_chessman->color == -1)
			{
				_backBlackA = _chessman;
				_backChessmanBlackA = Chessman(*_chessman);
				_backBlackB = NULL;
			}
			//»ÚÆå¼ÇÂ¼½áÊø
			_chessman->position_x = _dx;
			_chessman->position_y = _dy;
			Update();
			return true;
		}
		else if(map[_dy][_dx]*_chessman->color < 0)
		{
			//»ÚÆå¼ÇÂ¼
			if(_backRound < 2)
			{
				_backRound++;
			}
			if(_backRound == 2)
			{
				_backFlag = 2;
			}
			if(_chessman->color == 1)
			{
				_backRedA = _chessman;
				_backChessmanRedA = Chessman(*_chessman);
				_backRedB = GetChessmanFromABS(_dx,_dy);
				_backChessmanRedB = Chessman(*GetChessmanFromABS(_dx,_dy));
			}
			else if(_chessman->color == -1)
			{
				_backBlackA = _chessman;
				_backChessmanBlackA = Chessman(*_chessman);
				_backBlackB = GetChessmanFromABS(_dx,_dy);
				_backChessmanBlackB = Chessman(*GetChessmanFromABS(_dx,_dy));
			}
			//»ÚÆå¼ÇÂ¼½áÊø
			Chessman *_aimChessman = this->GetChessmanFromABS(_dx,_dy);
			_aimChessman->alive = 0;
			//ÅÐ¶ÏÊ¤¸º-Î´Íê³É
			//SetWin();
			//end
			_chessman->position_x = _dx;
			_chessman->position_y = _dy;
			Update();
			return true;
		}
	}
	return true;
}

bool ChessBoard::CheakChessmanFromMap(Chessman *_chessman, int x, int y)
{
	if(_chessman->position_x == x && _chessman->position_y == y)
	{
		return true;
	}
	return false;
}

bool ChessBoard::CheakMoveRule(int _type, int _kx, int _ky, int _dx, int _dy)
{
	if(_kx == _dx && _ky == _dy)
	{
		return false;
	}
	switch(_type)
	{
	case 1:
		if(map[_ky][_kx] == 1)
		{
			if(_ky <= 4)
			{
				if(_dy-_ky == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(_ky > 4)
			{
				if(abs(_dx + _dy - _kx - _ky) == 1 && _dy >= _ky)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{	
				return false;
			}
		}
		else if(map[_ky][_kx] == -1)
		{
			if(_ky >= 5)
			{
				if(_dy-_ky == -1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(_ky < 5)
			{
				if(abs(_dx + _dy - _kx - _ky) == 1 && _dy <= _ky)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{	
				return false;
			}
		}
		break;
	case 2:
		if(map[_dy][_dx] == 0)
		{
			if(_kx == _dx)
			{
				for(int i=min(_dy,_ky)+1;i<max(_dy,_ky);i++)
				{
					if(map[i][_kx] != 0)
					{
						return false;
					}
				}
			}
			else if(_ky == _dy)
			{
				for(int i=min(_dx,_kx)+1;i<max(_dx,_kx);i++)
				{
					if(map[_ky][i] != 0)
					{
						return false;
					}
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		else
		{
			int flag = 0;
			if(_kx == _dx)
			{
				for(int i=min(_dy,_ky)+1;i<max(_dy,_ky);i++)
				{
					if(map[i][_kx] != 0)
					{
						++flag;
					}
				}
			}
			else if(_ky == _dy)
			{
				for(int i=min(_dx,_kx)+1;i<max(_dx,_kx);i++)
				{
					if(map[_ky][i] != 0)
					{
						++flag;
					}
				}
			}
			else
			{
				return false;
			}
			if(flag == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;
	case 3:
		if(_kx == _dx)
		{
			for(int i=min(_dy,_ky)+1;i<max(_dy,_ky);i++)
			{
				if(map[i][_kx] != 0)
				{
					return false;
				}
			}
		}
		else if(_ky == _dy)
		{
			for(int i=min(_dx,_kx)+1;i<max(_dx,_kx);i++)
			{
				if(map[_ky][i] != 0)
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		return true;
		break;
	case 4:
		if(_dx-_kx == 2 && abs(_dy-_ky) == 1)
		{
			if(map[_ky][_kx+1] == 0)
			{
				return true;
			}
		}
		if(_dx-_kx == -2 && abs(_dy-_ky) == 1)
		{
			if(map[_ky][_kx-1] == 0)
			{
				return true;
			}
		}
		if(_dy-_ky == 2 && abs(_dx-_kx) == 1)
		{
			if(map[_ky+1][_kx] == 0)
			{
				return true;
			}
		}
		if(_dy-_ky == -2 && abs(_dx-_kx) == 1)
		{
			if(map[_ky-1][_kx] == 0)
			{
				return true;
			}
		}
		return false;
		break;
	case 5:
		if((_ky<=4 && _dy>4)||(_ky>4 && _dy<=4))
		{
			return false;
		}
		if(abs(_dx-_kx) == 2 && abs(_dy-_ky) == 2)
		{
			if(map[(_ky+_dy)/2][(_kx+_dx)/2] == 0)
			{
				return true;
			}
		}
		return false;
		break;
	case 6:
		if((_dx>5 || _dx<3 )||(_dy >2 && _dy<7))
		{
			return false;
		}
		if(abs(_dx-_kx) == 1 && abs(_dy-_ky) == 1)
		{
			return true;
		}
		return false;
		break;
	case 7:
		if((_dx>5 || _dx<3 )||(_dy >2 && _dy<7))
		{
			return false;
		}
		if(abs(_dx + _dy - _kx - _ky) == 1)
		{
			return true;
		}
		return false;
		break;
	}
	return false;
}

Chessman *ChessBoard::GetChessmanFromABS(int _kx, int _ky)
{
	Chessman *_chessman = NULL;
	if(map[_ky][_kx] == 0)
	{
		return false;
	}
	switch(abs(map[_ky][_kx]))
	{
	case 1:
		if(CheakChessmanFromMap(chessman_red_bin1,_kx,_ky))
		{
			_chessman = chessman_red_bin1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_bin2,_kx,_ky))
		{
			_chessman = chessman_red_bin2;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_bin3,_kx,_ky))
		{
			_chessman = chessman_red_bin3;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_bin4,_kx,_ky))
		{
			_chessman = chessman_red_bin4;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_bin5,_kx,_ky))
		{
			_chessman = chessman_red_bin5;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_zu1,_kx,_ky))
		{
			_chessman = chessman_black_zu1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_zu2,_kx,_ky))
		{
			_chessman = chessman_black_zu2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_zu3,_kx,_ky))
		{
			_chessman = chessman_black_zu3;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_zu4,_kx,_ky))
		{
			_chessman = chessman_black_zu4;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_zu5,_kx,_ky))
		{
			_chessman = chessman_black_zu5;
			break;
		}
		break;
	case 2:
		if(CheakChessmanFromMap(chessman_red_pao1,_kx,_ky))
		{
			_chessman = chessman_red_pao1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_pao2,_kx,_ky))
		{
			_chessman = chessman_red_pao2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_pao1,_kx,_ky))
		{
			_chessman = chessman_black_pao1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_pao2,_kx,_ky))
		{
			_chessman = chessman_black_pao2;
			break;
		}
		break;
	case 3:
		if(CheakChessmanFromMap(chessman_red_ju1,_kx,_ky))
		{
			_chessman = chessman_red_ju1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_ju2,_kx,_ky))
		{
			_chessman = chessman_red_ju2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_ju1,_kx,_ky))
		{
			_chessman = chessman_black_ju1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_ju2,_kx,_ky))
		{
			_chessman = chessman_black_ju2;
			break;
		}
		break;
	case 4:
		if(CheakChessmanFromMap(chessman_red_ma1,_kx,_ky))
		{
			_chessman = chessman_red_ma1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_ma2,_kx,_ky))
		{
			_chessman = chessman_red_ma2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_ma1,_kx,_ky))
		{
			_chessman = chessman_black_ma1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_ma2,_kx,_ky))
		{
			_chessman = chessman_black_ma2;
			break;
		}
		break;
	case 5:
		if(CheakChessmanFromMap(chessman_red_xiang1,_kx,_ky))
		{
			_chessman = chessman_red_xiang1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_xiang2,_kx,_ky))
		{
			_chessman = chessman_red_xiang2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_xiang1,_kx,_ky))
		{
			_chessman = chessman_black_xiang1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_xiang2,_kx,_ky))
		{
			_chessman = chessman_black_xiang2;
			break;
		}
		break;
	case 6:
		if(CheakChessmanFromMap(chessman_red_shi1,_kx,_ky))
		{
			_chessman = chessman_red_shi1;
			break;
		}
		if(CheakChessmanFromMap(chessman_red_shi2,_kx,_ky))
		{
			_chessman = chessman_red_shi2;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_shi1,_kx,_ky))
		{
			_chessman = chessman_black_shi1;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_shi2,_kx,_ky))
		{
			_chessman = chessman_black_shi2;
			break;
		}
		break;
	case 7:
		if(CheakChessmanFromMap(chessman_red_shuai,_kx,_ky))
		{
			_chessman = chessman_red_shuai;
			break;
		}
		if(CheakChessmanFromMap(chessman_black_jiang,_kx,_ky))
		{
			_chessman = chessman_black_jiang;
			break;
		}
		break;
	}
	return _chessman;
}

int ChessBoard::GetVictory()
{
	if(chessman_red_shuai->alive == 0)
	{
		return -1;
	}
	if(chessman_black_jiang->alive == 0)
	{
		return 1;
	}
	return 0;
}

//»ÚÆå
bool ChessBoard::BackChessman()
{
	if(_backFlag == 0 || _backRound < 2)
	{
		cout<<"Ê§°ÜÔ­Òò"<<_backFlag<<_backRound<<endl;
		return false;
	}
	if(_backFlag == 1 || _backFlag == 2)
	{
		if(_backRedA != NULL)
		{
			memcpy(_backRedA,&_backChessmanRedA,sizeof(_backChessmanRedA));
		}
		if(_backBlackA != NULL)
		{
			memcpy(_backBlackA,&_backChessmanBlackA,sizeof(_backChessmanBlackA));
		}
		if(_backRedB != NULL)
		{
			memcpy(_backRedB,&_backChessmanRedB,sizeof(_backChessmanRedB));
		}
		if(_backBlackB != NULL)
		{
			memcpy(_backBlackB,&_backChessmanBlackB,sizeof(_backChessmanBlackB));
		}	
		_backRedA = NULL;
		_backRedB = NULL;
		_backBlackA = NULL;
		_backBlackB = NULL;
		_backRound = 0;
		_backFlag = 0;
		Update();
		return true;
	}
	return false;
}