#pragma once
#include "singleton.h"
class cRenderManager :
    public singleton<cRenderManager>
{
public:
    LPD3DXSPRITE Sprite;
    LPD3DXFONT Font;
public:
    cRenderManager();
    virtual ~cRenderManager();

    void Render(CMeshLoader* _mesh, Mat matWorld, Vec4 lineColor = Vec4(0, 0, 0, 1), float linesize = 1.f, bool IsRenderOutLine = false);
    void Render(texture* _tex, Vec3 pos, Vec3 size = Vec3(1, 1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_ARGB(255,255,255,255));
    void CropRender(texture* tex, Vec2 pos, Vec3 size, RECT rect);

    void PrintText(wstring text, Vec3 pos, float size, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));

    void Begin(bool isUi, bool isBill);
    void ReBegin(bool isUi, bool isBill);
    void End();

    void LostDevice();
    void ResetDevice();
};

#define RENDER cRenderManager::Get()