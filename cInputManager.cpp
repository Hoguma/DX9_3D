#include "DXUT.h"
#include "cInputManager.h"

void cInputManager::Update()
{
	memcpy(&oldKey, &nowKey, sizeof(nowKey));
	memset(&nowKey, false, sizeof(nowKey));
	for (int i = 0; i < 256; i++)
		nowKey[i] = GetAsyncKeyState(i);
}
