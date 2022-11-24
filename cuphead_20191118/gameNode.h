#pragma once
// Direct2D
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")

using namespace D2D1;
class gameNode
{
public:

	
	virtual HRESULT Init();		// 초기화
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render(HDC hdc);		// 프레임 단위 출력
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	LRESULT MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	gameNode();
	~gameNode();

};

