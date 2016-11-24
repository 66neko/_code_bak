#include "stdafx.h"
#include"ClientSocket.h"

ClientSocket::ClientSocket()
{
	memset(&socketclient,0,sizeof(socketclient));
	_online = 0;
}

ClientSocket::~ClientSocket()
{
}

void ClientSocket::Init(u_short _port)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 1, 1 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {

		return;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
		HIBYTE( wsaData.wVersion ) != 1 ) {
			WSACleanup( );
			return; 
	}
	socketclient = socket(AF_INET,SOCK_STREAM,0);
	addrsrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(_port);
}

bool ClientSocket::Connect(char *_color)
{
	if(connect(socketclient,(SOCKADDR*)&addrsrv,sizeof(SOCKADDR)) == -1)
	{
		printf("Á¬½ÓÊ§°Ü£¡\n");
		return false;
	}
	char recvbuf[100] = "error!";
	send(socketclient,_color,2,0);
	recv(socketclient,recvbuf,100,0);
	if(recvbuf[0] == 'F')
	{
		return false;
	}
	printf("%s\n",recvbuf);
	this->_online = 1;
	return true;
}

bool ClientSocket::TranslateRecvClientToServer(char *str,int *_kx,int *_ky,int *_dx,int * _dy)
{
	if(strlen(str) != 4)
	{
		return false;
	}
	if(str[0] == 'A')
	{
		*_kx = -1;
	}
	else if(str[0] == 'B')
	{
		*_kx = 10;
	}
	else
	{
		*_kx = str[0] - 48;
	}
	*_ky = str[1] - 48;
	*_dx = str[2] - 48;
	*_dy = str[3] - 48;
	return true;
}

bool ClientSocket::TranslateSendServerToClient(char *str, int map[][9], int _player, int _state, int _feedback)
{
	int p = 0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(map[i][j] >= 0)
			{
				str[p] = map[i][j] + 48;
				p++;
			}
			else
			{
				str[p] = map[i][j] + 72;
				p++;
			}
		}
	}
	if(_player > 0)
	{
		str[p] = 'R';
		p++;
	}
	else
	{
		str[p] = 'B';
		p++;
	}
	str[p] = _state + 48;
	p++;
	str[p] = _feedback + 48;
	p++;
	str[p] = '\0';
	if(strlen(str) == 93)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ClientSocket::TranslateSendClientToServer(char *str,int _kx,int _ky,int _dx,int _dy)
{
	int p = 0;
	if(_kx >= 10)
	{
		str[p] = 'B';
		p++;
	}
	else if(_kx < 0)
	{
		str[p] = 'A';
		p++;
	}
	else
	{
		str[p] = _kx + 48;
		p++;
	}
	str[p] = _ky + 48;
	p++;
	str[p] = _dx + 48;
	p++;
	str[p] = _dy + 48;
	p++;
	str[p] = '\0';
	if(strlen(str) == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ClientSocket::TranslateRecvServerToClient(char *str,int map[][9],int *_player,int *_state,int *_feedback)
{
	if(strlen(str) != 93)
	{
		return false;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(str[9*i+j] < 58)
			{
				map[i][j] = str[9*i+j] - 48;
			}
			else
			{
				map[i][j] = str[9*i+j] - 72;
			}
		}
	}
	if(str[90] == 'R')
	{
		*_player = 1;
	}
	else
	{
		*_player = -1;
	}
	*_state = str[91] - 48;
	*_feedback = str[92] - 48;
	return true;
}

void ClientSocket::CloseSocket()
{
	closesocket(socketclient);
}

void ClientSocket::SendMessage(char *sendbuff)
{
	if(send(socketclient,sendbuff,strlen(sendbuff)+1,0) == SOCKET_ERROR)
	{
		this->_online = 0;
		CloseSocket();
	}
}

void ClientSocket::RecvMessage(char *recvbuff)
{
	if(recv(socketclient,recvbuff,100,0) <= 0)
	{
		this->_online = 0;
		CloseSocket();
	}
}

int ClientSocket::GetPlayerState()
{
	if(this->_online == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}