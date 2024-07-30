#include "SwordManIdle.h"
#include "../../CharactorCore.h"

void FSM::SwordManIdle::Start()
{
	__super::Start();
}

void FSM::SwordManIdle::StateEnter()
{
	__super::StateEnter();
	if (owner->TriggerKeyHold(owner->input.x))
	{
		if (owner->commandQueue[1] == owner->input.down)
		{
			FSM->ChangeState("Guard");
			return;
		}
	}
}

void FSM::SwordManIdle::StateUpdate()
{
	__super::StateUpdate();
}
