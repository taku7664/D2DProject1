#pragma once
#include "../../Interface/ISkillCore.h"

class HardAttack
	: public ISkillCore
{
private:

public:
	virtual void Set(IObjectCore* _owner, AttackInfo& _info);
	virtual void Start();
	virtual void Update();
};

