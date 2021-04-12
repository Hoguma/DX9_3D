#pragma once
#include "singleton.h"
class cCameraManager :
    public singleton<cCameraManager>
{
public:
    cCameraManager();
    virtual ~cCameraManager();

    cObject* player;

    Vec3 cameraPos;;
    Vec3 at;
    Vec3 up;

    Vec3 saveTemp = Vec3(0, 15, 30);

    Vec3 cameraRot = Vec3(0, 0, 0);
    Vec2 nowMouse = Vec3(0, 0, 0);

    Mat matView, matProj;

    bool isLoad = false;

    Vec3 Shakepos = Vec3(0, 0, 0);
    float shakeScale = 0.f;
    bool isShake = false;
    float shokeTime = 0;
    system_clock::time_point shTime;

    void Update();
    void SetTransform();
    void CameraShake(float time, float scale);
    void SetTarget(Vec3 target);

    Vec2 GetScreenPos()
    {
        POINT point = { 0,0 };
        ClientToScreen(DXUTGetHWND(), &point);
        Vec2 mousepos(point.x, point.y);
        return mousepos;
    }
};

#define CAMERA cCameraManager::Get()