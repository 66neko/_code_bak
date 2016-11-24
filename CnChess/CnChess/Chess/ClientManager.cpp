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
	cout<<"��ʼ����ɣ���Ϸ��ʼ!"<<endl;
	return true;
}

void ClientManager::GameProcess()
{
	int _feedback = 0;
	while(_feedback <= 4)
	{
		char buff[100] = "";
		int kx,ky,dx,dy;
		//��ȡ����״̬
		if(_clientSocket.GetPlayerState() == 0)
		{
			_sharing._state = 2;
			cout<<"���ѵ��ߣ���"<<endl;
			break;
		}
		//end
		_clientSocket.RecvMessage(buff);
		cout<<"�յ�ͬ�����ݣ�"<<endl;
		_clientSocket.TranslateRecvServerToClient(buff,_chessboard.map,&_player,&_state,&_feedback);
		_clientSocket.TranslateRecvServerToClient(buff,_sharing.map,&_sharing._player,&_sharing._state,&_sharing._feedback);
		if(_player == _myColor)
		{
			if(_feedback == 5 || _feedback == 6)
			{
				break;
			}
			flag_1:cout<<"�ҷ����壬��������ָ��"<<endl;
			if(_clientSocket.GetPlayerState() == 0)
			{
				cout<<"���ѵ��ߣ���"<<endl;
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
					cout<<"����ʧ�ܣ�"<<endl;
				}
				else
				{
					cout<<"��Чָ�"<<endl;
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
		cout<<"��Ϸ�������췽ʤ��/�ڷ���Ȩ��"<<endl;
	}
	if(_feedback == 6)
	{
		cout<<"��Ϸ�������ڷ�ʤ��/�췽��Ȩ��"<<endl;
	}
	_clientSocket.CloseSocket();
}