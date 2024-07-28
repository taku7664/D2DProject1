#pragma once
#include "../../Interface/ISkillCore.h"

class VaneSlashWave
	: public ISkillCore
{
public:
	IObjectCore* target;
	virtual void Set(IObjectCore* _owner, AttackInfo& _info);
	virtual void Start();
	virtual void Update();
};

