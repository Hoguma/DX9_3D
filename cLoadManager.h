#pragma once
#include "singleton.h"

class texture
{
public:
    LPDIRECT3DTEXTURE9 texPtr;
    D3DXIMAGE_INFO info;

    texture(LPDIRECT3DTEXTURE9 _texPtr, D3DXIMAGE_INFO _info)
        :texPtr(_texPtr), info(_info) {}
};
class CMeshLoader;
class CSound;

class cLoadManager :
    public singleton<cLoadManager>
{
public:
    
    map<wstring, texture*> MImage;
    map<wstring, CMeshLoader*> MMesh;
    
public:
    cLoadManager();
    virtual ~cLoadManager();

    texture* GetTexture(wstring key);
    void AddTexture(wstring key, wstring path, int count = 0);
    texture* AddMatTexture(wstring key, wstring path);
    vector<texture*> GetVecTexture(wstring key, wstring path, int count);

    CMeshLoader* GetMesh(wstring key);
    void AddMesh(wstring key, wstring path);

    
};

#define LOAD cLoadManager::Get()