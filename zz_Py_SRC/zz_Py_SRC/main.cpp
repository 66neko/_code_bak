#include <Winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

void main()
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
	SOCKET sockets = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrsrv;
	addrsrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(6666);
	
	bind(sockets,(sockaddr*)&addrsrv,sizeof(SOCKADDR));
	
	if (listen(sockets,5) == SOCKET_ERROR)
	{
		printf("listen error!");
		return;
	}

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	printf("Start~\n");
	while(true)
	{
		printf("等待连接...~\n");
		SOCKET sockcoen = accept(sockets,(SOCKADDR*)&addrClient,&len);
		printf("接受到一个连接\n");
		char sendbuf[100];
		sprintf(sendbuf,"%s",inet_ntoa(addrClient.sin_addr));
		send(sockcoen,sendbuf,strlen(sendbuf)+1,0);
		printf("返回IP地址%s\n",inet_ntoa(addrClient.sin_addr));
		char recvbuf[100];
		recv(sockcoen,recvbuf,100,0);
		printf("%s\n",recvbuf);
		closesocket(sockcoen);
	}
}