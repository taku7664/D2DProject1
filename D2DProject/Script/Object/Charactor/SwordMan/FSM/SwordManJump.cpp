#include "SwordManJump.h"
#include "../../CharactorCore.h"
#include "SwordManJumpAttack.h"

namespace FSM
{
	void SwordManJump::Start()
	{
		clamp = 3;
		__super::Start();
	}
	void SwordManJump::StateEnter()
	{
		__super::StateEnter();
	}
	void SwordManJump::StateUpdate()
	{
		if (owner->gravity > -owner->jumpPower * 0.7f)
		{
			if (owner->TriggerKeyHold(owner->input.x))
			{
				FSM->ChangeState("JumpAttack");
				owner->fsm->GetState<SwordManJumpAttack>("JumpAttack")->isRun = isRun;
				owner->fsm->GetState<SwordManJumpAttack>("JumpAttack")->isBackstep = false;
				return;
			}
		}
		__super::StateUpdate();
	}
}