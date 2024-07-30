#include "SwordManGuard.h"
#include "Contents.h"
#include "../../CharactorCore.h"

void FSM::SwordManGuard::Start()
{
	__super::Start();
}

void FSM::SwordManGuard::StateEnter()
{
	owner->animator->ChangeAnimation("Guard", false);
	owner->state = CharactorState::Attack;
	owner->soundPlayer->Play("Guard");
	guardTime = 0.f;
}

void FSM::SwordManGuard::StateUpdate()
{
	guardTime += Time::deltaTime;
	if (guardTime > 2.f)
	{
		FSM->ChangeState("Idle");
		return;
	}
	if (owner->TriggerKeyUp('X'))
	{
		FSM->ChangeState("Idle");
		return;
	}
	float delta = Time::GetDeltaTime(200); // 인재원컴 기준 0.9 ~ 1.1언저리 나오는듯?
	if (abs(owner->velocity.x) > 20.0f)
		owner->velocity.x -= (owner->velocity.x * 0.05f) * delta;
	else
		owner->velocity.x = 0.f;

	if (abs(owner->velocity.y) > 0.1f)
		owner->velocity.y -= (owner->velocity.y * 0.05f) * delta;
	else
		owner->velocity.y = 0.f;
}

void FSM::SwordManGuard::StateExit()
{
}
