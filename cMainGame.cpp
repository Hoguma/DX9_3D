#include "DXUT.h"
#include "cMainGame.h"
#include "cStage1.h"
#include "cShop.h"

void cMainGame::Init()
{
	srand(time(0));
	AddResource();
	SCENE->AddScene("Stage1", new cStage1);
	SCENE->AddScene("Shop", new cShop);
	SCENE->ChangeScene("Stage1");
}

void cMainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	CAMERA->Update();
	COLL->Update();
	SOUND->Update();
}

void cMainGame::Render()
{
	CAMERA->SetTransform();
	RENDER->Begin(false, false);
	SCENE->Render();
	RENDER->End();
}

void cMainGame::Release()
{
	cCameraManager::Del();
	cInputManager::Del();
	cObjectManager::Del();
	cLoadManager::Del();
	cRenderManager::Del();
	cSceneManager::Del();
	cCollisionManager::Del();
	cSoundManager::Del();
	cGameManager::Del();
}

void cMainGame::Reset()
{
	RENDER->ResetDevice();
}

void cMainGame::Lost()
{
	RENDER->LostDevice();
}

void cMainGame::AddResource()
{
	LOAD->AddMesh(L"Player", L"Player/Player01");

	LOAD->AddTexture(L"HomingMissile", L"HomingMissile");
	LOAD->AddTexture(L"Coin", L"Coin");
}
