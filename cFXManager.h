#pragma once
#include "singleton.h"
class cFXManager :
    public singleton<cFXManager>
{
public:
    LPD3DXEFFECT Toon = NULL;
public:
    cFXManager();
    virtual ~cFXManager();
};

#define FX cFXManager::Get()
#define FXToon cFXManager::Get()->Toon