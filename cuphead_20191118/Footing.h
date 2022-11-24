#pragma once
#include "gameNode.h"
class Animation;
class Footing : public gameNode
{
private:
	float posX, posY;
	RECT rc;
	D2Image*  img;
	Animation* ani;
public:
	RECT GetRc() { return rc; }

	virtual HRESULT Init(float _posX, float _posY, float _width, float _height, string _strKey);		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void D2Render(ID2D1DCRenderTarget *ap_target) override;		// 프레임 단위 출력
	Footing();
	~Footing();
};

