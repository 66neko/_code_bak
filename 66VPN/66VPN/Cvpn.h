#pragma once
using namespace std;

class Cvpn
{
public:
	Cvpn(char _name[] = "66VPN¼ÓËÙÆ÷");
	~Cvpn(){}
	bool Connect(char *_uid,char *_psw,char *_ip);
	bool Close();
	bool GetIP(char* _ip);
private:
	char name[20];
	RASENTRY rasEntry;
	RASDIALPARAMS rdParams;
	HRASCONN m_hRasconn;
	RASPPPIP *lpProjection;
};