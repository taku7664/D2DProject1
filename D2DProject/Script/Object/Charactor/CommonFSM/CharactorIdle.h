#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorIdle
		: public ICharactorFSM
	{
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}