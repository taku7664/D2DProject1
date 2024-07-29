#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorWin
		: public ICharactorFSM
	{
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}