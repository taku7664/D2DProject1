#pragma once
#include "../../CommonFSM/CharatorBackStep.h"

namespace FSM
{
	class GunnerBackStep
		: public CharatorBackStep
	{
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit() {}
	};
}

