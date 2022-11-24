#include "stdafx.h"
#include "ImageManager.h"


HRESULT ImageManager::Init()
{
	return S_OK;
}

void ImageManager::Release()
{
	DeleteAll();
}

Image* ImageManager::AddImage(string _strKey, int _width, int _height)
{
	Image* image = FindImage(_strKey);

	if (image)	return image;

	image = new Image;
	if (FAILED(image->Init(_width, _height)))
	{
		image->Release();
		SAFE_DELETE(image);
	}

	mapImageDatas.insert(make_pair(_strKey, image));
	return image;
}

Image* ImageManager::AddImage(string _strKey, const DWORD _resID, int _width, int _height, BOOL _trans, COLORREF _transColor)
{
	Image* image = FindImage(_strKey);

	if (image)	return image;

	image = new Image;
	if (FAILED(image->Init(_resID, _width, _height, _trans, _transColor)))
	{
		image->Release();
		SAFE_DELETE(image);
	}

	mapImageDatas.insert(make_pair(_strKey, image));
	return image;
}

Image* ImageManager::AddImage(string _strKey, const char * _fileName, int _width, int _height, BOOL _trans, COLORREF _transColor)
{
	Image* image = FindImage(_strKey);

	if (image)	return image;

	image = new Image;
	if (FAILED(image->Init(_fileName, _width, _height, _trans, _transColor)))
	{
		image->Release();
		SAFE_DELETE(image);
	}

	mapImageDatas.insert(make_pair(_strKey, image));
	return image;
}

Image* ImageManager::AddImage(string _strKey, const char * _fileName, float _x, float _y, int _width, int _height, int _frameX, int _frameY, BOOL _trans, COLORREF _transColor)
{
	Image* image = FindImage(_strKey);

	if (image)	return image;

	image = new Image;
	if (FAILED(image->Init(_fileName, _x, _y, _width, _height, _frameX, _frameY, _trans, _transColor)))
	{
		image->Release();
		SAFE_DELETE(image);
	}

	mapImageDatas.insert(make_pair(_strKey, image));
	return image;
}

Image * ImageManager::FindImage(string _strKey)
{
	itImageDatas = mapImageDatas.find(_strKey);

	if (itImageDatas != mapImageDatas.end())
	{
		return itImageDatas->second;
	}

	return NULL;
}

bool ImageManager::DeleteImage(string _strKey)
{
	itImageDatas = mapImageDatas.find(_strKey);

	if (itImageDatas != mapImageDatas.end())
	{
		(itImageDatas->second)->Release();
		SAFE_DELETE(itImageDatas->second);

		mapImageDatas.erase(itImageDatas);
		return true;
	}

	return false;
}

void ImageManager::DeleteAll()
{
	for (itImageDatas = mapImageDatas.begin();
		itImageDatas != mapImageDatas.end();)
	{
		if (itImageDatas->second != NULL)
		{
			itImageDatas->second->Release();
			SAFE_DELETE(itImageDatas->second);
			itImageDatas = mapImageDatas.erase(itImageDatas);
		}
		else
		{
			itImageDatas++;
		}
	}

	mapImageDatas.clear();
}

ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}
