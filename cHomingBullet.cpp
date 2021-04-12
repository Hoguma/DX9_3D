#include "DXUT.h"
#include "cHomingBullet.h"

void cHomingBullet::Init()
{
	if (tag == ObjectTag::PlayerBullet)
	{
		m_tex = LOAD->GetTexture(L"HomingMissile");
		
		float close = 100000;
		if (parent != nullptr)
		{
			for (auto iter : OBJECT->GetObjectList(Enemy))
			{
				if (close > D3DXVec3Length(&(parent->pos - iter->pos)))
				{
					close = D3DXVec3Length(&(parent->pos - iter->pos));
					m_target = iter;
				}
			}
		}
	}
	else
	{
		m_tex = LOAD->GetTexture(L"HomingMissile");
	}
}

void cHomingBullet::Update()
{
	timer += DT;
	if (timer >= 2)
		isHom = false;
	if(m_target == nullptr)
		pos += Vec3(0,0,1) * 3000 * DT;
	else
	{
		if (m_target->isDestroy == true)
			isHom = false;
		if(isHom)
		{
			m_targetPos = m_target->pos;
			D3DXVec3Normalize(&m_Dir, &(m_targetPos - pos));
			m_HomingVec += m_Dir * 10 * DT;
			D3DXVec3Normalize(&m_HomingVec, &m_HomingVec);
			pos += m_HomingVec * 3000 * DT;
		}
		else
		{
			pos += m_HomingVec * 3000 * DT;
		}
	}
}

void cHomingBullet::Render()
{
	RENDER->ReBegin(0, 1);
	RENDER->Render(m_tex, pos, size);
	RENDER->ReBegin(0, 0);
}

void cHomingBullet::Release()
{
}

void cHomingBullet::ObjectDead()
{
}

void cHomingBullet::OnCollision(cCollider* col)
{
	switch (col->parent->tag)
	{
	case Enemy:
		col->parent->hp -= damage;
		isDestroy = true;
	default:
		break;
	}
	
}

float cHomingBullet::Clamp(float f1, float min, float max)
{
	if (f1 < min) return min;
	else if (f1 > max) return max;
}