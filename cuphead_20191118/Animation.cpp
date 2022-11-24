#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}

HRESULT Animation::Init(int _totalWidth, int _totalHeight, int _frameW, int _frameH)
{
	frameWidth = _frameW;
	frameHeight = _frameH;

	int numFrameW = _totalWidth / frameWidth;
	int numFrameH = _totalHeight / frameHeight;

	frameNum = numFrameW * numFrameH;

	vecFrameList.clear();
	vecFrameList.reserve(frameNum);

	for (int i = 0; i < numFrameH; i++)
	{
		for (int j = 0; j < numFrameW; j++)
		{
			POINT posFrame;
			posFrame.x = j * frameWidth;
			posFrame.y = i * frameHeight;

			vecFrameList.push_back(posFrame);
		}
	}

	SetDefPlayFrame(false, true);

	return S_OK;
}

void Animation::Release()
{
	vecFrameList.clear();
	vecPlayList.clear();
}

void Animation::SetDefPlayFrame(bool _isReverse, bool _isLoop)
{
	isLoop = _isLoop;

	vecPlayList.clear();

	if (_isReverse)
	{
		// 역방향 플레이 리스트 설정
		for (int i = frameNum - 1; i > -1; i--)
		{
			vecPlayList.push_back(i);
		}
	}
	else
	{
		// 정방향 플레이 리스트 설정
		for (int i = 0; i < frameNum; i++)
		{
			vecPlayList.push_back(i);	// 0, 1, 2, 3, 4, 5, 6, ... frameNum - 1
		}
	}

}

void Animation::SetPlayFrame(int * _playArr, int _arrLength, bool _isLoop)
{
	isLoop = _isLoop;

	vecPlayList.clear();

	for (int i = 0; i < _arrLength; i++)
	{
		vecPlayList.push_back(_playArr[i]);
	}

}

void Animation::SetPlayFrame(int _start, int _end, bool _isReverse, bool _isLoop)
{
	isLoop = _isLoop;

	vecPlayList.clear();

	if (_start == _end)
	{
		Stop();
		return;
	}

	if (_start > _end)
	{
		for (int i = _start; i < frameNum; i++)
		{
			vecPlayList.push_back(i);
		}
		for (int i = 0; i < _end; i++)
		{
			vecPlayList.push_back(i);
		}
	}
	else
	{
		for (int i = _start; i < _end; i++)
		{
			vecPlayList.push_back(i);
		}
	}

}

void Animation::SetFPS(int _framePerSec)
{
	frameUpdateSec = 1.0f / _framePerSec;
}

void Animation::FrameUpdate()
{
	if (isPlaying)
	{
		elapsedSec += TIMERMANAGER->GetElapsedTime();

		if (elapsedSec >= frameUpdateSec)
		{
			nowPlayIdx++;

			if (nowPlayIdx == vecPlayList.size())
			{
				if (isLoop)
				{
					nowPlayIdx = 0;
				}
				else
				{
					nowPlayIdx--;
					isPlaying = false;
					isPlayed = true;
				}
			}


			elapsedSec -= frameUpdateSec;
		}
	}
}

void Animation::Start()
{
	isPlaying = true;
	isPlayed = false;
	nowPlayIdx = 0;
}

void Animation::Stop()
{
	isPlaying = false;
	nowPlayIdx = 0;
}

void Animation::Pause()
{
	isPlaying = false;
}

void Animation::Resume()
{
	isPlaying = true;
}
