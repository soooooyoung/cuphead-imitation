#pragma once

// singletonBase.h

template <typename T>
class singletonBase
{
protected:
	static T* instance;

	singletonBase() {};
	~singletonBase() {};

public:
	static T* GetSingleton();
	void ReleaseSingleton();
};

// �̱����� �ʱ�ȭ�Ѵ�.
template <typename T>
T* singletonBase<T>::instance = 0;

// �̱��� ���� �����´�.
template <typename T>
T* singletonBase<T>::GetSingleton()
{
	if (!instance)
	{
		instance = new T;
	}
	return instance;
}

// �̱��� �޸𸮸� �����Ѵ�.
template <typename T>
void singletonBase<T>::ReleaseSingleton()
{
	if (instance)
	{
		delete instance;
		instance = 0;
	}
}
