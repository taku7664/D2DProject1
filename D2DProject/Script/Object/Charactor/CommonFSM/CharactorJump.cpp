#include "CharactorJump.h"
#include "../CharactorCore.h"

void FSM::CharactorJump::StateEnter()
{
	// �����ϰ� ���ƿ����� 1�����ӿ� ������ �ȴ�ϱ� ���߿� ��ĥ ��
	owner->animator->ChangeAnimation("Jump", false);
	owner->state = CharactorState::Jump;
}

void FSM::CharactorJump::StateUpdate()
{
	owner->SetMoveDirect();
	// ���� �غ� �� ����
	if (!owner->isAirial)
	{
		if (owner->animator->currentFrame == 1)
		{
			owner->isAirial = true;
			owner->gravity = -owner->jumpPower;
		}
	}
	// ���� ����
	else if (owner->isAirial)
	{
		owner->zPos += owner->gravity * Time::deltaTime;
		owner->gravity += owner->weight * owner->gravityScale * Time::deltaTime;
		if (owner->gravity < 0)
		{
			if (owner->animator->currentFrame >= clamp)
				owner->animator->Stop();
		}
		else
		{
			if (owner->animator->currentFrame == clamp)
				owner->animator->GotoAndPlay(clamp + 1);
			if (owner->foot->CheckInteract(owner->body))
			{
				owner->isAirial = false;
				owner->zPos = 0.f;
				owner->gravity = 0.f;
				owner->velocity = { 0.f, 0.f };
				FSM->ChangeState("Idle");
				return;
			}
		}
		owner->gameObject->transform->position +=
			owner->dirVector * owner->moveSpd *
			Time::deltaTime * Vector2(1.f + (float)isRun, 1.f);
		if (owner->dirVector.x != 0.f)
		{
			if (owner->dirVector.x >= 1.f) owner->bodyActor->transform->scale.x = 1.f;
			else owner->bodyActor->transform->scale.x = -1.f;
		}
	}
}

void FSM::CharactorJump::StateExit()
{
}
