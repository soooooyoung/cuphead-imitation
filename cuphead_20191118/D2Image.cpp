#include "stdafx.h"
#include "D2Image.h"
#include "Animation.h"

HRESULT D2Image::Init(const wchar_t * ap_path)
{
	//LoadMyImage(gp_render_target, L"test.png");

	if (p_bitmap != NULL) {	// 기존에 읽은 이미지가있으면 해당이미지를 제거한다.
		p_bitmap->Release();
		p_bitmap = NULL;

	}


	// 파일 경로 이름 복사
	//int length = strlen(ap_path);
	//fileName = new wchar_t[length + 1];
	//strcpy_s(fileName, length + 1, ap_path);

	//WIC(Windows Imaging Component)관련 객체를 생성하기 위한 Factory 객체 선언
	IWICImagingFactory *p_wic_factory;
	// WIC객체를 생성하기 위한 Factory 객체를 생성한다.
	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&p_wic_factory));

	IWICBitmapDecoder *p_decoder;		// 압축된 이미지를 해제할 객체
	IWICBitmapFrameDecode *p_frame;		// 특정 그림을 선택한 객체
	IWICFormatConverter *p_converter;	// 이미지 변환 객체

	//WIC용 Factory 객체를 사용하여 이미지 압축 해제를 위한 객체를 생성
	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
		// 파일을 구성하는 이미지 중에서 첫번째 이미지를 선택한다.
		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
			// IWICBitmap 형식의 비트맵을 ID2D1Bitmap 형식으로 변한하기 위한 객체 생성
			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
				// 선택된 그림을 어떤 형식의 비트맵으로 변환할것인지 설정한다.
				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
					// IWICBitmap 형식의 비트맵으로 Id2d1bitmap 객체를 생성한다
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

	// 생성실패시 예외처리
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
// Framerender 전용
//HRESULT D2Image::Init(const wchar_t * ap_path, int _frameWidth, int _frameHeight)
//{
//	if (p_bitmap != NULL) {	// 기존에 읽은 이미지가있으면 해당이미지를 제거한다.
//		p_bitmap->Release();
//		p_bitmap = NULL;
//
//	}
//
//	// 파일 경로 이름 복사
//	//int length = strlen(ap_path);
//	//fileName = new wchar_t[length + 1];
//	//strcpy_s(fileName, length + 1, ap_path);
//
//	//WIC(Windows Imaging Component)관련 객체를 생성하기 위한 Factory 객체 선언
//	IWICImagingFactory *p_wic_factory;
//	// WIC객체를 생성하기 위한 Factory 객체를 생성한다.
//	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
//		IID_PPV_ARGS(&p_wic_factory));
//
//	IWICBitmapDecoder *p_decoder;		// 압축된 이미지를 해제할 객체
//	IWICBitmapFrameDecode *p_frame;		// 특정 그림을 선택한 객체
//	IWICFormatConverter *p_converter;	// 이미지 변환 객체
//
//	//WIC용 Factory 객체를 사용하여 이미지 압축 해제를 위한 객체를 생성
//	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
//		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
//		// 파일을 구성하는 이미지 중에서 첫번째 이미지를 선택한다.
//		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
//			// IWICBitmap 형식의 비트맵을 ID2D1Bitmap 형식으로 변한하기 위한 객체 생성
//			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
//				// 선택된 그림을 어떤 형식의 비트맵으로 변환할것인지 설정한다.
//				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
//					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
//					// IWICBitmap 형식의 비트맵으로 Id2d1bitmap 객체를 생성한다
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
//	// 생성실패시 예외처리
//	if (p_bitmap == NULL) {
//		Release();
//		return E_FAIL;
//	}
//
//	// 멤버 변수 초기화
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
	//Direct2D의 Render Target을 사용해서 그림 그리기를 시작한다.
		// 색변경
		if (p_bitmap != NULL) {

			D2D1_RECT_F image_rect;
			image_rect.left = 0;
			image_rect.top = 0;
			image_rect.right = p_bitmap->GetSize().width;
			image_rect.bottom = p_bitmap->GetSize().height;
			ap_target->DrawBitmap(p_bitmap, &image_rect,
				1.0f,																			// Opacity
/*				D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,*/ // 제일빠름
				D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, // 이미지를 더 부드럽게
				&image_rect);
		}
		else {
		/*	ap_target->Clear(ColorF(0.0f, 0.8f, 1.0f));*/
		}

}

// 애니메이션 draw
void D2Image::Render(ID2D1DCRenderTarget * ap_target, int _destX, int _destY, int _sourX, int _sourY, int _sourWidth, int _sourHeight)
{
	D2D_RECT_F dest = D2D1::RectF(
		_destX, _destY, _destX + _sourWidth, _destY + _sourHeight);

	D2D_RECT_F src = D2D1::RectF(
		_sourX, _sourY, _sourX + _sourWidth, _sourY + _sourHeight);

	if (p_bitmap != NULL) {
		ap_target->DrawBitmap(p_bitmap, &dest,
			1.0f,																				// Opacity
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, // 제일빠름
			/*D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,*/ // 이미지를 더 부드럽게
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
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, // 제일빠름
			/*D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,*/ // 이미지를 더 부드럽게
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
/*			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,*/ // 제일빠름
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, // 이미지를 더 부드럽게
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
//	if (p_bitmap != NULL) {	// 기존에 읽은 이미지가있으면 해당이미지를 제거한다.
//		p_bitmap->Release();
//		p_bitmap = NULL;
//
//	}
//
//
//	// 파일 경로 이름 복사
//	//int length = strlen(ap_path);
//	//fileName = new wchar_t[length + 1];
//	//strcpy_s(fileName, length + 1, ap_path);
//
//	//WIC(Windows Imaging Component)관련 객체를 생성하기 위한 Factory 객체 선언
//	IWICImagingFactory *p_wic_factory;
//	// WIC객체를 생성하기 위한 Factory 객체를 생성한다.
//	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER,
//		IID_PPV_ARGS(&p_wic_factory));
//
//	IWICBitmapDecoder *p_decoder;		// 압축된 이미지를 해제할 객체
//	IWICBitmapFrameDecode *p_frame;		// 특정 그림을 선택한 객체
//	IWICFormatConverter *p_converter;	// 이미지 변환 객체
//
//	//WIC용 Factory 객체를 사용하여 이미지 압축 해제를 위한 객체를 생성
//	if (S_OK == p_wic_factory->CreateDecoderFromFilename(ap_path, NULL, GENERIC_READ,
//		WICDecodeMetadataCacheOnDemand, &p_decoder)) {
//		// 파일을 구성하는 이미지 중에서 첫번째 이미지를 선택한다.
//		if (S_OK == p_decoder->GetFrame(0, &p_frame)) {
//			// IWICBitmap 형식의 비트맵을 ID2D1Bitmap 형식으로 변한하기 위한 객체 생성
//			if (S_OK == p_wic_factory->CreateFormatConverter(&p_converter)) {
//				// 선택된 그림을 어떤 형식의 비트맵으로 변환할것인지 설정한다.
//				if (S_OK == p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
//					NULL, 0.0f, WICBitmapPaletteTypeCustom)) {
//					// IWICBitmap 형식의 비트맵으로 Id2d1bitmap 객체를 생성한다
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
//	// 생성실패시 예외처리
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
