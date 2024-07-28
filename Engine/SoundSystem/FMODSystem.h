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

	static FMOD::System*                    m_system;	// fmod �ý���
    static FMOD::ChannelGroup*              m_masterGroup; // ��� �׷��� ��Ƶ� �����ͱ׷�
    static std::vector<FMOD::ChannelGroup*> m_channelGroups;

};