#include "stdafx.h"
#include "MenuScene.h"


HRESULT MenuScene::Init()
{
	menu[menu01] = D2IMAGEMANAGER->FindImage("menu01");
	menu[menu02] = D2IMAGEMANAGER->FindImage("menu02");
	menu[menu03] = D2IMAGEMANAGER->FindImage("menu03");
	bg_menu = D2IMAGEMANAGER->FindImage("bg_menu");

	currentMenu = menu01;
	return S_OK;
}

void MenuScene::Release()
{
	menu[menu01]->Release();
	menu[menu02]->Release();
	menu[menu03]->Release();
	SAFE_DELETE(menu[menu01]);
	SAFE_DELETE(menu[menu02]);
	SAFE_DELETE(menu[menu03]);
	bg_menu->Release();
	SAFE_DELETE(bg_menu);
}

void MenuScene::Update()
{

	switch (currentMenu) {
	case menu01:
		if (KEYMANAGER->IsOnceKeyDown(VK_DOWN)) {
			currentMenu = menu02;
		}
		if (KEYMANAGER->IsOnceKeyDown(VK_RETURN)) {
			SCENEMANAGER->ChangeScene("Æ©Åä¸®¾ó");
		}
		break;
	case menu02:
		if (KEYMANAGER->IsOnceKeyDown(VK_UP)) {
			currentMenu = menu01;
		}
		if (KEYMANAGER->IsOnceKeyDown(VK_DOWN)) {
			currentMenu = menu03;
		}
		break;

	case menu03:
		if (KEYMANAGER->IsOnceKeyDown(VK_UP)) {
			currentMenu = menu02;
		}
		if (KEYMANAGER->IsOnceKeyDown(VK_RETURN)) {
			PostQuitMessage(0);
		}
		break;

	}



}

void MenuScene::D2Render(ID2D1DCRenderTarget * ap_target)
{
	bg_menu->RenderSize(ap_target, 100, 0, 0, 0, WINSIZE_X, WINSIZE_Y, 1024, 576);
	menu[currentMenu]->Render(ap_target);
}

MenuScene::MenuScene()
{
}


MenuScene::~MenuScene()
{
}
