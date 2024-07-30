#pragma once
#include "IAttackCore.h"

class ISkillCore
	: public IAttackCore
{
public:
	Animator2D* animator;

	virtual void Set(CharactorCore* _owner, AttackInfo& _info);
};

