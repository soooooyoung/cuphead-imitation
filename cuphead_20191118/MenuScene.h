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
	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	MenuScene();
	~MenuScene();
};

