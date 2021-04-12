#pragma once
#include "singleton.h"
class cSceneManager :
    public singleton<cSceneManager>
{
public:
    map<string, cScene*> m_scenes;
    cScene* nowScene = nullptr;
    cScene* nextScene = nullptr;

    cSceneManager();
    ~cSceneManager();
    void Update();
    void Render();
    void Release();

    void AddScene(string key, cScene* scene);
    void ChangeScene(string key);
};

#define SCENE cSceneManager::Get()