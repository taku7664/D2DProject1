#pragma once
#include "../../CommonFSM/CharactorJump.h"

namespace FSM
{
	class GunnerJump
		: public CharactorJump
	{
	private:
	public:
		void StateEnter();
		void StateUpdate();
	};
}


