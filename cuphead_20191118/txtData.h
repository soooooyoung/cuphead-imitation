#pragma once
#include "singletonBase.h"
#include <vector>

class txtData : public singletonBase<txtData>
{
public:
	HRESULT Init();
	void Release();

	// 세이브
	void SaveTxt(const char* _fileName, vector<string> _vecStr);
	char* CombineVectorArray(vector<string> _vecStr);

	// 로드
	vector<string> LoadTxt(const char* _fileName);
	vector<string> SeparationCharArray(char _charArray[]);

	txtData();
	~txtData();
};

