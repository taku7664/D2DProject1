#include "Charactor.h"
#include "CharactorCore.h"

void Charactor::AddSkill(SkillInfo* _info)
{
	core->skillList[_info->id] = _info;
}
