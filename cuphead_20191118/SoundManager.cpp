#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager()
	: system(NULL)
	, sound(NULL)
	, channel(NULL)
{
}


SoundManager::~SoundManager()
{
}

HRESULT SoundManager::Init()
{
	// 사운드 시스템 생성
	System_Create(&system);

	// 채널 설정
	system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);

	// 사운드, 채널 동적할당
	sound = new Sound*[TOTALSOUNDBUFFER];
	channel = new Channel*[TOTALSOUNDBUFFER];

	memset(sound, 0, sizeof(Sound*) * TOTALSOUNDBUFFER);
	memset(channel, 0, sizeof(Channel*) * TOTALSOUNDBUFFER);

	return S_OK;
}

void SoundManager::Release()
{
	SAFE_DELETE_ARRAY(sound);
	SAFE_DELETE_ARRAY(channel);

	system->close();
	system->release();
}

void SoundManager::Update()
{
	if (system)
		system->update();
}

void SoundManager::AddSound(string _key, string _soundFile, bool _isBGM, bool _isLoop)
{
	if (_isLoop)
	{
		if (_isBGM)
		{
			system->createStream(
				_soundFile.c_str(),
				FMOD_LOOP_NORMAL,
				0,
				&sound[mapSoundData.size()]);
		}
		else
		{
			system->createSound(
				_soundFile.c_str(),
				FMOD_LOOP_NORMAL,
				0,
				&sound[mapSoundData.size()]);
		}
	}
	else
	{
		system->createSound(
			_soundFile.c_str(),
			FMOD_DEFAULT,
			0,
			&sound[mapSoundData.size()]);
	}

	mapSoundData.insert(make_pair(_key, &sound[mapSoundData.size()]));
}

void SoundManager::Play(string _key, float _volume)
{
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			system->playSound(
				FMOD_CHANNEL_FREE,
				//sound[count],
				(*(itSoundData->second)),
				false,
				&channel[count]);

			channel[count]->setVolume(_volume);
			break;
		}
	}

}

void SoundManager::Stop(string _key)
{
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			channel[count]->stop();
			break;
		}
	}
}

void SoundManager::Pause(string _key)
{
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			channel[count]->setPaused(true);
			break;
		}
	}
}

void SoundManager::Resume(string _key)
{
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			channel[count]->setPaused(false);
			break;
		}
	}
}

bool SoundManager::IsPlaySound(string _key)
{
	bool isPlay = false;
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool SoundManager::IsPauseSound(string _key)
{
	bool isPause = false;
	int count = 0;
	for (itSoundData = mapSoundData.begin();
		itSoundData != mapSoundData.end(); itSoundData++, count++)
	{
		if (_key == itSoundData->first)
		{
			channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}
