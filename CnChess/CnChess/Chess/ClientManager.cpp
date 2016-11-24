#include "stdafx.h"
#include"ClientManager.h"

ClientManager::ClientManager()
{
	_chessboard = ChessBoard();
	_player = 1;
	_state = 0;
	_myColor = 0;
	_clientSocket = ClientSocket();
}

ClientManager::~ClientManager()
{
}

bool ClientManager::Start(char *color,u_short _port)
{
	_clientSocket = ClientSocket();
	_clientSocket.Init(_port);
	if (!_clientSocket.Connect(color))
	{
		return false;
	}
	if(color[0] == 'R')
	{
		this->_myColor = 1;
	}
	if(color[0] == 'B')
	{
		this->_myColor = -1;
	}
	cout<<"初始化完成，游戏开始!"<<endl;
	return true;
}

void ClientManager::GameProcess()
{
	int _feedback = 0;
	while(_feedback <= 4)
	{
		char buff[100] = "";
		int kx,ky,dx,dy;
		//获取在线状态
		if(_clientSocket.GetPlayerState() == 0)
		{
			_sharing._state = 2;
			cout<<"你已掉线！！"<<endl;
			break;
		}
		//end
		_clientSocket.RecvMessage(buff);
		cout<<"收到同步数据！"<<endl;
		_clientSocket.TranslateRecvServerToClient(buff,_chessboard.map,&_player,&_state,&_feedback);
		_clientSocket.TranslateRecvServerToClient(buff,_sharing.map,&_sharing._player,&_sharing._state,&_sharing._feedback);
		if(_player == _myColor)
		{
			if(_feedback == 5 || _feedback == 6)
			{
				break;
			}
			flag_1:cout<<"我方下棋，输入下棋指令"<<endl;
			if(_clientSocket.GetPlayerState() == 0)
			{
				cout<<"你已掉线！！"<<endl;
				break;
			}
			//cin>>kx>>ky>>dx>>dy;
			//MessageBox(0,"11111",0,0);
			while(_sharing._doneChess != 1)
			{
				Sleep(100);
			}
			_sharing._doneChess = 0;
			kx = _sharing.kx;
			ky = _sharing.ky;
			dx = _sharing.dx;
			dy = _sharing.dy;
			_clientSocket.TranslateSendClientToServer(buff,kx,ky,dx,dy);
			_clientSocket.SendMessage(buff);
			_clientSocket.RecvMessage(buff);
			_clientSocket.TranslateRecvServerToClient(buff,_chessboard.map,&_player,&_state,&_feedback);
			_clientSocket.TranslateRecvServerToClient(buff,_sharing.map,&_sharing._player,&_sharing._state,&_sharing._feedback);
			//
			//
			if (_feedback == 0 || _feedback == 2)
			{
				if(_feedback == 2)
				{
					cout<<"悔棋失败！"<<endl;
				}
				else
				{
					cout<<"无效指令！"<<endl;
				}
				goto flag_1;
			}
			else if(_feedback == 1 || _feedback == 3 || _feedback == 4)
			{
				continue;
			}
			else if(_feedback == 5 || _feedback == 6)
			{
				break;
			}
		}
	}
	if(_feedback == 5)
	{
		cout<<"游戏结束，红方胜利/黑方弃权！"<<endl;
	}
	if(_feedback == 6)
	{
		cout<<"游戏结束，黑方胜利/红方弃权！"<<endl;
	}
	_clientSocket.CloseSocket();
}