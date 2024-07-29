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

    //for (int i = 0; i < m_channelGroups.size(); ++i)
    //{
    //    m_system->createChannelGroup(std::to_string(i).c_str(), &m_channelGroups[i]);
    //}
    //m_system->getMasterChannelGroup(&m_masterGroup);
    //for (const auto& group : m_channelGroups)
    //{
    //    m_masterGroup->addGroup(group);
    //}
}

void FMODSystem::Update()
{
    m_system->update();
}

void FMODSystem::AddGroup(const char* _groupName)
{
    if (!m_system) assert(false && "FMODSystem No Initialize");
    else
    {
        m_channelGroups.push_back(nullptr);
        m_system->createChannelGroup(_groupName, &m_channelGroups.back());
        m_masterGroup->addGroup(m_channelGroups.back());
    }   
}
