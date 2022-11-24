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
	// �Լ� ȣ�� ������ ����Ű(VK_)�� � ������ Ȯ���� �����ϴ�.
	// 1. 0x0000 => ������ ���� ���� ���� ȣ��������� �������� ����
	// 2. 0x0001 => ������ ���� ���� �ְ� ȣ��������� �������� ����
	// 3. 0x8000 => ������ ���� ���� ���� ȣ��������� �����ִ� ����
	// 4. 0x8001 => ������ ���� ���� �ְ� ȣ��������� �����ִ� ����
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
	�ǽ�. �ѹ� �����ٰ� �� �� Ȯ���ϴ� �ڵ带 �ϼ��غ���.
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
