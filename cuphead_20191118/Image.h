#pragma once
class Animation;
class Image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,
		LOAD_FILE,
		LOAD_EMPTY,
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;		// 리소스의 고유한 아이디
		HDC		hMemDC;		// 그리기를 주관하는 핸들
		HBITMAP	hBitmap;	// 이미지 정보
		HBITMAP hOldBit;	// 이전 정보
		int		width;		// 가로 크기
		int		height;		// 세로 크기
		BYTE	loadType;	// 종류
		// 추가
		float	x;				// 위치 좌표
		float	y;				// 위치 좌표
		int		currentFrameX;	// 현재 프레임 X좌표
		int		currentFrameY;	// 현재 프레임 Y좌표
		int		maxFrameX;		// 최대 프레임 수
		int		maxFrameY;		// 최대 프레임 수
		int		frameWidth;		// 프레임 하나의 가로크기
		int		frameHeight;	// 프레임 하나의 세로크기
		RECT	boundingBox;	// 충돌박스

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_EMPTY;
			// 추가
			x = 0.0f;
			y = 0.0f;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			boundingBox = SetRect(0, 0, 0, 0);
		}
	} IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	imageInfo;
	char*			fileName;
	bool			isTrans;
	COLORREF		transColor;

	BLENDFUNCTION	blendFunc;
	LPIMAGE_INFO	blendImageInfo;

public:
	// 빈 비트맵 이미지를 만든다.
	HRESULT Init(int width, int height);

	// 리소스로부터 데이터를 읽어온다.
	HRESULT Init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	// 파일로부터 데이터를 읽어온다.
	HRESULT Init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	// 이미지 + 프레임 파일 초기화
	HRESULT Init(const char* _fileName, float _x, float _y,
		int _width, int _height, int _frameX, int _frameY,
		BOOL _trans = FALSE, COLORREF _transColor = FALSE);

	// 메모리 해제
	void Release();

	void Render(HDC hdc, int destX, int destY, float scale = 1.0f);
	void Render(HDC _hdc, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight);

	// 회전 리사이징
	BOOL RotateSizingImage(HDC hdc,
		double dblAngle,
		int ixRotateAxis, int iyRotateAxis,
		int ixDisplay, int iyDisplay,
		double dblSizeRatio = 1,
		HBITMAP hMaskBmp = NULL, int ixMask = 0, int iyMask = 0);

	// 프레임 렌더
	void FrameRender(HDC _hdc, int _destX, int _destY,
		int _currentFrameX, int _currentFrameY);

	// 애니메이션 렌더
	void AniRender(HDC _hdc, int _destX, int _destY, Animation* _ani);
	void AniAlphaRender(HDC _hdc, int _destX, int _destY, Animation* _ani, BYTE _alpha);

	// 알파 렌더
	void AlphaRender(HDC _hdc, BYTE _alpha);
	void AlphaRender(HDC _hdc, int _destX, int _destY, BYTE _alpha);

	HDC GetMemDC() { return imageInfo->hMemDC; }

	void SetCurrentFrameX(int _frameX) { imageInfo->currentFrameX = _frameX; }
	int GetCurrentFrameX() { return imageInfo->currentFrameX; }

	void SetCurrentFrameY(int _frameY) { imageInfo->currentFrameY = _frameY; }
	int GetCurrentFrameY() { return imageInfo->currentFrameY; }

	int GetMaxFrameX() { return imageInfo->maxFrameX; }
	int GetMaxFrameY() { return imageInfo->maxFrameY; }

	int GetWidth() { return imageInfo->width; }
	int GetHeight() { return imageInfo->height; }


	Image();
	~Image();
};

