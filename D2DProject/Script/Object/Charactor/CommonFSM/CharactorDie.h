#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorDie
		: public ICharactorFSM
	{
	private:
	public:
		float startJump;
		float standTime;
		void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit() {}
	};
}