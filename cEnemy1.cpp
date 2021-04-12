#include "DXUT.h"
#include "cEnemy1.h"
#include "cExp.h"

void cEnemy1::Init()
{
	mesh = LOAD->GetMesh(L"Player");
	hp = 100;

	collider = new cCollider();
	collider->fRadius = 10;
	collider->parent = this;
	COLL->Register(collider);
}

void cEnemy1::Update()
{
	pos += Vec3(0,0,1) * 1000 * DT;
	if (hp <= 0)
	{
		int max = rand() % 10 +10;
		for(int i = 0; i < max; i++)
			ObjectAdd(ObjectTag::Exp, cExp());
		isDestroy = true;
	}
}

void cEnemy1::Render()
{
	RENDER->Render(mesh, matWorld);
}

void cEnemy1::Release()
{
}

void cEnemy1::ObjectDead()
{
}

void cEnemy1::OnCollision(cCollider* col)
{
	switch (col->parent->tag)
	{
	case EnemyBullet:

	default:
		break;
	}
}
