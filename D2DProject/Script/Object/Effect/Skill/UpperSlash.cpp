#include "UpperSlash.h"
#include "Contents.h"

void UpperSlash::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);
	
	animator->AddAnimation("UpperSlash", LoadAnimation::UpperSlash().Load());
	animator->ChangeAnimation("UpperSlash", false);
	animator->renderOffset = { 160, -100 };

	HitBox->offset = { -80.f * gameObject->transform->scale.x, 80.f };
	HitBox->size = { 180,170 };

	effectSounds.push_back(LoadSound::UpperSlash1().Load());
	effectSounds.push_back(LoadSound::UpperSlash2().Load());

	soundPlayer->Play(effectSounds[Random::Range(0,effectSounds.size() - 1)]);
}

void UpperSlash::Start()
{
}

void UpperSlash::Update()
{
	animator->countScale = owner->attackSpd;
	gameObject->transform->position = owner->bodyActor->transform->WorldPosition();

	if (animator->currentFrame == 3)
	{
		HitBox->SetState(GameState::Passive);
	}
	if (animator->End())
	{
		Destroy(gameObject);
	}
}