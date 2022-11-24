#pragma once
#include "gameNode.h"
class Animation;
class Footing : public gameNode
{
private:
	float posX, posY;
	RECT rc;
	D2Image*  img;
	Animation* ani;
public:
	RECT GetRc() { return rc; }

	virtual HRESULT Init(float _posX, float _posY, float _width, float _height, string _strKey);		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void D2Render(ID2D1DCRenderTarget *ap_target) override;		// ������ ���� ���
	Footing();
	~Footing();
};

