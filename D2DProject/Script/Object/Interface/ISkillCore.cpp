#include "ISkillCore.h"

void ISkillCore::Set(CharactorCore* _owner, AttackInfo& _info)
{
	__super::Set(_owner, _info);
	animator = gameObject->AddComponent<Animator2D>();
}
