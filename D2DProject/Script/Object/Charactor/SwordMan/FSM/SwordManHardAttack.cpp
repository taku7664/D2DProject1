#include "SwordManHardAttack.h"
#include "Contents.h"
#include "../../CharactorCore.h"
#include "../../../Effect/Skill/HardAttack.h"	

namespace FSM
{
	void SwordManHardAttack::Start()
	{
		__super::Start();
		voices.push_back(LoadSound::Voice_HardAttackVoice1().Load());
		voices.push_back(LoadSound::Voice_HardAttackVoice2().Load());
	}
	void SwordManHardAttack::StateEnter()
	{
		owner->animator->ChangeAnimation("Attack1", false);
		owner->animator->GotoAndPlay(0);
		owner->state = CharactorState::Attack;
		owner->soundPlayer->Play(voices[Random::Range(0, voices.size() - 1)]);
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