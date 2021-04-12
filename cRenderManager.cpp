#include "DXUT.h"
#include "cRenderManager.h"

cRenderManager::cRenderManager()
{
	D3DXCreateSprite(gDevice, &Sprite);
	D3DXCreateFont(gDevice, 40, 0, 0, 5, false, HANGUL_CHARSET, 0, 0, 0, L"¸¼Àº °íµñ Bold", &Font);
}

cRenderManager::~cRenderManager()
{
	SAFE_RELEASE(Font);
	SAFE_RELEASE(Sprite);
}



void cRenderManager::Render(CMeshLoader* _mesh, Mat matWorld, Vec4 lineColor, float linesize, bool IsRenderOutLine)
{
	if (IsRenderOutLine)
	{

	}

	gDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for (int i = 0; i < _mesh->GetNumMaterials(); ++i)
	{
		gDevice->SetTexture(0, _mesh->GetMaterial(i)->pTexture);
		gDevice->SetMaterial(&_mesh->GetMaterial(i)->mtl);
		_mesh->GetMesh()->DrawSubset(i);
	}
}

void cRenderManager::Render(texture* _tex, Vec3 pos, Vec3 size, float rot, D3DCOLOR color)
{
	Mat matWorld;
	gDevice->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matWorld));
	Mat mSize, mRot, mPos;
	D3DXMatrixScaling(&mSize, size.x, -size.y, size.z);
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));
	D3DXMatrixTranslation(&mPos, pos.x, pos.y, pos.z);

	Sprite->SetTransform(&(mSize * mRot * mPos));
	Sprite->Draw(_tex->texPtr, NULL, &Vec3(_tex->info.Width/2, _tex->info.Height/2, 0), NULL, color);
}

void cRenderManager::CropRender(texture* tex, Vec2 pos, Vec3 size, RECT rect)
{
	Mat matWorld;
	gDevice->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matWorld));
	Mat mSize, mRot, mPos;
	D3DXMatrixScaling(&mSize, size.x, -size.y, size.z);
	D3DXMatrixTranslation(&mPos, pos.x, pos.y, 0);
	D3DXMatrixIdentity(&mRot);

	Sprite->SetTransform(&(mSize * mRot * mPos));
	Sprite->Draw(tex->texPtr, &rect, &Vec3(tex->info.Width / 2, tex->info.Height / 2, 0), NULL, D3DCOLOR_XRGB(255,255,255));
}

void cRenderManager::PrintText(wstring text, Vec3 pos, float size, D3DCOLOR color)
{
	Mat matWorld;
	D3DXMatrixTranslation(&matWorld, pos.x , pos.y, pos.z);
	Sprite->SetTransform(&matWorld);
	Font->DrawText(Sprite, text.c_str(), text.size(), nullptr, DT_CENTER, color);
}

void cRenderManager::Begin(bool isUi, bool isBill)
{
	if (isBill)
	{
		Sprite->SetWorldViewLH(NULL, &CAMERA->matView);
		Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE | D3DXSPRITE_BILLBOARD);
	}
	else
	{
		if (!isUi)
			Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		else
			Sprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
}

void cRenderManager::ReBegin(bool isUi, bool isBill)
{
	End(), Begin(isUi, isBill);
}

void cRenderManager::End()
{
	Sprite->End();
}

void cRenderManager::LostDevice()
{
	Sprite->OnLostDevice();
}

void cRenderManager::ResetDevice()
{
	Sprite->OnResetDevice();
}
