#include "DXUT.h"
#include "cStage1.h"
#include "cPlayer.h"
#include "cEnemy1.h"

void cStage1::Init()
{
	ObjectAdd(ObjectTag::Player, cPlayer);
	
	/*auto obj1 = ObjectAdd(ObjectTag::Enemy, cEnemy1);
	obj1->pos = obj1->pos + Vec3(1000, 0, 0);
	auto obj2 = ObjectAdd(ObjectTag::Enemy, cEnemy1);
	obj2->pos = obj2->pos + Vec3(-1000, 0, 0);*/
}

void cStage1::Update()
{
	if (KEYDOWN(VK_TAB))
	{
		SCENE->ChangeScene("Shop");
	}

	timer += DT;

	if (timer >= 3.f)
	{
		ObjectAdd(ObjectTag::Enemy, cEnemy1);
		timer = 0;
	}
}

void cStage1::Render()
{
	RENDER->ReBegin(1, 0);
	wchar_t exp[128];
	swprintf(exp, L"Coin : %d", GAME->coin);
	RENDER->PrintText(exp, Vec3(1150, 20, 0), 10);
	RENDER->ReBegin(0, 0);
}

void cStage1::Release()
{
}
