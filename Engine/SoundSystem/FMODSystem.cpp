#include "pch.h"
#include "FMODSystem.h"
#include "../Resource/Manager/ResourceManager.h"

FMOD::System*                    FMODSystem::m_system;
FMOD::ChannelGroup*              FMODSystem::m_masterGroup;
std::vector<FMOD::ChannelGroup*> FMODSystem::m_channelGroups;

void FMODSystem::Initialize()
{
	// System Create
	FMOD::System_Create(&m_system);
	int number;
	// 채널 최대 개수를 받아와서 System초기화
	m_system->getSoftwareChannels(&number);
	m_system->init(number, FMOD_INIT_NORMAL, nullptr);

    for (int i = 0; i < m_channelGroups.size(); ++i)
    {
        m_system->createChannelGroup(std::to_string(i).c_str(), &m_channelGroups[i]);
    }
    m_system->getMasterChannelGroup(&m_masterGroup);
    for (const auto& group : m_channelGroups)
    {
        m_masterGroup->addGroup(group);
    }
}

void FMODSystem::Update()
{
    m_system->update();
}
// Initialize 이전에 미리 해줘야함
void FMODSystem::SetGroup(int _num)
{
    m_channelGroups.resize(_num);
}

void FMODSystem::Play(std::wstring _key, int _group, bool _isLoop)
{
    //m_system->playSound(ResourceManager::GetAudioClip(_key)->GetSound(), m_channelGroups[_group], false, );
}
