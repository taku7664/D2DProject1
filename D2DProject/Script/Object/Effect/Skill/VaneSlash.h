#pragma once
#include "../../Interface/ISkillCore.h"
class VaneSlash
	: public ISkillCore
{
public:
	virtual void Set(IObjectCore* _owner, AttackInfo& _info);
	virtual void Start();
	virtual void Update();
};
