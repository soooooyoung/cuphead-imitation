#include "stdafx.h"
#include "TutorialScene.h"


bool TutorialScene::isCollide(RECT A, RECT B)
{
	RECT ch = A;
	RECT obj = B;
	if ((ch.left < obj.left && ch.right > obj.left &&
		((ch.bottom <= obj.bottom && ch.bottom >= obj.top)
			|| (ch.top >= obj.top && ch.top <= obj.bottom))) ||

			(ch.left >= obj.left && ch.left < obj.right &&
		((ch.bottom <= obj.bottom && ch.bottom >= obj.top)
			|| (ch.top >= obj.top && ch.top <= obj.bottom)))
		) {
		return true;
	}

	return false;
}



void TutorialScene::CheckCollide()
{


}

HRESULT TutorialScene::Init()
{
	bg_tutorial = D2IMAGEMANAGER->FindImage("bg_tutorial");
	fg_tutorial = D2IMAGEMANAGER->FindImage("fg_tutorial");
	tutorial = D2IMAGEMANAGER->FindImage("tutorial");
	obj01 = D2IMAGEMANAGER->FindImage("obj01");
	
	cuphead = new Cuphead;
	cuphead->Init();

	tutorialFrame = 0;
	cupheadFrame = 0;
	return S_OK;
}

void TutorialScene::Release()
{
	bg_tutorial->Release();
	SAFE_DELETE(bg_tutorial);
	fg_tutorial->Release();
	SAFE_DELETE(fg_tutorial);
	cuphead->Release();
	SAFE_DELETE(cuphead);
}

void TutorialScene::Update()
{
	CheckCollide();
	cuphead->Update();
	if (cuphead->GetPosX() > 768 && cuphead->GetPosX() > WINSIZE_X / 2 + 0) {
		cuphead->SetPosX(cuphead->GetPosX() - 7);
		tutorialFrame+=7;
	}
	else if (tutorialFrame > 0 && cuphead->GetPosX() < WINSIZE_X / 2 - 200) {
		cuphead->SetPosX(cuphead->GetPosX() + 7);
		tutorialFrame -= 7;
	}
	



	rc_obj01 = SetRect(2033 - tutorialFrame * 1.5 + 10, 505, 285, 270);

}

void TutorialScene::Render(HDC hdc)		// 충돌박스 전용
{
	//char str[256];
	//sprintf_s(str, "tutorialFrame : %f", tutorialFrame);
	//TextOut(hdc, 5, 105, str, strlen(str));
	//cuphead->Render(hdc);
	//Rectangle(hdc, rc_obj01.left, rc_obj01.top, rc_obj01.right, rc_obj01.bottom);
	//
}

void TutorialScene::D2Render(ID2D1DCRenderTarget * ap_target)
{
	bg_tutorial->Render(ap_target);
	tutorial->RenderSize(ap_target, 0, 0, tutorialFrame, 0, 7500 - (tutorialFrame * 1.5), 864, 5000, 576);

	obj01->RenderSize(ap_target, 2033 - tutorialFrame * 1.5, 460, 0, 0, 
		329, 285, obj01->GetWidth(), obj01->GetHeight());





	cuphead->D2Render(ap_target);
	fg_tutorial->Render(ap_target);


}

TutorialScene::TutorialScene()
{
}


TutorialScene::~TutorialScene()
{
}
