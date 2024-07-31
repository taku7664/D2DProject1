#include "GameManager.h"
#include "Contents.h"
#include "GameMode.h"

FadeRect* GameManager::fader = nullptr;
HUD::Timer* GameManager::timer = nullptr;
FMODPlayer* GameManager::BgmPlayer;
std::vector<Resource::FMODSound*> GameManager::bgms;
Resource::FMODSound* GameManager::roomBgm;

GameManager::GameManager()
{
	// BackGroundSound
	roomBgm = LoadSound::Room().Load();
	bgms.push_back(LoadSound::Bwanga().Load());
	bgms.push_back(LoadSound::Odesa().Load());
	bgms.push_back(LoadSound::Town().Load());
	bgms.push_back(LoadSound::Pub().Load());
	BgmPlayer = CreateObject<Actor>("BgmPlayer")->AddComponent<FMODPlayer>();
	FMODSystem::GetGroups()[0]->setVolume(0.1);
	FMODSystem::GetGroups()[1]->setVolume(0.1);
	FMODSystem::GetGroups()[2]->setVolume(0.1);
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