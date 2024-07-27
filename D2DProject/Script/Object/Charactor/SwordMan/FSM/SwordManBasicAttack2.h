#pragma once
#include "../../CommonFSM/Interface/ICharactorAttackFSM.h"
#include "Data/Skill/SkillData.h"

class IAttackCore;

namespace FSM
{
	class SwordManBasicAttack2
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

