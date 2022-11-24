#include "stdafx.h"
#include "TitleScene.h"
#include "Animation.h"


HRESULT TitleScene::Init()
{
	Sleep(1000);
	img = D2IMAGEMANAGER->FindImage("title");
	//img->ConvertImage(L"Image/title/title.png", gp_dcrendertarget);
	ani = new Animation;
	ani->Init(5120, 6912, 1024, 576);
	ani->SetFPS(10.0f);
	ani->SetPlayFrame(0, 58, false, true);
	ani->Start();

	return S_OK;
}

void TitleScene::Release()
{
	img->Release();
	SAFE_DELETE(img);
	ani->Release();
	SAFE_DELETE(ani);
}

void TitleScene::Update()
{
	if (ani) {
		ani->FrameUpdate();
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE)){
		SCENEMANAGER->ChangeScene("¸Þ´º");

	}
}

void TitleScene::Render()
{
}

void TitleScene::D2Render(ID2D1DCRenderTarget * ap_target)
{
	if (ani) {
		img->AniRenderSize(ap_target, 0, 0, WINSIZE_X, WINSIZE_Y, ani);
	}
}

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}
