#include "GunnerBackStep.h"
#include "../../CharactorCore.h"

void FSM::GunnerBackStep::StateEnter()
{
	clamp = 3;
	__super::StateEnter();
}

void FSM::GunnerBackStep::StateUpdate()
{
	__super::StateUpdate();
}
