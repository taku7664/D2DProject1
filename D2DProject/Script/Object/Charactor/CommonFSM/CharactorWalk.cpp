#include "CharactorWalk.h"
#include "../CharactorCore.h"
#include "CharactorJump.h"

void FSM::CharactorWalk::StateEnter()
{
	owner->animator->ChangeAnimation("Walk");
	owner->state = CharactorState::Move;
}

void FSM::CharactorWalk::StateUpdate()
{
	if (owner->animator->IndexEnter(1))
	{
		owner->soundPlayer->Play(owner->runSound[Random::Range(0, owner->runSound.size() - 1)]);
		owner->soundPlayer->SetVolume(1.5f);
	}

	if (owner->animator->IndexEnter(5))
	{
		owner->soundPlayer->Play(owner->runSound[Random::Range(0, owner->runSound.size() - 1)]);
		owner->soundPlayer->SetVolume(1.5f);
	}

	if (CheckQuickKey(false)) // Äü½½·Ô Ã³¸®
		return;

	if (owner->TriggerKeyHold(owner->input.x))
	{
		FSM->ChangeState("BasicAttack1");
		return;
	}

	if (owner->TriggerKeyDown(owner->input.c))
	{
		if (owner->commandQueue[1] == owner->input.down)
			FSM->ChangeState("BackStep");
		else
		{
			FSM->ChangeState("Jump");
			owner->fsm->GetState<CharactorJump>("Jump")->isRun = false;
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
		owner->gameObject->transform->position += owner->dirVector * owner->moveSpd * Time::deltaTime;
		if (owner->dirVector.x != 0.f)
		{
			if (owner->dirVector.x >= 1.f) owner->bodyActor->transform->scale.x = 1.f;
			else owner->bodyActor->transform->scale.x = -1.f;
		}
	}
}

void FSM::CharactorWalk::StateExit()
{
}
