#include "stdafx.h"
#include "SceneManager.h"
#include "gameNode.h"

gameNode* SceneManager::currentScene = NULL;
gameNode* SceneManager::loadingScene = NULL;
gameNode* SceneManager::readyScene = NULL;

DWORD CALLBACK LoadingThread(LPVOID _pvParam)
{
	//쓰레드 종료 방법
	// 1. 호출된 함수가 반환될때 (우리가 사용할 방법)
	// 2. 호출되 함수 내부에서 ExitThread()를 호출햇을때ㅔ
	// 3. 동일한 프로세슨 ㅏ다른 프로세스에서 TerminateThread()함수를 호출
	// 4. 스레드가 포함된 프로세스가 종료될때
	SceneManager::readyScene->Init();
	SceneManager::currentScene = SceneManager::readyScene;

	SceneManager::loadingScene->Release();
	SceneManager::loadingScene = NULL;
	SceneManager::readyScene = NULL;

	return 0;
}
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

HRESULT SceneManager::Init()
{

	return S_OK;
}

void SceneManager::Release()
{
	for (itSceneData = mapSceneData.begin();
		itSceneData != mapSceneData.end(); )
	{
		if (itSceneData->second != NULL)
		{
			if (itSceneData->second == currentScene)
				(itSceneData->second)->Release();

			SAFE_DELETE(itSceneData->second);
			itSceneData = mapSceneData.erase(itSceneData);
		}
		else
		{
			itSceneData++;
		}
	}
	mapSceneData.clear();
}

void SceneManager::Update()
{
	if (currentScene)
	{
		currentScene->Update();
	}
	
}

void SceneManager::Render(HDC _hdc)
{
	if (currentScene)
		currentScene->Render(_hdc);
}

void SceneManager::D2Render(ID2D1DCRenderTarget * ap_target)
{
	if (currentScene)
	{
		currentScene->D2Render(ap_target);
	}

}
//
//void SceneManager::D2RenderLoading(ID2D1DCRenderTarget * ap_target)
//{
//
//	if (overlappedScene) {
//		overlappedScene->D2Render(ap_target);
//	}
//
//
//}

gameNode * SceneManager::AddScene(string _key, gameNode * _scene)
{
	if (_scene == NULL)	return NULL;

	mapSceneData.insert(pair<string, gameNode*>(_key, _scene));

	return _scene;
}

gameNode * SceneManager::AddLoadingScene(string _key, gameNode * _scene)
{
	if (_scene == NULL)	return NULL;

	mapLoadingScene.insert(pair<string, gameNode*>(_key, _scene));

	return _scene;
}

HRESULT SceneManager::ChangeScene(string _sceneName)
{
	itSceneData = mapSceneData.find(_sceneName);
	if (itSceneData == mapSceneData.end())	return E_FAIL;

	if (itSceneData->second == currentScene)	return S_OK;

	if (SUCCEEDED(itSceneData->second->Init()))
	{
		if (currentScene)
			currentScene->Release();

		currentScene = itSceneData->second;

		return S_OK;
	}

	return E_FAIL;
}

HRESULT SceneManager::ChangeScene(string _sceneName, string _loadingSceneName)
{

	// 바꾸려는 메인씬
	itSceneData = mapSceneData.find(_sceneName);

	if (itSceneData == mapSceneData.end()) {
		return E_FAIL;
	}
	if (itSceneData->second == currentScene) {
		return S_OK;
	}

	// 중간에 들어갈 로딩씬
	itLoadingScene = mapLoadingScene.find(_loadingSceneName);

	if (itLoadingScene == mapLoadingScene.end()) {
		return ChangeScene(_sceneName);
	}

	if (SUCCEEDED(itLoadingScene->second->Init())) {
		if (currentScene) {
			currentScene->Release();
		}
		readyScene = itSceneData->second;
		loadingScene = itLoadingScene->second;

		currentScene = loadingScene; 

	/*	HANDLE hThread;*/
		DWORD loadThreadID;
		CloseHandle(CreateThread(NULL, 0, LoadingThread, 0, 0, &loadThreadID));
	}

	return E_NOTIMPL;
}

//HRESULT SceneManager::LoadingScene(string _sceneName)
//{
//	itSceneData = mapSceneData.find(_sceneName);
//	if (itSceneData == mapSceneData.end()) {
//		return E_FAIL;
//	}
//	if (itSceneData->second == currentScene) {
//		return S_OK;
//	}
//	
//	overlappedScene = itSceneData->second;
//
//	return S_OK;
//}

//void SceneManager::PlayTransition()
//{
//	playTransition = true;
//}

