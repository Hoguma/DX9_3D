#pragma once
#include "cScene.h"
class cStage1 :
    public cScene
{
public:
    float timer = 0;
public:
    // cScene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

