#include "IMap.h"
#include "Contents.h"
#include "../../CameraController.h"

void IMap::Start()
{
	mainCamera = FindObject<Actor>("MainCamera", LayerTag::Defalut);
	cameraController = mainCamera->AddComponent<CameraController>();
	mainCamera->GetComponent<Camera2D>()->SetBackGroundColor(D2D1::ColorF(D2D1::ColorF::Black));
	mainCamera->transform->scale = { 1,1 };

	mapSprite = gameObject->AddComponent<SpriteRenderer2D>();
	backGround = CreateObject<Actor>("BackGround", LayerTag::BackGround, ObjectTag::Defalut);
	backGround->transform->SetParent(gameObject->transform);
	bgSprite = backGround->AddComponent<SpriteRenderer2D>();

	SetSpawnPoint();
}

void IMap::Update()
{
	backGround->transform->position.x =
		(mainCamera->transform->position.x + gameObject->transform->position.x) / 2;
}

void IMap::AddWallObject(Vector2 _pos, Vector2 _size)
{
	wallList.push_back(CreateObject<Actor>("Wall" + wallList.size(), LayerTag::Object, ObjectTag::HitBox));
	wallList.back()->transform->SetParent(gameObject->transform);
	wallList.back()->transform->position = _pos;
	Wall* wallobj = wallList.back()->AddComponent<Wall>();
	wallobj->wall->size = _size;
	wallobj->wall->SetRenderInfo(D2D1::ColorF(D2D1::ColorF::DarkBlue), 2.f);
}
