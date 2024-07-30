#include "PlayerZoomer.h"
#include "System/GameMode.h"
#include "System/GameManager.h"
#include "Script/Object/FadeRect.h"
#include "CameraController.h"
#include "Object/UI/PVPUI/CountDown.h"

void PlayerZoomer::Start()
{ 
	Actor* camera = FindObject<Actor>("MainCamera", LayerTag::Defalut);
	cameraController = camera->GetComponent<CameraController>();
}

void PlayerZoomer::Update()
{
	if (GameManager::fader->FadeInEnd())
	{
		timer += Time::deltaTime;
		if (timer >= 1.5f)
		{
			++index;
			timer = 0.f;
		}
		if (index < GameMode::playerList.size())
		{
			cameraController->targetActor = GameMode::playerList[index]->gameObject;
		}
		else
		{
			cameraController->targetActor = nullptr;
			GameMode::curState = GameProcess::Count;
			CreateObject<Actor>("CountDowner", LayerTag::UI, ObjectTag::UI)->AddComponent<PVPUI::CountDown>();
			Destroy(gameObject);
		}
	}
}