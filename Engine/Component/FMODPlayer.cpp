#include "pch.h"
#include "FMODPlayer.h"
#include "../Resource/Manager/ResourceManager.h"

Resource::FMODSound* FMODPlayer::AddAudio(std::string _key, Resource::FMODSound* _sound)
{
	if (_sound == nullptr)
		assert(false);

	if (this->FindAudio(_key) != nullptr)
		return nullptr;

	m_audioList.insert(std::make_pair(_key, _sound));

	return _sound;
}

Resource::FMODSound* FMODPlayer::FindAudio(std::string _key)
{
	auto it = m_audioList.find(_key);
	if (it == m_audioList.end())
		return nullptr;
	return it->second;
}

void FMODPlayer::Play(Resource::FMODSound* _sound)
{
	_sound->Play(&m_channel);
}

void FMODPlayer::Play(std::string _key)
{
	FindAudio(_key)->Play(&m_channel);
}

void FMODPlayer::Stop()
{
	if (m_channel)
	{
		m_channel->stop();
		m_channel = nullptr;
	}
}

void FMODPlayer::SetVolume(float _volume)
{
	if (m_channel)
	{
		m_channel->setVolume(_volume);
	}
}
