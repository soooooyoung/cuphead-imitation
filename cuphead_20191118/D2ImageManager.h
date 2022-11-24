#pragma once
#include "singletonBase.h"
#include <map>
#include <string>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")

using namespace D2D1;
class D2Image;
class D2ImageManager : public singletonBase<D2ImageManager>
{
private:
	map<string, D2Image*> mapImageDatas;
	map<string, D2Image*>::iterator itImageDatas;

public:
	HRESULT Init();
	void Release();

	//D2Image* AddImage(string _strKey, int _width, int _height);
	//D2Image* AddImage(string _strKey, const DWORD _resID,
	//	int _width, int _height,
	//	BOOL _trans = FALSE, COLORREF _transColor = FALSE);
	D2Image* AddImage(string _strKey, const wchar_t * _fileName);
	//D2Image* AddImage(string _strKey, const char* _fileName,
	//	float _x, float _y,
	//	int _width, int _height, int _frameX, int _frameY,
	//	BOOL _trans = FALSE, COLORREF _transColor = FALSE);

	D2Image* FindImage(string _strKey);

	//bool DeleteImage(string _strKey);
	//void DeleteAll();

	D2ImageManager();
	~D2ImageManager();
};

