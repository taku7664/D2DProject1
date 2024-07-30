#include "CharactorIdle.h"
#include "../CharactorCore.h"
#include "System/GameMode.h"
#include "Contents.h"

namespace FSM
{
	void CharactorIdle::StateEnter()
	{
		owner->animator->ChangeAnimation("Idle");
		owner->state = CharactorState::Idle;
		owner->dirVector = { 0,0 };
		owner->velocity = { 0,0 };
		owner->zPos = 0.f;
	}

	void CharactorIdle::StateUpdate()
	{
		if (GameMode::curState == GameProcess::Ready ||
			GameMode::curState == GameProcess::Start ||
			GameMode::curState == GameProcess::Result)
		{
			if (owner->TriggerKeyHold(owner->input.right))
				owner->bodyActor->transform->scale.x = 1.f;
			else if (owner->TriggerKeyHold(owner->input.left))
				owner->bodyActor->transform->scale.x = -1.f;

			if (CheckQuickKey(false)) // Äü½½·Ô Ã³¸®
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
				FSM->ChangeState("BasicAttack1");
				return;
			}

			if (owner->TriggerKeyDown(owner->input.c))
			{
				FSM->ChangeState("Jump");
				owner->soundPlayer->Play("Jump");
				return;
			}

			if (owner->TriggerKeyDown(owner->input.c))
			{
				if (owner->commandQueue[1] == owner->input.down)
					FSM->ChangeState("BackStep");
				else FSM->ChangeState("Jump");
				return;
			}

			if (owner->TriggerKeyHold(owner->input.left))
			{
				if (owner->commandQueue[1] == owner->input.left)
					FSM->ChangeState("Run");
				else FSM->ChangeState("Walk");
				owner->dirVector.x = -1;
				return;
			}
			else if (owner->TriggerKeyHold(owner->input.right))
			{
				if (owner->commandQueue[1] == owner->input.right)
					FSM->ChangeState("Run");
				else FSM->ChangeState("Walk");
				owner->dirVector.x = 1;
				return;
			}
			if (owner->TriggerKeyHold(owner->input.up))
			{
				FSM->ChangeState("Walk");
				owner->dirVector.y = -1;
				return;
			}
			else if (owner->TriggerKeyHold(owner->input.down))
			{
				FSM->ChangeState("Walk");
				owner->dirVector.y = 1;
				return;
			}
		}
		else if (GameMode::curState == GameProcess::End)
		{
			if(GameMode::CheckWinner() == owner)
				FSM->ChangeState("Win");
		}
	}

	void CharactorIdle::StateExit()
	{
	}
}