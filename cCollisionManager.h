#pragma once
#include "singleton.h"

class cCollider;
class cCollisionManager :
    public singleton<cCollisionManager>
{
public:
    list<cCollider*> colliderList;

    texture* pixelMap;
public:
    cCollisionManager();
    virtual ~cCollisionManager();

    void Register(cCollider* col);
    void UnRegister(cCollider* col);

    void Update();
};

#define COLL cCollisionManager::Get()