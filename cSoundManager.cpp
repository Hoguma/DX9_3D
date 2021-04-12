#include "DXUT.h"
#include "cSoundManager.h"

cSoundManager::cSoundManager()
{
    SoundManager.Initialize(DXUTGetHWND(), 1);
}

cSoundManager::~cSoundManager()
{
	SoundStopAll();
    for (auto& iter : MSound)
    {
        SAFE_DELETE(iter.second);
    }
    MSound.clear();
}

CSound* cSoundManager::GetSound(wstring key)
{
    if (auto find = MSound.find(key); find != MSound.end())
        return find->second;
}

void cSoundManager::AddSound(wstring key, wstring path)
{
    CSound** sound = new CSound * ();
    wchar_t Path[128];
    swprintf(Path, L"./Resource/Sound/%s.wav", path.c_str());
    SoundManager.Create(sound, Path, DSBCAPS_CTRLVOLUME);
    MSound.insert(make_pair(key, (*sound)));
    delete sound;
}

void cSoundManager::Update()
{
	DWORD status;
	for (auto& iter = m_channels.begin(); iter != m_channels.end();)
	{
		(*iter)->GetStatus(&status);
		if ((status & DSBSTATUS_PLAYING) == false)
		{
			(*iter)->Release();
			iter = m_channels.erase(iter);
		}
		else
			iter++;
	}
}

void cSoundManager::SoundPlay(CSound* sound, int Volumn, bool loop)
{
	LPDIRECTSOUNDBUFFER sb;
	SoundManager.GetDirectSound()->DuplicateSoundBuffer(sound->GetBuffer(0), &sb);
	sb->Play(0, 0, loop == true ? DSBPLAY_LOOPING : 0);
	sb->SetVolume(Volumn);
	m_channels.push_back(sb);
}

void cSoundManager::SoundStopAll()
{
	for (auto& iter : m_channels) iter->Release();
	m_channels.clear();
}