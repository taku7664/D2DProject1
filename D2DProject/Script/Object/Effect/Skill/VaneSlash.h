#pragma once
#include "../../Interface/ISkillCore.h"

class VaneSlashWave;

class VaneSlash
	: public ISkillCore
{
	VaneSlashWave* wave;
public:
	virtual void Set(IObjectCore* _owner, AttackInfo& _info);
	virtual void Start();
	virtual void Update();
};
