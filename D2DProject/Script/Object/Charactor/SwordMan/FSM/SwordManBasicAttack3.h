#pragma once
#include "../../CommonFSM/Interface/ICharactorAttackFSM.h"

namespace FSM
{
	class SwordManBasicAttack3
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
