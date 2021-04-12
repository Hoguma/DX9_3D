#include "DXUT.h"
#include "cExp.h"

void cExp::Init()
{
	m_tex = LOAD->GetTexture(L"Coin");

	float close = 100000;

	m_target = OBJECT->GetPlayer();
	
	m_Dir = Vec3(rand() % 200 - 100, 0, rand() % 200 - 100);
	D3DXVec3Normalize(&m_Dir, &m_Dir);
	sizef = rand() % 3 + 1;
	size = Vec3(sizef, sizef, sizef);
	lerpsize = rand() % 45 + 45;

	ColliderSet(sizef, this);
}

void cExp::Update()
{
	timer += DT;
	if (timer >= 1.f)
		ishom = true;
	if (ishom)
	{
		m_targetPos = m_target->pos;
		D3DXVec3Normalize(&m_Dir, &(m_targetPos - pos));
		m_HomingVec += m_Dir * 50 * DT;
		D3DXVec3Normalize(&m_HomingVec, &m_HomingVec);
		pos += m_HomingVec * 10000 * DT;
	}
	else
	{
		Lerp(&pos, pos, m_Dir * lerpsize*1000 *DT, 0.25f);
	}
}

void cExp::Render()
{
	RENDER->ReBegin(0, 1);
	RENDER->Render(m_tex, pos, size);
	RENDER->ReBegin(0, 0);
}

void cExp::Release()
{
}

void cExp::ObjectDead()
{
}

void cExp::OnCollision(cCollider* col)
{
}
