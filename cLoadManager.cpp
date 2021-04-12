#include "DXUT.h"
#include "cLoadManager.h"

cLoadManager::cLoadManager()
{
}

cLoadManager::~cLoadManager()
{
    for (auto iter : MImage)
    {
        SAFE_RELEASE(iter.second->texPtr);
        SAFE_DELETE(iter.second);
    }
    MImage.clear();

    for (auto iter : MMesh)
    {
        iter.second->Destroy();
        //SAFE_RELEASE(iter.second->m_pMesh);
        SAFE_DELETE(iter.second);
    }
    MMesh.clear();

    
}

texture* cLoadManager::GetTexture(wstring key)
{
    if(auto find = MImage.find(key); find != MImage.end())
    return find->second;
}

void cLoadManager::AddTexture(wstring key, wstring path, int count)
{
    wchar_t Path[128];
    if (count == 0)
    {
        swprintf(Path, L"./Resource/Texture/%s.png", path.c_str());
        LPDIRECT3DTEXTURE9 texPtr;
        D3DXIMAGE_INFO info;
        if (D3DXCreateTextureFromFileEx(gDevice, Path, -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, NULL, &info, nullptr, &texPtr) == S_OK)
        {
            texture* tex = new texture(texPtr, info);
            MImage.insert(make_pair(key, tex));
        }
    }
    else
    {
        wchar_t Key[128];
        for (int i = 0; i < count; i++)
        {
            swprintf(Path, L"./Resource/Texture/%s (%d).png", path.c_str(), i);
            swprintf(Key, L"%s%d", key.c_str(), i);
            LPDIRECT3DTEXTURE9 texPtr;
            D3DXIMAGE_INFO info;
            if (D3DXCreateTextureFromFileEx(gDevice, Path, -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, NULL, &info, nullptr, &texPtr) == S_OK)
            {
                texture* tex = new texture(texPtr, info);
                MImage.insert(make_pair(Key, tex));
            }
        }
    }
}

texture* cLoadManager::AddMatTexture(wstring key, wstring path)
{
	LPDIRECT3DTEXTURE9 texPtr;
	D3DXIMAGE_INFO info;
	if (D3DXCreateTextureFromFileEx(gDevice, path.c_str(), -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, NULL, &info, nullptr, &texPtr) == S_OK)
	{
		texture* tex = new texture(texPtr, info);
		MImage.insert(make_pair(key, tex));
        return tex;
	}
}

vector<texture*> cLoadManager::GetVecTexture(wstring key, wstring path, int count)
{
    vector<texture*> vecimg;
    for (int i = 0;; i++)
    {
        wchar_t Key[128];
        swprintf(Key, L"%s%d", key.c_str(), i);
        auto find = GetTexture(Key);
        if (find == nullptr) break;
        vecimg.push_back(find);
    }
    return vecimg;
}

CMeshLoader* cLoadManager::GetMesh(wstring key)
{
    if (auto find = MMesh.find(key); find != MMesh.end())
        return find->second;
}

void cLoadManager::AddMesh(wstring key, wstring path)
{
    CMeshLoader* mesh = new CMeshLoader();
    wchar_t Path[128];
    swprintf(Path, L"./Resource/Mesh/%s.obj", path.c_str());
    mesh->Create(gDevice, (LPCWSTR)Path);
    if (mesh)
    {
        MMesh.insert(make_pair(key, mesh));
    }
    
}

