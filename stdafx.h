#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "SDKsound.h"

#pragma comment (lib, "dsound.lib")

using namespace std;
using namespace chrono;

using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;
using Vec4 = D3DXVECTOR4;
using Mat = D3DXMATRIX;
using Quat = D3DXQUATERNION;
using Tag = int;
using Color = D3DXCOLOR;

const static float WINSIZEX = 1280;
const static float WINSIZEY = 720;

#define gDevice DXUTGetD3D9Device()
#define GetNowTime system_clock::now()
#define DT DXUTGetElapsedTime()

#ifdef _DEBUG()
#define Debug_Log(log) cout << log << endl;
#endif
#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

template <typename T>
void Lerp(T* target, const T& start, const T& end, float speed)
{
	*target = start + speed * (end - start);
}



#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")

#include "MeshLoader.h"
#include "cScene.h"
#include "cObject.h"
#include "cCollider.h"

#include "cLoadManager.h"
#include "cRenderManager.h"
#include "cCameraManager.h"
#include "cInputManager.h"
#include "cSceneManager.h"
#include "cCollisionManager.h"
#include "cObjectManager.h"
#include "cSoundManager.h"
#include "cGameManager.h"