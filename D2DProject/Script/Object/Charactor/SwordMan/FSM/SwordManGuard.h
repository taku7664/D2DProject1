#pragma once
#include "../../CommonFSM/Interface/ICharactorFSM.h"

namespace FSM
{
	class SwordManGuard
		: public ICharactorFSM
	{
		float guardTime = 0.f;
	public:
		void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}