#pragma once
#include "../../CommonFSM/Interface/ICharactorFSM.h"

namespace FSM
{
	class SwordManHardAttack
		: public ICharactorFSM
	{
	private:
	public:
		void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit() {}
	};
}
