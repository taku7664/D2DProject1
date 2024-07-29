#include "SwordManDashAttack.h"
#include "../../CharactorCore.h"
#include "Script/Object/Interface/IAttackCore.h"

namespace FSM
{
	void SwordManDashAttack::Start()
	{
		__super::Start();
		info.damagePer = 1.0f;
		info.yHitRange = 40.f;
		info.airPower = 0;
		info.staggerTime = 0.3f;
		info.vPower = Vector2(600.0f, 0.0f);
		info.isLow = false;
	}
	void SwordManDashAttack::StateEnter()
	{
		owner->animator->ChangeAnimation("DashAttack", false);
		owner->state = CharactorState::Attack;
		hitBox = owner->CreateObject<Actor>("DashAtk_HitBox", LayerTag::Object, ObjectTag::HitBox)
			->AddComponent<IAttackCore>();
		hitBox->Set(owner, info);
		hitBox->gameObject->SetActive(false);
		hitBox->HitBox->size = Vector2(130, 20);
		hitBox->HitBox->offset = Vector2(-80.0f * owner->bodyActor->transform->scale.x, 60.f);
		owner->soundPlayer->Play("DashAttack");
	}

	void SwordManDashAttack::StateUpdate()
	{
		// =================���� ��Ʈ�ڽ� ����=================
		hitBox->gameObject->transform->position = owner->gameObject->transform->position;
		if (owner->animator->IndexEnter(2)) hitBox->gameObject->SetActive(true);
		if (owner->animator->IndexEnter(4)) hitBox->gameObject->SetActive(false);
		// =================�÷��̾� �����Ÿ� ����=================
		owner->SetVelocityDirect();
		if (owner->animator->currentFrame >= 0 && owner->animator->currentFrame <= 5) {
			float factor = 0.5f; // ������ ���� (���� �������� �� ������ ����)
			owner->velocity.x = 100.0f * pow(factor, owner->animator->currentFrame) * Time::GetDeltaTime(1000);
		}
		else owner->velocity.x = 0.f;
		// =================�÷��̾� Ű �Է� �� �ִϸ��̼�=================
		if (ChangeState_To_AniEnd("Idle")) return;
	}
	void SwordManDashAttack::StateExit()
	{
		hitBox->gameObject->SetDestroy();
		owner->velocity = { 0,0 };
	}
}
