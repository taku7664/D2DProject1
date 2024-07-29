#include "CountDown.h"
#include "Contents.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::CountDown::Start()
{
	__super::Start();
	soundPlayer = gameObject->AddComponent<FMODPlayer>();
	uiSprite->SetSprite(LoadSprite::CountDownSheet().Load());
	uiSprite->centerOffset = Vector2(-60, -70);
	count = 0;
	timer = 0.f;
	gameObject->transform->position = Vector2(400, 300);
	gameObject->transform->scale = Vector2(2, 2);

	sounds[0] = LoadSound::Count3().Load();
	sounds[1] = LoadSound::Count2().Load();
	sounds[2] = LoadSound::Count1().Load();
	sounds[3] = LoadSound::Fight().Load();

	soundPlayer->Play(sounds[0]);
}

void PVPUI::CountDown::Update()
{
	uiSprite->index = (count) + (4 * (int)(timer <= 0.1f));
	timer += Time::deltaTime;
	if (timer >= 1.f)
	{
		timer = 0.f;
		gameObject->transform->scale = Vector2(2, 2);
		count++;
		if (count != 4)
		{
			soundPlayer->Play(sounds[count]);
		}
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
	LoadSound::Count1().Release();
	LoadSound::Count2().Release();
	LoadSound::Count3().Release();
	LoadSound::Fight().Release();
}
