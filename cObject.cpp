#include "DXUT.h"
#include "cObject.h"

cObject::cObject()
{
}

cObject::~cObject()
{
	DestroyCollider();
}

void cObject::DestroyCollider()
{
	if (collider)
	{
		COLL->UnRegister(collider);
		collider->colEnterList.clear();
		SAFE_DELETE(collider);
	}
}

void cObject::TransformUpdate()
{
	Mat scale, rotation[3], position;
	D3DXMatrixScaling(&scale, size.x, size.y, size.z);
	D3DXMatrixTranslation(&position, pos.x, pos.y, pos.z);

	if (isUseQuaAllRot)
	{
		D3DXMatrixRotationX(&rotation[0], D3DXToRadian(rot.x));
		D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
		D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(rot.z));
	}
	else
	{
		if (isUseQua)
		{
			D3DXMatrixRotationX(&rotation[0], D3DXToRadian(0));
			D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
			D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(0));
		}
		else
		{
			D3DXMatrixRotationX(&rotation[0], D3DXToRadian(rot.x));
			D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
			D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(rot.z));
		}
	}

	Mat r = rotation[0] * rotation[1] * rotation[2];
	if (isUseQua || isUseQuaAllRot)
	{
		Quat curQ;
		D3DXQuaternionIdentity(&curQ);
		D3DXQuaternionRotationMatrix(&curQ, &r);
		D3DXQuaternionSlerp(&resultQ, &resultQ, &curQ, 8.f * DT);
		D3DXMatrixRotationQuaternion(&r, &resultQ);
	}

	matWorld = scale * r * position;
}

void cObject::ColliderSet(float _radius, cObject* _parent)
{
	collider = new cCollider();
	collider->fRadius = _radius;
	collider->parent = _parent;
	COLL->Register(collider);
}
