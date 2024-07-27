#include "Pup.h"
#include "Data/Resource/LoadSpriteData.h"
#include "../CameraController.h"

void MAP::Pup::Start()
{
	__super::Start();
	mapSprite->SetSprite(LoadSprite::Pup_Map().Load());
	bgSprite->SetSprite(LoadSprite::Pup_BackGround().Load());

	gameObject->transform->position = Vector2(0, 80);
	backGround->transform->position = Vector2(0, -200);

	cameraController->limitRange = Rect_F(
		mapSprite->Left(),
		mapSprite->Top(),
		mapSprite->Right(),
		mapSprite->Down() - 150);

	AddWallObject(Vector2(70, -65), Vector2(330, 50));
	AddWallObject(Vector2(0, -95), Vector2(2000, 50));
	AddWallObject(Vector2(0, 250), Vector2(2000, 50));
	AddWallObject(Vector2(-480, -90), Vector2(50, 700));
	AddWallObject(Vector2(600, -90), Vector2(50, 700));
	
}
void MAP::Pup::OnDestroy()
{
	LoadSprite::Pup_Map().Release();
	LoadSprite::Pup_BackGround().Release();
}

void MAP::Pup::SetSpawnPoint()
{
	spawnPoint.push_back(Vector2(0, 100));
	spawnPoint.push_back(Vector2(-200, 100));
	spawnPoint.push_back(Vector2(200, 100));
	spawnPoint.push_back(Vector2(-200, 200));
	spawnPoint.push_back(Vector2(200, 200));
	spawnPoint.push_back(Vector2(-400, 100));
	spawnPoint.push_back(Vector2(400, 100));
	spawnPoint.push_back(Vector2(-400, 200));
	spawnPoint.push_back(Vector2(400, 200));
}

