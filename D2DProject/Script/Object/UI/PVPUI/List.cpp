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
		if (bt->button->OnPress())
		{
			if (bt->uiSprite->index == 0)
			{
				Actor* player;
				if(GameMode::playerCount % 2 == 0)
					player = GameMode::AddPlayer<Player, SwordMan>(WorldManager::GetActiveWorld());
				else player = GameMode::AddPlayer<AI, SwordMan>(WorldManager::GetActiveWorld());
				IMap* map = FindObject<Actor>("Map", LayerTag::Map)->GetComponent<IMap>();
				Vector2 spawnPos = map->spawnPoint[rand() % map->spawnPoint.size()];
				player->transform->position = spawnPos;
			}
			else
			{
				GameMode::RemovePlayer(id);
			}
		}
	}
};