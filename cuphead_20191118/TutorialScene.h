#pragma once
#include "gameNode.h"

class Animation;
class TutorialScene : public gameNode
{
private:
	D2Image* bg_tutorial;
	D2Image* fg_tutorial;
	D2Image* tutorial;

	//  ��ֹ�
	D2Image* obj01;
	RECT rc_obj01;

	Cuphead* cuphead;

	float cupheadFrame;
	float tutorialFrame;

public:
	bool isCollide(RECT A, RECT B);

	void CheckCollide();
	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void Render(HDC hdc);
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	TutorialScene();
	~TutorialScene();
};

