#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorRun
		: public ICharactorFSM
	{
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit()
		{}
	};
}