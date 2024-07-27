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
	HitBox->offset.y *= GameMode::skillRangePer;
	HitBox->size *= GameMode::skillRangePer;
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