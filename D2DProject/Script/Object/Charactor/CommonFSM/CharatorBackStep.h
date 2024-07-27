#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharatorBackStep
		: public ICharactorFSM
	{
	public:
		int clamp;
		void StateEnter();
		void StateUpdate();
		void StateExit()
		{}
	};
}