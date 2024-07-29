#include "GameManager.h"
#include "Contents.h"
#include "GameMode.h"

FadeRect* GameManager::fader = nullptr;
HUD::Timer* GameManager::timer = nullptr;

GameManager::GameManager()
{
	// BackGroundSound
	BgmPlayer = CreateObject<Actor>("BgmPlayer")->AddComponent<FMODPlayer>();
	BgmPlayer->Play(LoadSound::Odesa().Load());

	for (int i = 1; i <= 6; i++)
	{
		ResourceManager::AddSprite2D(L"DamageFont" + std::to_wstring(i),
			L"Sprite/FontSprite/DamageFont_Sheet" + std::to_wstring(i) + L".png", SpriteData(Vector2(10, 1)));
	}
	HUDs = CreateObject<Actor>("HUDOwner");
	HUDs->AddComponent<HUD::HUDOwner>();
	HUDs->SetPersistent(true);
	fader = CreateObject<Actor>("Fader", LayerTag::UI, ObjectTag::UI)->AddComponent<FadeRect>();
	SetPersistentObject(fader->gameObject, true);
	timer = CreateObject<Actor>("Timer", LayerTag::UI, ObjectTag::UI)->AddComponent<HUD::Timer>();
	SetPersistentObject(timer->gameObject, true);
}

GameManager::~GameManager()
{
	for (int i = 1; i <= 6; i++)
	{
		ResourceManager::ReleaseSprite2D(L"DamageFont" + std::to_wstring(i));
	}
}

void GameManager::Update()
{
	if (DynamicInput::KeyDown(1, 113))
	{
		if (Debug::IsActive())
		{
			Debug::Close_Console();
		}
		else
		{
			Debug::Get_Console();
		}
	}
}