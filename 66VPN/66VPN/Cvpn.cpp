#include "stdafx.h"
#include "Cvpn.h"
Cvpn::Cvpn(char _name[])
{
	memset(name,0,sizeof(name));
	strcpy(name,_name);
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
	strcpy_s(rasEntry.szDeviceType, RASDT_Vpn);
	strcpy_s(rasEntry.szDeviceName, "VPN_F");
	//初始化RASDIALPARAMS
	memset(&rdParams,0,sizeof(RASDIALPARAMS));
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	//
	lpProjection = new RASPPPIP;
	lpProjection->dwSize = sizeof(RASPPPIP);
	//
	m_hRasconn = NULL;
}
bool Cvpn::Connect(char *_uid, char *_psw, char *_ip)
{
	strcpy_s(rasEntry.szLocalPhoneNumber, _ip);
	int dwResult = RasSetEntryProperties(NULL, name , &rasEntry, sizeof(rasEntry), NULL, 0);
	if (dwResult != 0)
	{
		::AfxMessageBox("error : SetEntryProperties");
		return false;
	}
	strcpy_s(rdParams.szEntryName,name);
	strcpy_s(rdParams.szUserName,_uid);
	strcpy_s(rdParams.szPassword,_psw);
	DWORD dwRet = RasSetEntryDialParams(NULL, &rdParams, FALSE);

	if(dwRet == 0)
	{
		cout<<"vpn创建成功"<<endl;
	}
	else
	{
		cout<<"vpn创建失败"<<endl;
		return false;
	}
	int Ret = RasDial(NULL, NULL, &rdParams, 0, NULL, &m_hRasconn);//拨号
	if (Ret == 0)
	{
		cout<<"连接成功"<<endl;
		return true;
	}
	else
	{
		cout<<"连接失败"<<endl;
		return false;
	}
}
bool Cvpn::GetIP(char *_ip)
{
	DWORD c = sizeof(RASPPPIP);
	int RetPro = RasGetProjectionInfo(m_hRasconn,RASP_PppIp,lpProjection,&c);
	if (RetPro == 0)
	{
		memset(_ip,0,sizeof(_ip));
		strcpy(_ip,lpProjection->szIpAddress);
		return true;
	}
	else
	{
		return false;
	}
}
bool Cvpn::Close()
{
	if (RasHangUp(m_hRasconn) == 0)//断开
	{
		cout<<"断开成功"<<endl;
	}
	else
	{
		cout<<"断开失败"<<endl;
		return false;
	}
	if(RasDeleteEntry(NULL,name) == ERROR_SUCCESS)
	{
		cout<<"删除VPN成功"<<endl;
		return true;
	}
	else
	{
		cout<<"删除VPN失败"<<endl;
		return false;
	}
}