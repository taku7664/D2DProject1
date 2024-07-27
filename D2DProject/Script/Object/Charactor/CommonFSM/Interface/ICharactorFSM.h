#pragma once
#include "DemoApp.h"

class CharactorCore;

class ICharactorFSM
	:public Template_FSMState<CharactorCore>
{
public:
	virtual void Start();

	bool ProcessQuickKey(bool _isAttack);
	bool ChangeState_To_AniEnd(const std::string& _fsmName);


};

