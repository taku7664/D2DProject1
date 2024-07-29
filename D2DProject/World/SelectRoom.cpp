#include "SelectRoom.h"
#include "Contents.h"
#include "../Script/Object/UI/PVPUI/PVPList.h"
#include "Script/Map/Pup.h"

void SelectRoom::WorldLoad()
{
}

void SelectRoom::WorldDestroy()
{
}

void SelectRoom::WorldEnter()
{
	GameMode::curState = GameProcess::Ready;
	Actor* actor;
	// ¸Ê
	{
		actor = CreateObject<Actor>("Map", LayerTag::Map, ObjectTag::Defalut);
		actor->AddComponent<MAP::Pup>();
	}
	{
		actor = CreateObject<Actor>("pvp_list", LayerTag::UI, ObjectTag::UI);
		actor->AddComponent<PVPUI::PVPList>();
	}
	GameManager::BgmPlayer->Play(GameManager::roomBgm);
}

void SelectRoom::WorldExit()
{
	GameManager::BgmPlayer->Stop();
	LoadSprite::Pup_BackGround().Release();
	LoadSprite::Pup_Map().Release();
}