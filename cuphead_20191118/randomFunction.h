#pragma once
#include "stdafx.h"
#include "singletonBase.h"

// randomFunction.h

class randomFunction : public singletonBase<randomFunction>
{
//protected:
//	static randomFunction* instance;
//
//	singletonBase() {};
//	~singletonBase() {};
//
//public:
//	static randomFunction* GetSingleton();
//	void ReleaseSingleton();

public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction() {}

	inline int GetInt(int num) { return rand() % num; }
	inline int GetFromIntTo(int from, int to)
	{
		return (rand() % (to - from + 1)) + from;
	}
};
