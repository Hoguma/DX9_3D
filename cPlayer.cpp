#include "DXUT.h"
#include "cPlayer.h"
#include "cHomingBullet.h"
#include "cEnemy1.h"

void cPlayer::Init()
{
	mesh = LOAD->GetMesh(L"Player");
	pos = Vec3(0, 0, 0);
	m_speed = GAME->speed;
	m_rotSpeed = 0.2;
	damage = GAME->damage;
	collider = new cCollider();
	collider->fRadius = 10;
	collider->parent = this;
	COLL->Register(collider);
}

void cPlayer::Update()
{
	CAMERA->SetTarget(pos + Vec3(0, 0, 2000));

	if (KEYPRESS(VK_RIGHT))
	{
		if (KEYPRESS(VK_UP))
		{
			pos.x += m_speed * DT;
			pos.z += m_speed * DT;
			Lerp(&rot.z, rot.z, -15.f, m_rotSpeed);
		}
		else if(KEYPRESS(VK_DOWN))
		{
			pos.x += m_speed * DT;
			pos.z -= m_speed * DT;
			Lerp(&rot.z, rot.z, -15.f, m_rotSpeed);
		}
		else
		{
			pos.x += m_speed * DT;
			Lerp(&rot.z, rot.z, -30.f, m_rotSpeed);
		}
		
	}
	else if (KEYPRESS(VK_LEFT))
	{
		if (KEYPRESS(VK_UP))
		{
			pos.x -= m_speed * DT;
			pos.z += m_speed * DT;
			Lerp(&rot.z, rot.z, 15.f, m_rotSpeed);
		}
		else if (KEYPRESS(VK_DOWN))
		{
			pos.x -= m_speed * DT;
			pos.z -= m_speed * DT;
			Lerp(&rot.z, rot.z, 15.f, m_rotSpeed);
		}
		else
		{
			pos.x -= m_speed * DT;
			Lerp(&rot.z, rot.z, 30.f, m_rotSpeed);
		}
	}
	else if (KEYPRESS(VK_UP))
	{
		if (KEYPRESS(VK_RIGHT))
		{
			pos.x += m_speed * DT;
			pos.z += m_speed * DT;
			Lerp(&rot.z, rot.z, -15.f, m_rotSpeed);
		}
		else if (KEYPRESS(VK_LEFT))
		{
			pos.x -= m_speed * DT;
			pos.z += m_speed * DT;
			Lerp(&rot.z, rot.z, 15.f, m_rotSpeed);
		}
		else
		{
			pos.z += m_speed * DT;
			Lerp(&rot.z, rot.z, 0.f, m_rotSpeed);
		}
		
	}
	else if (KEYPRESS(VK_DOWN))
	{
		if (KEYPRESS(VK_RIGHT))
		{
			pos.x += m_speed * DT;
			pos.z -= m_speed * DT;
			Lerp(&rot.z, rot.z, -15.f, m_rotSpeed);
		}
		else if (KEYPRESS(VK_LEFT))
		{
			pos.x -= m_speed * DT;
			pos.z -= m_speed * DT;
			Lerp(&rot.z, rot.z, 0.f, m_rotSpeed);
		}
		else
		{
			pos.z -= m_speed * DT;
		}
	}
	else
	{
		Lerp(&rot.z, rot.z, 0.f, m_rotSpeed);
	}

	if (KEYDOWN(90))
	{
		auto obj1 = ObjectAdd(ObjectTag::PlayerBullet, cHomingBullet());
		obj1->pos = Vec3(pos.x + 375, pos.y, pos.z - 500);
		obj1->size = Vec3(3, 3, 1);
		obj1->damage = damage;
		obj1->ColliderSet(10, obj1);
		obj1->parent = this;
		obj1->Init();

		auto obj2 = ObjectAdd(ObjectTag::PlayerBullet, cHomingBullet());
		obj2->pos = Vec3(pos.x - 375, pos.y, pos.z - 500);
		obj2->size = Vec3(3, 3, 1);
		obj2->damage = GAME->damage;
		obj2->ColliderSet(10, obj2);
		obj2->parent = this;
		obj2->Init();
	}

	if (KEYDOWN(65))
	{
		float angle = 0;
		float rad = D3DX_PI * 2 / 10;
		for (int i = 0; i < 10; i++, angle += rad)
		{
			Vec3 dir = Vec3(pos.x + cos(angle) * 5, pos.y, pos.z + sin(angle) * 5);
			D3DXVec3Normalize(&dir, &(dir - pos));
			auto obj2 = ObjectAdd(ObjectTag::PlayerBullet, cHomingBullet());
			obj2->pos = pos + dir * 1000;
			obj2->size = Vec3(3, 3, 1);
			obj2->damage = GAME->damage;
			obj2->ColliderSet(10, obj2);
			obj2->parent = this;
			obj2->Init();
		}
	}
}

void cPlayer::Render()
{
	RENDER->Render(mesh, matWorld);
	RENDER->ReBegin(1, 0);
	wchar_t dmg[128];
	swprintf(dmg, L"DMG : %.1f", GAME->damage);
	RENDER->PrintText(dmg, Vec3(130, 20, 0), 10);
	RENDER->ReBegin(0, 0);
}

void cPlayer::Release()
{
}

void cPlayer::ObjectDead()
{
}

void cPlayer::OnCollision(cCollider* col)
{
	switch (col->parent->tag)
	{
	case Exp:
		col->parent->isDestroy = true;
		GAME->coin += col->parent->size.x;
	default:
		break;
	}
}
