#pragma once
#include "singleton.h"
class cGameManager :
    public singleton<cGameManager>
{
public:
    int coin = 0;
    float damage = 10;
    float speed = 3000;
};

#define GAME cGameManager::Get()