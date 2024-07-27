#include "SwordManVaneSlash.h"
#include "Data/Skill/LoadSwordManSkillData.h"
#include "../../CharactorCore.h"
#include "../../../Interface/ISkillCore.h"
#include "../../../Effect/Skill/VaneSlash.h"

void FSM::SwordManVaneSlash::StateEnter()
{
	owner->animator->ChangeAnimation("Attack2", false);
	owner->animator->GotoAndPlay(0);
	owner->state = CharactorState::Attack;
	Actor* ef = owner->CreateObject<Actor>("Ef_VaneSlash", LayerTag::Object, ObjectTag::Particle);
	slashEffect = ef->AddComponent<VaneSlash>();
	slashEffect->Set(owner, LoadSkill::VaneSlash().GetInfo("Up_Down"));
}

void FSM::SwordManVaneSlash::StateUpdate()
{
	// =================�÷��̾� ����=================
	// ���������� ���� �ִ� ����
	owner->dirVector.x = 0;
	// =================���� ��Ʈ�ڽ� ����=================

	if (slashEffect)
	{
		// Ÿ���� ������
		if (!targetCore)
		{
			// �ٵ� �¾�������
			if (slashEffect->IsHit())
			{
				// Ÿ���� �����ְ� �ִϸ��̼� ���
				targetCore = slashEffect->collisionArr.front();
				//slashEffect->animator->ChangeAnimation("VaneSlash", false);
			}
		}
		else
		{
			targetCore->gameObject->transform->position = owner->gameObject->transform->position;
		}
	}
	// =================�÷��̾� Ű �Է� �� �ִϸ��̼�=================
	
	if (owner->animator->GetActiveAnimation() == owner->animator->FindAnimation("Attack2"))
	{
		if (owner->animator->End())
		{
			if (!targetCore)
			{
				FSM->ChangeState("Idle");
			}
			else
			{
				owner->animator->ChangeAnimation("Attack3", false);
				if (slashEffect) slashEffect->animator->SetState(GameState::Passive);
			}
		}
	}
	if (owner->animator->GetActiveAnimation() == owner->animator->FindAnimation("Attack3"))
	{
		if (owner->animator->End())
		{
			FSM->ChangeState("Idle");
		}
		else if(owner->animator->currentFrame == 2)
		{
			if(slashEffect) slashEffect->animator->SetState(GameState::Active);
		}
	}
}

void FSM::SwordManVaneSlash::StateExit()
{
	targetCore = nullptr;
	slashEffect = nullptr;
	if (slashEffect) slashEffect->gameObject->SetDestroy();
}
