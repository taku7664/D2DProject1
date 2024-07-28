#include "SwordManBackStep.h"
#include "Data/Skill/LoadSwordManSkillData.h"
#include "../../CharactorCore.h"
#include "SwordManJumpAttack.h"

void FSM::SwordManBackStep::StateEnter()
{
	clamp = 5;
	__super::StateEnter();
}

void FSM::SwordManBackStep::StateUpdate()
{
	__super::StateUpdate();
	if (owner->TriggerKeyDown(owner->input.x))
	{
		if (owner->skillList[LoadSkill::BackStepCutter().id]->CanUse())
		{
			FSM->ChangeState("JumpAttack");
			owner->fsm->GetState<SwordManJumpAttack>("JumpAttack")->isRun = true;
			owner->fsm->GetState<SwordManJumpAttack>("JumpAttack")->isBackstep = true;
			owner->skillList[LoadSkill::BackStepCutter().id]->coolCount = 0;
			return;
		}
	}
}