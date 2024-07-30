#include "SwordManBasicAttack3.h"
#include "Contents.h"
#include "../../CharactorCore.h"
#include "Script/Object/Interface/IAttackCore.h"

namespace FSM
{
	void SwordManBasicAttack3::Start()
	{
		__super::Start();
		info.damagePer = 1.5f;
		info.yHitRange = 50.f;
		info.airPower = 350.0f;
		info.staggerTime = 0.0f;
		info.vPower = Vector2(120.0f, 0.0f);
		info.isLow = true;
	}

	void FSM::SwordManBasicAttack3::StateEnter()
	{
		owner->animator->ChangeAnimation("BasicAttack3", false);
		owner->state = CharactorState::Attack;
		hitBox = owner->CreateObject<Actor>("Basic3_HitBox", LayerTag::Object, ObjectTag::HitBox)
			->AddComponent<IAttackCore>();
		hitBox->Set(owner, info);
		hitBox->gameObject->SetActive(false);
		hitBox->HitBox->size = Vector2(190, 170);
		hitBox->HitBox->offset = Vector2(-75.f * owner->bodyActor->transform->scale.x, 80.f);

		owner->soundPlayer->Play("Bassicattack3");
	}

	void FSM::SwordManBasicAttack3::StateUpdate()
	{
		// =================플레이어 키 입력 및 애니메이션=================
		if (CheckQuickKey(true))
			return;
		if (owner->TriggerKeyDown(owner->input.c) && owner->commandQueue[1] == owner->input.down)
		{
			FSM->ChangeState("BackStep");
			return;
		}
		if (owner->TriggerKeyHold(owner->input.z))
		{
			if (owner->skillList[LoadSkill::UpperSlash().id]->CanUse())
			{
				FSM->ChangeState("Upper");
				owner->skillList[LoadSkill::UpperSlash().id]->coolCount = 0;
				return;
			}
		}
		if (ChangeState_To_AniEnd("Idle")) return;
		// =================플레이어 돌진거리 연산=================
		owner->SetVelocityDirect();
		if (owner->animator->currentFrame >= 2 && owner->animator->currentFrame <= 5) {
			float factor = 0.7f; // 감소율 조정 (값이 작을수록 더 빠르게 감소)
			owner->velocity.x = 30.0f * pow(factor, owner->animator->currentFrame - 2) * Time::GetDeltaTime(1000);
		}
		else owner->velocity.x = 0.f;

		// =================공격 히트박스 관련=================
		hitBox->gameObject->transform->position = owner->gameObject->transform->position;

		if (owner->animator->IndexEnter(3)) hitBox->gameObject->SetActive(true);
		if (owner->animator->IndexEnter(5)) hitBox->gameObject->SetActive(false);
	}
	void SwordManBasicAttack3::StateExit()
	{
		owner->velocity = { 0,0 };
		hitBox->gameObject->SetDestroy();
	}
}