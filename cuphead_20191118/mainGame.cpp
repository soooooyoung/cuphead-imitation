#include "stdafx.h"
#include "mainGame.h"
#include "LoadingScene.h"
#include "LogoScene.h"
#include "TitleScene.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "TutorialScene.h"

HRESULT mainGame::Init()
{
	hdc = GetDC(g_hWnd);

	TXTDATAMANAGER->Init();
	KEYMANAGER->Init();
	IMAGEMANAGER->Init();
	TIMERMANAGER->Init();
	SOUNDMANAGER->Init();
	SCENEMANAGER->Init();
	D2IMAGEMANAGER->Init();

	// �θ� Ŭ������ ������ ������ �ڿ�
	gameNode::Init();
	
	// ����� ����
	backBuffer = new Image;
	backBuffer->Init(WINSIZE_X, WINSIZE_Y);

				// �̹����߰� //
	//		ĳ����
	// �����
	D2IMAGEMANAGER->AddImage("cuphead_idle", L"Image/mob/cuphead/idle.png");
	D2IMAGEMANAGER->AddImage("cuphead_idle_left", L"Image/mob/cuphead/idle_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_idle_up", L"Image/mob/cuphead/idle_up.png");
	D2IMAGEMANAGER->AddImage("cuphead_idle_up_left", L"Image/mob/cuphead/idle_up_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_run_right", L"Image/mob/cuphead/run_right.png");
	D2IMAGEMANAGER->AddImage("cuphead_run_left", L"Image/mob/cuphead/run_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_jump", L"Image/mob/cuphead/jump.png");
	D2IMAGEMANAGER->AddImage("cuphead_jump_parry", L"Image/mob/cuphead/jump_parry.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_straight", L"Image/mob/cuphead/shoot_straight.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_straight_left", L"Image/mob/cuphead/shoot_straight_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_up", L"Image/mob/cuphead/shoot_up.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_up_left", L"Image/mob/cuphead/shoot_up_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_duck", L"Image/mob/cuphead/shoot_duck.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_duck_left", L"Image/mob/cuphead/shoot_duck_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_run_right_shoot", L"Image/mob/cuphead/run_right_shoot.png");
	D2IMAGEMANAGER->AddImage("cuphead_run_left_shoot", L"Image/mob/cuphead/run_left_shoot.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_diagonal_run", L"Image/mob/cuphead/shoot_diagonal_run.png");
	D2IMAGEMANAGER->AddImage("cuphead_shoot_diagonal_run_left", L"Image/mob/cuphead/shoot_diagonal_run_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_duck", L"Image/mob/cuphead/duck.png");
	D2IMAGEMANAGER->AddImage("cuphead_duck_left", L"Image/mob/cuphead/duck_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_idle_duck", L"Image/mob/cuphead/idle_duck.png");
	D2IMAGEMANAGER->AddImage("cuphead_idle_duck_left", L"Image/mob/cuphead/idle_duck_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_dash_air", L"Image/mob/cuphead/dash_air.png");
	D2IMAGEMANAGER->AddImage("cuphead_dash_air_left", L"Image/mob/cuphead/dash_air_left.png");
	//aim
	D2IMAGEMANAGER->AddImage("cuphead_aim_up", L"Image/mob/cuphead/aim_up.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_up_left", L"Image/mob/cuphead/aim_up_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_right", L"Image/mob/cuphead/aim_right.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_left", L"Image/mob/cuphead/aim_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_down", L"Image/mob/cuphead/aim_down.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_down_left", L"Image/mob/cuphead/aim_down_left.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_diagonal_up", L"Image/mob/cuphead/diagonal_up.png");
	D2IMAGEMANAGER->AddImage("cuphead_aim_diagonal_up_left", L"Image/mob/cuphead/diagonal_up_left.png");

		// ȿ��
	D2IMAGEMANAGER->AddImage("cuphead_dust_landing", L"Image/mob/cuphead/dust_landing.png");
	D2IMAGEMANAGER->AddImage("cuphead_dust_landing", L"Image/mob/cuphead/dust_landing.png");

	//		����
	// �ε���
	D2IMAGEMANAGER->AddImage("bg", L"Image/scenes/loading/bg.png");

	// �ΰ��
	D2IMAGEMANAGER->AddImage("logo", L"Image/scenes/logo/logo_small.png");

	// Ÿ��Ʋ��
	D2IMAGEMANAGER->AddImage("title", L"Image/scenes/title/title.png");

	// �޴���
	D2IMAGEMANAGER->AddImage("menu01", L"Image/scenes/menu/menu01.png");
	D2IMAGEMANAGER->AddImage("menu02", L"Image/scenes/menu/menu02.png");
	D2IMAGEMANAGER->AddImage("menu03", L"Image/scenes/menu/menu03.png");
	D2IMAGEMANAGER->AddImage("bg_menu", L"Image/scenes/menu/bg_menu.png");

	// Ʃ�丮���
	D2IMAGEMANAGER->AddImage("bg_tutorial", L"Image/scenes/tutorial/bg_tutorial.png");	//���
	D2IMAGEMANAGER->AddImage("fg_tutorial", L"Image/scenes/tutorial/fg_tutorial.png");
	D2IMAGEMANAGER->AddImage("tutorial", L"Image/scenes/tutorial/tutorial.png");
	D2IMAGEMANAGER->AddImage("obj01", L"Image/scenes/tutorial/obj01.png");

				// �� �߰� //
	// �ε�
	loadingScene = new LoadingScene;
	SCENEMANAGER->AddLoadingScene("�ε�", loadingScene);

	// ��Ʈ��
	logoScene = new LogoScene;
	SCENEMANAGER->AddScene("�ΰ�", logoScene);
	titleScene = new TitleScene;
	SCENEMANAGER->AddScene("Ÿ��Ʋ", titleScene);
	menuScene = new MenuScene;
	SCENEMANAGER->AddScene("�޴�", menuScene);
		
	//Ʃ�丮��
	tutorialScene = new TutorialScene;
	SCENEMANAGER->AddScene("Ʃ�丮��", tutorialScene);
	
	SCENEMANAGER->ChangeScene("Ʃ�丮��", "�ε�");

	return S_OK;
}

