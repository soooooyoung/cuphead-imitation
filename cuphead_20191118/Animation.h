#pragma once
#include <vector>

class Animation
{
private:
	vector<POINT>	vecFrameList;
	vector<int>		vecPlayList;

	int frameNum;
	int frameWidth;
	int frameHeight;

	bool isLoop;
	bool isPlaying;

	float frameUpdateSec;
	float elapsedSec;

	int nowPlayIdx;
	bool isEndFrame;
	bool isPlayed = false;
public:
	HRESULT Init(int _totalWidth, int _totalHeight, int _frameW, int _frameH);
	void Release();

	void SetDefPlayFrame(bool _isReverse, bool _isLoop);
	void SetPlayFrame(int* _playArr, int _arrLength, bool _isLoop = false);
	void SetPlayFrame(int _start, int _end, bool _isReverse = false, bool _isLoop = false);
	void SetIsLoop(bool _isLoop) { isLoop = _isLoop; }
	void SetFPS(int _framePerSec);
	void FrameUpdate();

	void Start();
	void Stop();
	void Pause();
	void Resume();

	POINT GetFramePos() { return vecFrameList[vecPlayList[nowPlayIdx]]; }
	int GetFrameWidth() { return frameWidth; }
	int GetFrameHeight() { return frameHeight; }
	bool GetIsPlaying() { return isPlaying; }
	bool GetIsPlayed() { return isPlayed; }
	void SetIsPlayed(bool _isPlayed) { isPlayed = _isPlayed; }

	int GetPlayIdx() { return nowPlayIdx; }

	Animation();
	~Animation();
};

