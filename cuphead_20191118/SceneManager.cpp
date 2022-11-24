#include "stdafx.h"
#include "SceneManager.h"
#include "gameNode.h"

gameNode* SceneManager::currentScene = NULL;
gameNode* SceneManager::loadingScene = NULL;
gameNode* SceneManager::readyScene = NULL;

DWORD CALLBACK LoadingThread(LPVOID _pvParam)
{
	//������ ���� ���
	// 1. ȣ��� �Լ��� ��ȯ�ɶ� (�츮�� ����� ���)
	// 2. ȣ��� �Լ� ���ο��� ExitThread()�� ȣ����������
	// 3. ������ ���μ��� ���ٸ� ���μ������� TerminateThread()�Լ��� ȣ��
	// 4. �����尡 ���Ե� ���μ����� ����ɶ�
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

	// �ٲٷ��� ���ξ�
	itSceneData = mapSceneData.find(_sceneName);

	if (itSceneData == mapSceneData.end()) {
		return E_FAIL;
	}
	if (itSceneData->second == currentScene) {
		return S_OK;
	}

	// �߰��� �� �ε���
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

