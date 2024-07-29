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
	// ĳ���͸� ���⺤�Ϳ� ������ġ�� ���Ѱ��� ������Ŵ
	gameObject->transform->position += velocity * dirVector * Time::deltaTime;
	// ��ü ������Ʈ�� y�� = zPos
	bodyActor->transform->position.y = zPos;
	bodyActor->depthsLevel = gameObject->transform->position.y;
}

void IObjectCore::OnDestroy()
{
	if (bodyActor)
		Destroy(bodyActor);
}
