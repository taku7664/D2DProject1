#include "HardAttack.h"
#include "Contents.h"

void HardAttack::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);
	animator->AddAnimation("HardAttack", LoadAnimation::HardAttack().Load());
	animator->ChangeAnimation("HardAttack", false);
	animator->renderOffset = { 100, -65 };

	HitBox->offset = { -100.f * gameObject->transform->scale.x, 70.f };
	HitBox->size = { 200,140 };
	HitBox->SetState(GameState::Passive);

	gameObject->transform->scale *= GameMode::skillRangePer;
	HitBox->offset.y *= GameMode::skillRangePer;
	HitBox->size *= GameMode::skillRangePer;

	effectSounds.push_back(LoadSound::HardAttack1().Load());
	effectSounds.push_back(LoadSound::HardAttack2().Load());
	effectSounds.push_back(LoadSound::HardAttack3().Load());
	soundPlayer->Play(effectSounds[Random::Range(0, effectSounds.size() - 1)]);
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