#include "SwordManJumpAttack.h"
#include "../../CharactorCore.h"
#include "SwordManJump.h"
#include "Script/Object/Interface/IAttackCore.h"

namespace FSM
{
	void SwordManJumpAttack::Start()
	{
		__super::Start();
		info.damagePer = 1.5f;
		info.yHitRange = 50.f;
		info.airPower = 250.0f;
		info.staggerTime = 0.0f;
		info.vPower = Vector2(200.0f, 0.0f);
		info.isLow = true;
		int i = 1;
		while (true)
		{
			Resource::FMODSound* sound = owner->soundPlayer->FindAudio("JumpAttack" + std::to_string(i++));
			if (sound)
			{
				voices.push_back(sound);
			}
			else break;
		}
	}
	void FSM::SwordManJumpAttack::StateEnter()
	{
		owner->animator->ChangeAnimation("JumpAttack", false);
		owner->state = CharactorState::Attack;
		hitBox = owner->CreateObject<Actor>("JumpAtk_HitBox", LayerTag::Object, ObjectTag::HitBox)
			->AddComponent<IAttackCore>();
		hitBox->Set(owner, info);
		hitBox->gameObject->SetActive(false);
		hitBox->HitBox->size = Vector2(120, 140);
		hitBox->HitBox->offset = Vector2(-50.f * owner->bodyActor->transform->scale.x, 60.f);

		owner->soundPlayer->Play(voices[Random::Range(0, voices.size() - 1)]);
	}

	void FSM::SwordManJumpAttack::StateUpdate()
	{
		// =================공격 히트박스 관련=================
		hitBox->gameObject->transform->position = owner->bodyActor->transform->WorldPosition();
		if (owner->animator->IndexEnter(2)) hitBox->gameObject->SetActive(true);
		if (owner->animator->IndexEnter(4)) hitBox->gameObject->SetActive(false);

		// =================플레이어 이동 연산=================
		if(!isBackstep)
			owner->SetMoveDirect();
		owner->zPos += owner->gravity * Time::deltaTime; 
		owner->gravity += owner->weight * owner->gravityScale * Time::deltaTime;
		owner->gameObject->transform->position +=
			owner->dirVector * owner->moveSpd *
			Time::deltaTime * Vector2(1.f + (float)isRun, 1.f);

		// =================플레이어 키 입력 및 애니메이션=================
		if (owner->animator->End())
		{
			FSM->ChangeState("Jump");
			owner->fsm->GetState<SwordManJump>("Jump")->isRun = isRun;
			owner->animator->ChangeAnimation("Jump", false);
			owner->animator->GotoAndPlay(3);
			return;
		}
		if (owner->gravity > 0)
		{
			if (owner->foot->CheckInteract(owner->body))
			{
				owner->isAirial = false;
				owner->zPos = 0.f;
				owner->gravity = 0.f;
				FSM->ChangeState("Idle");
				return;
			}
		}
	}
	void SwordManJumpAttack::StateExit()
	{
		isRun = false;
		owner->velocity = { 0,0 };
		hitBox->gameObject->SetDestroy();
	}
}