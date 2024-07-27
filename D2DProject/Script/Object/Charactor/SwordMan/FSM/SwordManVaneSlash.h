#pragma once
#include "../../CommonFSM/Interface/ICharactorFSM.h"

class ISkillCore;
class IObjectCore;

namespace FSM
{
	class SwordManVaneSlash
		: public ICharactorFSM
	{
	private:
	public:

		IObjectCore* targetCore = nullptr;

		ISkillCore* slashEffect;

		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}