#pragma once
#include "gameNode.h"

class Animation;
class Cuphead : public gameNode
{
private:
	// cuphead stats
	float posX, posY;

	RECT body;
	//cuphead MOTION
	enum MOTION {
		IDLE,
		IDLE_LEFT,
		IDLE_UP,
		IDLE_UP_LEFT,
		IDLE_DUCK,
		IDLE_DUCK_LEFT,
		RUN_RIGHT,
		RUN_LEFT,
		RUN_RIGHT_SHOOT,
		RUN_LEFT_SHOOT,
		JUMP,
		JUMP_PARRY,
		SHOOT_STRAIGHT,
		SHOOT_STRAIGHT_LEFT,
		SHOOT_UP,
		SHOOT_UP_LEFT,
		SHOOT_DUCK,
		SHOOT_DUCK_LEFT,
		SHOOT_DIAGONAL_RUN,
		SHOOT_DIAGONAL_RUN_LEFT,
		DUCK,
		DUCK_LEFT,
		DASH_AIR,
		DASH_AIR_LEFT,
		AIM_UP,
		AIM_UP_LEFT,
		AIM_LEFT,
		AIM_RIGHT,
		AIM_DOWN,
		AIM_DOWN_LEFT,
		AIM_DIAGONAL_UP,
		AIM_DIAGONAL_UP_LEFT,
		AIM_DIAGONAL_DOWN,
		AIM_DIAGONAL_DOWN_LEFT,
		MOTIONEND
	};

	enum DUST {
		DUST_NULL,
		DUST_LAND,
		DUSTEND
	};


	//enum DIRECTION {
	//	LEFT,
	//	RIGHT
	//};

	D2Image* img[MOTIONEND];
	Animation* ani[MOTIONEND];


	D2Image* dust_img[DUSTEND];
	Animation* dust_ani[DUSTEND];

	bool isFixed[MOTIONEND];

	int adjustX[MOTIONEND];
	int adjustY[MOTIONEND];

	float dustPosX[DUSTEND];
	float dustPosY[DUSTEND];
	int adjustDustX[DUSTEND];
	int adjustDustY[DUSTEND];

	MOTION currentMotion;
	DUST currentDust;

	bool isLeft;
	bool isLock;
	RECT objRC;

	//bool isShooting;
	//DIRECTION currentDir;
	
public:
	
	void GetObjRc(RECT _obj) { objRC = _obj; }
	RECT getCupheadRc() { return body; }

	float GetPosX() { return posX; }
	void SetPosX(float _posX) { posX = _posX; }
	float GetPosY() { return posY; }
	void SetPosY(float _posY) { posY = _posY; }
	void RectUpdate();
	void KeyUpdate();
	void MotionUpdate();
	void CollisionUpdate();
	void DustUpdate();
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render(HDC hdc);
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	Cuphead();
	~Cuphead();
};

