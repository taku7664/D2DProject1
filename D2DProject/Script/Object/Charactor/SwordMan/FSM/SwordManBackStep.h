#pragma once
#include "../../CommonFSM/CharatorBackStep.h"

namespace FSM
{
	class SwordManBackStep
		: public CharatorBackStep
	{
	public:
		void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit() {}
	};
}

