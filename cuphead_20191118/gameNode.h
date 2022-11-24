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

	
	virtual HRESULT Init();		// �ʱ�ȭ
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void Render(HDC hdc);		// ������ ���� ���
	virtual void D2Render(ID2D1DCRenderTarget *ap_target);
	LRESULT MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	gameNode();
	~gameNode();

};

