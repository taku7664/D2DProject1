#include "VaneSlashWave.h"
#include "Contents.h"

void VaneSlashWave::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);

	animator->AddAnimation("VaneSlashWave", LoadAnimation::VaneSlashWave().Load());
	animator->ChangeAnimation("VaneSlashWave", false);
	animator->renderOffset = { 120, -60 }; // x �������� ����, y �������� �Ʒ���

	HitBox->offset = { -130.f * gameObject->transform->scale.x, 60.f };
	HitBox->size = { 280,100 };
	HitBox->SetState(GameState::Passive);
}

void VaneSlashWave::Start()
{
}

void VaneSlashWave::Update()
{
	// =================���� ����=================
	animator->countScale = owner->attackSpd * 0.7f;

	target->gameObject->transform->position.y =
		MathF.Lerp<float>(target->gameObject->transform->position.y,
			gameObject->transform->WorldPosition().y, 10.f * Time::deltaTime);

	target->gameObject->transform->position.x =
		MathF.Lerp<float>(target->gameObject->transform->position.x,
			gameObject->transform->WorldPosition().x + animator->renderOffset.x * gameObject->transform->scale.x,
			7.f * Time::deltaTime);

	target->zPos = MathF.Lerp<float>(target->zPos,
			animator->renderOffset.y, 4.f * Time::deltaTime);

	target->gravity = 0.f;

	// =================���� ��Ʈ�ڽ� ����=================
	if (animator->IndexEnter(7))
		HitBox->SetState(GameState::Active);
	else if (animator->IndexEnter(9))
	{
		HitBox->SetState(GameState::Passive);
		Clear();
	}
	else if (animator->IndexEnter(11))
		HitBox->SetState(GameState::Active);
	else if (animator->IndexEnter(13))
	{
		HitBox->SetState(GameState::Passive);
		Clear();
	}
	else if (animator->IndexEnter(15))
		HitBox->SetState(GameState::Active);
	
	// =================����=================
	if (animator->End())
	{
		Destroy(gameObject);
	}
}