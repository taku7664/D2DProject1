#include "HardAttack.h"
#include "Contents.h"

void HardAttack::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);
	animator->AddAnimation("HardAttack", LoadAnimation::HardAttack().Load());
	animator->ChangeAnimation("HardAttack", false);
	animator->renderOffset = { 100, -65 };

	HitBox->SetState(GameState::Passive);
	HitBox->offset = { -100.f * gameObject->transform->scale.x, 70.f };
	HitBox->size = { 200,140 };
}

void HardAttack::Start()
{
}

void HardAttack::Update()
{
	animator->countScale = owner->attackSpd;
	
	if (animator->currentFrame == 1)
	{
		HitBox->SetState(GameState::Active);
	}
	if (animator->currentFrame == 5)
	{
		HitBox->SetState(GameState::Passive);
	}
	if (animator->End())
	{
		Destroy(gameObject);
	}
}