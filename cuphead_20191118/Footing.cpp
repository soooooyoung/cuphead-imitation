#include "stdafx.h"
#include "Footing.h"
#include "Animation.h"


HRESULT Footing::Init(float _posX, float _posY, float _width, float _height, string _strKey)
{
	img = D2IMAGEMANAGER->FindImage(_strKey);
	rc = SetRectCenter(_posX, _posY, _width, _height);

	return S_OK;
}

void Footing::Release()
{
}

void Footing::Update()
{
}

void Footing::D2Render(ID2D1DCRenderTarget * ap_target)
{
}

Footing::Footing()
{
}


Footing::~Footing()
{
}
