#include "stdafx.h"
#include "D2ImageManager.h"


HRESULT D2ImageManager::Init()
{
	return S_OK;
}

void D2ImageManager::Release()
{
}

D2Image * D2ImageManager::AddImage(string _strKey, const wchar_t * _fileName)
{
	D2Image* image = FindImage(_strKey);

	if (image)	return image;

	image = new D2Image;
	
	if (FAILED(image->Init(_fileName)))
	{
		image->Release();
		SAFE_DELETE(image);
	}

	mapImageDatas.insert(make_pair(_strKey, image));
	return image;
}

D2Image * D2ImageManager::FindImage(string _strKey)
{
	itImageDatas = mapImageDatas.find(_strKey);

	if (itImageDatas != mapImageDatas.end())
	{
		return itImageDatas->second;
	}

	return NULL;
}

D2ImageManager::D2ImageManager()
{
}


D2ImageManager::~D2ImageManager()
{
}
