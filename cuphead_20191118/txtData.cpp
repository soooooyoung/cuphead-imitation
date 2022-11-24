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
		GENERIC_WRITE,			// ���� ��� ���� (����, �б�)
		0,						// ��ü�� ���� ��� ���� : 0 (���� ����)
		NULL,					// FILE_SHARE_DELETE : ���� ���� ��û ��, ���� ��
								// FILE_SHARE_READ : �б� ���� ��û ��, ���� ��
								// FILE_SHARE_WRITE : ���� ���� ��û ��, ���� ��
		CREATE_ALWAYS,			// CREATE_NEW : ���ο� ���� ����
								// CREATE_ALWAYS : ���ο� ���� ����,
								// ������ �̸��� ������ ������ �����.
								// CREATE_EXSITING : ������ �����ϸ� ����, ������ �����ڵ� ����
		FILE_ATTRIBUTE_NORMAL,	// FILE_ATTRIBUTE_NORMAL : �ٸ� �Ӽ� ����
								// FILE_ATTRIBUTE_HIDDEN : ���� ���� ����
								// FILE_ATTRIBUTE_READONLY : �б� ���� ����
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
