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
	//如果_kx>=10(超过棋盘范围，则定义为跳过pass)
	if(_kx >= 10)
	{
		this->SwitchPlayer();
		cout<<"pass~"<<endl;
		return true;
	}
	//若_kx<0则悔棋(back).
	if(_kx < 0)
	{
		if(_chessboard.BackChessman())
		{
			cout<<"悔棋成功"<<endl;
			return true;
		}
		else
		{
			cout<<"悔棋失败"<<endl;
			return false;
		}
	}
	if(this->_chessboard.map[_ky][_kx]*_player > 0)
	{
		if(_chessboard.Debug_Move(_kx,_ky,_dx,_dy))
		{
			cout<<"走棋成功！"<<endl;
			if(_chessboard.GetVictory() != 0)
			{
				if(_chessboard.GetVictory() == 1)
				{
					cout<<"红方胜利，游戏结束"<<endl;
					_state = 0;
				}
				else if(_chessboard.GetVictory() == -1)
				{
					cout<<"黑方胜利，游戏结束"<<endl;
					_state = 0;
				}
				else
				{
					cout<<"发生错误，程序结束"<<endl;
					exit(1);
				}
			}
			else
			{
				cout<<"Debug-胜负未分,游戏继续"<<endl;
			}
			SwitchPlayer();
			return true;
		}
		else
		{
			cout<<"走棋失败~"<<endl;
			return false;
		}
	}
	else
	{
		cout<<"走棋失败~"<<endl;
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
		cout<<"现在是红色走棋"<<endl;
		return true;
	}
	else
	{
		cout<<"现在是黑色走棋"<<endl;
		return true;
	}
}

void GameManager::GameBegin(u_short _port)
{
	this->_chessboard = ChessBoard();
	_netManager = InternetManager();
	_state = 1;
	//连接玩家
	_netManager.Init(_port);
	_netManager.Listen();
	_netManager.AcceptRedAndBlack();
	_netManager.SendMessageRed("你是红色");
	_netManager.SendMessageBlack("你是黑色");
	//第一次同步数据
	char buff[100] = "";
	_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,0);
	_netManager.SendMessageRed(buff);
	_netManager.SendMessageBlack(buff);
	//同步结束
	cout<<"初始化完成，游戏开始!"<<endl;
	return;
}

void GameManager::GameProcess()
{
	while(_chessboard.GetVictory() == 0)
	{
		_chessboard.Debug_Print();
		char buff[100] = "";
		int kx,ky,dx,dy;
		//反馈指令设置
		int _feedback = 0;
		//获取在线状态
		switch(_netManager.GetPlayerState())
		{
		case 0:
			break;
		case 1:
			cout<<"红色玩家已离线！"<<endl;
			_feedback = 6;
			_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
			_netManager.SendMessageBlack(buff);
			return;
			break;
		case 2:
			cout<<"黑色玩家已离线！"<<endl;
			_feedback = 5;
			_netManager.TranslateSendServerToClient(buff,_chessboard.map,_player,_state,_feedback);
			_netManager.SendMessageRed(buff);
			return;
			break;
		case 3:
			cout<<"红色和黑色玩家已离线！"<<endl;
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
	cout<<"胜负已分，游戏结束！"<<endl;
}