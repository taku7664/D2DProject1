#include "Timer.h"
#include "System/GameMode.h"
#include "Data/Resource/LoadSpriteData.h"

void HUD::Timer::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::TimerBar().Load());
	gameObject->transform->position =
		GameApp::GetScreenSize() - (uiSprite->size / 2) - Vector2(0, 30);

	for (int i = 0; i < 8; i++)
	{
		timeSprite[i] = gameObject->AddComponent<SpriteRenderer2D>();
		timeSprite[i]->SetSprite(LoadSprite::TimerSheet1().Load());
		timeSprite[i]->renderOffset = Vector2((uiSprite->size.x / 2) - (i * 28) - 30, 0.f);
	}
	timeSprite[2]->index = 10;
	timeSprite[5]->index = 11;
}
void HUD::Timer::Update()
{
	if (isStart)
	{
		timer -= Time::deltaTime;
	}
	else if (timer <= 0)
	{
		timer = 0.f;
		isStart = false;
	}
	float tempTimer = timer;
	int min = (int)tempTimer / 60;
	int sec = (int)tempTimer % 60;
	int ms = (tempTimer - (int)tempTimer) * 100.0f;
	if (min < 0) min = 0; if (sec < 0) sec = 0; if (ms < 0) ms = 0;
	timeSprite[0]->index = ms % 10;
	timeSprite[1]->index = ms / 10;
	timeSprite[3]->index = sec % 10;
	timeSprite[4]->index = sec / 10;
	timeSprite[6]->index = min % 10;
	timeSprite[7]->index = min / 10;
}

void HUD::Timer::SetTimer(float _time)
{
	timer = _time;
}

void HUD::Timer::Play()
{
	isStart = true;
}

void HUD::Timer::Stop()
{
	isStart = false;
}

bool HUD::Timer::IsEnd()
{
	return timer <= 0.f;
}