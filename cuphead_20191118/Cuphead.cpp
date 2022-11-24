#include "stdafx.h"
#include "Cuphead.h"
#include "Animation.h"

HRESULT Cuphead::Init()
{
	// 컵헤드 정보 초기화
	posY = WINSIZE_Y - 350;
	posX = WINSIZE_X - (WINSIZE_X - 100);
	isLeft = false;
	isLock = false;
	// 충돌박스
	body.left = posX;
	body.top = posY;
	body.right = posX + 100;
	body.bottom = posY + 100;

	// 모션상태초기화
	for (int i = 0; i < MOTIONEND; i++) {
		adjustX[i] = 0;
		adjustY[i] = 0;
		isFixed[i] = false;
	}

	for (int i = 0; i < DUSTEND; i++) {
		adjustDustX[i] = 0;
		adjustDustY[i] = 0;
		dustPosX[i] = 0;
		dustPosY[i] = 0;
	}

	// IDLE
	img[IDLE] = D2IMAGEMANAGER->FindImage("cuphead_idle");
	ani[IDLE] = new Animation;
	ani[IDLE]->Init(856, 155, 107, 155);
	ani[IDLE]->SetFPS(15.0f);
	ani[IDLE]->SetIsLoop(true);
	adjustX[IDLE] = 43;
	adjustY[IDLE] = 45;
	ani[IDLE]->Start();
	// IDLE_LEFT
	img[IDLE_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_idle_left");
	ani[IDLE_LEFT] = new Animation;
	ani[IDLE_LEFT]->Init(856, 155, 107, 155);
	ani[IDLE_LEFT]->SetFPS(15.0f);
	ani[IDLE_LEFT]->SetDefPlayFrame(true, true);
	adjustX[IDLE_LEFT] = 43;
	adjustY[IDLE_LEFT] = 45;
	ani[IDLE_LEFT]->Start();

	// IDLE_UP
	img[IDLE_UP] = D2IMAGEMANAGER->FindImage("cuphead_idle_up");
	ani[IDLE_UP] = new Animation;
	ani[IDLE_UP]->Init(1200, 200, 150, 200);
	ani[IDLE_UP]->SetFPS(15.0f);
	ani[IDLE_UP]->SetIsLoop(true);
	adjustX[IDLE_UP] = 12;
	//adjustY[IDLE_UP] = 2;
	ani[IDLE_UP]->Start();
	// IDLE_UPLEFT
	img[IDLE_UP_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_idle_up_left");
	ani[IDLE_UP_LEFT] = new Animation;
	ani[IDLE_UP_LEFT]->Init(1200, 200, 150, 200);
	ani[IDLE_UP_LEFT]->SetFPS(15.0f);
	ani[IDLE_UP_LEFT]->SetDefPlayFrame(true, true);
	adjustX[IDLE_UP_LEFT] = 28;
	//adjustY[IDLE_UP_LEFT] = 45;
	ani[IDLE_UP_LEFT]->Start();

	// IDLE_DUCK
	img[IDLE_DUCK] = D2IMAGEMANAGER->FindImage("cuphead_idle_duck");
	ani[IDLE_DUCK] = new Animation;
	ani[IDLE_DUCK]->Init(1600, 200, 200, 200);
	ani[IDLE_DUCK]->SetFPS(14.0f);
	ani[IDLE_DUCK]->SetDefPlayFrame(false, true);
	adjustX[IDLE_DUCK] = -2;
	adjustY[IDLE_DUCK] = 5;
	ani[IDLE_DUCK]->Start();
	isFixed[IDLE_DUCK] = false;
	// IDLE_DUCK_LEFT
	img[IDLE_DUCK_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_idle_duck_left");
	ani[IDLE_DUCK_LEFT] = new Animation;
	ani[IDLE_DUCK_LEFT]->Init(1600, 200, 200, 200);
	ani[IDLE_DUCK_LEFT]->SetFPS(14.0f);
	ani[IDLE_DUCK_LEFT]->SetDefPlayFrame(true, true);
	adjustX[IDLE_DUCK_LEFT] = -2;
	adjustY[IDLE_DUCK_LEFT] = 5;
	ani[IDLE_DUCK_LEFT]->Start();
	isFixed[IDLE_DUCK_LEFT] = false;

	// RUN_RIGHT
	img[RUN_RIGHT] = D2IMAGEMANAGER->FindImage("cuphead_run_right");
	ani[RUN_RIGHT] = new Animation;
	ani[RUN_RIGHT]->Init(450, 1200, 150, 200);
	ani[RUN_RIGHT]->SetPlayFrame(0, 16, false, true);
	ani[RUN_RIGHT]->SetFPS(15.0f);
	ani[RUN_RIGHT]->Start();

	// RUN_LEFT
	img[RUN_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_run_left");
	ani[RUN_LEFT] = new Animation;
	ani[RUN_LEFT]->Init(2400, 200, 150, 200);
	ani[RUN_LEFT]->SetDefPlayFrame(true, true);
	ani[RUN_LEFT]->SetFPS(15.0f);
	ani[RUN_LEFT]->Start();

	// JUMP
	img[JUMP] = D2IMAGEMANAGER->FindImage("cuphead_jump");
	ani[JUMP] = new Animation;
	ani[JUMP]->Init(1350, 250, 150, 250);
	ani[JUMP]->SetDefPlayFrame(false, false);
	ani[JUMP]->SetFPS(18.0f);
	adjustX[JUMP] = 20;
	adjustY[JUMP] = -240;
	isFixed[JUMP] = true;

	// JUMP_PARRY
	img[JUMP_PARRY] = D2IMAGEMANAGER->FindImage("cuphead_jump_parry");
	ani[JUMP_PARRY] = new Animation;
	ani[JUMP_PARRY]->Init(1350, 350, 150, 350);
	ani[JUMP_PARRY]->SetDefPlayFrame(false, false);
	ani[JUMP_PARRY]->SetFPS(18.0f);
	adjustX[JUMP_PARRY] = 20;
	adjustY[JUMP_PARRY] = -300;
	isFixed[JUMP_PARRY] = true;

	// SHOOT_STRAIGHT
	img[SHOOT_STRAIGHT] = D2IMAGEMANAGER->FindImage("cuphead_shoot_straight");
	ani[SHOOT_STRAIGHT] = new Animation;
	ani[SHOOT_STRAIGHT]->Init(450, 200, 150, 200);
	ani[SHOOT_STRAIGHT]->SetDefPlayFrame(false, true);
	ani[SHOOT_STRAIGHT]->SetFPS(15.0f);
	ani[SHOOT_STRAIGHT]->Start();
	adjustX[SHOOT_STRAIGHT] = 25;
	//adjustY[SHOOT_STRAIGHT] = -200;

	// SHOOT_STRAIGHT_LEFT
	img[SHOOT_STRAIGHT_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_shoot_straight_left");
	ani[SHOOT_STRAIGHT_LEFT] = new Animation;
	ani[SHOOT_STRAIGHT_LEFT]->Init(450, 200, 150, 200);
	ani[SHOOT_STRAIGHT_LEFT]->SetDefPlayFrame(true, true);
	ani[SHOOT_STRAIGHT_LEFT]->SetFPS(15.0f);
	ani[SHOOT_STRAIGHT_LEFT]->Start();
	adjustX[SHOOT_STRAIGHT_LEFT] = 18;

	// RUN_RIGHT_SHOOT
	img[RUN_RIGHT_SHOOT] = D2IMAGEMANAGER->FindImage("cuphead_run_right_shoot");
	ani[RUN_RIGHT_SHOOT] = new Animation;
	ani[RUN_RIGHT_SHOOT]->Init(2400, 200, 150, 200);
	ani[RUN_RIGHT_SHOOT]->SetDefPlayFrame(false, true);
	ani[RUN_RIGHT_SHOOT]->SetFPS(15.0f);
	ani[RUN_RIGHT_SHOOT]->Start();
	adjustY[RUN_RIGHT_SHOOT] = 0;
	isFixed[RUN_RIGHT_SHOOT] = false;

	//RUN_LEFT_SHOOT
	img[RUN_LEFT_SHOOT] = D2IMAGEMANAGER->FindImage("cuphead_run_left_shoot");
	ani[RUN_LEFT_SHOOT] = new Animation;
	ani[RUN_LEFT_SHOOT]->Init(2400, 200, 150, 200);
	ani[RUN_LEFT_SHOOT]->SetDefPlayFrame(true, true);
	ani[RUN_LEFT_SHOOT]->SetFPS(15.0f);
	ani[RUN_LEFT_SHOOT]->Start();
	adjustY[RUN_LEFT_SHOOT] = 0;
	isFixed[RUN_LEFT_SHOOT] = false;

	//SHOOT_DIAGONAL_RUN
	img[SHOOT_DIAGONAL_RUN] = D2IMAGEMANAGER->FindImage("cuphead_shoot_diagonal_run");
	ani[SHOOT_DIAGONAL_RUN] = new Animation;
	ani[SHOOT_DIAGONAL_RUN]->Init(2400, 200, 150, 200);
	ani[SHOOT_DIAGONAL_RUN]->SetDefPlayFrame(false, true);
	ani[SHOOT_DIAGONAL_RUN]->SetFPS(15.0f);
	ani[SHOOT_DIAGONAL_RUN]->Start();
	adjustY[SHOOT_DIAGONAL_RUN] = 0;
	isFixed[SHOOT_DIAGONAL_RUN] = false;
	//SHOOT_DIAGONAL_RUN_LEFT
	img[SHOOT_DIAGONAL_RUN_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_shoot_diagonal_run_left");
	ani[SHOOT_DIAGONAL_RUN_LEFT] = new Animation;
	ani[SHOOT_DIAGONAL_RUN_LEFT]->Init(2400, 200, 150, 200);
	ani[SHOOT_DIAGONAL_RUN_LEFT]->SetDefPlayFrame(true, true);
	ani[SHOOT_DIAGONAL_RUN_LEFT]->SetFPS(15.0f);
	ani[SHOOT_DIAGONAL_RUN_LEFT]->Start();
	adjustY[SHOOT_DIAGONAL_RUN_LEFT] = 0;
	isFixed[SHOOT_DIAGONAL_RUN_LEFT] = false;

	// SHOOT_UP
	img[SHOOT_UP] = D2IMAGEMANAGER->FindImage("cuphead_shoot_up");
	ani[SHOOT_UP] = new Animation;
	ani[SHOOT_UP]->Init(450, 200, 150, 200);
	ani[SHOOT_UP]->SetDefPlayFrame(false, true);
	ani[SHOOT_UP]->SetFPS(15.0f);
	ani[SHOOT_UP]->Start();
	adjustX[SHOOT_UP] = 13;
	//adjustY[SHOOT_UP] = 5;
	isFixed[SHOOT_UP] = false;
	// SHOOT_UP_LEFT
	img[SHOOT_UP_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_shoot_up_left");
	ani[SHOOT_UP_LEFT] = new Animation;
	ani[SHOOT_UP_LEFT]->Init(450, 200, 150, 200);
	ani[SHOOT_UP_LEFT]->SetDefPlayFrame(false, true);
	ani[SHOOT_UP_LEFT]->SetFPS(15.0f);
	ani[SHOOT_UP_LEFT]->Start();
	adjustX[SHOOT_UP_LEFT] = 30;
	//adjustX[SHOOT_UP_LEFT] = -5;
	//adjustY[SHOOT_UP_LEFT] = 5;
	isFixed[SHOOT_UP_LEFT] = false;

	// SHOOT_DUCK
	img[SHOOT_DUCK] = D2IMAGEMANAGER->FindImage("cuphead_shoot_duck");
	ani[SHOOT_DUCK] = new Animation;
	ani[SHOOT_DUCK]->Init(600, 200, 200, 200);
	ani[SHOOT_DUCK]->SetDefPlayFrame(false, true);
	ani[SHOOT_DUCK]->SetFPS(18.0f);
	ani[SHOOT_DUCK]->Start();
	adjustX[SHOOT_DUCK] = -5;
	adjustY[SHOOT_DUCK] = 5;
	isFixed[SHOOT_DUCK] = false;

	// SHOOT_DUCK_LEFT
	img[SHOOT_DUCK_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_shoot_duck_left");
	ani[SHOOT_DUCK_LEFT] = new Animation;
	ani[SHOOT_DUCK_LEFT]->Init(600, 200, 200, 200);
	ani[SHOOT_DUCK_LEFT]->SetDefPlayFrame(false, true);
	ani[SHOOT_DUCK_LEFT]->SetFPS(18.0f);
	ani[SHOOT_DUCK_LEFT]->Start();
	adjustX[SHOOT_DUCK_LEFT] = 2;
	adjustY[SHOOT_DUCK_LEFT] = 5;
	isFixed[SHOOT_DUCK_LEFT] = false;

	// DUCK
	img[DUCK] = D2IMAGEMANAGER->FindImage("cuphead_duck");
	ani[DUCK] = new Animation;
	ani[DUCK]->Init(1400, 200, 200, 200);
	ani[DUCK]->SetDefPlayFrame(false, false);
	ani[DUCK]->SetFPS(18.0f);
	adjustX[DUCK] = -2;
	adjustY[DUCK] = 5;
	isFixed[DUCK] = true;

	// DUCK_LEFT
	img[DUCK_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_duck_left");
	ani[DUCK_LEFT] = new Animation;
	ani[DUCK_LEFT]->Init(1400, 200, 200, 200);
	ani[DUCK_LEFT]->SetDefPlayFrame(true, false);
	ani[DUCK_LEFT]->SetFPS(18.0f);
	adjustX[DUCK_LEFT] = -2;
	adjustY[DUCK_LEFT] = 5;
	isFixed[DUCK_LEFT] = true;

	// DASH_AIR
	img[DASH_AIR] = D2IMAGEMANAGER->FindImage("cuphead_dash_air");
	ani[DASH_AIR] = new Animation;
	ani[DASH_AIR]->Init(2100, 200, 350, 200);
	ani[DASH_AIR]->SetDefPlayFrame(false, false);
	ani[DASH_AIR]->SetFPS(13.0f);
	adjustX[DASH_AIR] = -100;  
	//adjustX[DASH_AIR] = -2;
	//adjustY[DASH_AIR] = 5;
	isFixed[DASH_AIR] = true;
	// DASH_AIR_LEFT
	img[DASH_AIR_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_dash_air_left");
	ani[DASH_AIR_LEFT] = new Animation;
	ani[DASH_AIR_LEFT]->Init(2100, 200, 350, 200);
	ani[DASH_AIR_LEFT]->SetDefPlayFrame(true, false);
	ani[DASH_AIR_LEFT]->SetFPS(13.0f);
	//adjustX[DASH_AIR_LEFT] = -2;
	//adjustY[DASH_AIR_LEFT] = 5;
	isFixed[DASH_AIR_LEFT] = true;

	//AIM_UP
	img[AIM_UP] = D2IMAGEMANAGER->FindImage("cuphead_aim_up");
	ani[AIM_UP] = new Animation;
	ani[AIM_UP]->Init(1200, 200, 150, 200);
	ani[AIM_UP]->SetDefPlayFrame(false, true);
	ani[AIM_UP]->SetFPS(15.0f);
	ani[AIM_UP]->Start();
	adjustX[AIM_UP] = 12;

	//AIM_UP_LEFT
	img[AIM_UP_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_aim_up_left");
	ani[AIM_UP_LEFT] = new Animation;
	ani[AIM_UP_LEFT]->Init(1200, 200, 150, 200);
	ani[AIM_UP_LEFT]->SetDefPlayFrame(true, true);
	ani[AIM_UP_LEFT]->SetFPS(15.0f);
	ani[AIM_UP_LEFT]->Start();
	adjustX[AIM_UP_LEFT] = 30;

	//AIM_RIGHT
	img[AIM_RIGHT] = D2IMAGEMANAGER->FindImage("cuphead_aim_right");
	ani[AIM_RIGHT] = new Animation;
	ani[AIM_RIGHT]->Init(1600, 200, 200, 200);
	ani[AIM_RIGHT]->SetDefPlayFrame(false, true);
	ani[AIM_RIGHT]->SetFPS(15.0f);
	ani[AIM_RIGHT]->Start();
	adjustX[AIM_RIGHT] = 14;
	adjustY[AIM_RIGHT] = -2;
	//AIM_LEFT
	img[AIM_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_aim_left");
	ani[AIM_LEFT] = new Animation;
	ani[AIM_LEFT]->Init(1600, 200, 200, 200);
	ani[AIM_LEFT]->SetDefPlayFrame(true, true);
	ani[AIM_LEFT]->SetFPS(15.0f);
	ani[AIM_LEFT]->Start();
	adjustX[AIM_LEFT] = -21;
	adjustY[AIM_LEFT] = -2;
	//AIM_DOWN
	img[AIM_DOWN] = D2IMAGEMANAGER->FindImage("cuphead_aim_down");
	ani[AIM_DOWN] = new Animation;
	ani[AIM_DOWN]->Init(1200, 200, 150, 200);
	ani[AIM_DOWN]->SetDefPlayFrame(false, true);
	ani[AIM_DOWN]->SetFPS(15.0f);
	ani[AIM_DOWN]->Start();
	adjustX[AIM_DOWN] = 25;
	adjustY[AIM_DOWN] = 16;

	//AIM_DOWN_LEFT
	img[AIM_DOWN_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_aim_down_left");
	ani[AIM_DOWN_LEFT] = new Animation;
	ani[AIM_DOWN_LEFT]->Init(1200, 200, 150, 200);
	ani[AIM_DOWN_LEFT]->SetDefPlayFrame(true, true);
	ani[AIM_DOWN_LEFT]->SetFPS(15.0f);
	ani[AIM_DOWN_LEFT]->Start();
	adjustX[AIM_DOWN_LEFT] = 18;
	adjustY[AIM_DOWN_LEFT] = 16;

	//AIM_DIAGONAL_UP
	img[AIM_DIAGONAL_UP] = D2IMAGEMANAGER->FindImage("cuphead_aim_diagonal_up");
	ani[AIM_DIAGONAL_UP] = new Animation;
	ani[AIM_DIAGONAL_UP]->Init(1600, 200, 200, 200);
	ani[AIM_DIAGONAL_UP]->SetDefPlayFrame(false, true);
	ani[AIM_DIAGONAL_UP]->SetFPS(15.0f);
	ani[AIM_DIAGONAL_UP]->Start();
	adjustX[AIM_DIAGONAL_UP] = 14;
	adjustY[AIM_DIAGONAL_UP] = -2;

	//AIM_DIAGONAL_UP_LEFT
	img[AIM_DIAGONAL_UP_LEFT] = D2IMAGEMANAGER->FindImage("cuphead_aim_diagonal_up_left");
	ani[AIM_DIAGONAL_UP_LEFT] = new Animation;
	ani[AIM_DIAGONAL_UP_LEFT]->Init(1600, 200, 200, 200);
	ani[AIM_DIAGONAL_UP_LEFT]->SetDefPlayFrame(true, true);
	ani[AIM_DIAGONAL_UP_LEFT]->SetFPS(15.0f);
	ani[AIM_DIAGONAL_UP_LEFT]->Start();
	adjustX[AIM_DIAGONAL_UP_LEFT] = -21;
	adjustY[AIM_DIAGONAL_UP_LEFT] = -2;

	// DUST_landing
	dust_img[DUST_LAND] = D2IMAGEMANAGER->FindImage("cuphead_dust_landing");
	dust_ani[DUST_LAND] = new Animation;
	dust_ani[DUST_LAND]->Init(900, 800, 300, 200);
	dust_ani[DUST_LAND]->SetDefPlayFrame(false, false);
	dust_ani[DUST_LAND]->SetFPS(15.0f);
	adjustDustX[DUST_LAND] = -50;
	adjustDustY[DUST_LAND] = 40;
	//adjustX[JUMP] = 20;
	//adjustY[JUMP] = -200;
	//isFixed[JUMP] = true;

	currentDust = DUST_NULL;
	currentMotion = IDLE;
	ani[currentMotion]->Start();
	return S_OK;
}

void Cuphead::Release()
{
	if (img[IDLE]) {
		img[IDLE]->Release();
		SAFE_DELETE(img[IDLE]);
	}
	if (ani[IDLE]) {
		ani[IDLE]->Release();
		SAFE_DELETE(ani[IDLE]);
	}
}

void Cuphead::Update()
{


	MotionUpdate();
	DustUpdate();
	ani[currentMotion]->FrameUpdate();
	if (currentMotion == JUMP) {
		ani[JUMP_PARRY]->FrameUpdate();
	}

	if (currentDust != DUST_NULL) {
		dust_ani[currentDust]->FrameUpdate();
	}
	RectUpdate();
}

void Cuphead::RectUpdate()
{
	switch (currentMotion) {
	case	IDLE:
		body.left = posX + 60;
		body.top = posY + 80;
		body.right = body.left + 80;
		body.bottom = body.top + 110;
		break;

	case	IDLE_LEFT:
		body.left = posX + 55;
		body.top = posY + 80;
		body.right = body.left + 80;
		body.bottom = body.top + 110;
		break;
	case	IDLE_UP:
		break;
	case	IDLE_UP_LEFT:
		break;
	case	IDLE_DUCK:
		break;
	case	IDLE_DUCK_LEFT:
		break;
	case	RUN_RIGHT:
		body.left = posX + 50;
		body.top = posY + 80;
		body.right = body.left + 80;
		body.bottom = body.top + 110;
		break;
	case	RUN_LEFT:
		body.left = posX + 20;
		body.top = posY + 80;
		body.right = body.left + 80;
		body.bottom = body.top + 110;
		break;
	case	RUN_RIGHT_SHOOT:
		break;
	case	RUN_LEFT_SHOOT:
		break;
	case	JUMP:
		switch (ani[JUMP]->GetPlayIdx()) {
		case 0 :
			body.left = posX + 60;
			body.top = posY + 10;
			body.right = body.left + 80;
			body.bottom = body.top + 110;
			break;

		case 1:
			body.left = posX + 60;
			body.top = posY - 100;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 2:
			body.left = posX + 60;
			body.top = posY - 150;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 3:
			body.left = posX + 60;
			body.top = posY - 150;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 4:
			body.left = posX + 60;
			body.top = posY - 180;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 5:
			body.left = posX + 60;
			body.top = posY - 200;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 6:
			body.left = posX + 60;
			body.top = posY - 170;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 7:
			body.left = posX + 60;
			body.top = posY - 150;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 8:
			body.left = posX + 60;
			body.top = posY - 80;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		case 9:
			body.left = posX + 60;
			body.top = posY - 100;
			body.right = body.left + 80;
			body.bottom = body.top + 80;
			break;
		}

		break;
	case	JUMP_PARRY:
		break;
	case	SHOOT_STRAIGHT:
		break;
	case	SHOOT_STRAIGHT_LEFT:
		break;
	case	SHOOT_UP:
		break;
	case	SHOOT_UP_LEFT:
		break;
	case	SHOOT_DUCK:
		break;
	case	SHOOT_DUCK_LEFT:
		break;
	case	SHOOT_DIAGONAL_RUN:
		break;
	case	SHOOT_DIAGONAL_RUN_LEFT:
		break;
	case	DUCK:
		break;
	case	DUCK_LEFT:
		break;
	case	DASH_AIR:
		break;
	case	DASH_AIR_LEFT:
		break;
	}
}

void Cuphead::KeyUpdate()
{

}

void Cuphead::MotionUpdate()
{


	if (KEYMANAGER->IsOnceKeyDown(VK_SHIFT)) {
		if (currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT) {
			if (isLeft) {
				currentMotion = DASH_AIR_LEFT;
			}
			else {
				currentMotion = DASH_AIR;
			}
			ani[currentMotion]->Start();
		}
	}
	if (isLock == false) {
		if (KEYMANAGER->IsOnceKeyDown(VK_DOWN)) {
			if (currentMotion != DUCK && currentMotion != DUCK_LEFT && currentMotion != IDLE_DUCK && currentMotion != IDLE_DUCK_LEFT &&
				currentMotion != JUMP && currentMotion != JUMP_PARRY &&
				currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT) {
				if (isLeft) {
					currentMotion = DUCK_LEFT;
				}
				else {
					currentMotion = DUCK;
				}
				ani[currentMotion]->Start();
			}
		}
	}
	if (KEYMANAGER->IsStayKeyDown(VK_DOWN)) {
		if (isLock == false) {
			if (currentMotion != DUCK && currentMotion != DUCK_LEFT &&
				currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT &&
				currentMotion != JUMP && currentMotion != JUMP_PARRY) {
				if (isLeft) {
					if (KEYMANAGER->IsStayKeyDown('X')) {
						currentMotion = SHOOT_DUCK_LEFT;
					}
					else {
						currentMotion = IDLE_DUCK_LEFT;
					}
				}
				else {
					if (KEYMANAGER->IsStayKeyDown('X')) {
						currentMotion = SHOOT_DUCK;
					}
					else {
						currentMotion = IDLE_DUCK;
					}
				}
			}
		}
	}
	else if (!KEYMANAGER->IsStayKeyDown(VK_DOWN)) {
		if (currentMotion == DUCK || currentMotion == DUCK_LEFT ||
			currentMotion == IDLE_DUCK || currentMotion == IDLE_DUCK_LEFT ||
			currentMotion == SHOOT_DUCK || currentMotion == SHOOT_DUCK_LEFT) {
			if (isLeft) {
				currentMotion = IDLE_LEFT;
			}
			else {
				currentMotion = IDLE;
			}
		} 
	}

	
	if (KEYMANAGER->IsStayKeyDown(VK_LEFT)) {
		isLeft = true;
		if (isLock == false) {
			if (currentMotion != IDLE_DUCK && currentMotion != IDLE_DUCK_LEFT && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT &&
				currentMotion != SHOOT_DUCK && currentMotion != SHOOT_DUCK_LEFT) {
				posX -= 7;

				if (currentMotion != JUMP && currentMotion != JUMP_PARRY) {
					if (KEYMANAGER->IsStayKeyDown('X') && KEYMANAGER->IsStayKeyDown(VK_UP)) {
						currentMotion = SHOOT_DIAGONAL_RUN_LEFT;
					}
					else if (KEYMANAGER->IsStayKeyDown('X')) {
						currentMotion = RUN_LEFT_SHOOT;
					}
					else {
						currentMotion = RUN_LEFT;
					}
				}
			}
		}
	}

	else if (KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
		isLeft = false;
		if (isLock == false) {
			if (currentMotion != IDLE_DUCK && currentMotion != IDLE_DUCK_LEFT && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT &&
				currentMotion != SHOOT_DUCK && currentMotion != SHOOT_DUCK_LEFT) {
				posX += 7;
				if (currentMotion != JUMP && currentMotion != JUMP_PARRY) {
					if (KEYMANAGER->IsStayKeyDown('X') && KEYMANAGER->IsStayKeyDown(VK_UP)) {
						currentMotion = SHOOT_DIAGONAL_RUN;
					}
					else if (KEYMANAGER->IsStayKeyDown('X')) {
						currentMotion = RUN_RIGHT_SHOOT;
					}
					else {
						currentMotion = RUN_RIGHT;
					}
				}
			}
		}
	}

	if (!KEYMANAGER->IsStayKeyDown(VK_LEFT)) {
		if (currentMotion == RUN_LEFT) {
			currentMotion = IDLE_LEFT;
		}
		if (currentMotion == RUN_LEFT_SHOOT) {
			currentMotion = IDLE_LEFT;
		}
		if (currentMotion == SHOOT_DIAGONAL_RUN_LEFT) {
			currentMotion = IDLE_LEFT;
		}
	}
	if (!KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
		if (currentMotion == RUN_RIGHT) {
			currentMotion = IDLE;
		}
		if (currentMotion == RUN_RIGHT_SHOOT) {
			currentMotion = IDLE;
		}
		if (currentMotion == SHOOT_DIAGONAL_RUN) {
			currentMotion = IDLE;
		}
	}

	if (KEYMANAGER->IsStayKeyDown('X')) {
		if (currentMotion != JUMP && currentMotion != JUMP_PARRY && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT) {

			if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
				if (currentMotion == IDLE_LEFT || currentMotion == SHOOT_STRAIGHT_LEFT)
				{
					currentMotion = SHOOT_UP_LEFT;
				}
				if (currentMotion == IDLE || currentMotion == SHOOT_STRAIGHT) {
						currentMotion = SHOOT_UP;
					
				}
			}
			else if (currentMotion == IDLE) {
				currentMotion = SHOOT_STRAIGHT;
			}
			else if (currentMotion == IDLE_LEFT) {
				currentMotion = SHOOT_STRAIGHT_LEFT;
			}

			if (!KEYMANAGER->IsStayKeyDown(VK_UP)) {
				if (currentMotion == SHOOT_UP || currentMotion == SHOOT_UP_LEFT) {
					if (isLeft)
					{
						currentMotion = IDLE_LEFT;
					}
					else {
						currentMotion = IDLE;
					}
				}
			}
		}
	}

	if (KEYMANAGER->IsOnceKeyUp('X')) {
		if (currentMotion == SHOOT_STRAIGHT) {
			currentMotion = IDLE;
		}
		if (currentMotion == SHOOT_STRAIGHT_LEFT) {
			currentMotion = IDLE_LEFT;
		}
		if (currentMotion == RUN_RIGHT_SHOOT) {
			currentMotion = RUN_RIGHT;
		}
		if (currentMotion == RUN_LEFT_SHOOT) {
			currentMotion = RUN_LEFT;
		}
		if (currentMotion == SHOOT_UP) {
			currentMotion = IDLE;
		}
		if (currentMotion == SHOOT_UP_LEFT) {
			currentMotion = IDLE_LEFT;
		}
	}

	if (KEYMANAGER->IsOnceKeyDown('Z')) {
		if (currentMotion != JUMP &&
			currentMotion != JUMP_PARRY &&
			currentMotion != DASH_AIR &&
			currentMotion != DASH_AIR_LEFT)
		{

			currentMotion = JUMP;
			ani[JUMP_PARRY]->Start();
			ani[JUMP]->Start();
		}
		else if (currentMotion == JUMP)
		{
			currentMotion = JUMP_PARRY;
		}
	}
	if (KEYMANAGER->IsStayKeyDown(VK_UP) /*&& currentMotion != SHOOT_UP && currentMotion != SHOOT_UP_LEFT
			&& currentMotion != JUMP && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT */
		) {
		if (currentMotion == IDLE) {
			currentMotion = AIM_UP;
		}
		if (currentMotion == IDLE_LEFT) {
			currentMotion = AIM_UP_LEFT;
		}

	}
	else {
		if (currentMotion == AIM_UP) {
			currentMotion = IDLE;
		}
		if (currentMotion == AIM_UP_LEFT) {
			currentMotion = IDLE_LEFT;
		}
	}
	if (KEYMANAGER->IsStayKeyDown('C')) {
		if (currentMotion != JUMP && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT
			&& KEYMANAGER->IsStayKeyDown('X') == false) {
			isLock = true;
			if (!isLeft) {
				if (KEYMANAGER->IsStayKeyDown(VK_UP) && KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
					currentMotion = AIM_DIAGONAL_UP;
				}
				else if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
					currentMotion = AIM_UP;
				}
				else if (KEYMANAGER->IsStayKeyDown(VK_DOWN)) {
					currentMotion = AIM_DOWN;
				} 
				else {
					currentMotion = AIM_RIGHT;
				}
			}
			else if (isLeft) {
				if (KEYMANAGER->IsStayKeyDown(VK_UP) && KEYMANAGER->IsStayKeyDown(VK_LEFT)) {
					currentMotion = AIM_DIAGONAL_UP_LEFT;
				}
				else if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
					currentMotion = AIM_UP_LEFT;
				}
				else if (KEYMANAGER->IsStayKeyDown(VK_DOWN)) {
					currentMotion = AIM_DOWN_LEFT;
				}
				else {
					currentMotion = AIM_LEFT;
				}
			}
		}
		else if (currentMotion != JUMP && currentMotion != DASH_AIR && currentMotion != DASH_AIR_LEFT
			&& KEYMANAGER->IsStayKeyDown('X') == true) {
			isLock = true;
			if (!isLeft) {
				if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
					currentMotion = SHOOT_UP;
				}
				else if (KEYMANAGER->IsStayKeyDown(VK_DOWN)) {
		/*			currentMotion = AIM_DOWN;*/
				}
				else {
					currentMotion = SHOOT_STRAIGHT;
				}
			}
			else if (isLeft) {
				if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
					currentMotion = SHOOT_UP_LEFT;
				}
				else {
					currentMotion = SHOOT_STRAIGHT_LEFT;
				}
			}
		}
	}
	else {
		isLock = false;
		if (currentMotion == AIM_UP || currentMotion == AIM_LEFT || currentMotion == AIM_RIGHT || currentMotion == AIM_UP_LEFT
			|| currentMotion == AIM_DIAGONAL_UP_LEFT || currentMotion == AIM_DIAGONAL_UP || currentMotion == AIM_DOWN || currentMotion == AIM_DOWN_LEFT) {
			if (isLeft) {
				currentMotion = IDLE_LEFT;
			}
			else {
				currentMotion = IDLE;
			}
		}
	}


	switch (currentMotion) {
	case AIM_UP:
		if (KEYMANAGER->IsOnceKeyDown('X')) {
			currentMotion = SHOOT_UP;
		}
		break;
	case AIM_UP_LEFT:
		if (KEYMANAGER->IsOnceKeyDown('X')) {
			currentMotion = SHOOT_UP_LEFT;
		}
		break;
	case IDLE:

		break;
	case IDLE_LEFT:

		break;
		//case IDLE_UP:
		//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
		//		currentMotion = IDLE;
		//	}
		//	if (KEYMANAGER->IsStayKeyDown('X')) {
	//		currentMotion = SHOOT_UP;
	//	}
	//	break;
	//case IDLE_UP_LEFT:
	//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
	//		currentMotion = IDLE_LEFT;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown('X')) {
	//		currentMotion = SHOOT_UP_LEFT;
	//	}
	//	break;
	//case SHOOT_UP:
	//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
	//		currentMotion = IDLE;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE_UP;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
	//		currentMotion = RUN_RIGHT;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_LEFT)) {
	//		currentMotion = RUN_LEFT;
	//	}
	//	break;
	//case SHOOT_UP_LEFT:
	//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
	//		currentMotion = IDLE_LEFT;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE_UP_LEFT;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
	//		currentMotion = RUN_RIGHT;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_LEFT)) {
	//		currentMotion = RUN_LEFT;
	//	}
	//	break;
	case IDLE_DUCK:
		if (isLeft) {
			currentMotion = IDLE_DUCK_LEFT;
		}
		//if (KEYMANAGER->IsStayKeyDown('X')) {
		//	currentMotion = SHOOT_DUCK;
		//}
		break;
	case IDLE_DUCK_LEFT:
		if (!isLeft) {
			currentMotion = IDLE_DUCK;
		}
		//if (KEYMANAGER->IsStayKeyDown('X')) {
		//	currentMotion = SHOOT_DUCK_LEFT;
		//}
		break;
	//case SHOOT_DUCK:
	//	if (KEYMANAGER->IsOnceKeyDown(VK_LEFT)) {
	//		currentMotion = SHOOT_DUCK_LEFT;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp(VK_DOWN)) {
	//		currentMotion = SHOOT_STRAIGHT;
	//	}

	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE_DUCK;
	//	}

	//	break;
	//case SHOOT_DUCK_LEFT:
	//	if (KEYMANAGER->IsOnceKeyDown(VK_RIGHT)) {
	//		currentMotion = SHOOT_DUCK;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp(VK_DOWN)) {
	//		currentMotion = SHOOT_STRAIGHT_LEFT;
	//	}

	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE_DUCK_LEFT;
	//	}
	//	break;
	case RUN_RIGHT:
		break;
	case RUN_LEFT:
		break;
	case RUN_RIGHT_SHOOT:
		//if (!KEYMANAGER->IsStayKeyDown('X')) {
		//	currentMotion = RUN_RIGHT;
		//}
		//if (!KEYMANAGER->IsStayKeyDown(VK_RIGHT)) {
		//	currentMotion =
		//}
		break;
	case RUN_LEFT_SHOOT:
	//	if (!KEYMANAGER->IsStayKeyDown('X')) {
	//		currentMotion = RUN_LEFT;
	//}
		break;
	//case SHOOT_DIAGONAL_RUN:
	//	isLeft = false;
	//	posX += 7;
	//	if (KEYMANAGER->IsOnceKeyUp(VK_RIGHT)) {
	//		currentMotion = IDLE;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = RUN_RIGHT;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
	//		currentMotion = RUN_RIGHT_SHOOT;
	//	}
	//	break;
	//case SHOOT_DIAGONAL_RUN_LEFT:
	//	isLeft = true;
	//	posX -= 7;
	//	if (KEYMANAGER->IsOnceKeyUp(VK_LEFT)) {
	//		currentMotion = IDLE_LEFT;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = RUN_LEFT;
	//	}
	//	if (KEYMANAGER->IsOnceKeyUp(VK_UP)) {
	//		currentMotion = RUN_LEFT_SHOOT;
	//	}
	//	break;
	case JUMP:
		//if (isG) {
		// abort jump on land
		//}
		if (ani[JUMP]->GetIsPlaying() == false) {
			currentDust = DUST_LAND;
			dustPosX[DUST_LAND] = posX;
			dustPosY[DUST_LAND] = posY;
			dust_ani[DUST_LAND]->Start();
			if (isLeft == true) {
				currentMotion = IDLE_LEFT;
			}
			else {
				currentMotion = IDLE;
			}
		}

		break;
	case JUMP_PARRY:
		if (ani[JUMP_PARRY]->GetIsPlaying() == false) {
			currentDust = DUST_LAND;
			dustPosX[DUST_LAND] = posX;
			dustPosY[DUST_LAND] = posY;
			dust_ani[DUST_LAND]->Start();
			if (isLeft == true) {
				currentMotion = IDLE_LEFT;
			}
			else {
				currentMotion = IDLE;

			}
		}
		break;

	//case SHOOT_STRAIGHT:
	//	isLeft = false;
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
	//		currentMotion = SHOOT_UP;
	//	}
	//	break;
	//case SHOOT_STRAIGHT_LEFT:
	//	isLeft = true;
	//	if (KEYMANAGER->IsOnceKeyUp('X')) {
	//		currentMotion = IDLE_LEFT;
	//	}
	//	if (KEYMANAGER->IsStayKeyDown(VK_UP)) {
	//		currentMotion = SHOOT_UP_LEFT;
	//	}
	//	break;
	case DUCK:
		//isLeft = false;
		if (KEYMANAGER->IsStayKeyDown('X')) {
			currentMotion = SHOOT_DUCK;
		}
		//if (KEYMANAGER->IsOnceKeyUp(VK_DOWN)) {
		//	currentMotion = IDLE;
		//}
		if (isLeft) {
			currentMotion = DUCK_LEFT;
		}
		if (ani[DUCK]->GetIsPlaying() == false) {
			currentMotion = IDLE_DUCK;
		}
		break;
	case DUCK_LEFT:
		//isLeft = true;
		if (KEYMANAGER->IsStayKeyDown('X')) {
			currentMotion = SHOOT_DUCK_LEFT;
		}
		//if (KEYMANAGER->IsOnceKeyUp(VK_DOWN)) {
		//	currentMotion = IDLE_LEFT;
		//}
		if (!isLeft) {
			currentMotion = DUCK;
		}
		if (ani[DUCK_LEFT]->GetIsPlaying() == false) {
			currentMotion = IDLE_DUCK_LEFT;
		}
		break;
	case DASH_AIR:
			posX += 8;
	
		if (ani[DASH_AIR]->GetIsPlaying() == false) {
				currentMotion = IDLE;
		}
		break;
	case DASH_AIR_LEFT:
			posX -= 8;
	
		if (ani[DASH_AIR_LEFT]->GetIsPlaying() == false) {

				currentMotion = IDLE_LEFT;

		}
		break;
	//	
	}
	
}

void Cuphead::CollisionUpdate()
{
	//if(isCollide &&
	//	objRC.left < (body.right - 10) && obj)

}

void Cuphead::DustUpdate()
{
	switch (currentDust) {
	case DUST_NULL:
		break;
	case DUST_LAND:
		if (dust_ani[DUST_LAND]->GetIsPlaying() == false) {
			currentDust = DUST_NULL;
		}
		break;
	}

	if (currentDust != DUST_NULL) {
		dust_ani[currentDust]->FrameUpdate();
	}
}

void Cuphead::D2Render(ID2D1DCRenderTarget * ap_target)
{

	img[currentMotion]->AniRender(ap_target, posX + adjustX[currentMotion], posY + adjustY[currentMotion], ani[currentMotion]);
	//img[currentMotion]->AniRenderSize(ap_target, posX + adjustX[currentMotion], posY + adjustY[currentMotion], 
	//	(ani[currentMotion]->GetFrameWidth()) * 0.9, ani[currentMotion]->GetFrameHeight() * 0.9, ani[currentMotion]);

	if (currentDust != DUST_NULL) {
		dust_img[currentDust]->AniRender(ap_target, dustPosX[currentDust] + adjustDustX[currentDust], 
			dustPosY[currentDust] + adjustDustY[currentDust], dust_ani[currentDust]);
	}

}

void Cuphead::Render(HDC hdc)
{
	Rectangle(hdc, body.left, body.top, body.right, body.bottom);
}

Cuphead::Cuphead()
{
}


Cuphead::~Cuphead()
{
}
