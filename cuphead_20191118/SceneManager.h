#pragma once
#include "singletonBase.h"
#include <map>

using namespace std;
// Direct2D
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")

using namespace D2D1;

class gameNode;
class SceneManager : public singletonBase<SceneManager>
{
public:
	static gameNode* currentScene;
	static gameNode* loadingScene;
	static gameNode* readyScene;
	static gameNode* overlappedScene;

	typedef map<string, gameNode*> mapScenes;
private:
	//map<string, gameNode*>	mapSceneData;
	//map<string, gameNode*>::iterator	itSceneData;

	//map<string, gameNode*>	mapSceneData;
	//map<string, gameNode*>::iterator	itLoadingScene;

	mapScenes	mapSceneData;
	mapScenes::iterator	itSceneData;

	mapScenes mapLoadingScene;
	mapScenes::iterator	itLoadingScene;

public:
	HRESULT Init();			// �ʱ�ȭ
	void Release();			// �޸� ����
	void Update();			// ������ ���� ���� ����
	void Render(HDC _hdc);	// ������ ���� ���
	void D2Render(ID2D1DCRenderTarget *ap_target);	// ������ ���� ���
	//void D2RenderLoading(ID2D1DCRenderTarget *ap_target);


	// �� �߰�
	gameNode* AddScene(string _key, gameNode* _scene);
	gameNode* AddLoadingScene(string _key, gameNode* _scene);
	//void SetIsTransition(bool _IsTransition) { IsTransition = _IsTransition; }
	//bool GetisTransition() { return IsTransition; }
	// �� ü����
	HRESULT ChangeScene(string _sceneName);
	HRESULT ChangeScene(string _sceneName, string _loadingSceneName);
	//HRESULT LoadingScene(string _sceneName);
	SceneManager();
	~SceneManager();

	friend DWORD CALLBACK LoadingThread(LPVOID _pvParam);

};

