#pragma once
#include "../../CommonFSM/Interface/ICharactorFSM.h"

namespace FSM
{
	class SwordManHardAttack
		: public ICharactorFSM
	{
	private:
	public:
		void StateEnter();
		void StateUpdate();
		void StateExit() {}
	};
}