void mainGame::Release()
{
	gameNode::Release();

	// TODO : ���� Ŭ���� ������ �����Ѵ�.
	SCENEMANAGER->Release();
	SCENEMANAGER->ReleaseSingleton();

	SOUNDMANAGER->Release();
	SOUNDMANAGER->ReleaseSingleton();

	TXTDATAMANAGER->Release();
	TXTDATAMANAGER->ReleaseSingleton();

	TIMERMANAGER->Release();
	TIMERMANAGER->ReleaseSingleton();

	IMAGEMANAGER->Release();
	IMAGEMANAGER->ReleaseSingleton();

	KEYMANAGER->Release();
	KEYMANAGER->ReleaseSingleton();

	backBuffer->Release();
	SAFE_DELETE(backBuffer);

	ReleaseDC(g_hWnd, hdc);
}

void mainGame::Update()
{
	gameNode::Update();
	SCENEMANAGER->Update();
}

//void mainGame::Render()
//{
//	if (!backBuffer)	return;
//
//	HDC hBackDC = backBuffer->GetMemDC();
//
//	//SCENEMANAGER->Render(hBackDC);
//
//	PatBlt(hBackDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
//	TIMERMANAGER->Render(hBackDC);
//	////cup->Render();
//	backBuffer->Render(hdc, 0, 0);
//}

void mainGame::Render()
{


	if (!backBuffer)	return;

	HDC hBackDC = backBuffer->GetMemDC();
	RECT r;
	r.left = 0;
	r.top = 0;
	r.right = WINSIZE_X;
	r.bottom = WINSIZE_Y; 

	gp_dcrendertarget->BindDC(hBackDC, &r);
	gp_dcrendertarget->BeginDraw();
	//gp_dcrendertarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	SCENEMANAGER->D2Render(gp_dcrendertarget);
	gp_dcrendertarget->EndDraw();
	SCENEMANAGER->Render(hBackDC);

	//PatBlt(hBackDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	TIMERMANAGER->Render(hBackDC);
	////cup->Render();



	backBuffer->Render(hdc, 0, 0);
}

void mainGame::D2Render()
{



}

mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
