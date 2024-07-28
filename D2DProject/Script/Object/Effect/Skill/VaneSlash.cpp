#include "VaneSlash.h"
#include "Contents.h"
#include "VaneSlashWave.h"

void VaneSlash::Set(IObjectCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);

	animator->AddAnimation("VaneSlash", LoadAnimation::VaneSlash().Load());
	animator->ChangeAnimation("VaneSlash", false);
	animator->renderOffset = { 40, -80 }; // x �������� ����, y �������� �Ʒ���
	
	HitBox->offset = { -60.f * gameObject->transform->scale.x, 80.f };
	HitBox->size = { 150,130 };
}

void VaneSlash::Start()
{
}

void VaneSlash::Update()
{
	animator->countScale = owner->attackSpd;
	if (animator->IndexEnter(2) && IsHit())
	{
		Actor* ef = owner->CreateObject<Actor>("Ef_VaneSlash", LayerTag::Object, ObjectTag::Particle);
		wave = ef->AddComponent<VaneSlashWave>();
		wave->target = collisionArr.front();
		wave->Set(owner, LoadSkill::VaneSlash().GetInfo("Wave"));
		HitBox->SetState(GameState::Passive);
	}
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