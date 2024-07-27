#include "HUDOwner.h"
#include "System/GameMode.h"

void HUD::HUDOwner::Start()
{
	for (int i = 0; i < 8; i++)
	{
		Actor* hud = CreateObject<Actor>("UpperHUD" + i, LayerTag::UI, ObjectTag::UI);
		hud->SetPersistent(true);
		upperHUDs[i] = hud->AddComponent<UpperHUD>();
		upperHUDs[i]->id = i;
		upperHUDs[i]->gameObject->transform->position =
			Vector2(200 * (i % 4), 60 * (i / 4));
	}
}

void HUD::HUDOwner::Update()
{
	for (int i = 0; i < 8; i++)
	{
		if (GameMode::playerList.size() > i)
		{
			upperHUDs[i]->targetObject =
				GameMode::playerList[i]->GetComponent<CharactorCore>(ComponentType::Script);
			upperHUDs[i]->gameObject->SetActive(true);
		}
		else
		{
			upperHUDs[i]->targetObject = nullptr;
			upperHUDs[i]->gameObject->SetActive(false);
		}
	}
}
