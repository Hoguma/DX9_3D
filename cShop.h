#pragma once
#include "cScene.h"
class cShop :
    public cScene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

