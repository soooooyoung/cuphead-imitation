#include "stdafx.h"
#include "txtData.h"


HRESULT txtData::Init()
{
	return S_OK;
}

void txtData::Release()
{
}

void txtData::SaveTxt(const char * _fileName, vector<string> _vecStr)
{
	HANDLE hFile;

	hFile = CreateFile(_fileName,
		GENERIC_WRITE,			// 접근 방식 지정 (쓰기, 읽기)
		0,						// 개체의 공유 방식 지정 : 0 (공유 안함)
		NULL,					// FILE_SHARE_DELETE : 삭제 접근 요청 시, 공유 됨
								// FILE_SHARE_READ : 읽기 접근 요청 시, 공유 됨
								// FILE_SHARE_WRITE : 쓰기 접근 요청 시, 공유 됨
		CREATE_ALWAYS,			// CREATE_NEW : 새로운 파일 생성
								// CREATE_ALWAYS : 새로운 파일 생성,
								// 동일한 이름의 파일이 있으면 덮어쓴다.
								// CREATE_EXSITING : 파일이 존재하면 오픈, 없으면 에러코드 리턴
		FILE_ATTRIBUTE_NORMAL,	// FILE_ATTRIBUTE_NORMAL : 다른 속성 없음
								// FILE_ATTRIBUTE_HIDDEN : 숨김 파일 생성
								// FILE_ATTRIBUTE_READONLY : 읽기 전용 생성
		NULL);

	char str[128];
	strncpy_s(str, 128, CombineVectorArray(_vecStr), 126);

	DWORD write;
	WriteFile(hFile,
		str, 128, &write, NULL);

	CloseHandle(hFile);
}

char * txtData::CombineVectorArray(vector<string> _vecStr)
{
	char str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < _vecStr.size(); i++)
	{
		strncat_s(str, 128, _vecStr[i].c_str(), 126);
		if (i + 1 < _vecStr.size())
			strcat_s(str, ", ");
	}

	return str;
}

vector<string> txtData::LoadTxt(const char * _fileName)
{
	HANDLE hFile;
	hFile = CreateFile(_fileName,
		GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	char str[128];
	ZeroMemory(str, sizeof(str));
	DWORD read;
	ReadFile(hFile, str, 128, &read, NULL);

	CloseHandle(hFile);

	return SeparationCharArray(str);
}

vector<string> txtData::SeparationCharArray(char _charArray[])
{
	vector<string> vecRet;
	char* context;
	char* token;
	const char* separator = ",";

	token = strtok_s(_charArray, separator, &context);
	vecRet.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &context)))
	{
		vecRet.push_back(token);
	}

	return vecRet;
}

txtData::txtData()
{
}


txtData::~txtData()
{
}
