#include "stdafx.h"
#include "gameNode.h"

HRESULT gameNode::Init()
{
	HANDLE hTimer = (HANDLE)SetTimer(g_hWnd, 1, 10, NULL);

	return S_OK;
}

void gameNode::Release()
{
	KillTimer(g_hWnd, 1);	
}

void gameNode::Update()
{
	InvalidateRect(g_hWnd, NULL, false);
}

void gameNode::Render(HDC hdc)
{
}

void gameNode::D2Render(ID2D1DCRenderTarget * ap_target)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
		g_ptMouse.x = LOWORD(lParam);
		g_ptMouse.y = HIWORD(lParam);
		break;
	case WM_CREATE:
		RECT r;
		/*GetClientRect(hWnd, &r); */// 클라이언트 영역의 좌표를 얻는다.
		r.right = WINSIZE_X;
		r.bottom = WINSIZE_Y;

		D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
			D2D1_RENDER_TARGET_TYPE_DEFAULT,
			D2D1::PixelFormat(
				DXGI_FORMAT_B8G8R8A8_UNORM,
				D2D1_ALPHA_MODE_PREMULTIPLIED),
			0,
			0,
			D2D1_RENDER_TARGET_USAGE_NONE,
			D2D1_FEATURE_LEVEL_DEFAULT
		);

		gp_factory->CreateDCRenderTarget(&props, &gp_dcrendertarget);

		gp_factory->CreateDCRenderTarget(&props, &gp_dc_loading);
		// 지정한 윈도우의 클라이언트 영역에 그림을 그리기위한
		// Render Target 을 생성한다.
		//gp_factory->CreateHwndRenderTarget(RenderTargetProperties(),
		//	HwndRenderTargetProperties(hWnd, SizeU(r.right, r.bottom)),
		//	&gp_render_target);

		return 0;
	case WM_TIMER:
		//Update();
		//this->Update();
		break;
	case WM_PAINT:
	{



		//PAINTSTRUCT ps;
		//HDC hdc = BeginPaint(hWnd, &ps);

		//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		////(*this).
		////this->Render(hdc);
		//EndPaint(hWnd, &ps);
	
	}
	break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

