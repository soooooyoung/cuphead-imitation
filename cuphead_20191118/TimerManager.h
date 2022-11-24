#pragma once
#include "singletonBase.h"
#include "Timer.h"

class TimerManager : public singletonBase<TimerManager>
{
private:
	Timer* timer;

public:
	HRESULT Init();
	void Release();
	void Update(float lockFPS = 0.0f);
	void Render(HDC hdc);

	float GetWorldTime() { return timer->GetWorldTime(); }
	float GetElapsedTime()
		{ if (timer) return timer->GetElapsedTime(); else return 0.0f; }

	TimerManager();
	~TimerManager();
};

