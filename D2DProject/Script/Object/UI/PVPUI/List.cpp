#include "List.h"
#include "ListButton.h"
#include "SelectType.h"
#include "System/GameMode.h"

#include "Script/Map/Interface/IMap.h"

namespace PVPUI
{
	void List::Start()
	{
		Actor* actor;
		actor = CreateObject<Actor>(gameObject->GetName() + "_Button", LayerTag::UI, ObjectTag::UI);
		actor->transform->SetParent(gameObject->transform);
		bt = actor->AddComponent<ListButton>();

		actor = CreateObject<Actor>(gameObject->GetName() + "_TypeButton", LayerTag::UI, ObjectTag::UI);
		actor->transform->SetParent(gameObject->transform);
		actor->transform->position.x = 40;
		pt = actor->AddComponent<SelectType>();
	}
	void List::Update()
	{
		if (bt->button->OnPress() && bt->GetState() == GameState::Active)
		{
			if (bt->uiSprite->index == 0)
			{
				CharactorCore* core;
				core = GameMode::AddPlayer<Player, SwordMan>(WorldManager::GetActiveWorld());
				IMap* map = FindObject<Actor>("Map", LayerTag::Map)->GetComponent<IMap>();
				Vector2 spawnPos = map->spawnPoint[Random::Range(0, map->spawnPoint.size() - 1)];
				core->gameObject->transform->position = spawnPos;
			}
			else
			{
				GameMode::RemovePlayer(id);
			}
		}
		if (pt->button->OnPress() && pt->GetState() == GameState::Active)
		{
			CharactorCore* core;
			if (bt->uiSprite->index == 1)
			{
				core = GameMode::RemoveAndAdd<AI, SwordMan>(id, WorldManager::GetActiveWorld());
			}
			else
			{
				core = GameMode::RemoveAndAdd<Player, SwordMan>(id, WorldManager::GetActiveWorld());
			}
			IMap* map = FindObject<Actor>("Map", LayerTag::Map)->GetComponent<IMap>();
			Vector2 spawnPos = map->spawnPoint[Random::Range(0, map->spawnPoint.size() - 1)];
			core->gameObject->transform->position = spawnPos;
		}
	}
};