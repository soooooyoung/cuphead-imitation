#include "stdafx.h"
#include "LoadingScene.h"
#include "Animation.h"

HRESULT LoadingScene::Init()
{

	bg = D2IMAGEMANAGER->FindImage("bg");
	/*bg->ConvertImage(L"Image/loading/bg.png", gp_dcrendertarget);*/



	return S_OK;
}

void LoadingScene::Release()
{
	//if (bg) {
	//	bg->Release();
	//}
}

void LoadingScene::Update()
{
	//ani_bg->FrameUpdate();
}

void LoadingScene::D2Render(ID2D1DCRenderTarget * ap_target)
{
	bg->Render(ap_target);
}


LoadingScene::LoadingScene()
{
}


LoadingScene::~LoadingScene()
{
}
