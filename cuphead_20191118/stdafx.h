// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <iostream>

// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
// Singleton 관련 헤더
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "Image.h"
#include "ImageManager.h"
#include "TimerManager.h"
#include "txtData.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "D2Image.h"
#include "D2ImageManager.h"

// 컵헤드!
#include "Cuphead.h"

// Direct2D
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")

using namespace D2D1;

#define RANDOMFUNC	randomFunction::GetSingleton()
#define KEYMANAGER	keyManager::GetSingleton()
#define IMAGEMANAGER	ImageManager::GetSingleton()
#define TIMERMANAGER	TimerManager::GetSingleton()
#define TXTDATAMANAGER	txtData::GetSingleton()
#define SOUNDMANAGER	SoundManager::GetSingleton()
#define SCENEMANAGER	SceneManager::GetSingleton()
#define D2IMAGEMANAGER	D2ImageManager::GetSingleton()

#define WINSTYLE	WS_CAPTION | WS_SYSMENU
#define WINSTART_X	100
#define WINSTART_Y	100
#define WINSIZE_X	1536	// 1536
#define WINSIZE_Y	864		// 864

#define PI			3.141592

#define SAFE_DELETE(p)			{ if(p)	{ delete p;		p = NULL; } }
#define SAFE_DELETE_ARRAY(p)	{ if(p)	{ delete[] p;	p = NULL; } }
#define DEGREE_TO_RADIAN(x)		x * PI / 180
#define RADIAN_TO_DEGREE(x)		(int)(x * 180 / PI)

////cuphead MOTION
//enum CupheadMotion {
//	IDLE,
//	RUN_RIGHT,
//	MOTIONEND
//};

extern POINT g_ptMouse;

extern HWND g_hWnd;
extern HINSTANCE g_hInst;

//Direct2D를 구성하는 각종 객체를 생성하는 객체
extern ID2D1Factory *gp_factory;
//extern IWICImagingFactory *gp_wic_factory;
//extern IWICImagingFactory *gp_wic_factory2;
extern ID2D1DCRenderTarget *gp_dcrendertarget;
extern ID2D1DCRenderTarget *gp_dc_loading;
//Direct2D에서 윈도우의 클라이언트 영역에 그림을 그릴객체
//extern ID2D1HwndRenderTarget *gp_render_target;
//extern ID2D1HwndRenderTarget *gp_render_target_loading;
////// Direct2D의 기본 render target에서 사용가능한 기본 비트맵 객체
//extern ID2D1Bitmap *gp_bitmap;

