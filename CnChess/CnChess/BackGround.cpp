#include "stdafx.h"
#include"BackGround.h"

BackGround::BackGround(MainClient *p)
{
	this->pclient = p;
}

BackGround::~BackGround()
{
}

void BackGround::OnStart()
{
	_beginthread(Thread_BackGround,0,(void*)pclient);
}

void BackGround::Thread_BackGround(void *p)
{
	MainClient *p_client = (MainClient*)p;
	if(p_client->OnStart(MyName.GetBuffer()))
	{
		_sharing._findState = 0;
	}
	else
	{
		return;
	}
}