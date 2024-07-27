#include "CharatorBackStep.h"
#include "../CharactorCore.h"

void FSM::CharatorBackStep::StateEnter()
{
	owner->animator->ChangeAnimation("Jump", false);
	owner->animator->GotoAndStop(clamp);
	owner->state = CharactorState::Jump;
	owner->gravity = -owner->jumpPower * 0.3f;
	owner->dirVector = { 0,0 };
}

void FSM::CharatorBackStep::StateUpdate()
{
	owner->zPos += owner->gravity * Time::deltaTime;
	owner->gravity += owner->weight * owner->gravityScale * Time::deltaTime;
	owner->dirVector.x = -owner->bodyActor->transform->scale.x;
	if (owner->gravity > 0)
	{
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
	owner->gameObject->transform->position += owner->dirVector * owner->moveSpd * Time::deltaTime * 2;
}
