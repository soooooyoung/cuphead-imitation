#pragma once
#include "singletonBase.h"
#include <vector>

class txtData : public singletonBase<txtData>
{
public:
	HRESULT Init();
	void Release();

	// ���̺�
	void SaveTxt(const char* _fileName, vector<string> _vecStr);
	char* CombineVectorArray(vector<string> _vecStr);

	// �ε�
	vector<string> LoadTxt(const char* _fileName);
	vector<string> SeparationCharArray(char _charArray[]);

	txtData();
	~txtData();
};

