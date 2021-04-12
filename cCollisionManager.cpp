#include "DXUT.h"
#include "cCollisionManager.h"

cCollisionManager::cCollisionManager()
{
}

cCollisionManager::~cCollisionManager()
{
}

void cCollisionManager::Register(cCollider* col)
{
	colliderList.push_back(col);
}

void cCollisionManager::UnRegister(cCollider* col)
{
	colliderList.remove(col);
}

void cCollisionManager::Update()
{
	if (colliderList.size() < 2)
		return;

	for (auto iter1 : colliderList)
	{
		for (auto iter2 : colliderList)
		{
			if (iter1 == iter2)
				continue;
			if (iter1->parent->isDestroy || iter2->parent->isDestroy)
				continue;
			if (iter1->parent->parent != nullptr)
				if (iter1->parent->parent->tag == iter2->parent->tag)
					continue;
			if (iter2->parent->parent != nullptr)
				if (iter2->parent->parent->tag == iter1->parent->tag)
					continue;

			float length = sqrtf(D3DXVec3Length(&((iter1->parent->pos + iter1->colPos) - (iter2->parent->pos + iter2->colPos))));
			if (length < (iter1->fRadius + iter2->fRadius))
			{
				iter1->OnCollision(iter2);
				if (auto find = iter1->colEnterList.find(iter2->parent); find == iter1->colEnterList.end())
				{
					iter1->colEnterList.insert(iter2->parent);
				}
			}
		}
	}
}
