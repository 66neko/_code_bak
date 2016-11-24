#include <Winsock2.h>
#include <stdio.h>

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
	SOCKET sockclient = socket(AF_INET,SOCK_STREAM,0);

	SOCKADDR_IN addrsrv,addr;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6001);
	addrsrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrsrv.sin_family = AF_INET;
	addrsrv.sin_port = htons(6666);
	if(connect(sockclient,(SOCKADDR*)&addrsrv,sizeof(SOCKADDR)) == -1);
	{
		printf("连接失败！\n");
	}
	//char name = '6';
	char *name = "我不是周卓";
	char recvbuf[100];
	recv(sockclient,recvbuf,100,0);
	printf("%s\n",recvbuf);
	send(sockclient,name,strlen(name)+1,0);
	/*
	sockclient = socket(AF_INET,SOCK_DGRAM,0);
	bind(sockclient,(sockaddr*)&addr,sizeof(sockaddr));
	sendto(sockclient,"123",strlen("123"),0,(sockaddr*)&addrsrv,sizeof(sockaddr));
	int len = sizeof(sockaddr);
	char buf[200];
	recvfrom(sockclient,buf,200,0,(sockaddr*)&addrsrv,&len);
	printf("%s\n",buf);
	*/
	closesocket(sockclient);
	system("pause");
}