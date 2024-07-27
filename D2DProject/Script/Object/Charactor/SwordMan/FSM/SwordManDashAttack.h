#pragma once
#include "../../CommonFSM/Interface/ICharactorAttackFSM.h"

namespace FSM
{
	class SwordManDashAttack
		: public ICharactorAttackFSM
	{
	private:
	public:
		virtual void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}
