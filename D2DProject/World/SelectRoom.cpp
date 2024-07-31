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
	LoadSprite::Pup_Map().Load();
	LoadSprite::Pup_BackGround().Load();
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
	for (IObjectCore* core : GameMode::playerList)
	{
		core->hp._cur = core->hp._max;
		core->mp._cur = core->mp._max;
		core->fsm->ChangeState("Idle");
		if (core->gameObject->transform->position.x >= 0)
		{
			core->bodyActor->transform->scale.x = -1.f;
		}
		else core->bodyActor->transform->scale.x = 1.f;
	}
	GameManager::BgmPlayer->Play(GameManager::roomBgm);
}

void SelectRoom::WorldExit()
{
	GameManager::BgmPlayer->Stop();
}