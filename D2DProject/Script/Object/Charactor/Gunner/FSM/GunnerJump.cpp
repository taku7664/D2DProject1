#include "GunnerJump.h"
#include "../../CharactorCore.h"

namespace FSM
{
	void GunnerJump::StateEnter()
	{
		clamp = 2;
		__super::StateEnter();
	}

	void GunnerJump::StateUpdate()
	{
		__super::StateUpdate();
	}
}