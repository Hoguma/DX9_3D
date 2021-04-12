#pragma once
class cObject;
class cCollider
{
public:
	cObject* parent = nullptr;
	Vec3 colPos = Vec3(0, 0, 0);
	float fRadius = 0;
	set<cObject*> colEnterList;

	cCollider();
	virtual ~cCollider();

	virtual void OnCollision(cCollider* col);
};

