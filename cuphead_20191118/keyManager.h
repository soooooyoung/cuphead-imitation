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

	bool IsOnceKeyDown(int key);	// 키를 한번만 눌렀을 때
	bool IsOnceKeyUp(int key);		// 키를 눌렀다 뗐을 때
	bool IsDoubleClick(int key);
	bool IsStayKeyDown(int key);	// 키를 누르고 있을 때
	bool IsToggleKey(int key);		// 키를 연타할 때

	// Getter, Setter
	bitset<KEYMAX>	GetKeyUp() { return keyUp; }
	bitset<KEYMAX>	GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUp.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

	keyManager();
	~keyManager();
};

