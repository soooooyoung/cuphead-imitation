#include "stdafx.h"
#include "keyManager.h"


HRESULT keyManager::Init()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		//this->GetKeyDown().set(i, false);
		//GetKeyDown().set(i, false);
		//keyDown.set(i, false);
		SetKeyDown(i, false);

		SetKeyUp(i, true);
		//this->GetKeyUp().set(i, true);
	}

	return S_OK;
}

void keyManager::Release()
{
}

bool keyManager::IsOnceKeyDown(int key)
{
	// 함수 호출 시점에 가상키(VK_)가 어떤 상태인 확인이 가능하다.
	// 1. 0x0000 => 이전에 누른 적이 없고 호출시점에도 눌려있지 않음
	// 2. 0x0001 => 이전에 누른 적이 있고 호출시점에는 눌려있지 않음
	// 3. 0x8000 => 이전에 누른 적이 없고 호출시점에는 눌려있는 상태
	// 4. 0x8001 => 이전에 누른 적이 있고 호출시점에도 눌려있는 상태
	//VK_LEFT
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->GetKeyDown()[key])
		{
			this->SetKeyDown(key, true);
			return true;
		}
	}
	else
	{
		this->SetKeyDown(key, false);
	}

	return false;
}

bool keyManager::IsOnceKeyUp(int key)
{
	/*
	실습. 한번 눌렀다가 뗄 때 확인하는 코드를 완성해보자.
	*/
	if (GetAsyncKeyState(key) & 0x8000)
	{
		this->SetKeyUp(key, false);
	}
	else
	{
		if (!this->GetKeyUp()[key])
		{
			this->SetKeyUp(key, true);
			return true;
		}
	}
	return false;
}

bool keyManager::IsDoubleClick(int key)
{
	if (GetAsyncKeyState(key) )
	{
		return true;
	}
	else
	{

	}
	return false;
}

bool keyManager::IsStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)	return true;

	return false;
}

bool keyManager::IsToggleKey(int key)
{
	if (GetAsyncKeyState(key) & 0x0001) return true;



	return false;
}

keyManager::keyManager()
{
}


keyManager::~keyManager()
{
}
