#pragma once
#include "gameNode.h"

class Animation;
class TutorialScene : public gameNode
{
private:
	D2Image* bg_tutorial;
	D2Image* fg_tutorial;
	D2Image* tutorial;

	//  장애물
	D2Image* obj01;
	RECT rc_obj01;

	Cuphead* cuphead;

	float cupheadFrame;
	float tutorialFrame;

public:
	bool isCollide(RECT A, RECT B);

	void CheckCollide();
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render(HDC hdc);
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	TutorialScene();
	~TutorialScene();
};

