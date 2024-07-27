#include "CountDown.h"
#include "System/GameMode.h"
#include "System/GameManager.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::CountDown::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::CountDownSheet().Load());
	uiSprite->centerOffset = Vector2(-60, -70);
	count = 0;
	timer = 0.f;
	gameObject->transform->position = Vector2(400, 300);
	//gameObject->transform->position = (uiSprite->size / 2) - Vector2(100,100);
	gameObject->transform->scale = Vector2(2, 2);
}

void PVPUI::CountDown::Update()
{
	uiSprite->index = (count) + (4 * (int)(timer <= 0.1f));
	timer += Time::deltaTime;
	if (timer >= 1.f)
	{
		timer = 0.f;
		++count;
		gameObject->transform->scale = Vector2(2, 2);
	}
	if (count == 4)
	{
		Destroy(gameObject);
		return;
	}
	else if(count == 3)
	{
		GameManager::timer->Play();
		GameMode::curState = GameProcess::Start;
	}
	if (gameObject->transform->scale.x > 1.f)
	{
		gameObject->transform->scale -= gameObject->transform->scale * 4.f * Time::deltaTime;
	}
	if (gameObject->transform->scale.x <= 1.f)
	{
		gameObject->transform->scale = Vector2::One;
	}
}

void PVPUI::CountDown::OnDestroy()
{
	LoadSprite::CountDownSheet().Release();
}
