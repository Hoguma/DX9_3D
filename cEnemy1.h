#pragma once
#include "cObject.h"
class cEnemy1 :
    public cObject
{
public:
    // cObject��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void ObjectDead() override;
    virtual void OnCollision(cCollider* col) override;
};

