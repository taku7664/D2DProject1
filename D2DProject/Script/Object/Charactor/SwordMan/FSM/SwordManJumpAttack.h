#pragma once
#include "../../CommonFSM/Interface/ICharactorAttackFSM.h"

namespace FSM
{
	class SwordManJumpAttack
		: public ICharactorAttackFSM
	{
	private:
	public:
		bool isRun = false;
		bool isBackstep = false;

		virtual void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}