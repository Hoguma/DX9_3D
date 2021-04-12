#pragma once
#include "cObject.h"
class cExp :
    public cObject
{
public:
    texture* m_tex;
    cObject* m_target;
    Vec3 m_targetPos;
    Vec3 m_Dir;
    Vec3 m_HomingVec;

    float rotX;
    float rotY;

    float sizef;
    float lerpsize;

    float timer = 0;

    bool ishom = false;
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void ObjectDead() override;
    virtual void OnCollision(cCollider* col) override;
};

