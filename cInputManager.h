#pragma once
#include "singleton.h"
class cInputManager :
    public singleton<cInputManager>
{
public:
    cInputManager() {}
    virtual ~cInputManager() {}

    bool nowKey[256] = { 0 };
    bool oldKey[256] = { 0 };

    void Update();

    bool KeyDown(int i) { return nowKey[i] && !oldKey[i]; }
    bool KeyUp(int i) { return !nowKey[i] && oldKey[i]; }
    bool KeyPress(int i) { return nowKey[i] && oldKey[i]; }

    Vec2 GetMousePos()
    {
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(DXUTGetHWND(), &pt);
        return Vec2(pt.x, pt.y);
    }

    Vec2 GetworldMousePos()
    {
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(DXUTGetHWND(), &pt);
        Vec2 mousePos = Vec2(pt.x, pt.y);
        mousePos -= Vec2((WINSIZEX / 2 - CAMERA->cameraPos.x), (WINSIZEY / 2 - CAMERA->cameraPos.y));
        return mousePos;
    }
};

#define INPUT cInputManager::Get()
#define KEYDOWN(i) INPUT->KeyDown(i)
#define KEYUP(i) INPUT->KeyUp(i)
#define KEYPRESS(i) INPUT->KeyPress(i)