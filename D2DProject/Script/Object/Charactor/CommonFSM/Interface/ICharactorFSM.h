#pragma once
#include "DemoApp.h"

class CharactorCore;

class ICharactorFSM
	:public Template_FSMState<CharactorCore>
{
public:

	std::vector<Resource::FMODSound*> voices;

	virtual void Start();

	bool CheckQuickKey(bool _isAttack);
	bool ChangeState_To_AniEnd(const std::string& _fsmName);


};

