#include "stdafx.h"
#include "TimerManager.h"


HRESULT TimerManager::Init()
{
	timer = new Timer;
	timer->Init();

	return S_OK;
}

void TimerManager::Release()
{
	SAFE_DELETE(timer);
}

void TimerManager::Update(float lockFPS/* = 0.0f*/)
{
	timer->Tick(lockFPS);
}

void TimerManager::Render(HDC hdc)
{
#ifdef _DEBUG
	char str[256];
	if (timer)
	{
		SetBkMode(hdc, TRANSPARENT);

		wsprintf(str, "FramePerSecond : %d", timer->GetFrameRate());
		TextOut(hdc, 5, 5, str, strlen(str));

		sprintf_s(str, "WorldTime : %f", timer->GetWorldTime());
		TextOut(hdc, 5, 25, str, strlen(str));
	}
#else
#endif
}

TimerManager::TimerManager()
{
}


TimerManager::~TimerManager()
{
}
