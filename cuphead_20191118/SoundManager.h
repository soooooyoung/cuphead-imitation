#pragma once
#include "singletonBase.h"
#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")

#include <map>

#define SOUNDBUFFER			10
#define EXTRACHANNELBUFFER	5
#define TOTALSOUNDBUFFER	SOUNDBUFFER + EXTRACHANNELBUFFER

using namespace FMOD;

class SoundManager : public singletonBase<SoundManager>
{
private:
	System*		system;
	Sound**		sound;
	Channel**	channel;

	map<string, Sound**>	mapSoundData;
	map<string, Sound**>::iterator	itSoundData;

public:
	HRESULT Init();
	void Release();
	void Update();

	void AddSound(string _key, string _soundFile, bool _isBGM, bool _isLoop);
	void Play(string _key, float _volume = 1.0f);	// 0.0f ~ 1.0f
	void Stop(string _key);
	void Pause(string _key);
	void Resume(string _key);

	bool IsPlaySound(string _key);
	bool IsPauseSound(string _key);

	SoundManager();
	~SoundManager();
};

