#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorWalk
		: public ICharactorFSM
	{
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}
