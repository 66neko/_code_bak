// mmm.cpp : WinMain µÄÊµÏÖ


#include "stdafx.h"
#include "resource.h"
#include "mmm_i.h"


class CmmmModule : public CAtlExeModuleT< CmmmModule >
{
public :
	DECLARE_LIBID(LIBID_mmmLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MMM, "{74FA94C4-3D8D-45AB-899E-CBB95B940FC9}")
};

CmmmModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

