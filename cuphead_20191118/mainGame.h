#pragma once
#include "gameNode.h"
//#include "Cannon.h"

//class gameNode;
/*
전방 선언 : has a
헤더 포함 : is a		(*)
*/

class Image;
class mainGame : public gameNode
{
private:
	HDC hdc;
	// 백버퍼
	Image*	backBuffer;


	gameNode* logoScene;
	gameNode* titleScene;
	gameNode* loadingScene;
	gameNode* menuScene;
	gameNode* tutorialScene;

public:
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render();		// 프레임 단위 출력
	void D2Render();

	mainGame();
	~mainGame();
};

