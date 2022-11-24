#include "stdafx.h"
#include "D2Image.h"
#include "Animation.h"

HRESULT D2Image::Init(const wchar_t * ap_path)
{
	//LoadMyImage(gp_render_target, L"test.png");

	if (p_bitmap != NULL) {	// ������ ���� �̹����������� �ش��̹����� �����Ѵ�.
		p_bitmap->Release();
		p_bitmap = NULL;

	}


	// ���� ��� �̸� ����
	//int length = strlen(ap_path);
	//fileName = new wchar_t[length + 1];
	//strcpy_s(fileName, length + 1, ap_path);

	//WIC(Windows Imaging Component)���� ��ü�� �����ϱ� ���� Factory ��ü ����
	IWICImagingFactory *p_wic_factory;
	// WIC��ü�� �����ϱ� ���� Factory ��ü�� �����Ѵ�.
	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&p_wic_factory));

	IWICBitmapDecoder *p_decoder;		// ����� �̹����� ������ ��ü
	IWICBitmapFrameDecode *p_frame;		// Ư�� �׸��� ������ ��ü
	IWICFormatConverter *p_converter;	// �̹��� ��ȯ ��ü

	//WIC�� Factory ��ü�� ����Ͽ� �̹��� ���� ������ ���� ��ü�� ����
	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
		// ������ �����ϴ� �̹��� �߿��� ù��° �̹����� �����Ѵ�.
		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
			// IWICBitmap ������ ��Ʈ���� ID2D1Bitmap �������� �����ϱ� ���� ��ü ����
			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
				// ���õ� �׸��� � ������ ��Ʈ������ ��ȯ�Ұ����� �����Ѵ�.
				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
					// IWICBitmap ������ ��Ʈ������ Id2d1bitmap ��ü�� �����Ѵ�
					if (S_OK == gp_dcrendertarget->CreateBitmapFromWicBitmap(p_converter, NULL, &p_bitmap)) {
					}
				}
				p_converter->Release();
			}
			p_frame->Release();
		}
		p_decoder->Release();
	}
	p_wic_factory->Release();

	// �������н� ����ó��
	if (p_bitmap == NULL) {
		Release();
		return E_FAIL;
	}

	return S_OK;
}
HRESULT D2Image::Init()
{
	return S_OK;
}
// Framerender ����
//HRESULT D2Image::Init(const wchar_t * ap_path, int _frameWidth, int _frameHeight)
//{
//	if (p_bitmap != NULL) {	// ������ ���� �̹����������� �ش��̹����� �����Ѵ�.
//		p_bitmap->Release();
//		p_bitmap = NULL;
//
//	}
//
//	// ���� ��� �̸� ����
//	//int length = strlen(ap_path);
//	//fileName = new wchar_t[length + 1];
//	//strcpy_s(fileName, length + 1, ap_path);
//
//	//WIC(Windows Imaging Component)���� ��ü�� �����ϱ� ���� Factory ��ü ����
//	IWICImagingFactory *p_wic_factory;
//	// WIC��ü�� �����ϱ� ���� Factory ��ü�� �����Ѵ�.
//	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
//		IID_PPV_ARGS(&p_wic_factory));
//
//	IWICBitmapDecoder *p_decoder;		// ����� �̹����� ������ ��ü
//	IWICBitmapFrameDecode *p_frame;		// Ư�� �׸��� ������ ��ü
//	IWICFormatConverter *p_converter;	// �̹��� ��ȯ ��ü
//
//	//WIC�� Factory ��ü�� ����Ͽ� �̹��� ���� ������ ���� ��ü�� ����
//	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
//		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
//		// ������ �����ϴ� �̹��� �߿��� ù��° �̹����� �����Ѵ�.
//		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
//			// IWICBitmap ������ ��Ʈ���� ID2D1Bitmap �������� �����ϱ� ���� ��ü ����
//			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
//				// ���õ� �׸��� � ������ ��Ʈ������ ��ȯ�Ұ����� �����Ѵ�.
//				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
//					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
//					// IWICBitmap ������ ��Ʈ������ Id2d1bitmap ��ü�� �����Ѵ�
//					if (S_OK == gp_render_target->CreateBitmapFromWicBitmap(p_converter, NULL, &p_bitmap)) {
//					}
//				}
//				p_converter->Release();
//			}
//			p_frame->Release();
//		}
//		p_decoder->Release();
//	}
//	p_wic_factory->Release();
//
//	// �������н� ����ó��
//	if (p_bitmap == NULL) {
//		Release();
//		return E_FAIL;
//	}
//
//	// ��� ���� �ʱ�ȭ
//	frameWidth = _frameWidth;
//	frameHeight = _frameHeight;
//	maxFrameX = p_bitmap->GetSize().width / frameWidth;
//	maxFrameY = p_bitmap->GetSize().width / frameHeight;
//
//	return S_OK;
//}

void D2Image::Release()
{
	if (p_bitmap) {
		p_bitmap->Release();
	}
}

void D2Image::Update()
{
}

void D2Image::Render(ID2D1DCRenderTarget *ap_target)
{
	//Direct2D�� Render Target�� ����ؼ� �׸� �׸��⸦ �����Ѵ�.
		// ������
		if (p_bitmap != NULL) {

			D2D1_RECT_F image_rect;
			image_rect.left = 0;
			image_rect.top = 0;
			image_rect.right = p_bitmap->GetSize().width;
			image_rect.bottom = p_bitmap->GetSize().height;
			ap_target->DrawBitmap(p_bitmap, &image_rect,
				1.0f,																			// Opacity
/*				D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,*/ // ���Ϻ���
				D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, // �̹����� �� �ε巴��
				&image_rect);
		}
		else {
		/*	ap_target->Clear(ColorF(0.0f, 0.8f, 1.0f));*/
		}

}

