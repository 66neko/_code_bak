#include "InternetManager.h"

InternetManager::InternetManager()
{
	memset(&sockets,0,sizeof(sockets));
	memset(&addrClientRed,0,sizeof(addrClientRed));
	memset(&socketClientRed,0,sizeof(socketClientRed));
	memset(&addrClientBlack,0,sizeof(addrClientBlack));
	memset(&socketClientBlack,0,sizeof(socketClientBlack));
	_redOnline = 0;
	_blackOnline = 0;
}

InternetManager::~InternetManager()
{

}

bool InternetManager::Init(u_short _port)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 1, 1 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {

		return false;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
		HIBYTE( wsaData.wVersion ) != 1 ) {
			WSACleanup( );
			return false; 
	}
	sockets = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrsrv;
	addrsrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(_port);

	bind(sockets,(sockaddr*)&addrsrv,sizeof(SOCKADDR));

	return true;
}

void InternetManager::Listen()
{
	if (listen(sockets,5) == SOCKET_ERROR)
	{
		printf("listen error!");
		return;
	}
	
	return;
}

void InternetManager::SendMessage(SOCKET *_socket,char *sendbuff)
{
	if(send(*_socket,sendbuff,strlen(sendbuff)+1,0) == SOCKET_ERROR)
	{
		CloseSocket(_socket);
	}
}

void InternetManager::RecvMessage(SOCKET *_socket,char *recvbuff)
{
	if(recv(*_socket,recvbuff,100,0) == 0)
	{
		CloseSocket(_socket);
	}
}

bool InternetManager::Accept(SOCKET *_socket,SOCKADDR_IN *_addr)
{
	int len = sizeof(SOCKADDR);
	printf("等待连接...~\n");
	*_socket = accept(sockets,(SOCKADDR*)_addr,&len);
	printf("接收到一个连接\n");
	return true;
}

void InternetManager::CloseSocket(SOCKET *_socket)
{
	if(_socket == &socketClientRed)
	{
		this->_redOnline = 0;
	}
	if(_socket == &socketClientBlack)
	{
		this->_blackOnline = 0;
	}

	closesocket(*_socket);
	printf("结束连接\n");
}

void InternetManager::AcceptRedAndBlack()
{
	char buff[100] = "";
	while(1)
	{
		this->CloseSocket(&socketClientRed);
		this->Accept(&socketClientRed,&addrClientRed);
		RecvMessage(&socketClientRed,buff);
		if(buff[0] == 'R')
		{
			break;
		}
		//连接失败验证
		SendMessageRed("F");
	}
	cout<<"红色连接成功"<<endl;
	this->_redOnline = 1;
	while(1)
	{
		this->CloseSocket(&socketClientBlack);
		this->Accept(&socketClientBlack,&addrClientBlack);
		RecvMessage(&socketClientBlack,buff);
		if(buff[0] == 'B')
		{
			break;
		}
		//连接失败验证
		SendMessageBlack("F");
	}
	cout<<"黑色连接成功"<<endl;
	this->_blackOnline = 1;
	return;
}

void InternetManager::SendMessageRed(char *sendbuff)
{
	this->SendMessage(&socketClientRed,sendbuff);
	return;
}

void InternetManager::SendMessageBlack(char *sendbuff)
{
	this->SendMessage(&socketClientBlack,sendbuff);
	return;
}

void InternetManager::RecvMessageFormRed(char *recvbuff)
{
	this->RecvMessage(&socketClientRed,recvbuff);
	return;
}

void InternetManager::RecvMessageFormBlack(char *recvbuff)
{
	this->RecvMessage(&socketClientBlack,recvbuff);
	return;
}

bool InternetManager::TranslateRecvClientToServer(char *str,int *_kx,int *_ky,int *_dx,int * _dy)
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

bool InternetManager::TranslateSendServerToClient(char *str, int map[][9], int _player, int _state, int _feedback)
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

bool InternetManager::TranslateSendClientToServer(char *str,int _kx,int _ky,int _dx,int _dy)
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

bool InternetManager::TranslateRecvServerToClient(char *str,int map[][9],int *_player,int *_state,int *_feedback)
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

int InternetManager::GetPlayerState()
{
	if(_redOnline+_blackOnline == 0)
	{
		return 3;
	}
	if(_redOnline == 0)
	{
		return 1;
	}
	if(_blackOnline == 0)
	{
		return 2;
	}
	return 0;
}