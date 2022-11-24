#pragma once
#include "gameNode.h"
//#include "Cannon.h"

//class gameNode;
/*
���� ���� : has a
��� ���� : is a		(*)
*/

class Image;
class mainGame : public gameNode
{
private:
	HDC hdc;
	// �����
	Image*	backBuffer;


	gameNode* logoScene;
	gameNode* titleScene;
	gameNode* loadingScene;
	gameNode* menuScene;
	gameNode* tutorialScene;

public:
	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void Render();		// ������ ���� ���
	void D2Render();

	mainGame();
	~mainGame();
};

