#include "DXUT.h"
#include "cObjectManager.h"

cObjectManager::cObjectManager()
{
}

cObjectManager::~cObjectManager()
{
    Destroy();
}

cObject* cObjectManager::CreateObject(ObjectTag tag, cObject* obj, cObject* parent)
{
    if (!obj) return nullptr;
    cObject* temp = obj;
    temp->idGenerator = ++objectId;
    temp->tag = tag;
    temp->parent = parent;
    temp->Init();
    objectList[tag].push_back(temp);
    return temp;
}

void cObjectManager::Update()
{
    for (int i = 0; i < ObjectTag::END; i++)
    {
        for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
        {
            if (!(*iter)->isDestroy)
            {
                (*iter)->Update();
                iter++;
            }
            else
            {
                for (auto& collision : COLL->colliderList)
                {
                    if (auto find = collision->colEnterList.find((*iter)); find != collision->colEnterList.end())
                        collision->colEnterList.erase(find);
                }

                (*iter)->DestroyCollider();
                (*iter)->Release();
                SAFE_DELETE(*iter);
                iter = objectList[i].erase(iter);
            }
        }
        
    }
}

void cObjectManager::Render()
{
    for (int i = 0; i < ObjectTag::END; i++)
    {
        for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
        {
            if (!(*iter)->isDestroy)
            {
                (*iter)->TransformUpdate();
                (*iter)->Render();
            }
            iter++;
        }
    }
}

void cObjectManager::Destroy()
{
    for (int i = 0; i < ObjectTag::END; i++)
    {
        for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
        {
            (*iter)->DestroyCollider();
            (*iter)->Release();
            SAFE_DELETE(*iter);
            iter = objectList[i].erase(iter);
        }
        objectList[i].clear();
    }
}
