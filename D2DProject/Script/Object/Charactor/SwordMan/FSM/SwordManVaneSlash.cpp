#include "SwordManVaneSlash.h"
#include "Contents.h"
#include "../../CharactorCore.h"
#include "../../../Interface/ISkillCore.h"
#include "../../../Effect/Skill/VaneSlash.h"

void FSM::SwordManVaneSlash::Start()
{
	__super::Start();
	voices.push_back(LoadSound::Voice_SwordManvaneSlashUp().Load());
	voices.push_back(LoadSound::Voice_SwordManvaneSlashDown().Load());
}

void FSM::SwordManVaneSlash::StateEnter()
{
	owner->animator->ChangeAnimation("Attack2", false);
	owner->animator->GotoAndPlay(0);
	owner->state = CharactorState::Attack;
	Actor* ef = owner->CreateObject<Actor>("Ef_VaneSlash", LayerTag::Object, ObjectTag::Particle);
	slashEffect = ef->AddComponent<VaneSlash>();
	slashEffect->Set(owner, LoadSkill::VaneSlash().GetInfo("Up_Down"));
	count = 0.0f;
	owner->soundPlayer->Play(voices[0]);
}

void FSM::SwordManVaneSlash::StateUpdate()
{
	// =================플레이어 연산=================
	// 돌진방향은 보고 있는 방향
	owner->dirVector.x = 0;

	// =================플레이어 키 입력 및 애니메이션=================
	
	if (owner->animator->GetActiveAnimation() == owner->animator->FindAnimation("Attack2"))
	{
		if (owner->animator->End())
		{
			if (slashEffect->collisionArr.empty())
			{
				FSM->ChangeState("Idle");
			}
			else
			{
				owner->animator->ChangeAnimation("Attack3", false);
				owner->soundPlayer->Play(voices[1]);
				owner->body->SetState(GameState::Passive);
				if (slashEffect) slashEffect->animator->SetState(GameState::Passive);
			}
		}
	}
	if (owner->animator->GetActiveAnimation() == owner->animator->FindAnimation("Attack3"))
	{
		if (owner->animator->End())
		{
			count += Time::deltaTime * owner->attackSpd;
			if (count >= 1.5)
			{
				FSM->ChangeState("Idle");
			}
		}
		else if(owner->animator->currentFrame == 2)
		{
			if(slashEffect) slashEffect->animator->SetState(GameState::Active);
		}
	}
}

void FSM::SwordManVaneSlash::StateExit()
{
	slashEffect = nullptr;
	owner->body->SetState(GameState::Active);
	if (slashEffect) slashEffect->gameObject->SetDestroy();
}
