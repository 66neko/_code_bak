#include "GameManager.h"

GameManager::GameManager()
{
	this->_chessboard = ChessBoard();
	_player = 1;
	_state = 0;
}

GameManager::~GameManager()
{
}

void GameManager::SwitchPlayer()
{
	_player *= -1;
	return;
}

bool GameManager::PlayingChess(int _kx, int _ky, int _dx, int _dy)
{
	//���_kx>=10(�������̷�Χ������Ϊ����pass)
	if(_kx >= 10)
	{
		this->SwitchPlayer();
		cout<<"pass~"<<endl;
		return true;
	}
	//��_kx<0�����(back).
	if(_kx < 0)
	{
		if(_chessboard.BackChessman())
		{
			cout<<"����ɹ�"<<endl;
			return true;
		}
		else
		{
			cout<<"����ʧ��"<<endl;
			return false;
		}
	}
	if(this->_chessboard.map[_ky][_kx]*_player > 0)
	{
		if(_chessboard.Debug_Move(_kx,_ky,_dx,_dy))
		{
			cout<<"����ɹ���"<<endl;
			if(_chessboard.GetVictory() != 0)
			{
				if(_chessboard.GetVictory() == 1)
				{
					cout<<"�췽ʤ������Ϸ����"<<endl;
					_state = 0;
				}
				else if(_chessboard.GetVictory() == -1)
				{
					cout<<"�ڷ�ʤ������Ϸ����"<<endl;
					_state = 0;
				}
				else
				{
					cout<<"�������󣬳������"<<endl;
					exit(1);
				}
			}
			else
			{
				cout<<"Debug-ʤ��δ��,��Ϸ����"<<endl;
			}
			SwitchPlayer();
			return true;
		}
		else
		{
			cout<<"����ʧ��~"<<endl;
			return false;
		}
	}
	else
	{
		cout<<"����ʧ��~"<<endl;
		return false;
	}
}

bool GameManager::GetGameState()
{
	if(_state == 0)
	{
		return false;
	}
	if(_player > 0)
	{
		cout<<"�����Ǻ�ɫ����"<<endl;
		return true;
	}
	else
	{
		cout<<"�����Ǻ�ɫ����"<<endl;
		return true;
	}
}

void GameManager::GameBegin(u_short _port)
{
	this->_chessboard = ChessBoard();
	_netManager = InternetManager();
	_state = 1;
	//�������
	_netManager.Init(_port);
	_netManager.Listen();
	_netManager.AcceptRedAndBlack();
	_netManager.SendMessageRed("���Ǻ�ɫ");
	_netManager.SendMessageBlack("���Ǻ�ɫ");
	//��һ��ͬ������
	char buff[100] = "";
	_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,0);
	_netManager.SendMessageRed(buff);
	_netManager.SendMessageBlack(buff);
	//ͬ������
	cout<<"��ʼ����ɣ���Ϸ��ʼ!"<<endl;
	return;
}

void GameManager::GameProcess()
{
	while(_chessboard.GetVictory() == 0)
	{
		_chessboard.Debug_Print();
		char buff[100] = "";
		int kx,ky,dx,dy;
		//����ָ������
		int _feedback = 0;
		//��ȡ����״̬
		switch(_netManager.GetPlayerState())
		{
		case 0:
			break;
		case 1:
			cout<<"��ɫ��������ߣ�"<<endl;
			_feedback = 6;
			_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
			_netManager.SendMessageBlack(buff);
			return;
			break;
		case 2:
			cout<<"��ɫ��������ߣ�"<<endl;
			_feedback = 5;
			_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
			_netManager.SendMessageRed(buff);
			return;
			break;
		case 3:
			cout<<"��ɫ�ͺ�ɫ��������ߣ�"<<endl;
			return;
			break;
		}
		//end
		if(_player == 1)
		{
			_netManager.RecvMessageFormRed(buff);
			_netManager.TranslateRecvClientToServer(buff,&kx,&ky,&dx,&dy);
			if(PlayingChess(kx,ky,dx,dy))
			{
				char buff[100] = "";
				if(kx < 0)
				{
					_feedback = 3;
				}
				else if(kx >= 10)
				{
					_feedback = 4;
				}
				else
				{
					if(_state == 1)
					{
						_feedback = 1;
					}
					else
					{
						if(_chessboard.GetVictory() == 1)
						{
							_feedback = 5;
						}
						if(_chessboard.GetVictory() == -1)
						{
							_feedback = 6;
						}
					}
				}
				_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
				_netManager.SendMessageRed(buff);
				_netManager.SendMessageRed(buff);
				_netManager.SendMessageBlack(buff);
			}
			else
			{
				if(kx < 0)
				{
					_feedback = 2;
				}
				else
				{
					_feedback = 0;
				}
				_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
				_netManager.SendMessageRed(buff);
			}
		}
		else
		{
			_netManager.RecvMessageFormBlack(buff);
			_netManager.TranslateRecvClientToServer(buff,&kx,&ky,&dx,&dy);
			if(PlayingChess(kx,ky,dx,dy))
			{
				char buff[100] = "";
				if(kx < 0)
				{
					_feedback = 3;
				}
				else if(kx >= 10)
				{
					_feedback = 4;
				}
				else
				{
					if(_state == 1)
					{
						_feedback = 1;
					}
					else
					{
						if(_chessboard.GetVictory() == 1)
						{
							_feedback = 5;
						}
						if(_chessboard.GetVictory() == -1)
						{
							_feedback = 6;
						}
					}
				}
				_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
				_netManager.SendMessageRed(buff);
				_netManager.SendMessageBlack(buff);
				_netManager.SendMessageBlack(buff);
			}
			else
			{
				if(kx < 0)
				{
					_feedback = 2;
				}
				else
				{
					_feedback = 0;
				}
				_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
				_netManager.SendMessageBlack(buff);
			}
		}
	}
	cout<<"ʤ���ѷ֣���Ϸ������"<<endl;
}