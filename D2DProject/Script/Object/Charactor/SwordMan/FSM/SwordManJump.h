#pragma once
#include "../../CommonFSM/CharactorJump.h"

namespace FSM
{
	class SwordManJump
		: public CharactorJump
	{
	private:
	public:
		void Start();
		void StateEnter();
		void StateUpdate();
	};
}