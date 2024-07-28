#pragma once
#include "AudioClip.h"

namespace Resource
{
	class FMODSound
		: public AudioClip
	{
	public:
		FMODSound(const std::wstring& _key, const std::wstring& _path, ResourceType _type, int _group);
		//FMOD::Sound* GetSound();

		void Play(FMOD::Channel** _channel);

	private:
		FMOD::System*		m_system;
		FMOD::Sound*		m_sound;
		FMOD::ChannelGroup* m_group;
	};
}