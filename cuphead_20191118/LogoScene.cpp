#include "stdafx.h"
#include "LogoScene.h"
#include "Animation.h"

HRESULT LogoScene::Init()
{
	img = D2IMAGEMANAGER->FindImage("logo");
	//img = new D2Image;
	//img->Init(L"Image/logo/logo.png");
	//img->ConvertImage(L"Image/logo/logo.png", gp_dcrendertarget);
	ani = new Animation;
	ani->Init(7168, 7488, 1024, 576);
	ani->SetFPS(20.0f);
	ani->SetIsLoop(false);
	ani->Start();
	return S_OK;
}

void LogoScene::Release()
{
	img->Release();
	SAFE_DELETE(img);
	ani->Release();
	SAFE_DELETE(ani);
}

void LogoScene::Update()
{
	ani->FrameUpdate();
	if (TIMERMANAGER->GetWorldTime() > 2.4 ) {
	}
	if (ani->GetIsPlayed()) {    
		SCENEMANAGER->ChangeScene("타이틀", "로딩");


	}
}

void LogoScene::Render()
{
}

void LogoScene::D2Render(ID2D1DCRenderTarget * ap_target)
{
	img->AniRenderSize(ap_target, 0, 0, WINSIZE_X, WINSIZE_Y, ani);
}

LogoScene::LogoScene()
{
}


LogoScene::~LogoScene()
{
}
