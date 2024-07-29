#pragma once
#include "Interface/ICharactorFSM.h"

namespace FSM
{
	class CharactorHit
		: public ICharactorFSM
	{
	private:
	public:
		int preHp;
		float startJump;
		float standTime;
		float wakeTime;
		bool isAirbon;
		void StateEnter();
		void StateUpdate();
		void StateExit();
		void HitEnter(); // 맞을 때 마다 호출 됨
	};
}