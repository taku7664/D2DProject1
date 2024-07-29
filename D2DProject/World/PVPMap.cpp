#include "PVPMap.h"
#include "Contents.h"
#include "Script/PlayerZoomer.h"
#include "Script/Map/Interface/IMap.h"

void PVPMap::WorldLoad()
{
}

void PVPMap::WorldDestroy()
{
	Clear(false);
	GameMode::isEnd = false;
	GameManager::BgmPlayer->Stop();
}

void PVPMap::WorldEnter()
{
	GameMode::curState = GameProcess::Zoom;
	Actor* actor;
	{
		actor = CreateObject<Actor>("CountDowner", LayerTag::Defalut, ObjectTag::Defalut);
		actor->AddComponent<PlayerZoomer>();
	}
	for (Actor*& player : GameMode::playerList)
	{
		IObjectCore* core = player->GetComponent<IObjectCore>();
		core->hp._cur = core->hp._max;
		core->mp._cur = core->mp._max;
		player->transform->position = mapCore->spawnPoint[Random::Range(0,mapCore->spawnPoint.size() - 1)];
		core->fsm->ChangeState("Idle");
		if (player->transform->position.x >= 0)
		{
			core->bodyActor->transform->scale.x = -1.f;
		}
		else core->bodyActor->transform->scale.x = 1.f;
	}
	GameManager::timer->SetTimer(240);
	GameManager::BgmPlayer->Play(GameManager::bgms[Random::Range(0, GameManager::bgms.size() - 1)]);
}

void PVPMap::WorldExit()
{
}