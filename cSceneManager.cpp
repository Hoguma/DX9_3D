#include "DXUT.h"
#include "cSceneManager.h"

cSceneManager::cSceneManager()
{
}

cSceneManager::~cSceneManager()
{
	Release();
}

void cSceneManager::Update()
{
	if (nowScene) nowScene->Update();
	if (nextScene)
	{
		if (nowScene)
		{
			nowScene->Release();
			OBJECT->Destroy();
		}
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	else if (nowScene)
	{
		nowScene->Update();
		OBJECT->Update();
	}
}

void cSceneManager::Render()
{
	if (nowScene)
	{
		nowScene->Render();
		OBJECT->Render();
	}
}

void cSceneManager::Release()
{
	if (nowScene)
	{
		nowScene->Release();
	}
	for (auto iter : m_scenes)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_scenes.clear();
}

void cSceneManager::AddScene(string key, cScene* scene)
{
	m_scenes[key] = scene;
}

void cSceneManager::ChangeScene(string key)
{
	auto find = m_scenes.find(key);
	nextScene = find->second;
}
