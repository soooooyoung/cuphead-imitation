#pragma once
#include "singletonBase.h"
#include <map>
#include <string>

class Image;
class ImageManager : public singletonBase<ImageManager>
{
private:
	map<string, Image*> mapImageDatas;
	map<string, Image*>::iterator itImageDatas;

public:
	HRESULT Init();
	void Release();

	Image* AddImage(string _strKey, int _width, int _height);
	Image* AddImage(string _strKey, const DWORD _resID,
		int _width, int _height,
		BOOL _trans = FALSE, COLORREF _transColor = FALSE);
	Image* AddImage(string _strKey, const char* _fileName,
		int _width, int _height,
		BOOL _trans = FALSE, COLORREF _transColor = FALSE);
	Image* AddImage(string _strKey, const char* _fileName,
		float _x, float _y,
		int _width, int _height, int _frameX, int _frameY,
		BOOL _trans = FALSE, COLORREF _transColor = FALSE);

	Image* FindImage(string _strKey);

	bool DeleteImage(string _strKey);
	void DeleteAll();

	ImageManager();
	~ImageManager();
};

