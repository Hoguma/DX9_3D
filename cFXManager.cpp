#include "DXUT.h"
#include "cFXManager.h"

cFXManager::cFXManager()
{
	ID3DXBuffer* pErrorMsgs;
	D3DXCreateEffectFromFile(gDevice, L"./Shader.fx", NULL, NULL, 0, NULL, &Toon, &pErrorMsgs);
}

cFXManager::~cFXManager()
{
	SAFE_RELEASE(Toon);
}
