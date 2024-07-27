#pragma once
#include "ICharactorFSM.h"
#include "Data/Skill/SkillData.h"

class IAttackCore;

class ICharactorAttackFSM
	: public ICharactorFSM
{
protected:
	AttackInfo	 info;
	IAttackCore* hitBox;
public:

};

