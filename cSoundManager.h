#pragma once
#include "singleton.h"
class cSoundManager :
    public singleton<cSoundManager>
{
public:
    CSoundManager SoundManager;
    map<wstring, CSound*> MSound;
public:
    cSoundManager();
    ~cSoundManager();

    CSound* GetSound(wstring key);
    void AddSound(wstring key, wstring path);

    list<LPDIRECTSOUNDBUFFER> m_channels;

    void Update();
    void SoundPlay(CSound* sound, int Volumn, bool loop);
    void SoundStopAll();
};

#define SOUND cSoundManager::Get()