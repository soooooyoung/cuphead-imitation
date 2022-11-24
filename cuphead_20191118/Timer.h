#pragma once
class Timer
{
private:
	bool	isHardware;			// ���� Ÿ�̸Ӹ� �� �� �ִ��� ����
	float	timeScale;			// ��� �������� �ʴ� �������� ����� �������� �ð������� ��ȯ
	float	timeElapsed;		// ������ �ð��� ���� �ð��� �����
	__int64 currTime;			// ���� �ð� (���ػ� Ÿ�̸� ��)
	__int64 lastTime;			// ���� �ð� (���ػ� Ÿ�̸� ��)
	__int64 periodFrequency;	// ���ػ� Ÿ�̸��� ���ļ� (�ʴ� ������), �������� ������ 0 ��ȯ

	unsigned long frameRate;
	unsigned long FPSFrameCount;
	float FPSTimeElapsed;
	float worldTime;

public:
	HRESULT Init();
	void Tick(float lockFPS = 0.0f);

	unsigned long GetFrameRate() { return frameRate; }
	float GetWorldTime() { return worldTime; }
	float GetElapsedTime() { return timeElapsed; }

	Timer();
	~Timer();
};

