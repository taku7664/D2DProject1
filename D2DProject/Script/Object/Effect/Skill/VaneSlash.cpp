#include "VaneSlash.h"
#include "Contents.h"

void VaneSlash::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);

	animator->AddAnimation("VaneSlash", LoadAnimation::VaneSlash().Load());
	animator->ChangeAnimation("VaneSlash", false);
	animator->renderOffset = { 40, -80 }; // x 작을수록 왼쪽, y 작을수록 아래쪽
	
	HitBox->offset = { -80.f * gameObject->transform->scale.x, 80.f };
	HitBox->size = { 80,70 };
}

void VaneSlash::Start()
{
}

void VaneSlash::Update()
{
	animator->countScale = owner->attackSpd;
	if (animator->IndexEnter(4))
	{
		if (!IsHit())
		{
			Destroy(gameObject);
			return;
		}
		else
		{
			animator->SetState(GameState::Passive);
		}
	}
	else if (animator->IndexEnter(5))
	{
		int resDamage = CalculateDamage(collisionArr.front());
		CreateDamageEffect(collisionArr.front(), 1, resDamage);
	}
	if (animator->End())
	{
		Destroy(gameObject);
	}
}