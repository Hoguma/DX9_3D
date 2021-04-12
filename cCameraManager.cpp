#include "DXUT.h"
#include "cCameraManager.h"

cCameraManager::cCameraManager()
	:cameraPos(0,4400,-5600), at(0,0,0), up(0,1,0)
{
}

cCameraManager::~cCameraManager()
{
}

void cCameraManager::Update()
{
	if (isShake)
	{
		duration<float> sec = GetNowTime - shTime;
		if (sec.count() > shokeTime)
			isShake = false;
		float xS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float yS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float zS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		Shakepos += Vec3(xS, yS, zS);
	}
	D3DXVec3Lerp(&Shakepos, &Shakepos, &Vec3(0, 0, 0), 3 * DT);
}

void cCameraManager::SetTransform()
{
	D3DXMatrixLookAtLH(&matView, &(cameraPos + Shakepos), &(at + Shakepos), &up);
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 4.f / 3.f, 1.f, 50000.f);

	gDevice->SetTransform(D3DTS_VIEW, &matView);
	gDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cCameraManager::CameraShake(float time, float scale)
{
	isShake = true;
	shokeTime = time;
	shakeScale = scale;
	shTime = GetNowTime;
}

void cCameraManager::SetTarget(Vec3 target)
{
	cameraPos = Vec3(target.x , target.y + 4400, target.z - 5600);
	at = target;
}
