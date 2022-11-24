#pragma once
#include "gameNode.h"
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")

using namespace D2D1;
class D2Image : public gameNode
{
public:
	//typedef struct tagD2ImageInfo
	//{
	//	ID2D1Bitmap *p_bitmap;	// 이미지 정보
	//	int		width;		// 가로 크기
	//	int		height;		// 세로 크기
	//	// 추가
	//	float	x;				// 위치 좌표
	//	float	y;				// 위치 좌표
	//	//int		currentFrameX;	// 현재 프레임 X좌표
	//	//int		currentFrameY;	// 현재 프레임 Y좌표
	//	//int		maxFrameX;		// 최대 프레임 수
	//	//int		maxFrameY;		// 최대 프레임 수
	//	//int		frameWidth;		// 프레임 하나의 가로크기
	//	//int		frameHeight;	// 프레임 하나의 세로크기
	//	RECT	boundingBox;	// 충돌박스

	//	tagD2ImageInfo()
	//	{
	//		p_bitmap = NULL;
	//		width = 0;
	//		height = 0;
	//		// 추가
	//		x = 0.0f;
	//		y = 0.0f;
	//		//currentFrameX = 0;
	//		//currentFrameY = 0;
	//		//maxFrameX = 0;
	//		//maxFrameY = 0;
	//		//frameWidth = 0;
	//		//frameHeight = 0;
	//		boundingBox = SetRect(0, 0, 0, 0);
	//	}
	//} D2IMAGE_INFO, *PD2IMAGE_INFO;
private:
	ID2D1Bitmap *p_bitmap;

	int frameWidth;
	int frameHeight;
	int maxFrameX;
	int maxFrameY;

	//PD2IMAGE_INFO	d2ImageInfo;
	//wchar_t*			fileName;
public:

	//IWICImagingFactory *p_wic_factory;
	//IWICFormatConverter *p_converter;
	int GetWidth() { return p_bitmap->GetSize().width; }
	int GetHeight() { return p_bitmap->GetSize().height; }

	HRESULT Init();		// 초기화
	HRESULT Init(const wchar_t *ap_path);
	//HRESULT Init(const wchar_t *ap_path, int _frameWidth, int _frameHeight);
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 로직 실행
	virtual void Render(ID2D1DCRenderTarget *ap_target);		// 프레임 단위 출력

	virtual void Render(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight);
	void FrameRender(ID2D1DCRenderTarget *ap_target, int _index, int _x, int _y);
	void RenderSize(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _sourX, int _sourY, int _destWidth, int _destHeight, int _sourWidth, int _sourHeight);
	void AniRender(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, Animation* _ani);
	void AniRenderSize(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _destWidth, int _destHeight, Animation* _ani);
	//HRESULT ConvertImage(const wchar_t *ap_path, ID2D1DCRenderTarget *_gp_render_target);
	D2Image();
	~D2Image();
};

