#include "CharactorRun.h"
#include "Contents.h"
#include "../CharactorCore.h"
#include "CharactorJump.h"

void FSM::CharactorRun::StateEnter()
{
	owner->animator->ChangeAnimation("Run");
	owner->state = CharactorState::Move;
}

void FSM::CharactorRun::StateUpdate()
{
	if (owner->animator->IndexEnter(1) || owner->animator->IndexEnter(5))
	{
		owner->soundPlayer->Play(owner->runSound[Random::Range(0, owner->runSound.size() - 1)]);
		owner->soundPlayer->SetVolume(2.f);
	}

	if (CheckQuickKey(false)) // ������ ó��
		return;	

	if (owner->TriggerKeyHold(owner->input.z))
	{
		if (owner->skillList[LoadSkill::UpperSlash().id]->CanUse())
		{
			FSM->ChangeState("Upper");
			owner->skillList[LoadSkill::UpperSlash().id]->coolCount = 0;
			return;
		}
	}

	if (owner->TriggerKeyHold(owner->input.x))
	{
		FSM->ChangeState("DashAttack");
		return;
	}
	if (owner->TriggerKeyDown(owner->input.c))
	{
		if (owner->commandQueue[1] == owner->input.down)
			FSM->ChangeState("BackStep");
		else
		{
			FSM->ChangeState("Jump");
			owner->fsm->GetState<CharactorJump>("Jump")->isRun = true;
		}
		return;
	}

	owner->SetMoveDirect();

	if (owner->dirVector == Vector2::Zero)
	{
		if (owner->TriggerKeyUp(owner->input.left))
			owner->commandQueue.push(owner->input.left);
		else if (owner->TriggerKeyUp(owner->input.right))
			owner->commandQueue.push(owner->input.right);
		FSM->ChangeState("Idle");
	}
	else
	{
		owner->gameObject->transform->position += owner->dirVector * owner->moveSpd * Time::deltaTime * Vector2(2.f, 1.f);
		if (owner->dirVector.x != 0.f)
		{
			if (owner->dirVector.x >= 1.f) owner->bodyActor->transform->scale.x = 1.f;
			else owner->bodyActor->transform->scale.x = -1.f;
		}
	}
}
