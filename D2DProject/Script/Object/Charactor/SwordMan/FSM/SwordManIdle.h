#pragma once
#include "../../CommonFSM/CharactorIdle.h"

namespace FSM
{
	class SwordManIdle
		: public CharactorIdle
	{
	private:
	public:
		void Start();
		void StateEnter();
		void StateUpdate();
	};
}