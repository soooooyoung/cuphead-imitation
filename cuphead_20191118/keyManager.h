#pragma once
#include "singletonBase.h"
#include <bitset>

using namespace std;

#define KEYMAX	256

class keyManager : public singletonBase<keyManager>
{
private:
	bitset<KEYMAX>		keyUp;
	//bool keyArr[KEYMAX];
	bitset<KEYMAX>		keyDown;

public:
	HRESULT Init();
	void Release();

	bool IsOnceKeyDown(int key);	// Ű�� �ѹ��� ������ ��
	bool IsOnceKeyUp(int key);		// Ű�� ������ ���� ��
	bool IsDoubleClick(int key);
	bool IsStayKeyDown(int key);	// Ű�� ������ ���� ��
	bool IsToggleKey(int key);		// Ű�� ��Ÿ�� ��

	// Getter, Setter
	bitset<KEYMAX>	GetKeyUp() { return keyUp; }
	bitset<KEYMAX>	GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUp.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

	keyManager();
	~keyManager();
};

