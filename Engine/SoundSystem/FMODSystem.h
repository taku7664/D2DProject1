#pragma once
#include "ISoundSystem.h"

class FMODSystem
{
public:

    static void Initialize();
    static void Update();
    static void SetGroup(int _num);

    static FMOD::System* GetSystem() { return m_system; }
    static FMOD::ChannelGroup* GetGroup(int _group) { return m_channelGroups[_group]; }

    static void Play(std::wstring _key, int _group, bool _isLoop);

private:

	static FMOD::System*                    m_system;	// fmod 시스템
    static FMOD::ChannelGroup*              m_masterGroup; // 모든 그룹을 모아둔 마스터그룹
    static std::vector<FMOD::ChannelGroup*> m_channelGroups;

};