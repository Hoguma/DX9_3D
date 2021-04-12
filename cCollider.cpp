#include "DXUT.h"
#include "cCollider.h"

cCollider::cCollider()
{
}

cCollider::~cCollider()
{
}

void cCollider::OnCollision(cCollider* col)
{
	parent->OnCollision(col);
}
