#include "pch.h"
#include "FMODSound.h"
#include "../SoundSystem/FMODSystem.h"

Resource::FMODSound::FMODSound(const std::wstring& _key, const std::wstring& _path, ResourceType _type, bool _isLoop, int _group)
	: AudioClip(_key, _path, _type)
{
	std::string path;
	path.assign(_path.begin(), _path.end());
	m_system = FMODSystem::GetSystem();
	m_group = FMODSystem::GetGroup(_group);

	m_system->createSound(path.c_str(), _isLoop ? FMOD_LOOP_NORMAL : FMOD_DEFAULT, nullptr, &m_sound);
}

void Resource::FMODSound::Play(FMOD::Channel** _channel)
{
	m_system->playSound(m_sound, m_group, false, &*_channel);
}
