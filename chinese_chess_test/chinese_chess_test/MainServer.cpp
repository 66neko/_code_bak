#include"MainServer.h"

MainServer::MainServer()
{
	this->_maxThread = MAXTHREAD;
	while(!_portQueue.empty())
	{
		_portQueue.pop();
	}
	u_short maxMaxThread = MAXTHREAD + 5;
	for(u_short i=0;i<maxMaxThread;i++)
	{
		_portQueue.push(7000+i);
	}
}

MainServer::~MainServer()
{
}

void MainServer::OnStart()
{
	Init(6666);
	Listen();
	AcceptPlayer();
}

void MainServer::AcceptPlayer()
{
	while(1)
	{
		int len = sizeof(SOCKADDR);
		printf("等待玩家匹配...~\n");
		SOCKADDR_IN addrA;
		SOCKET socketPlayA = accept(sockets,(SOCKADDR*)&addrA,&len);
		char nameA[20] = "";
		if(recv(socketPlayA,nameA,20,0) <= 0)
		{
			closesocket(socketPlayA);
			continue;
		}
		printf("玩家1:%s已就位\n",nameA);
		SOCKADDR_IN addrB;
		SOCKET socketPlayB = accept(sockets,(SOCKADDR*)&addrB,&len);
		char nameB[20] = "";
		if(recv(socketPlayB,nameB,20,0) <= 0)
		{
			closesocket(socketPlayA);
			closesocket(socketPlayB);
			continue;
		}
		printf("玩家2:%s已就位\n",nameB);
		char sendbuffA[30] = "";
		char sendbuffB[30] = "";
		srand((unsigned int)time(0));
		if(rand()%2 == 0)
		{
			sendbuffA[0] = 'R';
			sendbuffB[0] = 'B';
		}
		else
		{
			sendbuffA[0] = 'B';
			sendbuffB[0] = 'R';
		}
		while(_portQueue.empty())
		{
			Sleep(1000);
		}
		u_short port = _portQueue.front();
		_portQueue.pop();
		_itoa_s((int)port,&sendbuffA[1],5,10);
		_itoa_s((int)port,&sendbuffB[1],5,10);
		strcat_s(sendbuffA,30,nameB);
		strcat_s(sendbuffB,30,nameA);
		if(send(socketPlayB,sendbuffB,strlen(sendbuffB)+1,0) == SOCKET_ERROR)
		{
			closesocket(socketPlayA);
			closesocket(socketPlayB);
			continue;
		}
		if(send(socketPlayA,sendbuffA,strlen(sendbuffA)+1,0) == SOCKET_ERROR)
		{
			closesocket(socketPlayA);
			closesocket(socketPlayB);
			continue;
		}
		
		ThreadPara _threadPara;
		_threadPara.port = port;
		_threadPara._mainServer = this;
		_beginthread(Thread_game,0,(void*)&_threadPara);
		closesocket(socketPlayA);
		closesocket(socketPlayB);
		cout<<"本局游戏已启动，等下一次匹配~"<<endl;
	}
}

void MainServer::Thread_game(void *para)
{
	ThreadPara _threadPara = *(ThreadPara*)para;
	GameManager _game;
	_game.GameBegin(_threadPara.port);
	_game.GameProcess();
	_threadPara._mainServer->_portQueue.push(_threadPara.port);
	return;
}