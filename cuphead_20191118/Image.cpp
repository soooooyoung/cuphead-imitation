#include "stdafx.h"
#include "Image.h"
#include "Animation.h"

#pragma comment (lib, "msimg32.lib")

HRESULT Image::Init(int width, int height)
{
	if (imageInfo != NULL)
	{
		Release();
	}

	HDC hdc = GetDC(g_hWnd);
	// 멤버 변수 초기화
	imageInfo = new IMAGE_INFO;
	imageInfo->resID = 0;
	imageInfo->loadType = LOAD_EMPTY;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;

	fileName = NULL;
	isTrans = false;
	transColor = RGB(0, 0, 0);

	// 비트맵 생성 실패시 예외처리
	if (imageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	// 알파 블렌드
	blendFunc.BlendFlags = 0;
	blendFunc.AlphaFormat = 0;
	blendFunc.BlendOp = AC_SRC_OVER;

	blendImageInfo = new IMAGE_INFO;
	blendImageInfo->resID = 0;
	blendImageInfo->loadType = LOAD_EMPTY;
	blendImageInfo->hMemDC = CreateCompatibleDC(hdc);
	blendImageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	blendImageInfo->hOldBit = (HBITMAP)SelectObject(blendImageInfo->hMemDC, blendImageInfo->hBitmap);
	blendImageInfo->width = width;
	blendImageInfo->height = height;

	// 비트맵 생성 실패시 예외처리
	if (blendImageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

HRESULT Image::Init(const DWORD resID, int width, int height, BOOL trans, COLORREF transColor)
{
	if (imageInfo != NULL)
	{
		Release();
	}

	HDC hdc = GetDC(g_hWnd);
	// 멤버 변수 초기화
	imageInfo = new IMAGE_INFO;
	imageInfo->resID = resID;
	imageInfo->loadType = LOAD_RESOURCE;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;

	fileName = NULL;
	isTrans = false;
	transColor = RGB(0, 0, 0);

	// 비트맵 생성 실패시 예외처리
	if (imageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	// 알파 블렌드
	blendFunc.BlendFlags = 0;
	blendFunc.AlphaFormat = 0;
	blendFunc.BlendOp = AC_SRC_OVER;

	blendImageInfo = new IMAGE_INFO;
	blendImageInfo->resID = resID;
	blendImageInfo->loadType = LOAD_RESOURCE;
	blendImageInfo->hMemDC = CreateCompatibleDC(hdc);
	blendImageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	blendImageInfo->hOldBit = (HBITMAP)SelectObject(blendImageInfo->hMemDC, blendImageInfo->hBitmap);
	blendImageInfo->width = width;
	blendImageInfo->height = height;

	if (blendImageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

HRESULT Image::Init(const char * _fileName, int width, int height, BOOL trans, COLORREF _transColor)
{
	if (imageInfo != NULL)
	{
		Release();
	}

	HDC hdc = GetDC(g_hWnd);
	// 멤버 변수 초기화
	imageInfo = new IMAGE_INFO;
	imageInfo->resID = 0;
	imageInfo->loadType = LOAD_FILE;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = (HBITMAP)LoadImage(
		g_hInst, _fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;

	// 파일 경로 이름 복사
	int length = strlen(_fileName);
	fileName = new char[length + 1];
	strcpy_s(fileName, length + 1, _fileName);

	isTrans = trans;
	transColor = _transColor;

	// 비트맵 생성 실패시 예외처리
	if (imageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	// 알파 블렌드
	blendFunc.BlendFlags = 0;
	blendFunc.AlphaFormat = 0;
	blendFunc.BlendOp = AC_SRC_OVER;

	blendImageInfo = new IMAGE_INFO;
	blendImageInfo->resID = 0;
	blendImageInfo->loadType = LOAD_FILE;
	blendImageInfo->hMemDC = CreateCompatibleDC(hdc);
	blendImageInfo->hBitmap = (HBITMAP)LoadImage(
		g_hInst, _fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	blendImageInfo->hOldBit = (HBITMAP)SelectObject(blendImageInfo->hMemDC, blendImageInfo->hBitmap);
	blendImageInfo->width = width;
	blendImageInfo->height = height;

	ReleaseDC(g_hWnd, hdc);

	// 비트맵 생성 실패시 예외처리
	if (blendImageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const char * _fileName, float _x, float _y, int _width, int _height, int _frameX, int _frameY, BOOL _trans, COLORREF _transColor)
{
	if (imageInfo != NULL)
	{
		Release();
	}

	HDC hdc = GetDC(g_hWnd);
	// 멤버 변수 초기화
	imageInfo = new IMAGE_INFO;
	imageInfo->resID = 0;
	imageInfo->loadType = LOAD_FILE;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = (HBITMAP)LoadImage(
		g_hInst, _fileName, IMAGE_BITMAP, _width, _height, LR_LOADFROMFILE);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = _width;
	imageInfo->height = _height;
	// 추가
	imageInfo->x = _x - (_width / 2);
	imageInfo->y = _y - (_height / 2);
	imageInfo->currentFrameX = 0;
	imageInfo->currentFrameY = 0;
	imageInfo->frameWidth = _width / _frameX;
	imageInfo->frameHeight = _height / _frameY;
	imageInfo->maxFrameX = _frameX - 1;
	imageInfo->maxFrameY = _frameY - 1;


	// 파일 경로 이름 복사
	int length = strlen(_fileName);
	fileName = new char[length + 1];
	strcpy_s(fileName, length + 1, _fileName);

	isTrans = _trans;
	transColor = _transColor;

	// 비트맵 생성 실패시 예외처리
	if (imageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	// 알파 블렌드
	blendFunc.BlendFlags = 0;
	blendFunc.AlphaFormat = 0;
	blendFunc.BlendOp = AC_SRC_OVER;

	blendImageInfo = new IMAGE_INFO;
	blendImageInfo->resID = 0;
	blendImageInfo->loadType = LOAD_FILE;
	blendImageInfo->hMemDC = CreateCompatibleDC(hdc);
	blendImageInfo->hBitmap = (HBITMAP)LoadImage(
		g_hInst, _fileName, IMAGE_BITMAP, _width, _height, LR_LOADFROMFILE);
	blendImageInfo->hOldBit = (HBITMAP)SelectObject(blendImageInfo->hMemDC, blendImageInfo->hBitmap);
	blendImageInfo->width = _width;
	blendImageInfo->height = _height;
	// 추가
	blendImageInfo->x = _x - (_width / 2);
	blendImageInfo->y = _y - (_height / 2);
	blendImageInfo->currentFrameX = 0;
	blendImageInfo->currentFrameY = 0;
	blendImageInfo->frameWidth = _width / _frameX;
	blendImageInfo->frameHeight = _height / _frameY;
	blendImageInfo->maxFrameX = _frameX - 1;
	blendImageInfo->maxFrameY = _frameY - 1;

	ReleaseDC(g_hWnd, hdc);

	// 비트맵 생성 실패시 예외처리
	if (blendImageInfo->hBitmap == 0)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDC, imageInfo->hOldBit);
		DeleteObject(imageInfo->hBitmap);
		DeleteDC(imageInfo->hMemDC);

		SAFE_DELETE(fileName);
		SAFE_DELETE(imageInfo);
	}

	if (blendImageInfo)
	{
		SelectObject(blendImageInfo->hMemDC, blendImageInfo->hOldBit);
		DeleteObject(blendImageInfo->hBitmap);
		DeleteDC(blendImageInfo->hMemDC);

		//SAFE_DELETE(fileName);
		SAFE_DELETE(blendImageInfo);
	}
}

void Image::Render(HDC hdc, int destX, int destY, float scale/* = 1.0f*/)
{
	if (isTrans)
	{
		GdiTransparentBlt(hdc,
			destX, destY,
			imageInfo->width * scale,
			imageInfo->height * scale,
			imageInfo->hMemDC,
			0, 0,
			imageInfo->width,
			imageInfo->height,
			transColor);
	}
	else
	{
		BitBlt(
			hdc,						// 목적지 DC
			destX, destY,				// 목적지의 어디에 그릴건가

			imageInfo->width,
			imageInfo->height,			// 원본 DC에서 얼만큼 가져올 것인가
			imageInfo->hMemDC,			// 원본 DC			
			0, 0,						// 어디서부터 그릴건가
			SRCCOPY);					// 어떻게 복사할 것인가
	}
}

void Image::Render(HDC _hdc, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight)
{
	if (isTrans)
	{
		GdiTransparentBlt(_hdc,
			_destX, _destY,
			_sourWidth,
			_sourHeight,

			imageInfo->hMemDC,
			_sourX, _sourY,
			_sourWidth,
			_sourHeight,
			transColor);
	}
	else
	{
		BitBlt(
			_hdc,						// 목적지 DC
			_destX, _destY,				// 목적지의 어디에 그릴건가
			_sourWidth,
			_sourHeight,				// 원본 DC에서 얼만큼 가져올 것인가

			imageInfo->hMemDC,			// 원본 DC			
			_sourX, _sourY,				// 어디서부터 그릴건가
			SRCCOPY);					// 어떻게 복사할 것인가
	}
}

BOOL Image::RotateSizingImage(HDC hdc,
		        double dblAngle,
		        int ixRotateAxis, int iyRotateAxis,
		        int ixDisplay, int iyDisplay,
		        double dblSizeRatio/* = 1*/,
		        HBITMAP hMaskBmp/* = NULL*/, int ixMask/* = 0*/, int iyMask/* = 0*/)
{
	int i;
	BITMAP bm;
	GetObject(imageInfo->hBitmap, sizeof(BITMAP), &bm);
	POINT apt[3] = { 0 };
	double dblWidth = (double)bm.bmWidth*dblSizeRatio;
	double dblHeight = (double)bm.bmHeight*dblSizeRatio;
	double ixRotate = (int)((double)ixRotateAxis*dblSizeRatio); // 크기가 변하는 것 고려
	double iyRotate = (int)((double)iyRotateAxis*dblSizeRatio);
	//const double pi = 3.14159265358979323846;
	
	
	double dblRadian, dblx, dbly, dblxDest, dblyDest, cosVal, sinVal;
	dblRadian = dblAngle * PI / 180.0f;
	cosVal = cos(dblRadian), sinVal = sin(dblRadian);
	
	// 1. 회전축을 기준으로 상대좌표를 구하고
	// 2. 회전후 위치좌표(상대좌표)를 얻은 후
	// 3. 얻은 값을 원래의 좌표에 적용.
	for (i = 0; i < 3; i++)
	{
		if (i == 0) { dblx = -ixRotate, dbly = -iyRotate; }    // left up  꼭지점 부분
		else if (i == 1) { dblx = dblWidth - ixRotate, dbly = -iyRotate; }  // right up 꼭지점 부분
		else if (i == 2) { dblx = -ixRotate, dbly = dblHeight - iyRotate; } // left low 꼭지점 부분
		dblxDest = dblx * cosVal - dbly * sinVal;
		dblyDest = dblx * sinVal + dbly * cosVal;
		dblxDest += ixRotate, dblyDest += iyRotate;
		apt[i].x = ixDisplay - (long)ixRotate + (long)dblxDest;
		apt[i].y = iyDisplay - (long)iyRotate + (long)dblyDest;
	}		

	BOOL iRes = PlgBlt(hdc, apt, imageInfo->hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, hMaskBmp, ixMask, iyMask);

	return iRes;
}

void Image::FrameRender(HDC _hdc, int _destX, int _destY, int _currentFrameX, int _currentFrameY)
{
	imageInfo->currentFrameX = _currentFrameX;
	imageInfo->currentFrameY = _currentFrameY;

	if (_currentFrameX > imageInfo->maxFrameX)
		imageInfo->currentFrameX = imageInfo->maxFrameX;
	if (_currentFrameY > imageInfo->maxFrameY)
		imageInfo->currentFrameY = imageInfo->maxFrameY;

	if (isTrans)
	{
		GdiTransparentBlt(_hdc,
			_destX, _destY,
			imageInfo->frameWidth,
			imageInfo->frameHeight,
			imageInfo->hMemDC,
			imageInfo->frameWidth * imageInfo->currentFrameX,
			imageInfo->frameHeight * imageInfo->currentFrameY,
			imageInfo->frameWidth,
			imageInfo->frameHeight,
			transColor);
	}
	else
	{
		BitBlt(_hdc, _destX, _destY, imageInfo->frameWidth, imageInfo->frameHeight,
			imageInfo->hMemDC,
			imageInfo->frameWidth * imageInfo->currentFrameX,
			imageInfo->frameHeight * imageInfo->currentFrameY,
			SRCCOPY);
	}
}

void Image::AniRender(HDC _hdc, int _destX, int _destY, Animation * _ani)
{
	Render(
		_hdc, _destX, _destY,
		_ani->GetFramePos().x, _ani->GetFramePos().y,
		_ani->GetFrameWidth(), _ani->GetFrameHeight());
}

void Image::AniAlphaRender(HDC _hdc, int _destX, int _destY, Animation * _ani, BYTE _alpha)
{
}

void Image::AlphaRender(HDC _hdc, BYTE _alpha)
{	
	// 투명도
	blendFunc.SourceConstantAlpha = _alpha;

	if (isTrans)
	{
		// 1. 출력해야 되는 DC에 그려져 있는 내용을 Blend에 그린다.
		BitBlt(blendImageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height,
			_hdc, imageInfo->x, imageInfo->y, SRCCOPY);

		// 2. 출력할 이미지를 Blend에 지정한 색상을 제외하고 그린다.
		GdiTransparentBlt(blendImageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height,
			imageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height, transColor);

		// 3. Blend이미지를 출력해야 되는 DC에 그린다.
		AlphaBlend(_hdc, imageInfo->x, imageInfo->y, imageInfo->width, imageInfo->height,
			blendImageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height, blendFunc);
	}
	else
	{
		AlphaBlend(_hdc, imageInfo->x, imageInfo->y, imageInfo->width, imageInfo->height,
			blendImageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height, blendFunc);
	}
}

void Image::AlphaRender(HDC _hdc, int _destX, int _destY, BYTE _alpha)
{
	// 투명도
	blendFunc.SourceConstantAlpha = _alpha;

	AlphaBlend(_hdc, _destX, _destY, imageInfo->width, imageInfo->height,
		blendImageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height, blendFunc);
}

Image::Image()
{
}


Image::~Image()
{
}
