#pragma once
#include "Component.h"
#include "../Resource/FMODSound.h"

class FMODPlayer
	: public Component
{
public:

	void SetAudio(Resource::FMODSound* _sound);
	void SetAudio(std::wstring _key);

	void Play();
	void Stop();
	void SetVolume(float _volume);

private:

	Resource::FMODSound*	m_audio;
	FMOD::Channel*			m_channel;

};