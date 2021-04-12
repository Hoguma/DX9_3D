#include "DXUT.h"
#include "cShop.h"

void cShop::Init()
{
}

void cShop::Update()
{
	if (KEYDOWN(70))
	{
		if (GAME->coin >= 5)
		{
			GAME->damage += 2.5f;
			GAME->coin -= 5;
		}
	}
	if (KEYDOWN(VK_TAB))
		SCENE->ChangeScene("Stage1");
}

void cShop::Render()
{
	RENDER->ReBegin(1, 0);
	wchar_t exp[128];
	swprintf(exp, L"Coin : %d", GAME->coin);
	RENDER->PrintText(exp, Vec3(1150, 20, 0), 10);
	RENDER->ReBegin(0, 0);
}

void cShop::Release()
{
}
