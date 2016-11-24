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
		| RASEO_RemoteDefaultGateway; //ʹ��CHAP��Shiva�����������֤������ɹ���Э�����ݼ��ܣ�����ʾ���룬ʹ��Ĭ������
	rasEntry.dwfOptions2 = RASEO2_DontNegotiateMultilink; //ȡ��Ϊ����·���ö�������
	rasEntry.dwFramingProtocol = RASFP_Ppp; //��֡Э��
	rasEntry.dwVpnStrategy = VS_PptpOnly; //��PPTP���ӷ�ʽ
	rasEntry.dwfNetProtocols = RASNP_Ip; //ʹ��IPv4,IPv6Э��:| RASNP_Ipv6
	rasEntry.dwEncryptionType = ET_Optional;    //��ѡ����
	strcpy_s(rasEntry.szDeviceType, RASDT_Vpn);
	strcpy_s(rasEntry.szDeviceName, "VPN_F");
	//��ʼ��RASDIALPARAMS
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
		cout<<"vpn�����ɹ�"<<endl;
	}
	else
	{
		cout<<"vpn����ʧ��"<<endl;
		return false;
	}
	int Ret = RasDial(NULL, NULL, &rdParams, 0, NULL, &m_hRasconn);//����
	if (Ret == 0)
	{
		cout<<"���ӳɹ�"<<endl;
		return true;
	}
	else
	{
		cout<<"����ʧ��"<<endl;
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
	if (RasHangUp(m_hRasconn) == 0)//�Ͽ�
	{
		cout<<"�Ͽ��ɹ�"<<endl;
	}
	else
	{
		cout<<"�Ͽ�ʧ��"<<endl;
		return false;
	}
	if(RasDeleteEntry(NULL,name) == ERROR_SUCCESS)
	{
		cout<<"ɾ��VPN�ɹ�"<<endl;
		return true;
	}
	else
	{
		cout<<"ɾ��VPNʧ��"<<endl;
		return false;
	}
}