#define WINVER 0x0501
#include<iostream>
#include<windows.h>
#include<ras.h>
#include<string>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
typedef struct tagIPInfo
{
	char ip[30];
}IPInfo;

bool GetLocalIPs(IPInfo* ips,int maxCnt,int* cnt)
{
	//1.初始化wsa
	WSADATA wsaData;
	int ret=WSAStartup(MAKEWORD(2,2),&wsaData);
	if (ret!=0)
	{
		return false;
	}
	//2.获取主机名
	char hostname[256];
	ret=gethostname(hostname,sizeof(hostname));
	if (ret==SOCKET_ERROR)
	{
		return false;
	}
	//3.获取主机ip
	HOSTENT* host=gethostbyname(hostname);
	if (host==NULL)
	{
		return false;
	}
	//4.逐个转化为char*并拷贝返回
	*cnt=host->h_length<maxCnt?host->h_length:maxCnt;
	for (int i=0;i<*cnt;i++)
	{
		in_addr* addr=(in_addr*)*host->h_addr_list;
		strcpy(ips[i].ip,inet_ntoa(addr[i]));
	}
	return true;
}
int main()
{
	//test
	IPInfo ipinfo[10];
	int cnt;
	if(GetLocalIPs(ipinfo,10,&cnt))
	{
		cout<<"拨号IP:"<<ipinfo[1].ip<<endl;
	}
	//end
	
	char uid[20],psw[20];
	memset(&uid,0,sizeof(uid));
	memset(&psw,0,sizeof(psw));
	cout<<"输入用户名和密码"<<endl<<"用户名:";
	cin>>uid;
	cout<<"密码:";
	cin>>psw;
	RASENTRY rasEntry;
	memset(&rasEntry,0,sizeof(RASENTRY));
	rasEntry.dwSize = sizeof(rasEntry);
	rasEntry.dwCountryCode = 86;
	rasEntry.dwCountryID = 86;
	rasEntry.dwDialExtraPercent = 75;
	rasEntry.dwDialExtraSampleSeconds = 120;
	rasEntry.dwDialMode = RASEDM_DialAll;
	rasEntry.dwType = RASET_Vpn; //VPN
	rasEntry.dwRedialCount = 30;
	rasEntry.dwRedialPause = 60;
	rasEntry.dwSize = sizeof(rasEntry);
	rasEntry.dwfOptions = RASEO_RequireEncryptedPw | RASEO_RequireDataEncryption | RASEO_PreviewUserPw 
		| RASEO_RemoteDefaultGateway; //使用CHAP和Shiva的密码身份验证，必须成功的协商数据加密，不显示密码，使用默认网关
	rasEntry.dwfOptions2 = RASEO2_DontNegotiateMultilink; //取消为单链路设置多重连接
	rasEntry.dwFramingProtocol = RASFP_Ppp; //分帧协议
	rasEntry.dwVpnStrategy = VS_PptpOnly; //仅PPTP连接方式
	rasEntry.dwfNetProtocols = RASNP_Ip; //使用IPv4,IPv6协议:| RASNP_Ipv6
	rasEntry.dwEncryptionType = ET_Optional;    //可选加密
	strcpy_s(rasEntry.szLocalPhoneNumber, "118.193.178.3");
	strcpy_s(rasEntry.szDeviceType, RASDT_Vpn);
	strcpy_s(rasEntry.szDeviceName, "VPN_FUCK");
	int dwResult = RasSetEntryProperties(NULL, "VPNforROBO", &rasEntry, sizeof(rasEntry), NULL, 0);
	if (dwResult != 0)
	{
		cout<<"error : SetEntryProperties"<<endl;
		return false;
	}
	RASDIALPARAMS rdParams;
	memset(&rdParams,0,sizeof(RASDIALPARAMS));
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	strcpy_s(rdParams.szEntryName,"VPNforROBO");
	strcpy_s(rdParams.szUserName,uid);
	strcpy_s(rdParams.szPassword,psw);
	DWORD dwRet = RasSetEntryDialParams(NULL, &rdParams, FALSE);

	if(dwRet == 0)
	{
		cout<<"vpn创建成功"<<endl;
	}
	else
	{
		cout<<"vpn创建失败"<<endl;
	}
	memset(&rdParams,0,sizeof(RASDIALPARAMS));
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	strcpy_s(rdParams.szEntryName,"VPNforROBO");
	strcpy_s(rdParams.szPhoneNumber, "118.193.178.3");
	strcpy_s(rdParams.szUserName,uid);
	strcpy_s(rdParams.szPassword,psw);
	HRASCONN m_hRasconn = NULL;
	int Ret = RasDial(NULL, NULL, &rdParams, 0, NULL, &m_hRasconn);//拨号
	if (Ret == 0)
	{
		cout<<"连接成功"<<endl;
	}
	else
	{
		cout<<"连接失败"<<endl;
	}
	//获取连接信息
	RASPPPIP *lpProjection = new RASPPPIP;
	lpProjection->dwSize = sizeof(RASPPPIP);
	DWORD c = sizeof(RASPPPIP);
	int RetPro = RasGetProjectionInfo(m_hRasconn,RASP_PppIp,lpProjection,&c);
	if (RetPro == 0)
		cout<<"本地ip"<<lpProjection->szIpAddress<<endl;
	cout<<"服务器ip"<<lpProjection->szServerIpAddress<<endl;
	//改变路由表
	
	string str[11];
	//route add 109.0.0.0 mask 255.0.0.0 192.168.6.9 metric 2
	str[1] = "route add 58.20.222.178 mask 255.255.255.255 ";
	str[2] = "route add 23.0.0.0 mask 255.0.0.0 ";
	str[3] = "route add 50.0.0.0 mask 255.0.0.0 ";
	str[4] = "route add 54.0.0.0 mask 255.0.0.0 ";
	str[5] = "route add 98.0.0.0 mask 255.0.0.0 ";
	str[6] = "route add 174.0.0.0 mask 255.0.0.0 ";
	str[7] = "route add 107.0.0.0 mask 255.0.0.0 ";
	str[8] = "route add 78.0.0.0 mask 255.0.0.0 ";
	str[9] = "route add 88.0.0.0 mask 255.0.0.0 ";
	str[10] = "route add 199.0.0.0 mask 255.0.0.0 ";
	for (int i=1;i<=1;i++)
	{
		str[i] += ipinfo[1].ip;
		str[i] += " metric 2";
		cout<<str[i]<<endl;
		system(str[i].c_str());
	}
	cout<<"路由表添加完成"<<endl;
	//
	
	cout<<"按任意键断开连接"<<endl;
	system("pause");
	//
	if (RasHangUp(m_hRasconn) == 0)//断开
	{
		cout<<"断开成功"<<endl;
		system("route delete 58.20.222.178");
	}
	else
	{
		cout<<"断开失败"<<endl;
	}
	if(RasDeleteEntry(NULL,"VPNforROBO") == ERROR_SUCCESS)
	{
		cout<<"删除VPN成功"<<endl;
	}
	else
	{
		cout<<"删除VPN失败"<<endl;
	}
	system("pause");
}
