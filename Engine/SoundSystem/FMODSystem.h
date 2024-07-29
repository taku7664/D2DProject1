#pragma once
#include "ISoundSystem.h"

class FMODSystem
{
public:

    static void Initialize();
    static void Update();
    static void AddGroup(const char* _groupName);

    static FMOD::System* GetSystem() { return m_system; }
    static FMOD::ChannelGroup* GetGroup(int _group) 
    {
        if (_group >= m_channelGroups.size()) assert(false && "ChnnelGroup Range Over");
        else return m_channelGroups[_group];
    }

private:

	static FMOD::System*                    m_system;	// fmod 시스템
    static FMOD::ChannelGroup*              m_masterGroup; // 모든 그룹을 모아둔 마스터그룹
    static std::vector<FMOD::ChannelGroup*> m_channelGroups;

};