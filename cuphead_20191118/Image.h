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
		DWORD	resID;		// ���ҽ��� ������ ���̵�
		HDC		hMemDC;		// �׸��⸦ �ְ��ϴ� �ڵ�
		HBITMAP	hBitmap;	// �̹��� ����
		HBITMAP hOldBit;	// ���� ����
		int		width;		// ���� ũ��
		int		height;		// ���� ũ��
		BYTE	loadType;	// ����
		// �߰�
		float	x;				// ��ġ ��ǥ
		float	y;				// ��ġ ��ǥ
		int		currentFrameX;	// ���� ������ X��ǥ
		int		currentFrameY;	// ���� ������ Y��ǥ
		int		maxFrameX;		// �ִ� ������ ��
		int		maxFrameY;		// �ִ� ������ ��
		int		frameWidth;		// ������ �ϳ��� ����ũ��
		int		frameHeight;	// ������ �ϳ��� ����ũ��
		RECT	boundingBox;	// �浹�ڽ�

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_EMPTY;
			// �߰�
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
	// �� ��Ʈ�� �̹����� �����.
	HRESULT Init(int width, int height);

	// ���ҽ��κ��� �����͸� �о�´�.
	HRESULT Init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	// ���Ϸκ��� �����͸� �о�´�.
	HRESULT Init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	// �̹��� + ������ ���� �ʱ�ȭ
	HRESULT Init(const char* _fileName, float _x, float _y,
		int _width, int _height, int _frameX, int _frameY,
		BOOL _trans = FALSE, COLORREF _transColor = FALSE);

	// �޸� ����
	void Release();

	void Render(HDC hdc, int destX, int destY, float scale = 1.0f);
	void Render(HDC _hdc, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight);

	// ȸ�� ������¡
	BOOL RotateSizingImage(HDC hdc,
		double dblAngle,
		int ixRotateAxis, int iyRotateAxis,
		int ixDisplay, int iyDisplay,
		double dblSizeRatio = 1,
		HBITMAP hMaskBmp = NULL, int ixMask = 0, int iyMask = 0);

	// ������ ����
	void FrameRender(HDC _hdc, int _destX, int _destY,
		int _currentFrameX, int _currentFrameY);

	// �ִϸ��̼� ����
	void AniRender(HDC _hdc, int _destX, int _destY, Animation* _ani);
	void AniAlphaRender(HDC _hdc, int _destX, int _destY, Animation* _ani, BYTE _alpha);

	// ���� ����
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

