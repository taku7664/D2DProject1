#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorJump
		: public ICharactorFSM
	{
	public:
		bool isRun;
		int  clamp;
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}
