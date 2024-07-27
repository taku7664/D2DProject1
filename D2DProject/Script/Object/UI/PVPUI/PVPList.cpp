#include "PvpList.h"
#include "Data/Resource/LoadSpriteData.h"
#include "System/GameMode.h"
#include "System/GameManager.h"
#include "Script/Object/FadeRect.h"
#include "List.h"
#include "ListButton.h"
#include "SelectType.h"
#include "SelectMap.h"
#include "ArrowButton.h"
#include "PVPButton.h"
#include "World/PVPMap_Pup.h"

namespace PVPUI
{
	void PVPList::Start()
	{
		__super::Start();
		gameObject->depthsLevel = -1;
		uiSprite->SetSprite(LoadSprite::Pvp_List().Load());
		gameObject->transform->position =
			GameApp::GetScreenSize() - (uiSprite->size / 2) - Vector2(0, 100);
		Actor* actor;
		for (int i = 0; i < 8; i++)
		{
			
			actor = CreateObject<Actor>("playerList_" + std::to_string(i),
				LayerTag::UI, ObjectTag::UI);
			playerList[i] = actor->AddComponent<List>();
			playerList[i]->id = i;
			playerList[i]->gameObject->transform->SetParent(gameObject->transform);
			playerList[i]->gameObject->transform->position.x = -137;
			playerList[i]->gameObject->transform->position.y = (i * 23) - 53;
		}

		actor = CreateObject<Actor>("SelectMap",
			LayerTag::UI, ObjectTag::UI);
		actor->AddComponent<SelectMap>();
		actor->transform->SetParent(gameObject->transform);
		actor->transform->position.y = -112;

		actor = CreateObject<Actor>("RightArrowButton",
			LayerTag::UI, ObjectTag::UI);
		actor->transform->SetParent(gameObject->transform);
		actor->transform->position = Vector2(140,-110);
		rightArrow = actor->AddComponent<ArrowButton>();
		rightArrow->index = 0;

		actor = CreateObject<Actor>("LeftArrowButton",
			LayerTag::UI, ObjectTag::UI);
		actor->transform->SetParent(gameObject->transform);
		actor->transform->position = Vector2(-140, -110);
		leftArrow = actor->AddComponent<ArrowButton>();
		leftArrow->index = 2;

		actor = CreateObject<Actor>("StartButton",
			LayerTag::UI, ObjectTag::UI);
		actor->transform->SetParent(gameObject->transform);
		actor->transform->position = Vector2(-105, 137);
		startButton = actor->AddComponent<PVPButton>();
		startButton->index = 0;
	}

	void PVPList::Update()
	{
		for (int i = 0; i < 8; i++)
		{
			if (i < GameMode::playerList.size())
			{
				playerList[i]->bt->uiSprite->SetState(GameState::Active);
				playerList[i]->pt->uiSprite->SetState(GameState::Active);
				playerList[i]->bt->uiSprite->index = 1;
				if (dynamic_cast<Player*>(GameMode::playerList[playerList[i]->id]))
					playerList[i]->pt->uiSprite->index = 0;
				else playerList[i]->pt->uiSprite->index = 1;
			}
			else if (i == GameMode::playerList.size())
			{
				playerList[i]->bt->uiSprite->SetState(GameState::Active);
				playerList[i]->pt->uiSprite->SetState(GameState::Passive);
				playerList[i]->bt->uiSprite->index = 0;
			}
			else
			{
				playerList[i]->bt->uiSprite->SetState(GameState::Passive);
				playerList[i]->pt->uiSprite->SetState(GameState::Passive);
			}
		}
		if (GameMode::playerList.size() < 2)
		{
			startButton->index_ex = 1;
		}
		else
		{
			startButton->index_ex = 0;
			if (startButton->button->OnPress())
			{
				GameManager::fader->fadeType = 1;
				GameManager::fader->duration = 2;
				
			}
			if (GameManager::fader->FadeOutEnd())
			{
				WorldManager::ChangeWorld(WorldManager::CreateWorld<PVPMap_Pup>("PVPMap_Pup", WorldTag::Play));
				GameManager::fader->fadeType = -1;
			}
		}
	}
}