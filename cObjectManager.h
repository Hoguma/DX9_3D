#pragma once
#include "singleton.h"

enum ObjectTag : char
{
    Player,
    Enemy,
    Map,

    PlayerBullet,
    EnemyBullet,
    Exp,
    Object2D,

    UI,
    PlayerUI,
    BossUI,
    ScoreUI,
    SkillUI,
    SkillBTN,
    MouseUI,

    END
};

class cObjectManager :
    public singleton<cObjectManager>
{
public:
    vector<cObject*> objectList[ObjectTag::END];
    long objectId = 0;
public:
    cObjectManager();
    virtual ~cObjectManager();

    cObject* CreateObject(ObjectTag tag, cObject* obj, cObject* parent = nullptr);

    void Update();
    void Render();
    void Destroy();

    cObject* GetPlayer()
    {
        return objectList[ObjectTag::Player].front();
    }

    vector<cObject*>& GetObjectList(ObjectTag tag)
    {
        return objectList[tag];
    }
};

#define OBJECT cObjectManager::Get()
#define ObjectAdd(tag, obj) OBJECT->CreateObject(tag, new obj)