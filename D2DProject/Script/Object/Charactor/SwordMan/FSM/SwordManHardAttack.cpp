#include "SwordManHardAttack.h"
#include "Data/Skill/LoadSwordManSkillData.h"
#include "../../CharactorCore.h"
#include "../../../Effect/Skill/HardAttack.h"	

namespace FSM
{

	void SwordManHardAttack::StateEnter()
	{
		owner->animator->ChangeAnimation("Attack1", false);
		owner->state = CharactorState::Attack;
	}

	void SwordManHardAttack::StateUpdate()
	{
		if (ChangeState_To_AniEnd("Idle")) return;

		if (owner->animator->IndexEnter(2))
		{
			Actor* effect = owner->CreateObject<Actor>("Ef_HardAttack", LayerTag::Object, ObjectTag::Particle);
			HardAttack* sk = effect->AddComponent<HardAttack>();
			sk->Set(owner, LoadSkill::HardAttack().GetInfo("Slash"));
			return;
		}
	}
}