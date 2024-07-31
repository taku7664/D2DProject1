#pragma once
#include "Component.h"
#include "../Resource/FMODSound.h"

class FMODPlayer
	: public Component
{
public:
	virtual ~FMODPlayer() {}
	Resource::FMODSound* AddAudio(std::string _key, Resource::FMODSound* _sound);
	Resource::FMODSound* FindAudio(std::string _key);

	void Play(Resource::FMODSound* _sound);
	void Play(std::string _key);
	void Stop();
	void SetVolume(float _volume);

private:

	FMOD::Channel*		 m_channel;
	std::unordered_map<std::string, Resource::FMODSound*> m_audioList;
	

};