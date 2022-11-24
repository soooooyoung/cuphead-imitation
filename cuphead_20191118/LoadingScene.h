#pragma once
#include "gameNode.h"

class Animation;
class LoadingScene : public gameNode
{
private:
	D2Image* bg;
	Animation* ani_bg;

public:
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	//virtual void Render(HDC hdc);		// 프레임 단위 출력
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	LoadingScene();
	~LoadingScene();
};

