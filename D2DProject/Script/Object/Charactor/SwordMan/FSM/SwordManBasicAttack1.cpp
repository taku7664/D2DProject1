#include "SwordManBasicAttack1.h"
#include "Contents.h"
#include "../../CharactorCore.h"
#include "Script/Object/Interface/IAttackCore.h"

namespace FSM
{
	void SwordManBasicAttack1::Start()
	{
		__super::Start();
		info.damagePer = 1.f;
		info.yHitRange = 50.f;
		info.airPower = 0.f;
		info.staggerTime = 0.5f;
		info.vPower = Vector2(120.0f, 0.0f);
		info.isLow = false;
	}

	void FSM::SwordManBasicAttack1::StateEnter()
	{
		owner->animator->ChangeAnimation("BasicAttack1", false);
		owner->state = CharactorState::Attack;
		hitBox = owner->CreateObject<Actor>("Basic1_HitBox", LayerTag::Object, ObjectTag::HitBox)
			->AddComponent<IAttackCore>();
		hitBox->Set(owner, info);
		hitBox->gameObject->SetActive(false);
		hitBox->HitBox->size = Vector2(180, 130);
		hitBox->HitBox->offset = Vector2(-55.f * owner->bodyActor->transform->scale.x, 60.f);

		owner->soundPlayer->Play("Bassicattack1");
	}

	void FSM::SwordManBasicAttack1::StateUpdate()
	{
		// =================�÷��̾� Ű �Է� �� �ִϸ��̼�=================
		if (ProcessQuickKey(true)) 
			return;
		if (owner->TriggerKeyDown(owner->input.c) && owner->commandQueue[1] == owner->input.down)
		{
			FSM->ChangeState("BackStep");
			return;
		}
		// ������ �������� �Ǿ��� ��,
		if (owner->animator->currentFrame == owner->animator->FrameSize() - 1)
		{
			if (ChangeState_To_AniEnd("Idle")) return;
			else if (owner->animator->frameCount > owner->animator->GetAnimationData().duration * 0.5)
			{
				if (owner->TriggerKeyHold(owner->input.x))
				{
					FSM->ChangeState("BasicAttack2");
					return;
				}
			}
			else if (owner->TriggerKeyDown(owner->input.x))
			{
				FSM->ChangeState("BasicAttack2");
				return;
			}
		}
		// =================�÷��̾� �����Ÿ� ����=================
		owner->SetVelocityDirect();
		if (owner->animator->currentFrame >= 2 && owner->animator->currentFrame <= 5) {
			float factor = 0.7f; // ������ ���� (���� �������� �� ������ ����)
			owner->velocity.x = 30.0f * pow(factor, owner->animator->currentFrame - 2) * Time::GetDeltaTime(1000);
		}
		else owner->velocity.x = 0.f;

		// =================���� ��Ʈ�ڽ� ����=================
		hitBox->gameObject->transform->position = owner->gameObject->transform->position;

		if (owner->animator->IndexEnter(3)) hitBox->gameObject->SetActive(true);
		if (owner->animator->IndexEnter(5)) hitBox->gameObject->SetActive(false);
	}
	void SwordManBasicAttack1::StateExit()
	{
		hitBox->gameObject->SetDestroy();
		owner->velocity = { 0,0 };
	}
}
