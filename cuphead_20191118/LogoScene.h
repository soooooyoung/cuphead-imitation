#pragma once
#include "gameNode.h"

class Animation;
class LogoScene : public gameNode
{
private:
	D2Image* img;
	Animation* ani;
public:
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render();		// 프레임 단위 출력
	virtual void D2Render(ID2D1DCRenderTarget *ap_target) override;		// 프레임 단위 출력
	LogoScene();
	~LogoScene();
};

