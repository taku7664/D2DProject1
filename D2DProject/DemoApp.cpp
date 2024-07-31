#include "DemoApp.h"
#include "Data/Resource/LoadSpriteData.h"
#include "Data/Resource/LoadSoundData.h"
#include "World/MainTitle.h"
#include "World/SelectRoom.h"
#include "World/PVPMap_Pup.h"
#include "System/GameManager.h"

void DemoApp::Initialize(HINSTANCE _hinstance, int _width, int _height, const wchar_t* _title)
{
	__super::Initialize(_hinstance, _width, _height, _title);
	CollisionManager::ProcessCycle = 1;
	CollisionManager::SetCollsionLayer(LayerTag::Object, true);
	LoadResource();
	LoadWorld();
	gameManager = new GameManager();
}

void DemoApp::Release()
{
	__super::Release();
	LoadSprite::SwordManSheet1().Release();
	LoadSprite::SwordManSheet2().Release();
	LoadSprite::GunnerSheet1().Release();
	LoadSprite::GunnerSheet2().Release();
	LoadSprite::UpperSlashSheet1().Release();
	LoadSprite::HardAttackSheet1().Release();
}

void DemoApp::LoadWorld()
{
	WorldManager::CreateWorld<MainTitle>("Title", WorldTag::Title);
	WorldManager::CreateWorld<SelectRoom>("SelectRoom", WorldTag::Play);
	//WorldManager::ChangeWorld("Title");
	WorldManager::ChangeWorld("SelectRoom");
}

void DemoApp::LoadResource()
{
	ResourceManager::AddFont(L"던파 비트비트체 v2", L"Font/DNFBitBitv2.ttf");

	FMODSystem::AddGroup("BackGround");
	FMODSystem::AddGroup("Effect");
	FMODSystem::AddGroup("Voice");

	LoadSound::Odesa().Load();
	LoadSound::Bwanga().Load();
	LoadSound::Pub().Load();
	LoadSound::Town().Load();

	LoadSprite::SwordManSheet1().Load();
	LoadSprite::SwordManSheet2().Load();
	LoadSprite::GunnerSheet1().Load();
	LoadSprite::GunnerSheet2().Load();
	LoadSprite::UpperSlashSheet1().Load();
	LoadSprite::HardAttackSheet1().Load();
	LoadSprite::VaneSlashSheet1().Load();
	LoadSprite::VaneSlashSheet2().Load();
}

