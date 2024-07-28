#include "pch.h"
#include "AudioClip.h"

Resource::AudioClip::AudioClip(const std::wstring& _key, const std::wstring& _path, ResourceType _type)
	: Resource(_key, _type)
{
	m_path = _path;
	//_system->createSound(path, isLoop ? FMOD_LOOP_NORMAL : FMOD_DEFAULT, nullptr, &_sound);
}
