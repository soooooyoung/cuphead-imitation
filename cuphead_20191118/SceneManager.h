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
	HRESULT Init();			// 초기화
	void Release();			// 메모리 해제
	void Update();			// 프레임 단위 로직 실행
	void Render(HDC _hdc);	// 프레임 단위 출력
	void D2Render(ID2D1DCRenderTarget *ap_target);	// 프레임 단위 출력
	//void D2RenderLoading(ID2D1DCRenderTarget *ap_target);


	// 씬 추가
	gameNode* AddScene(string _key, gameNode* _scene);
	gameNode* AddLoadingScene(string _key, gameNode* _scene);
	//void SetIsTransition(bool _IsTransition) { IsTransition = _IsTransition; }
	//bool GetisTransition() { return IsTransition; }
	// 씬 체인지
	HRESULT ChangeScene(string _sceneName);
	HRESULT ChangeScene(string _sceneName, string _loadingSceneName);
	//HRESULT LoadingScene(string _sceneName);
	SceneManager();
	~SceneManager();

	friend DWORD CALLBACK LoadingThread(LPVOID _pvParam);

};

