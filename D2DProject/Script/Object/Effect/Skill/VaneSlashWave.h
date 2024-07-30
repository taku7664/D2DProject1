#pragma once
#include "../../Interface/ISkillCore.h"

class VaneSlashWave
	: public ISkillCore
{
public:
	CharactorCore* target;
	virtual void Set(CharactorCore* _owner, AttackInfo& _info);
	virtual void Start();
	virtual void Update();
};

