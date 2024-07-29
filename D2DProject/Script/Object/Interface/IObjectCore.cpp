#include"IObjectCore.h"

void IObjectCore::Start()
{
	dirVector = Vector2(0, 0);
	bodyActor = CreateObject<BodyActor>("Body", LayerTag::Object, ObjectTag::BodyBox);
	foot = gameObject->AddComponent<BoxCollider2D>();
	body = bodyActor->AddComponent<BoxCollider2D>();
	soundPlayer = gameObject->AddComponent<FMODPlayer>();
	bodyActor->transform->SetParent(gameObject->transform);
}

void IObjectCore::Update()
{
	pvpInfo.Update();
}

void IObjectCore::LateUpdate()
{
	// 캐릭터를 방향벡터에 물리수치를 곱한값을 증가시킴
	gameObject->transform->position += velocity * dirVector * Time::deltaTime;
	// 몸체 오브젝트의 y값 = zPos
	bodyActor->transform->position.y = zPos;
	bodyActor->depthsLevel = gameObject->transform->position.y;
}

void IObjectCore::OnDestroy()
{
	if (bodyActor)
		Destroy(bodyActor);
}
