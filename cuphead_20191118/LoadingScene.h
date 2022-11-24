#pragma once
#include "gameNode.h"

class Animation;
class LoadingScene : public gameNode
{
private:
	D2Image* bg;
	Animation* ani_bg;

public:
	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	//virtual void Render(HDC hdc);		// ������ ���� ���
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	LoadingScene();
	~LoadingScene();
};

