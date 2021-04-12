#pragma once
#include "cObject.h"
class cPlayer :
    public cObject
{
public:
    float m_speed;
    float m_rotSpeed;

    
public:
    // cObject��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void ObjectDead() override;
    virtual void OnCollision(cCollider* col) override;
};

