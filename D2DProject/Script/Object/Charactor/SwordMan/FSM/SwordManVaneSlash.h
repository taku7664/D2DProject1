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
		float count = 0.f;
	public:

		ISkillCore* slashEffect;

		void Start();
		void StateEnter();
		void StateUpdate();
		void StateExit();
	};
}