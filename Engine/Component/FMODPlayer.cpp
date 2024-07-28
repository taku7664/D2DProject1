#include "pch.h"
#include "FMODPlayer.h"
#include "../Resource/Manager/ResourceManager.h"

void FMODPlayer::SetAudio(Resource::FMODSound* _sound)
{
	if (!_sound) assert(false);
	m_audio = _sound;
}

void FMODPlayer::SetAudio(std::wstring _key)
{
		SetAudio(ResourceManager::GetFMODSound(_key));
}

void FMODPlayer::Play()
{
	m_audio->Play(&m_channel);
}

void FMODPlayer::Stop()
{
	if (m_channel)
	{
	}
}

void FMODPlayer::SetVolume(float _volume)
{
	if (m_channel)
	{
		m_channel->setVolume(_volume);
	}
}
