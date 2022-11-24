#pragma once
#include "gameNode.h"

class Animation;
//class Transition;
class TitleScene : public gameNode
{
private:
	D2Image * img;
	Animation* ani;

public:

	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void Render();		// ������ ���� ���
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	TitleScene();
	~TitleScene();
};

