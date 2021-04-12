#pragma once
#include "cObject.h"
class cHomingBullet :
    public cObject
{
public:
	texture* m_tex;
	cObject* m_target;
	Vec3 m_targetPos;
	Vec3 m_Dir;
	Vec3 m_HomingVec;

	float rotX;
	float rotY;
	
	bool isHom = true;

	float timer = 0;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void ObjectDead() override;
	virtual void OnCollision(cCollider* col) override;

	float Clamp(float f1, float min, float max);

};

