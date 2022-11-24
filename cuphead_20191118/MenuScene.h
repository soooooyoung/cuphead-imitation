#pragma once
#include "gameNode.h"

class Animation;
class MenuScene : public gameNode
{
private:

	enum MENU {
		menu01,
		menu02,
		menu03,
		menuend
	};
	D2Image * bg_menu;
	D2Image * menu[menuend];
	MENU currentMenu;
public:
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	MenuScene();
	~MenuScene();
};

