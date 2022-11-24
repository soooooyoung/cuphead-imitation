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

// 싱글톤을 초기화한다.
template <typename T>
T* singletonBase<T>::instance = 0;

// 싱글톤 값을 가져온다.
template <typename T>
T* singletonBase<T>::GetSingleton()
{
	if (!instance)
	{
		instance = new T;
	}
	return instance;
}

// 싱글톤 메모리를 해제한다.
template <typename T>
void singletonBase<T>::ReleaseSingleton()
{
	if (instance)
	{
		delete instance;
		instance = 0;
	}
}
