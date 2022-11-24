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
	//	ID2D1Bitmap *p_bitmap;	// �̹��� ����
	//	int		width;		// ���� ũ��
	//	int		height;		// ���� ũ��
	//	// �߰�
	//	float	x;				// ��ġ ��ǥ
	//	float	y;				// ��ġ ��ǥ
	//	//int		currentFrameX;	// ���� ������ X��ǥ
	//	//int		currentFrameY;	// ���� ������ Y��ǥ
	//	//int		maxFrameX;		// �ִ� ������ ��
	//	//int		maxFrameY;		// �ִ� ������ ��
	//	//int		frameWidth;		// ������ �ϳ��� ����ũ��
	//	//int		frameHeight;	// ������ �ϳ��� ����ũ��
	//	RECT	boundingBox;	// �浹�ڽ�

	//	tagD2ImageInfo()
	//	{
	//		p_bitmap = NULL;
	//		width = 0;
	//		height = 0;
	//		// �߰�
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

	HRESULT Init();		// �ʱ�ȭ
	HRESULT Init(const wchar_t *ap_path);
	//HRESULT Init(const wchar_t *ap_path, int _frameWidth, int _frameHeight);
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ����
	virtual void Render(ID2D1DCRenderTarget *ap_target);		// ������ ���� ���

	virtual void Render(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight);
	void FrameRender(ID2D1DCRenderTarget *ap_target, int _index, int _x, int _y);
	void RenderSize(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _sourX, int _sourY, int _destWidth, int _destHeight, int _sourWidth, int _sourHeight);
	void AniRender(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, Animation* _ani);
	void AniRenderSize(ID2D1DCRenderTarget *ap_target, int _destX, int _destY, int _destWidth, int _destHeight, Animation* _ani);
	//HRESULT ConvertImage(const wchar_t *ap_path, ID2D1DCRenderTarget *_gp_render_target);
	D2Image();
	~D2Image();
};

