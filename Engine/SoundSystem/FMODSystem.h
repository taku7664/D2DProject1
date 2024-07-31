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
    static FMOD::ChannelGroup* GetMasterGroup() { return m_masterGroup; }
    static  std::vector<FMOD::ChannelGroup*>& GetGroups() { return m_channelGroups; }
private:

	static FMOD::System*                    m_system;	// fmod �ý���
    static FMOD::ChannelGroup*              m_masterGroup; // ��� �׷��� ��Ƶ� �����ͱ׷�
    static std::vector<FMOD::ChannelGroup*> m_channelGroups;

};