// �ִϸ��̼� draw
void D2Image::Render(ID2D1DCRenderTarget * ap_target, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight)
{
	D2D_RECT_F dest = D2D1::RectF(
		_destX, _destY, _destX + _sourWidth, _destY + _sourHeight);

	D2D_RECT_F src = D2D1::RectF(
		_sourX, _sourY, _sourX + _sourWidth, _sourY + _sourHeight);

	if (p_bitmap != NULL) {
		ap_target->DrawBitmap(p_bitmap, &dest,
			1.0f,																				// Opacity
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, // ���Ϻ���
			/*D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,*/ // �̹����� �� �ε巴��
			&src);
	}
}

void D2Image::FrameRender(ID2D1DCRenderTarget * ap_target, int _index, int _x, int _y)
{
	D2D_RECT_F src = D2D1::RectF(
		(float)((_index % maxFrameX) * frameWidth),
		(float)((_index / maxFrameX) * frameHeight),
		(float)((_index % maxFrameX) * frameWidth) - frameWidth,
		(float)((_index / maxFrameX) * frameHeight) + frameHeight);

	D2D_RECT_F dest = D2D1::RectF(
		_x, _y, _x + frameWidth, _y + frameHeight);

	if (p_bitmap != NULL) {
		ap_target->DrawBitmap(p_bitmap, &dest,
			1.0f,																				// Opacity
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, // ���Ϻ���
			/*D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,*/ // �̹����� �� �ε巴��
			&src);
	}

}

void D2Image::RenderSize(ID2D1DCRenderTarget * ap_target, int _destX, int _destY, int _sourX, int _sourY, int _destWidth, int _destHeight, int _sourWidth, int _sourHeight)
{
	D2D_RECT_F dest = D2D1::RectF(
		_destX, _destY, _destX + _destWidth, _destY + _destHeight);

	D2D_RECT_F src = D2D1::RectF(
		_sourX, _sourY, _sourX + _sourWidth, _sourY + _sourHeight);

	if (p_bitmap != NULL) {
		ap_target->DrawBitmap(p_bitmap, &dest,
			1.0f,																				// Opacity
/*			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,*/ // ���Ϻ���
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, // �̹����� �� �ε巴��
			&src);
	}
}

void D2Image::AniRender(ID2D1DCRenderTarget * ap_target, int _destX, int _destY, Animation * _ani)
{
	Render(
		ap_target, _destX, _destY,
		_ani->GetFramePos().x, _ani->GetFramePos().y,
		_ani->GetFrameWidth(), _ani->GetFrameHeight());
}

void D2Image::AniRenderSize(ID2D1DCRenderTarget * ap_target, int _destX, int _destY, int _destWidth, int _destHeight, Animation * _ani)
{
	RenderSize(
		ap_target, _destX, _destY,
		_ani->GetFramePos().x, _ani->GetFramePos().y, _destWidth, _destHeight,
		_ani->GetFrameWidth(), _ani->GetFrameHeight());

}

//
//
//HRESULT D2Image::ConvertImage(const wchar_t *ap_path, ID2D1DCRenderTarget *_gp_render_target)
//{
//
//	if (p_bitmap != NULL) {	// ������ ���� �̹����������� �ش��̹����� �����Ѵ�.
//		p_bitmap->Release();
//		p_bitmap = NULL;
//
//	}
//
//
//	// ���� ��� �̸� ����
//	//int length = strlen(ap_path);
//	//fileName = new wchar_t[length + 1];
//	//strcpy_s(fileName, length + 1, ap_path);
//
//	//WIC(Windows Imaging Component)���� ��ü�� �����ϱ� ���� Factory ��ü ����
//	IWICImagingFactory *p_wic_factory;
//	// WIC��ü�� �����ϱ� ���� Factory ��ü�� �����Ѵ�.
//	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
//		IID_PPV_ARGS(&p_wic_factory));
//
//	IWICBitmapDecoder *p_decoder;		// ����� �̹����� ������ ��ü
//	IWICBitmapFrameDecode *p_frame;		// Ư�� �׸��� ������ ��ü
//	IWICFormatConverter *p_converter;	// �̹��� ��ȯ ��ü
//
//	//WIC�� Factory ��ü�� ����Ͽ� �̹��� ���� ������ ���� ��ü�� ����
//	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
//		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
//		// ������ �����ϴ� �̹��� �߿��� ù��° �̹����� �����Ѵ�.
//		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
//			// IWICBitmap ������ ��Ʈ���� ID2D1Bitmap �������� �����ϱ� ���� ��ü ����
//			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
//				// ���õ� �׸��� � ������ ��Ʈ������ ��ȯ�Ұ����� �����Ѵ�.
//				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
//					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
//					// IWICBitmap ������ ��Ʈ������ Id2d1bitmap ��ü�� �����Ѵ�
//					if (S_OK == _gp_render_target->CreateBitmapFromWicBitmap(p_converter, NULL, &p_bitmap)) {
//					}
//				}
//				p_converter->Release();
//			}
//			p_frame->Release();
//		}
//		p_decoder->Release();
//	}
//	p_wic_factory->Release();
//
//	// �������н� ����ó��
//	if (p_bitmap == NULL) {
//		Release();
//		return E_FAIL;
//	}
//
//	return S_OK;
//}

D2Image::D2Image()
{
}


D2Image::~D2Image()
{
}
